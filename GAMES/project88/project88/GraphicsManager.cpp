#include "GraphicsManager.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 128
#define STRIP_HEIGHT 8
#define STRIP_SIZE_PIX (SCREEN_WIDTH * STRIP_HEIGHT)
#define STRIP_SIZE_BYTES (STRIP_SIZE_PIX * 2)

using namespace roads;

#ifndef DMA_DESC_COUNT
#define DMA_DESC_COUNT (3)
#endif

//#define DEBUG_PERF
namespace Gamebuino_Meta
{
  extern volatile uint32_t dma_desc_free_count;
}

namespace roads
{
#ifdef SCREENSHOT_MODE
uint16_t counter = 0;
File* wfile;
#endif

      static force_inline void WaitForDescAvailable(const uint32_t min_desc_num, GraphicsManager::TaskSet* taskSet) noexcept
      {
        while (Gamebuino_Meta::dma_desc_free_count < min_desc_num)
        {
          if(taskSet && taskSet->currentTask < taskSet->taskCount) // perform short tasks instead of losing CPU cycles
          {
            (*(taskSet->tasks[taskSet->currentTask].function))(taskSet->tasks[taskSet->currentTask].param);
            ++taskSet->currentTask;
          }
        }
      }
      
      static force_inline void WaitForTransfersDone() noexcept
      {
        WaitForDescAvailable(DMA_DESC_COUNT, nullptr);
      }
}

GraphicsManager::GraphicsManager(uint16_t* strip1, uint16_t* strip2) noexcept:
  strip1(strip1),
  strip2(strip2)
{}

uint16_t* GraphicsManager::StartFrame() noexcept
{
    gb.tft.setAddrWindow(0, 0, SCREEN_WIDTH , SCREEN_HEIGHT );
    //initiate SPI
//    SPI.beginTransaction(Gamebuino_Meta::tftSPISettings);
//    gb.tft.dataMode();

    currentStrip = strip1;
    sentStrip = strip2;

    return currentStrip;
}

void GraphicsManager::EndFrame() noexcept
{
  //WaitForTransfersDone();
  //gb.tft.idleMode();
  //SPI.endTransaction();

}

uint16_t* GraphicsManager::CommitStrip(GraphicsManager::TaskSet* taskSet) noexcept
{
    uint16_t *temp = currentStrip;
    currentStrip = sentStrip;
    sentStrip = temp;

    gb.tft.sendBuffer(sentStrip, STRIP_SIZE_PIX);

    //WaitForDescAvailable(2, taskSet);

    return currentStrip;
}

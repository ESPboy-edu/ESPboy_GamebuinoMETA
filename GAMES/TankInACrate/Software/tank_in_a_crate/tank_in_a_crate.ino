/*
 * tank_in_a_crate.ino
 *
 *  Created on: 30.07.2025
 *      Author: Agandi
 */

#include <Arduino.h>
#include <Gamebuino-Meta.h>
#include "Player.h"
#include "World.h"
#include "Constants.h"
#include "Levels.h"

World world;

GAME_STATES gameState;

int levelSelected = 1;

Image imgControl = Image(IMG_CONTROL);
Image imgLock = Image(IMG_LOCK);

const SaveDefault savefileDefaults[] = {
{ 0, SAVETYPE_INT, 1, 0 }
};

void setup()
{
  //Serial.begin(115200);
  gb.begin();
  gameState = HOME_STATE;
  gb.save.config(savefileDefaults);
}

void loop()
{
  while (!gb.update());
  gb.display.clear(); 

  if(gb.buttons.pressed(BUTTON_MENU))
  {
    gamePaused();
  }

  switch(gameState)
  {
    case HOME_STATE:
      delay(300);
      gameState = drawMainMenu();
      break;
    case PLAY_STATE:
      if(world.getWorldState() != PLAYING)
      {
        world.create();
      }
      world.player.update();
      world.collision();
      world.update();
      world.draw();
      world.player.draw();
      if(world.getWorldState() == WON)
      {
        gameState = WIN_STATE;
      }
      else if(world.getWorldState() == LOST)
      {
        gameState = LOSE_STATE;
      }
      break;
    case LEVELS_STATE:
      gameState = drawLevelsMenu();
      break;
    case CONTROL_STATE:
      gameState = drawControlMenu();
      break;
    case RESET_STATE:
      gameState = drawResetMenu();
      break;
    case VERSION_STATE:
      gameState = drawVersionPanel();
      break;
    case WIN_STATE:
      if(levelSelected == gb.save.get(0) && levelSelected < NBR_MAPS)
      {
        //unlock next level
        gb.save.set(0, levelSelected + 1);
      }
      
      if(levelSelected < NBR_MAPS)
      {
        //set next level
        world.setNbrMap(levelSelected);
      }
      gameState = drawWinPanel();
      levelSelected++;
      break;
    case LOSE_STATE:
      gameState = drawLosePanel();
      break;
    default:
      gb.display.println("Something went wrong");
      break;
  }
}

GAME_STATES drawMainMenu()
{
  const char* entries[] = {
    "Play",
    "Levels",
    "Control",
    "Reset",
    "Version",
  };  
  const uint8_t entryIndex = gb.gui.menu("Menu", entries);
  GAME_STATES selected = HOME_STATE;
  if(entries[entryIndex] == "Play")
  {
    selected = PLAY_STATE;
  }
  if(entries[entryIndex] == "Levels")
  {
    selected = LEVELS_STATE;
  }
  if(entries[entryIndex] == "Control")
  {
    selected = CONTROL_STATE;
  }
  if(entries[entryIndex] == "Reset")
  {
    selected = RESET_STATE;
  }
  if(entries[entryIndex] == "Version")
  {
    selected = VERSION_STATE;
  }
  return selected;
}

GAME_STATES drawLevelsMenu()
{ 
  int tempLevelSelected = levelSelected;
  while(true)
  {
    delay(1);
    if(gb.update())
    {
      gb.display.clear(BLACK);
      gb.display.setColor(WHITE);
      gb.display.setCursor(13, 28);
      gb.display.printf(" < Level %d >", levelSelected);
      if(levelSelected > gb.save.get(0))
      {
        gb.display.drawImage(35, 42, imgLock);
      }
      if(gb.buttons.pressed(BUTTON_A))
      {
        if(levelSelected <= gb.save.get(0))
        {
          world.setNbrMap(levelSelected - 1);
          return HOME_STATE;
        }
      }
      if(gb.buttons.pressed(BUTTON_B))
      {
        levelSelected = tempLevelSelected;
        return HOME_STATE;
      }
      if(gb.buttons.pressed(BUTTON_RIGHT))
      {
        if(levelSelected < NBR_MAPS)
        {
          levelSelected++;
        }
        else
        {
          levelSelected = 1;
        }
      }
      if(gb.buttons.pressed(BUTTON_LEFT))
      {
        if(levelSelected > 1)
        {
          levelSelected--;
        }
        else
        {
          levelSelected = NBR_MAPS;
        }
      }
    }
  }
}

GAME_STATES drawControlMenu()
{
  while(true)
  {
    delay(1);
    if(gb.update())
    {
      gb.display.drawImage(0, 0, imgControl);
      if(gb.buttons.pressed(BUTTON_B))
      {
        return HOME_STATE;
      }
    }
  }
}

GAME_STATES drawResetMenu()
{
  while(true)
  {
    delay(1);
    if(gb.update())
    {
      gb.display.clear(BLACK);
      gb.display.setColor(WHITE);
      gb.display.setCursor(0, 16);
      gb.display.println(" Click A to reset");
      gb.display.println(" Click B to return");
      if(gb.buttons.pressed(BUTTON_B))
      {
        return HOME_STATE;
      }
      if(gb.buttons.pressed(BUTTON_A))
      {
        gb.save.set(0, (int)1);
        gb.display.setCursor(0, 34);
        gb.display.println(" Game has been"); 
        gb.display.println(" reseted");
        world.setNbrMap(0);
        delay(1500);
          return HOME_STATE;
      }
    }
  }
}

GAME_STATES drawVersionPanel()
{
  while(true)
  {
    delay(1);
    if(gb.update())
    {
      gb.display.clear(BLACK);
      gb.display.setColor(WHITE);
      gb.display.setCursor(0, 3);
      gb.display.println(" Version: 1.0");
      gb.display.println(" Date: 30.07.2025");
      gb.display.println(" Date: DD/MM/YYYY");
      if(gb.buttons.pressed(BUTTON_B))
      {
        return HOME_STATE;
      }
    }
  }
}

GAME_STATES drawWinPanel()
{
  while(true)
  { 
    delay(1);
    if(gb.update())
    {
      gb.display.clear(BLACK);
      gb.display.setColor(WHITE);
      gb.display.setCursor(24, 28);
      gb.display.print("YOU WIN!");
      if(gb.buttons.pressed(BUTTON_A))
      {
        return HOME_STATE;
      }
    }
  }
}

GAME_STATES drawLosePanel()
{
  while(true)
  { 
    delay(1);
    if(gb.update())
    {
      gb.display.clear(BLACK);
      gb.display.setColor(WHITE);
      gb.display.setCursor(24, 28);
      gb.display.print("YOU LOSE");
      if(gb.buttons.pressed(BUTTON_A))
      {
        return HOME_STATE;
      }
    }
  }
}

void gamePaused()
{
  while(true)
  {
    delay(1);
    if(gb.update())
    {
      gb.display.clear(BLACK);
      gb.display.setColor(WHITE);
      gb.display.setCursor(18, 28);
      gb.display.println("Game paused");
      if(gb.buttons.pressed(BUTTON_MENU))
      {
        return;
      }
    }
  }
}

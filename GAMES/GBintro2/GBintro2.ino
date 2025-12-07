// Gamebuitro2 by Exocet
// 5 July 2025 @ Shadow Party

#include <Ticker.h>
#include <Gamebuino-Meta.h>
#include "logo.h"
#include "font.h"
#include "blink.h"
#include "pmf_player.h"

static pmf_player s_player;
static uint8_t s_effect_channel=0;

#define SAMPLE_RATE 22000

static const uint8_t PROGMEM music[]=
{
  #include "music.h"
};


#define font font_

// Assets
Image mylogo(IMAGE_DATA);
Image font(FONT_DATA);
Image blink(BLINK_DATA);

const uint8_t SCREEN_WIDTH  = 80;
const uint8_t SCREEN_HEIGHT = 64;
const uint8_t FONT_WIDTH = 8;
const uint8_t FONT_HEIGHT = 8;

const uint8_t BLINK_FRAMES = BLINK_DATA[2];
uint16_t blink_frame = 0;
uint8_t blink_x = 23;
uint8_t blink_y = 29;
uint8_t blink_delay = 99;
bool blink_ready = false;
uint8_t sp = 0;


// Scrolltext variables
char scrolltext[] = "          HELLO SHADOW PARTY! CHAVEZ AND EXOCET ARE BACK WITH ANOTHER LITTLE INTRO FOR THE GAMEBUINO THAT MIGHT OR MIGHT NOT LOOK A BIT SIMILAR TO A RELEASE FROM LAST YEAR. HERE IN GIVRY-EN-ARGONNE, THE SUN IS SHINING, BITS AND BEATS ARE FLOWING, AND THERE'S AMAZING FOOD ON THE WAY. WHAT MORE TO ASK? HI TO EVERYONE AT THE PARTY PLACE, WE HOPE TO SEE MORE GAMEBUINO PRODS SOON! CODE + GFX: EXOCET  -  MUSIC: CHAVEZ  -  MUSIC PLAYER: JARKKOPFC, ADAPTED BY R043V/DPH        - WRAP -          "; 
uint8_t screenchar = 0;
String textAscii1 = "A";
String textAscii2 = "A";
uint8_t textInt1 = 0;
uint8_t textInt2 = 0;
uint8_t textoffset = 0;
uint8_t scrolltext_speed = 2;
int scrolltext_pos = 0;


// starfield variables
uint8_t stars1_x[] = {10, 20, 30, 40, 50, 60, 70, 78, 19, 71};
uint8_t stars1_y[] = {30, 10, 58, 22, 41, 06, 19, 49, 35, 44};
uint8_t stars1_speed = 1;

uint8_t stars2_x[] = {7, 0, 24, 35, 41, 50, 16, 67, 14, 75};
uint8_t stars2_y[] = {9, 53, 27, 16, 47, 2, 62, 30, 55, 11};
uint8_t stars2_speed = 1;

uint8_t stars3_x[] = {6, 10, 32, 42, 45, 52, 58, 67, 18, 60};
uint8_t stars3_y[] = {19, 41, 52, 35, 12, 32, 15, 56, 38, 27};
uint8_t stars3_speed = 1;


// Logo variables
uint8_t mylogo_y = 0;
int costable[] = {100,100,98,96,92,88,83,77,70,62,54,46,37,27,17,7,-2,-12,-22,-32,-41,-50,-58,-66,-73,-80,-85,-90,-94,-97,-99,-100,-100,-99,-97,-94,-90,-85,-80,-73,-66,-58,-50,-41,-32,-22,-12,-2,7,17,27,37,46,54,62,70,77,83,88,92,96,98,100,100};
uint8_t z = 0;
uint8_t logo_amplitude = 10;

Ticker musUpdate;


void musUpd(){
  s_player.update();
};


void setup() {
  gb.begin(); 
  s_player.load(music);
  s_player.start(SAMPLE_RATE);
  musUpdate.attach(0.001, musUpd);
  //playSong( music ) ;
  }



void loop() {
  while(!gb.update());
  gb.display.clear();

// background
gb.display.setColor(DARKBLUE);
gb.display.fillRect(0, 0, 80, 64);


// Stars
  
for (int k = 0; k < sizeof(stars3_x) / sizeof(stars3_x[0]); k++) {
  if (stars3_x[k] < 79) {
    stars3_x[k]++;
  }
  else {
    stars3_x[k] = 0;
  }
}

for (int k = 0; k < sizeof(stars2_x) / sizeof(stars2_x[0]); k++) {
  if (stars2_x[k] < 79) {
    stars2_x[k] = stars2_x[k] + 2;
  }
  else {
    stars2_x[k] = 0;
  }
}

for (int k = 0; k < sizeof(stars1_x) / sizeof(stars1_x[0]); k++) {
  if (stars1_x[k] < 79) {
    stars1_x[k] = stars1_x[k] + 3;
  }
  else {
    stars1_x[k] = 0;
  }
}

if (z < sizeof(costable) / sizeof(costable[0])-1){
  z++;
}
else {
  z = 0;
}



gb.display.setColor(BLUE);
for (int j = 0; j < sizeof(stars3_x) / sizeof(stars3_x[0]); j++) {
  gb.display.drawPixel(stars3_x[j], stars3_y[j]); 
}

gb.display.setColor(LIGHTBLUE);
for (int j = 0; j < sizeof(stars2_x) / sizeof(stars2_x[0]); j++) {
  gb.display.drawPixel(stars2_x[j], stars2_y[j]); 
}

gb.display.setColor(WHITE);
for (int j = 0; j < sizeof(stars1_x) / sizeof(stars1_x[0]); j++) {
  gb.display.drawPixel(stars1_x[j], stars1_y[j]); 
}


gb.display.drawImage(0, mylogo_y + int(costable[z] / logo_amplitude), mylogo);



// blink

if (sp < blink_delay) {
  sp++;
}

if (sp == blink_delay) {
  blink_ready = true;
}

blink.setFrame(blink_frame);
gb.display.drawImage(blink_x, blink_y + int(costable[z] / logo_amplitude), blink);

if (gb.frameCount & 0x1 && blink_frame < BLINK_FRAMES) { // update blink animation every 2 frames
  blink_frame ++;
}

if (blink_frame == BLINK_FRAMES && blink_ready) { 
  blink_x = 23 ;
  blink_y = 29 ;
  blink_frame = 0 ;
  blink_delay = rand() % 40 + 8;
  blink_ready = false;
  sp = 0;
}





// Scrolltext

    for (uint8_t screenchar = 0; screenchar <= SCREEN_WIDTH / FONT_WIDTH; screenchar++) {
    textAscii1 = String(scrolltext[scrolltext_pos + screenchar], DEC); // ascii code conversion
    uint8_t textInt1 = textAscii1.toInt(); // ascii code to int conversion

    textAscii2 = String(scrolltext[scrolltext_pos + screenchar + 1], DEC); // ascii code conversion
    uint8_t textInt2 = textAscii2.toInt(); // ascii code to int conversion
  
      // Left half-letter
      if (textInt1 < 62) 
        {
            gb.display.drawImage(screenchar*FONT_WIDTH, 55, font,(textInt1*FONT_WIDTH-496 + textoffset), 1, FONT_WIDTH - textoffset, FONT_HEIGHT);  
         }
       else
        {
            gb.display.drawImage(screenchar*FONT_WIDTH, 55, font,(textInt1*FONT_WIDTH-496 + textoffset), FONT_HEIGHT, FONT_WIDTH - textoffset, FONT_HEIGHT);       
         }
       
      // Right half-letter
      if (textInt2 < 62) 
        {
            gb.display.drawImage(screenchar*FONT_WIDTH + FONT_WIDTH - textoffset, 55, font,(textInt2*FONT_WIDTH-496), 1, 0 + textoffset, FONT_HEIGHT); 
         }
      else
        {
            gb.display.drawImage(screenchar*FONT_WIDTH + FONT_WIDTH - textoffset, 55, font,(textInt2*FONT_WIDTH-496), FONT_HEIGHT, 0 + textoffset, FONT_HEIGHT);      
         }
    }

    if (textoffset < FONT_WIDTH) {
      textoffset = textoffset + scrolltext_speed;
    }
    else {
      textoffset = 0;
    }

    if (scrolltext_pos<(sizeof(scrolltext) / sizeof(scrolltext[0])-11) && (textoffset == 0)) { 
      scrolltext_pos++;
    }
    if (scrolltext_pos >= (sizeof(scrolltext) / sizeof(scrolltext[0])-11)) { 
      scrolltext_pos = 0;
    }


}

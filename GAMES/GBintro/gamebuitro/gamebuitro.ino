// Gamebuitro by Exocet
// November 2023 - May 2024

#include <Ticker.h>
#include <Gamebuino-Meta.h>
#include "logo.h"
#include "font.h"
#include "sparkle.h"

#include "pmf_player.h"

static pmf_player s_player;
static uint8_t s_effect_channel=0;

#define SAMPLE_RATE 22000


static const uint8_t music[]=
{
  #include "music.h"
};


// Assets
Image mylogo(IMAGE_DATA);
Image font_(FONT_DATA);
Image sparkle(SPARKLE_DATA);

const uint8_t SCREEN_WIDTH  = 80;
const uint8_t SCREEN_HEIGHT = 64;
const uint8_t FONT_WIDTH = 8;
const uint8_t FONT_HEIGHT = 8;

const uint8_t SPARKLE_FRAMES = SPARKLE_DATA[2];
uint16_t sparkle_frame = 0;
uint8_t sparkle_x = 40;
uint8_t sparkle_y = 32;
uint8_t sparkle_delay = 24;
bool sparkle_ready = false;
uint8_t sp = 0;


// Scrolltext variables
char scrolltext[] = "          I MET NERDINA AT A LOCAL SPEED DATING EVENT. SHE LOOKED STUNNING AND WAS WELL OUT OF MY LEAGUE. <SURE,> SHE TOLD ME, <YOU'RE HANDSOME, RIPPED AND I LOVE YOUR ATARI TATTOO, BUT LOOKS ISN'T EVERYTHING.> HER GAZE SHARPENED. <CAN YOU CODE?> I FELT A SHIVER DOWN MY SPINE. BOASTING ABOUT PIXEL ART CATS WAS NOT GOING TO CUT IT. <CO... CODE?>, I STUTTERED, <WELL, I MADE THESE GFA BASIC INTROS 20 YEARS AGO WHICH -> SHE SLAMMED HER FIST ON THE TABLE. <LOOK, I NEED A GUY WITH ENOUGH BRAINS TO HANDLE MORE THAN FUCKING BASIC. THE BARE MINIMUM IS C++. MY EX COULD DO Z80 ASM.> I WALKED HOME. IT WAS A WET NOVEMBER NIGHT AND THE DRIZZLE WAS CONVENIENTLY HIDING THE TEARS OF BITTERNESS CASCADING DOWN MY CHEEKS. ALL THAT TIME SPENT LIFTING WEIGHTS, PUSHING PIXELS, AND GETTING A SWANKY ATARI TATTOO - ALL FOR NOTHING. NERDINA WAS SUCH A LONG SHOT THAT I HAD NO CHOICE BUT TO UTTERLY KNOCK HER SOCKS OFF. I COULDN'T GET MUCH SLEEP THAT NIGHT BUT WHEN A LAZY SUN PEEPED OVER THE SLEEPY SUBURBAN JUMBLE, I HAD A PLAN. MICROCONSOLES! WOMEN LOVE THEM. SOMEWHERE IN A DRAWER, I HAD A GAMEBUINO META, A DINKY LITTLE ARDUINO-BASED HANDHELD PROGRAMMABLE IN C++. THERE WAS NO TIME TO LOSE. HERE I COME, NERDINA!         TO BE CONTINUED...          CODE + GFX: EXOCET  -  MUSIC: CHAVEZ + JOSSS  -  MUSIC PLAYER: JARKKOPFC, ADAPTED BY R043V/DPH          - WRAP -          "; 
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
uint8_t mylogo_y = 9;
int costable[] = {100,100,98,96,92,88,83,77,70,62,54,46,37,27,17,7,-2,-12,-22,-32,-41,-50,-58,-66,-73,-80,-85,-90,-94,-97,-99,-100,-100,-99,-97,-94,-90,-85,-80,-73,-66,-58,-50,-41,-32,-22,-12,-2,7,17,27,37,46,54,62,70,77,83,88,92,96,98,100,100};
uint8_t z = 0;
uint8_t logo_amplitude = 12;

Ticker musUpdate;


void musUpd(){
  s_player.update();
};


void setup() {
  //Serial.begin(115200);
  gb.begin(); 
  s_player.load(music);
  s_player.start(SAMPLE_RATE);
  musUpdate.attach(0.001, musUpd);
  //playSong( music ) ;
  }


void loop() {
  if (!gb.update()) return;
  gb.display.clear();

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


gb.display.setColor(DARKBLUE);
for (int j = 0; j < sizeof(stars3_x) / sizeof(stars3_x[0]); j++) {
  gb.display.drawPixel(stars3_x[j], stars3_y[j]); 
}

gb.display.setColor(BLUE);
for (int j = 0; j < sizeof(stars2_x) / sizeof(stars2_x[0]); j++) {
  gb.display.drawPixel(stars2_x[j], stars2_y[j]); 
}

gb.display.setColor(LIGHTBLUE);
for (int j = 0; j < sizeof(stars1_x) / sizeof(stars1_x[0]); j++) {
  gb.display.drawPixel(stars1_x[j], stars1_y[j]); 
}


gb.display.drawImage(14, mylogo_y + int(costable[z] / logo_amplitude), mylogo);


// Sparkle

if (sp < sparkle_delay) {
  sp++;
}

if (sp == sparkle_delay) {
  sparkle_ready = true;
}

sparkle.setFrame(sparkle_frame);
gb.display.drawImage(sparkle_x, sparkle_y + int(costable[z] / logo_amplitude), sparkle);

if (gb.frameCount & 0x1 && sparkle_frame < SPARKLE_FRAMES) { // update sparkle animation every 2 frames
  sparkle_frame ++;
}

if (sparkle_frame == SPARKLE_FRAMES && sparkle_ready) { 
  sparkle_x = rand() % 46 + 14 ;
  sparkle_y = rand() % 36 + 5 ;
  sparkle_frame = 0 ;
  sparkle_delay = rand() % 40 + 8;
  sparkle_ready = false;
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
            gb.display.drawImage(screenchar*FONT_WIDTH, 55, font_,(textInt1*FONT_WIDTH-496 + textoffset), 1, FONT_WIDTH - textoffset, FONT_HEIGHT);  
         }
       else
        {
            gb.display.drawImage(screenchar*FONT_WIDTH, 55, font_,(textInt1*FONT_WIDTH-496 + textoffset), FONT_HEIGHT, FONT_WIDTH - textoffset, FONT_HEIGHT);       
         }
       
      // Right half-letter
      if (textInt2 < 62) 
        {
            gb.display.drawImage(screenchar*FONT_WIDTH + FONT_WIDTH - textoffset, 55, font_,(textInt2*FONT_WIDTH-496), 1, 0 + textoffset, FONT_HEIGHT); 
         }
      else
        {
            gb.display.drawImage(screenchar*FONT_WIDTH + FONT_WIDTH - textoffset, 55, font_,(textInt2*FONT_WIDTH-496), FONT_HEIGHT, 0 + textoffset, FONT_HEIGHT);      
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

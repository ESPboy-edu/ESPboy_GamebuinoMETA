// "Demon Girls" (previously "Hellmaker" or "Pancaker")
// A "Helltaker" demake (unofficial)
// for Gamebuino Meta
// by Juice Lizard.

// Original game by VanRipper.
// Original music by Mittsies.

// With this beautiful source code
// you can change the levels
// or anything you want
// to make your own version of the game.

#include <Gamebuino-Meta.h>

//extern const PROGMEM uint8_t font5x7[];

const PROGMEM uint8_t font5x7[] = {
  5,7, // width and height
    0x7F, 0x41, 0x41, 0x41, 0x7F, // 0
    0x3E, 0x5B, 0x4F, 0x5B, 0x3E, // 1  sad
    0x3E, 0x6B, 0x4F, 0x6B, 0x3E, // 2  happy
    0x18, 0x3C, 0x78, 0x3C, 0x18, // 3  heart
    0x18, 0x3C, 0x7E, 0x3C, 0x18, // 4  diamond
    0x1C, 0x57, 0x7D, 0x57, 0x1C, // 5  clover
    0x1C, 0x5E, 0x7F, 0x5E, 0x1C, // 6  spade
    0x00, 0x7E, 0x43, 0x43, 0x7E, // 7  bat low
    0x00, 0x7E, 0x73, 0x73, 0x7E, // 8  bat med
    0x00, 0x7E, 0x7F, 0x7F, 0x7E, // 9  bat high
    0x7F, 0x41, 0x41, 0x41, 0x7F, // 10  line feed
    0x30, 0x48, 0x3A, 0x06, 0x0E, // 11  male
    0x06, 0x29, 0x79, 0x29, 0x06, // 12  female
    0x7F, 0x41, 0x41, 0x41, 0x7F, // 13  carriage return
    0x60, 0x70, 0x3F, 0x02, 0x04, // 14  note
    0x2A, 0x1C, 0x36, 0x1C, 0x2A, // 15  sun
    0x7F, 0x3E, 0x1C, 0x08, 0x00, // 16  right triangle
    0x00, 0x08, 0x1C, 0x3E, 0x7F, // 17  left triangle
    0x14, 0x22, 0x7F, 0x22, 0x14, // 18  double arrow
    0x3C, 0x3C, 0x3C, 0x7E, 0xFF, // 19  speaker
    0x18, 0x42, 0x3C, 0x81, 0x7E, // 20  sound
    0x3E, 0x63, 0x75, 0x63, 0x3E, // 21  A button
    0x3E, 0x61, 0x6B, 0x63, 0x3E, // 22  B button
    0x3E, 0x6B, 0x6B, 0x6B, 0x3E, // 23  C button
    0x04, 0x02, 0x7F, 0x02, 0x04, // 24  up arrow
    0x10, 0x20, 0x7F, 0x20, 0x10, // 25  down arrow
    0x08, 0x08, 0x2A, 0x1C, 0x08, // 26  right arrow
    0x08, 0x1C, 0x2A, 0x08, 0x08, // 27  left arrow
    0x14, 0x3E, 0x55, 0x41, 0x22, // 28  euro
    0x63, 0x75, 0x69, 0x75, 0x63, // 29  timer
    0x10, 0x18, 0x1C, 0x18, 0x10, // 30  up triangle
    0x04, 0x0C, 0x1C, 0x0C, 0x04, // 31  down triangle
    0x00, 0x00, 0x00, 0x00, 0x00, // 32  space
    0x00, 0x00, 0x5F, 0x00, 0x00, // 33
    0x00, 0x07, 0x00, 0x07, 0x00, // 34
    0x14, 0x7F, 0x14, 0x7F, 0x14, // 35
    0x04, 0x2A, 0x7F, 0x2A, 0x10, // 36
    0x23, 0x13, 0x08, 0x64, 0x62, // 37
    0x36, 0x49, 0x56, 0x20, 0x50, // 38
    0x00, 0x08, 0x07, 0x03, 0x00, // 39
    0x00, 0x1C, 0x22, 0x41, 0x00, // 40
    0x00, 0x41, 0x22, 0x1C, 0x00, // 41
    0x2A, 0x1C, 0x3E, 0x1C, 0x2A, // 42
    0x08, 0x08, 0x3E, 0x08, 0x08, // 43
    0x00, 0xE0, 0x60, 0x00, 0x00, // 44
    0x08, 0x08, 0x08, 0x08, 0x08, // 45
    0x00, 0x60, 0x60, 0x00, 0x00, // 46
    0x60, 0x10, 0x08, 0x04, 0x03, // 47
    0x3E, 0x51, 0x49, 0x45, 0x3E, // 48  0
    0x00, 0x42, 0x7F, 0x40, 0x00, // 49  1
    0x62, 0x51, 0x49, 0x49, 0x46, // 50  2
    0x21, 0x41, 0x49, 0x4D, 0x33, // 51  3
    0x18, 0x14, 0x12, 0x7F, 0x10, // 52  4
    0x27, 0x45, 0x45, 0x45, 0x39, // 53  5
    0x3C, 0x4A, 0x49, 0x49, 0x30, // 54  6
    0x41, 0x21, 0x11, 0x09, 0x07, // 55  7
    0x36, 0x49, 0x49, 0x49, 0x36, // 56  8
    0x06, 0x49, 0x49, 0x29, 0x1E, // 57  9
    0x00, 0x00, 0x24, 0x00, 0x00, // 58
    0x00, 0x80, 0x64, 0x00, 0x00, // 59
    0x08, 0x14, 0x22, 0x41, 0x00, // 60
    0x14, 0x14, 0x14, 0x14, 0x14, // 61
    0x00, 0x41, 0x22, 0x14, 0x08, // 62
    0x02, 0x01, 0x59, 0x09, 0x06, // 63
    0x3E, 0x41, 0x5D, 0x59, 0x4E, // 64
    0x7C, 0x12, 0x11, 0x12, 0x7C, // 65  A
    0x7F, 0x49, 0x49, 0x49, 0x36, // 66  B
    0x3E, 0x41, 0x41, 0x41, 0x22, // 67  C
    0x7F, 0x41, 0x41, 0x22, 0x1C, // 68  D
    0x7F, 0x49, 0x49, 0x49, 0x41, // 69  E
    0x7F, 0x09, 0x09, 0x09, 0x01, // 70  F
    0x3E, 0x41, 0x41, 0x51, 0x32, // 71  G
    0x7F, 0x08, 0x08, 0x08, 0x7F, // 72  H
    0x00, 0x41, 0x7F, 0x41, 0x00, // 73  I
    0x20, 0x41, 0x41, 0x3F, 0x01, // 74  J
    0x7F, 0x08, 0x14, 0x22, 0x41, // 75  K
    0x7F, 0x40, 0x40, 0x40, 0x40, // 76  L
    0x7F, 0x02, 0x0C, 0x02, 0x7F, // 77  M
    0x7F, 0x02, 0x04, 0x08, 0x7F, // 78  N
    0x3E, 0x41, 0x41, 0x41, 0x3E, // 79  O
    0x7F, 0x09, 0x09, 0x09, 0x06, // 80  P
    0x3E, 0x41, 0x61, 0x41, 0xBE, // 81  Q
    0x7F, 0x09, 0x19, 0x29, 0x46, // 82  R
    0x26, 0x49, 0x49, 0x49, 0x32, // 83  S
    0x01, 0x01, 0x7F, 0x01, 0x01, // 84  T
    0x3F, 0x40, 0x40, 0x40, 0x3F, // 85  U
    0x1F, 0x20, 0x40, 0x20, 0x1F, // 86  V
    0x3F, 0x40, 0x38, 0x40, 0x3F, // 87  W
    0x63, 0x14, 0x08, 0x14, 0x63, // 88  X
    0x03, 0x04, 0x78, 0x04, 0x03, // 89  Y
    0x61, 0x51, 0x49, 0x45, 0x43, // 90  Z
    0x00, 0x7F, 0x41, 0x41, 0x00, // 91
    0x03, 0x04, 0x08, 0x10, 0x60, // 92
    0x00, 0x41, 0x41, 0x7F, 0x00, // 93
    0x04, 0x02, 0x01, 0x02, 0x04, // 94
    0x80, 0x80, 0x80, 0x80, 0x80, // 95
    0x00, 0x03, 0x07, 0x08, 0x00, // 96
    0x20, 0x54, 0x54, 0x78, 0x40, // 97  a
    0x7F, 0x28, 0x44, 0x44, 0x38, // 98  b
    0x38, 0x44, 0x44, 0x44, 0x28, // 99  c
    0x38, 0x44, 0x44, 0x28, 0x7F, // 100  d
    0x38, 0x54, 0x54, 0x54, 0x18, // 101  e
    0x08, 0x7E, 0x09, 0x09, 0x02, // 102  f
    0x18, 0xA4, 0xA4, 0x9C, 0x78, // 103  g
    0x7F, 0x08, 0x04, 0x04, 0x78, // 104  h
    0x00, 0x44, 0x7D, 0x40, 0x00, // 105  i
    0x00, 0x60, 0x80, 0x84, 0x7D, // 106  j
    0x7F, 0x10, 0x10, 0x28, 0x44, // 107  k
    0x00, 0x41, 0x7F, 0x40, 0x00, // 108  l
    0x7C, 0x04, 0x78, 0x04, 0x78, // 109  m
    0x7C, 0x08, 0x04, 0x04, 0x78, // 110  n
    0x38, 0x44, 0x44, 0x44, 0x38, // 111  o
    0xFC, 0x18, 0x24, 0x24, 0x18, // 112  p
    0x18, 0x24, 0x24, 0x18, 0xFC, // 113  q
    0x7C, 0x08, 0x04, 0x04, 0x08, // 114  r
    0x08, 0x54, 0x54, 0x54, 0x20, // 115  s
    0x04, 0x3F, 0x44, 0x44, 0x20, // 116  t
    0x3C, 0x40, 0x40, 0x20, 0x7C, // 117  u
    0x1C, 0x20, 0x40, 0x20, 0x1C, // 118  v
    0x3C, 0x40, 0x20, 0x40, 0x3C, // 119  w
    0x44, 0x28, 0x10, 0x28, 0x44, // 120  x
    0x4C, 0x90, 0x90, 0x90, 0x7C, // 121  y
    0x44, 0x64, 0x54, 0x4C, 0x44, // 122  z
    0x00, 0x08, 0x36, 0x41, 0x00, // 123
    0x00, 0x00, 0x7F, 0x00, 0x00, // 124
    0x00, 0x41, 0x36, 0x08, 0x00, // 125
    0x18, 0x04, 0x08, 0x10, 0x0C, // 126
    0x7F, 0x41, 0x41, 0x41, 0x7F, // 127
    
    0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x7d, 0x00, 0x00,
    0x1c, 0x22, 0x7f, 0x22, 0x14,
    0x48, 0x7e, 0x49, 0x49, 0x42,
    0x41, 0x3e, 0x22, 0x3e, 0x41,
    0x2b, 0x2c, 0x78, 0x2c, 0x2b,
    0x00, 0x00, 0x77, 0x00, 0x00,
    0x20, 0x4e, 0x55, 0x39, 0x02,
    0x00, 0x01, 0x00, 0x01, 0x00,
    0x3e, 0x49, 0x55, 0x55, 0x3e,
    0x08, 0x0f, 0x0f, 0x0c, 0x08,
    0x08, 0x14, 0x00, 0x08, 0x14,
    0x08, 0x08, 0x08, 0x08, 0x18,
    0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x3c, 0x14, 0x28, 0x00,
    0x01, 0x01, 0x01, 0x01, 0x01,
    0x00, 0x06, 0x09, 0x09, 0x06,
    0x14, 0x14, 0x1f, 0x14, 0x14,
    0x00, 0x00, 0x01, 0x07, 0x04,
    0x00, 0x00, 0x05, 0x07, 0x02,
    0x00, 0x00, 0x02, 0x01, 0x00,
    0x7e, 0x08, 0x10, 0x10, 0x0e,
    0x06, 0x0f, 0x0f, 0x7f, 0x7f,
    0x00, 0x00, 0x08, 0x00, 0x00,
    0x00, 0x40, 0x60, 0x00, 0x00,
    0x00, 0x00, 0x05, 0x07, 0x04,
    0x08, 0x0a, 0x0d, 0x0a, 0x08,
    0x14, 0x08, 0x00, 0x14, 0x08,
    0x05, 0x07, 0x34, 0x20, 0x70,
    0x05, 0x07, 0x14, 0x70, 0x40,
    0x05, 0x07, 0x32, 0x20, 0x70,
    0x30, 0x48, 0x4d, 0x40, 0x20,
    0x70, 0x29, 0x26, 0x28, 0x70,
    0x70, 0x28, 0x26, 0x29, 0x70,
    0x70, 0x2a, 0x25, 0x2a, 0x70,
    0x72, 0x29, 0x26, 0x29, 0x70,
    0x70, 0x29, 0x24, 0x29, 0x70,
    0x70, 0x2f, 0x25, 0x2f, 0x70,
    0x7c, 0x12, 0x7f, 0x49, 0x49,
    0x0e, 0x51, 0x71, 0x11, 0x0a,
    0x7c, 0x55, 0x56, 0x54, 0x44,
    0x7c, 0x54, 0x56, 0x55, 0x44,
    0x7c, 0x56, 0x55, 0x56, 0x44,
    0x7c, 0x55, 0x54, 0x55, 0x44,
    0x00, 0x45, 0x7e, 0x44, 0x00,
    0x00, 0x44, 0x7e, 0x45, 0x00,
    0x00, 0x46, 0x7d, 0x46, 0x00,
    0x00, 0x45, 0x7c, 0x45, 0x00,
    0x08, 0x7f, 0x49, 0x22, 0x1c,
    0x7c, 0x0a, 0x11, 0x22, 0x7d,
    0x38, 0x45, 0x46, 0x44, 0x38,
    0x38, 0x44, 0x46, 0x45, 0x38,
    0x38, 0x46, 0x45, 0x46, 0x38,
    0x3a, 0x45, 0x46, 0x45, 0x38,
    0x38, 0x45, 0x44, 0x45, 0x38,
    0x22, 0x14, 0x08, 0x14, 0x22,
    0x3e, 0x61, 0x5d, 0x43, 0x3e,
    0x3c, 0x41, 0x42, 0x40, 0x3c,
    0x3c, 0x40, 0x42, 0x41, 0x3c,
    0x3c, 0x42, 0x41, 0x42, 0x3c,
    0x3c, 0x41, 0x40, 0x41, 0x3c,
    0x04, 0x08, 0x72, 0x09, 0x04,
    0x7f, 0x22, 0x22, 0x1c, 0x00,
    0x7c, 0x12, 0x29, 0x29, 0x16,
    0x20, 0x55, 0x56, 0x78, 0x40,
    0x20, 0x54, 0x56, 0x79, 0x40,
    0x20, 0x56, 0x55, 0x7a, 0x40,
    0x22, 0x55, 0x56, 0x79, 0x40,
    0x20, 0x55, 0x54, 0x79, 0x40,
    0x20, 0x57, 0x55, 0x7b, 0x40,
    0x60, 0x54, 0x7c, 0x54, 0x0c,
    0x0c, 0x52, 0x72, 0x12, 0x00,
    0x38, 0x55, 0x56, 0x54, 0x18,
    0x38, 0x54, 0x56, 0x55, 0x18,
    0x38, 0x56, 0x55, 0x56, 0x18,
    0x38, 0x55, 0x54, 0x55, 0x18,
    0x00, 0x49, 0x7a, 0x40, 0x00,
    0x00, 0x48, 0x7a, 0x41, 0x00,
    0x00, 0x4a, 0x79, 0x42, 0x00,
    0x00, 0x49, 0x78, 0x41, 0x00,
    0x30, 0x4a, 0x4b, 0x4e, 0x32,
    0x7c, 0x0a, 0x05, 0x06, 0x79,
    0x30, 0x49, 0x4a, 0x48, 0x30,
    0x30, 0x48, 0x4a, 0x49, 0x30,
    0x30, 0x4a, 0x49, 0x4a, 0x30,
    0x32, 0x49, 0x4a, 0x49, 0x30,
    0x30, 0x49, 0x48, 0x49, 0x30,
    0x08, 0x08, 0x2a, 0x08, 0x08,
    0x38, 0x64, 0x54, 0x4c, 0x38,
    0x3c, 0x41, 0x42, 0x20, 0x7c,
    0x3c, 0x40, 0x42, 0x21, 0x7c,
    0x3c, 0x42, 0x41, 0x22, 0x7c,
    0x3c, 0x41, 0x40, 0x21, 0x7c,
    0x24, 0x48, 0x4a, 0x49, 0x3c,
    0x7e, 0x24, 0x24, 0x18, 0x00,
    0x24, 0x49, 0x48, 0x49, 0x3c,
};

#include "settings.h"
#include "assets.h"
#include "levels.h"

// 0: intro, 1: Hell levels, 2: Hell dialogues,
// 3: BAD END, 4: credits, 5: level selection screen,
// 6: It was an accident , 7: Heaven dislogues, 8: sin certificates
// 9: rats everywhere, 10: Michael is BAD, 11: Heaven levels
// 12: Heaven level selection screen, 13: Acrylique et pixels

int gamestate = 0;

// the hero
uint8_t rowPlayer = 2;
uint8_t columnPlayer = 7;
bool heroKicks = false;
// Our hero faces right or left.
bool heroTurnsRight = false;


// HUD variables
int levelNumber = 0;
uint8_t remainingMoves = 23;

// death animation
bool death = false;
uint8_t deathCounter = 0;
uint8_t skullCounter = 0;

// DEMON GIRLS animation
bool resetLevel = false;
bool clap = false;
uint8_t clapCounter = 0;

// Does the hero get a key?
bool hasKey = false;

// Usefull for moving teeth
bool evenNumber = true;

// for dialogue animation
uint8_t bigDemon = 8;

bool levelFinished = false;
uint8_t goDialogues = 0;

bool topAnswer = true;
bool goodAnswer = false;
uint8_t answered = 0;

// Do you keep your underwear when you sleep?
uint8_t whatTheFoxSays = 0;
bool slipMode = false;
bool codeLearned = false;
int xButtons = 50;

// secret letters hidden under some blocks
bool hasSecretB = false;
bool hasSecretA = false;
bool hasSecretD = false;
bool fromBadScreen = false;
bool hasYellowTriangle = false;
bool hasPinkCircle = false;
bool hasBlueSquare = false;
bool fromDogScreen = false;

// Usefull for LEDs at the back of the Gamebuino Meta
// when the hero is hurt by teeth
uint8_t redFlash = 0;

// Badger logo animation
int xLogo = 80;
int yLogo = 80;
int logoTrouble = 120;
uint8_t frames = 0;
bool logoSide = true;
bool logoReduces = true;
bool anim = true;
uint8_t beforePress = 0;

// It was an accident
int xSquareNose = -20;
int xDumbulance = -156;
int accidentCounter = 0;
uint8_t accidentStep = 0;
int accidentCounterMax = 66;
bool startSiren = true;

// Heaven
int WYFLevelNumber = 0;
int xBigCloud = -32;
bool WYFLevelFinished = false;
bool nextLevel = false;
bool goToHell = false;

// THE END - rats everywhere
uint8_t THE_ENDCounter = 0;
bool THE_ENDFlash = false;
uint8_t backToHellStep = 1;
bool waitOneFrame = false;
int xHarem = 0;
int haremCounter = 0;
bool buttonsMoveCloser = true;
bool buttonsMove = true;

// Befriend All Demon
bool BadIsPlaying = false;
int BadFrames = 0;
int BadSeconds = 0;
int BadMinutes = 0;

/*
// Framerate
uint8_t fps;
uint8_t frame_count;
*/

// Music
int8_t track = -1;
int8_t MittsiesTrack = 0;
int8_t trackColorCounter = 0;
int lyricsNumber = 0;

bool startRainbow = true;

// save progress
int lastLevelWon = 0;

// SOUNDS
// little Tick
const PROGMEM Gamebuino_Meta::Sound_FX littleTick[] = {
//    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,100,0,0,126,2},
//    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,100,0,0,169,2}
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,80,-10,-128,200,4}
};

// example sound
const PROGMEM Gamebuino_Meta::Sound_FX mySfx[] = {
    {Gamebuino_Meta::Sound_FX_Wave::NOISE,1,100,2,5,96,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,100,10,0,126,10},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,120,-6,0,84,10}
};

// Square Nose sound
const PROGMEM Gamebuino_Meta::Sound_FX squirrel[] = {
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,80,0,-16,32,10}
};

// Dumbulance siren sound
const PROGMEM Gamebuino_Meta::Sound_FX siren[] = {
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,30,0,0,50,25},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,60,0,0,45,25},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,90,0,0,50,25},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,0,0,45,25},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,0,0,50,25},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,90,0,0,45,25},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,60,0,0,50,25},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,30,0,0,45,25}
};

// simple hero move
const PROGMEM Gamebuino_Meta::Sound_FX simpleMove[] = {
    {Gamebuino_Meta::Sound_FX_Wave::NOISE,0,60,0,-120,128,6}
};

// slow move (big characters in dialogues)
const PROGMEM Gamebuino_Meta::Sound_FX slowMove[] = {
    {Gamebuino_Meta::Sound_FX_Wave::NOISE,0,0,2,2,48,13}
};

// push a skeleton
const PROGMEM Gamebuino_Meta::Sound_FX pushSkeleton[] = {
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,180,0,0,200,2},
    {Gamebuino_Meta::Sound_FX_Wave::NOISE,1,0,0,0,0,1},
    {Gamebuino_Meta::Sound_FX_Wave::NOISE,0,60,0,-120,128,4}
};

// break a skeleton
const PROGMEM Gamebuino_Meta::Sound_FX skeletonBreak[] = {
    {Gamebuino_Meta::Sound_FX_Wave::NOISE,1,200,-20,0,32,2},
    {Gamebuino_Meta::Sound_FX_Wave::NOISE,1,160,-20,0,48,2},
    {Gamebuino_Meta::Sound_FX_Wave::NOISE,1,120,-20,0,64,2},
    {Gamebuino_Meta::Sound_FX_Wave::NOISE,0,80,-20,0,80,2}
};

// kick a block with no move
const PROGMEM Gamebuino_Meta::Sound_FX kickOnly[] = {
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,160,0,0,200,2},
    {Gamebuino_Meta::Sound_FX_Wave::NOISE,1,0,0,0,0,1},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,80,0,0,142,2}
};

// struck by lightning (death)
const PROGMEM Gamebuino_Meta::Sound_FX lightningStrike[] = {
    {Gamebuino_Meta::Sound_FX_Wave::NOISE,1,230,-20,0,32,2},
    {Gamebuino_Meta::Sound_FX_Wave::NOISE,1,180,-20,0,48,2},
    {Gamebuino_Meta::Sound_FX_Wave::NOISE,1,130,-20,0,64,2},
    {Gamebuino_Meta::Sound_FX_Wave::NOISE,0,80,-20,0,80,2}
};


// move and teeth hurt
const PROGMEM Gamebuino_Meta::Sound_FX moveAndTeeth[] = {
    {Gamebuino_Meta::Sound_FX_Wave::NOISE,1,60,0,-120,128,4},
    {Gamebuino_Meta::Sound_FX_Wave::NOISE,1,200,0,0,256,2},
    {Gamebuino_Meta::Sound_FX_Wave::NOISE,1,140,0,0,0,2},
    {Gamebuino_Meta::Sound_FX_Wave::NOISE,1,80,0,0,256,2},
    {Gamebuino_Meta::Sound_FX_Wave::NOISE,0,20,0,0,0,2}
};

// when we take the key
const PROGMEM Gamebuino_Meta::Sound_FX keySound[] = {
    {Gamebuino_Meta::Sound_FX_Wave::NOISE,1,60,0,-120,128,4},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,140,0,0,25,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,60,-2,0,25,40}
};

// open a lock
const PROGMEM Gamebuino_Meta::Sound_FX openALock[] = {
    {Gamebuino_Meta::Sound_FX_Wave::NOISE,1,200,-20,0,32,3},
    {Gamebuino_Meta::Sound_FX_Wave::NOISE,0,160,-20,0,48,3}
};

// Wedding March (une octave plus grave)
const PROGMEM Gamebuino_Meta::Sound_FX WeddingMarch[] = {
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,119,6},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,119,6},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,119,6},
    
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,119,24},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,0,0,0,119,24},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,119,6},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,119,6},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,119,6},
    
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,119,24},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,0,0,0,119,24},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,119,6},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,119,6},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,119,6},
    
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,95,12},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,95,6},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,95,6},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,95,6},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,95,12},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,95,6},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,95,6},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,95,6},
    
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,80,12},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,80,6},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,80,6},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,80,6},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,80,12},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,80,6},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,80,6},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,80,6},
    
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,60,24},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,63,18},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,84,6},
    
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,71,12},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,80,12},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,89,12},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,106,12},

    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,119,12},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,106,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,119,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,126,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,119,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,106,12},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,142,9},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,106,3},

    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,95,12},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,0,0,0,119,18},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,119,6},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,95,6},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,80,6},

    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,60,24},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,63,18},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,84,6},

    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,71,12},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,80,12},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,89,12},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,106,12},

    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,119,12},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,106,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,119,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,126,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,119,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,95,12},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,106,9},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,95,3},

    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,106,24},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,119,12},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,0,0,0,119,12},

// second page

    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,60,24},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,60,18},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,60,6},

    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,47,12},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,53,12},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,63,12},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,84,12},

    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,80,18},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,60,6},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,60,18},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,47,6},

    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,47,12},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,53,12},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,63,12},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,84,12},

    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,80,18},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,47,6},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,47,18},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,40,6},

    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,40,24},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,45,12},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,47,12},

    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,53,12},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,56,6},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,47,6},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,53,12},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,71,6},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,60,6},

    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,63,12},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,40,12},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,35,12},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,32,12},

    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,30,24},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,32,18},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,42,6},

    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,35,12},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,40,12},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,45,12},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,53,12},

    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,60,12},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,53,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,60,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,63,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,60,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,53,12},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,80,9},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,53,3},

    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,47,12},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,0,0,0,60,18},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,60,6},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,47,6},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,40,6},

    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,30,24},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,32,18},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,42,6},
    
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,35,12},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,40,12},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,45,12},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,53,12},

    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,60,12},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,53,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,60,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,63,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,60,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,47,12},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,53,9},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,47,3},

    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,120,-10,0,53,24},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,120,-10,0,60,12},
};

// This part runs once at the start of the game.
void setup() {
  //Serial.begin(115200);
  gb.begin();
// we take the game progress from the block zero
  lastLevelWon = gb.save.get(0);
}

/*
void updateFPS() {

    static uint32_t last_sec;

    uint32_t sec = millis() / 1000;

    if (sec != last_sec) {

        fps = frame_count;
        frame_count = 0;
        last_sec = sec;

    }

    frame_count++;

}
*/

void drawRemainingMoves() {

  // This instance is created in memory only as long as necessary.
  // There is no need to keep this instance outside this function.
  Image digit(NB_DATA);

  // Then we convert `remainingMoves` in a string to be able
  // to browse each of its characters one by one.
  char moves[3]; // 2 + 1 (for the string termination character `\0`)
  snprintf(moves, 3, "%02u", remainingMoves);

  // It is assumed that `remainingMoves` will always be less than 100
  // and therefore be expressed by 1 or 2 characters.
  if (remainingMoves < 10 ) {
    digit.setFrame(moves[1] - '0');
    gb.display.drawImage(7, 115, digit);
  } else {
    digit.setFrame(moves[0] - '0');
    gb.display.drawImage(4, 115, digit);
    digit.setFrame(moves[1] - '0');
    gb.display.drawImage(10, 115, digit);
  }

}

void drawLevelNumber() {
  // This instance is created in memory only as long as necessary.
  // There is no need to keep this instance outside this function.
  Image level(LEVEL_NB_DATA);
  level.setFrame(levelNumber - 1);
  gb.display.drawImage(144, 114, level);
}

void drawHUD() {

  drawRemainingMoves();
  drawLevelNumber();

}


// This is the death animation,
// when the hero moves once too often.
void drawDeath() {
  if(deathCounter == 0) {
    gb.lights.fill(WHITE);
  }

  if(deathCounter < 3) {
    gb.display.fill(DARKGRAY);
    gb.display.setColor(WHITE);
    gb.display.fillCircle(columnPlayer*16, (rowPlayer*16)-8, 16);
  }

  if((deathCounter > 2) && (deathCounter < 6)) {
    gb.display.fill(BLACK);
    gb.display.drawImage((columnPlayer*16)-24, (rowPlayer*16)-16, deathHoleBig);
    gb.display.setColor(WHITE);
    gb.display.fillRect((columnPlayer*16)-14, 0, 28, (rowPlayer*16)-16);
  }

  if(deathCounter > 5) {
    gb.display.fill(BLACK);
    gb.display.drawImage((columnPlayer*16)-24, (rowPlayer*16)-16, deathHoleSmall);
    gb.display.setColor(WHITE);
    gb.display.fillRect((columnPlayer*16)-8, 0, 16, (rowPlayer*16)-16);
    if(heroTurnsRight) {
      gb.display.drawImage((columnPlayer*16)-8, (rowPlayer*16)-20-(skullCounter/2), heroDeadRight);
    } else {
      gb.display.drawImage((columnPlayer*16)-8, (rowPlayer*16)-20-(skullCounter/2), heroDeadLeft);
    }
    skullCounter = skullCounter + 1;
  }

  if(deathCounter == 10) {
    clap = true;
  }

  deathCounter = deathCounter + 1;
  
  
}

// Title clap animation
// (after we die or when we reset a level)
void drawClap() {
  if(clapCounter < 12) {
    gb.display.drawImage(0, (clapCounter*6)-64, DEMON160x64);
    gb.display.drawImage(0, 128-(clapCounter*6), GIRLS160x64);
   
// sound of shock when the two parts meet
    if(clapCounter == 11) {
      gb.sound.fx(kickOnly);
    }
  }
  
  if((clapCounter > 11) && (clapCounter < 33)) {
    gb.display.drawImage(0, 0, DEMON160x64);
    gb.display.drawImage(0, 64, GIRLS160x64);

    if((gamestate == 1) || (gamestate == 2) || (gamestate == 3) || (gamestate == 5)) {
      if(levelNumber <= TOTAL_LEVELS) {
        gamestate = 1; // hell levels
//        track = gb.sound.play("Vitality.wav", true);
      } else {
        gamestate = 4; // credits
      }
    }
    
    if(clapCounter == 22) {
      changeLevel();
      heroKicks = false;
      deathCounter = 0;
      skullCounter = 0;
      fromBadScreen = false;
      startRainbow = true;
    }
    answered = 0;
  }

  if(clapCounter > 32) {
    gb.display.drawImage(0, 0-((clapCounter-33)*6), DEMON160x64);
    gb.display.drawImage(0, 64+((clapCounter-33)*6), GIRLS160x64);
  }

  clapCounter = clapCounter + 1;

  if(clapCounter > 43) {
    clapCounter = 0;
    clap = false;
    bigDemon = 8;
  }
}

// graphic function of the hell game part
void drawGraphics() {
// We paint all the screen in purple.
  gb.display.clear(PURPLE);

// We draw the secret letters hidden under some blocks
  if(fromBadScreen == false) {
    secretLetters();
  }

// The back lights flash in purple if teeth hurt
  if(redFlash == 1) {
    gb.lights.fill(PURPLE);
  }

// 'M' wall, '@' player, ' ' ground, 'S' Skeleton,
// 'B' block, 'D' demon girl, 'K' key, 'L' lock, 'H' holes

// Each of the level boxes is displayed.
  for (int row=0; row<NB_ROWS_LEVELS; row++) {
    for (int column=0; column<NB_COLUMNS_LEVELS; column++) {
      switch (level[row][column]) {
        case 'M':
          drawWall(row, column);
          break;
        case '@':
          drawPlayer(row, column);
          break;
        case 'S':
          drawSkeleton(row, column);
          break;
        case 'B':
          drawBlock(row, column);
          break;
        case 'D':
          drawDemon(row, column);
          break;
        case 'K':
          drawKey(row, column);
          break;
        case 'L':
          drawLock(row, column);
          break;
        case 'T': // those don't move
          drawTeeth(row, column);
          break;
        case ' ':
// If ground, we draw nothing (gb.display.clear() color).
          break;
        case 'a': // those teeth don't move
          drawPlayerOnTeeth(row, column);
          break;
        case 'b':
          if(evenNumber == true) {
            drawPlayerOnTeeth(row, column);
          } else {
            drawPlayerOnHoles(row, column);
          }
          break;
        case 'c':
          if(evenNumber == false) {
            drawPlayerOnTeeth(row, column);
          } else {
            drawPlayerOnHoles(row, column);
          }
          break;
        case 'd':
          drawBlockOnTeeth(row, column);
          break;
        case 'e':
          if(evenNumber == true) {
            drawBlockOnTeeth(row, column);
          } else {
            drawBlockOnHoles(row, column);
          }
          break;
        case 'f':
          if(evenNumber == false) {
            drawBlockOnTeeth(row, column);
          } else {
            drawBlockOnHoles(row, column);
          }
          break;
        case 'g':
          drawHoles(row, column);
          drawSkeleton(row, column);
          break;
        case 'h':
          drawHoles(row, column);
          drawSkeleton(row, column);
          break;
        case 'i':
          drawBlockOnKey(row, column);
          break;
        case 'j':
          drawKey(row, column);
          drawSkeleton(row, column);
          break;
        case 'k':
          if(evenNumber == true) {
            drawTeeth(row, column);
          } else {
            drawHoles(row, column);
          }
          break;
        case 'l':
          if(evenNumber == false) {
            drawTeeth(row, column);
          } else {
            drawHoles(row, column);
          }
          break; 
        default:
          break;
      }
    }
  }

// We draw the HUD
  drawHUD();
  
}

// Graphics in the hell levels
void drawWall(int row, int column) {
  switch (walls[row][column]) {
    case 'a':
      gb.display.drawImage(column*16 - 8, row*16 - 16, wall_a);
    break;
    case 'b':
      gb.display.drawImage(column*16 - 8, row*16 - 16, wall_b);
    break;
    case 'c':
      gb.display.drawImage(column*16 - 8, row*16 - 16, wall_c);
    break;
    case 'd':
      gb.display.drawImage(column*16 - 8, row*16 - 16, wall_d);
    break;
    case 'e':
      gb.display.drawImage(column*16 - 8, row*16 - 16, wall_e);
    break;
    case 'f':
      gb.display.drawImage(column*16 - 8, row*16 - 16, wall_f);
    break;
    case 'g':
      gb.display.drawImage(column*16 - 8, row*16 - 16, wall_g);
    break;
    case 'h':
      gb.display.drawImage(column*16 - 8, row*16 - 16, wall_h);
    break;
    case 'i':
      gb.display.drawImage(column*16 - 8, row*16 - 16, wall_i);
    break;
    case 'j':
      gb.display.drawImage(column*16 - 8, row*16 - 16, wall_j);
    break;
    case 'k':
      gb.display.drawImage(column*16 - 8, row*16 - 16, wall_k);
    break;
    case 'l':
      gb.display.drawImage(column*16 - 8, row*16 - 16, wall_l);
    break;
    case 'm':
      gb.display.drawImage(column*16 - 8, row*16 - 16, wall_m);
    break;
    case 'n':
      gb.display.drawImage(column*16 - 8, row*16 - 16, wall_n);
    break;
    case 'o':
      gb.display.drawImage(column*16 - 8, row*16 - 16, wall_o);
    break;
    case 'p':
      gb.display.drawImage(column*16 - 8, row*16 - 16, wall_p);
    break;
    default:
      gb.display.drawImage(column*16 - 8, row*16 - 16, wall_a);
    break;
  }
}

void drawPlayer(int row, int column) {
  if(slipMode == false) {
    if (heroTurnsRight) {
      if(heroKicks == true) {
        gb.display.drawImage(column*16 - 8, row*16 - 16, heroKicksRight);
      } else {
        gb.display.drawImage(column*16 - 8, row*16 - 16, heroRight);
      }
    } else {
      if(heroKicks == true) {
        gb.display.drawImage(column*16 - 8, row*16 - 16, heroKicksLeft);
      } else {
        gb.display.drawImage(column*16 - 8, row*16 - 16, heroLeft);
      }
    }
  } else {
    if (heroTurnsRight) {
      if(heroKicks == true) {
        gb.display.drawImage(column*16 - 8, row*16 - 16, heroNippleKicksRight);
      } else {
        gb.display.drawImage(column*16 - 8, row*16 - 16, heroNippleRight);
      }
    } else {
      if(heroKicks == true) {
        gb.display.drawImage(column*16 - 8, row*16 - 16, heroNippleKicksLeft);
      } else {
        gb.display.drawImage(column*16 - 8, row*16 - 16, heroNippleLeft);
      }
    } 
  }
}

void drawPlayerOnTeeth(int row, int column) {
  gb.display.drawImage(column*16 - 8, row*16 - 16, teeth_down);
  gb.display.drawImage(column*16 - 8, row*16 - 16, teeth_down);
  if(redFlash > 0) {
    if (heroTurnsRight) {
      gb.display.drawImage(column*16 - 8, row*16 - 16, heroRightRed);
    } else {
      gb.display.drawImage(column*16 - 8, row*16 - 16, heroRightRed, -16, 16);
    }
  } else {
    if(slipMode == false) {
      if (heroTurnsRight) {
        if(heroKicks == true) {
          gb.display.drawImage(column*16 - 8, row*16 - 16, heroKicksRight);
        } else {
          gb.display.drawImage(column*16 - 8, row*16 - 16, heroRight);
        }
      } else {
        if(heroKicks == true) {
          gb.display.drawImage(column*16 - 8, row*16 - 16, heroKicksLeft);
        } else {
          gb.display.drawImage(column*16 - 8, row*16 - 16, heroLeft);
        }
      }
    } else {
      if (heroTurnsRight) {
        if(heroKicks == true) {
          gb.display.drawImage(column*16 - 8, row*16 - 16, heroNippleKicksRight);
        } else {
          gb.display.drawImage(column*16 - 8, row*16 - 16, heroNippleRight);
        }
      } else {
        if(heroKicks == true) {
          gb.display.drawImage(column*16 - 8, row*16 - 16, heroNippleKicksLeft);
        } else {
          gb.display.drawImage(column*16 - 8, row*16 - 16, heroNippleLeft);
        }
      }
    }
  }
//  gb.display.drawImage(column*16 - 8, row*16 - 16, teeth_down);
}

void drawPlayerOnHoles(int row, int column) {
  gb.display.drawImage(column*16 - 8, row*16 - 16, holes_up);
  gb.display.drawImage(column*16 - 8, row*16 - 16, holes_down);
  if(slipMode == false) {
    if (heroTurnsRight) {
      if(heroKicks == true) {
        gb.display.drawImage(column*16 - 8, row*16 - 16, heroKicksRight);
      } else {
        gb.display.drawImage(column*16 - 8, row*16 - 16, heroRight);
      }
    } else {
      if(heroKicks == true) {
        gb.display.drawImage(column*16 - 8, row*16 - 16, heroKicksLeft);
      } else {
        gb.display.drawImage(column*16 - 8, row*16 - 16, heroLeft);
      }
    }
  } else {
    if (heroTurnsRight) {
      if(heroKicks == true) {
        gb.display.drawImage(column*16 - 8, row*16 - 16, heroNippleKicksRight);
      } else {
        gb.display.drawImage(column*16 - 8, row*16 - 16, heroNippleRight);
      }
    } else {
      if(heroKicks == true) {
        gb.display.drawImage(column*16 - 8, row*16 - 16, heroNippleKicksLeft);
      } else {
        gb.display.drawImage(column*16 - 8, row*16 - 16, heroNippleLeft);
      }
    }
  }
//  gb.display.drawImage(column*16 - 8, row*16 - 16, holes_down);
}

void drawSkeleton(int row, int column) {
  gb.display.drawImage(column*16 - 8, row*16 - 16, Skeleton);
}

void drawSkeletonAndKey(int row, int column) {
  gb.display.drawImage(column*16 - 8, row*16 - 16, key);
  gb.display.drawImage(column*16 - 8, row*16 - 16, Skeleton);
}

void drawBlock(int row, int column) {
  gb.display.drawImage(column*16 - 8, row*16 - 16, block);
}

void drawBlockOnTeeth(int row, int column) {
  gb.display.drawImage(column*16 - 8, row*16 - 16, block);
  gb.display.drawImage(column*16 - 8, row*16 - 16, teeth_down);
}

void drawBlockOnHoles(int row, int column) {
  gb.display.drawImage(column*16 - 8, row*16 - 16, block);
  gb.display.drawImage(column*16 - 8, row*16 - 16, holes_down);
}

void drawBlockOnKey(int row, int column) {
  gb.display.drawImage(column*16 - 8, row*16 - 16, key);
  gb.display.drawImage(column*16 - 8, row*16 - 16, block);
}

void drawKey(int row, int column) {
  gb.display.drawImage(column*16 - 8, row*16 - 16, key);
}

void drawBlockAndKey(int row, int column) {
  gb.display.drawImage(column*16 - 8, row*16 - 16, key);
  gb.display.drawImage(column*16 - 8, row*16 - 16, block);
}

void drawLock(int row, int column) {
  gb.display.drawImage(column*16 - 8, row*16 - 16, lock);
}

void drawTeeth(int row, int column) {
  gb.display.drawImage(column*16 - 8, row*16 - 16, teeth_up);
  gb.display.drawImage(column*16 - 8, row*16 - 16, teeth_down);
}

void drawHoles(int row, int column) {
  gb.display.drawImage(column*16 - 8, row*16 - 16, holes_up);
  gb.display.drawImage(column*16 - 8, row*16 - 16, holes_down);
}

void drawDemon(int row, int column) {
// The ten demon girls match to each level.
  switch (levelNumber) {
    case 1:
      gb.display.drawImage(column*16 - 8, row*16 - 16, Pandemonica);
    break;
    case 2:
      gb.display.drawImage(column*16 - 8, row*16 - 16, Modeus);
    break;
    case 3:
      gb.display.drawImage(column*16 - 8, row*16 - 16, Cerberus);
    break;
    case 4:
      gb.display.drawImage(column*16 - 8, row*16 - 16, Malina);
    break;
    case 5:
      gb.display.drawImage(column*16 - 8, row*16 - 16, Zdrada);
    break;
    case 6:
      gb.display.drawImage(column*16 - 8, row*16 - 16, Azazel);
    break;
    case 7:
      gb.display.drawImage(column*16 - 8, row*16 - 16, Justice);
    break;
    case 8:
      gb.display.drawImage(column*16 - 8, row*16 - 16, Lucifer);
    break;
    case 9:
      gb.display.drawImage(column*16 - 8, row*16 - 16, Judgement);
    break;
    case 10:
      gb.display.drawImage(column*16 - 8, row*16 - 16, Beelzebub);
    break;
    default:
      gb.display.drawImage(column*16 - 8, row*16 - 16, Beelzebub);
    break;
  }
}

// Inputs

#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4

// Next row function
int nr(int Direction, int nb) {
  switch (Direction) {
    case UP:
    return rowPlayer - nb;
    break;
    case DOWN:
    return rowPlayer + nb;
    break;
    default:
    return rowPlayer;
    break;
  }
}

// Next column function
int nc(int Direction, int nb) {
  switch (Direction) {
    case RIGHT:
    return columnPlayer + nb;
    break;
    case LEFT:
    return columnPlayer - nb;
    break;
    default:
    return columnPlayer;
    break;
  }
}

// shortcut next box
#define NEXT(DIR,NB) level[nr(DIR,NB)][nc(DIR,NB)]

// We update the box that the player just leaves
void previousBox() {
        if(level[rowPlayer][columnPlayer] == '@') {
          level[rowPlayer][columnPlayer] = ' ';
        }
        if(level[rowPlayer][columnPlayer] == 'a') {
          level[rowPlayer][columnPlayer] = 'T';
        }
        if(level[rowPlayer][columnPlayer] == 'b') {
          level[rowPlayer][columnPlayer] = 'k';
        }
        if(level[rowPlayer][columnPlayer] == 'c') {
          level[rowPlayer][columnPlayer] = 'l';
        }
        if(level[rowPlayer][columnPlayer] == '+') {
          level[rowPlayer][columnPlayer] = '.';
        }
}

// We hurt the player if he is on teeth
void teethHurt() {
  if(((level[rowPlayer][columnPlayer] == 'a') || ((level[rowPlayer][columnPlayer] == 'b') && (evenNumber == true)) || ((level[rowPlayer][columnPlayer] == 'c') && (evenNumber == false))) && (remainingMoves > 0)) {
      remainingMoves = remainingMoves - 1;
      redFlash = 2;
//      gb.lights.fill(RED);
    }
}

// We move the player and the other items in the levels
void moveTo(int dir) {

// If next box is wall…
  if(NEXT(dir,1) == 'M') {
// … we don't move the player.
  return;
  }
  
// If the two next boxes are blocks…
  if( ( (NEXT(dir,1) == 'B') || (NEXT(dir,1) == 'd') || (NEXT(dir,1) == 'e') || (NEXT(dir,1) == 'f') || (NEXT(dir,1) == 'i') ) && ( (NEXT(dir,2) == 'B') || (NEXT(dir,2) == 'd') || (NEXT(dir,2) == 'e') || (NEXT(dir,2) == 'f') || (NEXT(dir,2) == 'i') || (NEXT(dir,2) == 'L') || (NEXT(dir,2) == 'D') || (NEXT(dir,2) == 'S') ) ) {
// … we don't move the player, but he kicks the block and counts a move.
    heroKicks = true;
//    gb.sound.playTick();
    gb.sound.fx(kickOnly);
    if(remainingMoves > 0) {
      remainingMoves = remainingMoves - 1;
      if(evenNumber == true) {
        evenNumber = false;
      } else {
        evenNumber = true;
      }
    } else {
      death = true;
//      drawDeath();
//      gb.sound.playCancel();
      gb.sound.fx(lightningStrike);
    }
// We check if the player is hurted by teeth
    teethHurt();
// If the remaining moves counter is zero, we lose.
  if(remainingMoves == 0) {
    death = true;
//    drawDeath();
//    gb.sound.playCancel();
    gb.sound.fx(lightningStrike);
    return;
  }
    return;    
  }

// If the two next boxes are a block and a wall…
  if( ( (NEXT(dir,1) == 'B')  || (NEXT(dir,1) == 'd') || (NEXT(dir,1) == 'e') || (NEXT(dir,1) == 'f') || (NEXT(dir,1) == 'i') ) && (NEXT(dir,2) == 'M') ) {
// … we don't move the player, but he kicks the block and counts a move.
    heroKicks = true;
//    gb.sound.playTick();
    gb.sound.fx(kickOnly);
    if(remainingMoves > 0) {
      remainingMoves = remainingMoves - 1;
      if(evenNumber == true) {
        evenNumber = false;
      } else {
        evenNumber = true;
      }
    } else {
      death = true;
//      drawDeath();
//      gb.sound.playCancel();
      gb.sound.fx(lightningStrike);
    }
// We check if the player is hurted by teeth
    teethHurt();
// If the remaining moves counter is zero, we lose.
  if(remainingMoves == 0) {
    death = true;
//    drawDeath();
//    gb.sound.playCancel();
    gb.sound.fx(lightningStrike);
    return;
  }
    return;    
  }

// If the two next boxes are a block and a skeleton…
  if( (NEXT(dir,1) == 'B') && (NEXT(dir,2) == 'S') ) {
// … we don't move the player, but he kicks the block and counts a move.
    heroKicks = true;
//    gb.sound.playTick();
    gb.sound.fx(kickOnly);
    if(remainingMoves > 0) {
      remainingMoves = remainingMoves - 1;
      if(evenNumber == true) {
        evenNumber = false;
      } else {
        evenNumber = true;
      }
    } else {
      death = true;
//      drawDeath();
//      gb.sound.playCancel();
      gb.sound.fx(lightningStrike);
    }
// We check if the player is hurted by teeth
    teethHurt();
// If the remaining moves counter is zero, we lose.
  if(remainingMoves == 0) {
    death = true;
//    drawDeath();
//    gb.sound.playCancel();
    gb.sound.fx(lightningStrike);
    return;
  }
    return;    
  }

// If next box is lock and we don't have the key…
  if( (NEXT(dir,1) == 'L') && (hasKey == false) ) {
// … we don't move the player, but he kicks the lock and counts a move.
    heroKicks = true;
//    gb.sound.playTick();
    gb.sound.fx(kickOnly);
    if(remainingMoves > 0) {
      remainingMoves = remainingMoves - 1;
      if(evenNumber == true) {
        evenNumber = false;
      } else {
        evenNumber = true;
      }
    } else {
      death = true;
//      drawDeath();
//      gb.sound.playCancel();
      gb.sound.fx(lightningStrike);
    }
// We check if the player is hurted by teeth
    teethHurt();
// If the remaining moves counter is zero, we lose.
  if(remainingMoves == 0) {
    death = true;
//    drawDeath();
//    gb.sound.playCancel();
    gb.sound.fx(lightningStrike);
    return;
  }
  return;
  }

// If the remaining moves counter is zero, we lose.
  if(remainingMoves == 0) {
    death = true;
//    drawDeath();
//    gb.sound.playCancel();
    gb.sound.fx(lightningStrike);
    return;
  }

// We know that movement is allowed.

  if(remainingMoves > 0) {
    remainingMoves = remainingMoves - 1;
    if(evenNumber == true) {
      evenNumber = false;
    } else {
      evenNumber = true;
    }
  }

// If next box is a block…
  if((NEXT(dir,1) == 'B') || (NEXT(dir,1) == 'd') || (NEXT(dir,1) == 'e') || (NEXT(dir,1) == 'f') || (NEXT(dir,1) == 'i')) {
    {
// … the player kicks it…
      heroKicks = true;
//      gb.sound.playTick();
      gb.sound.fx(pushSkeleton);
// … we move the block to the next box…
      if(NEXT(dir,2) == ' ') {
        NEXT(dir,2) = 'B';
      } else if(NEXT(dir,2) == 'K') {
        NEXT(dir,2) = 'i';
      } else if(NEXT(dir,2) == 'T') {
        NEXT(dir,2) = 'd';
      } else if(NEXT(dir,2) == 'k') {
        NEXT(dir,2) = 'e';
      } else if(NEXT(dir,2) == 'l') {
        NEXT(dir,2) = 'f';
      }
    }

// … and we take off the block from its previous location.
    if(NEXT(dir,1) == 'B') {
      NEXT(dir,1) = ' ';
    } else if (NEXT(dir,1) == 'i') {
      NEXT(dir,1) = 'K';
    } else if (NEXT(dir,1) == 'd') {
      NEXT(dir,1) = 'T';
    } else if (NEXT(dir,1) == 'e') {
      NEXT(dir,1) = 'k';
    } else if (NEXT(dir,1) == 'f') {
      NEXT(dir,1) = 'l';
    }

// We check if the player is hurted by teeth
    teethHurt();
// If the remaining moves counter is zero, we lose.
  if(remainingMoves == 0) {
    death = true;
//    drawDeath();
//    gb.sound.playCancel();
    gb.sound.fx(lightningStrike);
    return;
  }
    return;
  }

// If next box is a skeleton…
    if(NEXT(dir,1) == 'S') {
// … the player kicks it…
      heroKicks = true;
//      gb.sound.playTick();
      gb.sound.fx(pushSkeleton);
    {
// … and if the box after it is empty…
      if(NEXT(dir,2) == ' ') {
// … we move the skeleton to this next box.
        NEXT(dir,2) = 'S';
      } else {
// if there is no more skeleton
// we hear the sound of its death
        gb.sound.fx(skeletonBreak);
      }
    }
// We take off the skeleton from its previous location.
    if(NEXT(dir,1) == 'S') {
      NEXT(dir,1) = ' ';
    }
// We check if the player is hurted by teeth
    teethHurt();
// If the remaining moves counter is zero, we lose.
  if(remainingMoves == 0) {
    death = true;
//    drawDeath();
//    gb.sound.playCancel();
    gb.sound.fx(lightningStrike);
    return;
  }
    return;
    }
    
// If next box is empty…
      if(NEXT(dir,1) == ' ') {
//        gb.sound.playTick();
        gb.sound.fx(simpleMove);
// … we put a player to this next box…
        NEXT(dir,1) = '@';
// … and we take off the player from its previous location.
        previousBox();
// We update the player coordinates.
        rowPlayer = nr(dir,1);
        columnPlayer = nc(dir,1);
        return;
      }

// If next box is teeth…
      if(NEXT(dir,1) == 'T') {
//        gb.sound.playTick();
        gb.sound.fx(moveAndTeeth);
// The backlights flash in red
        redFlash = 2;
//        gb.lights.fill(RED);
// … we put a player to this next box…
        NEXT(dir,1) = 'a';
// … and we take off the player from its previous location.
        previousBox();
// We update the player coordinates.
        rowPlayer = nr(dir,1);
        columnPlayer = nc(dir,1);
// The teeth hurt the player
        if(remainingMoves > 0) {
          remainingMoves = remainingMoves - 1;
        } else if(remainingMoves == 0) {
          death = true;
//          drawDeath();
//          gb.sound.playCancel();
          gb.sound.fx(lightningStrike);
          return;
        }
        return;
      }

// If next box is even number teeth…
//      gb.sound.playTick();
      gb.sound.fx(simpleMove);
      
      if(NEXT(dir,1) == 'k') {

// … we put a player to this next box…
        NEXT(dir,1) = 'b';
// … and we take off the player from its previous location.
        previousBox();
// We update the player coordinates.
        rowPlayer = nr(dir,1);
        columnPlayer = nc(dir,1);
// The teeth hurt the player
        if((remainingMoves > 0) && (evenNumber == true)) {
          remainingMoves = remainingMoves - 1;
          gb.sound.fx(moveAndTeeth);
// The backlights flash in red
          redFlash = 2;
//          gb.lights.fill(RED);
        } else if((remainingMoves == 0) && (evenNumber == true)) {
          death = true;
//          drawDeath();
//          gb.sound.playCancel();
          gb.sound.fx(lightningStrike);
          return;
        }
        return;
      }

// If next box is odd number teeth…
//      gb.sound.playTick();
      gb.sound.fx(simpleMove);
      
      if(NEXT(dir,1) == 'l') {
// … we put a player to this next box…
        NEXT(dir,1) = 'c';
// … and we take off the player from its previous location.
        previousBox();
// We update the player coordinates.
        rowPlayer = nr(dir,1);
        columnPlayer = nc(dir,1);
// The teeth hurt the player
        if((remainingMoves > 0) && (evenNumber == false)) {
          remainingMoves = remainingMoves - 1;
          gb.sound.fx(moveAndTeeth);
// The backlights flash in red
          redFlash = 2;
//          gb.lights.fill(RED);
        } else if((remainingMoves == 0) && (evenNumber == false)) {
          death = true;
//          drawDeath();
//          gb.sound.playCancel();
          gb.sound.fx(lightningStrike);
          return;
        }
        return;
      }
      
// If next box is key…
//      gb.sound.playOK();
      gb.sound.fx(keySound);
      if(NEXT(dir,1) == 'K') {
// … we put the player to the next box…
        NEXT(dir,1) = '@';
// … and we take off the player from its previous location.
        previousBox();
// We update the player coordinates.
        rowPlayer = nr(dir,1);
        columnPlayer = nc(dir,1);
// And we tell the game the player has the key.
        hasKey = true;
// Yellow flash with LEDs
        gb.lights.fill(YELLOW);
        return;
      }

// If next box is lock and we have key…
//      gb.sound.playOK();
      gb.sound.fx(openALock);
      if( (NEXT(dir,1) == 'L') && (hasKey == true) ) {
// … we put the player to the next box…
        NEXT(dir,1) = '@';
// … and we take off the player from its previous location.
        previousBox();
// We update the player coordinates.
        rowPlayer = nr(dir,1);
        columnPlayer = nc(dir,1);
// Yellow flash with LEDs
        gb.lights.fill(YELLOW);
        return;
      }
}

// We decide which sprite goes with which wall.
void updateWalls() {
  for (int row=1; row<(NB_ROWS_LEVELS-1); row++) {
    for (int column=1; column<(NB_COLUMNS_LEVELS-1); column++) {
      if(level[row-1][column] == 'M') {
        if(level[row][column+1] == 'M') {
          if(level[row+1][column] == 'M') {
            if(level[row][column-1] == 'M') {
              walls[row][column] = 'a';
            } else {
              walls[row][column] = 'b';
            }
          } else {
            if(level[row][column-1] == 'M') {
              walls[row][column] = 'c';
            } else {
              walls[row][column] = 'd';
            }
          }
        } else {
          if(level[row+1][column] == 'M') {
            if(level[row][column-1] == 'M') {
              walls[row][column] = 'e';
            } else {
              walls[row][column] = 'f';
            }
          } else {
            if(level[row][column-1] == 'M') {
              walls[row][column] = 'g';
            } else {
              walls[row][column] = 'h';
            }
          }
        }
      } else {
        if(level[row][column+1] == 'M') {
          if(level[row+1][column] == 'M') {
            if(level[row][column-1] == 'M') {
              walls[row][column] = 'i';
            } else {
              walls[row][column] = 'j';
            }
          } else {
            if(level[row][column-1] == 'M') {
              walls[row][column] = 'k';
            } else {
              walls[row][column] = 'l';
            }
          }
        } else {
          if(level[row+1][column] == 'M') {
            if(level[row][column-1] == 'M') {
              walls[row][column] = 'm';
            } else {
              walls[row][column] = 'n';
            }
          } else {
            if(level[row][column-1] == 'M') {
              walls[row][column] = 'o';
            } else {
              walls[row][column] = 'p';
            }
          }
        }
      }
    }
  }

// Set the border walls.
// Left line.
  for (int row=0; row<(NB_ROWS_LEVELS); row++) {
    if(level[row][1] == 'M') {
      walls[row][0] = 'a';
    } else {
      walls[row][0] = 'e';
    }
  }
// Right line.
  for (int row=0; row<(NB_ROWS_LEVELS); row++) {
    if(level[row][NB_COLUMNS_LEVELS - 2] == 'M') {
      walls[row][NB_COLUMNS_LEVELS - 1] = 'a';
    } else {
      walls[row][NB_COLUMNS_LEVELS - 1] = 'b';
    }
  }
// Top line.
  for (int column=0; column<(NB_COLUMNS_LEVELS); column++) {
    if(level[1][column] == 'M') {
      walls[0][column] = 'a';
    } else {
      walls[0][column] = 'c';
    }
  }
// Bottom line.
  for (int column=0; column<(NB_COLUMNS_LEVELS); column++) {
    if(level[NB_ROWS_LEVELS - 2][column] == 'M') {
      walls[NB_ROWS_LEVELS - 1][column] = 'a';
    } else {
      walls[NB_ROWS_LEVELS - 1][column] = 'i';
    }
  }
}

// We reset the level or go to the next one.
void changeLevel() {
// Go to next level or reset level if dead.
  if((death == false) && (resetLevel == false) && (levelNumber <= TOTAL_LEVELS)) {
    levelNumber = levelNumber + 1;
  }
  resetLevel = false;

// Go to credits screen
  if((levelNumber > TOTAL_LEVELS) && (gamestate == 2)) {
    gamestate = 4;
  }

// We copy the selected constant level table to the variable level table.
  switch (levelNumber) {
    case 0:
    case 1:
      memcpy(level, level1, sizeof(level));
      rowPlayer = 2;
      columnPlayer = 7;
      remainingMoves = 23;
      heroTurnsRight = false;
    break;
    case 2:
      memcpy(level, level2, sizeof(level));
      rowPlayer = 6;
      columnPlayer = 2;
      remainingMoves = 24;
      heroTurnsRight = true;
    break;
    case 3:
      memcpy(level, level3, sizeof(level));
      rowPlayer = 4;
      columnPlayer = 9;
      remainingMoves = 32;
      heroTurnsRight = false;
    break;
    case 4:
      memcpy(level, level4, sizeof(level));
      rowPlayer = 3;
      columnPlayer = 2;
      remainingMoves = 23;
      heroTurnsRight = true;
    break;
    case 5:
      memcpy(level, level5, sizeof(level));
      rowPlayer = 4;
      columnPlayer = 2;
      remainingMoves = 23;
      heroTurnsRight = true;
    break;
    case 6:
      memcpy(level, level6, sizeof(level));
      rowPlayer = 1;
      columnPlayer = 4;
      remainingMoves = 43;
      heroTurnsRight = true;
    break;
    case 7:
      memcpy(level, level7, sizeof(level));
      rowPlayer = 6;
      columnPlayer = 8;
      remainingMoves = 32;
      heroTurnsRight = false;
    break;
    case 8:
      memcpy(level, level8, sizeof(level));
      rowPlayer = 8;
      columnPlayer = 5;
      remainingMoves = 8;
      heroTurnsRight = true;
    break;
    case 9:
      memcpy(level, level9, sizeof(level));
      rowPlayer = 7;
      columnPlayer = 2;
      remainingMoves = 33;
      heroTurnsRight = true;
    break;
    case 10:
      memcpy(level, level10, sizeof(level));
      rowPlayer = 6;
      columnPlayer = 8;
      remainingMoves = 42;
      heroTurnsRight = false;
    break;
    default:
    break;
  }

// Walls sprites function
  updateWalls();

// The player faces right.
//  heroTurnsRight = true;

// We revive the player.
  death = false;

// The player has not the key
  hasKey = false;

// Set the even number for the moving teeth
  if((remainingMoves % 2) == 0) {
    evenNumber = true;
  } else {
    evenNumber = false;
  }
}

// We check if a button is pressed and do something.
void inputs() {
  if(gb.buttons.pressed(BUTTON_UP)) {
    moveTo(UP);
  }

  if(gb.buttons.pressed(BUTTON_DOWN)) {
    moveTo(DOWN);
  }

  if(gb.buttons.pressed(BUTTON_RIGHT)) {
    heroTurnsRight = true;
    moveTo(RIGHT);
  }

  if(gb.buttons.pressed(BUTTON_LEFT)) {
    heroTurnsRight = false;
    moveTo(LEFT);
  }

// If direction buttons are released,
// the player stops to kick.
  if((gb.buttons.released(BUTTON_UP)) || (gb.buttons.released(BUTTON_DOWN)) || (gb.buttons.released(BUTTON_RIGHT)) || (gb.buttons.released(BUTTON_LEFT))) {
    heroKicks = false;
  }

// If hero next to a demon girl, go to dialogue
  if(((NEXT(1,1) == 'D') || (NEXT(2,1) == 'D') || (NEXT(3,1) == 'D') || (NEXT(4,1) == 'D') ) && (clap == false)) {
    if(levelFinished == false) {
//      gb.sound.playOK();
    }
    levelFinished = true;
  }

// If B button is pressed, reset the level
  if(gb.buttons.pressed(BUTTON_B)) {
    resetLevel = true;
    clap = true;
  }
  
}

// draw free RAM
/*
void drawFreeRam() {
  gb.display.setFontSize(1);
  gb.display.setColor(WHITE);
  gb.display.printf(2, 2, "RAM: %u", gb.getFreeRam());
//  gb.display.printf(2, 2, "%u", redFlash);
}
*/

// draw the demon girls in Hell dialogues
void drawBigDemon () {
  switch (levelNumber) {
    case 0:
      if((answered > 0) && (answered < 4)) {
        gb.display.drawImage(bigDemon*4 + 64, 0, theGreatFly, 32, 32);
      }
      if(answered > 4) {
        if(slipMode == false) {
          gb.display.drawImage(bigDemon*4 + 64, 0, heroRight, 32, 32);
        } else {
          gb.display.drawImage(bigDemon*4 + 64, 0, heroNippleRight, 32, 32);
        }
      }
      break;
    case 1:
      gb.display.drawImage(bigDemon*4 + 64, 0, Pandemonica, 32, 32);
      break;
    case 2:
      gb.display.drawImage(bigDemon*4 + 64, 0, Modeus, 32, 32);
      break;
    case 3:
      gb.display.drawImage(bigDemon*4 + 32, 0, Cerberus, 32, 32);
      gb.display.drawImage(bigDemon*4 + 64, 0, Cerberus, 32, 32);
      gb.display.drawImage(bigDemon*4 + 96, 0, Cerberus, 32, 32);
      break;
    case 4:
      gb.display.drawImage(bigDemon*4 + 64, 0, Malina, 32, 32);
      break;
    case 5:
      gb.display.drawImage(bigDemon*4 + 64, 0, Zdrada, 32, 32);
      break;
    case 6:
      gb.display.drawImage(bigDemon*4 + 64, 0, Azazel, 32, 32);
      break;
    case 7:
      gb.display.drawImage(bigDemon*4 + 64, 0, Justice, 32, 32);
      break;
    case 8:
      gb.display.drawImage(bigDemon*4 + 64, 0, Lucifer, 32, 32);
      if(answered < 5) {
        gb.display.drawImage(bigDemon*4 + 32, 0, SkeletonStill, 32, 32);
        gb.display.drawImage(bigDemon*4 + 96, 0, SkeletonStill, -32, 32);
      } else {
        gb.display.drawImage(bigDemon*4 + 32, 0, SkeletonLove, 32, 32);
        gb.display.drawImage(bigDemon*4 + 96, 0, SkeletonLove, -32, 32);
      }
      break;
    case 9:
      gb.display.drawImage(bigDemon*4 + 64, 0, Judgement, 32, 32);
      break;
    case 10:
      gb.display.drawImage(bigDemon*4 + 64, 0, Beelzebub, 32, 32);
      break;
  }
}

void demonText() {
  gb.display.setColor(RED);
  gb.display.setCursor(0, 40);
  gb.display.setFont(font5x7);
  gb.display.setFontSize(1);

  switch (levelNumber) {

// the Great Fly
    case 0:
      switch (answered) {
        case 0:
          gb.display.setColor(GRAY);
          gb.display.setCursorX(5);
          gb.display.print(F("    You find yourself\n"));
          gb.display.setCursorX(5);
          gb.display.print(F(" surrounded by the void."));
          break;
        case 1:
          gb.display.setCursorX(5);
          gb.display.print(F("  Greetings little one.\n"));
          gb.display.setCursorX(2);
          gb.display.print(F(" Please don't mind me. It\n"));
          gb.display.setCursorX(5);
          gb.display.print(F("   is just I, good old\n"));
          gb.display.setCursorX(2);
          gb.display.print(F("        Beelzebub."));
          break;
        case 2:
          gb.display.setCursorX(2);
          gb.display.print(F(" Story of the demon girls\n"));
          gb.display.setCursorX(5);
          gb.display.print(F("  again? Interesting..."));
          break;
        case 3:
          gb.display.setCursorX(2);
          gb.display.print(F("  Do you, by any chance,\n"));
          gb.display.setCursorX(2);
          gb.display.print(F("     need a narrator?"));
          break;
        case 4:
          gb.display.setCursorX(2);
          gb.display.print(F(" Why please, allow me. It\n"));
          gb.display.setCursorX(5);
          gb.display.print(F("   will be a pleasure."));
          break;
        case 5:
          gb.display.setCursorX(2);
          gb.display.print(F("You woke up one day with a\n"));
          gb.display.setCursorX(2);
          gb.display.print(F("dream. Harem full of demon\n"));
          gb.display.setCursorX(2);
          gb.display.print(F("          girls."));
          break;
        case 6:
          gb.display.setCursorX(5);
          gb.display.print(F(" It was, however, not an\n"));
          gb.display.setCursorX(5);
          gb.display.print(F("easy dream to achieve. It\n"));
          gb.display.setCursorX(5);
          gb.display.print(F("could cost you your life."));
          break;
      }
      if(answered > 6) {
        gb.display.setColor(WHITE);
        gb.display.setCursorX(5);
        gb.display.print(F("  \"When demon girls are\n"));
        gb.display.setCursorX(2);
        gb.display.print(F("involved, no price is high\n"));
        gb.display.setCursorX(2);
        gb.display.print(F("         enough.\"\n\n"));
        gb.display.setColor(RED);
        gb.display.setCursorX(5);
        gb.display.print(F("You said, as you ventured\n"));
        gb.display.setCursorX(5);
        gb.display.print(F("      down to Hell."));
        if(gb.buttons.pressed(BUTTON_A)) {
          clap = true;
        }
      }
      break;

// Pandemonica
    case 1:
    if(answered == 0) {
      gb.display.setCursorX(2);
      gb.display.print(F("Name's Pandemonica. Hell's\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("Customer Service. How may\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("       I serve you?\n\n\n"));
    } else {
      if(goodAnswer == true) {
        gb.display.setCursorX(2);
        gb.display.print(F(" You have your own house?\n"));
        gb.display.setCursorX(2);
        gb.display.print(F("  You don't live by your\n"));
        gb.display.setCursorX(2);
        gb.display.print(F("  parents? That's a good\n"));
        gb.display.setCursorX(2);
        gb.display.print(F("          point!"));
      } else {
        gb.display.setCursorX(5);
        gb.display.print(F("No way. I only date tough\n"));
        gb.display.setCursorX(5);
        gb.display.print(F("  guys. Go back to your\n"));
        gb.display.setCursorX(5);
        gb.display.print(F("     little flowers."));
      }
    }
    if(answered == 0) {
      gb.display.setColor(topAnswer?WHITE:GRAY);
      gb.display.setCursorX(5);
      gb.display.print(F(" We can figure something\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("     out at my place.\n\n"));
      gb.display.setColor(topAnswer?GRAY:WHITE);
      gb.display.setCursorX(5);
      gb.display.print(F("  Maybe I can serve YOU\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("         instead?"));
    }
    goodAnswer = topAnswer?true:false;
    break;

// Modeus
    case 2:
    if(answered == 0) {
      gb.display.setCursorX(2);
      gb.display.print(F("     You and me. Now."));
    } else {
      if(goodAnswer == true) {
        gb.display.setCursorX(2);
        gb.display.print(F("  You take the blacks. I\n"));
        gb.display.setCursorX(5);
        gb.display.print(F("  take the whites. It's\n"));
        gb.display.setCursorX(5);
        gb.display.print(F("       chess time!"));
      } else {
        gb.display.print(F("Other girls? I am the only\n"));
        gb.display.setCursorX(5);
        gb.display.print(F("    one, remember it!"));
      }
    }
    if(answered == 0) {
      gb.display.setColor(topAnswer?WHITE:GRAY);
      gb.display.print(F("\n\n\n\n\n"));
      gb.display.setCursorX(2);
      gb.display.print(F(" Deal. No question asked.\n\n\n"));
      gb.display.setColor(topAnswer?GRAY:WHITE);
      gb.display.setCursorX(5);
      gb.display.print(F(" No time. Busy gathering\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("          girls."));
    }
    goodAnswer = topAnswer?true:false;
    break;

// Cerberus
    case 3:
    if(answered == 0) {
      gb.display.setCursorX(5);
      gb.display.print(F("  Are you human? A real\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("  human? Please, take us\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("        with you!"));
    } else {
      if(goodAnswer == true) {
        gb.display.setCursorX(2);
        gb.display.print(F("Great! We love to talk. Do\n"));
        gb.display.setCursorX(5);
        gb.display.print(F("  you have an unlimited\n"));
        gb.display.setCursorX(2);
        gb.display.print(F("      phone package?"));
      } else {
        gb.display.setCursorX(5);
        gb.display.print(F(" Don't be in a hurry! We\n"));
        gb.display.setCursorX(5);
        gb.display.print(F(" have to know each other\n"));
        gb.display.setCursorX(5);
        gb.display.print(F("         before."));
      }
    }
    if(answered == 0) {
      gb.display.setColor(topAnswer?WHITE:GRAY);
      gb.display.print(F("\n\n\n"));
      gb.display.setCursorX(2);
      gb.display.print(F(" Deal. No question asked.\n\n\n"));
      gb.display.setColor(topAnswer?GRAY:WHITE);
      gb.display.setCursorX(5);
      gb.display.print(F("This is getting too easy.\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("    I have questions."));
    }
    goodAnswer = topAnswer?false:true;
    break;

// Malina
    case 4:
    if(answered == 0) {
      gb.display.setCursorX(5);
      gb.display.print(F("  Great, more braindead\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("idiots... Never seen your\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("ugly face before. What are\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("     you playing at?"));
    } else {
      if(goodAnswer == true) {
        gb.display.setCursorX(5);
        gb.display.print(F("Like what... video games?\n"));
        gb.display.setCursorX(5);
        gb.display.print(F("Sure, why not. As long as\n"));
        gb.display.setCursorX(2);
        gb.display.print(F("  you're okay with first\n"));
        gb.display.setCursorX(2);
        gb.display.print(F("     person shooters."));
      } else {
        gb.display.setCursorX(2);
        gb.display.print(F("Fantastic. Just my luck to\n"));
        gb.display.setCursorX(2);
        gb.display.print(F("  find another masochist\n"));
        gb.display.setCursorX(2);
        gb.display.print(F("          creep!"));
      }
    }
    if(answered == 0) {
      gb.display.setColor(topAnswer?WHITE:GRAY);
      gb.display.print(F("\n\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("I'd sure love to play with\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("           you."));
      gb.display.setColor(topAnswer?GRAY:WHITE);
      gb.display.print(F("\n\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("This is delicious. Please,\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("     insult me more!"));
    }
    goodAnswer = topAnswer?true:false;
    break;

// Zdrada
    case 5:
    if(answered == 0) {
      gb.display.setCursorX(5);
      gb.display.print(F("Yo. I've heard about your\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("      harem. I'm in!"));
    } else {
      if(goodAnswer == true) {
        gb.display.setCursorX(2);
        gb.display.print(F("Really? That's my favorite\n"));
        gb.display.setCursorX(5);
        gb.display.print(F("game category! Let's turn\n"));
        gb.display.setCursorX(2);
        gb.display.print(F("          it ON!"));
      } else {
        gb.display.setCursorX(5);
        gb.display.print(F("Do you mean I am not good\n"));
        gb.display.setCursorX(2);
        gb.display.print(F("  enough for you? That's\n"));
        gb.display.setCursorX(2);
        gb.display.print(F("        unberable!"));
      }
    }
    if(answered == 0) {
      gb.display.setColor(topAnswer?WHITE:GRAY);
      gb.display.print(F("\n\n\n\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("  Wait. I have a feeling\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("     I'll regret it.\n\n"));
      gb.display.setColor(topAnswer?GRAY:WHITE);
      gb.display.setCursorX(5);
      gb.display.print(F(" It's not really a harem\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("anymore. We just play FPS."));
    }
    goodAnswer = topAnswer?false:true;
    break;

// Azazel
    case 6:
    if(answered == 0) {
      gb.display.setColor(BLUE);
      gb.display.setCursorX(5);
      gb.display.print(F("Oh my heavens! What would\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("a living human be doing in\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("   Hell? Most unusual.\n\n\n"));
    } else {
      gb.display.setColor(BLUE);
      if(goodAnswer == true) {
        gb.display.setCursorX(2);
        gb.display.print(F("Oh, you too? Let me guess,\n"));
        gb.display.setCursorX(2);
        gb.display.print(F(" thesis on Modern Sin? Or\n"));
        gb.display.setCursorX(2);
        gb.display.print(F("   is it Demonology? We\n"));
        gb.display.setCursorX(5);
        gb.display.print(F("   should join forces."));
      } else {
        gb.display.setCursorX(5);
        gb.display.print(F(" You could search in the\n"));
        gb.display.setCursorX(5);
        gb.display.print(F("source code. But cheating\n"));
        gb.display.setCursorX(2);
        gb.display.print(F("  is really getting away\n"));
        gb.display.setCursorX(2);
        gb.display.print(F("     from perfection!"));
      }
    }
    if(answered == 0) {
      gb.display.setColor(topAnswer?WHITE:GRAY);
      gb.display.setCursorX(5);
      gb.display.print(F("   Looking for demons."));
      gb.display.setColor(topAnswer?GRAY:WHITE);
      gb.display.print(F("\n\n\n"));
      gb.display.setCursorX(2);
      gb.display.print(F(" Looking for cheat codes."));
    }
    goodAnswer = topAnswer?true:false;
    break;

// Justice
    case 7:
    if(answered == 0) {
      gb.display.setCursorX(2);
      gb.display.print(F("  Yo, did you just solve\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("   that puzzle? That's\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("         awesome!"));
    } else {
      if(goodAnswer == true) {
        gb.display.setCursorX(5);
        gb.display.print(F("You don't have to ask me.\n"));
        gb.display.setCursorX(5);
        gb.display.print(F(" I'd never miss a party!"));
      } else {
        gb.display.setCursorX(2);
        gb.display.print(F("You failed the gaming law!\n"));
        gb.display.setCursorX(2);
        gb.display.print(F("        How petty!"));
      }
    }
    if(answered == 0) {
      gb.display.setColor(topAnswer?WHITE:GRAY);
      gb.display.print(F("\n\n\n"));
      gb.display.setCursorX(2);
      gb.display.print(F(" It took some work. Wanna\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("      join my harem?\n\n"));
      gb.display.setColor(topAnswer?GRAY:WHITE);
      gb.display.setCursorX(5);
      gb.display.print(F("I just used a cheat code.\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("   Wanna join my harem?"));
    }
    goodAnswer = topAnswer?true:false;
    break;

// Lucifer
    case 8:
    if(answered == 0) {
      gb.display.setCursorX(5);
      gb.display.print(F(" We meet at last. You've\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("proved yourself worthy by\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("  passing all my trials."));
    }
    if(answered == 1) {
      gb.display.setCursorX(2);
      gb.display.print(F("Pledge your soul to me and\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("  I'll make you my most\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("     treasured slave.\n\n\n"));

      gb.display.setColor(topAnswer?WHITE:GRAY);
      gb.display.setCursorX(5);
      gb.display.print(F("      Yes my queen!\n\n\n"));
      gb.display.setColor(topAnswer?GRAY:WHITE);
      gb.display.setCursorX(5);
      gb.display.print(F(" No, thanks. But you can\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("      join my harem."));
    }
    if(answered == 2) {
      goodAnswer = topAnswer?false:true;
       if(goodAnswer == false) {
        gb.display.setCursorX(2);
        gb.display.print(F("   Eager little soul..."));
      } else {
        answered = 3;
        topAnswer = true;
      }
    }
    if(answered == 3) {
      gb.display.setCursorX(2);
      gb.display.print(F("  What are you trying to\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("accomplish? You think you\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("can enslave demons to your\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("          will?"));
       
      gb.display.setColor(topAnswer?WHITE:GRAY);
      gb.display.print(F("\n\n"));
      gb.display.setCursorX(2);
      gb.display.print(F(" Call me Badger. And read\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("my book to know the Truth."));
      gb.display.setColor(topAnswer?GRAY:WHITE);
      gb.display.print(F("\n\n"));
      gb.display.setCursorX(2);
      gb.display.print(F(" I can offer fruit juices\n"));
      if(slipMode == false) {
        gb.display.setCursorX(5);
        gb.display.print(F(" and chocolate pancakes."));
      } else {
        gb.display.setCursorX(2);
        gb.display.print(F("   and white underwear."));
      }
    }
    if(answered == 4) {
      goodAnswer = topAnswer?false:true;
      if(goodAnswer == true) {
        gb.display.setCursorX(5);
        gb.display.print(F(" Really? Is that it? You\n"));
        gb.display.setCursorX(5);
        gb.display.print(F("come here, and try to buy\n"));
        if(slipMode == false) {
          gb.display.setCursorX(2);
          gb.display.print(F("  me over with pancakes?"));
        } else {
          gb.display.setCursorX(5);
          gb.display.print(F(" me over with underwear?"));
        }
      } else {
        gb.display.setCursorX(5);
        gb.display.print(F(" You really think I have\n"));
        gb.display.setCursorX(5);
        gb.display.print(F("   time to read books,\n"));
        gb.display.setCursorX(2);
        gb.display.print(F(" running Hell and dealing\n"));
        gb.display.setCursorX(5);
        gb.display.print(F("   with all this mess?"));
      }
    }
    if(answered > 4) {
      gb.display.setCursorX(2);
      gb.display.print(F("  You're lucky, I have a\n"));
      if(slipMode == false) {
        gb.display.setCursorX(5);
        gb.display.print(F("   thing for pancakes."));
      } else {
        gb.display.setCursorX(2);
        gb.display.print(F("   thing for underwear."));
      }
    }
    break;

// Judgement
    case 9:
    if(answered == 0) {
      gb.display.setCursorX(2);
      gb.display.print(F("  Hello trespasser. Make\n"));
      gb.display.setCursorX(2);
      gb.display.print(F(" yourself at home. You're\n"));
      gb.display.setCursorX(5);
      gb.display.print(F(" just in time to test my\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("  new suffering machine.\n\n"));
    } else {
      if(goodAnswer == true) {
        gb.display.setCursorX(5);
        gb.display.print(F(" Oh, you like it? Do you\n"));
        gb.display.setCursorX(5);
        gb.display.print(F("  want to help me build\n"));
        gb.display.setCursorX(2);
        gb.display.print(F("    more in my fablab?"));
      } else {
        gb.display.setCursorX(2);
        gb.display.print(F(" Are you kidding me? Only\n"));
        gb.display.setCursorX(2);
        gb.display.print(F("humans deserve to feel the\n"));
        gb.display.setCursorX(5);
        gb.display.print(F("    unrelenting pain!"));
      }
    }
    if(answered == 0) {
      gb.display.setColor(topAnswer?WHITE:GRAY);
      gb.display.setCursorX(5);
      gb.display.print(F("   Did you built it by\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("yourself? You're a maker?"));
      gb.display.setColor(topAnswer?GRAY:WHITE);
      gb.display.print(F("\n\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("    Did you test it on\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("     animals before?"));
    }
    goodAnswer = topAnswer?true:false;
    break;

// Beelzebub (human shape)
    case 10:
    if(answered == 0) {
      gb.display.setCursorX(2);
      gb.display.print(F("Are you going to follow me\n"));
      gb.display.setCursorX(2);
      gb.display.print(F(" to the farest? And leave\n"));
      gb.display.setCursorX(5);
      gb.display.print(F(" the other girls behind?"));
    } else {
      if(goodAnswer == true) {
        gb.display.setCursorX(5);
        gb.display.print(F("Great! I like people with\n"));
        gb.display.setCursorX(2);
        gb.display.print(F("    high expectations."));
      } else {
        gb.display.setCursorX(5);
        gb.display.print(F("Who will make us food and\n"));
        gb.display.setCursorX(5);
        gb.display.print(F("bring some champagne? I'm\n"));
        gb.display.setCursorX(5);
        gb.display.print(F(" expecting boring times."));
      }
    }
    if(answered == 0) {
      gb.display.setColor(topAnswer?WHITE:GRAY);
      gb.display.print(F("\n\n\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("     Only you and me."));
      gb.display.setColor(topAnswer?GRAY:WHITE);
      gb.display.print(F("\n\n\n"));
      gb.display.setCursorX(2);
      gb.display.print(F(" I stopped counting but I\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("  need a full set harem."));
    }
    goodAnswer = topAnswer?false:true;
    break;
  }

// draw SUCCESS (not for Lucifer)
  if((answered > 0) && (goodAnswer == true) && (levelNumber != 8) && (levelNumber != 0)) {
    gb.display.drawImage(47, 100, SUCCESS);
    if(clap == false) {
      //gb.lights.drawImage(0, 0, rainbow);
      if(startRainbow == true) {
// we update the game progress
        if(lastLevelWon < levelNumber) {
          lastLevelWon = levelNumber;
          gb.save.set(0, lastLevelWon);
        }
        gb.sound.playOK();
//        gb.sound.fx(rainbowSound);
        startRainbow = false;
      }
    }
    if((answered > 1) && (levelNumber != 8)) {
      clap = true;
    }
  }

// draw SUCCESS for Lucifer
  if(levelNumber == 8) {
    if((answered > 4) && (goodAnswer == true)) {
      gb.display.drawImage(47, 100, SUCCESS);
      if(clap == false) {
        //gb.lights.drawImage(0, 0, rainbow);
        if(startRainbow == true) {
// we update the game progress
        if(lastLevelWon < levelNumber) {
          lastLevelWon = levelNumber;
          gb.save.set(0, lastLevelWon);
        }
          gb.sound.playOK();
//        gb.sound.fx(rainbowSound);
          startRainbow = false;
        }
      }
    }
    if(answered > 5) {
      clap = true;
    }
  }
}


void docTeaches() {
  if(gb.buttons.repeat(BUTTON_A, 0)) {
    if(whatTheFoxSays == 0) {
      if(gb.buttons.pressed(BUTTON_UP)) {
        whatTheFoxSays = whatTheFoxSays + 1;
      } else if((gb.buttons.pressed(BUTTON_DOWN)) || (gb.buttons.pressed(BUTTON_LEFT)) || (gb.buttons.pressed(BUTTON_RIGHT))) {
        whatTheFoxSays = 0;
      }
    } else if(whatTheFoxSays == 1) {
      if(gb.buttons.pressed(BUTTON_DOWN)) {
        whatTheFoxSays = whatTheFoxSays + 1;
      } else if((gb.buttons.pressed(BUTTON_UP)) || (gb.buttons.pressed(BUTTON_LEFT)) || (gb.buttons.pressed(BUTTON_RIGHT))) {
        whatTheFoxSays = 0;
      }
    } else if(whatTheFoxSays == 2) {
      if(gb.buttons.pressed(BUTTON_LEFT)) {
        whatTheFoxSays = whatTheFoxSays + 1;
      } else if((gb.buttons.pressed(BUTTON_DOWN)) || (gb.buttons.pressed(BUTTON_UP)) || (gb.buttons.pressed(BUTTON_RIGHT))) {
        whatTheFoxSays = 0;
      }
    } else if(whatTheFoxSays == 3) {
      if(gb.buttons.pressed(BUTTON_RIGHT)) {
        whatTheFoxSays = whatTheFoxSays + 1;
      } else if((gb.buttons.pressed(BUTTON_DOWN)) || (gb.buttons.pressed(BUTTON_LEFT)) || (gb.buttons.pressed(BUTTON_UP))) {
        whatTheFoxSays = 0;
      }
    }
  }

  if(whatTheFoxSays == 4) {
//    levelFinished = true;

    gb.sound.fx(keySound);

    if(slipMode == false) {
      gb.lights.fill(BEIGE);
      slipMode = true;
    } else {
      gb.lights.fill(WHITE);
      slipMode = false;
    }
    whatTheFoxSays = 0;

    if(gamestate == 9) {
      buttonsMoveCloser = false;
      buttonsMove = true;
    }
  }
}


// There are three secret letters to find in the game
// Level 4: "B", level 5: "A" and level 6: "D"
void secretLetters() {
// The Sour Demon
  if((levelNumber == 4) && (hasSecretB == false)) {
    gb.display.drawImage(8*16 - 8, 6*16 - 16, secretB);
    if((columnPlayer == 8) && (rowPlayer == 6) && (clap == false)) {
      hasSecretB = true;
      gb.lights.fill(WHITE);
      gb.sound.fx(keySound);
    }
  }

// The Bitch Demon
  if((levelNumber == 5) && (hasSecretA == false)) {
    gb.display.drawImage(6*16 - 8, 3*16 - 16, secretA);
    if((columnPlayer == 6) && (rowPlayer == 3) && (clap == false)) {
      hasSecretA = true;
      gb.lights.fill(WHITE);
      gb.sound.fx(keySound);
    }
  }

// The Curious Angel
  if((levelNumber == 6) && (hasSecretD == false)) {
    gb.display.drawImage(7*16 - 8, 7*16 - 16, secretD);
    if((columnPlayer == 7) && (rowPlayer == 7) && (clap == false)) {
      hasSecretD = true;
      gb.lights.fill(WHITE);
      gb.sound.fx(keySound);
    }
  }

// if we have the three secret letters of Hell
  if((hasSecretB == true) && (hasSecretA == true) && (hasSecretD == true)) {
// go to Befriend all demons screen
    gamestate = 10;
  }

// PRIDE
  if((levelNumber == 11) && (hasYellowTriangle == false)) {
// we hide the way to the yellow triangle
    gb.display.drawImage(4*16 - 8, 16 -16, cloud_a);
    gb.display.drawImage(5*16 - 8, 16 -16, cloud_a);
    gb.display.drawImage(6*16 - 8, 16 -16, cloud_a);
    gb.display.drawImage(4*16 - 8, 2*16 -16, cloud_c);
    gb.display.drawImage(5*16 - 8, 2*16 -16, cloud_a);
    gb.display.drawImage(6*16 - 8, 2*16 -16, cloud_a);
// we draw the yellow triangle
    gb.display.drawImage(6*16 - 8, 2*16 - 16, yellowTriangle);
    if((columnPlayer == 6) && (rowPlayer == 2) && (clap == false)) {
      hasYellowTriangle = true;
      gb.lights.fill(YELLOW);
      gb.sound.fx(keySound);
    }
  }

// LUST
  if((levelNumber == 13) && (hasPinkCircle == false)) {
// we hide the way to the pink circle
    gb.display.drawImage(9*16 - 8, 5*16 -16, cloud_a);
    gb.display.drawImage(9*16 - 8, 6*16 -16, cloud_a);
    gb.display.drawImage(8*16 - 8, 7*16 -16, cloud_a);
    gb.display.drawImage(9*16 - 8, 7*16 -16, cloud_a);
    gb.display.drawImage(6*16 - 8, 8*16 -16, cloud_a);
    gb.display.drawImage(7*16 - 8, 8*16 -16, cloud_a);
    gb.display.drawImage(8*16 - 8, 8*16 -16, cloud_a);
    gb.display.drawImage(9*16 - 8, 8*16 -16, cloud_a);

// we draw the pink circle
    gb.display.drawImage(9*16 - 8, 6*16 - 16, pinkCircle);
    if((columnPlayer == 9) && (rowPlayer == 6) && (clap == false)) {
      hasPinkCircle = true;
      gb.lights.fill(PINK);
      gb.sound.fx(keySound);
    }
  }

// GLUTTONY
  if((levelNumber == 15) && (hasBlueSquare == false)) {
// we hide the way to the blue square
    gb.display.drawImage(7*16 - 8, 6*16 -16, cloud_a);
    gb.display.drawImage(8*16 - 8, 6*16 -16, cloud_a);
    gb.display.drawImage(7*16 - 8, 7*16 -16, cloud_a);
    gb.display.drawImage(8*16 - 8, 7*16 -16, cloud_a);

// we draw the yellow triangle
    gb.display.drawImage(8*16 - 8, 7*16 - 16, blueSquare);
    if((columnPlayer == 8) && (rowPlayer == 7) && (clap == false)) {
      hasBlueSquare = true;
      gb.lights.fill(BLUE);
      gb.sound.fx(keySound);
    }
  }

// if we have the three secret letters of Heaven
  if((hasYellowTriangle == true) && (hasPinkCircle == true) && (hasBlueSquare == true)) {
// go to Acrylique et pixels screen
    gamestate = 13;
// - - - WIP - - -
  }
}

void HellLevels() {
  drawGraphics();
  
// We fill the back lights in RED if teeth hurt.
  if(redFlash > 0) {
    redFlash = redFlash - 1;
  }

  if(death == true){
    drawDeath();
  }
  
  if(clap == true){
     drawClap();
  }

//  drawFreeRam();

  if((clap == false) && (death == false) && (levelFinished == false)) {
    inputs();
  }

  if(levelFinished == true) {
    goDialogues = goDialogues + 1;
  }

  if(goDialogues > 4) {
    gamestate = 2; // hell dialogues
    goDialogues = 0;
    levelFinished = false;
    topAnswer = true;
  }

  docTeaches();

  if((gb.buttons.pressed(BUTTON_MENU)) && (clap == false)) {
    gamestate = 5; // level selection screen
  }

}

void HellDialogues() {
// We draw the purple rectangle around the character.
  if(!((levelNumber == 0) && ((answered == 0) || (answered == 4)))) {
//    gb.display.setColor(PURPLE);
//    gb.display.fillRect(0, bigDemon, 160, 32 - bigDemon*2);
     purpleBanner();
  }

// The purple rectangle grows until the size of the character.
  if(bigDemon > 0) {
    bigDemon = bigDemon - 1;
  } else {
    bigDemon = 0;
    demonText();
  }

// We draw the character.
  drawBigDemon();

// sound of the big character coming
  if((bigDemon == 7) && !((answered == 0) && (levelNumber == 0))) {
    gb.sound.fx(slowMove);
  }

// We select the answer
  if(levelNumber != 0) {
    if(levelNumber != 8) {
      if(answered == 0) {
        if(gb.buttons.pressed(BUTTON_DOWN)) {
          topAnswer = false;
        }
        if(gb.buttons.pressed(BUTTON_UP)) {
          topAnswer = true;
        }
      } else {
        if((gb.buttons.pressed(BUTTON_A)) && (goodAnswer == false)) {
          gamestate = 3;
        }
      }
    } else {
      if((answered == 1) || (answered == 3)) {
        if(gb.buttons.pressed(BUTTON_DOWN)) {
          topAnswer = false;
        }
        if(gb.buttons.pressed(BUTTON_UP)) {
          topAnswer = true;
        }
      } else if((answered == 2) || (answered == 4)) {
        if((gb.buttons.pressed(BUTTON_A)) && (goodAnswer == false)) {
        gamestate = 3;
        }
      }
    }
  }

  if(gb.buttons.pressed(BUTTON_A)) {
    if((levelNumber == 0) && (answered == 7)) {
//      gb.sound.stop(track);
//      track = gb.sound.play("Vitality.wav", true);
    }
//    gb.sound.fx(littleTick);

// wrong answer sound
    if((goodAnswer == false) && (answered == 0) && (levelNumber != 8)) {
      gb.sound.playCancel();
    }
    
    answered = answered + 1;
    if((levelNumber == 0) && ((answered == 1) || (answered == 5))) {
      bigDemon = 8;
    }
  }
  
  if(clap == true){
    drawClap();
  }
}

void drawBadEnd() {
  gb.display.drawImage(17+(random(0,3)), 53+(random(0,3)), BAD_END, 124, 20);
    
  if(gb.buttons.pressed(BUTTON_A) && (clap == false)) {
    clap = true;
    resetLevel = true;
  }

  if(clap == true){
    drawClap();
  }
}

void intro() {
// We draw the badger logo shaking to the center
// and then going out.
  if(((anim == true) || (logoReduces == false)) && (logoTrouble < 101)) {
    gb.display.drawImage(56+xLogo, 44+yLogo, logoBadger, 48, 40);
  }

  if((frames%2 == 0) && (anim == true)) {
    if(logoSide == true) {
      logoSide = false;
    } else {
      logoSide = true;
    }

    xLogo = random(-logoTrouble, logoTrouble);
    yLogo = random(-logoTrouble, logoTrouble);

// intro sound
//    gb.sound.tone(logoTrouble*100, 80);
//    gb.sound.tone((random(logoTrouble/2, logoTrouble))*100, 80);
    gb.sound.tone(abs(xLogo*yLogo), 80);
  }

  if(anim == true) {
    if(logoReduces==true) {
      logoTrouble=logoTrouble-2;
    } else {
      logoTrouble=logoTrouble+2;
    }
  }

  frames = frames + 1;

  if(frames > 29) {
    frames = 0;
  }

  if(logoTrouble < 1) {
    logoReduces = false;
    anim = false;
    logoTrouble = 0;
    xLogo = 0;
    yLogo = 0;
  }

  if(logoTrouble > 120) {
//    logoReduces = true;
//    anim = false;
// we go to the Hell dialogues
    gamestate = 2;
    
// reset the intro values
    xLogo = 80;
    yLogo = 80;
    logoTrouble = 120;
    frames = 0;
    logoSide = true;
    logoReduces = true;
    anim = true;
    beforePress = 0;
  }

  if((gb.buttons.pressed(BUTTON_A)) && (logoTrouble == 0)) {
    anim = true;
    beforePress = 0;
//    gb.sound.playOK();
  }

  if(logoTrouble == 0) {
    beforePress = beforePress + 1;
    if(beforePress > 29) {
      beforePress = 0;
    }
    gb.display.setFont(font5x7);
    gb.display.setCursor(26, 103);
    gb.display.setColor(RED);
    if(beforePress > 14) {
      gb.display.print(F("PRESS [A] TO START"));
    }
  }
}

void drawEnd() {
  gb.display.setFont(font5x7);
  gb.display.setFontSize(1);
  gb.display.setColor(RED);
//  gb.display.print(F("\n\n"));
  gb.display.setCursorY(12);
  gb.display.setCursorX(2);
  gb.display.print(F("      Demon Girls by\n\n"));
  gb.display.setColor(WHITE);
  gb.display.setCursorX(2);
  gb.display.print(F("       Juice Lizard\n\n\n"));
  gb.display.setColor(RED);
  gb.display.setCursorX(2);
  gb.display.print(F("       Helltaker by\n\n"));
  gb.display.setColor(WHITE);
  gb.display.setCursorX(2);
  gb.display.print(F("      Lukasz Piskorz\n\n\n"));
  gb.display.setColor(RED);
  gb.display.setCursorX(2);
  gb.display.print(F("       Music Tracks\n\n"));
  gb.display.setColor(WHITE);
  gb.display.setCursorX(2);
  gb.display.print(F("         Mittsies"));
  
  if(clap == true){
     drawClap();
  }

  if((clap == false) && (gb.buttons.pressed(BUTTON_A))) {
    gamestate = 6;
  }

}

void changeMusic() {
  switch (MittsiesTrack) {
    case 0:
      gb.sound.stop(track);
      break;
    case 1:
      gb.sound.stop(track);
      track = gb.sound.play("01 Vitality.wav");
      break;
    case 2:
      gb.sound.stop(track);
      track = gb.sound.play("02 Apropos.wav");
      break;
    case 3:
      gb.sound.stop(track);
      track = gb.sound.play("03 Epitomize.wav");
      break;
    case 4:
      gb.sound.stop(track);
      track = gb.sound.play("04 Luminescent.wav");
      break;
    case 5:
      gb.sound.stop(track);
      track = gb.sound.play("05 Alchemy.wav");
      break;
    case 6:
      gb.sound.stop(track);
      track = gb.sound.play("06 Titanium.wav");
      break;
    case 7:
      gb.sound.stop(track);
      track = gb.sound.play("07 Epitomize (VIP Edit).wav");
      break;
    case 8:
      gb.sound.stop(track);
      track = gb.sound.play("08 Vitality (VIP Edit).wav");
      break;
    case 9:
      gb.sound.stop(track);
      track = gb.sound.play("09 Epitomize (Sinner's VIP).wav");
      break;
    case 10:
      gb.sound.stop(track);
      track = gb.sound.play("10 Brimstone.wav");
      break;
  }
}

void chapterSelect() {
// We draw the level number in a nice rectangle.
  gb.display.setColor(WHITE);
  gb.display.drawRect(50, 44, 60, 40);
  gb.display.drawRect(54, 48, 52, 32);
  gb.display.drawRect(53, 47, 54, 34);
  
  gb.display.setColor(DARKGRAY);
  gb.display.fillRect(57, 51, 46, 26);
  
  Image level(LEVEL_NB_DATA);
  level.setFrame(levelNumber - 1);
  if((levelNumber == 2) || (levelNumber == 7)) {
    gb.display.drawImage(66, 54, level, 32, 20);
  } else {
    gb.display.drawImage(65, 54, level, 32, 20);
  }

// We print the name of the level.
  gb.display.setCursorY(102);
  gb.display.setColor(WHITE);
  gb.display.setFont(font5x7);
  gb.display.setFontSize(1);

  switch (levelNumber) {
    case 1:
      gb.display.setCursorX(5);
      gb.display.print(F("     The Tired Demon"));
      break;
    case 2:
      gb.display.setCursorX(5);
      gb.display.print(F("    The Lustful Demon"));
      break;
    case 3:
      gb.display.setCursorX(2);
      gb.display.print(F("     The Triple Demon"));
      break;
    case 4:
      gb.display.setCursorX(2);
      gb.display.print(F("      The Sour Demon"));
      break;
    case 5:
      gb.display.setCursorX(5);
      gb.display.print(F("     The Bitch Demon"));
      break;
    case 6:
      gb.display.setCursorX(5);
      gb.display.print(F("    The Curious Angel"));
      break;
    case 7:
      gb.display.setCursorX(5);
      gb.display.print(F("    The Awesome Demon"));
      break;
    case 8:
      gb.display.setCursorX(5);
      gb.display.print(F("     The CEO of Hell"));
      break;
    case 9:
      gb.display.setCursorX(5);
      gb.display.print(F("   The High Prosecutor"));
      break;
    case 10:
      gb.display.setCursorX(5);
      gb.display.print(F("      The Great Fly"));
      break;
  }

// Inputs to select the level.
  if(gb.buttons.pressed(BUTTON_RIGHT)) {
    if(levelNumber < 10) {
      if(levelNumber <= lastLevelWon) {
        levelNumber = levelNumber + 1;
        gb.sound.playTick();
      } else {
        gb.sound.fx(kickOnly);
      }
    } else if(levelNumber == 10) {
      levelNumber = levelNumber + 1;
      WYFLevelNumber = levelNumber - 10;
      gamestate = 12;
      gb.sound.playTick();
    }
  } else if((gb.buttons.pressed(BUTTON_LEFT)) && (levelNumber > 1)) {
    levelNumber = levelNumber - 1;
    gb.sound.playTick();
  }

// Input to valid the selected level.
  if(gb.buttons.pressed(BUTTON_A)) {
    gb.sound.stop(track);
    MittsiesTrack = 0;
    resetLevel = true;
    clap = true;
    WYFLevelNumber = levelNumber - 10;
  }

// Input to select the Mittsies track
  if((gb.buttons.pressed(BUTTON_DOWN)) && (MittsiesTrack < 10)) {
    MittsiesTrack = MittsiesTrack + 1;
    changeMusic();
  }
  if((gb.buttons.pressed(BUTTON_UP)) && (MittsiesTrack > 0)) {
    MittsiesTrack = MittsiesTrack - 1;
    changeMusic();
  }

// We print the title of the track
  gb.display.setCursorY(17);

// We color the title of the track in pink, red and brown
  if(trackColorCounter < 6) {
    gb.display.setColor(PINK);
  }
  if(((trackColorCounter > 5) && (trackColorCounter < 12)) || (trackColorCounter > 17)) {
    gb.display.setColor(RED);
  }
  if((trackColorCounter > 11) && (trackColorCounter < 18)) {
    gb.display.setColor(BROWN);
  }

  trackColorCounter = trackColorCounter + 1;

  if(trackColorCounter > 23) {
    trackColorCounter = 0;
  }
  
  gb.display.setFont(font5x7);
  gb.display.setFontSize(1);

  switch (MittsiesTrack) {
    case 1:
      gb.display.setCursorX(2);
      gb.display.print(F("         Vitality"));
      break;
    case 2:
      gb.display.setCursorX(5);
      gb.display.print(F("         Apropos"));
      break;
    case 3:
      gb.display.setCursorX(5);
      gb.display.print(F("        Epitomize"));
      break;
    case 4:
      gb.display.setCursorX(5);
      gb.display.print(F("       Luminescent"));
      break;
    case 5:
      gb.display.setCursorX(5);
      gb.display.print(F("         Alchemy"));
      break;
    case 6:
      gb.display.setCursorX(2);
      gb.display.print(F("         Titanium"));
      break;
    case 7:
      gb.display.setCursorX(2);
      gb.display.print(F("   Epitomize (VIP Edit)"));
      break;
    case 8:
      gb.display.setCursorX(5);
      gb.display.print(F("   Vitality (VIP Edit)"));
      break;
    case 9:
      gb.display.setCursorX(2);
      gb.display.print(F(" Epitomize (Sinner's VIP)"));
      break;
    case 10:
      gb.display.setCursorX(5);
      gb.display.print(F("        Brimstone"));
      break;
    default:
      break;
  }


// We draw the clap and go to a level.
  if(clap == true){
     drawClap();
  }
}

void purpleBanner() {
  gb.display.drawImage(0, bigDemon, purple80x16);
  gb.display.drawImage(80, bigDemon, purple80x16);
  gb.display.drawImage(0, 16 - bigDemon, purple80x16);
  gb.display.drawImage(80, 16 - bigDemon, purple80x16);
}

void lightBlueBanner() {
  gb.display.drawImage(0, bigDemon, lightBlue80x16);
  gb.display.drawImage(80, bigDemon, lightBlue80x16);
  gb.display.drawImage(0, 16 - bigDemon, lightBlue80x16);
  gb.display.drawImage(80, 16 - bigDemon, lightBlue80x16);
}

void setText() {
  gb.display.setCursor(0, 40);
  gb.display.setFont(font5x7);
  gb.display.setFontSize(1);
}

void ItWasAnAccident() {
// The background is purple if we see rats or ambulance.
// The background is black is a demon girl speaks.
  if((accidentStep % 2 == 0) && (clap == false)) {
    gb.display.clear();
  } else {
    gb.display.clear(PURPLE);
  }

  switch (accidentStep) {
// Lucifer and Judgement speak
    case 0:
      purpleBanner();
      if(answered == 0) {
        gb.display.drawImage(bigDemon*4 + 64, 0, Lucifer, 32, 32);
      }
      if(answered == 1) {
        gb.display.drawImage(bigDemon*4 + 64, 0, Judgement, 32, 32);
      }
      if(bigDemon > 0) {
        bigDemon = bigDemon - 1;
        if(bigDemon == 7){
          gb.sound.fx(slowMove);
        }
      } else {
        bigDemon = 0;
        gb.display.setColor(RED);
        setText();
        
        if(answered == 0) {
          gb.display.setCursorX(5);
          gb.display.print(F("Where is he again? I hope\n"));
          gb.display.setCursorX(2);
          gb.display.print(F("  he likes the delicious\n"));
          gb.display.setCursorX(2);
          gb.display.print(F(" pancakes I made for him."));
        } else {
          gb.display.setCursorX(2);
          gb.display.print(F(" You spoil that dude! You\n"));
          gb.display.setCursorX(2);
          gb.display.print(F(" were not that sweet when\n"));
          gb.display.setCursorX(5);
          gb.display.print(F("      we first met."));
        }
      }
      break;

// first rat (Square Nose)
    case 1:
      accidentCounterMax = 66;
      gb.display.drawImage(xSquareNose + 4*accidentCounter, 7, SquareNose, 20, 24);
      if(random(24)== 1) {
        gb.sound.fx(squirrel);
      }
      break;

// Malina and Lucifer speak
    case 2:
      purpleBanner();
      if(answered == 0) {
        gb.display.drawImage(bigDemon*4 + 64, 0, Malina, 32, 32);
      }
      if(answered == 1) {
        gb.display.drawImage(bigDemon*4 + 64, 0, Lucifer, 32, 32);
      }
      if(bigDemon > 0) {
        bigDemon = bigDemon - 1;
        if(bigDemon == 7){
          gb.sound.fx(slowMove);
        }
      } else {
        bigDemon = 0;
        gb.display.setColor(RED);
        setText();
        if(answered == 0) {
          gb.display.setCursorX(2);          
          gb.display.print(F("This place is a true mess!\n"));
          gb.display.setCursorX(2);
          gb.display.print(F("   I just saw a big rat\n"));
          gb.display.setCursorX(5);
          gb.display.print(F("running near the kitchen."));
        } else {
          gb.display.setCursorX(2);
          gb.display.print(F("Don't fret my dear. I used\n"));
          gb.display.setCursorX(2);
          gb.display.print(F("  a chemical to fix this\n"));
          gb.display.setCursorX(2);
          gb.display.print(F(" problem two minutes ago."));
        }
      }
      break;

// two rats
    case 3:
      accidentCounterMax = 74;
      gb.display.drawImage(xSquareNose + 180 - 4*accidentCounter, 37, SquareNose, -20, 24);
      gb.display.drawImage(xSquareNose + 212 - 4*accidentCounter, 37, SquareNose, -20, 24);
      if(random(12)== 1) {
        gb.sound.fx(squirrel);
      }
      break;

// Judgement and Modeus speak
    case 4:
      purpleBanner();
      if(answered == 0) {
        gb.display.drawImage(bigDemon*4 + 64, 0, Judgement, 32, 32);
      }
      if(answered == 1) {
        gb.display.drawImage(bigDemon*4 + 64, 0, Modeus, 32, 32);
      }
      if(bigDemon > 0) {
        bigDemon = bigDemon - 1;
        if(bigDemon == 7){
          gb.sound.fx(slowMove);
        }
      } else {
        bigDemon = 0;
        gb.display.setColor(RED);
        setText();
        if(answered == 0) {
          gb.display.setCursorX(2);
          gb.display.print(F("Rats seem to be growing in\n"));
          gb.display.setCursorX(2);
          gb.display.print(F("number! Luci, did you feed\n"));
          gb.display.setCursorX(5);
          gb.display.print(F("          them?"));
        } else {
          gb.display.setCursorX(2);
          gb.display.print(F("Somebody! Help! He's lying\n"));
          gb.display.setCursorX(2);
          gb.display.print(F("on the ground and his face\n"));
          gb.display.setCursorX(5);
          gb.display.print(F("      turned green!"));
        }
      }
      break;

// three rats
    case 5:
      accidentCounterMax = 82;
      gb.display.drawImage(xSquareNose + 4*accidentCounter, 67, SquareNose, 20, 24);
      gb.display.drawImage(xSquareNose - 32 + 4*accidentCounter, 67, SquareNose, 20, 24);
      gb.display.drawImage(xSquareNose - 64+ 4*accidentCounter, 67, SquareNose, 20, 24);
      if(random(8)== 1) {
        gb.sound.fx(squirrel);
      }
      break;

// Judgement and Lucifer speak
    case 6:
      purpleBanner();
      if(answered == 0) {
        gb.display.drawImage(bigDemon*4 + 64, 0, Judgement, 32, 32);
      }
      if(answered == 1) {
        gb.display.drawImage(bigDemon*4 + 64, 0, Lucifer, 32, 32);
      }
      if(bigDemon > 0) {
        bigDemon = bigDemon - 1;
        if(bigDemon == 7){
          gb.sound.fx(slowMove);
        }
      } else {
        bigDemon = 0;
        gb.display.setColor(RED);
        setText();
        if(answered == 0) {
          gb.display.setCursorX(2);
          gb.display.print(F(" What an idiot! How could\n"));
          gb.display.setCursorX(2);
          gb.display.print(F(" you mistake Nuthella for\n"));
          gb.display.setCursorX(5);
          gb.display.print(F("     the rat poison?"));
        } else {
          gb.display.setCursorX(5);
          gb.display.print(F(" It was an accident! How\n"));
          gb.display.setCursorX(5);
          gb.display.print(F(" can I see sharp through\n"));
          gb.display.setCursorX(5);
          gb.display.print(F("those fat pixels and this\n"));
          gb.display.setCursorX(2);
          gb.display.print(F("       tiny screen?"));
        }
      }
      break;

// four rats
    case 7:
      accidentCounterMax = 90;
      gb.display.drawImage(xSquareNose + 180 - 4*accidentCounter, 97, SquareNose, -20, 24);
      gb.display.drawImage(xSquareNose + 212 - 4*accidentCounter, 97, SquareNose, -20, 24);
      gb.display.drawImage(xSquareNose + 244 - 4*accidentCounter, 97, SquareNose, -20, 24);
      gb.display.drawImage(xSquareNose + 276 - 4*accidentCounter, 97, SquareNose, -20, 24);
      if(random(6) == 1) {
        gb.sound.fx(squirrel);
      }
      break;

// Lucifer and Pandemonica speak
    case 8:
      purpleBanner();
      if(answered == 0) {
        gb.display.drawImage(bigDemon*4 + 64, 0, Lucifer, 32, 32);
      }
      if(answered == 1) {
        gb.display.drawImage(bigDemon*4 + 64, 0, Pandemonica, 32, 32);
      }
      if(bigDemon > 0) {
        bigDemon = bigDemon - 1;
        if(bigDemon == 7){
          gb.sound.fx(slowMove);
        }
      } else {
        bigDemon = 0;
        gb.display.setColor(RED);
        setText();
        if(answered == 0) {
          gb.display.setCursorX(2);
          gb.display.print(F(" Oh no! What have I done?\n"));
        } else {
          gb.display.setCursorX(2);
          gb.display.print(F(" I called 999. They're on\n"));
          gb.display.setCursorX(2);
          gb.display.print(F("         the way.\n"));
        }
      }
      break;
// an ambulance comes (from my previous game "Dumbulance")
    case 9:
      accidentCounterMax = 99;
// We draw the ambulance
      gb.display.drawImage(xDumbulance + 4*accidentCounter, 38, Dumbulance, 72, 52);
      gb.display.drawImage(xDumbulance + 4*accidentCounter + 48, 42, flashingLight, 4, 4);
      gb.display.drawImage(xDumbulance + 4*accidentCounter + 12, 74, leftWheel, 12, 12);
      gb.display.drawImage(xDumbulance + 4*accidentCounter + 52, 74, rightWheel, 12, 12);
// We hear the siren sound
    if(startSiren == true) {
      gb.sound.fx(siren);
      startSiren = false;
    }
      break;
  }

  if((gb.buttons.pressed(BUTTON_A)) && (bigDemon == 0) && (accidentStep % 2 == 0) && (clap == false)) {
    if(answered > 0) {
      accidentStep = accidentStep + 1;
      answered = 0;
    } else {
      answered = answered + 1;
    }
    bigDemon = 8;
  }

  if((clap == false) && ((accidentStep % 2) == 1)) {
    accidentCounter = accidentCounter + 1;
  }

  if(accidentCounter > accidentCounterMax) {
    accidentCounter = 0;
    accidentStep = accidentStep + 1;
    bigDemon = 8;
    
    if(accidentStep > 9) {
//      accidentStep = 0;
//      gamestate = 7;
      clap = true;
      startSiren = true;
    }
  }

  if(clap == true){
    drawHeavenClap();
    WYFLevelNumber = 0;
  }
}

// dialogues between the hero and Lucifer
// when he comes back to Hell
void darlingImHome() {
  purpleBanner();
  
  if((answered == 0) || (answered == 2)) {
    if(slipMode == false) {
      gb.display.drawImage(bigDemon*4 + 64, 0, heroRight, 32, 32);
    } else {
      gb.display.drawImage(bigDemon*4 + 64, 0, heroNippleRight, 32, 32);
    }
  }
  if((answered == 1) || (answered == 3)) {
    gb.display.drawImage(bigDemon*4 + 64, 0, Lucifer, 32, 32);
  }
  
  if(bigDemon > 0) {
    bigDemon = bigDemon - 1;
    if(bigDemon == 7){
      gb.sound.fx(slowMove);
    }
  } else {
    bigDemon = 0;
    if((answered == 0) || (answered == 2)) {
      gb.display.setColor(WHITE);
    } else {
      gb.display.setColor(RED);
    }
    setText();
        
    if(answered == 0) {
      gb.display.setCursorX(2);
      gb.display.print(F("    Darling! I'm home!"));
    }
    if (answered == 1) {
      gb.display.setCursorX(2);
      gb.display.print(F("Damn! You're already here!"));
// we hear a squirrel
      if(random(32)== 1) {
        gb.sound.fx(squirrel);
      }
    }
    if (answered == 2) {
      gb.display.setCursorX(5);
      gb.display.print(F(" What means this worried\n"));
      gb.display.setCursorX(2);
      gb.display.print(F(" face? Is there something\n"));
      gb.display.setCursorX(5);
      gb.display.print(F(" you want to talk about?"));
    }
    if (answered == 3) {
      gb.display.setCursorX(5);
      gb.display.print(F("Are you suggesting that I\n"));
      gb.display.setCursorX(2);
      gb.display.print(F(" don't handle this place?\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("No, really... It's fine."));
// we hear more squirrels
      if(random(24)== 1) {
        gb.sound.fx(squirrel);
      }
    }
  }

  if((gb.buttons.pressed(BUTTON_A)) && (bigDemon == 0) && (clap == false)) {
    answered = answered + 1;
    bigDemon = 8;
    if(answered > 3) {
      backToHellStep = 3;
      answered = 0;
    }
  }
}

void GoddessText() {
  gb.display.setColor(BLUE);
  gb.display.setCursor(0, 40);
  gb.display.setFont(font5x7);
  gb.display.setFontSize(1);

  switch (WYFLevelNumber) {

// Goddess
    case 0:
      switch (answered) {
        case 0:
          gb.display.setCursorX(5);
          gb.display.print(F("    You find yourself\n"));
          gb.display.setCursorX(5);
          gb.display.print(F("surrounded by the clouds."));
          break;
        case 1:
          gb.display.setCursorX(2);
          gb.display.print(F("Welcome gentleman. You are\n"));
          gb.display.setCursorX(5);
          gb.display.print(F(" pleased to meet me, the\n"));
          gb.display.setCursorX(2);
          gb.display.print(F(" young and mighty Captain\n"));
          gb.display.setCursorX(2);
          gb.display.print(F("        of Heaven."));
          break;
        case 2:
          gb.display.setCursorX(2);
          gb.display.print(F("I won't hide the fact that\n"));
          gb.display.setCursorX(2);
          gb.display.print(F("  you are a little dead.\n"));
          gb.display.setCursorX(5);
          gb.display.print(F("      But anyway..."));
          break;
        case 3:
          gb.display.setCursorX(5);
          gb.display.print(F(" Let my introduce you my\n"));
          gb.display.setCursorX(2);
          gb.display.print(F("          W.Y.F.\n"));
          break;
        case 4:
          gb.display.setCursorX(5);
          gb.display.print(F("The White Yogurt Factory."));
          break;
        case 5:
          gb.display.setCursorX(2);
          gb.display.print(F(" I woke up one day with a\n"));
          gb.display.setCursorX(2);
          gb.display.print(F(" dream. A world empty of\n"));
          gb.display.setCursorX(2);
          gb.display.print(F("       filthiness."));
          break;
        case 6:
          gb.display.setCursorX(5);
          gb.display.print(F(" It was, however, not an\n"));
          gb.display.setCursorX(5);
          gb.display.print(F("easy dream to achieve. It\n"));
          gb.display.setCursorX(5);
          gb.display.print(F(" requires a lot of work."));
          break;
      }
      if(answered > 6) {
        gb.display.setColor(BLACK);
        gb.display.setCursorX(2);
        gb.display.print(F("     \"When angels are\n"));
        gb.display.setCursorX(5);
        gb.display.print(F("involved, no work is hard\n"));
        gb.display.setCursorX(2);
        gb.display.print(F("         enough.\"\n\n"));
        gb.display.setColor(BLUE);
        gb.display.setCursorX(2);
        gb.display.print(F(" You said, as you entered\n"));
        gb.display.setCursorX(2);
        gb.display.print(F("      the warehouse."));
        if(gb.buttons.pressed(BUTTON_A)) {
          clap = true;
        }
      }
      break;

// Pride
    case 1:
    if(answered == 0) {
      gb.display.setColor(BLACK);
      gb.display.setCursorX(2);
      gb.display.print(F("I did it! You can clap. It\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("  was not an easy task."));
    } else {
      gb.display.setColor(BLUE);
      gb.display.setCursorX(5);
      gb.display.print(F("It was only the begining,\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("  worker. The next rooms\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("    are the real deal."));
    }
    break;

// Greed
    case 2:
    if(answered == 0) {
      gb.display.setColor(BLACK);
      gb.display.setCursorX(5);
      gb.display.print(F("This holy salary won't be\n"));
      gb.display.setCursorX(5);
      gb.display.print(F(" spent foulishly. I must\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("think about my retirement."));
    } else {
      gb.display.setColor(BLUE);
      gb.display.setCursorX(5);
      gb.display.print(F(" What retirement? You're\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("  dead! Give your coins\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("     to poor people."));
    }
    break;

// Lust
    case 3:
    if(answered == 0) {
      gb.display.setColor(BLACK);
      gb.display.setCursorX(2);
      gb.display.print(F(" All this work deserves a\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("  little kiss! Don't you\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("          think?"));
    } else {
      gb.display.setColor(BLUE);
      gb.display.setCursorX(2);
      gb.display.print(F("Carnal desires do not suit\n"));
      gb.display.setCursorX(2);
      gb.display.print(F(" a pure angel like me. Go\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("  back to your yogurts,\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("         worker!"));
    }
    break;

// Anger
    case 4:
    if(answered == 0) {
      gb.display.setColor(BLACK);
      gb.display.setCursorX(2);
      gb.display.print(F(" Enough is enough! I hate\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("to work in this boring and\n"));
      gb.display.setCursorX(2);
      gb.display.print(F(" empty place! I demand to\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("     go back to Hell!"));
    } else {
      gb.display.setColor(BLUE);
      gb.display.setCursorX(5);
      gb.display.print(F(" What a lack of respect!\n"));
      gb.display.setCursorX(2);
      gb.display.print(F(" You just don't know your\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("     luck to be here."));
    }
    break;

// Gluttony
    case 5:
    if(answered == 0) {
      gb.display.setColor(BLACK);
      gb.display.setCursorX(5);
      gb.display.print(F("    All this work has\n"));
      gb.display.setCursorX(2);
      gb.display.print(F(" increased my appetite. I\n"));
      gb.display.setCursorX(5);
      gb.display.print(F(" could eat seven burgers\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("        in a row!"));
    } else {
      gb.display.setColor(BLUE);
      gb.display.setCursorX(5);
      gb.display.print(F("It seems way too much for\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("your health! Take time to\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("feed your spirit instead."));
    }
    break;

// Envy
    case 6:
    if(answered == 0) {
      gb.display.setColor(BLACK);
      gb.display.setCursorX(2);
      gb.display.print(F(" I am still stuck here...\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("  Even the tiny rocks in\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("Hell must be happier than\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("  me, surrounded by the\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("      lovely demons."));
    } else {
      gb.display.setColor(BLUE);
      gb.display.setCursorX(2);
      gb.display.print(F(" Don't be a foul! You are\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("with me. It is infinitely\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("    more delightfull!"));
    }
    break;

// Sloth
    case 7:
    if(answered == 0) {
      gb.display.setColor(BLACK);
      gb.display.setCursorX(5);
      gb.display.print(F(" Pushing yogurts all day\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("long makes me so tired! I\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("   deserve a great nap."));
    } else {
      gb.display.setColor(BLUE);
      gb.display.setCursorX(2);
      gb.display.print(F(" It's no time to sleep! A\n"));
      gb.display.setCursorX(2);
      gb.display.print(F(" lot of work are still to\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("         be done."));
    }
    break; 
  }
}

void HeavenDialogues() {
  gb.display.clear(WHITE);
// We draw the light blue rectangle around the character.
  if(!((WYFLevelNumber == 0) && ((answered == 0) || (answered == 4)))) {
    lightBlueBanner();
  }

// The light blue rectangle grows until the size of the character.
  if(bigDemon > 0) {
    if(!((WYFLevelNumber == 0) && (answered == 0))) {
      bigDemon = bigDemon - 1;
    } else {
      if(clap == false) { 
        GoddessText();
      }
    }
  } else {
    bigDemon = 0;
    GoddessText();
  }

// We draw the character or the yogurt
  if(WYFLevelNumber == 0) {
    if((answered > 0) && (answered < 4)) {
      gb.display.drawImage(bigDemon*4 + 64, 0, Goddess, 32, 32);
    }
    if((answered > 4) && (answered < 7)) {
      gb.display.drawImage(bigDemon*4 + 64, 0, yogurt, 32, 32);
    }
    if(answered > 6) {
      if(slipMode == false) {
        gb.display.drawImage(bigDemon*4 + 64, 0, heroRight, 32, 32);
      } else {
        gb.display.drawImage(bigDemon*4 + 64, 0, heroNippleRight, 32, 32);
      }
    }
  } else {
    if(answered == 0) {
      if(slipMode == false) {
        gb.display.drawImage(bigDemon*4 + 64, 0, heroRight, 32, 32);
      } else {
        gb.display.drawImage(bigDemon*4 + 64, 0, heroNippleRight, 32, 32);
      }
    } else {
      gb.display.drawImage(bigDemon*4 + 64, 0, Goddess, 32, 32);
    }
  }

// sound of the big character coming
  if(bigDemon == 7) {
    gb.sound.fx(slowMove);
  }

  if((gb.buttons.pressed(BUTTON_A)) && ((bigDemon == 0) || (clap == false))) {
    answered = answered + 1;

    if(((answered == 5) || (answered == 7)) && (WYFLevelNumber == 0)) {
      bigDemon = 8;
    }

    if((WYFLevelNumber > 0) && (answered < 2)) {
      bigDemon = 8;
    }

    if((answered > 1) && (WYFLevelNumber != 0)) {
      clap = true;
    }
  }
  
  if(clap == true){
    drawHeavenClap();
  }
}

void dismissal() {
  gb.display.clear(WHITE);
  
  gb.display.setColor(BLUE);
  gb.display.setFont(font5x7);
  gb.display.setFontSize(1);

  gb.display.setCursor(2, 4);
  gb.display.print(F("Dear worker,\n\n"));
  gb.display.setCursorX(2);
  gb.display.print(F("In spite of the undeniable\n"));
  gb.display.setCursorX(2);
  gb.display.print(F("habilities you may surely\n"));
  gb.display.setCursorX(2);
  gb.display.print(F("possess, it is clear that\n"));
  gb.display.setCursorX(2);
  gb.display.print(F("your state of mind is very\n"));
  gb.display.setCursorX(2);
  gb.display.print(F("far from the standards of\n"));
  gb.display.setCursorX(2);
  gb.display.print(F("purity of our Enterpraise.\n\n"));
  gb.display.setCursorX(2);
  gb.display.print(F("With the seven-level trial\n"));
  gb.display.setCursorX(2);
  gb.display.print(F("period over, please, clear\n"));
  gb.display.setCursorX(2);
  gb.display.print(F("out of Heaven and go roast\n"));
  gb.display.setCursorX(2);
  gb.display.print(F("miserably in Hell!\n\n"));
  gb.display.setCursorX(2);
  gb.display.print(F("Yours sins early."));

  gb.display.drawImage(144, 112, sheetCorner);

  if((gb.buttons.pressed(BUTTON_A)) && (clap == false)) {
    backToHellStep = 2;
  }

  if(clap == true) {
    drawHeavenClap();
  }
}

void ratsEverywhere() {
  gb.display.clear(PURPLE);
  accidentCounterMax = 7;

//  if(THE_ENDCounter == 0) {
    
    if((random(10)) == 0) {
      gb.sound.fx(squirrel);
    }
    
    for(int i = 0; i < 6; i++) {
      gb.display.drawImage(xSquareNose + 148 - (i*32) + 4*accidentCounter, 7, SquareNose, 20, 24);
      gb.display.drawImage(xSquareNose + 148 - (i*32) + 4*accidentCounter, 67, SquareNose, 20, 24);
    } 

    for(int i = 0; i < 6; i++) {
      gb.display.drawImage(xSquareNose + 180 - (i*32) - 4*accidentCounter, 37, SquareNose, -20, 24);
      gb.display.drawImage(xSquareNose + 180 - (i*32) - 4*accidentCounter, 97, SquareNose, -20, 24);
    }
//  }
  
  accidentCounter = accidentCounter + 1;

  if(accidentCounter > accidentCounterMax) {
    accidentCounter = 0;
  }

//  bool waitOneFrame = false;

//  waitOneFrame = true;

  if(gb.buttons.pressed(BUTTON_A)) {
    backToHellStep = 4;
  }
}

void teachTheCode() {
  docTeaches();

  if(buttonsMove == true) {
    gb.display.drawImage(112 + xButtons, 86, grayButtons);
    gb.display.drawImage(12 - xButtons, 80, grayCross);

    if(buttonsMoveCloser == true) {
      if(xButtons == 50) {
        gb.sound.fx(slowMove);
      }
      xButtons = xButtons - 6;
      if(xButtons < 1) {
        buttonsMove = false;
      }
    } else {
      xButtons = xButtons + 6;
      if(xButtons > 48) {
        codeLearned = true;
      }
    }
    
  } else {
    gb.display.drawImage(112, 86, grayButtons);
    gb.display.drawImage(114, 96, whiteBlinkCircle);

    gb.display.drawImage(12, 80, grayCross);
    
    if(gb.buttons.repeat(BUTTON_A, 0)) {
      if(whatTheFoxSays == 0) {
        gb.display.drawImage(26, 82, whiteBlinkSquare);        
      }
      if(whatTheFoxSays == 1) {
        gb.display.drawImage(26, 108, whiteBlinkSquare);
      }
      if(whatTheFoxSays == 2) {
        gb.display.drawImage(14, 94, whiteBlinkSquare);
      }
      if(whatTheFoxSays == 3) {
        gb.display.drawImage(38, 94, whiteBlinkSquare);
      }
    }
  }
}

void harem() {
  gb.display.clear(PURPLE);

  switch (haremCounter) {
    case 0:
      if(xHarem == -64) {
        gb.sound.fx(WeddingMarch);
      }
      gb.display.drawImage(128 + xHarem, 48, Pandemonica, 32, 32);
      gb.display.drawImage(192 + xHarem, 48, Modeus, 32, 32);
    break;
    case 1:
      gb.display.drawImage(128 + xHarem, 48, Modeus, 32, 32);
      gb.display.drawImage(192 + xHarem, 48, Cerberus, 32, 32);
    break;
    case 2:
      gb.display.drawImage(128 + xHarem, 48, Cerberus, 32, 32);
      gb.display.drawImage(192 + xHarem, 48, Cerberus, 32, 32);
    break;
    case 3:
      gb.display.drawImage(128 + xHarem, 48, Cerberus, 32, 32);
      gb.display.drawImage(192 + xHarem, 48, Cerberus, 32, 32);
    break;
    case 4:
      gb.display.drawImage(128 + xHarem, 48, Cerberus, 32, 32);
      gb.display.drawImage(192 + xHarem, 48, Malina, 32, 32);
    break;
    case 5:
/*
      if(xHarem == -64) {
        gb.sound.fx(WeddingMarch);
      }
*/
      gb.display.drawImage(128 + xHarem, 48, Malina, 32, 32);
      gb.display.drawImage(192 + xHarem, 48, Zdrada, 32, 32);
    break;
    case 6:
      gb.display.drawImage(128 + xHarem, 48, Zdrada, 32, 32);
      gb.display.drawImage(192 + xHarem, 48, Azazel, 32, 32);
    break;
    case 7:
      gb.display.drawImage(128 + xHarem, 48, Azazel, 32, 32);
      gb.display.drawImage(192 + xHarem, 48, Justice, 32, 32);
    break;
    case 8:
      gb.display.drawImage(128 + xHarem, 48, Justice, 32, 32);
      gb.display.drawImage(192 + xHarem, 48, Lucifer, 32, 32);
    break;
    case 9:
      gb.display.drawImage(128 + xHarem, 48, Lucifer, 32, 32);
      gb.display.drawImage(192 + xHarem, 48, Judgement, 32, 32);
    break;
    case 10:
      gb.display.drawImage(128 + xHarem, 48, Judgement, 32, 32);
      gb.display.drawImage(192 + xHarem, 48, Beelzebub, 32, 32);
    break;
    case 11:
      gb.display.drawImage(128 + xHarem, 48, Beelzebub, 32, 32);
      if(slipMode == false) {
        gb.display.drawImage(192 + xHarem, 48, heroRight, 32, 32);
      } else {
        gb.display.drawImage(192 + xHarem, 48, heroNippleRight, 32, 32);
      }
    break;
    case 12:
      if(slipMode == false) {
        gb.display.drawImage(128 + xHarem, 48, heroRight, 32, 32);
      } else {
        gb.display.drawImage(128 + xHarem, 48, heroNippleRight, 32, 32);
      }
//      gb.display.drawImage(192 + xHarem, 48, Modeus, 32, 32);
    break;
  }

// move the demons to the left
  if(!((haremCounter == 12) && (xHarem < -63))){
    xHarem = xHarem - 1;
  }

  if(xHarem < -128) {
    xHarem = -64;
    haremCounter = haremCounter + 1;
  }

//  if((haremCounter > 12) || (gb.buttons.pressed(BUTTON_B))) {
  if((codeLearned == true) && (gb.buttons.pressed(BUTTON_A))) { 
// go back to the game intro
    gamestate = 0;
// reset some values
    levelNumber = 0;
    answered = 0;
    bigDemon = 8;
    WYFLevelNumber = 0;
    resetLevel = false;
    xHarem = 0;
    haremCounter = 0;
    backToHellStep = 1;
    codeLearned = false;
    xButtons = 50;
    buttonsMove = true;
    buttonsMoveCloser = true;
  }

  gb.display.drawImage(0, 0, hugeHeart);

// explain the code to see the hero underwear
  if((haremCounter == 12) && (xHarem == -64) && (codeLearned == false)) {
    teachTheCode();    
  }
}

void backToHell() {
  switch (backToHellStep) {
    case 1:
      dismissal();
      break;
    case 2:
      darlingImHome();
      break;  
    case 3:
      ratsEverywhere();
      break;
    case 4:
      harem();
      break;
  }
}

void BadClock() {
  BadFrames = BadFrames + 1;

  if(BadFrames > 24) {
    BadSeconds = BadSeconds + 1;
    BadFrames = 0;
  }

  if(BadSeconds > 59) {
    BadMinutes = BadMinutes + 1;
    BadSeconds = 0;
  }
}

void lyrics() {
//  calculate the clock
  if(BadMinutes < 6) {
    BadClock();
  }

/*
// press up and down to change the lyrics
  if((gb.buttons.pressed(BUTTON_DOWN)) && (lyricsNumber < 43)) {
    lyricsNumber = lyricsNumber + 1;
  }
  if((gb.buttons.pressed(BUTTON_UP)) && (lyricsNumber > 0)) {
    lyricsNumber = lyricsNumber - 1;
  }
*/

// The lyrics change depending of the BadClock
  switch (BadMinutes) {
    case 0:
      if(BadSeconds == 17){
        lyricsNumber = 1;
      }
      if(BadSeconds == 25){
        lyricsNumber = 2;
      }
      if(BadSeconds == 35){
        lyricsNumber = 3;
      }
      if(BadSeconds == 39){
        lyricsNumber = 0;
      }
      if(BadSeconds == 42){
        lyricsNumber = 4;
      }
      if(BadSeconds == 50){
        lyricsNumber = 5;
      }
      if(BadSeconds == 58){
        lyricsNumber = 6;
      }
      break;
    case 1:
      if((BadSeconds == 2) && (BadFrames == 15)){
        lyricsNumber = 7;
      }
      if((BadSeconds == 6) && (BadFrames == 15)){
        lyricsNumber = 8;
      }
      if(BadSeconds == 10){
        lyricsNumber = 9;
      }
      if((BadSeconds == 14) && (BadFrames == 15)){
        lyricsNumber = 10;
      }
      if(BadSeconds == 19){
        lyricsNumber = 11;
      }
      if(BadSeconds == 24){
        lyricsNumber = 0;
      }
      if(BadSeconds == 31){
        lyricsNumber = 12;
      }
      if((BadSeconds == 39) && (BadFrames == 15)){
        lyricsNumber = 13;
      }
      if(BadSeconds == 48){
        lyricsNumber = 14;
      }
      if(BadSeconds == 56){
        lyricsNumber = 15;
      }
      break;
    case 2:
      if(BadSeconds == 0){
        lyricsNumber = 16;
      }
      if((BadSeconds == 3) && (BadFrames == 15)){
        lyricsNumber = 17;
      }
      if(BadSeconds == 8){
        lyricsNumber = 18;
      }
      if(BadSeconds == 12){
        lyricsNumber = 19;
      }
      if((BadSeconds == 16) && (BadFrames == 15)){
        lyricsNumber = 20;
      }
      if((BadSeconds == 18) && (BadFrames == 15)){
        lyricsNumber = 21;
      }
      if((BadSeconds == 21) && (BadFrames == 15)){
        lyricsNumber = 0;
      }
      if((BadSeconds == 44) && (BadFrames == 15)){
        lyricsNumber = 22;
      }
      if(BadSeconds == 49){
        lyricsNumber = 23;
      }
      if(BadSeconds == 53){
        lyricsNumber = 24;
      }
      if(BadSeconds == 57){
        lyricsNumber = 25;
      }
      break;
    case 3:
      if(BadSeconds == 1){
        lyricsNumber = 26;
      }
      if((BadSeconds == 5) && (BadFrames == 15)){
        lyricsNumber = 27;
      }
      if(BadSeconds == 9){
        lyricsNumber = 28;
      }
      if((BadSeconds == 13) && (BadFrames == 15)){
        lyricsNumber = 29;
      }
      if(BadSeconds == 18){
        lyricsNumber = 30;
      }
      if((BadSeconds == 21) && (BadFrames == 15)){
        lyricsNumber = 31;
      }
      if((BadSeconds == 23) && (BadFrames == 15)){
        lyricsNumber = 32;
      }
      if((BadSeconds == 25) && (BadFrames == 15)){
        lyricsNumber = 33;
      }
      if((BadSeconds == 29) && (BadFrames == 15)){
        lyricsNumber = 34;
      }
      if(BadSeconds == 34){
        lyricsNumber = 35;
      }
      if(BadSeconds == 38){
        lyricsNumber = 36;
      }
      if(BadSeconds == 40){
        lyricsNumber = 37;
      }
      if(BadSeconds == 42){
        lyricsNumber = 38;
      }
      if(BadSeconds == 46){
        lyricsNumber = 39;
      }
      if((BadSeconds == 50) && (BadFrames == 15)){
        lyricsNumber = 40;
      }
      if(BadSeconds == 54){
        lyricsNumber = 41;
      }
      if(BadSeconds == 56){
        lyricsNumber = 42;
      }
      break;
    case 4:
      if((BadSeconds == 0) && (BadFrames == 15)){
        lyricsNumber = 43;
      }
      break;
    default:
      lyricsNumber = 43;
      break;
  }

// draw the lyrics
  switch (lyricsNumber) {
    case 0:
      gb.display.drawImage(72, 92, musicNote);
      break;
    case 1:
      gb.display.setCursorX(5);
      gb.display.print(F("    Your horn is mine\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("      Go horny night\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("  Just throw your faith\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("       In firelight"));
      break;
    case 2:
      gb.display.setCursorX(5);
      gb.display.print(F("    Not safe for work\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("     Fill the Discord\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("    Now learn to code\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("    Your \"Hello world\"\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("         Turn on,"));
      break;
    case 3:
      gb.display.setCursorX(2);
      gb.display.print(F("         Turn on,\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("      Hold the Meta\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("      Press start..."));
      break;
    case 4:
      gb.display.setCursorX(2);
      gb.display.print(F("       Lucifer nods\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("     The code is free\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("    To play your mods\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("     There is no fee"));
      break;
    case 5:
      gb.display.setCursorX(2);
      gb.display.print(F("      Take the power\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("    Just read her mind\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("     The right answer\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("      Is just behind"));
      break;
    case 6:
      gb.display.setCursorX(5);
      gb.display.print(F(" Well they say the RAM's\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("        the limit\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("And Team Meat is an issue"));
      break;
    case 7:
      gb.display.setCursorX(2);
      gb.display.print(F(" But the cast is not full\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("         complete\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("Just add Baphomet through"));
      break;
    case 8:
      gb.display.setCursorX(2);
      gb.display.print(F("  Because I bad, I bad -\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("         turn on\n"));
      gb.display.setColor(GRAY);
      gb.display.setCursorX(2);
      gb.display.print(F("  Bad bad - befriend all\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("          demons"));
      break;
    case 9:
      gb.display.setCursorX(5);
      gb.display.print(F(" You know I bad, I bad -\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("       you know it\n"));
      gb.display.setColor(GRAY);
      gb.display.setCursorX(2);
      gb.display.print(F("  Bad bad - befriend all\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("          demons"));
      break;
    case 10:
      gb.display.setCursorX(5);
      gb.display.print(F(" You know I bad, I bad -\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("    turn on, you know\n"));
      gb.display.setColor(GRAY);
      gb.display.setCursorX(2);
      gb.display.print(F("  Bad bad - befriend all\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("          demons"));
      break;
    case 11:
      gb.display.setCursorX(2);
      gb.display.print(F("And the whole world in not\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("       Tasty enough\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("  To fulfill my appetite\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("         Who bad?"));
      break;
    case 12:
      gb.display.setCursorX(5);
      gb.display.print(F("     The game design\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("     Forget your Pong\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("     Is all but kind\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("    The maze is strong"));
      break;
    case 13:
      gb.display.setCursorX(2);
      gb.display.print(F("    To choose one girl\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("     Is quite unfair\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("     I need them all\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("      At Maker Faire"));
      break;
    case 14:
      gb.display.setCursorX(5);
      gb.display.print(F("     The Pocket Chip\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("       The Pokitto\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("       The Arduboy\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("      The Gamebuino"));
      break;
    case 15:
      gb.display.setCursorX(5);
      gb.display.print(F("But the game is full open\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("          source\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("     Open to polygamy"));
      break;
    case 16:
      gb.display.setCursorX(2);
      gb.display.print(F("  A master piece made of\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("          pixels\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("  Featured on Polygon..."));
      break;
    case 17:
      gb.display.setCursorX(2);
      gb.display.print(F("  Because I bad, I bad -\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("         turn on\n"));
      gb.display.setColor(GRAY);
      gb.display.setCursorX(2);
      gb.display.print(F("  Bad bad - befriend all\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("          demons"));
      break;
    case 18:
      gb.display.setCursorX(5);
      gb.display.print(F(" You know I bad, I bad -\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("       you know it\n"));
      gb.display.setColor(GRAY);
      gb.display.setCursorX(2);
      gb.display.print(F("  Bad bad - befriend all\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("          demons"));
      break;
    case 19:
      gb.display.setCursorX(5);
      gb.display.print(F(" You know I bad, I bad -\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("  you know it, you know\n"));
      gb.display.setColor(GRAY);
      gb.display.setCursorX(2);
      gb.display.print(F("  Bad bad - befriend all\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("          demons"));
      break;
    case 20:
      gb.display.setCursorX(2);
      gb.display.print(F("And the whole world in not\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("       tasty enough\n"));
      gb.display.setColor(GRAY);
      gb.display.setCursorX(2);
      gb.display.print(F("And the whole world in not\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("       tasty enough"));
      break;
    case 21:
      gb.display.setCursorX(2);
      gb.display.print(F("  To fulfill my appetite\n"));
      gb.display.setColor(GRAY);
      gb.display.setCursorX(2);
      gb.display.print(F("  To fulfill my appetite\n"));
      gb.display.setColor(WHITE);
      gb.display.setCursorX(2);
      gb.display.print(F("         Who bad?\n"));
      break;
    case 22:
      gb.display.setCursorX(5);
      gb.display.print(F(" You can change the game\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("       this morning\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("  This could be a better\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("           code"));
      break;
    case 23:
      gb.display.setCursorX(5);
      gb.display.print(F("If you prefer what you're\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("         thinking\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("   Won't you slap your\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("        keyboard?"));
      break;
    case 24:
      gb.display.setCursorX(2);
      gb.display.print(F("  Because I bad, I bad -\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("         turn on\n"));
      gb.display.setColor(GRAY);
      gb.display.setCursorX(2);
      gb.display.print(F("  Bad bad - befriend all\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("          demons"));
      break;
    case 25:
      gb.display.setCursorX(5);
      gb.display.print(F(" You know I bad, I bad -\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("       you know it\n"));
      gb.display.setColor(GRAY);
      gb.display.setCursorX(2);
      gb.display.print(F("  Bad bad - befriend all\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("          demons"));
      break;
    case 26:
      gb.display.setCursorX(5);
      gb.display.print(F(" You know I bad, I bad -\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("  you know it, you know\n"));
      gb.display.setColor(GRAY);
      gb.display.setCursorX(2);
      gb.display.print(F("  Bad bad - befriend all\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("          demons"));
      break;
    case 27:
      gb.display.setCursorX(5);
      gb.display.print(F("And the... Woo! Woo! Woo!\n"));
      gb.display.setColor(GRAY);
      gb.display.setCursorX(2);
      gb.display.print(F("And the whole world is not\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("       tasty enough\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("To fulfill my appetite..."));
      break;
    case 28:
      gb.display.setCursorX(5);
      gb.display.print(F(" You know I bad, I bad -\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("         turn on\n"));
      gb.display.setColor(GRAY);
      gb.display.setCursorX(2);
      gb.display.print(F("  Bad bad - befriend all\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("          demons"));
      break;
    case 29:
      gb.display.setCursorX(5);
      gb.display.print(F(" You know I bad, I bad -\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("you know it - you know it\n"));
      gb.display.setColor(GRAY);
      gb.display.setCursorX(2);
      gb.display.print(F("  Bad bad - befriend all\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("          demons"));
      break;
    case 30:
      gb.display.setCursorX(5);
      gb.display.print(F(" You know, you know, you\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("      know - turn on\n"));
      gb.display.setColor(GRAY);
      gb.display.setCursorX(2);
      gb.display.print(F("  Bad bad - befriend all\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("          demons"));
      break;
    case 31:
      gb.display.setCursorX(2);
      gb.display.print(F("And the whole world is not\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("       tasty enough\n"));
      gb.display.setColor(GRAY);
      gb.display.setCursorX(2);
      gb.display.print(F("And the whole world is not\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("       tasty enough"));
      break;
    case 32:
      gb.display.setCursorX(2);
      gb.display.print(F("     To fulfill my...\n"));
      gb.display.setColor(GRAY);
      gb.display.setCursorX(2);
      gb.display.print(F("  To fulfill my appetite"));
      break;
    case 33:
      gb.display.setCursorX(5);
      gb.display.print(F("You know they're smooth -\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("   I bad - you know it\n"));
      gb.display.setColor(GRAY);
      gb.display.setCursorX(2);
      gb.display.print(F("  Bad bad - befriend all\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("          demons"));
      break;
    case 34:
      gb.display.setCursorX(2);
      gb.display.print(F("  You know I bad - I bad\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("          daily\n"));
      gb.display.setColor(GRAY);
      gb.display.setCursorX(2);
      gb.display.print(F("  Bad bad - befriend all\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("          demons"));
      break;
    case 35:
      gb.display.setCursorX(5);
      gb.display.print(F(" You know, you know, you\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("    know it - turn on\n"));
      gb.display.setColor(GRAY);
      gb.display.setCursorX(2);
      gb.display.print(F("  Bad bad - befriend all\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("          demons"));
      break;
    case 36:
      gb.display.setCursorX(2);
      gb.display.print(F("And the whole world is not\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("       tasty enough\n"));
      gb.display.setColor(GRAY);
      gb.display.setCursorX(2);
      gb.display.print(F("And the whole world is not\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("       tasty enough"));
      break;
    case 37:
      gb.display.setCursorX(2);
      gb.display.print(F("           Woo!\n"));
      gb.display.setColor(GRAY);
      gb.display.setCursorX(2);
      gb.display.print(F("  To fulfill my appetite\n"));
      break;
    case 38:
      gb.display.setCursorX(5);
      gb.display.print(F(" You know I bad, I bad -\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("       you know it\n"));
      gb.display.setColor(GRAY);
      gb.display.setCursorX(2);
      gb.display.print(F("  Bad bad - befriend all\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("          demons"));
      break;
    case 39:
      gb.display.setCursorX(5);
      gb.display.print(F("You know I bad - you know\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("          - hoo!\n"));
      gb.display.setColor(GRAY);
      gb.display.setCursorX(2);
      gb.display.print(F("  Bad bad - befriend all\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("          demons"));
      break;
    case 40:
      gb.display.setCursorX(2);
      gb.display.print(F(" You know I bad - I bad -\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("  you know it, you know\n"));
      gb.display.setColor(GRAY);
      gb.display.setCursorX(2);
      gb.display.print(F("  Bad bad - befriend all\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("          demons"));
      break;
    case 41:
      gb.display.setCursorX(2);
      gb.display.print(F("And the whole world is not\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("       tasty enough\n"));
      gb.display.setColor(GRAY);
      gb.display.setCursorX(2);
      gb.display.print(F("And the whole world is not\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("       tasty enough"));
      break;
    case 42:
      gb.display.setCursorX(5);
      gb.display.print(F("To fulfill my appetite...\n"));
      gb.display.setColor(GRAY);
      gb.display.setCursorX(5);
      gb.display.print(F("To fulfill my appetite...\n"));
      gb.display.setColor(WHITE);
      gb.display.setCursorX(2);
      gb.display.print(F("         Who bad?"));
      break;
    case 43:
      gb.display.setColor(RED);
      gb.display.setCursorX(5);
      gb.display.print(F("  Music"));
      gb.display.setColor(WHITE);
      gb.display.print(F(" Michael Jackson\n\n"));
      gb.display.setColor(RED);
      gb.display.setCursorX(5);
      gb.display.print(F("   Lyrics"));
      gb.display.setColor(WHITE);
      gb.display.print(F(" Juice Lizard\n\n"));
      gb.display.setColor(RED);
      gb.display.setCursorX(5);
      gb.display.print(F("Vocals"));
      gb.display.setColor(WHITE);
      gb.display.print(F(" Alessandro Granato"));
      break;
  }
}

// lyrics for "Acrylique et pixels"
void HeavenLyrics() {
//  calculate the clock
  if(BadMinutes < 6) {
    BadClock();
  }

// press up and down to change the lyrics
  if((gb.buttons.pressed(BUTTON_DOWN)) && (lyricsNumber < 17)) {
    lyricsNumber = lyricsNumber + 1;
  }
  if((gb.buttons.pressed(BUTTON_UP)) && (lyricsNumber > 0)) {
    lyricsNumber = lyricsNumber - 1;
  }

// The lyrics change depending of the BadClock
  switch (BadMinutes) {
    case 0:
      if(BadSeconds == 15){
        lyricsNumber = 1;
      }
      if(BadSeconds == 30){
        lyricsNumber = 2;
      }
      if(BadSeconds == 45){
        lyricsNumber = 3;
      }
      break;
    case 1:
      if(BadSeconds == 1){
        lyricsNumber = 4;
      }
      if(BadSeconds == 16) {
        lyricsNumber = 5;
      }
      if(BadSeconds == 33){
        lyricsNumber = 6;
      }
      if(BadSeconds == 47) {
        lyricsNumber = 7;
      }
      break;
    case 2:
      if(BadSeconds == 3){
        lyricsNumber = 8;
      }
      if(BadSeconds == 18) {
        lyricsNumber = 9;
      }
      if(BadSeconds == 35){
        lyricsNumber = 0;
      }
      break;
    case 3:
      if(BadSeconds == 4){
        lyricsNumber = 10;
      }
      if(BadSeconds == 20) {
        lyricsNumber = 11;
      }
      if(BadSeconds == 34){
        lyricsNumber = 12;
      }
      if(BadSeconds == 50) {
        lyricsNumber = 13;
      }
      break;
    case 4:
      if(BadSeconds == 5) {
        lyricsNumber = 14;
      }
      if(BadSeconds == 21) {
        lyricsNumber = 15;
      }
      if(BadSeconds == 36) {
        lyricsNumber = 16;
      }
      break;
    case 5:
      if(BadSeconds == 2) {
        lyricsNumber = 17;
      }
    default:
      lyricsNumber = 17;
      break;
  }

// draw the lyrics
  switch (lyricsNumber) {
    case 0:
      gb.display.drawImage(72, 92, blueMusicNote);
      break;
    case 1:
      gb.display.setCursorX(5);
      gb.display.print(F("Acrylique peinte sagement\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("   Elle pense aux jeux\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("      \xC9""lectroniques"));
      break;
    case 2:
      gb.display.setCursorX(2);
      gb.display.print(F("   Insouciance, elle se\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("         d\xE9""pense\n"));
      gb.display.setCursorX(2);
      gb.display.print(F(" Elle entre dans l'action"));
      break;
    case 3:
      gb.display.setCursorX(2);
      gb.display.print(F("       Tetris, Sega\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("    Entre deux, trois\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("        dimensions"));
      break;
    case 4:
      gb.display.setCursorX(2);
      gb.display.print(F(" Hors du ring elle pousse\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("   L'ennui des journaux\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("   C'est la guerre des\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("         boutons"));
      break;
    case 5:
      gb.display.setCursorX(2);
      gb.display.print(F("Elle se pose des questions\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("Sur le divorce d'une \xE9""lite\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("      et d'un monde\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("        Acrylique"));
      break;
    case 6:
      gb.display.setCursorX(2);
      gb.display.print(F("    Acrylique inspir\xE9""e\n"));
      gb.display.setCursorX(5);
      gb.display.print(F(" Elle tape du code, code"));
      break;
    case 7:
      gb.display.setCursorX(5);
      gb.display.print(F("  Dans les forums, plus\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("         autonome\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("En algorithmes elle avance"));
      break;
    case 8:
      gb.display.setCursorX(2);
      gb.display.print(F("  Mais ce m\xE9""pris myst\xE8""re\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("    Cette vraie omert\xE0""\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("Acrylique reste sans voix"));
      break;
    case 9:
      gb.display.setCursorX(2);
      gb.display.print(F("Elle se pose des questions\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("Sur le divorce d'une \xE9""lite\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("      et d'un monde"));
      break;
    case 10:
      gb.display.setCursorX(5);
      gb.display.print(F("   Acrylique voyageuse\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("  C'est l'histoire d'une\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("   toile et d'un monde"));
      break;
    case 11:
      gb.display.setCursorX(2);
      gb.display.print(F("   Acrylique acrylique,\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("     peinte sagement\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("   Elle pense aux jeux\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("      \xC9""lectroniques"));
      break;
    case 12:
      gb.display.setCursorX(2);
      gb.display.print(F("       Tetris, Sega\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("    Entre deux, trois\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("        dimensions"));
      break;
    case 13:
      gb.display.setCursorX(2);
      gb.display.print(F("C'est hors du ring qu'elle\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("          pousse\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("   L'ennui des journaux\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("   C'est la guerre des\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("         boutons"));
      break;
    case 14:
      gb.display.setCursorX(2);
      gb.display.print(F("Elle se pose des questions\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("Sur le divorce d'une \xE9""lite\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("      et d'un monde"));
      break;
    case 15:
      gb.display.setCursorX(2);
      gb.display.print(F("Elle se pose "));
      gb.display.setColor(LIGHTBLUE);
      gb.display.print(F("(se pose)"));
      gb.display.setColor(BLUE);
      gb.display.print(F(" des\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("        questions\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("Sur le divorce d'une \xE9""lite\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("      et d'un monde"));
      break;
    case 16:
      gb.display.setCursorX(2);
      gb.display.print(F("Elle se pose des questions\n"));
      gb.display.setCursorX(2);
      gb.display.print(F("Sur le divorce d'une \xE9""lite\n"));
      gb.display.setCursorX(5);
      gb.display.print(F("      et d'un monde"));
      break;
    case 17:
      gb.display.setColor(LIGHTBLUE);
      gb.display.setCursorX(5);
      gb.display.print(F("  Music"));
      gb.display.setColor(BLUE);
      gb.display.print(F(" Vanessa Paradis\n\n"));
      gb.display.setColor(LIGHTBLUE);
      gb.display.setCursorX(5);
      gb.display.print(F("   Lyrics"));
      gb.display.setColor(BLUE);
      gb.display.print(F(" Juice Lizard\n\n"));
      gb.display.setColor(LIGHTBLUE);
      gb.display.setCursorX(2);
      gb.display.print(F("   Vocals"));
      gb.display.setColor(BLUE);
//      gb.display.print(F(" Fanny Krief"));
      gb.display.print(F(" Marine Parodi"));
      break;
  }
}

// song in Hell, Mickael Jackson parody
void BAD() {

/*
// draw the BAD song timer
  gb.display.setCursor(0, 0);
  gb.display.setColor(GREEN);
  gb.display.setFont(font5x7);
  gb.display.setFontSize(1);
  gb.display.print(BadMinutes);
  gb.display.print("m");
  gb.display.print(BadSeconds);
  gb.display.print("s");
  gb.display.print(BadFrames);
*/

// we draw the big "BAD"
  gb.display.drawImage(26, 20, BAD108x48);


// Start the song when pressing [A]
// "Befriend all demons" (lyrics by Juice Lizard)
  if(gb.buttons.pressed(BUTTON_A)) {
    gb.sound.stop(track);
    track = gb.sound.play("Befriend all demons.wav");
    BadIsPlaying = true;
    beforePress = 0;
    BadFrames = 0;
    BadSeconds = 0;
    BadMinutes = 0;
    lyricsNumber = 0;
  }

// We print the text
  gb.display.setFont(font5x7);
  gb.display.setFontSize(1);

  if(BadIsPlaying == false) {
    gb.display.setColor(RED);
    gb.display.setCursorY(88);

//    gb.display.setCursorX(2);
//    gb.display.print("       PRESS [B] TO\n\n");
    gb.display.setCursorX(2);
    gb.display.print(" \n");  
      
// We color the title "BEFRIEND ALL DEMONS" in white, gray and dark gray
  if(trackColorCounter < 5) {
    gb.display.setColor(WHITE);
  }
  if(((trackColorCounter > 4) && (trackColorCounter < 10)) || (trackColorCounter > 14)) {
    gb.display.setColor(GRAY);
  }
  if((trackColorCounter > 9) && (trackColorCounter < 15)) {
    gb.display.setColor(DARKGRAY);
  }

  trackColorCounter = trackColorCounter + 1;

  if(trackColorCounter > 19) {
    trackColorCounter = 0;
  }

      gb.display.setCursorX(5);
      gb.display.print(F("   BEFRIEND ALL DEMONS"));

  } else {
    gb.display.setColor(WHITE);
    gb.display.setCursorY(80);

    lyrics();
  }

// go to the Hell level selection screen
// when pressing [B]
  if(gb.buttons.pressed(BUTTON_B)) {
    gb.sound.stop(track);
    
    hasSecretB = false;
    hasSecretA = false;
    hasSecretD = false;

    BadIsPlaying = false;

    BadFrames = 0;
    BadSeconds = 0;
    BadMinutes = 0;
    lyricsNumber = 0;

// Hell level selection screen
    gamestate = 5;

    fromBadScreen = true;
  }
}

// song in Heaven, Vanessa Paradis parody
// "Acrylique et pixel" (lyrics by Juice Lizard)
void AcryliqueEtPixels() {
  gb.display.clear(WHITE);

/*
// draw the BAD song timer
  gb.display.setCursor(0, 0);
  gb.display.setColor(GREEN);
  gb.display.setFont(font5x7);
  gb.display.setFontSize(1);
  gb.display.print(BadMinutes);
  gb.display.print("m");
  gb.display.print(BadSeconds);
  gb.display.print("s");
  gb.display.print(BadFrames);
*/

// we draw the big "DOG"
  gb.display.drawImage(36, 32, bigYellowTriangle);
  gb.display.drawImage(68, 32, bigPinkCircle);
  gb.display.drawImage(100, 32, bigBlueSquare);

// Start the Vanessa Paradis song when pressing [A]
  if(gb.buttons.pressed(BUTTON_A)) {
    gb.sound.stop(track);
    track = gb.sound.play("Acrylique et Pixels.wav");
    BadIsPlaying = true;
    beforePress = 0;
    BadFrames = 0;
    BadSeconds = 0;
    BadMinutes = 0;
    lyricsNumber = 0;
  }

// We print the text
  gb.display.setFont(font5x7);
  gb.display.setFontSize(1);

  if(BadIsPlaying == false) {
    gb.display.setColor(BLUE);
    gb.display.setCursorY(88);

    gb.display.setCursorX(2);
    gb.display.print(" \n");  
      
// We color the title "ACRYLIQUE ET PIXELS" in light blue, blue and dark blue
  if(trackColorCounter < 5) {
    gb.display.setColor(LIGHTBLUE);
  }
  if(((trackColorCounter > 4) && (trackColorCounter < 10)) || (trackColorCounter > 14)) {
    gb.display.setColor(BLUE);
  }
  if((trackColorCounter > 9) && (trackColorCounter < 15)) {
    gb.display.setColor(DARKBLUE);
  }

  trackColorCounter = trackColorCounter + 1;

  if(trackColorCounter > 19) {
    trackColorCounter = 0;
  }

      gb.display.setCursorX(5);
      gb.display.print(F("   ACRYLIQUE ET PIXELS"));

  } else {
    gb.display.setColor(BLUE);
    gb.display.setCursorY(80);

    HeavenLyrics();
  }

// go to the Heaven level selection screen
// when pressing [B]
  if(gb.buttons.pressed(BUTTON_B)) {
    gb.sound.stop(track);

    BadFrames = 0;
    BadSeconds = 0;
    BadMinutes = 0;
    lyricsNumber = 0;
    
    hasYellowTriangle = false;
    hasPinkCircle = false;
    hasBlueSquare = false;

    BadIsPlaying = false;

// Heaven level selection screen
    gamestate = 12;

//    fromBadScreen = true;
  }

}

// We decide which sprite goes with which cloud.
void updateClouds() {
  for (int row=1; row<(NB_ROWS_LEVELS-1); row++) {
    for (int column=1; column<(NB_COLUMNS_LEVELS-1); column++) {
      if(level[row-1][column] == 'M') {
        if(level[row][column+1] == 'M') {
          if(level[row+1][column] == 'M') {
            if(level[row][column-1] == 'M') {
              clouds[row][column] = 'a';
            } else {
              clouds[row][column] = 'b';
            }
          } else {
            if(level[row][column-1] == 'M') {
              clouds[row][column] = 'c';
            } else {
              clouds[row][column] = 'd';
            }
          }
        } else {
          if(level[row+1][column] == 'M') {
            if(level[row][column-1] == 'M') {
              clouds[row][column] = 'e';
            } else {
              clouds[row][column] = 'f';
            }
          } else {
            if(level[row][column-1] == 'M') {
              clouds[row][column] = 'g';
            } else {
              clouds[row][column] = 'h';
            }
          }
        }
      } else {
        if(level[row][column+1] == 'M') {
          if(level[row+1][column] == 'M') {
            if(level[row][column-1] == 'M') {
              clouds[row][column] = 'i';
            } else {
              clouds[row][column] = 'j';
            }
          } else {
            if(level[row][column-1] == 'M') {
              clouds[row][column] = 'k';
            } else {
              clouds[row][column] = 'l';
            }
          }
        } else {
          if(level[row+1][column] == 'M') {
            if(level[row][column-1] == 'M') {
              clouds[row][column] = 'm';
            } else {
              clouds[row][column] = 'n';
            }
          } else {
            if(level[row][column-1] == 'M') {
              clouds[row][column] = 'o';
            } else {
              clouds[row][column] = 'p';
            }
          }
        }
      }
    }
  }
}

// Graphics in the Heaven levels
void drawHeavenWall(int row, int column) {
  switch (walls[row][column]) {
    case 'a':
      gb.display.drawImage(column*16 - 8, row*16 - 16, cloud_a);
    break;
    case 'b':
      gb.display.drawImage(column*16 - 8, row*16 - 16, cloud_b);
    break;
    case 'c':
      gb.display.drawImage(column*16 - 8, row*16 - 16, cloud_c);
    break;
    case 'd':
      gb.display.drawImage(column*16 - 8, row*16 - 16, cloud_d);
    break;
    case 'e':
      gb.display.drawImage(column*16 - 8, row*16 - 16, cloud_e);
    break;
    case 'f':
      gb.display.drawImage(column*16 - 8, row*16 - 16, cloud_f);
    break;
    case 'g':
      gb.display.drawImage(column*16 - 8, row*16 - 16, cloud_g);
    break;
    case 'h':
      gb.display.drawImage(column*16 - 8, row*16 - 16, cloud_h);
    break;
    case 'i':
      gb.display.drawImage(column*16 - 8, row*16 - 16, cloud_i);
    break;
    case 'j':
      gb.display.drawImage(column*16 - 8, row*16 - 16, cloud_j);
    break;
    case 'k':
      gb.display.drawImage(column*16 - 8, row*16 - 16, cloud_k);
    break;
    case 'l':
      gb.display.drawImage(column*16 - 8, row*16 - 16, cloud_l);
    break;
    case 'm':
      gb.display.drawImage(column*16 - 8, row*16 - 16, cloud_m);
    break;
    case 'n':
      gb.display.drawImage(column*16 - 8, row*16 - 16, cloud_n);
    break;
    case 'o':
      gb.display.drawImage(column*16 - 8, row*16 - 16, cloud_o);
    break;
    case 'p':
      gb.display.drawImage(column*16 - 8, row*16 - 16, cloud_p);
    break;
    default:
      gb.display.drawImage(column*16 - 8, row*16 - 16, cloud_a);
    break;
  }
}

void drawPlayerOnTarget(int row, int column) {
  gb.display.drawImage(column*16 - 8, row*16 - 16, carton);
  drawPlayer(row, column);
  gb.display.drawImage(column*16 - 8, row*16 - 6, cartonFront);
}

void drawYogurt(int row, int column) {
  gb.display.drawImage(column*16 - 8, row*16 - 16, yogurt);
}

void drawYogurtOnTarget(int row, int column) {
  gb.display.drawImage(column*16 - 8, row*16 - 16, carton);
  gb.display.drawImage(column*16 - 8, row*16 - 17, yogurt);
  gb.display.drawImage(column*16 - 8, row*16 - 6, cartonFront);
}

void drawTarget(int row, int column) {
  gb.display.drawImage(column*16 - 8, row*16 - 16, carton);
}

void drawHeavenGraphics() {
// We paint all the screen in light blue.
  gb.display.clear(LIGHTBLUE);

// 'M' HeavenWall, '@' player, '+' player on target,
// '$' yogurt, '*' yogurt on target, '.' target, ' ' ground,

// Each of the level boxes is displayed.
  for (int row=0; row<NB_ROWS_LEVELS; row++) {
    for (int column=0; column<NB_COLUMNS_LEVELS; column++) {
      switch (level[row][column]) {
        case 'M':
          drawHeavenWall(row, column);
          break;
        case '@':
          drawPlayer(row, column);
          break;
        case '+':
          drawPlayerOnTarget(row, column);
          break;
        case '$':
          drawYogurt(row, column);
          break;
        case '*':
          drawYogurtOnTarget(row, column);
          break;
        case '.':
          drawTarget(row, column);
          break;
        case ' ':
// If ground, we draw nothing (gb.display.clear() color).
          break;
        default:
          break;
      }
    }
  }

// We draw the secret letters hidden under some blocks
  if(fromDogScreen == false) {
    secretLetters();
  }
}

// We reset the level or go to the next one.
void changeWYFLevel() {

  answered = 0;

// We copy the selected constant level table to the variable level table.
  switch (levelNumber) {
    case 0:
    case 11:
      memcpy(level, level11, sizeof(level));
      rowPlayer = 5;
      columnPlayer =8;
      heroTurnsRight = false;
    break;
    case 12:
      memcpy(level, level12, sizeof(level));
      rowPlayer = 4;
      columnPlayer = 4;
      heroTurnsRight = true;
    break;
    case 13:
      memcpy(level, level13, sizeof(level));
      rowPlayer = 4;
      columnPlayer = 7;
      heroTurnsRight = false;
    break;
    case 14:
      memcpy(level, level14, sizeof(level));
      rowPlayer = 3;
      columnPlayer = 2;
      heroTurnsRight = true;
    break;
    case 15:
      memcpy(level, level15, sizeof(level));
      rowPlayer = 5;
      columnPlayer = 4;
      heroTurnsRight = true;
    break;
    case 16:
      memcpy(level, level16, sizeof(level));
      rowPlayer = 4;
      columnPlayer = 3;
      heroTurnsRight = true;
    break;
    case 17:
      memcpy(level, level17, sizeof(level));
      rowPlayer = 7;
      columnPlayer = 5;
      heroTurnsRight = false;
    break;
    default:
    
    break;
  }

// Walls sprites function
  updateWalls();

}

void resetAccident() {
  xSquareNose = -20;
  xDumbulance = -156;
  accidentCounter = 0;
  accidentStep = 0;
  accidentCounterMax = 66;
  bigDemon = 8;
  answered = 0;
}

void drawHeavenClap() {
// We draw the big cloud
  if(xBigCloud < 160) {
    gb.display.drawImage(xBigCloud, 0, bigCloud1);
  }
  if((xBigCloud > 0) && (xBigCloud < 192)) {
    gb.display.drawImage(xBigCloud - 32, 0, bigCloud2);
  }
  if((xBigCloud > 32) && (xBigCloud < 224)) {
    gb.display.drawImage(xBigCloud - 64, 0, bigCloud3);
  }
  if((xBigCloud > 64) && (xBigCloud < 256)) {
    gb.display.drawImage(xBigCloud - 96, 0, bigCloud4);
  }
  if((xBigCloud > 96) && (xBigCloud < 288)) {
    gb.display.drawImage(xBigCloud - 128, 0, bigCloud5);
  }
  if((xBigCloud > 128) && (xBigCloud < 320)) {
    gb.display.drawImage(xBigCloud - 160, 0, bigCloud6);
  }
  if((xBigCloud > 160) && (xBigCloud < 352)) {
    gb.display.drawImage(xBigCloud - 192, 0, bigCloud7);
  }
  if((xBigCloud > 192) && (xBigCloud < 384)) {
    gb.display.drawImage(xBigCloud - 224, 0, bigCloud8);
  }
  if((xBigCloud > 224) && (xBigCloud < 416)) {
    gb.display.drawImage(xBigCloud - 256, 0, bigCloud9);
  }

// We move the big bloud to the right
  xBigCloud = xBigCloud + 5;

// We stop the clap animation if the big cloud
// goes totally off the screen by the right side.
  if(xBigCloud > 416) {
    xBigCloud = -32;
    clap = false;
  }

// We update the level or change the gamestate
// if the big cloud covers all the screen.
  if(xBigCloud == 193) {

    if((levelNumber < 17) && (nextLevel == true)) {
      WYFLevelNumber = WYFLevelNumber + 1;
      levelNumber = levelNumber + 1;
      nextLevel = false;
    } else if((levelNumber == 17) && (nextLevel == true)) {
      goToHell = true;
      nextLevel = false;
    }
    
    changeWYFLevel();
    bigDemon = 8;
    if(gamestate == 6) {
      resetAccident();
      gamestate = 7; // HeavenDialogues
    } else if((gamestate == 7) || (gamestate == 11) || (gamestate == 12)){
      WYFLevelNumber = levelNumber - 10;
      if((levelNumber == 17) && (gamestate == 7) && (goToHell == true)){
        gamestate = 9; // back to Hell
        goToHell = false;
      } else {
        gamestate = 11; // Heaven levels
      }
    }
  }
}

void moveToWYF(int dir) {

// If next box is wall…
  if(NEXT(dir,1) == 'M') {
// … we don't move the player.
  return;
  }

// If the two next boxes are yogurts…
  if( ( (NEXT(dir,1) == '$') || (NEXT(dir,1) == '*') ) && ( (NEXT(dir,2) == '$') || (NEXT(dir,2) == '*') || (NEXT(dir,2) == 'M') ) ) {
// … we don't move the player, but he kicks the yogurt.
    heroKicks = true;
//    gb.sound.playTick();
    gb.sound.fx(kickOnly);
    return;
  }
  
// We know that movement is allowed

// If next box is a yogurt…

  if( (NEXT(dir,1) == '$') || (NEXT(dir,1) == '*') ) {
    {
// … the player kicks it…
      heroKicks = true;
//      gb.sound.playTick();
      gb.sound.fx(pushSkeleton);
// … we move the yogurt to the next box…
      if(NEXT(dir,2) == ' ') {
        NEXT(dir,2) = '$';
      } else if(NEXT(dir,2) == '.') {
        NEXT(dir,2) = '*';
      }
    }

// … and we take off the yogurt from its previous location.
    if(NEXT(dir,1) == '$') {
      NEXT(dir,1) = ' ';
    } else if (NEXT(dir,1) == '*') {
      NEXT(dir,1) = '.';
    }
    return;
  }

// If next box is empty…
  if(NEXT(dir,1) == ' ') {
//    gb.sound.playTick();
    gb.sound.fx(simpleMove);
// … we put a player to this next box…
    NEXT(dir,1) = '@';
// … and we take off the player from its previous location.
    previousBox();
// We update the player coordinates.
    rowPlayer = nr(dir,1);
    columnPlayer = nc(dir,1);
    return;
  }

// If next box is a target…
  if(NEXT(dir,1) == '.') {
//    gb.sound.playTick();
    gb.sound.fx(simpleMove);
// … we put a player on target to this next box…
    NEXT(dir,1) = '+';
// … and we take off the player from its previous location.
    previousBox();
// We update the player coordinates.
    rowPlayer = nr(dir,1);
    columnPlayer = nc(dir,1);
    return;
  }
}

bool isLevelCleared() {
  for (int row=0; row<NB_ROWS_LEVELS; row++) {
    for (int column=0; column<NB_COLUMNS_LEVELS; column++) {
      if(level[row][column] == '$') {
        return false;
      }
    }
  }
  nextLevel = true;
  
  return true;
}

void HeavenInputs() {
  if(gb.buttons.pressed(BUTTON_UP)) {
    moveToWYF(UP);
  }

  if(gb.buttons.pressed(BUTTON_DOWN)) {
    moveToWYF(DOWN);
  }

  if(gb.buttons.pressed(BUTTON_RIGHT)) {
    heroTurnsRight = true;
    moveToWYF(RIGHT);
  }

  if(gb.buttons.pressed(BUTTON_LEFT)) {
    heroTurnsRight = false;
    moveToWYF(LEFT);
  }

// If direction buttons are released,
// the player stops to kick,
// and we check if level is cleared.
  if((gb.buttons.released(BUTTON_UP)) || (gb.buttons.released(BUTTON_DOWN)) || (gb.buttons.released(BUTTON_RIGHT)) || (gb.buttons.released(BUTTON_LEFT))) {
    heroKicks = false;
    WYFLevelFinished = isLevelCleared();
  }
}

void HeavenLevels() {
// We draw the graphics
  drawHeavenGraphics();

// We reset the level if [B] is pressed
  if(gb.buttons.pressed(BUTTON_B)) {
    clap = true;
  }

// The big cloud moves if clap is true
  if(clap == true) {
     drawHeavenClap();
  }

  if((clap == false) && (WYFLevelFinished == false)) {
    HeavenInputs();
  }

  if(WYFLevelFinished == true) {
    goDialogues = goDialogues + 1;
  }

  if(goDialogues > 4) {
    answered = 0;
    gamestate = 7; // Heaven dialogues
    goDialogues = 0;
    WYFLevelFinished = false;
    topAnswer = true;
// we update the game progress
    if(lastLevelWon < levelNumber) {
      lastLevelWon = levelNumber;
      gb.save.set(0, lastLevelWon);
    }
/*    
    if(levelNumber < 17) {
      WYFLevelNumber = WYFLevelNumber + 1;
      levelNumber = levelNumber + 1;
    }
*/   
  }

// laiceps si noitcnuf siht
  docTeaches();

// we go to level selection screen if we press the menu button
  if((gb.buttons.pressed(BUTTON_MENU)) && (clap == false)) {
    gamestate = 12; // Heaven level selection screen
  }
}

void HeavenChapterSelect() {
  gb.display.clear(WHITE);

  // We draw the level number in a nice rectangle.
  gb.display.setColor(YELLOW);
  gb.display.drawRect(50, 44, 60, 40);
  gb.display.drawRect(54, 48, 52, 32);
  gb.display.drawRect(53, 47, 54, 34);

  gb.display.fillRect(57, 51, 46, 26);


  Image level(LEVEL_NB_DATA);
  level.setFrame(levelNumber - 11);
  if((levelNumber == 12) || (levelNumber == 17)) {
    gb.display.drawImage(66, 54, level, 32, 20);
  } else {
    gb.display.drawImage(65, 54, level, 32, 20);
  }

// We print the name of the level.
/*
  gb.display.setCursorY(98);
  gb.display.setColor(YELLOW);
  gb.display.setFont(font5x7);
  gb.display.setFontSize(2);
*/

  switch (levelNumber) {
    case 11:
//      gb.display.setCursorX(3);
//      gb.display.print("    Pride");
      gb.display.drawImage(57, 100, PRIDE);
      break;
    case 12:
//      gb.display.setCursorX(3);
//      gb.display.print("    Greed");
      gb.display.drawImage(55, 100, GREED);
      break;
    case 13:
//      gb.display.setCursorX(9);
//      gb.display.print("    Lust");
      gb.display.drawImage(60, 100, LUST);
      break;
    case 14:
//      gb.display.setCursorX(3);
//      gb.display.print("    Anger");
      gb.display.drawImage(52, 100, ANGER);
      break;
    case 15:
//      gb.display.setCursorX(9);
//      gb.display.print("  Gluttony");
      gb.display.drawImage(35, 100, GLUTTONY);
      break;
    case 16:
//      gb.display.setCursorX(9);
//      gb.display.print("    Envy");
      gb.display.drawImage(56, 100, ENVY);
      break;
    case 17:
//      gb.display.setCursorX(3);
//      gb.display.print("    Sloth");
      gb.display.drawImage(54, 100, SLOTH);
      break;
  }

// Inputs to select the level.
  if(clap == false){
    if((gb.buttons.pressed(BUTTON_RIGHT)) && (levelNumber < 17)) {
      if(levelNumber <= lastLevelWon) {
        levelNumber = levelNumber + 1;
        WYFLevelNumber = levelNumber - 10;
        gb.sound.playTick();
      } else {
        gb.sound.fx(kickOnly);
      }
    } else if(gb.buttons.pressed(BUTTON_LEFT)) {
      if(levelNumber > 11) {
        levelNumber = levelNumber - 1;
        WYFLevelNumber = levelNumber - 10;
        gb.sound.playTick();
      } else if(levelNumber == 11) {
        levelNumber = levelNumber - 1;
        WYFLevelNumber = 0;
        gamestate = 5;
        gb.sound.playTick();
      }
    }
  }

// Input to valid the selected level.
  if((gb.buttons.pressed(BUTTON_A)) && (clap == false)) {
    gb.sound.stop(track);
    MittsiesTrack = 0;
    resetLevel = true;
    clap = true;
    WYFLevelNumber = levelNumber - 10;
  }


// We draw the clap and go to a level.
  if(clap == true){
     drawHeavenClap();
  }
}

/*
void wip() {
  gb.display.setFont(font5x7);
  gb.display.setFontSize(1);
  gb.display.setColor(PINK);
  gb.display.setCursor(2, 4);
//  gb.display.print("     WORK IN PROGRESS");
  gb.display.print(WYFLevelNumber);
  gb.display.print("  ");
  gb.display.print(levelNumber);
}
*/

void loop() {
  while(!gb.update());

  gb.display.clear();

  gb.lights.clear();

  switch (gamestate) {
// Logo Badger intro
    case 0:
      intro();
      break;
      
// Hell levels
    case 1:
      HellLevels();
      break;

// Hell dialogues
    case 2:
      HellDialogues();
      break;

// BAD END
    case 3:
      drawBadEnd();
      break;

// credits
    case 4:
      drawEnd();
      break;

// level selection screen
    case 5:
      chapterSelect();
      break;

// Cutscene between hell and heaven..
    case 6:
      ItWasAnAccident();
      break;
      
// Heaven dialogues
    case 7:
      HeavenDialogues();
      break;

// Sins certificates
/*
    case 8:
      certificates();
      break;
*/

// back to Hell (true end after Heaven)
    case 9:
      backToHell();
      break;

// Michael Jackson is BAD
    case 10:
      BAD();
      break;

// Heaven levels
    case 11:
      HeavenLevels();
      break;

// Heaven level selection screen
    case 12:
      HeavenChapterSelect();
      break;

// bonus song Acrylique et Pixels
// Vanessa Paradis parody song
    case 13:
      AcryliqueEtPixels();
      break;
  }

/*
  updateFPS();
  gb.display.setFontSize(1);
  gb.display.setColor(LIGHTGREEN);
  gb.display.setFont(font5x7);
  gb.display.print(2, 2, fps);
*/

/*
  gb.display.setFontSize(1);
  gb.display.setColor(LIGHTGREEN);
  gb.display.setFont(font5x7);
  gb.display.print(2, 2, lastLevelWon);
*/
}

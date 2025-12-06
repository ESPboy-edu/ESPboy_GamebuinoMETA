// ###########################################################################
//         
//
//         Title : MetaPatrol.ino
//         Author: Jean-Baptiste Chaffange Koch
//    Description: A moonpatrol-like game for Gamebuino Meta.
//        Version: 0bis
//           Date: 14 Sep 2018
//        License: GPLv3 (see LICENSE)
//
//    MetaPatrol Copyright (C) 2018 Jean-Baptiste Chaffange Koch
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    any later version.
//    
//    It's a modification of CosmicPods for Arduboy created by cubic9com 
//    <https://twitter.com/cubic9com>
//    <https://github.com/ArduboyCollection/CosmicPods<
//    Thanks to him !
//
//    
//###########################################################################


// ###########################################################################
//    VARIABLES
// ###########################################################################

#include <Gamebuino-Meta.h>

#define X_MAX 64
#define Y_MAX 80

#define NUM_PLAYER_BULLETS 4
#define MAX_NUM_ENEMIES 4
#define MAX_NUM_OBSTACLES 2
#define NUM_STARS 16

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

#define OBSTACLE_RECT {0, 0, 12, 12}
#define ENEMY_RECT {0, 0, 12, 12}
#define PLAYER_RECT {0, 1, 12, 10}

int STAR_COLORS [] = {1, 6, 7, 12, 13};
int GROUND_COLORS [] = {0, 6, 5, 15};

struct Rect {
  int x;      
  int y;      
  int w;      
  int h;      
};

struct Point {
  int x;      
  int y;      
};

struct Speed {
  int dx;      
  int dy; 
};

struct Vector2 {
  float x;
  float y;
};

struct FloatPoint {
  float x;
  float y;
};

struct PlayerBullet {
  Point point;
  Speed spd;
  boolean enabled;
};

struct Player {
  Rect rect;
  byte power;
  PlayerBullet bullets[NUM_PLAYER_BULLETS];
};

struct EnemyBullet {
  FloatPoint point;
  Vector2 delta;
  boolean enabled;
};

struct Enemy {
  Rect rect;
  EnemyBullet bullet;
  Speed spd;
  byte type;
};

struct Obstacle {
  Rect rect;
  byte type;
  byte state;
};

struct Star {
  Point point;
  byte spd;
  byte color;
};

struct Ground {
  Point point;
  byte spd;
  byte color;
};

struct Camera {
  Speed spd;
};

struct Player player;
struct Star stars[NUM_STARS];
struct Ground grounds[NUM_STARS];
struct Enemy enemies[MAX_NUM_ENEMIES];
struct Obstacle obstacles[MAX_NUM_OBSTACLES];

boolean benchmark = true;
boolean is_gameover;
boolean is_title;
unsigned int score;
unsigned int best_score;
boolean is_highscore;
byte num_enemies;
byte num_obstacles;
byte bullet_speed_factor;
byte level;
byte WIDTH;
byte HEIGHT;
byte ymin = 36;
struct Camera camera;
const int XMap[80] = {1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3};
const int YMap[50] = {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0};


// FIN DES VARIABLES #########################################################
// ###########################################################################



// ###########################################################################
//    BMP & SOUNDS
// ###########################################################################

const PROGMEM uint8_t img_tankData[] = {
16,10,
2,0,12,
11,
1,

0x00,0x00,0x00,0x00,0x00,0x0B,0xBB,0xBB,
0x00,0x80,0x80,0x80,0x07,0xD0,0x00,0x00,
0x00,0x80,0x88,0x80,0x70,0x7D,0x0A,0xA0,
0xBB,0x00,0x08,0x07,0x70,0x77,0x00,0x00,
0xBB,0xB0,0x00,0x00,0x00,0x00,0x0B,0xBB,
0xB0,0x00,0x00,0x07,0x70,0x00,0x00,0x0B,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x70,0x07,0x77,0x77,0x70,0x07,0x00,
0xB0,0x60,0x60,0x60,0x60,0x60,0x60,0x0B,
0xBB,0x06,0x06,0x06,0x06,0x06,0x00,0xBB,
0xBB,0xBB,0xBB,0xBB,0xBB,0xBB,0xBB,0xBB,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x80,0x80,0x80,0x07,0xD0,0x0A,0xA0,
0x00,0x80,0x88,0x80,0x70,0x7D,0x00,0x00,
0xBB,0x00,0x08,0x07,0x70,0x77,0x0B,0xBB,
0xB0,0x00,0x00,0x00,0x00,0x00,0x00,0x0B,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x70,0x07,0x77,0x77,0x70,0x07,0x00,
0xB0,0x06,0x06,0x06,0x06,0x06,0x06,0x0B,
0xBB,0x00,0x60,0x60,0x60,0x60,0x60,0xBB
};
Image img_tank(img_tankData);

const PROGMEM uint8_t img_ennemy1Data[] = {
16,10,
2,0,12,
0xFF,
1,

0x00,0x00,0x01,0x11,0x11,0x10,0x00,0x00,
0x00,0x00,0x11,0xDD,0xCC,0x11,0x00,0x00,
0x00,0x00,0x11,0x1D,0xD7,0xC1,0x00,0x00,
0x00,0x01,0x11,0x11,0xDD,0xC1,0x10,0x00,
0x00,0x01,0x1C,0x11,0x1D,0xD1,0x10,0x00,
0x03,0xA0,0x11,0x11,0x11,0x11,0x0A,0x30,
0x03,0x33,0x00,0x00,0x00,0x00,0x33,0x30,
0x03,0x77,0x77,0x77,0x77,0x77,0x77,0x30,
0x05,0x55,0x55,0x3B,0x3B,0x55,0x55,0x50,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x01,0x11,0x11,0x10,0x00,0x00,
0x00,0x00,0x11,0xDD,0xCC,0x11,0x00,0x00,
0x00,0x00,0x11,0x1D,0xD7,0xC1,0x00,0x00,
0x00,0x01,0x11,0x11,0xDD,0xC1,0x10,0x00,
0x00,0x01,0x1C,0x11,0x1D,0xD1,0x10,0x00,
0x03,0xA0,0x11,0x11,0x11,0x11,0x0A,0x30,
0x03,0x33,0x00,0x00,0x00,0x00,0x33,0x30,
0x03,0x77,0x77,0x77,0x77,0x77,0x77,0x30,
0x05,0x55,0x55,0xB3,0xB3,0x55,0x55,0x50,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
Image img_ennemy1(img_ennemy1Data);

const PROGMEM uint8_t img_ennemy2Data[] = {
16,10,
2,0,12,
0xFF,
1,

0x00,0x00,0x01,0x11,0x11,0x10,0x00,0x00,
0x00,0x00,0x11,0xDD,0xCC,0x11,0x00,0x00,
0x00,0x00,0x11,0x1D,0xD7,0xC1,0x00,0x00,
0x00,0x01,0x11,0x11,0xDD,0xC1,0x10,0x00,
0x00,0x01,0x1C,0x11,0x1D,0xD1,0x10,0x00,
0x08,0xA0,0x11,0x11,0x11,0x11,0x0A,0x80,
0x08,0x88,0x00,0x00,0x00,0x00,0x88,0x80,
0x08,0x77,0x77,0x77,0x77,0x77,0x77,0x80,
0x05,0x55,0x55,0x3B,0x3B,0x55,0x55,0x50,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x01,0x11,0x11,0x10,0x00,0x00,
0x00,0x00,0x11,0xDD,0xCC,0x11,0x00,0x00,
0x00,0x00,0x11,0x1D,0xD7,0xC1,0x00,0x00,
0x00,0x01,0x11,0x11,0xDD,0xC1,0x10,0x00,
0x00,0x01,0x1C,0x11,0x1D,0xD1,0x10,0x00,
0x08,0xA0,0x11,0x11,0x11,0x11,0x0A,0x80,
0x08,0x88,0x00,0x00,0x00,0x00,0x88,0x80,
0x08,0x77,0x77,0x77,0x77,0x77,0x77,0x80,
0x05,0x55,0x55,0xB3,0xB3,0x55,0x55,0x50,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
Image img_ennemy2(img_ennemy2Data);

const PROGMEM uint8_t img_bonusData[] = {
12,12,
2,0,12,
14,
1,

0x00,0x00,0x00,0x00,0x00,0x00,
0x03,0xB3,0xB3,0x3B,0x3B,0x30,
0xE0,0x00,0x00,0x00,0x00,0x0E,
0xE0,0x3B,0x3A,0xB3,0xB3,0x0E,
0xE0,0x3B,0x3B,0xA3,0xB3,0x0E,
0xE0,0x3B,0x37,0xA3,0xB3,0x0E,
0xE0,0x3B,0x3A,0x73,0xB3,0x0E,
0xE0,0x3B,0x3A,0xB3,0xB3,0x0E,
0xE0,0x3B,0x3B,0xA3,0xB3,0x0E,
0xE0,0x00,0x00,0x00,0x00,0x0E,
0x03,0xB3,0xB3,0x3B,0x3B,0x30,
0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,
0x03,0xB3,0xB3,0x3B,0x3B,0x30,
0xE0,0x00,0x00,0x00,0x00,0x0E,
0xE0,0x3B,0x3B,0xA3,0xB3,0x0E,
0xE0,0x3B,0x3A,0xB3,0xB3,0x0E,
0xE0,0x3B,0x3A,0x73,0xB3,0x0E,
0xE0,0x3B,0x37,0xA3,0xB3,0x0E,
0xE0,0x3B,0x3B,0xA3,0xB3,0x0E,
0xE0,0x3B,0x3A,0xB3,0xB3,0x0E,
0xE0,0x00,0x00,0x00,0x00,0x0E,
0x03,0xB3,0xB3,0x3B,0x3B,0x30,
0x00,0x00,0x00,0x00,0x00,0x00
};
Image img_bonus(img_bonusData);

const PROGMEM uint8_t img_rockData[] = {
12,12,
1,0,0,
14,
1,

0xE5,0x55,0x55,0x55,0x55,0x5E,
0x57,0x67,0x77,0x66,0x5B,0x65,
0x56,0x77,0x66,0x6B,0xB3,0x35,
0x57,0x66,0x63,0xB5,0x63,0x55,
0x56,0x77,0x76,0xBB,0x66,0x55,
0x56,0x76,0x66,0x36,0x66,0x55,
0x57,0x66,0x66,0xB6,0x66,0x55,
0x56,0x66,0x63,0x65,0x66,0x55,
0x56,0x66,0x65,0x66,0x66,0x65,
0x56,0x53,0x66,0x63,0x66,0x55,
0x55,0x33,0x36,0x55,0x35,0x55,
0xE5,0x55,0x55,0x55,0x55,0x5E
};
Image img_rock(img_rockData);

const Gamebuino_Meta::Sound_FX sfx_shoot[] = {
  {Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,255,-15,25,24,8},
};

const Gamebuino_Meta::Sound_FX sfx_explosion[] = {
  {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,180,25,35,100,2},
  {Gamebuino_Meta::Sound_FX_Wave::NOISE,1,200,0,19,112,9},
  {Gamebuino_Meta::Sound_FX_Wave::NOISE,0,90,0,20,0,16},
};

const Gamebuino_Meta::Sound_FX sfx_blop[] = {
  {Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,255,30,30,100,13},
};

// FIN DES BMP & SOUNDS ######################################################
// ###########################################################################


// ###########################################################################
//    SETUP
// ###########################################################################
void setup() {
    gb.begin();

    best_score = gb.save.get(0);

    WIDTH = gb.display.width();
    HEIGHT = gb.display.height();

    for (byte i = 0; i < MAX_NUM_ENEMIES; i++) {
      enemies[i].rect = ENEMY_RECT;
    }

    for (byte i = 0; i < MAX_NUM_OBSTACLES; i++) {
      obstacles[i].rect = OBSTACLE_RECT;
      obstacles[i].state = 0;
    }
  
    player.rect = PLAYER_RECT;
  
    beginGame();
}
// FIN DU BEGIN ##############################################################
// ###########################################################################



// ###########################################################################
//    LOOP
// ###########################################################################
void loop() {
    
    while(!gb.update());
    
    gb.display.clear();
    gb.lights.clear();

     if (is_title) {
      displayTitle();
      if (gb.buttons.pressed(BUTTON_A) || gb.buttons.pressed(BUTTON_B)) {
        benchmark = false;
        if (gb.buttons.pressed(BUTTON_B)) {/*benchmark = true;*/}
        beginGame();
        is_title = false;
      }
       return;
     }
  
    if (is_gameover) {
       displayGameover();
       if (gb.buttons.pressed(BUTTON_A) || gb.buttons.pressed(BUTTON_B)) {
       beginGame();
       }
      return;
    }

    movePlayer();
    moveStars();
    moveGrounds();
    moveEnemies();
    moveObstacles();
    movePlayerBullets();
    moveEnemiesBullet();
    
    drawStars();
    drawScene();

    drawObstacles();
    
    drawPlayer();
    drawPlayerBullets();
    drawEnemies();
    drawEnemiesBullet();
    
    
    drawScore();

    checkEnemyCollision();
    checkObstaclesCollision();
    checkPlayerCollision();
  
}

// FIN DU LOOP ###############################################################
// ###########################################################################



// ###########################################################################
//    FONCTIONS
// ###########################################################################

void beginGame() {
  
  score = 0;

  player.rect.x = 0;
  player.rect.y =  ymin - player.rect.h;
  player.power = 50;

  for (byte i = 0; i < NUM_STARS; i++) {
    spawnStar(i);
    spawnGround(i);
  }

  for (byte i = 0; i < MAX_NUM_ENEMIES; i++) {
    spawnEnemy(i);
  }

  for (byte i = 0; i < MAX_NUM_OBSTACLES; i++) {
    spawnObstacles(i);
  }

  for (byte i = 0; i < NUM_PLAYER_BULLETS; i++) {
    player.bullets[i].enabled = false;
    player.bullets[i].point.x = 0;
    player.bullets[i].point.y = 0;
    player.bullets[i].spd.dx = 0;
    player.bullets[i].spd.dy = 0;
  }

  for (byte i = 0; i < MAX_NUM_ENEMIES; i++) {
    enemies[i].bullet.enabled = false;
    enemies[i].bullet.point.x = 0;
    enemies[i].bullet.point.y = 0;
  }

  is_gameover = false;
  is_title = true;
  is_highscore = false;

  shiftLevel();
}



void shiftLevel() {
  switch (score) {
    case 0:
      setLevel(1, 1, 1, 1.4);
      break;
    case 1:
      setLevel(2, 1, 1, 1.4);
      break;
    case 3:
      setLevel(3, 2, 1, 1.4);
      break;
    case 7:
      setLevel(4, 2, 1, 1.5);
      break;
    case 16:
      setLevel(5, 2, 2,  1.6);
      break;
    case 25:
      setLevel(6, 2, 2,  1.8);
      break;
    case 37:
      setLevel(7, 2, 2,  2.0);
      break;
    case 49:
      setLevel(8, 2, 2,  2.3);
      break;
    case 64:
      setLevel(9, 2, 2,  2.4);
      break;
    case 79:
      setLevel(10, 2, 2,  2.6);
      break;
    case 97:
      setLevel(11, 3, 2,  2.8);
      break;
    case 115:
      setLevel(12, 3, 2,  3.1);
      break;
    case 136:
      setLevel(13, 3, 2,  3.4);
      break;
    case 157:
      setLevel(14, MAX_NUM_ENEMIES, MAX_NUM_OBSTACLES,  3.7);
      break;
    case 181:
      setLevel(15, MAX_NUM_ENEMIES, MAX_NUM_OBSTACLES,  4.1);
      break;
    default:
      break;
  }
}


void setLevel(byte lv, byte ne, byte no, float spd) {
  level = lv;
  num_enemies = ne;
  num_obstacles = no;
  bullet_speed_factor = spd;
}

void spawnEnemy(byte i) {
  enemies[i].rect.y = -10 ;
  enemies[i].type = random(1,3);
  switch (enemies[i].type) {
    case 1:
      enemies[i].rect.x = random(12,68) ;
      enemies[i].spd.dx = -random(1,3);
      break;
    case 2:
      enemies[i].rect.x = random(12,68) ;
      enemies[i].spd.dx = -random(2,4);
      break;
  }
  enemies[i].spd.dy = 1;
}

void spawnObstacles(byte i) {
  obstacles[i].state = 1; //O : inactive , 1 : active
  obstacles[i].rect.x = WIDTH;
  obstacles[i].type = random(1,4);
  switch (obstacles[i].type ) {
    case 1:   //HOLE
      obstacles[i].rect.y = ymin + player.rect.h - 1 ;
      break;
    case 2:   //ROCK
      obstacles[i].rect.y = ymin-(obstacles[i].rect.h-player.rect.h)+1;
      break;   
    case 3:   //BONUS
      obstacles[i].rect.y = ymin-(obstacles[i].rect.h-player.rect.h)+1;
      break;
   }
}

void spawnStar(byte i) {
  stars[i].point.x = random(WIDTH, WIDTH * 2);
  stars[i].point.y = random(0, HEIGHT);
  stars[i].spd = random(1, 5);
  stars[i].color = STAR_COLORS[random(0,5)];
}

void spawnGround(byte i) {
  grounds[i].point.x = random(WIDTH, WIDTH * 2);
  grounds[i].point.y = random(ymin + player.rect.h, HEIGHT);
  grounds[i].spd = camera.spd.dx;
  grounds[i].color = GROUND_COLORS[random(0,4)];
}

void spawnPlayerBullet(byte i, byte dir) {
  player.bullets[i].enabled = true;
  switch (dir) {
    case 0: //Vertical
      player.bullets[i].point.x = player.rect.x+3;
      player.bullets[i].point.y = player.rect.y+3;
      player.bullets[i].spd.dx = 0;
      player.bullets[i].spd.dy = 2;
      break;
    case 1: //Horizontal
      player.bullets[i].point.x = player.rect.x+9;
      player.bullets[i].point.y = player.rect.y+2;
      player.bullets[i].spd.dx = 2;
      player.bullets[i].spd.dy = 0;
      break;
    }
}

void spawnEnemyBullet(byte i) {
  enemies[i].bullet.enabled = true;
  enemies[i].bullet.point.x = enemies[i].rect.x+5;
  enemies[i].bullet.point.y = enemies[i].rect.y+5;

  Vector2 orig_delta;
  orig_delta.x = player.rect.x - enemies[i].rect.x;
  orig_delta.y = player.rect.y - enemies[i].rect.y;

  Vector2 new_delta = calcDelta(orig_delta);

  enemies[i].bullet.delta.x = new_delta.x;
  enemies[i].bullet.delta.y = new_delta.y;
}

Vector2 calcDelta(Vector2 v) {
  float mag = bullet_speed_factor / sqrt(v.x * v.x + v.y * v.y);

  Vector2 v2;
  v2.x = v.x * mag;
  v2.y = v.y * mag;

  return v2;
}

void movePlayer() {

  //player.power = min(player.power + 1 , 25);
  
  if (gb.buttons.repeat(BUTTON_RIGHT,1) && (player.rect.x < 70)) {
    player.rect.x++;
  }

  if (gb.buttons.repeat(BUTTON_LEFT,1) && (player.rect.x > 0)) {
    player.rect.x--;
  }

  if (gb.buttons.repeat(BUTTON_UP,1) && (player.rect.y > 0) && player.power > 0) {
    player.rect.y--;
    player.power = max(player.power - 1 , 0);
  } else {player.rect.y = min(ymin, player.rect.y + 1) ;}

  if (gb.buttons.repeat(BUTTON_DOWN,1) && (player.rect.y < ymin)) {
    player.rect.y++;
  }

  if (gb.buttons.repeat(BUTTON_B,12)) {
    for (byte i = 0; i < NUM_PLAYER_BULLETS; i++) {
      if (!player.bullets[i].enabled) {
        spawnPlayerBullet(i,0);
        gb.sound.fx(sfx_shoot);
        break;
      }
     }
  }

  if (gb.buttons.repeat(BUTTON_A,24)) {
    for (byte i = 0; i < NUM_PLAYER_BULLETS; i++) {
      if (!player.bullets[i].enabled) {
        spawnPlayerBullet(i,1);
        player.power = max(player.power - 5, 0);
        gb.sound.fx(sfx_explosion);
        break;
      }
     }
  }

   setupCamera(player.rect.x, player.rect.y);
    
}

void moveStars() {
  for (byte i = 0; i < NUM_STARS; i++) {
    stars[i].point.x -= stars[i].spd;
    if (stars[i].point.x < 0) {
      spawnStar(i);
    }
  }
}

void moveGrounds() {
  for (byte i = 0; i < NUM_STARS; i++) {
    grounds[i].point.x -= camera.spd.dx;
    if (grounds[i].point.x < 0) {
      spawnGround(i);
    }
  }
}

void moveEnemies() {
  for (byte i = 0; i < num_enemies; i++) {
    
    enemies[i].rect.x =  enemies[i].rect.x - enemies[i].spd.dx;
    enemies[i].rect.y =  enemies[i].rect.y + enemies[i].spd.dy;

    if (
      (level > 2)
      && (enemies[i].rect.x > player.rect.x + 10)
      && (enemies[i].rect.x < WIDTH - 10)
      && (!enemies[i].bullet.enabled)
      && (random(0, 50) == 10)
    ) {
      spawnEnemyBullet(i);
      gb.sound.fx(sfx_blop);
    }

    if (enemies[i].rect.x < 1 || enemies[i].rect.x >= (WIDTH - enemies[i].rect.w)) {
      enemies[i].spd.dx = -enemies[i].spd.dx;
    }

    if (enemies[i].rect.y >= 8 ) {
      enemies[i].spd.dy = 0;
    }
  }
}

void moveObstacles() {
  for (byte i = 0; i < num_obstacles; i++) {
    obstacles[i].rect.x = obstacles[i].rect.x - camera.spd.dx;
    if (obstacles[i].rect.x < (0 - obstacles[i].rect.w)) {
      spawnObstacles(i);
    }
  }
}

void movePlayerBullets() {
  for (byte i = 0; i < NUM_PLAYER_BULLETS; i++) {
    if (player.bullets[i].enabled) {
      player.bullets[i].point.x += player.bullets[i].spd.dx;
      player.bullets[i].point.y -= player.bullets[i].spd.dy;
      if (player.bullets[i].point.x > WIDTH || player.bullets[i].point.y < 0) {
        player.bullets[i].enabled = false;
      }
    }
  }
}

void moveEnemiesBullet() {
  for (byte i = 0; i < num_enemies; i++) {
    if (enemies[i].bullet.enabled) {
      enemies[i].bullet.point.x += enemies[i].bullet.delta.x;
      enemies[i].bullet.point.y += enemies[i].bullet.delta.y;
      if (
        (enemies[i].bullet.point.x <= 0)
        || (enemies[i].bullet.point.y <= 0)
        || (enemies[i].bullet.point.y >= HEIGHT)
      ) {
        enemies[i].bullet.enabled = false;
      }
    }
  }
}

boolean collidePointRect(Point test_point, Rect test_rect){
  if ( (test_point.x < test_rect.x) || (test_point.x > (test_rect.x + test_rect.w - 1)) || (test_point.y < test_rect.y) || (test_point.y > (test_rect.y + test_rect.h -1)) ) {
    return false;
  } else {
    return true;
  }
}

boolean collideRectRect(Rect test_rect_A, Rect test_rect_B){
     if((test_rect_B.x >= test_rect_A.x + test_rect_A.w)
        || (test_rect_B.x + test_rect_B.w <= test_rect_A.x) 
        || (test_rect_B.y >= test_rect_A.y + test_rect_A.h)
        || (test_rect_B.y + test_rect_B.h <= test_rect_A.y)) {
          return false; 
        } else {
          return true; 
        }
}

void checkEnemyCollision() {
  for (byte j = 0; j < num_enemies; j++) {
    boolean is_col = false;
    for (byte i = 0; i < NUM_PLAYER_BULLETS; i++) {
      if (player.bullets[i].enabled) {
        is_col = collidePointRect(player.bullets[i].point, enemies[j].rect);
        if (is_col) {
          player.bullets[i].enabled = false;
          drawExplosion(player.bullets[i].point.x,player.bullets[i].point.y);
          break;
        }
      }
    }
    if (is_col) {
      player.power = min(player.power + 2, 50);
      score++;
      shiftLevel();
      spawnEnemy(j);
    }
  }
}

void checkObstaclesCollision() {
    for (byte j = 0; j < num_obstacles; j++) {
    if (obstacles[j].state == 0) { continue;}
    boolean is_col = false;
    for (byte i = 0; i < NUM_PLAYER_BULLETS; i++) {
      if (player.bullets[i].enabled) {
        is_col = collidePointRect(player.bullets[i].point, obstacles[j].rect);
        if (is_col) {
          drawExplosion(player.bullets[i].point.x,player.bullets[i].point.y);
          player.bullets[i].enabled = false;
          break;
        }
      }
    }
    if (is_col) {
      player.power = min(player.power + 2, 50);
      score++;
      shiftLevel();
      obstacles[j].state = 0;
    }
  }
}

void checkPlayerCollision() {
  for (byte i = 0; i < num_enemies; i++) {
    Point tmp_point;
    tmp_point.x = enemies[i].bullet.point.x;
    tmp_point.y = enemies[i].bullet.point.y;
    boolean is_enemy_col = collideRectRect(enemies[i].rect, player.rect);
    boolean is_bullet_col = (enemies[i].bullet.enabled) && (collidePointRect(tmp_point, player.rect));
    if ((is_enemy_col) || (is_bullet_col)) {
      drawExplosion(enemies[i].rect.x,enemies[i].rect.y);
      if (score > best_score) { 
        gb.save.set(0, score);
        best_score = score;
        is_highscore = true;
        } else {
          is_highscore = false;
        }
      displayGameover();
      return;
    }
  }
  for (byte i = 0; i < num_obstacles; i++) {
    if (obstacles[i].state == 0) { continue;}
    boolean is_obstacle_col = collideRectRect(obstacles[i].rect, player.rect);
    if (is_obstacle_col) {
      if (obstacles[i].type == 3) { //BONUS
        player.power = min(player.power + 25, 50);
        score++;
        shiftLevel();
        obstacles[i].state = 0;      
        continue;
      }
      if (obstacles[i].type == 2) { //ROCK
        if (player.rect.x > (obstacles[i].rect.x + 5)) {
          player.rect.x = min(obstacles[i].rect.x + player.rect.w, player.rect.x + 1 + camera.spd.dx);
        } else { player.rect.x = max(obstacles[i].rect.x - player.rect.w, player.rect.x - 2 - camera.spd.dx);}
        if ( player.rect.x < 0 ) {
          drawExplosion(obstacles[i].rect.x,obstacles[i].rect.y);
          goto gameover;} //player blocked 
        continue;
      }
      gameover:
      if (score > best_score) {     //HOLE
        gb.save.set(0, score);
        best_score = score;
        is_highscore = true;
        } else {
          is_highscore = false;
        }
      displayGameover();
      return;
    }
  }


  
}

void displayGameover() {
  for (byte i = 0; i <= 3; i++) {
    gb.lights.drawPixel(0, i, RED);
    gb.lights.drawPixel(1, i, RED);
  }
  drawScore();
  gb.display.setColor(WHITE);
  gb.display.setCursor(20,20);
  gb.display.print("GAME OVER");
  if (is_highscore) {
     gb.display.setColor(RED);
     gb.display.setCursor(12,30);
     gb.display.print("NEW HIGH SCORE");
  }
  is_gameover = true;
}

void displayTitle() {
  gb.display.setColor(WHITE);
  gb.display.setCursor(20,20);
  gb.display.println("Meta Patrol");
  gb.display.println("                  ");
  gb.display.print("   Highscore : ");
  gb.display.println(best_score);
}

void drawScore() {
 gb.display.setColor(BLACK);
 gb.display.fillRect(0,56,80,64); 
 gb.display.setColor(GRAY);
 gb.display.setCursor(1, HEIGHT - 6);
 gb.display.print("SCORE:");
 gb.display.setCursor(30, HEIGHT - 6);
 gb.display.print(score);
 gb.display.setColor(YELLOW);
 gb.display.fillRect(54,58,player.power/2,5);
 gb.display.setColor(BLACK);
 gb.display.setCursor(55, HEIGHT - 6);
 gb.display.print("POW");
 //BENCH
 if (benchmark) {
 gb.display.setColor(WHITE);
 gb.display.setCursor(1, 1);
 int load = gb.getCpuLoad();
 gb.display.print("CPU:");
 gb.display.print(load);
 gb.display.println("%");
 }
}

void drawPlayer() {
  int x = player.rect.x;
  int y = player.rect.y;
  int w = player.rect.w;
  int h = player.rect.h;
  gb.display.drawImage(x-2,y,img_tank);
  gb.display.setColor(BLACK); 
  gb.display.drawFastHLine(x+1,y+h,w-2);
  if (benchmark) {
    gb.display.setColor(RED);
    gb.display.drawRect(x, y, w, h); 
  }
}

void drawStars() {
  for (byte i = 0; i < NUM_STARS; i++) {
    int x = stars[i].point.x;
    int y = stars[i].point.y;
    gb.display.setColor(stars[i].color);
    gb.display.drawPixel(x, y);
  }
}

void drawEnemies() {
  for (byte i = 0; i < num_enemies; i++) {
    int x = enemies[i].rect.x;
    int y = enemies[i].rect.y;
    int w = enemies[i].rect.w;
    int h = enemies[i].rect.h;
    switch (enemies[i].type) {
      case 1:
        gb.display.drawImage(x-2,y+2,img_ennemy2);  
        if (benchmark) {
          gb.display.setColor(RED);
          gb.display.drawRect(x, y, w, h);
        }
        break;
      case 2:
        gb.display.drawImage(x-2,y+2,img_ennemy1);  
        if (benchmark) {
          gb.display.setColor(BLUE);
          gb.display.drawRect(x, y, w, h);
        }
        break;
    }
  }
}

void drawObstacles() {
  for (byte i = 0; i < num_obstacles; i++) {
    if (obstacles[i].state == 0) { continue;}
    int x = obstacles[i].rect.x;
    int y = obstacles[i].rect.y;
    int w = obstacles[i].rect.w;
    int h = obstacles[i].rect.h;
    switch (obstacles[i].type) {
      case 1: //HOLE
        y = y + 1;  //not very smart, but fast !
        gb.display.setColor(DARKGRAY);
        gb.display.drawFastVLine(x,y,3);
        gb.display.setColor(BLACK);
        gb.display.drawFastVLine(x+1,y,5);
        gb.display.drawFastVLine(x+2,y,7);
        gb.display.drawFastVLine(x+3,y,9);
        gb.display.drawFastVLine(x+4,y,9);
        gb.display.drawFastVLine(x+5,y,9);
        gb.display.drawFastVLine(x+6,y,9);
        gb.display.drawFastVLine(x+7,y,9);
        gb.display.drawFastVLine(x+8,y,9);
        gb.display.drawFastVLine(x+9,y,7);
        gb.display.drawFastVLine(x+10,y,5);
        gb.display.setColor(DARKGRAY);
        gb.display.drawFastVLine(x+11,y,3);
        if (benchmark) {
           gb.display.setColor(BLACK);
           gb.display.fillRect(x, y, w, h);
        }
        break;
      case 2: //ROCK
        gb.display.drawImage(x,y,img_rock);
        if (benchmark) {
           gb.display.setColor(PINK);
           gb.display.drawRect(x, y, w, h);
        }
        break;
      case 3: //BONUS
        gb.display.drawImage(x,y,img_bonus);
        if (benchmark) {
           gb.display.setColor(PINK);
           gb.display.drawRect(x, y, w, h);
        }
        break;
    }
  }
}

void drawPlayerBullets() {
  for (byte i = 0; i < NUM_PLAYER_BULLETS; i++) {
    if (player.bullets[i].enabled && player.bullets[i].spd.dx >= 1) {
      int x = player.bullets[i].point.x;
      int y = player.bullets[i].point.y;
      gb.display.setColor(RED);
      gb.display.drawCircle(x-3, y, 1);
      gb.display.setColor(ORANGE);
      gb.display.drawCircle(x-2, y, 1);
      gb.display.setColor(YELLOW);
      gb.display.fillCircle(x-1, y, 1);
      gb.display.drawPixel(x, y, WHITE);
    }
    if (player.bullets[i].enabled && player.bullets[i].spd.dy >= 1) {
      int x = player.bullets[i].point.x;
      int y = player.bullets[i].point.y;
      gb.display.setColor(BLUE);
      gb.display.drawCircle(x, y+1, 1);
      gb.display.setColor(LIGHTBLUE);
      gb.display.fillCircle(x, y, 1);
      gb.display.drawPixel(x, y, WHITE);
    }
  }
}

void drawEnemiesBullet() {
  for (byte i = 0; i < num_enemies; i++) {
    if (enemies[i].bullet.enabled) {
      int x = enemies[i].bullet.point.x;
      int y = enemies[i].bullet.point.y;
      gb.display.setColor(PINK);
      gb.display.fillCircle(x, y, 1);
      gb.display.drawPixel(x, y, WHITE);
     }
  }
}

void drawScene() {
  //sky
  gb.display.setColor(WHITE);
  gb.display.drawFastHLine(0,player.rect.h+ymin-4+(camera.spd.dy),WIDTH);
  gb.display.setColor(LIGHTBLUE);
  gb.display.drawFastHLine(0,player.rect.h+ymin-3+(camera.spd.dy),WIDTH);
  gb.display.setColor(BLUE);
  gb.display.drawFastHLine(0,player.rect.h+ymin-2+(camera.spd.dy),WIDTH);
  gb.display.setColor(DARKBLUE);
  gb.display.drawFastHLine(0,player.rect.h+ymin-1+(camera.spd.dy),WIDTH);
  gb.display.setColor(DARKGRAY);
  gb.display.drawFastHLine(0,player.rect.h+ymin+(camera.spd.dy),WIDTH);
  //mountain back
  //gb.display.drawImage(0,25+camera.spd.dy*1.3,img_back_1a);
  //mountain front
  //gb.display.drawImage(0,25+camera.spd.dy,img_back_2a);
  //plants

  //ground
  gb.display.setColor(BROWN);
  gb.display.fillRect(0,ymin + player.rect.h,WIDTH,10);
  for (byte i = 0; i < NUM_STARS; i++) {
    int x = grounds[i].point.x;
    int y = grounds[i].point.y;
    gb.display.setColor(grounds[i].color);
    gb.display.drawPixel(x, y);
  }
  gb.display.setColor(DARKGRAY);
  gb.display.drawFastHLine(0,ymin + player.rect.h,WIDTH);

}

void setupCamera(byte x, byte y) {    //  coord of the object
  camera.spd.dx = XMap[x];
  camera.spd.dy = YMap[y];
}

void drawExplosion(byte x, byte y) {
      gb.display.setColor(random(8,11));
      gb.display.fillCircle(x + 3, y + 6, 7);
      gb.display.setColor(random(8,11));
      gb.display.fillCircle(x + 7,y + 2, 4);
      gb.lights.drawPixel(0, 1, RED);
      gb.lights.drawPixel(1, 1, RED);
      gb.lights.drawPixel(0, 2, ORANGE);
      gb.lights.drawPixel(1, 2, ORANGE);
      gb.lights.drawPixel(0, 3, YELLOW);
      gb.lights.drawPixel(1, 3, YELLOW);
      gb.sound.fx(sfx_explosion);
}
// FIN DES FONCTIONS##########################################################
// ###########################################################################

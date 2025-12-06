/*
 * Player.cpp
 *
 *  Created on: 30.07.2025
 *      Author: Agandi
 */

#include "Player.h"

Player::Player() 
{
  colorCircle = BLUE;
  direction = E;
  setIsDestroyed(false);
  setPosMapX(8.0);
  setPosMapY(8.0);
  image[N] = Image(IMG_PLAYER_N);
  image[NE] = Image(IMG_PLAYER_NE);
  image[E] = Image(IMG_PLAYER_E);
  image[SE] = Image(IMG_PLAYER_SE);
  image[S] = Image(IMG_PLAYER_N);
  image[SW] = Image(IMG_PLAYER_NE);
  image[W] = Image(IMG_PLAYER_E);
  image[NW] = Image(IMG_PLAYER_SE);
}

Player::~Player() 
{
	
}

void Player::update()
{
  setLastPosMapX((int)round(getPosMapX()));
  setLastPosMapY((int)round(getPosMapY()));

  //Movement
  if(!gb.buttons.repeat(BUTTON_A, 0))
  {
   if(gb.buttons.repeat(BUTTON_UP, velocity) && gb.buttons.repeat(BUTTON_RIGHT, velocity))
	  {
      if(direction == NE)
      {
        incDecPosMap(incDecValDiagonal, -incDecValDiagonal);
      }
      else
      {
        direction = NE;
      }
	  }

    if(gb.buttons.repeat(BUTTON_DOWN, velocity) && gb.buttons.repeat(BUTTON_RIGHT, velocity))
	  {
      if(direction == SE)
      {
        incDecPosMap(incDecValDiagonal, incDecValDiagonal);
      }
      else
      {
        direction = SE;
      }
	  }
    if(gb.buttons.repeat(BUTTON_DOWN, velocity) && gb.buttons.repeat(BUTTON_LEFT, velocity))
	  {
      if(direction == SW)
      {
        incDecPosMap(-incDecValDiagonal, incDecValDiagonal);
      }
      else
      {
        direction = SW;
      }
	  }
    if(gb.buttons.repeat(BUTTON_UP, velocity) && gb.buttons.repeat(BUTTON_LEFT, velocity))
	  {
      if(direction == NW)
      {
        incDecPosMap(-incDecValDiagonal, -incDecValDiagonal);
      }
      else
      {
        direction = NW;
      }
	  }
    if(gb.buttons.repeat(BUTTON_UP, velocity) && !gb.buttons.repeat(BUTTON_LEFT, 0) && !gb.buttons.repeat(BUTTON_RIGHT, 0))
	  {
		  if(direction == N)
      {
        incDecPosMap(0.0, -incDecVal);
      }
      else
      {
        direction = N;
      }
	  }
    if(gb.buttons.repeat(BUTTON_RIGHT, velocity) && !gb.buttons.repeat(BUTTON_UP, 0) && !gb.buttons.repeat(BUTTON_DOWN, 0))
	  { 
      if(direction == E)
      {
        incDecPosMap(incDecVal, 0.0);
      }
      else
      {
        direction = E;
      }
	  } 
    if(gb.buttons.repeat(BUTTON_DOWN, velocity) && !gb.buttons.repeat(BUTTON_LEFT, 0) && !gb.buttons.repeat(BUTTON_RIGHT, 0))
	  {
      if(direction == S)
      {
        incDecPosMap(0.0, incDecVal);
      }
      else
      {
        direction = S;
      }
	  }
    if(gb.buttons.repeat(BUTTON_LEFT, velocity) && !gb.buttons.repeat(BUTTON_UP, 0) && !gb.buttons.repeat(BUTTON_DOWN, 0))
	  {
      if(direction == W)
      { 
        incDecPosMap(-incDecVal, 0.0);
      }
      else
      {
        direction = W;
      }
	  }
  }
  //Movement pipe
   if(gb.buttons.repeat(BUTTON_A, 0))
   {
      while(pipe.getAngle() < 0.0)
      {
        pipe.incDecAngle(2 * M_PI);
      }
      while(fabs(pipe.getAngle()) > (2 * M_PI))
      {
        pipe.incDecAngle(-2 * M_PI);
      }

      if(gb.buttons.repeat(BUTTON_UP, pipe.getVelocity()))
      {
        if(pipe.getAngle() < (M_PI / 2))
        {
          pipe.incDecAngle(pipe.getIncDecVal());
        }
        else if(pipe.getAngle() > ((3 * M_PI) / 2))
        {
          pipe.incDecAngle(pipe.getIncDecVal());
        }
        else if(pipe.getAngle() < ((3 *M_PI) / 2))
          pipe.incDecAngle(-pipe.getIncDecVal());
      }
      else if(gb.buttons.repeat(BUTTON_LEFT, pipe.getVelocity()))
      {
        if(pipe.getAngle() < M_PI)
        {
          pipe.incDecAngle(pipe.getIncDecVal());
        }
        else if(pipe.getAngle() > M_PI) 
        {
          pipe.incDecAngle(-pipe.getIncDecVal());
        }
      }
      else if(gb.buttons.repeat(BUTTON_DOWN, pipe.getVelocity()))
      {
        if(pipe.getAngle() < (M_PI/2))
        {
          pipe.incDecAngle(-pipe.getIncDecVal());
        }
        else if(pipe.getAngle() < ((3 *M_PI) / 2))
        {
          pipe.incDecAngle(pipe.getIncDecVal());
        }
        else if(pipe.getAngle() > ((3 *M_PI) / 2))
        {
          pipe.incDecAngle(-pipe.getIncDecVal());
        }
      }
      else if(gb.buttons.repeat(BUTTON_RIGHT, pipe.getVelocity()))
      {
        if(pipe.getAngle() < M_PI)
        {
          pipe.incDecAngle(-pipe.getIncDecVal());
        }
        else if(pipe.getAngle() > M_PI)
        {
          pipe.incDecAngle(pipe.getIncDecVal());
        }
      }
   }

  static int timeNewBullet = DURATION_NEW_BULLET + 1;
   //Shoot
  if(gb.buttons.pressed(BUTTON_B))
  {
    int i = 0;
    while(i < MAX_BULLETS)
    {
      if(bullets[i].getIsFired() == true)
      {
        i++;
      }
      else 
      {
        if(timeNewBullet > DURATION_NEW_BULLET)
        {
          bullets[i].shoot(pipe.calcTipX(getPosMapX()), pipe.calcTipY(getPosMapY()), pipe.getAngle());
          timeNewBullet = 0;
        }
        break;
      }
    }
  }
  for(int num = 0; num < MAX_BULLETS; num++)
  {
    if(bullets[num].getIsFired())
    {
    bullets[num].update(pipe.calcTipX(getPosMapX()), pipe.calcTipY(getPosMapY()));
    }
  }
  timeNewBullet++;
  if(timeNewBullet == 255)
  {
    timeNewBullet = DURATION_NEW_BULLET + 1;
  }
}
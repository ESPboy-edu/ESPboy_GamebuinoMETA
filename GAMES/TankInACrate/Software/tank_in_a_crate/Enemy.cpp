/*
 * Enemy.cpp
 *
 *  Created on: 30.07.2025
 *      Author: Agandi
 */

#include "Enemy.h"
#include "Constants.h"
#include "Images.h"

Enemy::Enemy()
{
  colorCircle = RED;
  direction = E;
  setPosMapX(20.0);
  setPosMapY(20.0);
  image[N] = Image(IMG_ENEMY_N);
  image[NE] = Image(IMG_ENEMY_NE);
  image[E] = Image(IMG_ENEMY_E);
  image[SE] = Image(IMG_ENEMY_SE);
  image[S] = Image(IMG_ENEMY_N);
  image[SW] = Image(IMG_ENEMY_NE);
  image[W] = Image(IMG_ENEMY_E);
  image[NW] = Image(IMG_ENEMY_SE);
  moveBehaviour = 0;
  pipeBehaviour = 0;
  shootBehaviour = 0;
  isCollided = false;
  incDecVal = 0.5;
  stopRadius = 10;
  stopRadiusReached = false;
  isTimeWaited = false;
}

Enemy::~Enemy() 
{

}

void Enemy::setMoveBehaviour(uint choice)
{
  moveBehaviour = choice;
}

void Enemy::setPipeBehaviour(uint choice)
{
  pipeBehaviour = choice;
}

void Enemy::setShootBehaviour(uint choice)
{
  shootBehaviour = choice;
}

void Enemy::setIsTimeWaited(bool flag)
{
  isTimeWaited = flag;
}

void Enemy::setIsCollided(bool val)
{
  isCollided = val;
}

bool Enemy::getIsCollided()
{
  return isCollided;
}

void Enemy::setStopRadiusReached(bool val)
{
  stopRadiusReached = val;
}
uint Enemy::getStopRadius()
{
  return stopRadius;
}

void Enemy::setStopRadius(uint radius)
{
  stopRadius = radius;
}

void Enemy::updatePlayerPos(double x, double y)
{
  playerPosMapX = x;
  playerPosMapY = y;
}

void Enemy::update()
{
  setLastPosMapX((int)round(getPosMapX()));
  setLastPosMapY((int)round(getPosMapY()));

//***********************Moving**************************************************
  switch(moveBehaviour)
  {
    //no moving
    case 0: //no moving
      break;
    //random hard
    case 1:
      //change direction
      if(random(5) == 4)
      {
        direction = (CARDINAL_DIRECTIONS)random(8);
      }
      
      if(direction == NE)
      {
        incDecPosMap(incDecValDiagonal, -incDecValDiagonal);
      }
      if(direction == SE)
      {
        incDecPosMap(incDecValDiagonal, incDecValDiagonal);
      }
      if(direction == SW)
      {
        incDecPosMap(-incDecValDiagonal, incDecValDiagonal);
      }
      if(direction == NW)
      {
        incDecPosMap(-incDecValDiagonal, -incDecValDiagonal);
      }
      if(direction == N)
      {
        incDecPosMap(0.0, -incDecVal);
      }
      if(direction == E)
      {
        incDecPosMap(incDecVal, 0.0);
      }
      if(direction == S)
      {
        incDecPosMap(0.0, incDecVal);
      }
      if(direction == W)
      { 
        incDecPosMap(-incDecVal, 0.0);
      }
      break;

    case 2: //collision then random direction
      if(isCollided)
      {
        direction = (CARDINAL_DIRECTIONS)random(8);
      }
      if(direction == NE)
      {
        incDecPosMap(incDecValDiagonal, -incDecValDiagonal);
      }
      if(direction == SE)
      {
        incDecPosMap(incDecValDiagonal, incDecValDiagonal);
      }
      if(direction == SW)
      {
        incDecPosMap(-incDecValDiagonal, incDecValDiagonal);
      }
      if(direction == NW)
      {
        incDecPosMap(-incDecValDiagonal, -incDecValDiagonal);
      }
      if(direction == N)
      {
        incDecPosMap(0.0, -incDecVal);
      }
      if(direction == E)
      {
        incDecPosMap(incDecVal, 0.0);
      }
      if(direction == S)
      {
        incDecPosMap(0.0, incDecVal);
      }
      if(direction == W)
      { 
        incDecPosMap(-incDecVal, 0.0);
      }
      break;

    case 3: //move toward player
      //check if diagonal is shorter
      if(abs(playerPosMapX - getPosMapX()) == abs(playerPosMapY - getPosMapY()))
      {
        if(playerPosMapX < getPosMapX())
        {
          if(playerPosMapY < getPosMapY())
          {
            direction = NW;
          }
          else
          {
            direction = SW;
          }
        }
        else
          if(playerPosMapY < getPosMapY())
          {
            direction = NE;
          }
          else
          {
            direction = SE;
          }
      }
      //check if horizontal is shorter  
      else if (abs(playerPosMapX - getPosMapX()) > abs(playerPosMapY - getPosMapY()))
      {
        if(playerPosMapX < getPosMapX())
        {
          direction = W;
        }
        else
        {
          direction = E;
        }
      }
      //check if vertical is shorter
      else if (abs(playerPosMapX - getPosMapX()) < abs(playerPosMapY - getPosMapY()))
      {
        if(playerPosMapY < getPosMapY())
        {
          direction = N;
        }
        else
        {
          direction = S;
        }
      }
      if(stopRadius == 0 || (stopRadius > 0 && stopRadiusReached == false))
      {
        if(direction == NE)
        {
          incDecPosMap(incDecValDiagonal, -incDecValDiagonal);
        }
        if(direction == SE)
        {
          incDecPosMap(incDecValDiagonal, incDecValDiagonal);
        }
        if(direction == SW)
        {
          incDecPosMap(-incDecValDiagonal, incDecValDiagonal);
        }
        if(direction == NW)
        {
          incDecPosMap(-incDecValDiagonal, -incDecValDiagonal);
        }
        if(direction == N)
        {
          incDecPosMap(0.0, -incDecVal);
        }
        if(direction == E)
        {
          incDecPosMap(incDecVal, 0.0);
        }
        if(direction == S)
        {
          incDecPosMap(0.0, incDecVal);
        }
        if(direction == W)
        { 
          incDecPosMap(-incDecVal, 0.0);
        }
      }
      break;
    default:
      break;
  }

//***********************Pipe**************************************************
  double targetAngle = 0.0;
  switch(pipeBehaviour)
  {
    case 0: //no turning
      break;
    case 1: //random
      static int sign = 1;
      
      if(random(5) == 4)
      {
        (random(2)) ? sign = 1 : sign = -1;
      }
      pipe.incDecAngle(sign * pipe.getIncDecVal());
      break;
    case 2: //move toward player
      //calculate target angle
      targetAngle = atan2(playerPosMapX - getPosMapX(), playerPosMapY - getPosMapY());
      //normalize the angle
      targetAngle -= (M_PI / 2);
      while(targetAngle > (2 * M_PI))
      {
        targetAngle += -2 * M_PI;
      }
      while(targetAngle < 0.0)
      {
        targetAngle += (2 * M_PI);
      }

      while(pipe.getAngle() > (2 * M_PI))
      {
        pipe.incDecAngle(-2 * M_PI);
      } 
      while(pipe.getAngle() < 0.0)
      {
        pipe.incDecAngle(2 * M_PI);
      }

      //move with the shorter way
      if(fabs(targetAngle - pipe.getAngle()) > pipe.getIncDecVal())
      {
        if(targetAngle > pipe.getAngle())
        {
          if((targetAngle - pipe.getAngle()) < M_PI)
          {
            pipe.incDecAngle(pipe.getIncDecVal());
          }
          else
          {
            pipe.incDecAngle(-pipe.getIncDecVal());
          }
        }
        else if(targetAngle < pipe.getAngle())
        {
          if((pipe.getAngle() - targetAngle) < M_PI)
          {
            pipe.incDecAngle(-pipe.getIncDecVal());
          }
          else
          {
            pipe.incDecAngle(pipe.getIncDecVal());
          }
        }
      }
      break;
    default:
      break;
  }
//***********************Shooting**************************************************
  int i = 0;
  switch(shootBehaviour)
  {
    case 0: //Shoot never
      break;
    case 1: //Shoot always
      static int timeNewBullet = DURATION_NEW_BULLET + 1;

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
      break;
      case 2: //Shoot always with a random duration and a wait time

      static int timeNewBullet2 = DURATION_NEW_BULLET + 1;
      while(i < MAX_BULLETS)
      {
        if(bullets[i].getIsFired() == true)
        {
          i++;
        }
        else 
        {
          if(timeNewBullet2 > (DURATION_NEW_BULLET + random(11)) && (isTimeWaited == true))
          {
            bullets[i].shoot(pipe.calcTipX(getPosMapX()), pipe.calcTipY(getPosMapY()), pipe.getAngle());
            timeNewBullet2 = 0;
          }
          break;
        }
      }
      for(int num = 0; num < MAX_BULLETS; num++)
      {
        if(bullets[num].getIsFired())
        {
        bullets[num].update(pipe.calcTipX(getPosMapX()), pipe.calcTipY(getPosMapY()));
        }
      }
      timeNewBullet2++;
      //Check wait time
      if(timeNewBullet2 > WAITTIME)
      {
        isTimeWaited = true;
      }
      if(timeNewBullet2 == 255)
      {
        timeNewBullet2 = DURATION_NEW_BULLET + 1;
      }
      break;
    default:
      break;
  }
}
/*
 * Moveable.cpp
 *
 *  Created on: 30.07.2025
 *      Author: Agandi
 */

#include "Moveable.h"

Moveable::Moveable()
{
	
}

Moveable::~Moveable() 
{
	
}

void Moveable::incDecPosMap(double dx, double dy)
{
  setPosMapX(getPosMapX() + dx);
  setPosMapY(getPosMapY() + dy);
}

int Moveable::getVelocity()
{
  return velocity;
}

Bullet::Bullet() 
{
  color = BLACK;
  isFired = false;
  velocity = 2.0;
  radius = 1;
  isCollided = false;
  isFirstTime = true;
  setPosMapX(-10.0);
  setPosMapY(-10.0);
}

Bullet::~Bullet() 
{
	
}

void Bullet::draw()
{
    if(isFired)
    {
      gb.display.setColor(color);
      gb.display.drawCircle(getPosDrawX(), getPosDrawY(), getRadius());
    }
}

void Bullet::update(int posTankX, int posTankY)
{
  if(isFired)
  {     
    if(isFirstTime)
    {
      doublePosMapX = posTankX;
      doublePosMapY = posTankY; 
    }
    isFirstTime = false;
    doublePosMapX = doublePosMapX + (getVelocity() * cos(getAngle()));
    doublePosMapY = doublePosMapY - (getVelocity() * sin(getAngle()));
    setPosMapX(round(doublePosMapX));
    setPosMapY(round(doublePosMapY));
  }
  if(isCollided)
  {
    isFired = false;
    isFirstTime = true;
    setPosMapX(-10);
    setPosMapY(-10);
    doublePosMapX = -10.0;
    doublePosMapY = -10.0;
    isCollided = false;
  }
}

void Bullet::shoot(int x, int y, double alpha)
{
  isFired = true;
  setPosMapX(x);
  setPosMapY(y);
  angle = alpha; 
}

double Bullet::getAngle()
{
  return angle;
}

double Bullet::getVelocity()
{
  return velocity;
}

int Bullet::getRadius()
{
  return radius;
}
bool Bullet::getIsCollided()
{
  return isCollided;
}

bool Bullet::getIsFired()
{
  return isFired;
}

void Bullet::setIsFired(bool flag)
{
  isFired = flag;
}

void Bullet::setAngle(double alpha)
{
  angle = alpha;
}

void Bullet::setIsCollided(bool flag)
{
  isCollided = flag;
}

Pipe::Pipe() 
{
  offsetSpriteX = 0;
  offsetSpriteY = 0;
  length = 6;
  width = 1;
  velocity = 1;
  angle = 2 * M_PI;
  color = BLACK;
  incDecVal = 0.05;
}

Pipe::~Pipe() 
{
	
}

double Pipe::getAngle()
{
  return angle;
}

double Pipe::calcTipX(double x)
{
  return (x + length * cos(angle));
}

double Pipe::calcTipY(double y)
{
  return (y - length * sin(angle));
}

void Pipe::setAngle(double alpha)
{
  angle = alpha;
}

double Pipe::getIncDecVal()
{
  return incDecVal;
}

void Pipe::draw(int x, int y)
{
  gb.display.setColor(color);
  gb.display.drawLine(x, y, x + round(length * cos(angle)), y - round(length * sin(angle)));
}

void Pipe::incDecAngle(double a)
{
  angle += a;
}

Tank::Tank()
{
  offsetSpriteX = 5;
  offsetSpriteY = 5;
  length = 11;
  width = 11;
  colorCircle = RED;
  radius = 5;
  velocity = 1;
  incDecVal = 1.0;
  incDecValDiagonal = sqrt(2)/2;
}

Tank::~Tank() 
{
	
}

int Tank::getRadius()
{
  return radius;
}

int Tank::getLastPosMapX()
{
  return lastPosMapX;
}

int Tank::getLastPosMapY()
{
  return lastPosMapY;
}

Image& Tank::getImage(int n)
{
  if(n < NBR_OF_CARDINAL_DIRECTIONS)
  {
    return image[n];
  }
 return image[0];
}

bool Tank::getIsDestroyed()
{
   return isDestroyed;
}

void Tank::setLastPosMapX(int x)
{
  lastPosMapX = x;
}

void Tank::setLastPosMapY(int y)
{
  lastPosMapY = y;
}

void Tank::setIsDestroyed(bool val)
{
  isDestroyed = val;
}

void Tank::setDirection(char dir)
{
  direction = (CARDINAL_DIRECTIONS)dir;
}

void Tank::setPipeDirection(int dir)
{
  if(dir == 0)
    pipe.setAngle(0.5 * M_PI);
  if(dir == 1)
    pipe.setAngle(0.25 * M_PI);
  if(dir == 2)
    pipe.setAngle(0.0);
  if(dir == 3)
    pipe.setAngle(0.25 * -M_PI);
  if(dir == 4)
    pipe.setAngle(0.5 * -M_PI);
  if(dir == 5)
    pipe.setAngle(0.75 * -M_PI);
  if(dir == 6)
    pipe.setAngle(M_PI);
  if (dir == 7)
    pipe.setAngle(0.75 * M_PI);
}

void Tank::draw()
{
  switch(direction)
  {
    case N:
      gb.display.drawImage(getPosDrawX(), getPosDrawY(), getImage(N));
      break;
    case NE:
      gb.display.drawImage(getPosDrawX(), getPosDrawY(), getImage(NE));
      break;
    case E:
      gb.display.drawImage(getPosDrawX(), getPosDrawY(), getImage(E));
      break;
    case SE:
      gb.display.drawImage(getPosDrawX(), getPosDrawY(), getImage(SE));
      break;
    case S:
      gb.display.drawImage(getPosDrawX(), getPosDrawY(), getImage(S));
      break;
    case SW:
      gb.display.drawImage(getPosDrawX(), getPosDrawY(), getImage(SW));
      break;
    case W:
      gb.display.drawImage(getPosDrawX(), getPosDrawY(), getImage(W));
      break;
    case NW:
      gb.display.drawImage(getPosDrawX(), getPosDrawY(), getImage(NW));
      break;
  }
  gb.display.setColor(colorCircle);
  gb.display.drawCircle(getPosMapX(), getPosMapY(), radius);
  pipe.draw(getPosMapX(), getPosMapY());
   for(int num = 0; num < MAX_BULLETS; num++)
  {
    bullets[num].draw();
  }
}

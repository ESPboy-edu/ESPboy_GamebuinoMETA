/*
 * Stationary.cpp
 *
 *  Created on: 30.07.2025
 *      Author: Agandi
 */

#include "Stationary.h"

Stationary::Stationary() 
{
	offsetSpriteX = 1;
  offsetSpriteY = 1;
  length = 3;
  width = 3;
}

Stationary::~Stationary() 
{
	
}

Image& Stationary::getImage()
{
  return image;
}

void Stationary::position(int x, int y)
{
  setPosMapX(x);
  setPosMapY(y);
}

void Stationary::draw()
{
  gb.display.drawImage(getPosDrawX(), getPosDrawY(), getImage());
}

Floor::Floor() 
{
  image = Image(IMG_FLOOR);
}

Floor::~Floor() 
{

}

Wall::Wall() 
{
	image = Image(IMG_WALL);
}

Wall::~Wall() 
{

}

Obstacle::Obstacle()
{
  image = Image(IMG_OBSTACLE);
}

Obstacle::~Obstacle() 
{

}
/*
 * Object.cpp
 *
 *  Created on: 30.07.2025
 *      Author: Agandi
 */

#include "Object.h"

Object::Object() 
{
	posMapX = 0.0;
  posMapY = 0.0;
  offsetSpriteX = 0;
  offsetSpriteY = 0;
  length = 1;
  width = 1;
}

Object::~Object() 
{
	
}

void Object::setPosMapX(double x)
{
	posMapX = x;
}

void Object::setPosMapY(double y)
{
	posMapY = y;
}

double Object::getPosMapX()
{
	return posMapX;
}

double Object::getPosMapY()
{
	return posMapY;
}

int Object::getPosDrawX()
{
	return posMapX - offsetSpriteX;
}

int Object::getPosDrawY()
{
	return posMapY - offsetSpriteY;
}

int Object::getLength()
{
	return length;
}

int Object::getWidth()
{
	return width;
}
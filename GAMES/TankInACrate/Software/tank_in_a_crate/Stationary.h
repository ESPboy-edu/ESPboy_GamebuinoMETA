/*
 * Stationary.h
 *
 *  Created on: 30.07.2025
 *      Author: Agandi
 */

#ifndef STATIONARY_H_
#define STATIONARY_H_

#include <Gamebuino-Meta.h>
#include "Object.h"
#include "Images.h"

class Stationary: public Object
{
  protected:
    Image image;

  public:
	  Stationary();
	  virtual ~Stationary();

    Image& getImage();
    void position(int x, int y);
    void draw();
};

class Floor: public Stationary
{
  public:
	  Floor();
	  virtual ~Floor();
};

class Wall: public Stationary
{
  public:
	  Wall();
	  virtual ~Wall();
};

class Obstacle: public Stationary
{
  public:
	  Obstacle();
	  virtual ~Obstacle();
};
#endif /* STATIONARY_H_ */

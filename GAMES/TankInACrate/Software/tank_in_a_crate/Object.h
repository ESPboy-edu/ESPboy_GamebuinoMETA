/*
 * Object.h
 *
 *  Created on: 30.07.2025
 *      Author: Agandi
 */

#ifndef OBJECT_H_
#define OBJECT_H_

#include<Gamebuino-Meta.h>

class Object
{
  private:
    double posMapX;
    double posMapY;

  protected:
    int offsetSpriteX;
    int offsetSpriteY;
    int length;
    int width;

  public:
	  Object();
	  virtual ~Object();

    void setPosMapX(double x);
    void setPosMapY(double y);
    
    double getPosMapX();
    double getPosMapY();
    int getPosDrawX();
    int getPosDrawY();
    int getLength();
    int getWidth();
};

#endif /* OBJECT_H_ */

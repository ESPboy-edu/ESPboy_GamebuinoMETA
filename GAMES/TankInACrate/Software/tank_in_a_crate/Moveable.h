/*
 * Moveable.h
 *
 *  Created on: 30.07.2025
 *      Author: Agandi
 */

#ifndef MOVEABLE_H_
#define MOVEABLE_H_

#include "Object.h"
#include "Constants.h"

class Moveable: public Object
{
  protected:
    void incDecPosMap(double dx, double dy);
    int velocity;

  public:
	  Moveable();
	  virtual ~Moveable();
    
    int getVelocity();
};

class Bullet: public Moveable
{
  private:
    bool isFired;
    bool isCollided;
    bool isFirstTime;

    int radius;

    double angle;
    double velocity;
    double doublePosMapX;
    double doublePosMapY;

    Color color;
    

  public:
    Bullet();
    virtual ~Bullet();

    void draw();
    void update(int posTankX, int posTankY);
    void shoot(int x, int y, double alpha);
    double getVelocity();
    double getAngle();
    int getRadius();
    bool getIsCollided();
    bool getIsFired();
    void setIsFired(bool flag);
    void setAngle(double alpha);
    void setIsCollided(bool flag);
};

class Pipe: public Moveable
{
  private:
    double angle;
    double incDecVal;

    Color color;
    
  public:
    Pipe();
    virtual ~Pipe();

    double getIncDecVal();
    void draw(int y, int x);
    void incDecAngle(double a);
    double getAngle();
    double calcTipX(double x);
    double calcTipY(double y);
    void setAngle(double alpha);
};

class Tank: public Moveable
{
  private:
    bool isDestroyed;

    int lastPosMapX;
    int lastPosMapY;
   

  protected: 
    int radius;

    double incDecVal;
    double incDecValDiagonal;
   
    Color colorCircle;
    Image image[NBR_OF_CARDINAL_DIRECTIONS];
    CARDINAL_DIRECTIONS direction;

  public:
    Tank();
    virtual ~Tank();

    Pipe pipe;
    Bullet bullets[MAX_BULLETS];

    int getRadius();
    int getLastPosMapX();
    int getLastPosMapY();
    bool getIsDestroyed();

    Image& getImage(int n); //0-7, N, NE, E...

    void setLastPosMapX(int x);
    void setLastPosMapY(int y);
    void setIsDestroyed(bool val);
    void setDirection(char dir);
    void setPipeDirection(int dir);

    void draw();
};

#endif /* MOVEABLE_H_ */

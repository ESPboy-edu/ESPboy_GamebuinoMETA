/*
 * Enemy.h
 *
 *  Created on: 30.07.2025
 *      Author: Agandi
 */

#ifndef ENEMY_H_
#define ENEMY_H_

#include "Moveable.h"

class Enemy: public Tank
{
  private:
    bool isCollided;
    bool stopRadiusReached;
    bool isTimeWaited;

    uint moveBehaviour;
    uint pipeBehaviour;
    uint shootBehaviour;
    uint stopRadius;
    uint timeNewBullet;

    double playerPosMapX;
    double playerPosMapY;
    
  public:
	  Enemy();
	  virtual ~Enemy();
    
    void setMoveBehaviour(uint choice);
    void setPipeBehaviour(uint choice);
    void setShootBehaviour(uint choice);
    void setIsTimeWaited(bool flag);
    void setIsCollided(bool val);
    bool getIsCollided();
    void setStopRadiusReached(bool val);
    void setStopRadius(uint radius);
    uint getStopRadius();
    void updatePlayerPos(double x, double y);
    
    void update();
};

#endif /* ENEMY_H_ */

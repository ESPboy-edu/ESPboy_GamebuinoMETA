/*
 * World.h
 *
 *  Created on: 30.07.2025
 *      Author: Agandi
 */

#ifndef WORLD_H_
#define WORLD_H_

#include <Gamebuino-Meta.h>
#include "Stationary.h"
#include "Constants.h"
#include "Player.h"
#include "Levels.h"
#include "Enemy.h"

class World {
  private:
    int wallPosList[MAX_WALL_POS_SUM][2];
    int wallPosSum;
    int obstaclePosList[MAX_OBSTACLE_POS_SUM][2];
    int obstaclePosSum;
    Enemy enemiesList[MAX_ENEMIES];
    int enemiesSum;

    int nbrMap;
    WORLD_STATES worldState;

  public:
	  World();
	  virtual ~World();

    Player player;
    Floor floor;
    Wall wall;
    Obstacle obstacle;

    void create();
    void update();
    void draw();
    void collision();
    void setNbrMap(int n);
    WORLD_STATES getWorldState();
};
#endif /* WORLD_H_ */

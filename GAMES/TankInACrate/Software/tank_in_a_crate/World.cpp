/*
 * World.cpp
 *
 *  Created on: 30.07.2025
 *      Author: Agandi
 */

#include "World.h"

World::World() 
{
  nbrMap = 0;
  worldState = LOST;
}

World::~World() 
{
	
}

void World::setNbrMap(int n)
{
  nbrMap = n;
}

WORLD_STATES World::getWorldState()
{
  return worldState;
}

void World::create()
{
  worldState = PLAYING;

  //Reset Player
  player.setIsDestroyed(false);
  player.setDirection(E);
  player.setPipeDirection(2);
  player.setPosMapX(8.0);
  player.setPosMapY(8.0);
  for(int b = 0; b < MAX_BULLETS; b++)
  {
    player.bullets[b].setPosMapX(-10.0);
    player.bullets[b].setPosMapY(-10.0);
    player.bullets[b].setIsFired(false);
    
  }

  //Initialize of the arrays
  for(int x = 0; x < MAX_WALL_POS_SUM; x++)
  {
    for(int y = 0; y < 2; y++)
    {
       wallPosList[x][y] = 9999;
    }     
  }

  for(int x = 0; x < MAX_OBSTACLE_POS_SUM; x++)
  {
    for(int y = 0; y < 2; y++)
    {
       obstaclePosList[x][y] = 9999;
    }     
  } 

  for(int i = 0; i < MAX_ENEMIES; i++)
  {
    enemiesList[i].setIsDestroyed(true);
  }

  wallPosSum = 0;
  obstaclePosSum = 0;

  //Fill lists of the walls and obstacles
  for(int x = 0; x < pgm_read_byte(mapsWall[nbrMap]); x++)
  {
    for(int y = 0; y < pgm_read_byte(mapsWall[nbrMap] + 1); y++)
    {
      if(gb.display.getBitmapPixel(mapsWall[nbrMap], x, y))
      {
        wallPosList[wallPosSum][0] = (3 * x + 1);
        wallPosList[wallPosSum][1] = (3 * y + 1);
        wallPosSum++;
      }
      if(gb.display.getBitmapPixel(mapsObstacle[nbrMap], x, y))
      {
        obstaclePosList[obstaclePosSum][0] = (3 * x + 1);
        obstaclePosList[obstaclePosSum][1] = (3 * y + 1);
        obstaclePosSum++;
      }
    }
  }

  //Initialize the enemys
  enemiesSum = mapsEnemies[nbrMap][0];
  for(int i = 0; i < enemiesSum; i++)
  {
    enemiesList[i].setIsDestroyed(false);
    enemiesList[i].setIsTimeWaited(false);
    enemiesList[i].setPosMapX(mapsEnemies[nbrMap][i * 7 + 1]);
    enemiesList[i].setPosMapY(mapsEnemies[nbrMap][i * 7 + 2]);
    enemiesList[i].setDirection(mapsEnemies[nbrMap][i * 7 + 3]);
    enemiesList[i].setPipeDirection(mapsEnemies[nbrMap][i * 7 + 4]);
    enemiesList[i].setMoveBehaviour(mapsEnemies[nbrMap][i * 7 + 5]);
    enemiesList[i].setPipeBehaviour(mapsEnemies[nbrMap][i * 7 + 6]);
    enemiesList[i].setShootBehaviour(mapsEnemies[nbrMap][i * 7 + 7]);
    for(int b = 0; b < MAX_BULLETS; b++)
    {
      enemiesList[i].bullets[b].setPosMapX(-10.0);
      enemiesList[i].bullets[b].setPosMapY(-10.0);
      enemiesList[i].bullets[b].setIsFired(false);
    }
    
  }
}

void World::update()
{
  //Update enemies
  for(int e = 0; e < enemiesSum; e++)
  {
    if(enemiesList[e].getIsDestroyed() == false)
    {
      enemiesList[e].updatePlayerPos(player.getPosMapX(), player.getPosMapY());
      enemiesList[e].update();
    }
  }

  //Check if all enemies are destroyed
  int enemiesDestroyedSum = 0;
  for(int e = 0; e < enemiesSum; e++)
  {
    if(enemiesList[e].getIsDestroyed() == true)
    {
      enemiesDestroyedSum++;
    }
  }
  if(enemiesDestroyedSum == enemiesSum)
  {
    worldState = WON;
  }
  else if(player.getIsDestroyed() == true)
  {
    worldState = LOST;
  }
  
}

void World::draw()
{
  for(int x = 0; x < pgm_read_byte(mapsFloor[nbrMap]); x++)
  {
    for(int y = 0; y < pgm_read_byte(mapsFloor[nbrMap] + 1); y++)
    {
      if(gb.display.getBitmapPixel(mapsFloor[nbrMap], x, y))
      {
        floor.position(3 * x + 1, 3 * y + 1);
        floor.draw();
      }
    }
  }
  for(int i = 0; i < wallPosSum; i++)
  {
    wall.position(wallPosList[i][0], wallPosList[i][1]);
    wall.draw();
  }

  for(int i = 0; i < obstaclePosSum; i++)
  {
    obstacle.position(obstaclePosList[i][0], obstaclePosList[i][1]);
    obstacle.draw();
  }
  for(int e = 0; e < enemiesSum; e++)
   {
    if(enemiesList[e].getIsDestroyed() == false)
    {
      enemiesList[e].draw();
    }
  }
}

void World::collision()
{
  //Player
  //Player with wall
  for(int i = 0; i < wallPosSum; i++)
  {
    if(gb.collide.circleCircle(player.getPosMapX(), player.getPosMapY(), player.getRadius(), wallPosList[i][0], wallPosList[i][1], RADIUS_STATIONARY))
      {
        player.setPosMapX(player.getLastPosMapX());
        player.setPosMapY(player.getLastPosMapY());
      }
  }
  //Player with obstacle
  for(int i = 0; i < obstaclePosSum; i++)
  {
    if(gb.collide.circleCircle(player.getPosMapX(), player.getPosMapY(), player.getRadius(), obstaclePosList[i][0], obstaclePosList[i][1], RADIUS_STATIONARY))
    {
      player.setPosMapX(player.getLastPosMapX());
      player.setPosMapY(player.getLastPosMapY());
    }
  }
  //Player with enemy
  for(int e = 0; e < enemiesSum; e++)
  {
    if(enemiesList[e].getIsDestroyed() == false)
    {
      if(gb.collide.circleCircle(player.getPosMapX(), player.getPosMapY(), player.getRadius(), enemiesList[e].getPosMapX(), enemiesList[e].getPosMapY(), enemiesList[e].getRadius()))
      {
        player.setPosMapX(player.getLastPosMapX());
        player.setPosMapY(player.getLastPosMapY()); 
      }
    }
  }

  //Enemy
  for(int e = 0; e < enemiesSum; e++)
  {
    if(enemiesList[e].getIsDestroyed() == false)
    {
      if(enemiesList[e].getIsCollided())
      {
        enemiesList[e].setIsCollided(false);
      }
      //Enemy with wall
      for(int i = 0; i < wallPosSum; i++)
      {
        if(gb.collide.circleCircle(enemiesList[e].getPosMapX(), enemiesList[e].getPosMapY(), enemiesList[e].getRadius()+1, wallPosList[i][0], wallPosList[i][1], RADIUS_STATIONARY))
          {
            enemiesList[e].setPosMapX(enemiesList[e].getLastPosMapX());
            enemiesList[e].setPosMapY(enemiesList[e].getLastPosMapY());
            enemiesList[e].setIsCollided(true);
          }
      }
      //Enemy with obstacle
      for(int i = 0; i < obstaclePosSum; i++)
      {
        if(gb.collide.circleCircle(enemiesList[e].getPosMapX(), enemiesList[e].getPosMapY(), enemiesList[e].getRadius()+1, obstaclePosList[i][0], obstaclePosList[i][1], RADIUS_STATIONARY))
        {
          enemiesList[e].setPosMapX(enemiesList[e].getLastPosMapX());
          enemiesList[e].setPosMapY(enemiesList[e].getLastPosMapY());
          enemiesList[e].setIsCollided(true);
        }
      }
      //Enemy with player
      if(gb.collide.circleCircle(enemiesList[e].getPosMapX(), enemiesList[e].getPosMapY(), enemiesList[e].getRadius()+1, player.getPosMapX(), player.getPosMapY(), player.getRadius()))
      {
        enemiesList[e].setPosMapX(enemiesList[e].getLastPosMapX());
        enemiesList[e].setPosMapY(enemiesList[e].getLastPosMapY());
        enemiesList[e].setIsCollided(true); 
      }

      //StopRadius
      if(gb.collide.circleCircle(enemiesList[e].getPosMapX(), enemiesList[e].getPosMapY(), enemiesList[e].getStopRadius(), player.getPosMapX(), player.getPosMapY(), player.getRadius()))
      {
        enemiesList[e].setStopRadiusReached(true); 
      }
      else
      {
        enemiesList[e].setStopRadiusReached(false); 
      }

      //Enemy with enemy
      for(int eRest = 0; eRest < enemiesSum; eRest++)
      {
        if(eRest != e)
        {
          if(gb.collide.circleCircle(enemiesList[e].getPosMapX(), enemiesList[e].getPosMapY(), enemiesList[e].getRadius()+1, enemiesList[eRest].getPosMapX(), enemiesList[eRest].getPosMapY(), enemiesList[eRest].getRadius()))
          {
            enemiesList[e].setPosMapX(enemiesList[e].getLastPosMapX());
            enemiesList[e].setPosMapY(enemiesList[e].getLastPosMapY());
            enemiesList[e].setIsCollided(true); 
          }
        }
      }
    }
  }

  //Player Bullets to walls, obstacles and enemies
  for(int i = 0; i < MAX_BULLETS; i++)
  {
    for(int w = 0; w < wallPosSum; w++)
    {
      if(gb.collide.circleCircle(player.bullets[i].getPosMapX(), player.bullets[i].getPosMapY(), player.bullets[i].getRadius(), wallPosList[w][0], wallPosList[w][1], RADIUS_STATIONARY))
        {
          player.bullets[i].setIsCollided(true);
        }
    }

    for(int o = 0; o < obstaclePosSum; o++)
    {
      if(gb.collide.circleCircle(player.bullets[i].getPosMapX(), player.bullets[i].getPosMapY(), player.bullets[i].getRadius(), obstaclePosList[o][0], obstaclePosList[o][1], RADIUS_STATIONARY))
      {
        player.bullets[i].setIsCollided(true);
      }
    }

    for(int e = 0; e < enemiesSum; e++)
    {
      if(enemiesList[e].getIsDestroyed() == false)
      {
        if(gb.collide.circleCircle(player.bullets[i].getPosMapX(), player.bullets[i].getPosMapY(), player.bullets[i].getRadius(), enemiesList[e].getPosMapX(), enemiesList[e].getPosMapY(), enemiesList[e].getRadius()))
        {
          player.bullets[i].setIsCollided(true);
          enemiesList[e].setIsDestroyed(true);
          enemiesList[e].setPosMapX(-20);
          enemiesList[e].setPosMapY(-20);

          //change old position from bullets from enemy
          for(int f = 0; f < MAX_BULLETS; f++)
          {
            enemiesList[e].bullets[f].setPosMapX(-10.0);
            enemiesList[e].bullets[f].setPosMapY(-10.0);
          }
        }
      }
    }
  }

  //Enemey Bullets to walls, obstacles and player
  for(int i = 0; i < MAX_BULLETS; i++)
  {
    for(int e = 0; e < enemiesSum; e++)
    {
      for(int w = 0; w < wallPosSum; w++)
      {
        if(gb.collide.circleCircle(enemiesList[e].bullets[i].getPosMapX(), enemiesList[e].bullets[i].getPosMapY(), enemiesList[e].bullets[i].getRadius(), wallPosList[w][0], wallPosList[w][1], RADIUS_STATIONARY))
          {
            enemiesList[e].bullets[i].setIsCollided(true);
          }
      }

      for(int o = 0; o < obstaclePosSum; o++)
      {
        if(gb.collide.circleCircle(enemiesList[e].bullets[i].getPosMapX(), enemiesList[e].bullets[i].getPosMapY(), enemiesList[e].bullets[i].getRadius(), obstaclePosList[o][0], obstaclePosList[o][1], RADIUS_STATIONARY))
        {
          enemiesList[e].bullets[i].setIsCollided(true);
        }
      }

      if(gb.collide.circleCircle(enemiesList[e].bullets[i].getPosMapX(), enemiesList[e].bullets[i].getPosMapY(), enemiesList[e].bullets[i].getRadius(), player.getPosMapX(), player.getPosMapY(), player.getRadius()))
      {
        enemiesList[e].bullets[i].setIsCollided(true);
        player.setIsDestroyed(true);
      }

    }
  }
}
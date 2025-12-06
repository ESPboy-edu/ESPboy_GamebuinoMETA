/*
 * Player.h
 *
 *  Created on: 30.07.2025
 *      Author: Agandi
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <Gamebuino-Meta.h>
#include "Moveable.h"
#include "Constants.h"
#include "Images.h"

class Player: public Tank
{
  public:
	  Player();
	  virtual ~Player();

    void update();
};

#endif /* PLAYER_H_ */

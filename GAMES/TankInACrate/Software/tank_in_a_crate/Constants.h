/*
 * Constants.h
 *
 *  Created on: 30.07.2025
 *      Author: Agandi
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

const uint8_t NBR_OF_CARDINAL_DIRECTIONS = 8;
enum CARDINAL_DIRECTIONS {N, NE, E, SE, S, SW, W, NW};
enum GAME_STATES {HOME_STATE, PLAY_STATE, CONTROL_STATE, RESET_STATE, VERSION_STATE, LEVELS_STATE, WIN_STATE, LOSE_STATE};
enum WORLD_STATES {PLAYING, WON, LOST};
// max Field 160px x 128px /3(Field) => 53 x 42 = 2226 Fields 
const uint8_t MAX_WALL_POS_SUM = 255;
const uint8_t MAX_OBSTACLE_POS_SUM = 128;
const uint8_t MAX_ENEMIES = 4;
const uint8_t MAX_BULLETS = 5;
const uint8_t DURATION_NEW_BULLET = 20;
const uint8_t NBR_MAPS = 5;
const uint8_t RADIUS_STATIONARY = 2;
const uint8_t WAITTIME = 40;

#endif /* CONSTANTS_H_ */
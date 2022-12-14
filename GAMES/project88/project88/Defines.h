#pragma once

#include <Gamebuino-Meta.h>

#define likely(x)       __builtin_expect((x),1)
#define unlikely(x)     __builtin_expect((x),0)
#define force_inline    
//__attribute__((always_inline))

namespace Gamebuino_Meta
{
  static SPISettings tftSPISettings = SPISettings(24000000, MSBFIRST, SPI_MODE0);
};

#define COLOR_R(r) ((uint16_t)(r & 0xF8))
#define COLOR_G_LOW(g) ((uint16_t)(g) << 13)
#define COLOR_G_HIGH(g) ((uint16_t)(g) >> 5)
#define COLOR_B(b) ((uint16_t)(b & 0xF8) << 5)

#define COLOR_565(r, g, b) ((uint16_t)(COLOR_R(r) | COLOR_G_LOW(g) | COLOR_G_HIGH(g) | COLOR_B(b)))

enum class Level
{
  Arizona,
  Suburb,
  Skyway,
  Bonus
};

const uint16_t LIGHT_COLLISION_RIGHT[] {
  2,4,    // width, height
  1,      // number of frames
  0,      // frame looping speed
  0,      // transparent color magenta
  0,      // color mode RGB
  //image data
  COLOR_565(0x00, 0xF, 0x00), 0x0000,
  COLOR_565(0x00, 0xF, 0x00), 0x0000,
  COLOR_565(0x00, 0xF, 0x00), 0x0000,
  COLOR_565(0x00, 0xF, 0x00), 0x0000
  };

const uint16_t LIGHT_COLLISION_LEFT[] {
  2,4,    // width, height
  1,      // number of frames
  0,      // frame looping speed
  0,      // transparent color magenta
  0,      // color mode RGB
  //image data
  0x0000, COLOR_565(0x00, 0xF, 0x00),
  0x0000, COLOR_565(0x00, 0xF, 0x00),
  0x0000, COLOR_565(0x00, 0xF, 0x00),
  0x0000, COLOR_565(0x00, 0xF, 0x00)
  };

const uint16_t LIGHT_COLLISION_FRONT[] {
  2,4,    // width, height
  1,      // number of frames
  0,      // frame looping speed
  0,      // transparent color magenta
  0,      // color mode RGB
  //image data
  COLOR_565(0x00, 0xF, 0x00), COLOR_565(0x00, 0xF, 0x00),
  COLOR_565(0x00, 0xF, 0x00), COLOR_565(0x00, 0xF, 0x00),
  COLOR_565(0x00, 0xF, 0x00), COLOR_565(0x00, 0xF, 0x00),
  COLOR_565(0x00, 0xF, 0x00), COLOR_565(0x00, 0xF, 0x00)
  };

const uint16_t LIGHT_NONE[] {
  2,4,    // width, height
  1,      // number of frames
  0,      // frame looping speed
  0,      // transparent color magenta
  0,      // color mode RGB
  //image data
  0x0000, 0x0000,
  0x0000, 0x0000,
  0x0000, 0x0000,
  0x0000, 0x0000
  };

const uint16_t LIGHT_BONUS[] {
  2,4,    // width, height
  1,      // number of frames
  0,      // frame looping speed
  0,      // transparent color magenta
  0,      // color mode RGB
  //image data
  COLOR_565(0xFF, 0x00, 0xFF), COLOR_565(0xFF, 0x00, 0xFF),
  COLOR_565(0xFF, 0x00, 0xFF), COLOR_565(0xFF, 0x00, 0xFF),
  COLOR_565(0xFF, 0x00, 0xFF), COLOR_565(0xFF, 0x00, 0xFF),
  COLOR_565(0xFF, 0x00, 0xFF), COLOR_565(0xFF, 0x00, 0xFF)
  };
  
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 128
#define STRIP_HEIGHT 8
#define STRIP_SIZE_PIX (SCREEN_WIDTH * STRIP_HEIGHT)
#define STRIP_SIZE_BYTES (STRIP_SIZE_PIX * 2)

//#define FIXED_8_8 uint16_t
#define Z_POSITION int32_t /* sign.23.8 */
#define Z_POSITION_SHIFT 8
#define Z_POSITION_MAX 0x7FFFFFFF

#define ROAD_CURVATURE_X int8_t /* sign.3.4 */
#define ROAD_CURVATURE_X_SHIFT 4

namespace roads
{
  struct LevelConfig
  {
    Level level;
    int16_t xCurvature;
    int16_t zCurvatureMin;
    int16_t zCurvatureMax;
    uint8_t bumperWidth;
    uint8_t roadWidth;
    uint8_t lineWidth;
    uint8_t sceneryObjectsCount;
    uint8_t sceneryObjectsIndexStart;
    uint8_t sceneryObjectsIndexEnd;
    uint8_t staticObstaclesCount;
    uint8_t staticObstaclesIndexStart;
    uint8_t staticObstaclesIndexEnd;
    uint8_t movingObstaclesCount;
    uint8_t movingObstaclesIndexStart;
    uint8_t movingObstaclesIndexEnd;
  };
}

#define Z_E (-5.f)
#define Y_E_METERS (5.f)
#define DEPTH_LEVEL_COUNT (80)

#define SKY_Z (0xFF)

#define COLOR_TRACK_GRASS_INDEX 0
#define COLOR_TRACK_BUMPER_INDEX (COLOR_TRACK_GRASS_INDEX+1)
#define COLOR_TRACK_ROAD_INDEX (COLOR_TRACK_BUMPER_INDEX+1)
#define COLOR_TRACK_LINE_INDEX (COLOR_TRACK_ROAD_INDEX+1)
#define COLOR_TRACK_SIZE (COLOR_TRACK_LINE_INDEX + 1)

#define MAX_SPRITES 8
#define JERRICAN_SPRITE_INDEX (MAX_SPRITES-2)
#define BONUS_SPRITE_INDEX (MAX_SPRITES-1)
#define MAX_SCENERY_OBJECTS 14
#define MAX_STATIC_OBSTACLES 3
#define MAX_MOVING_OBSTACLES 3
#define MAX_DRAWABLES (MAX_SCENERY_OBJECTS + MAX_STATIC_OBSTACLES + MAX_MOVING_OBSTACLES + 1 /*car*/)

/*
 * Perspective computation: 
 * - Unit: meter
 * - The viewport is located at depth z = 0, and is perpendicular to the ground. The bottom row has altitude y = 0.
 * - The eye of the viewer is located at z = ze (negative), height ye = 5 (5 meters above ground looks like a nice point of view for a racing game). Let's say that 5 meters is 80 pixels (horizon slightly above the middle of the screen)
 * - So, at row ye, we see the horizon (z = inf)
 * - At row 0, the viewport touches the ground.
 * - Let's find the z value for the point showed at row y :
 * - Let alpha the angle between a horizontal line and the line from the eye to the row
 * - [1] tan(alpha) = (ye - y) / (-ze)
 * - the line touches the ground at z
 * - [2] tan(alpha) = ye / (z - ze)
 * - Combining both equations:
 * - (ye - y) / (-ze) = ye / (z - ze)
 * -> (z - ze) = (-ze) / (ye - y) * ye
 * -> z = (-ze) / (ye - y) * ye + ze
 */

enum class CarSprite 
{
  Front,
  Left,
  Right
};

#define COLLISION_LEFT 0x01
#define COLLISION_RIGHT 0x02
#define COLLISION_FRONT (COLLISION_RIGHT | COLLISION_LEFT)

// 88 mph is ~40 m/s = 1 m/frame. Make 1.5 to make things more dramatic
#define MAX_SPEED_Z 1.5f
#define MAX_SPEED_X 2.f

struct SpriteDefinition
{
  uint8_t width;
  uint8_t height;
  const uint16_t* buffer;
};

#define MAX_FUEL (10000 << Z_POSITION_SHIFT)

struct CarInfo
{
  CarSprite sprite;
  int16_t posX; // 0 is the center of the road
  Z_POSITION posZ; // meters
  float speedZ; // meters / frame. Max 1
  float speedX;
  const uint16_t* lights;
  SpriteDefinition* fluxSprite;
  Gamebuino_Meta::Sound_FX engineFx[1];
  uint8_t engineFxDuration;
  bool fluxed; // goal reached
};

struct DepthInfo
{
  Z_POSITION z;
  float scaleFactor = 0;
  int32_t lineWidth = 0;
  int32_t lineRoadWidth = 0;
  int32_t lineRoadBumperWidth = 0;
};

struct RoadSegment
{
  ROAD_CURVATURE_X xCurvature;
  float zCurvature;
  Z_POSITION segmentStartZ;
};

struct SceneryObject
{
  int16_t posX; // 0 is the center of the road
  Z_POSITION posZ;
  SpriteDefinition* sprite;
};

struct Jerrican
{
  int16_t posX; // 0 is the center of the road
  Z_POSITION posZ;
  SpriteDefinition* sprite;
  bool visible;
};

struct StaticObstacle
{
  int16_t posX; // 0 is the center of the road
  Z_POSITION posZ;
  SpriteDefinition* sprite;
  uint32_t validUntil; 
};

#define OBJECT_VALIDITY 400

struct MovingObstacle
{
  int16_t posX; // 0 is the center of the road
  Z_POSITION posZ;
  float speedZ; // meters / frame. Max 1
  SpriteDefinition* sprite;  
};

struct BonusStar
{
  int16_t posX; // 0 is the center of the road
  Z_POSITION posZ;
  float speedZ; // meters / frame. Max 1
  SpriteDefinition* sprite;
  bool visible;
};

struct Drawable
{
  int32_t xStart;
  int32_t yStart;
  uint32_t yEnd;
  uint32_t zoomPattern;
  uint32_t yZoomPattern;
  SpriteDefinition* sprite; 
  Drawable* next; // for Drawable sorting
  bool removable;
};

struct LevelContext
{
  DepthInfo* depthLevels;
  uint32_t* lineToDepthLevel;
  int16_t* depthLevelToX;
  uint16_t* trackPalette;
  RoadSegment* segments;
  SpriteDefinition* carSprites;
  SpriteDefinition* speedSprites;
  SpriteDefinition* fuelSprites;
  SpriteDefinition* sprites;
  SceneryObject* sceneryObjects;
  StaticObstacle* staticObstacles;
  MovingObstacle* movingObstacles;
  Jerrican* jerrican;
  BonusStar* bonusStar;
  Drawable* drawables;
  const uint8_t* background;
  const uint32_t* backgroundPalette;
  uint16_t backgroundHeight;
  uint32_t remainingJerricans;
};

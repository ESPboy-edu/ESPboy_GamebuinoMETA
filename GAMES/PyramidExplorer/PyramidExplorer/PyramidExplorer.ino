#include <Gamebuino-Meta.h>
#include "assets/definitions.h"
#include "assets/sprites.h"
#include "assets/helpers.h"
#include "assets/sounds.h"
#include "assets/level_sketches.h"

int posX = 0;
int posY = 0;

int row = 0;
int column = 0;

int sRowIdx = 0;
int sColIdx = 0;

TileStruct CurrentPyramidLevel[15][15];
unsigned int CurrentTileSelectionBoard[7];
NewTileInfoStruct NewTileInfo = {0,0,0,0,false,0,0,0};
int GameDifficulty = DIFFICULTY_EASY;
int CurrentScene = SCENE_MAIN_MENU;
bool TileEventTriggered = true;
int PyramidLevel = 1;
int EndGameResult = END_GAME_NONE;
bool EventSoundProcessed = false;
bool NewHighScore = false;

//Player
int PlayerMaxHealth = 24;
int PlayerHealth = 24;
int PlayerMaxKnowledge = 6;
int PlayerKnowledge = 6;
int PlayerTreasureValue = 0;

void setup() {
  gb.begin();
  gb.save.config(savefileDefaults);
  for (int i = 0; i < 7; i++)
  {
    ScoreBoard[i]=gb.save.get(i);
  }
}

void loop() {
  while(!gb.update())
  gb.display.clear();
  gb.lights.clear();

  if (CurrentScene == SCENE_EXPLORATION)
  {
    CurrentScene = PyramidExplore();
  }
  else if (CurrentScene == SCENE_ADD_TILE)
  {
    CurrentScene = ExploreNewTile();
  }
  else if (CurrentScene == SCENE_EVENT)
  {
    CurrentScene = TileEvent();
  }
  else if (CurrentScene == SCENE_PAUSE_MENU)
  {
    CurrentScene = PauseMenu();
  }
  else if (CurrentScene == SCENE_MAIN_MENU)
  {
    CurrentScene = MainMenu();
  }
  else if (CurrentScene == SCENE_GAME_CONFIGURATION)
  {
    CurrentScene = ConfigureNewGame();
  }
  else if (CurrentScene == SCENE_END_GAME)
  {
    CurrentScene = EndGame();
  }
  else if (CurrentScene == SCENE_SCORE_BOARD)
  {
    CurrentScene = HighScoreBoard();
  }
  //debug();
}

void NewGame()
{
  memcpy(CurrentPyramidLevel, PyramidLevel1, sizeof(CurrentPyramidLevel));
  memcpy(CurrentTileSelectionBoard, TileSelectionBoard, sizeof(CurrentTileSelectionBoard));
  GameDifficulty = DIFFICULTY_EASY;
  sRowIdx = 0;
  sColIdx = 0;
  posX = 0;
  posY = 45;
  row = 5;
  column = 0;
  PlayerMaxHealth = 24;
  PlayerHealth = 24;
  PlayerMaxKnowledge = 6;
  PlayerKnowledge = 6;
  TileEventTriggered = true;
  PyramidLevel = 1;
  PlayerTreasureValue = 0;
  EndGameResult = END_GAME_NONE;
  NewTileInfo.MovingDirection = 0;
  NewTileInfo.Row = 0;
  NewTileInfo.Column = 0;
  NewTileInfo.SelectionCount = 0;
  NewTileInfo.EventId = TILE_EVENT_NONE;
  NewTileInfo.TreasureType = 0;
  NewTileInfo.TreasureValue = 0;
  NewHighScore = false;
  EventSoundProcessed = false;
}

void changeLevel()
{
  switch(PyramidLevel)
  {
    case 1:
      memcpy(CurrentPyramidLevel, PyramidLevel2, sizeof(CurrentPyramidLevel)); break;
    case 2:
      memcpy(CurrentPyramidLevel, PyramidLevel3, sizeof(CurrentPyramidLevel)); break;
    case 3:
      memcpy(CurrentPyramidLevel, PyramidLevel4, sizeof(CurrentPyramidLevel)); break;
    case 4:
      memcpy(CurrentPyramidLevel, PyramidLevel5, sizeof(CurrentPyramidLevel)); break;
    case 5:
      memcpy(CurrentPyramidLevel, PyramidLevel6, sizeof(CurrentPyramidLevel)); break;
    case 6:
      memcpy(CurrentPyramidLevel, PyramidLevel7, sizeof(CurrentPyramidLevel)); break;
  }

  if (PyramidLevel < 7)
  {
    PyramidLevel++;
  }

  sRowIdx = 0;
  sColIdx = 0;
  posX = 0;
  posY = 45;
  row = 5;
  column = 0;
  PlayerHealth = PlayerMaxHealth;
  PlayerKnowledge = PlayerMaxKnowledge;
  TileEventTriggered = true;
}

int knowledgeCost()
{
  switch (GameDifficulty)
  {
    case DIFFICULTY_EASY:
      return 1;
    case DIFFICULTY_NORMAL:
      return 2;
    case DIFFICULTY_HARD:
      return 2;
    default:
      return 2;
  }
}

int calculateDamageModifier(int baseDamage)
{
  int damageModifier = baseDamage;
  switch (GameDifficulty)
  {
    case DIFFICULTY_NORMAL:
      damageModifier += 1; break;
    case DIFFICULTY_HARD:
      damageModifier += 2; break;
  }

  switch (PyramidLevel)
  {
    case 3:
    case 4:
      damageModifier += 1; break;
    case 5:
    case 6:
      damageModifier += 2; break;
    case 7:
      damageModifier += 3; break;
  }

  return damageModifier;
}


bool compareAndUpdateTreasureScore()
{
  bool isScoreQualified=false;
  int temp = 0;
  int temp2 = 0;
  int index = 0;

  for (int i = 0; i < 7; i++)
  {
    if(PlayerTreasureValue > ScoreBoard[i])
    {
       temp = ScoreBoard[i];
       ScoreBoard[i] = PlayerTreasureValue;
       index = i;
       isScoreQualified = true;
       break;
    } 
  }

  if (isScoreQualified == false)
  {
    return false;
  }

  for (int i = index + 1; i < 7; i++)
  {
    temp2 = ScoreBoard[i];
    ScoreBoard[i] = temp;
    temp = temp2;
  }

  for (int i = 0; i < 7; i++)
  {
    gb.save.set(i,ScoreBoard[i]);
  }
  return isScoreQualified;
}

int expandedWidth = 7;
int expandedHeight = 8;

int PyramidExplore()
{
  bool forceEventAfterMove = false;
  if (gb.buttons.repeat(BUTTON_UP, 3))
  {
    if (posY != 0 && canMoveToTheNextTile(MOVE_UP) == true)
    {
      posY -= 9;
      row--;
      if (isNewTileExploration(MOVE_UP) == true)
      {
        return SCENE_ADD_TILE;
      }
      forceEventAfterMove = triggerAndForceTileEventIfNeeded(CurrentPyramidLevel[row][column].EventId);
    }
    else
    {
      if (sRowIdx > 0 && canMoveToTheNextTile(MOVE_UP) == true)
      {
        sRowIdx--;
        row--;
        if (isNewTileExploration(MOVE_UP) == true)
        {
          return SCENE_ADD_TILE;
        }
        forceEventAfterMove = triggerAndForceTileEventIfNeeded(CurrentPyramidLevel[row][column].EventId);
      }
    }
  }
  else if (gb.buttons.repeat(BUTTON_DOWN, 3))
  {
    if (posY != 54 && canMoveToTheNextTile(MOVE_DOWN) == true)
    {
      posY += 9;
      row++;
      if (isNewTileExploration(MOVE_DOWN) == true)
      {
        return SCENE_ADD_TILE;
      }
      forceEventAfterMove = triggerAndForceTileEventIfNeeded(CurrentPyramidLevel[row][column].EventId);
    }
    else
    {
      if (sRowIdx < expandedHeight && canMoveToTheNextTile(MOVE_DOWN) == true)
      {
        sRowIdx++;
        row++;
        if (isNewTileExploration(MOVE_DOWN) == true)
        {
          return SCENE_ADD_TILE;
        }
        forceEventAfterMove = triggerAndForceTileEventIfNeeded(CurrentPyramidLevel[row][column].EventId);
      }
    }
  }
  else if (gb.buttons.repeat(BUTTON_LEFT, 3))
  {
    if (posX != 0 && canMoveToTheNextTile(MOVE_LEFT) == true)
    {
      posX -= 9;
      column--;
      if (isNewTileExploration(MOVE_LEFT) == true)
      {
        return SCENE_ADD_TILE;
      }
      forceEventAfterMove = triggerAndForceTileEventIfNeeded(CurrentPyramidLevel[row][column].EventId);
    }
    else
    {
      if (sColIdx > 0 && canMoveToTheNextTile(MOVE_LEFT) == true)
      {
        sColIdx--;
        column--;
        if (isNewTileExploration(MOVE_LEFT) == true)
        {
          return SCENE_ADD_TILE;
        }
        forceEventAfterMove = triggerAndForceTileEventIfNeeded(CurrentPyramidLevel[row][column].EventId);
      }
    }
  }
  else if (gb.buttons.repeat(BUTTON_RIGHT, 3))
  {
    if (posX != 63 && canMoveToTheNextTile(MOVE_RIGHT) == true)
    {
      posX += 9;
      column++;
      if (isNewTileExploration(MOVE_RIGHT) == true)
      {
        return SCENE_ADD_TILE;
      }
      forceEventAfterMove = triggerAndForceTileEventIfNeeded(CurrentPyramidLevel[row][column].EventId);
    }
    else
    {
      if (sColIdx < expandedWidth && canMoveToTheNextTile(MOVE_RIGHT) == true)
      {
        sColIdx++;
        column++;
        if (isNewTileExploration(MOVE_RIGHT) == true)
        {
          return SCENE_ADD_TILE;
        }
        forceEventAfterMove = triggerAndForceTileEventIfNeeded(CurrentPyramidLevel[row][column].EventId);
      }
    }
  }
  else if (gb.buttons.pressed(BUTTON_MENU))
  {
    return SCENE_PAUSE_MENU;
  }
  
  DrawPyramidLevel();

  if (PlayerHealth == 0)
  {
    EndGameResult = END_GAME_DEFEAT;
    NewHighScore = compareAndUpdateTreasureScore();
    return SCENE_END_GAME;
  }

  if (forceEventAfterMove == true)
  {
    return SCENE_EVENT;
  }
  return SCENE_EXPLORATION;
}

bool isNewTileExploration(int movement)
{
  int currentTileId = CurrentPyramidLevel[row][column].Id;
  if (currentTileId != CORRIDOR_UNKNOWN)
  {
    return false;
  }

  prepareTileSelectionBoard(movement);
  NewTileInfo.MovingDirection = movement;
  NewTileInfo.Row = row;
  NewTileInfo.Column = column;
  NewTileInfo.SelectionCount = getCorridorSelectionCount(false);
  NewTileInfo.CanChangeSelection = (PlayerKnowledge - knowledgeCost()) >= 0;
  tryGenerateTileEvent();

  return true;
}

int getCorridorSelectionCount(bool knowledgeUsed)
{
  if (knowledgeUsed == true)
  {
    return 7;
  }

  switch(GameDifficulty)
  {
    case DIFFICULTY_EASY:
      return 3;
    case DIFFICULTY_NORMAL:
      return 2;
    case DIFFICULTY_HARD:
      return 1;
    default:
      return 1;
  }
}

void prepareTileSelectionBoard(int movement)
{
  memcpy(CurrentTileSelectionBoard, TileSelectionBoard, sizeof(CurrentTileSelectionBoard));

  switch(movement)
  {
    case MOVE_UP:
      fillTileSelectionBoard(TileSelectionUp); break;
    case MOVE_DOWN:
      fillTileSelectionBoard(TileSelectionDown); break;
    case MOVE_LEFT:
      fillTileSelectionBoard(TileSelectionLeft); break;
    case MOVE_RIGHT:
      fillTileSelectionBoard(TileSelectionRight); break;
  }
}

void prepareDirectionFullTileSelectionBoard(int movement)
{
  switch(movement)
  {
    case MOVE_UP:
      memcpy(CurrentTileSelectionBoard, TileSelectionUp, sizeof(CurrentTileSelectionBoard)); break;
    case MOVE_DOWN:
      memcpy(CurrentTileSelectionBoard, TileSelectionDown, sizeof(CurrentTileSelectionBoard)); break;
    case MOVE_LEFT:
      memcpy(CurrentTileSelectionBoard, TileSelectionLeft, sizeof(CurrentTileSelectionBoard)); break;
    case MOVE_RIGHT:
      memcpy(CurrentTileSelectionBoard, TileSelectionRight, sizeof(CurrentTileSelectionBoard)); break;
  }
}

void fillTileSelectionBoard(const unsigned int tilesArr[])
{
  int firstTileId = random(0,7);
  CurrentTileSelectionBoard[0] = tilesArr[firstTileId];

  if (GameDifficulty == DIFFICULTY_NORMAL || GameDifficulty == DIFFICULTY_EASY)
  {
    int secondDist = random(1,4);
    int secondTileId = firstTileId - secondDist;
    if (secondTileId < 0)
    {
      secondTileId = 7 + secondTileId;
    }

    CurrentTileSelectionBoard[1] = tilesArr[secondTileId];
  }

  if (GameDifficulty == DIFFICULTY_EASY)
  {
    int thirdDist = random(1,4);
    int thirdTileId = firstTileId + thirdDist;
    if (thirdTileId > 6)
    {
      thirdTileId = thirdTileId - 7;
    }

    CurrentTileSelectionBoard[2] = tilesArr[thirdTileId];
  }
}

bool canMoveToTheNextTile(int movement)
{
  int currentTileId = CurrentPyramidLevel[row][column].Id;
  bool canLeaveCurrentTile = checkMovementFrom(movement, currentTileId);

  if (canLeaveCurrentTile == false)
  {
    return false;
  }

  if (movement == MOVE_UP)
  {
    int nextRow = row - 1;
    if (nextRow < 0)
    {
      return false;
    }
    else
    {
      return checkMovementTo(movement, CurrentPyramidLevel[nextRow][column].Id, CurrentPyramidLevel[nextRow][column].EventId);
    }
  }
  else if (movement == MOVE_DOWN)
  {
    int nextRow = row + 1;
    if (nextRow > 14)
    {
      return false;
    }
    else
    {
      return checkMovementTo(movement, CurrentPyramidLevel[nextRow][column].Id, CurrentPyramidLevel[nextRow][column].EventId);
    }
  }
  else if (movement == MOVE_LEFT)
  {
    int nextColumn = column - 1;
    if (nextColumn < 0)
    {
      return false;
    }
    else
    {
      return checkMovementTo(movement, CurrentPyramidLevel[row][nextColumn].Id, CurrentPyramidLevel[row][nextColumn].EventId);
    }
  }
  else if (movement == MOVE_RIGHT)
  {
    int nextColumn = column + 1;
    if (nextColumn > 14)
    {
      return false;
    }
    else
    {
      return checkMovementTo(movement, CurrentPyramidLevel[row][nextColumn].Id, CurrentPyramidLevel[row][nextColumn].EventId);
    }
  }
  else
  {
    return false;
  }
}

bool checkMovementFrom(int movement, int tileId)
{
  if (tileId == CORRIDOR_CROSSROADS)
  {
    return true;
  }
  else if (tileId == CORRIDOR_STRAIGHT_HORIZONTAL && (movement == MOVE_LEFT || movement == MOVE_RIGHT))
  {
    return true;
  }
  else if (tileId == CORRIDOR_STRAIGHT_VERTICAL && (movement == MOVE_UP || movement == MOVE_DOWN))
  {
    return true;
  }
  else if (tileId == CORRIDOR_TURN_DOWN_LEFT && (movement == MOVE_DOWN || movement == MOVE_LEFT))
  {
    return true;
  }
  else if (tileId == CORRIDOR_TURN_DOWN_RIGHT && (movement == MOVE_DOWN || movement == MOVE_RIGHT))
  {
    return true;
  }
  else if (tileId == CORRIDOR_TURN_UP_LEFT && (movement == MOVE_UP || movement == MOVE_LEFT))
  {
    return true;
  }
  else if (tileId == CORRIDOR_TURN_UP_RIGHT && (movement == MOVE_UP || movement == MOVE_RIGHT))
  {
    return true;
  }
  else if (tileId == CORRIDOR_STRAIGHT_HORIZONTAL_UP && (movement == MOVE_UP || movement == MOVE_RIGHT || movement == MOVE_LEFT))
  {
    return true;
  }
  else if (tileId == CORRIDOR_STRAIGHT_HORIZONTAL_DOWN && (movement == MOVE_DOWN || movement == MOVE_RIGHT || movement == MOVE_LEFT))
  {
    return true;
  }
  else if (tileId == CORRIDOR_STRAIGHT_VERTICAL_LEFT && (movement == MOVE_UP || movement == MOVE_DOWN || movement == MOVE_LEFT))
  {
    return true;
  }
  else if (tileId == CORRIDOR_STRAIGHT_VERTICAL_RIGHT && (movement == MOVE_UP || movement == MOVE_DOWN || movement == MOVE_RIGHT))
  {
    return true;
  }
  return false; //CORRIDOR_BLOCKED
}

bool checkMovementTo(int movement, int tileId, int tileEventId)
{
  if (tileEventId == TILE_EVENT_BARS)
  {
    return false;  
  }
  
  if (tileId == CORRIDOR_UNKNOWN)
  {
    return true;
  }
  else if (tileId == CORRIDOR_CROSSROADS)
  {
    return true;
  }
  else if (tileId == CORRIDOR_STRAIGHT_HORIZONTAL && (movement == MOVE_LEFT || movement == MOVE_RIGHT))
  {
    return true;
  }
  else if (tileId == CORRIDOR_STRAIGHT_VERTICAL && (movement == MOVE_UP || movement == MOVE_DOWN))
  {
    return true;
  }
  else if (tileId == CORRIDOR_TURN_DOWN_LEFT && (movement == MOVE_UP || movement == MOVE_RIGHT))
  {
    return true;
  }
  else if (tileId == CORRIDOR_TURN_DOWN_RIGHT && (movement == MOVE_UP || movement == MOVE_LEFT))
  {
    return true;
  }
  else if (tileId == CORRIDOR_TURN_UP_LEFT && (movement == MOVE_DOWN || movement == MOVE_RIGHT))
  {
    return true;
  }
  else if (tileId == CORRIDOR_TURN_UP_RIGHT && (movement == MOVE_DOWN || movement == MOVE_LEFT))
  {
    return true;
  }
  else if (tileId == CORRIDOR_STRAIGHT_HORIZONTAL_UP && (movement == MOVE_DOWN || movement == MOVE_RIGHT || movement == MOVE_LEFT))
  {
    return true;
  }
  else if (tileId == CORRIDOR_STRAIGHT_HORIZONTAL_DOWN && (movement == MOVE_UP || movement == MOVE_RIGHT || movement == MOVE_LEFT))
  {
    return true;
  }
  else if (tileId == CORRIDOR_STRAIGHT_VERTICAL_LEFT && (movement == MOVE_UP || movement == MOVE_DOWN || movement == MOVE_RIGHT))
  {
    return true;
  }
  else if (tileId == CORRIDOR_STRAIGHT_VERTICAL_RIGHT && (movement == MOVE_UP || movement == MOVE_DOWN || movement == MOVE_LEFT))
  {
    return true;
  }
  return false; //CORRIDOR_BLOCKED
}


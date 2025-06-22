int selectedCorridorIdx = 0;
int mainMenuSelectionIdx = 0;
int configurationSelectionIdx = 0;

int PauseMenu()
{
  if (gb.buttons.pressed(BUTTON_MENU))
  {
    return SCENE_EXPLORATION;
  }
  if (gb.buttons.pressed(BUTTON_B))
  {
    EndGameResult = END_GAME_DEFEAT;
    NewHighScore = compareAndUpdateTreasureScore();
    return SCENE_END_GAME;
  }
  
  DrawPauseMenu();
  return SCENE_PAUSE_MENU;
}

int EndGame()
{
  if (gb.buttons.pressed(BUTTON_A))
  {
    return SCENE_MAIN_MENU;
  }
  DrawEndGame();
  return SCENE_END_GAME;
}

int HighScoreBoard()
{
  if (gb.buttons.pressed(BUTTON_B))
  {
    return SCENE_MAIN_MENU;
  }
  DrawHighScoreBoard();
  return SCENE_SCORE_BOARD;
}

int MainMenu()
{
  if (gb.buttons.pressed(BUTTON_A))
  {
    if (mainMenuSelectionIdx == MAIN_MENU_NEW_GAME)
    {
      NewGame();
      mainMenuSelectionIdx = MAIN_MENU_NEW_GAME;
      return SCENE_GAME_CONFIGURATION;
    }
    else
    {
      mainMenuSelectionIdx = MAIN_MENU_NEW_GAME;
      return SCENE_SCORE_BOARD;
    }
  }
  else if (gb.buttons.pressed(BUTTON_UP))
  {
    gb.sound.fx(selectionSfx);
    if (mainMenuSelectionIdx == 0)
    {
      mainMenuSelectionIdx = 1;
    }
    else
    {
      mainMenuSelectionIdx = 0;
    }
  }
  else if (gb.buttons.pressed(BUTTON_DOWN))
  {
    gb.sound.fx(selectionSfx);
    if (mainMenuSelectionIdx == 0)
    {
      mainMenuSelectionIdx = 1;
    }
    else
    {
      mainMenuSelectionIdx = 0;
    }
  }
  
  DrawMainMenu(mainMenuSelectionIdx);
  return SCENE_MAIN_MENU;
}

int ConfigureNewGame()
{
  if (gb.buttons.pressed(BUTTON_A))
  {
    PlayerHealth = PlayerMaxHealth;
    PlayerKnowledge = PlayerMaxKnowledge;
    configurationSelectionIdx = CONFIGURATION_DIFFICULTY;
    return SCENE_EXPLORATION;
  }
  else if (gb.buttons.pressed(BUTTON_B))
  {
    configurationSelectionIdx = CONFIGURATION_DIFFICULTY;
    return SCENE_MAIN_MENU;
  }
  else if (gb.buttons.pressed(BUTTON_UP))
  {
    gb.sound.fx(selectionSfx);
    changeConfigurationType();
  }
  else if (gb.buttons.pressed(BUTTON_DOWN))
  {
    gb.sound.fx(selectionSfx);
    changeConfigurationType();
  }
  else if (gb.buttons.pressed(BUTTON_LEFT))
  {
    gb.sound.fx(selectionSfx);
    changeConfigurationParameter(CHANGE_DECREASE);
  }
  else if (gb.buttons.pressed(BUTTON_RIGHT))
  {
    gb.sound.fx(selectionSfx);
    changeConfigurationParameter(CHANGE_INCREASE);
  }
  
  DrawGameConfiguration(configurationSelectionIdx);
  return SCENE_GAME_CONFIGURATION;
}

void changeConfigurationType()
{
  if (configurationSelectionIdx == CONFIGURATION_DIFFICULTY)
  {
    configurationSelectionIdx = CONFIGURATION_STATS;
  }
  else
  {
    configurationSelectionIdx = CONFIGURATION_DIFFICULTY;
  }
}

void changeConfigurationParameter(int changeMethod)
{
  if (configurationSelectionIdx == CONFIGURATION_DIFFICULTY && changeMethod == CHANGE_INCREASE)
  {
    if (GameDifficulty < 3)
    {
      GameDifficulty++;
    }
    else
    {
      GameDifficulty = 1;
    }
  }
  else if (configurationSelectionIdx == CONFIGURATION_DIFFICULTY && changeMethod == CHANGE_DECREASE)
  {
    if (GameDifficulty > 1)
    {
      GameDifficulty--;
    }
    else
    {
      GameDifficulty = 3;
    }
  }

  if (configurationSelectionIdx == CONFIGURATION_STATS && changeMethod == CHANGE_INCREASE)
  {
    if (PlayerMaxHealth < 32)
    {
      PlayerMaxHealth +=4;
      PlayerMaxKnowledge--;
    }
  }
  else if (configurationSelectionIdx == CONFIGURATION_STATS && changeMethod == CHANGE_DECREASE)
  {
    if (PlayerMaxHealth > 16)
    {
      PlayerMaxHealth -= 4;
      PlayerMaxKnowledge++;
    }
  }
}

int ExploreNewTile()
{
  if (gb.buttons.pressed(BUTTON_A))
  {
    CurrentPyramidLevel[NewTileInfo.Row][NewTileInfo.Column].Id = CurrentTileSelectionBoard[selectedCorridorIdx];
    selectedCorridorIdx = 0;
    if (NewTileInfo.EventId == TILE_EVENT_NONE)
    {
      NewTileInfo.MovingDirection = 0;
      NewTileInfo.Row = 0;
      NewTileInfo.Column = 0;
      NewTileInfo.SelectionCount = 0;
      NewTileInfo.CanChangeSelection = false;
      NewTileInfo.EventId = 0;
      NewTileInfo.TreasureType = 0;
      NewTileInfo.TreasureValue = 0;
      return SCENE_EXPLORATION;
    }
    signalEventType();
    return SCENE_EVENT;
  }
  else if (gb.buttons.pressed(BUTTON_B) && NewTileInfo.CanChangeSelection == true)
  {
    prepareDirectionFullTileSelectionBoard(NewTileInfo.MovingDirection);
    NewTileInfo.SelectionCount = getCorridorSelectionCount(true);
    NewTileInfo.EventId = TILE_EVENT_NONE;
    NewTileInfo.CanChangeSelection = false;
    PlayerKnowledge = PlayerKnowledge - knowledgeCost();
    gb.sound.fx(useKnowledgeSfx);
    gb.lights.fill(BLUE);
  }
  else if (gb.buttons.pressed(BUTTON_LEFT))
  {
    gb.sound.fx(selectionSfx);
    if (selectedCorridorIdx > 0)
    {
      selectedCorridorIdx--;
    }
    else
    {
      selectedCorridorIdx = NewTileInfo.SelectionCount - 1;
    }
  }
  else if (gb.buttons.pressed(BUTTON_RIGHT))
  {
    gb.sound.fx(selectionSfx);
    if (selectedCorridorIdx < NewTileInfo.SelectionCount - 1)
    {
      selectedCorridorIdx++;
    }
    else
    {
      selectedCorridorIdx = 0;
    }
  }

  DrawCorridorSelection(selectedCorridorIdx, NewTileInfo.CanChangeSelection);
  return SCENE_ADD_TILE;
}

void signalEventType()
{
  switch(NewTileInfo.EventId)
  {
    case TILE_EVENT_SNAKES:
    case TILE_EVENT_MUMMY:
    case TILE_EVENT_TRAP:
    case TILE_EVENT_BARS:
      gb.lights.fill(RED); break;
    case TILE_EVENT_TREASURE:
      gb.lights.fill(YELLOW); break;
    case TILE_EVENT_HIEROGLYPHICS:
      gb.lights.fill(BLUE); break;
  }
}

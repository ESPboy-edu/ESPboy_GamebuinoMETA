
int TileEvent()
{
  bool eventProcessed = false;

  if (EventSoundProcessed == false)
  {
    processEventSound();
    EventSoundProcessed = true;
  }
  
  switch(NewTileInfo.EventId)
  {
    case TILE_EVENT_SNAKES:
      eventProcessed = processTileEventSnakes(); break;
    case TILE_EVENT_MUMMY:
      eventProcessed = processTileEventMummy(); break;
    case TILE_EVENT_HIEROGLYPHICS:
      eventProcessed = processTileEventHieroglyphics(); break;
    case TILE_EVENT_TRAP:
      eventProcessed = processTileEventTrap(); break;
    case TILE_EVENT_BARS:
      eventProcessed = processTileEventBars(); break;
    case TILE_EVENT_STAIRS:
      eventProcessed = processTileEventStairs(); break;
    case TILE_EVENT_TREASURE:
      eventProcessed = processTileEventTreasure(); break;
    case TILE_EVENT_PHAROAH:
      eventProcessed = processTileEventPharoah(); break;
    default:
      eventProcessed = true; break;
  }

  if (eventProcessed == true)
  {
    if (NewTileInfo.EventId == TILE_EVENT_PHAROAH)
    {
      EndGameResult = END_GAME_VICTORY;
      EventSoundProcessed = false;
      return SCENE_END_GAME;
    }
    else if ((NewTileInfo.EventId == TILE_EVENT_MUMMY || NewTileInfo.EventId == TILE_EVENT_SNAKES) && PlayerHealth == 0)
    {
      EndGameResult = END_GAME_DEFEAT;
      EventSoundProcessed = false;
      return SCENE_END_GAME;
    }
    
    NewTileInfo.MovingDirection = 0;
    NewTileInfo.Row = 0;
    NewTileInfo.Column = 0;
    NewTileInfo.SelectionCount = 0;
    NewTileInfo.EventId = TILE_EVENT_NONE;
    NewTileInfo.TreasureType = 0;
    NewTileInfo.TreasureValue = 0;
    EventSoundProcessed = false;
    
    return SCENE_EXPLORATION;
  }

  return SCENE_EVENT;
}

void processEventSound()
{
  switch(NewTileInfo.EventId)
  {
    case TILE_EVENT_SNAKES:
    case TILE_EVENT_MUMMY:
    case TILE_EVENT_TRAP:
    case TILE_EVENT_BARS:
      gb.sound.fx(negativeEventSfx); break;
    case TILE_EVENT_TREASURE:
    case TILE_EVENT_HIEROGLYPHICS:
      gb.sound.fx(positiveEventSfx); break;
  }
}

bool processTileEventSnakes()
{
  if (gb.buttons.pressed(BUTTON_A))
  {
    triggerTileEventSnakes();
    CurrentPyramidLevel[NewTileInfo.Row][NewTileInfo.Column].EventId = TILE_EVENT_SNAKES;
    return true;
  }

  DrawTileEventSnakes();
  return false;
}

bool processTileEventMummy()
{
  if (gb.buttons.pressed(BUTTON_A))
  {
    triggerTileEventMummy();
    CurrentPyramidLevel[NewTileInfo.Row][NewTileInfo.Column].EventId = TILE_EVENT_MUMMY;
    return true;
  }

  DrawTileEventMummy();
  return false;
}

bool processTileEventHieroglyphics()
{
  int knowledge = knowledgeCost() + 1;
  if (gb.buttons.pressed(BUTTON_A))
  {
    PlayerKnowledge += knowledge;
    if (PlayerKnowledge > PlayerMaxKnowledge)
    {
      PlayerKnowledge = PlayerMaxKnowledge;
    }
    return true;
  }

  DrawTileEventHieroglyphics(knowledge);
  return false;
}

bool processTileEventTrap()
{
  if (gb.buttons.pressed(BUTTON_A))
  {
    triggerTileEventTrap();
    CurrentPyramidLevel[NewTileInfo.Row][NewTileInfo.Column].EventId = TILE_EVENT_TRAP;
    return true;
  }

  DrawTileEventTrap();
  return false;
}

bool processTileEventBars()
{
  if (gb.buttons.pressed(BUTTON_A))
  {
    switch(NewTileInfo.MovingDirection)
    {
      case MOVE_UP:
        row++; posY += 9; break;
      case MOVE_DOWN:
        row--; posY -= 9; break;
      case MOVE_LEFT:
        column++; posX +=9; break;
      case MOVE_RIGHT:
        column--; posX -=9; break;
    }
    CurrentPyramidLevel[NewTileInfo.Row][NewTileInfo.Column].EventId = TILE_EVENT_BARS;
    return true;
  }

  DrawTileEventBars();
  return false;
}

bool processTileEventStairs()
{
  if (gb.buttons.pressed(BUTTON_A))
  {
    changeLevel();
    return true;
  }

  DrawTileEventStairs();
  return false;
}

bool processTileEventPharoah()
{
  if (gb.buttons.pressed(BUTTON_A))
  {
    PlayerTreasureValue += NewTileInfo.TreasureValue;
    NewHighScore = compareAndUpdateTreasureScore();
    return true;
  }

  DrawTileEventPharoah(NewTileInfo.TreasureValue);
  return false;
}

bool processTileEventTreasure()
{
  if (gb.buttons.pressed(BUTTON_A))
  {
    PlayerTreasureValue += NewTileInfo.TreasureValue;
    return true;
  }

  DrawTileEventTreasure(NewTileInfo.TreasureType, NewTileInfo.TreasureValue);
  return false;
}

void tryGenerateTileEvent()
{
  if (TileEventTriggered == true)
  {
    TileEventTriggered = false;
    NewTileInfo.EventId = TILE_EVENT_NONE;
    return;
  }

  TileEventTriggered = true;
  int eventResult = random(0,6);
  if (eventResult == 1 || eventResult == 4)
  {
    NewTileInfo.EventId = TILE_EVENT_NONE;
    return;
  }
  
  int eventSelectionIdx = random(0,8);
  NewTileInfo.EventId = TileEventBoard[eventSelectionIdx];

  if (NewTileInfo.EventId == TILE_EVENT_TREASURE)
  {
    int treasureTypeResult = random(1,7);
    if (treasureTypeResult == 2 || treasureTypeResult == 4 || treasureTypeResult == 6)
    {
      NewTileInfo.TreasureType = TREASURE_TYPE_SARCOPHAGUS;
      NewTileInfo.TreasureValue = treasureTypeResult * 5;
    }
    else
    {
      NewTileInfo.TreasureType = TREASURE_TYPE_JEWELLRY;
      int treasureModifier = PlayerKnowledge;
      if (treasureModifier <= 0)
      {
        treasureModifier = 1;
      }

      NewTileInfo.TreasureValue = treasureModifier * 10;
    }
  }
}

void triggerTileEventTrap()
{
  posX = 0;
  posY = 45;
  row = 5;
  column = 0;
  sRowIdx = 0;
  sColIdx = 0;
}

void triggerTileEventSnakes()
{
  PlayerHealth -= calculateDamageModifier(1);
  if (PlayerHealth < 0)
  {
    PlayerHealth = 0;
  }
}

void triggerTileEventMummy()
{
  PlayerHealth -= calculateDamageModifier(2);
  PlayerKnowledge -= 1;
  if (PlayerHealth < 0)
  {
    PlayerHealth = 0;
  }

  if (PlayerKnowledge < 0)
  {
    PlayerKnowledge = 0;
  }
}

bool triggerAndForceTileEventIfNeeded(int tileEventId)
{
  if (tileEventId == TILE_EVENT_TRAP) //Place player at the level entrance
  {
    triggerTileEventTrap();
    gb.sound.fx(damageSfx);
    gb.lights.fill(RED);
  }
  else if (tileEventId == TILE_EVENT_SNAKES)
  {
    triggerTileEventSnakes();
    gb.sound.fx(damageSfx);
    gb.lights.fill(RED);
  }
  else if (tileEventId == TILE_EVENT_MUMMY)
  {
    triggerTileEventMummy();
    gb.sound.fx(damageSfx);
    gb.lights.fill(RED);
  }
  else if (tileEventId == TILE_EVENT_STAIRS)
  {
    NewTileInfo.EventId = TILE_EVENT_STAIRS;
    gb.sound.fx(positiveEventSfx);
    gb.lights.fill(GREEN);
    return true;
  }
  else if (tileEventId == TILE_EVENT_PHAROAH)
  {
    NewTileInfo.EventId = TILE_EVENT_PHAROAH;
    NewTileInfo.TreasureType = TREASURE_TYPE_JEWELLRY;
    int treasureModifier = PlayerKnowledge;
    if (treasureModifier <= 0)
    {
      treasureModifier = 1;
    }
    NewTileInfo.TreasureValue = treasureModifier * 15;
    gb.sound.fx(positiveEventSfx);
    gb.lights.fill(YELLOW);
    return true;
  }

  return false;
}

Image PlayerCursor(IMAGE_PLAYER_CURSOR);
Image CorridorSelectionCursor(IMAGE_CORRIDOR_SELECTION_CURSOR);
Image TileEventMummy(IMAGE_TILE_EVENT_MUMMY);
Image TileEventSnake(IMAGE_TILE_EVENT_SNAKE);
Image Torch(IMAGE_TORCH);
Image PlayerMapPointer(IMAGE_PLAYER_MAP_POINTER);

void DrawPyramidLevel()
{
  for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 7; j++)
    {
      TileStruct tile = CurrentPyramidLevel[j + sRowIdx][i + sColIdx];
      drawTile(tile.Id, i * 9, j * 9);
      drawTileEvent(tile.EventId, i * 9, j * 9);
    }
  }
  gb.display.drawImage(73, 5, IMAGE_HEALTH_MARKER, 5, 5);
  gb.display.setColor(RED);
  drawNumberVertical(74, 11, PlayerHealth);
  gb.display.drawImage(73, 25, IMAGE_LORE_MARKER, 5, 5);
  gb.display.setColor(BLUE);
  drawNumberVertical(74, 31, PlayerKnowledge);
  
  gb.display.drawImage(posX, posY, PlayerCursor);
}

void drawNumberVertical(int posX, int posY, int number)
{
  if (number < 10)
  {
    gb.display.setCursor(posX, posY);
    gb.display.println((String)number);
  }
  else
  {
    int single = number % 10;
    int tens = (number - single) / 10;

    gb.display.setCursor(posX, posY);
    gb.display.println((String)tens);
    gb.display.setCursor(posX, posY + 6);
    gb.display.println((String)single);
  }
}

void DrawCorridorSelection(int selectedCorridorIdx, bool canChangeSelection)
{
  gb.display.drawImage(0, 0, IMAGE_MAIN_THEME, 80, 64);
  gb.display.setColor(BLACK);
  gb.display.fillRect(0, 23, 80, 13);
  gb.display.setColor(WHITE);
  gb.display.setCursor(4,3);
  gb.display.println("CORRIDOR SELECTION");
  int posX = 2;
  for(int i = 0; i < 7; i ++)
  {
    if (CurrentTileSelectionBoard[i] != 0)
    {
      drawTile(CurrentTileSelectionBoard[i], posX, 25);
    }
    posX += 11;
  }
  gb.display.drawImage(2, 55, IMAGE_BUTTON_A, 7, 7);
  gb.display.setColor(GRAY);
  gb.display.setCursor(12, 56);
  gb.display.println("select");
  if (canChangeSelection == true)
  {
    gb.display.drawImage(41, 55, IMAGE_BUTTON_B, 7, 7);
    gb.display.setColor(GRAY);
    gb.display.setCursor(51, 56);
    gb.display.println("use map");
  }

  gb.display.drawImage(1 + (selectedCorridorIdx * 11), 24, CorridorSelectionCursor);
}

void DrawTileEventSnakes()
{
  gb.display.drawImage(0, 0, IMAGE_MAIN_THEME, 80, 64);
  gb.display.setColor(WHITE);
  gb.display.setCursor(19, 3);
  gb.display.println("SNAKES LAIR");
  
  gb.display.drawImage(2, 11, Torch, 9, 11);
  DrawTileEventImage(TILE_EVENT_SNAKES, 30, 11);
  gb.display.drawImage(70, 11, Torch, 9, 11);
  gb.display.setColor(WHITE);
  
  gb.display.setCursor(0, 25);
  gb.display.println("You stepped into thesnakes nest.");
  gb.display.drawImage(33, 40, IMAGE_HEALTH_MARKER, 5, 5);
  gb.display.setColor(RED);
  gb.display.setCursor(40, 40);
  gb.display.println("-" + (String)calculateDamageModifier(1));
  
  gb.display.drawImage(5, 55, IMAGE_BUTTON_A, 7, 7);
  gb.display.setColor(GRAY);
  gb.display.setCursor(15, 56);
  gb.display.println("continue");
}

void DrawTileEventMummy()
{
  gb.display.drawImage(0, 0, IMAGE_MAIN_THEME, 80, 64);
  gb.display.setColor(WHITE);
  gb.display.setCursor(7, 3);
  gb.display.println("MUMMY SARCOPHAGUS");
  
  gb.display.drawImage(2, 11, Torch, 9, 11);
  DrawTileEventImage(TILE_EVENT_MUMMY, 30, 11);
  gb.display.drawImage(70, 11, Torch, 9, 11);
  gb.display.setColor(WHITE);

  gb.display.setCursor(0, 25);
  gb.display.println("Mummy attacks you.");
  gb.display.drawImage(33, 40, IMAGE_HEALTH_MARKER, 5, 5);
  gb.display.setColor(RED);
  gb.display.setCursor(40, 40);
  gb.display.println("-" + (String)calculateDamageModifier(2));
  gb.display.drawImage(33, 46, IMAGE_LORE_MARKER, 5, 5);
  gb.display.setColor(BLUE);
  gb.display.setCursor(40, 46);
  gb.display.println("-1");
  
  gb.display.drawImage(5, 55, IMAGE_BUTTON_A, 7, 7);
  gb.display.setColor(GRAY);
  gb.display.setCursor(15, 56);
  gb.display.println("continue");
}

void DrawTileEventHieroglyphics(int knowledge)
{
  gb.display.drawImage(0, 0, IMAGE_MAIN_THEME, 80, 64);
  gb.display.setColor(WHITE);
  gb.display.setCursor(4, 3);
  gb.display.println("HIEROGLYPHICS ROOM");

  gb.display.drawImage(2, 11, Torch, 9, 11);
  DrawTileEventImage(TILE_EVENT_HIEROGLYPHICS, 30, 11);
  gb.display.drawImage(70, 11, Torch, 9, 11);
  gb.display.setColor(WHITE);

  gb.display.setCursor(0, 25);
  gb.display.println("You have found the  pyramid map.");
  gb.display.drawImage(33, 40, IMAGE_LORE_MARKER, 5, 5);
  gb.display.setColor(BLUE);
  gb.display.setCursor(40, 40);
  gb.display.println("+" + (String)knowledge);
  
  gb.display.drawImage(5, 55, IMAGE_BUTTON_A, 7, 7);
  gb.display.setColor(GRAY);
  gb.display.setCursor(15, 56);
  gb.display.println("continue");
}

void DrawTileEventTrap()
{
  gb.display.drawImage(0, 0, IMAGE_MAIN_THEME, 80, 64);
  gb.display.setColor(WHITE);
  gb.display.setCursor(20, 3);
  gb.display.println("FLOOR TRAP");

  gb.display.drawImage(2, 11, Torch, 9, 11);
  DrawTileEventImage(TILE_EVENT_TRAP, 30, 11);
  gb.display.drawImage(70, 11, Torch, 9, 11);
  gb.display.setColor(WHITE);

  gb.display.setCursor(0, 25);
  gb.display.println("You have felled intothe trap which leadsto the entrance.");
  
  gb.display.drawImage(5, 55, IMAGE_BUTTON_A, 7, 7);
  gb.display.setColor(GRAY);
  gb.display.setCursor(15, 56);
  gb.display.println("continue");
}

void DrawTileEventBars()
{
  gb.display.drawImage(0, 0, IMAGE_MAIN_THEME, 80, 64);
  gb.display.setColor(WHITE);
  gb.display.setCursor(10, 3);
  gb.display.println("BARRED CORRIDOR");

  gb.display.drawImage(2, 11, Torch, 9, 11);
  DrawTileEventImage(TILE_EVENT_BARS, 30, 11);
  gb.display.drawImage(70, 11, Torch, 9, 11);
  gb.display.setColor(WHITE);

  gb.display.setCursor(0, 25);
  gb.display.println("The corridor is     blocked by the bars.You cannot move     further.");
  
  gb.display.drawImage(5, 55, IMAGE_BUTTON_A, 7, 7);
  gb.display.setColor(GRAY);
  gb.display.setCursor(15, 56);
  gb.display.println("continue");
}

void DrawTileEventStairs()
{
  gb.display.drawImage(0, 0, IMAGE_MAIN_THEME, 80, 64);
  gb.display.setColor(WHITE);
  gb.display.setCursor(28, 3);
  gb.display.println("STAIRS");

  gb.display.drawImage(2, 11, Torch, 9, 11);
  DrawTileEventImage(TILE_EVENT_STAIRS, 30, 11);
  gb.display.drawImage(70, 11, Torch, 9, 11);
  gb.display.setColor(WHITE);

  gb.display.setCursor(0, 25);
  gb.display.println("You have found the  stairs which leads  to the upper level.");
  
  gb.display.drawImage(5, 55, IMAGE_BUTTON_A, 7, 7);
  gb.display.setColor(GRAY);
  gb.display.setCursor(15, 56);
  gb.display.println("continue");
}

void DrawTileEventPharoah(int treasureValue)
{
  gb.display.drawImage(0, 0, IMAGE_MAIN_THEME, 80, 64);
  gb.display.setColor(WHITE);
  gb.display.setCursor(15, 3);
  gb.display.println("PHAROAHS TOMB");

  gb.display.drawImage(2, 11, Torch, 9, 11);
  DrawTileEventImage(TILE_EVENT_PHAROAH, 30, 11);
  gb.display.drawImage(70, 11, Torch, 9, 11);
  gb.display.setColor(WHITE);

  gb.display.setCursor(0, 25);
  gb.display.println("You have reached theroyal tomb. Your    quest is completed.");

  gb.display.drawImage(28, 45, IMAGE_TREASURE_MARKER, 5, 5);
  gb.display.setColor(YELLOW);
  gb.display.setCursor(35, 45);
  gb.display.println("+" + (String)treasureValue);
  
  gb.display.drawImage(5, 55, IMAGE_BUTTON_A, 7, 7);
  gb.display.setColor(GRAY);
  gb.display.setCursor(15, 56);
  gb.display.println("finish game");
}

void DrawTileEventTreasure(int treasureType, int treasureValue)
{
  gb.display.drawImage(0, 0, IMAGE_MAIN_THEME, 80, 64);
  gb.display.setColor(WHITE);
  if (treasureType == TREASURE_TYPE_SARCOPHAGUS)
  {
    gb.display.setCursor(0, 3);
    gb.display.println("TREASURE-SARCOPHAGUS");
  }
  else
  {
    gb.display.setCursor(2, 3);
    gb.display.println("TREASURE - JEWELLRY");
  }

  gb.display.drawImage(2, 11, Torch, 9, 11);
  DrawTreasureEventImage(treasureType, 30, 11);
  gb.display.drawImage(70, 11, Torch, 9, 11);
  gb.display.setColor(WHITE);

  gb.display.setCursor(0, 25);
  gb.display.println("You have found the  treasure.");
  gb.display.drawImage(28, 40, IMAGE_TREASURE_MARKER, 5, 5);
  gb.display.setColor(YELLOW);
  gb.display.setCursor(35, 40);
  gb.display.println("+" + (String)treasureValue);
  
  gb.display.drawImage(5, 55, IMAGE_BUTTON_A, 7, 7);
  gb.display.setColor(GRAY);
  gb.display.setCursor(15, 56);
  gb.display.println("continue");
}

void DrawTileEventImage(int eventId, int posX, int posY)
{
  switch(eventId)
  {
    case TILE_EVENT_STAIRS:
      gb.display.drawImage(posX, posY, IMAGE_EVENT_STAIRS, 20, 11); break;
    case TILE_EVENT_SNAKES:
      gb.display.drawImage(posX, posY, IMAGE_EVENT_SNAKE, 20, 11); break;
    case TILE_EVENT_BARS:
      gb.display.drawImage(posX, posY, IMAGE_EVENT_BARS, 20, 11); break;
    case TILE_EVENT_TRAP:
      gb.display.drawImage(posX, posY, IMAGE_EVENT_TRAP, 20, 11); break;
    case TILE_EVENT_MUMMY:
      gb.display.drawImage(posX, posY, IMAGE_EVENT_MUMMY, 20, 11); break;
    case TILE_EVENT_HIEROGLYPHICS:
      gb.display.drawImage(posX, posY, IMAGE_EVENT_HIEROGLYPHICS, 20, 11); break;
    case TILE_EVENT_PHAROAH:
      gb.display.drawImage(posX, posY, IMAGE_EVENT_PHAROAH, 20, 11); break;
    default:
      break;
  }
}

void DrawTreasureEventImage(int treasureType, int posX, int posY)
{
  if (treasureType == TREASURE_TYPE_SARCOPHAGUS)
  {
    gb.display.drawImage(posX, posY, IMAGE_EVENT_TREASURE_SARCOPHAGUS, 20, 11);
  }
  else
  {
    gb.display.drawImage(posX, posY, IMAGE_EVENT_TREASURE_JEWELLRY, 20, 11);
  }
}

void DrawMainMenu(int selectionIdx)
{
  gb.display.drawImage(0, 0, IMAGE_MAIN_THEME, 80, 64);
  gb.display.drawImage(0, 2, IMAGE_MAIN_TITLE, 80, 24);
  gb.display.setColor(WHITE);
  gb.display.setCursor(20, 35);
  gb.display.println("NEW GAME");
  gb.display.setCursor(20, 42);
  gb.display.println("HIGH SCORES");
  gb.display.drawImage(12, 35 + (selectionIdx * 7), IMAGE_SELECTION_MARKER, 5, 5);

  gb.display.drawImage(5, 55, IMAGE_BUTTON_CROSS, 7, 7);
  gb.display.setColor(GRAY);
  gb.display.setCursor(15, 56);
  gb.display.println("switch");

  gb.display.drawImage(45, 55, IMAGE_BUTTON_A, 7, 7);
  gb.display.setColor(GRAY);
  gb.display.setCursor(55, 56);
  gb.display.println("select");
}

void DrawHighScoreBoard()
{
  gb.display.drawImage(0, 0, IMAGE_MAIN_THEME, 80, 64);
  gb.display.setColor(WHITE);
  gb.display.setCursor(20, 3);
  gb.display.println("HIGH SCORES");

  for (int i = 0; i < 7; i++)
  {
    gb.display.setCursor(18, 10 + (i * 6));
    gb.display.setColor(YELLOW);
    gb.display.println((String)(i + 1) + ".");
    gb.display.drawImage(28, 10 + (i * 6), IMAGE_TREASURE_MARKER, 5, 5);
    gb.display.setColor(YELLOW);
    gb.display.setCursor(35, 10 + (i * 6));
    gb.display.println((String)ScoreBoard[i]);
  }

  gb.display.drawImage(5, 55, IMAGE_BUTTON_B, 7, 7);
  gb.display.setColor(GRAY);
  gb.display.setCursor(15, 56);
  gb.display.println("return");
}

void DrawGameConfiguration(int selectionIdx)
{
  gb.display.drawImage(0, 0, IMAGE_MAIN_THEME, 80, 64);
  gb.display.setColor(WHITE);
  gb.display.setCursor(4, 3);
  gb.display.println("GAME CONFIGURATION");
  gb.display.setCursor(10, 15);
  gb.display.println("DIFFICULTY");
  gb.display.setCursor(10, 25);
  gb.display.println("INITIAL STATS");

  gb.display.drawImage(14, 35, IMAGE_HEALTH_MARKER, 5, 5);
  gb.display.setColor(RED);
  gb.display.setCursor(21, 35);
  gb.display.println((String)PlayerMaxHealth);
  gb.display.drawImage(43, 35, IMAGE_LORE_MARKER, 5, 5);
  gb.display.setColor(BLUE);
  gb.display.setCursor(50, 35);
  gb.display.println((String)PlayerMaxKnowledge);
  
  gb.display.setColor(BEIGE);
  gb.display.setCursor(55, 15);
  gb.display.println(displayDifficulty());
  
  gb.display.drawImage(3, 15 + (selectionIdx * 10), IMAGE_SELECTION_MARKER, 5, 5);

  gb.display.drawImage(5, 47, IMAGE_BUTTON_CROSS, 7, 7);
  gb.display.setColor(GRAY);
  gb.display.setCursor(15, 48);
  gb.display.println("adjust");

  gb.display.drawImage(5, 55, IMAGE_BUTTON_B, 7, 7);
  gb.display.setColor(GRAY);
  gb.display.setCursor(15, 56);
  gb.display.println("back");

  gb.display.drawImage(45, 55, IMAGE_BUTTON_A, 7, 7);
  gb.display.setColor(GRAY);
  gb.display.setCursor(55, 56);
  gb.display.println("accept");
}

void DrawEndGame()
{
  gb.display.drawImage(0, 0, IMAGE_MAIN_THEME, 80, 64);
  if (EndGameResult == END_GAME_VICTORY)
  {
    gb.display.setCursor(10, 15);
    gb.display.setColor(GREEN);
    gb.display.println("TOMB DISCOVERED");
  }
  else
  {
    gb.display.setCursor(22, 15);
    gb.display.setColor(RED);
    gb.display.println("GAME OVER");
  }

  gb.display.setCursor(12, 30);
  gb.display.setColor(YELLOW);
  gb.display.println("Total treasure:");
  gb.display.drawImage(28, 38, IMAGE_TREASURE_MARKER, 5, 5);
  gb.display.setColor(YELLOW);
  gb.display.setCursor(35, 38);
  gb.display.println((String)PlayerTreasureValue);

  if (NewHighScore == true)
  {
    gb.display.setCursor(20, 46);
    gb.display.println("NEW RECORD!");
  }

  gb.display.drawImage(5, 55, IMAGE_BUTTON_A, 7, 7);
  gb.display.setColor(GRAY);
  gb.display.setCursor(15, 56);
  gb.display.println("main menu");
}

String displayDifficulty()
{
  switch(GameDifficulty)
  {
    case DIFFICULTY_EASY:
      return "EASY";
    case DIFFICULTY_NORMAL:
      return "NORMAL";
    case DIFFICULTY_HARD:
      return "HARD";
  }
return "EASY";
}

void DrawPauseMenu()
{
  gb.display.drawImage(0, 0, IMAGE_MAIN_THEME, 80, 64);
  gb.display.setColor(WHITE);
  gb.display.setCursor(4, 3);
  gb.display.println("LEVEL " + (String)PyramidLevel);
  
  drawPyramidLevelMap();

  gb.display.drawImage(60, 1, Torch, 9, 11);
  gb.display.setColor(WHITE);
  gb.display.setCursor(54, 16);
  gb.display.println("STATS");
  gb.display.drawImage(48, 22, IMAGE_HEALTH_MARKER, 5, 5);
  gb.display.setColor(RED);
  gb.display.setCursor(55, 22);
  gb.display.println((String)PlayerHealth + "/" + (String)PlayerMaxHealth);
  gb.display.drawImage(48, 28, IMAGE_LORE_MARKER, 5, 5);
  gb.display.setColor(BLUE);
  gb.display.setCursor(55, 28);
  gb.display.println((String)PlayerKnowledge + "/" + (String)PlayerMaxKnowledge);
  gb.display.drawImage(48, 34, IMAGE_TREASURE_MARKER, 5, 5);
  gb.display.setColor(YELLOW);
  gb.display.setCursor(55, 34);
  gb.display.println((String)PlayerTreasureValue);
  gb.display.drawImage(60, 42, Torch, 9, 11);

  gb.display.drawImage(2, 57, IMAGE_BUTTON_MENU, 7, 3);
  gb.display.setColor(GRAY);
  gb.display.setCursor(11, 56);
  gb.display.println("continue");

  gb.display.drawImage(46, 55, IMAGE_BUTTON_B, 7, 7);
  gb.display.setColor(GRAY);
  gb.display.setCursor(55, 56);
  gb.display.println("yield");
}

void drawPyramidLevelMap()
{
  gb.display.drawImage(1, 8, IMAGE_MAP_TABLE, 47, 47);
  for(int i = 0; i < 15; i++)
  {
    for(int j = 0; j < 15; j++)
    {
      TileStruct tile = CurrentPyramidLevel[j][i];
      drawMapTile(tile.Id, 2 + (i * 3), 9 + (j * 3));

      if (tile.EventId == TILE_EVENT_SNAKES || tile.EventId == TILE_EVENT_MUMMY)
      {
        gb.display.drawImage(3 + (i * 3), 10 + (j * 3), IMAGE_DANGER_MARKER, 1, 1);
      }
      else if (tile.EventId == TILE_EVENT_BARS || tile.EventId == TILE_EVENT_TRAP)
      {
        gb.display.drawImage(3 + (i * 3), 10 + (j * 3), IMAGE_BLOCKED_MARKER, 1, 1);
      }
    }
  }

  gb.display.drawImage(3 + (column * 3), 10 + (row * 3), PlayerMapPointer);
}

void drawTile(int id, int posX, int posY)
{
  switch(id)
  {
    case CORRIDOR_UNKNOWN:
      gb.display.drawImage(posX, posY, IMAGE_CORRIDOR_UNKNOWN, 9, 9); break;
    case CORRIDOR_BLOCKED:
      gb.display.drawImage(posX, posY, IMAGE_CORRIDOR_BLOCKED, 9, 9); break;
    case CORRIDOR_CROSSROADS:
      gb.display.drawImage(posX, posY, IMAGE_CORRIDOR_CROSSROADS, 9, 9); break;
    case CORRIDOR_STRAIGHT_HORIZONTAL:
      gb.display.drawImage(posX, posY, IMAGE_CORRIDOR_STRAIGHT_HORIZONTAL, 9, 9); break;
    case CORRIDOR_STRAIGHT_VERTICAL:
      gb.display.drawImage(posX, posY, IMAGE_CORRIDOR_STRAIGHT_VERTICAL, 9, 9); break;
    case CORRIDOR_TURN_DOWN_LEFT:
      gb.display.drawImage(posX, posY, IMAGE_CORRIDOR_TURN_DOWN_LEFT, 9, 9); break;
    case CORRIDOR_TURN_DOWN_RIGHT:
      gb.display.drawImage(posX, posY, IMAGE_CORRIDOR_TURN_DOWN_RIGHT, 9, 9); break;
    case CORRIDOR_TURN_UP_LEFT:
      gb.display.drawImage(posX, posY, IMAGE_CORRIDOR_TURN_UP_LEFT, 9, 9); break;
    case CORRIDOR_TURN_UP_RIGHT:
      gb.display.drawImage(posX, posY, IMAGE_CORRIDOR_TURN_UP_RIGHT, 9, 9); break;
    case CORRIDOR_STRAIGHT_HORIZONTAL_UP:
      gb.display.drawImage(posX, posY, IMAGE_CORRIDOR_STRAIGHT_HORIZONTAL_UP, 9, 9); break;
    case CORRIDOR_STRAIGHT_HORIZONTAL_DOWN:
      gb.display.drawImage(posX, posY, IMAGE_CORRIDOR_STRAIGHT_HORIZONTAL_DOWN, 9, 9); break;
    case CORRIDOR_STRAIGHT_VERTICAL_LEFT:
      gb.display.drawImage(posX, posY, IMAGE_CORRIDOR_STRAIGHT_VERTICAL_LEFT, 9, 9); break;
    case CORRIDOR_STRAIGHT_VERTICAL_RIGHT:
      gb.display.drawImage(posX, posY, IMAGE_CORRIDOR_STRAIGHT_VERTICAL_RIGHT, 9, 9); break;
  }
}

void drawMapTile(int id, int posX, int posY)
{
  switch(id)
  {
    case CORRIDOR_BLOCKED:
      gb.display.drawImage(posX, posY, IMAGE_CORRIDOR_BLOCKED_MAP, 3, 3); break;
    case CORRIDOR_CROSSROADS:
      gb.display.drawImage(posX, posY, IMAGE_CORRIDOR_CROSSROADS_MAP, 3, 3); break;
    case CORRIDOR_STRAIGHT_HORIZONTAL:
      gb.display.drawImage(posX, posY, IMAGE_CORRIDOR_STRAIGHT_HORIZONTAL_MAP, 3, 3); break;
    case CORRIDOR_STRAIGHT_VERTICAL:
      gb.display.drawImage(posX, posY, IMAGE_CORRIDOR_STRAIGHT_VERTICAL_MAP, 3, 3); break;
    case CORRIDOR_TURN_DOWN_LEFT:
      gb.display.drawImage(posX, posY, IMAGE_CORRIDOR_TURN_DOWN_LEFT_MAP, 3, 3); break;
    case CORRIDOR_TURN_DOWN_RIGHT:
      gb.display.drawImage(posX, posY, IMAGE_CORRIDOR_TURN_DOWN_RIGHT_MAP, 3, 3); break;
    case CORRIDOR_TURN_UP_LEFT:
      gb.display.drawImage(posX, posY, IMAGE_CORRIDOR_TURN_UP_LEFT_MAP, 3, 3); break;
    case CORRIDOR_TURN_UP_RIGHT:
      gb.display.drawImage(posX, posY, IMAGE_CORRIDOR_TURN_UP_RIGHT_MAP, 3, 3); break;
    case CORRIDOR_STRAIGHT_HORIZONTAL_UP:
      gb.display.drawImage(posX, posY, IMAGE_CORRIDOR_STRAIGHT_HORIZONTAL_UP_MAP, 3, 3); break;
    case CORRIDOR_STRAIGHT_HORIZONTAL_DOWN:
      gb.display.drawImage(posX, posY, IMAGE_CORRIDOR_STRAIGHT_HORIZONTAL_DOWN_MAP, 3, 3); break;
    case CORRIDOR_STRAIGHT_VERTICAL_LEFT:
      gb.display.drawImage(posX, posY, IMAGE_CORRIDOR_STRAIGHT_VERTICAL_LEFT_MAP, 3, 3); break;
    case CORRIDOR_STRAIGHT_VERTICAL_RIGHT:
      gb.display.drawImage(posX, posY, IMAGE_CORRIDOR_STRAIGHT_VERTICAL_RIGHT_MAP, 3, 3); break;
  }
}

void drawTileEvent(int id, int posX, int posY)
{
  switch(id)
  {
    case TILE_EVENT_STAIRS:
      gb.display.drawImage(posX, posY, IMAGE_TILE_EVENT_STAIRS, 9, 9); break;
    case TILE_EVENT_SNAKES:
      gb.display.drawImage(posX, posY, TileEventSnake, 9, 9); break;
    case TILE_EVENT_BARS:
      gb.display.drawImage(posX, posY, IMAGE_TILE_EVENT_BARS, 9, 9); break;
    case TILE_EVENT_TRAP:
      gb.display.drawImage(posX, posY, IMAGE_TILE_EVENT_TRAP, 9, 9); break;
    case TILE_EVENT_MUMMY:
      gb.display.drawImage(posX, posY, TileEventMummy, 9, 9); break;
    case TILE_EVENT_PHAROAH:
      gb.display.drawImage(posX, posY, IMAGE_TILE_EVENT_PHAROAH, 9, 9); break;
  }
}

void debug()
{
  gb.display.setColor(WHITE);
  gb.display.setCursor(3,3);
  gb.display.println(gb.getFreeRam());
  gb.display.setCursor(3,9);
  gb.display.println(gb.getCpuLoad());
}

/*
SAVE/LOAD data plan
  score  blocks 13 >> 13*4 = 52bytes
  RawMapData[9] >> block N14/ take 3 blocks
  RawPlayerData[27] >> 16/7
  RawUnitIdData[513] >> 23/129
  RawUnitHpData[513] >> 152/129
  RawUnitOwnerData[257] >> 281/65
  RawUnitOwnerData[257] >> 346/65
  RawUnitStatusData[257] >> 411/65
*/

bool LoadGame()
{
  MapId=0;
  loadMapConfig();
  if(loadMap()==true)
  {
    clearMap();
    BaseLocation = &None;
    Attacker = &None;
    Defender = &None;
    loadPlayersConfig();
    loadMapSettings();
    return true;
  }

  return false;
}

void loadMapConfig()
{
  char RawMapData[9];
  gb.save.get(0, RawMapData);
  String MapConfig(RawMapData);
  MapId = MapConfig.substring(0,5).toInt();
  int actualPlayer = MapConfig.substring(6,7).toInt();
  if(actualPlayer==1)
  {
    CurrentPlayer = &Player_1;
  }
  else if(actualPlayer==2)
  {
    CurrentPlayer = &Player_2;
  }
  GameMode=MapConfig.substring(7,8).toInt();
}

bool loadMap()
{
  bool result=false;
  switch(MapId)
  {
    case 1:
    {
      memcpy(CurrentBoard, Board1, sizeof(CurrentBoard));
      result=true;
    }
    break;
    case 2:
    {
      memcpy(CurrentBoard, Board2, sizeof(CurrentBoard));
      result=true;
    }
    break;
    case 3:
    {
      memcpy(CurrentBoard, Board3, sizeof(CurrentBoard));
      result=true;
    }
    break;
    case 4:
    {
      memcpy(CurrentBoard, Board4, sizeof(CurrentBoard));
      result=true;
    }
    break;
    case 5:
    {
      memcpy(CurrentBoard, Board5, sizeof(CurrentBoard));
      result=true;
    }
    break;
    case 6:
    {
      memcpy(CurrentBoard, Board6, sizeof(CurrentBoard));
      result=true;
    }
    break;
    case 7:
    {
      memcpy(CurrentBoard, Board7, sizeof(CurrentBoard));
      result=true;
    }
    break;
    default:
    {
      result=false;
    }
    break;
  }
return(0);
}

void loadPlayersConfig()
{
  char RawPlayerData[27];
  //gb.save.get(1, RawPlayerData);
  gb.save.get(16, RawPlayerData);
  String PlayerData(RawPlayerData);
  
  Player_1.funds = PlayerData.substring(0,5).toInt();
  Player_1.baseLevel = PlayerData.substring(5,6).toInt();
  Player_1.totalUnits = PlayerData.substring(6,8).toInt();
  Player_1.points = PlayerData.substring(8,13).toInt();
  Player_2.funds = PlayerData.substring(13,18).toInt();
  Player_2.baseLevel = PlayerData.substring(18,19).toInt();
  Player_2.totalUnits = PlayerData.substring(19,21).toInt();
  Player_2.points = PlayerData.substring(21,26).toInt();
}

void loadMapSettings()
{
  char RawUnitIdData[513];
  //gb.save.get(2, RawUnitIdData);
  gb.save.get(23, RawUnitIdData);
  String UnitIdData(RawUnitIdData);

  char RawUnitHpData[513];
  //gb.save.get(3, RawUnitHpData);
  gb.save.get(152, RawUnitHpData);
  String UnitHpData(RawUnitHpData);

  char RawUnitOwnerData[257];
  //gb.save.get(4, RawUnitOwnerData);
  gb.save.get(281, RawUnitOwnerData);
  String UnitOwnerData(RawUnitOwnerData);

  char RawUnitStatusData[257];
  //gb.save.get(5, RawUnitStatusData);
  gb.save.get(411, RawUnitStatusData);
  String UnitStatusData(RawUnitStatusData);

  char RawBuildingOwnerData[257];
  //gb.save.get(6, RawBuildingOwnerData);
  gb.save.get(411, RawBuildingOwnerData);
  String BuildingOwnerData(RawBuildingOwnerData);
  
  int idx=0;
  int idx2=0;
  for(int i=0;i<16;i++)
  {
    for(int j=0;j<16;j++)
    {
      CurrentBoard[i][j].unitId = UnitIdData.substring(idx,idx+2).toInt();
      CurrentBoard[i][j].unitHp = UnitHpData.substring(idx,idx+2).toInt();
      CurrentBoard[i][j].player = UnitOwnerData.substring(idx2,idx2+1).toInt();
      CurrentBoard[i][j].active = UnitStatusData.substring(idx2,idx2+1).toInt();
      if(CurrentBoard[i][j].terrainTexture==11 || CurrentBoard[i][j].terrainTexture==12)
      {
        CurrentBoard[i][j].playerBuilding=BuildingOwnerData.substring(idx2,idx2+1).toInt();
      }
      idx+=2;
      idx2++;
    }
  }
}

bool clearMap()
{
  for(int i=0;i<16;i++)
  {
    for(int j=0;j<16;j++)
    {
      CurrentBoard[i][j].unitId = 0;
      CurrentBoard[i][j].unitHp = 0;
      CurrentBoard[i][j].player = 0;
      CurrentBoard[i][j].active = 0;
      if(CurrentBoard[i][j].terrainTexture==11 || CurrentBoard[i][j].terrainTexture==12)
      {
        CurrentBoard[i][j].playerBuilding=0;
      }
    }
  }
  return (0);
}

void SaveGame()
{
  
  if(saveMapConfig()==false)
  {
    gb.gui.popup("ERROR: SAVE MPCON",50);
    return;
  }
  
  if(savePlayerStats()==false)
  {
    gb.gui.popup("ERROR: SAVE PLSTA",50);
    return;
  }
  
  if(saveTilesParams()==false)
  {
    return;
  }
  
  gb.save.set(7,1);
  SaveExist=true;
  
  gb.gui.popup("GAME SAVED!",50);
}

bool saveMapConfig()
{
  String strData="";
  strData+=returnDecimalStringFive(MapId);
  strData+="2"; //Improve when number of players will change
  strData+=(String)CurrentPlayer->id;
  strData+=(String)GameMode;
  strData+=" ";
  if(strData.length()==9)
  {
    //saveDataToBlock(0,strData,9);
    saveDataToBlock(14,strData,9);
    return true;
  }
  else
  {
    return false;
  }
}

bool savePlayerStats()
{
  String strData="";
  
  strData+=returnDecimalStringFive(Player_1.funds);
  strData+=(String)Player_1.baseLevel;
  strData+=returnDecimalStringTwo(Player_1.totalUnits);
  strData+=returnDecimalStringFive(Player_1.points);
  
  strData+=returnDecimalStringFive(Player_2.funds);
  strData+=(String)Player_2.baseLevel;
  strData+=returnDecimalStringTwo(Player_2.totalUnits);
  strData+=returnDecimalStringFive(Player_2.points);
  
  strData+=" ";
  if(strData.length()==27)
  {
    //saveDataToBlock(1,strData,27);
    saveDataToBlock(16,strData,27);
    return true;
  }
  else
  {
    return false;
  }
}

bool saveTilesParams()
{
  String strDataUnitsId="";
  String strDataUnitsHp="";
  String strDataUnitsOwner="";
  String strDataUnitsStatus="";
  String strBuildingsOwner="";
  
  for(int i=0;i<16;i++)
  {
    for(int j=0;j<16;j++)
    {
      strDataUnitsId += returnDecimalStringTwo(CurrentBoard[i][j].unitId);
      strDataUnitsHp += returnDecimalStringTwo(CurrentBoard[i][j].unitHp);
      strDataUnitsOwner += (String)CurrentBoard[i][j].player;
      strDataUnitsStatus += (String)CurrentBoard[i][j].active;
      strBuildingsOwner += (String)CurrentBoard[i][j].playerBuilding;
    }
  }
  
  strDataUnitsId+=" ";
  strDataUnitsHp+=" ";
  strDataUnitsOwner+=" ";
  strDataUnitsStatus+=" ";
  strBuildingsOwner+=" ";
  
  if(strDataUnitsId.length()==513)
  {
    //saveDataToBlock(2,strDataUnitsId,513);
    saveDataToBlock(23,strDataUnitsId,513);
  }
  else
  {
    gb.gui.popup("ERROR: SAVE MPUID",50);
    return false;
  }
  if(strDataUnitsHp.length()==513)
  {
    //saveDataToBlock(3,strDataUnitsHp,513);
    saveDataToBlock(152,strDataUnitsHp,513);
  }
  else
  {
    gb.gui.popup("ERROR: SAVE MPUHP",50);
    return false;
  }
  if(strDataUnitsOwner.length()==257)
  {
    //saveDataToBlock(4,strDataUnitsOwner,257);
    saveDataToBlock(281,strDataUnitsOwner,257);
  }
  else
  {
    gb.gui.popup("ERROR: SAVE MPUOW",50);
    return false;
  }
  if(strDataUnitsStatus.length()==257)
  {
    //saveDataToBlock(5,strDataUnitsStatus,257);
    saveDataToBlock(346,strDataUnitsStatus,257);
  }
  else
  {
    gb.gui.popup("ERROR: SAVE MPUST",50);
    return false;
  }
  if(strBuildingsOwner.length()==257)
  {
    //saveDataToBlock(6,strBuildingsOwner,257);
    saveDataToBlock(411,strBuildingsOwner,257);
  }
  else
  {
    gb.gui.popup("ERROR: SAVE MPBOW",50);
    return false;
  }
  return true;
}

void saveDataToBlock(uint16_t block,String data,int bufferSize)
{
  //char Buffer[bufferSize];
  //data.toCharArray(Buffer,bufferSize);
  //gb.save.set(block,Buffer);
  gb.save.set(block, (char *)data.c_str());
}

//---------------HELPERS---------------------------------

String returnDecimalStringTwo(int number)
{
  if(number<100 && number>9)
    return (String)number;
  else if(number>=0)
    return "0" + (String)number;
  else
    return "00";  
}

String returnDecimalStringFive(int number)
{
  if(number<10000 && number>999)
    return "0"+(String)number;
  else if(number<1000 && number>99)
    return "00"+(String)number;
  else if(number<100 && number>9)
    return "000"+(String)number;
  else if(number>=0)
    return "0000" + (String)number;
  else
    return "00000";  
}

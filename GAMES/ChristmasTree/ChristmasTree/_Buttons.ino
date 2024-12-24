void button_check(){
  
  if(gameMode==DEMO){
    if(gb.buttons.pressed(BUTTON_RIGHT)){
      timerSnow=timerSnow+1;
      if(timerSnow>15){timerSnow=15;}
    }else{
      if(gb.buttons.pressed(BUTTON_LEFT)){
        timerSnow=timerSnow-1;
        if(timerSnow<0){timerSnow=0;}
      }
    }
    if(gb.buttons.pressed(BUTTON_UP)){
      snowOn = false;
    }else{
      if(gb.buttons.pressed(BUTTON_DOWN)){snowOn = true;}
    }
    if(gb.buttons.pressed(BUTTON_A)){
      elecSequence=elecSequence-1;
      if(elecSequence<0){elecSequence=3;}
    }else{
      if(gb.buttons.pressed(BUTTON_B)){
        elecSequence=elecSequence+1;
        if(elecSequence>3){elecSequence=0;}
      }
    }
    

    if(gb.buttons.released(BUTTON_MENU)){
      check=false;
    }    
    if(gb.buttons.pressed(BUTTON_MENU)){
      gameMode=SETTINGS;
      check=true;
    }
  }


  if(gameMode==SETTINGS){
    if(gb.buttons.pressed(BUTTON_B)){
      gameMode=DEMO;
    }

    if(gb.buttons.released(BUTTON_MENU)){
      check=false;
    }    
    if(gb.buttons.pressed(BUTTON_MENU) && check==false){
      gameMode=DEMO;
      check=true;
    }
  
    if(gb.buttons.pressed(BUTTON_UP)){
      selectedSetting--;
      if(selectedSetting<0){selectedSetting=0;}
    }else{
      if(gb.buttons.pressed(BUTTON_DOWN)){
        selectedSetting++;
        if(selectedSetting>5){selectedSetting=5;}        
      }
    }

    if(selectedSetting==0){
      if(gb.buttons.pressed(BUTTON_LEFT)){snowOn=false;}
      if(gb.buttons.pressed(BUTTON_RIGHT)){snowOn=true;}
    }

    if(selectedSetting==1){
      if(gb.buttons.pressed(BUTTON_RIGHT)){tree.type = tree.type+1;}
      if(gb.buttons.pressed(BUTTON_LEFT)){tree.type = tree.type-1;}
      if(tree.type<0){tree.type=0;}
      if(tree.type>2){tree.type=2;}
      if(gb.buttons.pressed(BUTTON_A)){gameMode=TREEPOS;}
    }

    if(selectedSetting==2){
      if(gb.buttons.pressed(BUTTON_LEFT)){tree.starTheme=tree.starTheme-1;}
      if(gb.buttons.pressed(BUTTON_RIGHT)){tree.starTheme=tree.starTheme+1;}
      if(tree.starTheme<0){tree.starTheme=0;}
      if(tree.starTheme>4){tree.starTheme=4;}
    }

    if(selectedSetting==3){
      if(gb.buttons.pressed(BUTTON_LEFT)){tree.ballsTheme=tree.ballsTheme-1;}
      if(gb.buttons.pressed(BUTTON_RIGHT)){tree.ballsTheme=tree.ballsTheme+1;}
      if(tree.ballsTheme<0){tree.ballsTheme=0;}
      if(tree.ballsTheme>3){tree.ballsTheme=3;}
      if(gb.buttons.pressed(BUTTON_A) && tree.ballsTheme==3){gameMode=TREEDECO;}
    }

    if(selectedSetting==4){
      if(gb.buttons.pressed(BUTTON_LEFT)){tree.electTheme=tree.electTheme-1;}
      if(gb.buttons.pressed(BUTTON_RIGHT)){tree.electTheme=tree.electTheme+1;}
      if(tree.electTheme<0){tree.electTheme=0;}
      if(tree.electTheme>7){tree.electTheme=7;}
    }

    if(selectedSetting==5){
      if(gb.buttons.pressed(BUTTON_LEFT)){selectedDeco=selectedDeco-1;}
      if(gb.buttons.pressed(BUTTON_RIGHT)){selectedDeco=selectedDeco+1;}
      if(selectedDeco<0){selectedDeco=0;}
      if(selectedDeco>8){selectedDeco=8;}
      if(gb.buttons.pressed(BUTTON_A)){gameMode=DECOPOS;}
    }
  }

  if(gameMode==DECOPOS){
      if(gb.buttons.repeat(BUTTON_LEFT ,0)){coordDeco[selectedDeco].x=coordDeco[selectedDeco].x-1;}
      if(gb.buttons.repeat(BUTTON_UP   ,0)){coordDeco[selectedDeco].y=coordDeco[selectedDeco].y-1;}
      if(gb.buttons.repeat(BUTTON_RIGHT,0)){coordDeco[selectedDeco].x=coordDeco[selectedDeco].x+1;}
      if(gb.buttons.repeat(BUTTON_DOWN ,0)){coordDeco[selectedDeco].y=coordDeco[selectedDeco].y+1;}
      if(gb.buttons.pressed(BUTTON_B)){gameMode=SETTINGS;}
  }

  if(gameMode==TREEPOS){
      if(gb.buttons.repeat(BUTTON_LEFT ,0)){tree.x=tree.x-1;}
      if(gb.buttons.repeat(BUTTON_UP   ,0)){tree.y=tree.y-1;}
      if(gb.buttons.repeat(BUTTON_RIGHT,0)){tree.x=tree.x+1;}
      if(gb.buttons.repeat(BUTTON_DOWN ,0)){tree.y=tree.y+1;}
      if(gb.buttons.pressed(BUTTON_B)){gameMode=SETTINGS;}
  }

  if(gameMode==TREEDECO){
      
      if(gb.buttons.pressed(BUTTON_MENU)){
        gameMode=SETTINGS;
        isMovingDeco=false;
        selectedSubSetting=0;
      }
    
    if(isMovingDeco==false){
      if(gb.buttons.pressed(BUTTON_UP  )){
        selectedSubSetting=selectedSubSetting-1;
        if(selectedSubSetting<0){selectedSubSetting=0;}
      }
      if(gb.buttons.pressed(BUTTON_DOWN)){
        selectedSubSetting=selectedSubSetting+1;
        if(selectedSubSetting>3){selectedSubSetting=3;}
      }
      if(gb.buttons.pressed(BUTTON_B)){gameMode=SETTINGS;}
    }

    if(selectedSubSetting==0){
      if(gb.buttons.pressed(BUTTON_LEFT)){
        selectedTreeDeco=selectedTreeDeco-1;
        if(selectedTreeDeco<0){selectedTreeDeco=0;}
      }
      
      if(gb.buttons.pressed(BUTTON_RIGHT)){
        selectedTreeDeco=selectedTreeDeco+1;
        if(selectedTreeDeco>9){selectedTreeDeco=9;}
      }
    }

    if(selectedSubSetting==1){
      if(gb.buttons.pressed(BUTTON_LEFT)){
        bouleTheme[2][selectedTreeDeco].type=bouleTheme[2][selectedTreeDeco].type-1;
        if(bouleTheme[2][selectedTreeDeco].type<0){bouleTheme[2][selectedTreeDeco].type=0;}
      }
      
      if(gb.buttons.pressed(BUTTON_RIGHT)){
        bouleTheme[2][selectedTreeDeco].type=bouleTheme[2][selectedTreeDeco].type+1;
        if(bouleTheme[2][selectedTreeDeco].type>15){bouleTheme[2][selectedTreeDeco].type=15;}
      }
    }

    if(selectedSubSetting==2){
      if(isMovingDeco==false){
        if(gb.buttons.pressed(BUTTON_A)){
          isMovingDeco=true;
        }
      }else{
        if(gb.buttons.pressed(BUTTON_B)){isMovingDeco=false;}
        if(gb.buttons.pressed(BUTTON_LEFT)) {bouleTheme[2][selectedTreeDeco].x=bouleTheme[2][selectedTreeDeco].x-1;}
        if(gb.buttons.pressed(BUTTON_RIGHT)){bouleTheme[2][selectedTreeDeco].x=bouleTheme[2][selectedTreeDeco].x+1;}      
        if(gb.buttons.pressed(BUTTON_UP))   {bouleTheme[2][selectedTreeDeco].y=bouleTheme[2][selectedTreeDeco].y-1;}
        if(gb.buttons.pressed(BUTTON_DOWN)) {bouleTheme[2][selectedTreeDeco].y=bouleTheme[2][selectedTreeDeco].y+1;}
      }
    }
  }
}

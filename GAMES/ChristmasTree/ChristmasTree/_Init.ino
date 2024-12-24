
void initSnow(){
  for(int i=0;i<70;i++){snow[i]=random(0, 80);}
}

void initTree(){
  tree.type=1;
  tree.x=5;
  tree.y=11;
  tree.starTheme=1;
  tree.ballsTheme=2;
  tree.electTheme=0;
}

void initBalls(){
  bouleTheme[0][0].x=18;  bouleTheme[0][0].y=7;   bouleTheme[0][0].type=3;
  bouleTheme[0][1].x=12;   bouleTheme[0][1].y=11;  bouleTheme[0][1].type=3;
  bouleTheme[0][2].x=20;  bouleTheme[0][2].y=15;  bouleTheme[0][2].type=4;
  bouleTheme[0][3].x=17;  bouleTheme[0][3].y=20;  bouleTheme[0][3].type=5;
  bouleTheme[0][4].x=9;   bouleTheme[0][4].y=24;  bouleTheme[0][4].type=4;
  bouleTheme[0][5].x=15;   bouleTheme[0][5].y=27;  bouleTheme[0][5].type=6;
  bouleTheme[0][6].x=23;  bouleTheme[0][6].y=35;  bouleTheme[0][6].type=4;
  bouleTheme[0][7].x=8;   bouleTheme[0][7].y=36;  bouleTheme[0][7].type=3;
  bouleTheme[0][8].x=14;   bouleTheme[0][8].y=39;  bouleTheme[0][8].type=5;
  bouleTheme[0][9].x=24;  bouleTheme[0][9].y=41;  bouleTheme[0][9].type=3;

  bouleTheme[1][0].x=18;  bouleTheme[1][0].y=7;   bouleTheme[1][0].type=10;
  bouleTheme[1][1].x=12;   bouleTheme[1][1].y=11;  bouleTheme[1][1].type=11;
  bouleTheme[1][2].x=20;  bouleTheme[1][2].y=15;  bouleTheme[1][2].type=6;
  bouleTheme[1][3].x=17;  bouleTheme[1][3].y=20;  bouleTheme[1][3].type=10;
  bouleTheme[1][4].x=9;   bouleTheme[1][4].y=24;  bouleTheme[1][4].type=10;
  bouleTheme[1][5].x=15;   bouleTheme[1][5].y=27;  bouleTheme[1][5].type=6;
  bouleTheme[1][6].x=23;  bouleTheme[1][6].y=33;  bouleTheme[1][6].type=10;
  bouleTheme[1][7].x=8;   bouleTheme[1][7].y=36;  bouleTheme[1][7].type=10;
  bouleTheme[1][8].x=14;   bouleTheme[1][8].y=39;  bouleTheme[1][8].type=6;
  bouleTheme[1][9].x=24;  bouleTheme[1][9].y=41;  bouleTheme[1][9].type=11;

  bouleTheme[2][0].x=18;  bouleTheme[2][0].y=7;   bouleTheme[2][0].type=1;
  bouleTheme[2][1].x=12;   bouleTheme[2][1].y=11;  bouleTheme[2][1].type=2;
  bouleTheme[2][2].x=20;  bouleTheme[2][2].y=15;  bouleTheme[2][2].type=3;
  bouleTheme[2][3].x=17;  bouleTheme[2][3].y=20;  bouleTheme[2][3].type=4;
  bouleTheme[2][4].x=9;   bouleTheme[2][4].y=24;  bouleTheme[2][4].type=5;
  bouleTheme[2][5].x=15;   bouleTheme[2][5].y=27;  bouleTheme[2][5].type=6;
  bouleTheme[2][6].x=23;  bouleTheme[2][6].y=33;  bouleTheme[2][6].type=7;
  bouleTheme[2][7].x=8;   bouleTheme[2][7].y=36;  bouleTheme[2][7].type=8;
  bouleTheme[2][8].x=14;   bouleTheme[2][8].y=39;  bouleTheme[2][8].type=9;
  bouleTheme[2][9].x=24;  bouleTheme[2][9].y=41;  bouleTheme[2][9].type=10;
}

void initElec(){
  for(int i=0; i<38;i++){
    electric[0].x = 17; electric[0].y = 3;
    electric[1].x = 19; electric[1].y = 5;
    electric[2].x = 17; electric[2].y = 6;
    electric[3].x = 14; electric[3].y = 8;
    electric[4].x = 16; electric[4].y = 10;
    
    electric[5].x = 19; electric[5].y = 11;
    electric[6].x = 21; electric[6].y = 12;
    electric[7].x = 19; electric[7].y = 14;
    electric[8].x = 17; electric[8].y = 16;
    electric[9].x = 15; electric[9].y = 17;
    
    electric[10].x = 12; electric[10].y = 18;
    electric[11].x = 11; electric[11].y = 21;
    electric[12].x = 13; electric[12].y = 23;
    electric[13].x = 16; electric[13].y = 24;
    electric[14].x = 18; electric[14].y = 25;
    
    electric[15].x = 21; electric[15].y = 26;
    electric[16].x = 24; electric[16].y = 26;
    electric[17].x = 25; electric[17].y = 28;
    electric[18].x = 23; electric[18].y = 30;
    electric[19].x = 21; electric[19].y = 31;
    
    electric[20].x = 18; electric[20].y = 32;
    electric[21].x = 15; electric[21].y = 32;
    electric[22].x = 12; electric[22].y = 31;
    electric[23].x = 9;  electric[23].y = 30;
    electric[24].x = 10; electric[24].y = 32;
    
    electric[25].x = 12; electric[25].y = 34;
    electric[26].x = 14; electric[26].y = 36;
    electric[27].x = 16; electric[27].y = 37;
    electric[28].x = 19; electric[28].y = 38;
    electric[29].x = 22; electric[29].y = 38;
    
    electric[30].x = 26; electric[30].y = 38;
    electric[31].x = 25; electric[31].y = 40;
    electric[32].x = 22; electric[32].y = 42;
    electric[33].x = 19; electric[33].y = 43;
    electric[34].x = 16; electric[34].y = 44;
    
    electric[35].x = 13; electric[35].y = 44;
    electric[36].x = 11; electric[36].y = 43;
    electric[37].x = 8;  electric[37].y = 42;
  }
}


void initDeco(){
  coordDeco[0].x=0; coordDeco[0].y=0;
  coordDeco[1].x=41; coordDeco[1].y=41;
  coordDeco[2].x=41; coordDeco[2].y=41;
  coordDeco[3].x=42; coordDeco[3].y=35;
  coordDeco[4].x=42; coordDeco[4].y=35;
  coordDeco[5].x=37;  coordDeco[5].y=33;
  coordDeco[6].x=37;  coordDeco[6].y=33;
  coordDeco[7].x=34;  coordDeco[7].y=42;
  coordDeco[8].x=34;  coordDeco[8].y=42;
}

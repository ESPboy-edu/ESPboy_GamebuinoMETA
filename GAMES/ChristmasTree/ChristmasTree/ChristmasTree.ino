#include <Gamebuino-Meta.h>
#define SCREENHEIGHT 64
#define SCREENWIDTH 80

#define DEMO 0
#define SETTINGS 1
#define TREEPOS 2
#define DECOPOS 3
#define TREEDECO 4

int gameMode;
int selectedSetting=0;
int selectedSubSetting=0;

typedef struct{
  int x;
  int y;
} coord;
coord coordDeco[9];
coord electric[38];

typedef struct {
  int x;
  int y;
  int type;
} particle;
particle bouleTheme[3][10];

bool check = false;

int snow[70];
int snowPos=0;
int snowSpeed=2;

typedef struct {
  int type;
  int x;
  int y;
  int starTheme;
  int ballsTheme;
  int electTheme;
}TreeParam;
TreeParam tree;

int timerSnow=0;
bool snowOn = true;

int timerElec=0;
int timerLight=0;
int sideElec=1;
int sideLight=1;
int elecSequence=0;

int selectedTreeDeco=0;
bool isMovingDeco=false;

int selectedDeco=1;

//###########################
//##### Game Setup ##########
//###########################
void setup(){
  gb.begin();
  //randomSeed(analogRead(A2));
  initSnow();
  initTree();
  initBalls();
  initElec();
  initDeco();

  gameMode= DEMO;
  loop();
}


//###########################
//##### Game Loop ###########
//###########################
void loop(){
    if(gb.update()){
      outputScreen_clear();

      if(gameMode==DEMO){
        outputScreen_displaySnow(0);
        outputScreen_displayGround();
        outputScreen_displayDecoBackground(coordDeco[selectedDeco].x,coordDeco[selectedDeco].y);
        outputScreen_displayTree(tree.x, tree.y, tree.type);
        outputScreen_displayStar(tree.x, tree.y);
        outputScreen_displayElec(tree.x, tree.y);
        outputScreen_displayBoule(tree.x,tree.y);
        outputScreen_displayDeco(coordDeco[selectedDeco].x,coordDeco[selectedDeco].y);

        outputLights_displayColors();

        game_snowUpdate();
        game_snowNewParticule();
        game_elecUpdate();

      }

      if(gameMode==SETTINGS){
        if(selectedSetting==0){
          game_snowUpdate();
          game_snowNewParticule();
          outputScreen_displaySnow(16);
        }


        
        if(selectedSetting==1){
          outputScreen_displayTree(23, 19, tree.type);
          outputScreen_displayStar(23, 19);
          outputScreen_displayElec(23, 19);
          outputScreen_displayBoule(23, 19);
        }
       
        if(selectedSetting==2){
          outputScreen_displayTree(23, 25, tree.type);
          outputScreen_displayStar(23, 25);
          outputScreen_displayElec(23, 25);
          outputScreen_displayBoule(23, 25);
        }
        
        if(selectedSetting==3){
          outputScreen_displayTree(23, 19, tree.type);
          outputScreen_displayStar(23, 19);
          outputScreen_displayElec(23, 19);
          outputScreen_displayBoule(23, 19);
        }

        if(selectedSetting==4){
          outputScreen_displayTree(23, 19, tree.type);
          outputScreen_displayStar(23, 19);
          outputScreen_displayElec(23, 19);
          outputScreen_displayBoule(23, 19);
          game_elecUpdate();
        }
        
        if(selectedSetting==5){
          outputScreen_displayDeco4Menu(coordDeco[selectedDeco].x,coordDeco[selectedDeco].y);
        }
        
        if(selectedSetting==6){
          outputScreen_displayDeco4Menu(coordDeco[selectedDeco].x,coordDeco[selectedDeco].y);
        }
        
        outputScreen_displayText();
      }

      if(gameMode==TREEPOS){
        outputScreen_displayGround();
        outputScreen_displayDecoBackground(coordDeco[selectedDeco].x,coordDeco[selectedDeco].y);
        outputScreen_displayTree(tree.x, tree.y, tree.type);
        outputScreen_displayStar(tree.x, tree.y);
        outputScreen_displayElec(tree.x, tree.y);
        outputScreen_displayBoule(tree.x,tree.y);
        outputScreen_displayDeco(coordDeco[selectedDeco].x,coordDeco[selectedDeco].y);
        outputScreen_diplayTextPos();
      }

      if(gameMode==DECOPOS){
        outputScreen_displayGround();
        outputScreen_displayDecoBackground(coordDeco[selectedDeco].x,coordDeco[selectedDeco].y);
        outputScreen_displayTree(tree.x, tree.y, tree.type);
        outputScreen_displayStar(tree.x, tree.y);
        outputScreen_displayElec(tree.x, tree.y);
        outputScreen_displayBoule(tree.x,tree.y);
        outputScreen_displayDeco(coordDeco[selectedDeco].x,coordDeco[selectedDeco].y);
        outputScreen_diplayTextPos();
      }

      if(gameMode==TREEDECO){
        outputScreen_displayTree(44, 13, tree.type);
        outputScreen_displayStar(44, 13);
        outputScreen_displayElec(44, 13);
        outputScreen_displayBoule(44,13);
        outputScreen_diplayTextTreeDeco();
      }
      button_check();
    }
}

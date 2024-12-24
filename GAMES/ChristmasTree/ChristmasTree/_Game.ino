
void game_snowNewParticule(){
  for(int i=0;i<70;i++){
    if(((i+(snowPos/snowSpeed))%70)==0){
      if(snowOn==false){snow[i]=200;}
      else{snow[i]=random(0, 80);}
    }
  }
  
}

void game_snowUpdate(){
  snowPos=(snowPos+1)%(70*snowSpeed);
}

void game_elecUpdate(){
  timerElec=timerElec+sideElec;
  if(timerElec==26){sideElec=-1;}
  if(timerElec==0){sideElec=1;}

  timerLight=timerLight+sideLight;
  if(timerLight==26){sideLight=-1;}
  if(timerLight==0){sideLight=1;}
}

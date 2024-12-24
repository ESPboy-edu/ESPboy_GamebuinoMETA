PROGMEM const uint16_t COLORS_DATA[] = {6, 27, 1, 1, 0x0000, 0, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x1080, 0x0000,
    0x0000, 0x1002, 0x1000, 0x0002, 0x1080, 0x0080,
    0x0000, 0x2004, 0x2000, 0x0004, 0x3180, 0x0080,
    0x0000, 0x3006, 0x3000, 0x0006, 0x3180, 0x0100,
    0x0841, 0x3006, 0x3000, 0x0006, 0x3180, 0x0100,
    0x18c3, 0x4008, 0x4000, 0x0008, 0x3180, 0x0180,
    0x2945, 0x500a, 0x5000, 0x000a, 0x3180, 0x0180,
    0x3186, 0x500a, 0x5000, 0x000a, 0x4220, 0x0220,
    0x4228, 0x600c, 0x6000, 0x000c, 0x4220, 0x0220,
    0x52aa, 0x700e, 0x7000, 0x000e, 0x6320, 0x0220,
    0x632c, 0x8811, 0x8800, 0x0011, 0x6320, 0x02a0,
    0x6b6d, 0x8811, 0x8800, 0x0011, 0x73a0, 0x02a0,
    0x73ae, 0x9813, 0x9800, 0x0013, 0x73a0, 0x0320,
    0x9492, 0xa815, 0xa800, 0x0015, 0x73a0, 0x0320,
    0x9cd3, 0xa815, 0xa800, 0x0015, 0x8c40, 0x03a0,
    0xa514, 0xb817, 0xb800, 0x0017, 0x8c40, 0x03a0,
    0xb596, 0xc819, 0xc800, 0x0019, 0x9cc0, 0x0440,
    0xc618, 0xd81b, 0xd800, 0x0019, 0xad40, 0x0440,
    0xd6ba, 0xd81b, 0xd800, 0x001b, 0xbdc0, 0x0440,
    0xdefb, 0xe81d, 0xe800, 0x001d, 0xdee0, 0x04c0,
    0xef7d, 0xf81f, 0xf800, 0x001f, 0xef60, 0x04c0,
    0xffff, 0xf89f, 0xf882, 0x001f, 0xef60, 0x0540,
    0xffff, 0xf89f, 0xf882, 0x109f, 0xffe2, 0x0540,
    0xffff, 0xf89f, 0xf882, 0x109f, 0xffe2, 0x0540
};

void outputLights_clear(){
  gb.lights.clear();
}


void  outputLights_displayColors(){
  /*
  if(tree.electTheme){
    Image ELEC000 = Image(COLORS_DATA);
    int lightColor1=tree.electTheme-1;
    int lightColor2=tree.electTheme-1;
    int lightColor3=tree.electTheme-1;
    int lightColor4=tree.electTheme-1;
    if(tree.electTheme==7){
      lightColor1=2; //red
      lightColor2=3; //blue
      lightColor3=4; //yellow
      lightColor4=5; //green
    }
    
    if(elecSequence==0){
      gb.lights.drawImage(0,0,ELEC000,lightColor2,timerLight,1,1);
      gb.lights.drawImage(0,1,ELEC000,lightColor2,timerLight,1,1);
      gb.lights.drawImage(0,2,ELEC000,lightColor1,timerLight,1,1);
      gb.lights.drawImage(0,3,ELEC000,lightColor1,timerLight,1,1);
      
      gb.lights.drawImage(1,0,ELEC000,lightColor3,timerLight,1,1);
      gb.lights.drawImage(1,1,ELEC000,lightColor3,timerLight,1,1);
      gb.lights.drawImage(1,2,ELEC000,lightColor4,timerLight,1,1);
      gb.lights.drawImage(1,3,ELEC000,lightColor4,timerLight,1,1);
    }

    if(elecSequence==1){
      gb.lights.drawImage(0,0,ELEC000,lightColor2,timerLight,1,1);
      gb.lights.drawImage(0,1,ELEC000,lightColor2,timerLight,1,1);
      gb.lights.drawImage(0,2,ELEC000,lightColor1,27-timerLight,1,1);
      gb.lights.drawImage(0,3,ELEC000,lightColor1,27-timerLight,1,1);
      
      gb.lights.drawImage(1,0,ELEC000,lightColor3,27-timerLight,1,1);
      gb.lights.drawImage(1,1,ELEC000,lightColor3,27-timerLight,1,1);
      gb.lights.drawImage(1,2,ELEC000,lightColor4,timerLight,1,1);
      gb.lights.drawImage(1,3,ELEC000,lightColor4,timerLight,1,1);
    }

    if(elecSequence==2){
      gb.lights.clear();
        if(timerElec<6){
          gb.lights.drawImage(0,0,ELEC000,lightColor2,26,1,1);
          gb.lights.drawImage(0,2,ELEC000,lightColor1,26,1,1);
          gb.lights.drawImage(1,1,ELEC000,lightColor3,26,1,1);
          gb.lights.drawImage(1,3,ELEC000,lightColor4,26,1,1);
        }
        
        if(timerElec>=6  && timerElec<12){
          gb.lights.drawImage(0,1,ELEC000,lightColor2,26,1,1);
          gb.lights.drawImage(0,3,ELEC000,lightColor1,26,1,1);
          gb.lights.drawImage(1,0,ELEC000,lightColor3,26,1,1);
          gb.lights.drawImage(1,2,ELEC000,lightColor4,26,1,1);
        }
        
        if(timerElec>=12 && timerElec<17){
          gb.lights.drawImage(0,0,ELEC000,lightColor2,26,1,1);
          gb.lights.drawImage(0,2,ELEC000,lightColor1,26,1,1);
          gb.lights.drawImage(1,1,ELEC000,lightColor3,26,1,1);
          gb.lights.drawImage(1,3,ELEC000,lightColor4,26,1,1);
        }
        
        if(timerElec>=17 && timerElec<21){
          gb.lights.drawImage(0,1,ELEC000,lightColor2,26,1,1);
          gb.lights.drawImage(0,3,ELEC000,lightColor1,26,1,1);
          gb.lights.drawImage(1,0,ELEC000,lightColor3,26,1,1);
          gb.lights.drawImage(1,2,ELEC000,lightColor4,26,1,1);
        }
        
        if(timerElec>=21 && timerElec<24){
          gb.lights.drawImage(0,0,ELEC000,lightColor2,26,1,1);
          gb.lights.drawImage(0,2,ELEC000,lightColor1,26,1,1);
          gb.lights.drawImage(1,1,ELEC000,lightColor3,26,1,1);
          gb.lights.drawImage(1,3,ELEC000,lightColor4,26,1,1);
        }
        
        if(timerElec>=24 && timerElec<26){
          gb.lights.drawImage(0,1,ELEC000,lightColor2,26,1,1);
          gb.lights.drawImage(0,3,ELEC000,lightColor1,26,1,1);
          gb.lights.drawImage(1,0,ELEC000,lightColor3,26,1,1);
          gb.lights.drawImage(1,2,ELEC000,lightColor4,26,1,1);
        }
        
        if(timerElec>=26){
          gb.lights.drawImage(0,0,ELEC000,lightColor2,26,1,1);
          gb.lights.drawImage(0,2,ELEC000,lightColor1,26,1,1);
          gb.lights.drawImage(1,1,ELEC000,lightColor3,26,1,1);
          gb.lights.drawImage(1,3,ELEC000,lightColor4,26,1,1);
        }
    }

    if(elecSequence==3){
      gb.lights.drawImage(0,0,ELEC000,lightColor2,26*random(0,2),1,1);
      gb.lights.drawImage(0,1,ELEC000,lightColor2,26*random(0,2),1,1);
      gb.lights.drawImage(0,2,ELEC000,lightColor1,26*random(0,2),1,1);
      gb.lights.drawImage(0,3,ELEC000,lightColor1,26*random(0,2),1,1);
      
      gb.lights.drawImage(1,0,ELEC000,lightColor3,26*random(0,2),1,1);
      gb.lights.drawImage(1,1,ELEC000,lightColor3,26*random(0,2),1,1);
      gb.lights.drawImage(1,2,ELEC000,lightColor4,26*random(0,2),1,1);
      gb.lights.drawImage(1,3,ELEC000,lightColor4,26*random(0,2),1,1);
    }    
  }else{
    outputLights_clear();
  }
  */
}

#ifndef GLITCH_DOORS_H
#define GLITCH_DOORS_H

#include "constants.h"

struct Door 
{
    uint8_t x;
    uint8_t w;
    uint8_t y;
    uint8_t h;
    uint8_t destinationSpace;
    uint8_t destinationDoor;
};

static PROGMEM const Door spacesDoors[NB_OF_SPACES][NB_DOORS_PER_SPACE] = 
{
  //SPACE 1, The Street
  {
    {//door bottom left on space 1
      5 * LOGIC_TILE_W,//x
      4 * LOGIC_TILE_W,//width
      SPACE_H - (5 * LOGIC_TILE_H),//y
      4 * LOGIC_TILE_H,//height
      1, //destination space
      0,//destination door
    },
    {//door middle right on space 1
      21 * LOGIC_TILE_W,//x
      2 * LOGIC_TILE_W,//w
      6 * LOGIC_TILE_H,//y
      2 * LOGIC_TILE_H,//h
      2, //destination space
      0,//destination door
    }, 
    {//door top right on space 1
      22 * LOGIC_TILE_W,//x
      LOGIC_TILE_W,//w
      0,//y
      2 * LOGIC_TILE_H,//h
      1, //destination space
      0,//destination door
    }, 
    {//door top left on space 1
      3 * LOGIC_TILE_W,//x
      2 * LOGIC_TILE_W,//w
      2 * LOGIC_TILE_H,//y
      LOGIC_TILE_H,//h
      1, //destination space
      3,//destination door
    }
  },
  //SPACE 2, The Store
  {
    {//door bottom left on space 2
      LOGIC_TILE_W,//x
      LOGIC_TILE_W,//width
      SPACE_H - (6 * LOGIC_TILE_H),//y
      5 * LOGIC_TILE_H,//height
      0, //destination space
      0,//destination door
    },
    {//door bottom left on space 2
      LOGIC_TILE_W,//x
      LOGIC_TILE_W,//width
      SPACE_H - (6 * LOGIC_TILE_H),//y
      5 * LOGIC_TILE_H,//height
      0, //destination space
      0,//destination door
    },
    {//door top middle on space 2
      9 * LOGIC_TILE_W,//x
      2 * LOGIC_TILE_W,//w
      2 * LOGIC_TILE_H,//y
      2 * LOGIC_TILE_H,//h
      7, //destination space
      1,//destination door
    }, 
    {//door top left on space 2
      2 * LOGIC_TILE_W,//x
      2 * LOGIC_TILE_W,//w
      LOGIC_TILE_H,//y
      2 * LOGIC_TILE_H,//h
      0, //destination space
      3,//destination door
    }
  },
  //SPACE 3, The Lab
  {
    {//door top left on space 3
      6 * LOGIC_TILE_W,//x
      2 * LOGIC_TILE_W,//width
      2 * LOGIC_TILE_H,//y
      LOGIC_TILE_H,//height
      0, //destination space
      1,//destination door
    },
    {//door top left on space 3
      3 * LOGIC_TILE_W,//x
      2 * LOGIC_TILE_W,//width
      2 * LOGIC_TILE_H,//y
      LOGIC_TILE_H,//height
      0, //destination space
      1,//destination door
    },
    {//door bottom right on space 3
      SPACE_W - (4 * LOGIC_TILE_W),//x
      2 * LOGIC_TILE_W,//w
      SPACE_H - (5 * LOGIC_TILE_H),//y
      4 * LOGIC_TILE_H,//h
      3, //destination space
      0,//destination door
    }, 
    {//door top right on space 3
      SPACE_W - (9 * LOGIC_TILE_W),//x
      3 * LOGIC_TILE_W,//w
      2 * LOGIC_TILE_H,//y
      LOGIC_TILE_H,//h
      4, //destination space
      0,//destination door
    }
  },
  //SPACE 4, The wasteland
  {
    {//door bottom left on space 4
      LOGIC_TILE_W,//x
      3 * LOGIC_TILE_W,//width
      SPACE_H - (5 * LOGIC_TILE_H),//y
      4 * LOGIC_TILE_H,//height
      2, //destination space
      2,//destination door
    },
    {//door bottom left on space 4
      LOGIC_TILE_W,//x
      3 * LOGIC_TILE_W,//width
      SPACE_H - (5 * LOGIC_TILE_H),//y
      4 * LOGIC_TILE_H,//height
      2, //destination space
      0,//destination door
    },
    {//door bottom left on space 4
      LOGIC_TILE_W,//x
      3 * LOGIC_TILE_W,//width
      SPACE_H - (5 * LOGIC_TILE_H),//y
      4 * LOGIC_TILE_H,//height
      2, //destination space
      0,//destination door
    },
    {//door top left on space 4
      5 * LOGIC_TILE_W,//x
      2 * LOGIC_TILE_W,//w
      LOGIC_TILE_H,//y
      2 * LOGIC_TILE_H,//h
      0, //destination space
      2,//destination door
    }
  },
  //SPACE 5, The Parallel Street
  {
    {//door bottom left on space 1
      5 * LOGIC_TILE_W,//x
      4 * LOGIC_TILE_W,//width
      SPACE_H - (5 * LOGIC_TILE_H),//y
      4 * LOGIC_TILE_H,//height
      5, //destination space
      0,//destination door
    },
    {//door bottom left on space 1
      5 * LOGIC_TILE_W,//x
      4 * LOGIC_TILE_W,//width
      SPACE_H - (5 * LOGIC_TILE_H),//y
      4 * LOGIC_TILE_H,//height
      5, //destination space
      0,//destination door
    },
    {//door bottom left on space 1
      5 * LOGIC_TILE_W,//x
      4 * LOGIC_TILE_W,//width
      SPACE_H - (5 * LOGIC_TILE_H),//y
      4 * LOGIC_TILE_H,//height
      5, //destination space
      0,//destination door
    },
    {//door top left on space 1
      3 * LOGIC_TILE_W,//x
      2 * LOGIC_TILE_W,//w
      2 * LOGIC_TILE_H,//y
      LOGIC_TILE_H,//h
      5, //destination space
      3,//destination door
    }
  },
  //SPACE 6, The Parallel Store
  {
    {//door bottom left on space 6
      LOGIC_TILE_W,//x
      LOGIC_TILE_W,//width
      SPACE_H - (6 * LOGIC_TILE_H),//y
      5 * LOGIC_TILE_H,//height
      4, //destination space
      0,//destination door
    },
    {//door bottom left on space 6
      LOGIC_TILE_W,//x
      LOGIC_TILE_W,//width
      SPACE_H - (6 * LOGIC_TILE_H),//y
      5 * LOGIC_TILE_H,//height
      4, //destination space
      0,//destination door
    },
    {//door top right on space 6
      SPACE_W - (9 * LOGIC_TILE_W),//x
      3 * LOGIC_TILE_W,//w
      0,//y
      5 * LOGIC_TILE_H,//h
      6, //destination space
      0,//destination door
    }, 
    {//door top left on space 6
      2 * LOGIC_TILE_W,//x
      2 * LOGIC_TILE_W,//w
      LOGIC_TILE_H,//y
      2 * LOGIC_TILE_H,//h
      4, //destination space
      3,//destination door
    }
  },
   //SPACE 7, The parallel Lab
  {
    {//door top right on space 7
      SPACE_W - 5 * LOGIC_TILE_W,//x
      2 * LOGIC_TILE_W,//width
      0,//y
      5 * LOGIC_TILE_H,//height
      5, //destination space
      2,//destination door
    },
    {//door bottom middle on space 7
      14 * LOGIC_TILE_W,//x
      3 * LOGIC_TILE_W,//width
      SPACE_H - 7 * LOGIC_TILE_H,//y
      5 * LOGIC_TILE_H,//height
      7, //destination space
      0,//destination door
    },
    {//door bottom right on space 7
      SPACE_W - (6 * LOGIC_TILE_W),//x
      2 * LOGIC_TILE_W,//w
      SPACE_H - (3 * LOGIC_TILE_H),//y
      2 * LOGIC_TILE_H,//h
      7, //destination space
      2,//destination door
    }, 
    {//door bottom right on space 7
      SPACE_W - (6 * LOGIC_TILE_W),//x
      2 * LOGIC_TILE_W,//w
      SPACE_H - (3 * LOGIC_TILE_H),//y
      2 * LOGIC_TILE_H,//h
      7, //destination space
      2,//destination door
    }
  },
  //SPACE 8, void
  {
    {//door bottom left on space 8
      5 * LOGIC_TILE_W,//x
      3 * LOGIC_TILE_W,//width
      SPACE_H - 6 * LOGIC_TILE_H,//y
      5 * LOGIC_TILE_H,//height
      6, //destination space
      1,//destination door
    },
    {//door top right on space 8
      SPACE_W - 5 * LOGIC_TILE_W,//x
      3 * LOGIC_TILE_W,//width
      3 * LOGIC_TILE_H,//y
      2 * LOGIC_TILE_H,//height
      1, //destination space
      2,//destination door
    },
    {//door top left on space 8
      5 * LOGIC_TILE_W,//x
      2 * LOGIC_TILE_W,//w
      2 * LOGIC_TILE_H,//y
      LOGIC_TILE_H,//h
      6, //destination space
      2,//destination door
    }, 
    {//door top left on space 8
      5 * LOGIC_TILE_W,//x
      2 * LOGIC_TILE_W,//w
      2 * LOGIC_TILE_H,//y
      LOGIC_TILE_H,//h
      6, //destination space
      2,//destination door
    }
  },
};
#endif

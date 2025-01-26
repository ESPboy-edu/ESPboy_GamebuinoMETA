/**
 * -------------------------------------------------------------------------
 *         The famous Minesweeper game ported to the Gamebuino Meta
 * -------------------------------------------------------------------------
 *                         © 2025 Steph @ m1cr0lab
 *                      https://gamebuino.m1cr0lab.com
 * -------------------------------------------------------------------------
 */

#pragma once

#include <Gamebuino-Meta.h>

const PROGMEM Gamebuino_Meta::Sound_FX SFX_HOME[] = {
  { Gamebuino_Meta::Sound_FX_Wave::SQUARE, 1, 255, -128, 0, 30, 2 },
  { Gamebuino_Meta::Sound_FX_Wave::SQUARE, 1, 255, -128, 0, 28, 2 },
  { Gamebuino_Meta::Sound_FX_Wave::SQUARE, 1, 255, -128, 0, 25, 2 },
  { Gamebuino_Meta::Sound_FX_Wave::SQUARE, 1, 255, -128, 0, 22, 2 },
  { Gamebuino_Meta::Sound_FX_Wave::SQUARE, 1, 255, -128, 0, 20, 2 },
  { Gamebuino_Meta::Sound_FX_Wave::SQUARE, 1, 255, -128, 0, 18, 2 },
  { Gamebuino_Meta::Sound_FX_Wave::NOISE,  0,   0,    0, 0,  0, 0 }
};

const PROGMEM Gamebuino_Meta::Sound_FX SFX_CONF_STATS[] = {
  { Gamebuino_Meta::Sound_FX_Wave::SQUARE, 1, 255, -128, 0, 28, 2 },
  { Gamebuino_Meta::Sound_FX_Wave::SQUARE, 1, 255, -128, 0, 22, 2 },
  { Gamebuino_Meta::Sound_FX_Wave::SQUARE, 1, 255, -128, 0, 18, 2 },
  { Gamebuino_Meta::Sound_FX_Wave::NOISE,  0,   0,    0, 0,  0, 0 }
};

const PROGMEM Gamebuino_Meta::Sound_FX SFX_BACK[] = {
  { Gamebuino_Meta::Sound_FX_Wave::SQUARE, 1, 255, -128, 0, 18, 2 },
  { Gamebuino_Meta::Sound_FX_Wave::SQUARE, 1, 255, -128, 0, 20, 2 },
  { Gamebuino_Meta::Sound_FX_Wave::SQUARE, 1, 255, -128, 0, 22, 2 },
  { Gamebuino_Meta::Sound_FX_Wave::NOISE,  0,   0,    0, 0,  0, 0 }
};

const PROGMEM Gamebuino_Meta::Sound_FX SFX_START[] = {
  { Gamebuino_Meta::Sound_FX_Wave::SQUARE, 1, 255,    0,  0, 67,  4 },
  { Gamebuino_Meta::Sound_FX_Wave::NOISE,  1,   0, -128,  0,  0,  8 },
  { Gamebuino_Meta::Sound_FX_Wave::SQUARE, 1, 255,    0,  0, 67,  4 },
  { Gamebuino_Meta::Sound_FX_Wave::SQUARE, 0, 255,    0,  0, 50, 15 }
};

const PROGMEM Gamebuino_Meta::Sound_FX SFX_TICK[] = {
  { Gamebuino_Meta::Sound_FX_Wave::SQUARE, 0, 255, -128, 0, 10, 10 }
};

const PROGMEM Gamebuino_Meta::Sound_FX SFX_FLAG[] = {
  { Gamebuino_Meta::Sound_FX_Wave::NOISE, 0, 255, -64, 64, 80, 4 }
};

const PROGMEM Gamebuino_Meta::Sound_FX SFX_VISIT[] = {
  { Gamebuino_Meta::Sound_FX_Wave::SQUARE, 0, 255, -128, 0, 17, 10 }
};

const PROGMEM Gamebuino_Meta::Sound_FX SFX_EXPLORE[] = {
  { Gamebuino_Meta::Sound_FX_Wave::SQUARE, 0, 255, 0, -6, 13, 10 }
};

const PROGMEM Gamebuino_Meta::Sound_FX SFX_EXPLODE[] = {
  { Gamebuino_Meta::Sound_FX_Wave::NOISE, 0, 255, -4, -8, 128, 20 }
};

const PROGMEM Gamebuino_Meta::Sound_FX SFX_WIN[] = {
  { Gamebuino_Meta::Sound_FX_Wave::SQUARE, 1, 255, -128, 0, 63, 3 },
  { Gamebuino_Meta::Sound_FX_Wave::SQUARE, 1, 255, -128, 0, 35, 6 },
  { Gamebuino_Meta::Sound_FX_Wave::SQUARE, 1, 255, -128, 0, 28, 3 },
  { Gamebuino_Meta::Sound_FX_Wave::NOISE,  0,   0,    0, 0,  0, 0 }
};

const PROGMEM Gamebuino_Meta::Sound_FX SFX_LOST[] = {
  { Gamebuino_Meta::Sound_FX_Wave::SQUARE, 1, 255, -128, 0,  28, 3 },
  { Gamebuino_Meta::Sound_FX_Wave::SQUARE, 1, 255, -128, 0,  36, 6 },
  { Gamebuino_Meta::Sound_FX_Wave::SQUARE, 1, 255, -128, 0,  64, 6 },
  { Gamebuino_Meta::Sound_FX_Wave::SQUARE, 1, 255, -128, 0, 128, 9 },
  { Gamebuino_Meta::Sound_FX_Wave::NOISE,  0,   0,    0, 0,   0, 0 }
};
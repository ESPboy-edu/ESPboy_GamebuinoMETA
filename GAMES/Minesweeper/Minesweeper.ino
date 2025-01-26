/**
 * -------------------------------------------------------------------------
 *         The famous Minesweeper game ported to the Gamebuino Meta
 * -------------------------------------------------------------------------
 *                         © 2025 Steph @ m1cr0lab
 *                      https://gamebuino.m1cr0lab.com
 * -------------------------------------------------------------------------
 */

#include <Gamebuino-Meta.h>

#include "src/sprites.h"
#include "src/sounds.h"

constexpr uint8_t   SCREEN_WIDTH    = 128;
constexpr uint8_t   SCREEN_HEIGHT   = 128;
constexpr uint8_t   CELL_SIZE       = 8;
constexpr uint8_t   BOARD_WIDTH     = SCREEN_WIDTH / CELL_SIZE;
constexpr uint8_t   BOARD_HEIGHT    = SCREEN_HEIGHT / CELL_SIZE;
constexpr uint8_t   EMOJI_SIZE      = 17;
constexpr uint8_t   SPLASH_WIDTH    = 120;
constexpr uint8_t   SPLASH_HEIGHT   = 28;
constexpr uint8_t   FONT_SIZE       = 5;
constexpr uint8_t   SELECTOR_WIDTH  = 3;
constexpr uint8_t   SELECTOR_HEIGHT = 5;
constexpr uint8_t   DIGIT_WIDTH     = 14;
constexpr uint8_t   DIGIT_HEIGHT    = 29;
constexpr uint8_t   LEVELS          = 3;
constexpr uint8_t   BOMBS[LEVELS]   = { 30, 50, 70 };
constexpr uint8_t   SAVING_BLOCK    = 0;
constexpr uint16_t  WON_TIMEOUT_MS  = 2000;
constexpr uint16_t  LOST_TIMEOUT_MS = 3000;
constexpr uint32_t  MAX_TIME_MS     = 999000;

enum class GameState : uint8_t {
  SPLASH,
  LEVELS,
  START,
  PLAY,
  TIME,
  WIN,
  WON,
  LOST,
  BEST_TIME
};

enum class Level : uint8_t { BEGINNER, INTERMEDIATE, EXPERT };

struct Cell {
  bool    mined;
  bool    exploded;
  bool    visited;
  bool    flagged;
  uint8_t threats;

  void reset() {
    mined    = false;
    exploded = false;
    visited  = false;
    flagged  = false;
    threats  = 0;
  }
};

struct Player {
  uint8_t x;
  uint8_t y;
};

Cell      board[BOARD_HEIGHT][BOARD_WIDTH];
uint32_t  best_time[LEVELS];
uint32_t  start_time_ms;
uint32_t  play_time_ms;
Player    player;
Level     level = Level::BEGINNER;
uint16_t  visited_count;
uint16_t  flagged_count;
GameState game_state = GameState::SPLASH;
Image     sprites(CELL_SPRITES);
Image     emoji(EMOJI_SPRITES);
Image     splash(SPLASH_TITLE);
Image     labels(LABEL_SPRITES);
Image     selector(MENU_SELECTOR);
Image     digits(DIGIT_SPRITES);

void load_best_time() {
  bool  loaded = gb.save.get(SAVING_BLOCK, best_time, sizeof(best_time));
  if (!loaded) {
    for (uint8_t i = 0; i < 3; ++i) {
      best_time[i] = MAX_TIME_MS;
    }
  }
}

void save_best_time() {
  gb.save.set(SAVING_BLOCK, best_time, sizeof(best_time));
}

void reset_board() {
  for (uint8_t i = 0; i < BOARD_HEIGHT; ++i) {
    for (uint8_t j = 0; j < BOARD_WIDTH; ++j) {
      board[i][j].reset();
    }
  }
}

void add_bomb(uint8_t  x, uint8_t  y) {
  board[y][x].mined = true;
  for (int8_t i = -1; i < 2; ++i) {
    int  yi = y + i;
    if (yi == -1 || yi == BOARD_HEIGHT) continue;
    for (int8_t j = -1; j < 2; ++j) {
      int  xj = x + j;
      if (xj == -1 || xj == BOARD_WIDTH) continue;
      if (xj == x && yi == y) continue;
      Cell*  c = &board[yi][xj];
      if (!c->mined) c->threats++;
    }
  }
}

void scatter_bombs() {
  for (uint8_t i = 0; i < BOMBS[(uint8_t)level]; ++i) {
    uint8_t x, y;
    do {
      x = random(BOARD_WIDTH);
      y = random(BOARD_HEIGHT);
    } while (board[y][x].mined);
    add_bomb(x, y);
  }
}

void start() {
  reset_board();
  scatter_bombs();
  player.x      = BOARD_WIDTH >> 1;
  player.y      = BOARD_HEIGHT >> 1;
  visited_count = 0;
  flagged_count = 0;
  start_time_ms = millis();
  game_state    = GameState::PLAY;
}

void explore(uint8_t  x, uint8_t  y) {
  for (int8_t i = -1; i < 2; ++i) {
    int  yi = y + i;
    if (yi == -1 || yi == BOARD_HEIGHT) continue;
    for (int8_t j = -1; j < 2; ++j) {
      int  xj = x + j;
      if (xj == -1 || xj == BOARD_WIDTH) continue;
      if (xj == x && yi == y) continue;
      Cell*  c = &board[yi][xj];
      if (c->visited || c->flagged) continue;
      c->visited = true;
      visited_count++;
      if (!c->threats) {
        explore(xj, yi);
      }
    }
  }
}

void splash_screen() {
  if (gb.buttons.pressed(BUTTON_A)) {
    game_state = GameState::LEVELS;
    gb.sound.fx(SFX_CONF_STATS);
  }
}

void level_menu() {

  if (gb.buttons.pressed(BUTTON_A)) {

    game_state = GameState::START;
    gb.sound.fx(SFX_START);

  } else if (gb.buttons.pressed(BUTTON_B)) {

    game_state = GameState::SPLASH;
    gb.sound.fx(SFX_BACK);

  } else if (gb.buttons.pressed(BUTTON_DOWN)) {

    uint8_t level_index = (uint8_t)level;

    ++level_index %= LEVELS;
    level = static_cast<Level>(level_index);

    gb.sound.fx(SFX_TICK);

  } else if (gb.buttons.pressed(BUTTON_UP)) {

    uint8_t level_index = (uint8_t)level + LEVELS;

    --level_index %= LEVELS;
    level = static_cast<Level>(level_index);

    gb.sound.fx(SFX_TICK);

  }

}

bool has_won_the_game() {
  return flagged_count + visited_count == BOARD_WIDTH * BOARD_HEIGHT;
}

void play() {

  play_time_ms = millis();

  if (play_time_ms - start_time_ms > MAX_TIME_MS) {
    game_state = GameState::LOST;
    return;
  }

  uint8_t  frames = 3;

  if (gb.buttons.repeat(BUTTON_LEFT, frames) && player.x > 0) {
    player.x--;
  } else if (gb.buttons.repeat(BUTTON_RIGHT, frames) && player.x + 1 < BOARD_WIDTH) {
    player.x++;
  }

  if (gb.buttons.repeat(BUTTON_UP, frames) && player.y > 0) {
    player.y--;
  } else if (gb.buttons.repeat(BUTTON_DOWN, frames) && player.y + 1 < BOARD_HEIGHT) {
    player.y++;
  }

  Cell*  c = &board[player.y][player.x];

  if (gb.buttons.pressed(BUTTON_A) && !c->visited && !c->flagged) {

    if (c->mined) {

      c->exploded = true;
      game_state  = GameState::LOST;
      gb.sound.fx(SFX_EXPLODE);

    } else {

      c->visited = true;
      visited_count++;

      if (!c->threats) {

        gb.sound.fx(SFX_EXPLORE);
        explore(player.x, player.y);

      } else {

        gb.sound.fx(SFX_VISIT);

      }

    }

  } else if (gb.buttons.pressed(BUTTON_B) && !c->visited && (c->flagged || flagged_count < BOMBS[(uint8_t)level])) {

    c->flagged = !c->flagged;
    flagged_count += c->flagged ? 1 : -1;
    gb.sound.fx(SFX_FLAG);

  } else if (gb.buttons.pressed(BUTTON_MENU)) {

    game_state = GameState::TIME;
    gb.sound.fx(SFX_CONF_STATS);

  }

  if (has_won_the_game()) {
    game_state = GameState::WIN;
    gb.sound.fx(SFX_WIN);
  }

}

void show_time(bool ending = false) {

  if (!ending) play_time_ms = millis();

  bool  action = ending ? gb.buttons.pressed(BUTTON_MENU) || gb.buttons.pressed(BUTTON_A)
                             : gb.buttons.pressed(BUTTON_MENU) || gb.buttons.pressed(BUTTON_B);
  if (action) {

    if (ending) {

      game_state = GameState::SPLASH;
      gb.sound.fx(SFX_HOME);

    } else {

      game_state = GameState::PLAY;
      gb.sound.fx(SFX_BACK);

    }

  }

}

void win() {

  uint32_t  time = play_time_ms - start_time_ms;

  if (time < best_time[(uint8_t)level]) {
    best_time[(uint8_t)level] = time;
    save_best_time();
  }

  game_state = GameState::WON;

}

void won() {
  if (gb.buttons.pressed(BUTTON_MENU) || millis() - play_time_ms > WON_TIMEOUT_MS) {
    game_state = GameState::BEST_TIME;
    gb.sound.fx(SFX_CONF_STATS);
  }
}

void lost() {
  if (gb.buttons.pressed(BUTTON_MENU) || millis() - play_time_ms > LOST_TIMEOUT_MS) {
    game_state = GameState::BEST_TIME;
    gb.sound.fx(SFX_LOST);
  }
}

void update() {
  switch (game_state) {
    case GameState::SPLASH:    splash_screen(); break;
    case GameState::LEVELS:    level_menu();    break;
    case GameState::START:     start();         break;
    case GameState::PLAY:      play();          break;
    case GameState::TIME:      show_time();     break;
    case GameState::WIN:       win();           break;
    case GameState::WON:       won();           break;
    case GameState::LOST:      lost();          break;
    case GameState::BEST_TIME: show_time(true); break;
    default:;
  }
}

uint8_t  SPLASH_BOARD_WIDTH = 14;
uint8_t  SPLASH_BOARD_HEIGHT = 7;
uint8_t  SPLASH_BOARD[7][14] = {
  0xf, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xf, 0x0, 0x0, 0x0, 0x0, 0xf, 0xf,
  0x0, 0x6, 0x6, 0x6, 0x7, 0x2, 0x0, 0x0, 0x0, 0x7, 0x6, 0x7, 0x0, 0xf,
  0x0, 0x8, 0x6, 0x1, 0x6, 0x6, 0x7, 0x8, 0x2, 0x7, 0x1, 0x6, 0x6, 0x0,
  0x0, 0x0, 0x7, 0x1, 0x1, 0x1, 0x1, 0x6, 0x6, 0x6, 0x1, 0x1, 0x6, 0x0,
  0xf, 0x0, 0x8, 0x7, 0x6, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x7, 0x0,
  0xf, 0xf, 0x0, 0x0, 0x7, 0x7, 0x6, 0x1, 0x1, 0x6, 0x6, 0x6, 0x7, 0x0,
  0xf, 0xf, 0xf, 0xf, 0x0, 0x2, 0x6, 0x6, 0x1, 0x6, 0x2, 0x0, 0x0, 0xf
};

void draw_splash() {

  uint8_t  h  = SCREEN_HEIGHT >> 1;
  uint8_t  xs = (SCREEN_WIDTH - SPLASH_WIDTH) >> 1;
  uint8_t  ys = h - SPLASH_HEIGHT - 8;
  uint8_t  xe = (SCREEN_WIDTH - EMOJI_SIZE) >> 1;
  uint8_t  ye = ys - EMOJI_SIZE - 4;

  gb.display.clear(ColorIndex::pink);  // 0xe

  emoji.setFrame(0);
  gb.display.drawImage(xe, ye, emoji);
  gb.display.drawImage(xs, ys, splash);

  for (uint8_t i = 0; i < SPLASH_BOARD_HEIGHT; ++i) {

    uint8_t  y = SCREEN_HEIGHT - SPLASH_BOARD_HEIGHT * CELL_SIZE + i * CELL_SIZE;

    for (uint8_t j = 0; j < SPLASH_BOARD_WIDTH; ++j) {

      uint8_t  x = ((SCREEN_WIDTH - SPLASH_BOARD_WIDTH * CELL_SIZE) >> 1) + j * CELL_SIZE;
      uint8_t  c = SPLASH_BOARD[i][j];

      if (c < 0xf) {
        sprites.setFrame(c);
        gb.display.drawImage(x, y, sprites);
      }

    }

  }

}

void draw_levels() {

  uint8_t  nb_labels = 4;
  uint8_t max_w = 0;

  for (uint8_t i = 0; i < nb_labels; ++i) {
    uint8_t lw = LABEL_XYW[i * 3 + 2];
    if (lw > max_w) max_w = lw;
  }

  uint8_t  h_margin = 6;
  uint8_t  mx = (SCREEN_WIDTH - max_w) >> 1;
  uint8_t  my = (SCREEN_HEIGHT - nb_labels * FONT_SIZE - (nb_labels - 1) * h_margin) >> 1;
  uint8_t  sx = mx - SELECTOR_WIDTH - 4;
  uint8_t  sy = my + (FONT_SIZE + h_margin) * (uint8_t)level;

  gb.display.clear(ColorIndex::pink);  // 0xe

  gb.display.drawImage(sx, sy, selector);
  gb.display.drawImage(
    mx,
    my - (h_margin << 1) - FONT_SIZE,
    labels,
    LABEL_XYW[0],
    LABEL_XYW[1],
    LABEL_XYW[2],
    FONT_SIZE
  );

  for (uint8_t i = 1; i < 4; ++i) {

    uint8_t  lx = LABEL_XYW[i * 3];
    uint8_t  ly = LABEL_XYW[i * 3 + 1];
    uint8_t  lw = LABEL_XYW[i * 3 + 2];

    gb.display.drawImage(
      mx,
      my + (i - 1) * (FONT_SIZE + h_margin),
      labels,
      lx,
      ly,
      lw,
      FONT_SIZE
    );
  }

}

uint8_t get_play_frame(Cell& c) {

  uint8_t frame = 0;

  if (c.visited) {

         if (c.mined)   frame = 3;
    else if (c.threats) frame = 5 + c.threats;
    else                frame = 1;

  } else if (c.flagged) {

    frame = 2;

  }

  return frame;

}

uint8_t get_lost_frame(Cell& c) {

  uint8_t frame = 0;

       if (c.exploded) frame = 4;
  else if (c.flagged)  frame = c.mined ? 2 : 5;
  else if (c.mined)    frame = 3;
  else if (c.visited)  frame = c.threats ? 5 + c.threats : 1;

  return frame;

}

uint8_t get_frame(Cell& c) {
  switch (game_state) {
    case GameState::PLAY:
    case GameState::WIN:
    case GameState::WON:  return get_play_frame(c);
    case GameState::LOST: return get_lost_frame(c);
  }
return 0;
}

void draw_board() {
  gb.display.clear();
  for (uint8_t i = 0; i < BOARD_HEIGHT; ++i) {
    for (uint8_t j = 0; j < BOARD_WIDTH; ++j) {
      sprites.setFrame(get_frame(board[i][j]));
      gb.display.drawImage(j * CELL_SIZE, i * CELL_SIZE, sprites);
    }
  }
}

void draw_player() {
  gb.display.setColor(0x4);
  gb.display.drawRect(
    player.x * CELL_SIZE - 1,
    player.y * CELL_SIZE - 1,
    CELL_SIZE + 2,
    CELL_SIZE + 2
  );
  gb.display.drawRoundRect(
    player.x * CELL_SIZE - 2,
    player.y * CELL_SIZE - 2,
    CELL_SIZE + 4,
    CELL_SIZE + 4,
    2
  );
}

void draw_number(
  uint16_t  n,
  uint8_t   len,
  uint8_t   x,
  uint8_t   y,
  uint8_t   margin = 1) {

    char format[7];
    char buffer[len + 1];

    snprintf(format, 7, "%%0%uu", len);
    snprintf(buffer, len + 1, format, n);

    for (uint8_t i = 0; i < len; ++i) {
      uint8_t  f = buffer[i] - 48;
      digits.setFrame(f);
      gb.display.drawImage(x + i * (margin + DIGIT_WIDTH), y, digits);
    }

}

void draw_time(bool ending = false) {

  uint8_t   bombs = BOMBS[(uint8_t)level] - flagged_count;
  uint32_t  time  = (play_time_ms - start_time_ms) / 1000;

  uint8_t  boffset = 4 * 3;
  uint8_t  bw      = LABEL_XYW[boffset + 2];
  uint8_t  bsw     = DIGIT_WIDTH * 2 + 1;
  uint8_t  mbw     = max(bw, bsw);

  uint8_t  toffset = boffset + 3;
  uint8_t  tw      = LABEL_XYW[toffset + 2];
  uint8_t  tsw     = DIGIT_WIDTH * 3 + 2;
  uint8_t  mtw     = max(tw, tsw);

  uint8_t  h_margin = (SCREEN_WIDTH - mbw - mtw) / 3;
  uint8_t  bx       = h_margin + ((mbw - bw) >> 1);
  uint8_t  bsx      = h_margin + ((mbw - bsw) >> 1);
  uint8_t  tx       = (h_margin << 1) + mbw + ((mtw - tw) >> 1);
  uint8_t  tsx      = (h_margin << 1) + mbw + ((mtw - tsw) >> 1);

  uint8_t yl = ending
                ? (SCREEN_HEIGHT - EMOJI_SIZE - ((FONT_SIZE + 6 + DIGIT_HEIGHT) << 1)) >> 2
                : (SCREEN_HEIGHT - (FONT_SIZE + 6 + DIGIT_HEIGHT)) >> 1;

  uint8_t yn = yl + FONT_SIZE + 6;

  uint8_t  v_margin = ending ? yl : 0;


  gb.display.clear(ColorIndex::pink);  // 0xe

  if (ending) {
    emoji.setFrame(has_won_the_game() ? 1 : 2);
    gb.display.drawImage((SCREEN_WIDTH - EMOJI_SIZE) >> 1, yl, emoji);
    yl += EMOJI_SIZE + v_margin;
    yn = yl + FONT_SIZE + 6;
  }

  gb.display.drawImage(
    bx,
    yl,
    labels,
    LABEL_XYW[boffset],
    LABEL_XYW[boffset + 1],
    bw,
    FONT_SIZE
  );

  draw_number(bombs, 2, bsx, yn, 1);

  gb.display.drawImage(
    tx,
    yl,
    labels,
    LABEL_XYW[toffset],
    LABEL_XYW[toffset + 1],
    tw,
    FONT_SIZE
  );

  draw_number(time, 3, tsx, yn, 1);

  if (ending) {

    yl += FONT_SIZE + 6 + DIGIT_HEIGHT + v_margin;
    yn = yl + FONT_SIZE + 6;

    uint8_t  btoffset = toffset + 3;
    uint8_t  btw      = LABEL_XYW[btoffset + 2];
    uint8_t  btsw     = DIGIT_WIDTH * 3 + 2;
    uint8_t  btx      = (SCREEN_WIDTH - btw) >> 1;
    uint8_t  btsx     = (SCREEN_WIDTH - btsw) >> 1;

    gb.display.drawImage(
      btx,
      yl,
      labels,
      LABEL_XYW[btoffset],
      LABEL_XYW[btoffset + 1],
      btw,
      FONT_SIZE
    );

    draw_number(best_time[(uint8_t)level] / 1000, 3, btsx, yn, 1);

  }

}

void draw() {
  switch (game_state) {
    case GameState::SPLASH:    draw_splash();   break;
    case GameState::START:
    case GameState::LEVELS:    draw_levels();   break;
    case GameState::PLAY:
      draw_board();
      draw_player();
      break;
    case GameState::TIME:      draw_time();     break;
    case GameState::WIN:
    case GameState::WON:       draw_board();    break;
    case GameState::LOST:      draw_board();    break;
    case GameState::BEST_TIME: draw_time(true); break;
    default:;
  }
}

float_t hue2rgb(float_t p, float_t q, float_t t) {
  if (t < 0) t += 1.f;
  if (t > 1) t -= 1.f;
  if (t < 1.f / 6.f) return p + (q - p) * 6.f * t;
  if (t < 1.f / 2.f) return q;
  if (t < 2.f / 3.f) return p + (q - p) * 6.f * ((2.f / 3.f) - t);
  return p;
}

uint16_t hsl2rgb(float_t h, float_t s, float_t l) {

  float_t r, g, b;

  if (s == 0) {

    r = g = b = l;

  } else {

    float_t q = l < .5f ? l * (1 + s) : l + s - l * s;
    float_t p = 2 * l - q;

    r = hue2rgb(p, q, h + 1.f/3.f);
    g = hue2rgb(p, q, h);
    b = hue2rgb(p, q, h - 1.f/3.f);

  }

  uint8_t  red   = r * 255.f;
  uint8_t  green = g * 255.f;
  uint8_t  blue  = b * 255.f;

  return (red >> 3) << 11 | (green >> 2) << 5 | blue >> 3;

}

void wave(uint32_t  ticks, uint16_t hue, uint8_t speed) {
/*
  uint8_t  t = (ticks << speed) & 0xff;
  float_t  a = .02464f * t; // (2 * π / 255)
  float_t  l = .25f * (1 + sin(a));
  float_t  h = hue / 360.f;

  for (uint8_t i = 0; i < 4; ++i) {
    gb.lights._buffer[2*i] = gb.lights._buffer[2*i + 1] = hsl2rgb(h, 1.f, l);
  }
*/
}

void light_splash(uint32_t  ticks) {
  //for (uint8_t i = 0; i < 4; ++i) {
    //float_t  hue = (((ticks + i*5) << 3) % 360) / 360.f;
    //gb.lights._buffer[2*i] = gb.lights._buffer[2*i + 1] = hsl2rgb(hue, 1.f, .5f);
 // }
}

void light_time(uint32_t  ticks) {
  wave(ticks, 240, 2);
}

void light_won(uint32_t  ticks) {
  wave(ticks, 120, 5);
}

void light_lost(uint32_t  ticks) {
  wave(ticks, 359, 6);
}

void light_best_time(uint32_t  ticks) {
  wave(ticks, has_won_the_game() ? 140 : 40, 2);
}

void light() {
/*
  static uint32_t ticks = 0;

  switch (game_state) {
    case GameState::SPLASH:    light_splash(ticks);    break;
    case GameState::TIME:      light_time(ticks);      break;
    case GameState::WIN:
    case GameState::WON:       light_won(ticks);       break;
    case GameState::LOST:      light_lost(ticks);      break;
    case GameState::BEST_TIME: light_best_time(ticks); break;
    default:                   gb.lights.clear();
  }
  ticks++;
*/
}

void setup() {
  //Serial.begin(57600);
  gb.begin();
  gb.display.setPalette(PALETTE);
  load_best_time();
  gb.sound.fx(SFX_HOME);
}

void loop() {
  gb.waitForUpdate();
  update();
  draw();
  light();
}

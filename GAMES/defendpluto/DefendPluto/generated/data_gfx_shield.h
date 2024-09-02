/*
    Copyright Alex Margarit <alex@alxm.org>
    This file is part of Defend Pluto, a video game.
    Generated by assets/gfx/compile.py from ../assets/gfx/shield.png
*/

#if Z_PLATFORM_ARDUBOY

PROGMEM static const uint8_t z_data_gfx_shield_frames = 1;

PROGMEM static const uint8_t z_data_gfx_shield_buffer[] = {
    // Frame dimension
    7, 8,

    // Image frames
    0x00,0x1e,0x3e,0x7e,0x22,0x1e,0x00,

    // Mask frames
    0x1f,0x3f,0x7f,0xff,0x7f,0x3f,0x1f,
};

#elif Z_PLATFORM_META

PROGMEM static const uint8_t z_data_gfx_shield_frames = 1;

PROGMEM static const uint16_t z_data_gfx_shield_buffer[] = {
    // Frame dimension
    7, 8,

    // Number of frames, looping
    1, 0,

    // Transparent color, color mode
    0xf81f, 0,

    // Image frames
    0x10a4,0x10a4,0x10a4,0x10a4,0x10a4,0x10a4,0x10a4,0x10a4,0xd988,0xd988,0xd988,0xd988,0xd988,0x10a4,0x10a4,0xd988,0xd988,0xd988,0x10a4,0xd988,0x10a4,0x10a4,0xd988,0xd988,0xd988,0x10a4,0xd988,0x10a4,0x10a4,0xd988,0xd988,0xd988,0x10a4,0xd988,0x10a4,0xf81f,0x10a4,0xd988,0xd988,0xd988,0x10a4,0xf81f,0xf81f,0xf81f,0x10a4,0xd988,0x10a4,0xf81f,0xf81f,0xf81f,0xf81f,0xf81f,0x10a4,0xf81f,0xf81f,0xf81f,
};

#endif

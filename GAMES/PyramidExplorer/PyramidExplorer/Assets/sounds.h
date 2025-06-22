#pragma once

const PROGMEM Gamebuino_Meta::Sound_FX selectionSfx[] = {
    {Gamebuino_Meta::Sound_FX_Wave::NOISE,0,50,-4,6,79,10}
};

const PROGMEM Gamebuino_Meta::Sound_FX positiveEventSfx[] = {
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,60,-8,5,60,8},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,50,-3,10,70,8},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,60,-8,5,90,8}
};

const PROGMEM Gamebuino_Meta::Sound_FX negativeEventSfx[] = {
    {Gamebuino_Meta::Sound_FX_Wave::NOISE,1,60,2,3,70,5},
    {Gamebuino_Meta::Sound_FX_Wave::NOISE,0,30,0,20,70,10}
};

const PROGMEM Gamebuino_Meta::Sound_FX useKnowledgeSfx[] = {
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,60,-8,5,90,8}
};

const PROGMEM Gamebuino_Meta::Sound_FX damageSfx[] = {
    {Gamebuino_Meta::Sound_FX_Wave::NOISE,0,30,0,20,70,10}
};

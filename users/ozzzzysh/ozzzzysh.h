#pragma once

#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

#if defined(KEYMAP_SAFE_RANGE)
#    define PLACEHOLDER_SAFE_RANGE KEYMAP_SAFE_RANGE
#else
#    define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
    KC_SECRET_1 = PLACEHOLDER_SAFE_RANGE,
    KC_SECRET_2,
    KC_SECRET_3,
    KC_SECRET_4,
    KC_SECRET_5,
    KC_MAKE,
    SONG1,
    SONG2,
    SONG3,
    SONG4,
    NEW_SAFE_RANGE
};

//Tap Dance Declarations
enum {
    TD_QUOT_PIPE = 0,
    TD_TAB_ESC,
    TD_DOT_SLSH,
    TD_LSFT_CAPS
};

#endif
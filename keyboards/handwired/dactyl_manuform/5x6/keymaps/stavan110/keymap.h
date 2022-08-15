#pragma once

#include QMK_KEYBOARD_H

uint8_t mod_state;
uint8_t oneshot_mod_state;
uint16_t last_keycode;
bool caps_word_lock_on;

enum layer_names {
    _COLEMAK_DH,
    _PLOVER,
    _SYM,
    _NAV,
    _GNAV,
#ifdef MOUSEKEY_ENABLE
    _MOUSE,
#endif
    _ADJUST,
};

// Layer keys
#define NAV_TAB LT(_NAV, KC_TAB)
#define NAV MO(_NAV)
#define GNAV MO(_GNAV)
#define SYM MO(_SYM)
#define ADJUST MO(_ADJUST)
#define SYM_ENT LT(_SYM, KC_ENT)
#define PLOVER TG(_PLOVER)

#ifdef MOUSEKEY_ENABLE
#    define MOUSE MO(_MOUSE)
#    define MS_CAPS LT(_MOUSE, KC_CAPS)
#else
#    define MOUSE KC_TRNS
#    define MS_CAPS KC_CAPS
#endif

//IDE layer
#define RFTR_RENAME LSFT_T(KC_F6) // Shift + F6
#define COMMENT LCTL_T(KC_SLSH) // CRTL + /

// Miscellaneous keyboard shortcuts in direct access
#define UNDO LCTL(KC_Z)
#define REDO LCTL(KC_Y)
#define COMPOSE KC_APP
#define TG_MIC KC_F20 // Default binding for XF86AudioMicMute

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LSFT_T(KC_S)
#define HOME_T LCTL_T(KC_T)

// Right-hand home row mods
#define HOME_O RGUI_T(KC_O)
#define HOME_I LALT_T(KC_I)
#define HOME_E RSFT_T(KC_E)
#define HOME_N RCTL_T(KC_N)

// One Shot Modifiers
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_RALT OSM(MOD_RALT)
#define OS_LGUI OSM(MOD_LGUI)
#define OS_RGUI OSM(MOD_RGUI)

enum custom_keycodes {
    ARROW_R = SAFE_RANGE,
    // g navigation to move through screen lines in Vim
    G_DOWN,
    G_UP,
    G_HOME,
    G_END,
    // Macro to refer to the parent directory in Linux ../
    UPDIR,
    // "Yank Inner CODE"
    // Macro for
    // $yi{
    YICODE,
    REPEAT,
    // "Opening brace"
    // Macro for
    // {<enter>
    O_BRACE,
    // "Closing brace"
    // Macro for
    // }<enter>
    C_BRACE,
    CAPS_WORD_LOCK,
    // "Opening Bracket-Quote"
    // Macro for
    // ["
    O_BRQOT,
    // "Closing Bracket-Quote"
    // Macro for
    // "]
    C_BRQOT,

    //SELECT WORD
    SELWORD,
    // SELLINE,
    JOINLN


};

#ifdef TAP_DANCE_ENABLE
enum {
    DOT_TD,
};

#define TD_DOT TD(DOT_TD)
#else
#define TD_DOT KC_DOT
#endif

#include "gh60.h"
#include "action_layer.h"

enum layers {
    _BASE = 0,
    _NAV = 1,
    _ADJUST = 2,
    _GAME = 8,
    _GMNV = 9,
    _GMADJ = 10,
};

enum planck_keycodes {
  BASE = SAFE_RANGE,
  GAME,
};

enum macros {
    _RDY = 0,
};

#define _______ KC_TRNS
#define XXXXXXX XXXXXXX

#define NV_SCLN LT(_NAV, KC_SCLN)
#define NV_SPC  LT(_NAV, KC_SPC)
#define AD_GRV  LT(_ADJUST, KC_GRV)

/* ANSI with split-right shift. */
#define KM( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,      K2D, \
    K30, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B,      K3D, K3C, \
    K40, K41, K42,           K45,                     K4A, K4B, K4C, K4D  \
) { \
   { K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D }, \
   { K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D }, \
   { K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, KC_NO, K2D }, \
   { K30, KC_NO, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C,  K3D }, \
   { K40, K41, K42, KC_NO, KC_NO, K45, KC_NO, KC_NO, KC_NO, KC_NO, K4A, K4B, K4C, K4D } \
  }

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = KM(
        KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL ,  KC_BSPC,
        KC_TAB ,  KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS,
        MO(_NAV),  KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , NV_SCLN, KC_QUOT,         KC_ENT ,
        KC_LSFT,    KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,        KC_RSFT, AD_GRV ,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC ,                             KC_RALT, KC_RGUI, KC_APP , KC_RCTL),
    [_NAV] = KM(
        KC_GRV , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL ,
        _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , _______, _______, KC_PGUP, KC_UP  , KC_PGDN, _______, _______, _______, _______,
        _______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,          _______,
        _______, KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______, KC_END , _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______),
    [_ADJUST] = KM(
        RESET  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______,TG(_GAME),_______,                            _______,                            _______, _______, _______, _______),
    [_GAME] = KM(
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL ,  KC_BSPC,
        KC_TAB ,  KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS,
        KC_PAUS,   KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,         KC_ENT ,
        KC_LSFT,    KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,        KC_RSFT, MO(_GMADJ),
        KC_LCTL, KC_PGUP, KC_PGDN,                            KC_SPC ,                             KC_RALT, KC_RGUI,MO(_GMNV),KC_RCTL),
    [_GMNV] = KM(
        KC_ESC , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , _______, _______, KC_PGUP, KC_UP  , KC_PGDN, _______, _______, _______, _______,
        _______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,          _______,
        _______, KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______, KC_END , _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______),
    [_GMADJ] = KM(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______,TG(_GAME),_______,                            _______,                            _______, _______, _______, _______),
};

const uint16_t PROGMEM fn_actions[] = {
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
    switch(id) {
        case _RDY:
            return MACRODOWN(T(T), T(DOT), T(R), T(E), T(A), T(D), T(Y), T(ENT), END);
    }

    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GAME:
            layer_invert(_GAME);
            return false;
    }

    return true;
}

void matrix_scan_user(void) {
    //Layer LED indicators
    uint32_t layer = layer_state;

    if (layer & (1<<_GAME)) {
        gh60_wasd_leds_off();
    } else {
        gh60_wasd_leds_off();
    }
};

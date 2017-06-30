#include "zeal60.h"
#include "zeal_backlight.h"
#include "action_layer.h"
#include "solarized.h"

enum layers {
    _BASE = 0,
    _WORKMAN,
    _NORMAN,
    _NAV,
    _ADJUST,
    _RESET,
};

enum custom_keycodes {
  DEFAULTS = SAFE_RANGE,
  TOGGLE_BACKLIGHT,
  EFFECT,
  EFFECT_END = EFFECT + 10
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define NV_SPC  LT(_NAV, KC_SPC)

#define MO_NAV    MO(_NAV)
#define MO_ADJ    MO(_ADJUST)
#define TT_ADJ    TT(_ADJUST)
#define MO_RST    MO(_RESET)
#define TG_ADJ    TG(_ADJUST)
#define LY_QWER   DF(_BASE)
#define LY_WORK   DF(_WORKMAN)
#define LY_NRMN   DF(_NORMAN)
#define TG_BKLT   TOGGLE_BACKLIGHT
#define FX(x)     (EFFECT + x)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = KM(
      KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSLS, KC_GRV,
      KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSPC,
      KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,          KC_ENT ,
      KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,          KC_RSFT, TT_ADJ ,
      KC_LCTL, KC_LGUI, KC_LALT,                            NV_SPC ,                            KC_RALT, KC_RGUI, KC_RCTL, KC_F24 ),
  [_WORKMAN] = KM(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, KC_Q   , KC_D   , KC_R   , KC_W   , KC_B   , KC_J   , KC_F   , KC_U   , KC_P   , KC_SCLN, _______, _______, _______,
      _______, KC_A   , KC_S   , KC_H   , KC_T   , KC_G   , KC_Y   , KC_N   , KC_E   , KC_O   , KC_I   , _______,          _______,
      _______, KC_Z   , KC_X   , KC_M   , KC_C   , KC_V   , KC_K   , KC_L   , KC_COMM, KC_DOT , KC_SLSH,          _______, _______,
      _______, _______, _______,                            _______,                            _______, _______, _______, _______),
  [_NORMAN] = KM(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, KC_Q   , KC_W   , KC_D   , KC_F   , KC_K   , KC_J   , KC_U   , KC_R   , KC_L   , KC_SCLN, _______, _______, _______,
      _______, KC_A   , KC_S   , KC_E   , KC_T   , KC_G   , KC_Y   , KC_N   , KC_I   , KC_O   , KC_H   , _______,          _______,
      _______, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_P   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,          _______, _______,
      _______, _______, _______,                            _______,                            _______, _______, _______, _______),
  [_NAV] = KM(
      KC_GRV , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_VOLU, KC_INS , KC_PGUP, KC_UP  , KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL ,
      XXXXXXX, KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_MUTE, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,          XXXXXXX,
      XXXXXXX, KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_VOLD, KC_END , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX,
      MO_ADJ , XXXXXXX, XXXXXXX,                            XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),
  [_ADJUST] = KM(
      MO_RST , FX(1)  , FX(2)  , FX(3)  , FX(4)  , FX(5)  , FX(6)  , FX(7)  , FX(8)  , FX(9)  , FX(10) , BR_DEC , BR_INC , XXXXXXX, MO_RST ,
      XXXXXXX, H1_INC , S1_INC , H2_INC , S2_INC , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, EF_DEC , EF_INC , DEFAULTS,
      XXXXXXX, H1_DEC , S1_DEC , H2_DEC , S2_DEC , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
      XXXXXXX, LY_QWER, LY_WORK, LY_NRMN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, TG_ADJ ,
      XXXXXXX, AG_NORM, AG_SWAP,                            TG_BKLT,                            XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS),
  // To Reset hit FN + ` + Esc
  [_RESET] = KM(
      RESET  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET ,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),
};

// from zeal_backlight.c
// we want to be able to set indicators for the spacebar stabs
// but they are not represented by a row/index.
extern zeal_backlight_config g_config;
void map_row_column_to_led( uint8_t row, uint8_t column, uint8_t *led );

void set_backlight_defaults(void) {
  uint8_t space_stab_l = 36+6;
  uint8_t space_stab_r = 54+13;
  uint8_t space;
  uint8_t caps_lock;
  map_row_column_to_led(4, 13, &caps_lock);
  map_row_column_to_led(4, 7, &space);
  zeal_backlight_config default_values = {
    .use_split_backspace = 1,
    .use_split_left_shift = 0,
    .use_split_right_shift = 1,
    .use_7u_spacebar = 0,
    .use_iso_enter = 0,
    .disable_when_usb_suspended = 1,
    .disable_after_timeout = 0,
    .brightness = 255,
    .effect = 10,
    .color_1 = solarized.base2,
    .color_2 = solarized.base02,
    .caps_lock_indicator = { .index = caps_lock, .color = solarized.red },
    .layer_1_indicator = { .index = space_stab_l, .color = solarized.blue },
    .layer_2_indicator = { .index = space_stab_r, .color = solarized.yellow },
    .layer_3_indicator = { .index = space, .color = solarized.red },
    .alphas_mods = {
      BACKLIGHT_ALPHAS_MODS_ROW_0,
      BACKLIGHT_ALPHAS_MODS_ROW_1,
      BACKLIGHT_ALPHAS_MODS_ROW_2,
      BACKLIGHT_ALPHAS_MODS_ROW_3,
      BACKLIGHT_ALPHAS_MODS_ROW_4 }
  };
  memcpy(&g_config, &default_values, sizeof(zeal_backlight_config));
  backlight_config_save();

  solarized_t* S = &solarized;
  HSV alphas = S->base2;
  HSV custom_color_map[MATRIX_ROWS][MATRIX_COLS] = CM(
    S->red, alphas, alphas, alphas, alphas, alphas, alphas, alphas, alphas, alphas, alphas, alphas, alphas, alphas, S->red,
    S->orange, alphas, alphas, alphas, alphas, alphas, alphas, alphas, alphas, alphas, alphas, alphas, alphas, S->orange,
    S->green, alphas, alphas, alphas, alphas, alphas, alphas, alphas, alphas, alphas, alphas, alphas, S->green,
    S->blue, alphas, alphas, alphas, alphas, alphas, alphas, alphas, alphas, alphas, alphas, S->blue, S->blue,
    S->violet, S->magenta, S->yellow,              alphas,          S->yellow, S->magenta, S->violet, S->green
  );
  for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
    for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
      backlight_set_key_color(row, col, custom_color_map[row][col]);
    }
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint8_t last_effect;
  switch (keycode) {
    case DEFAULTS:
      if (IS_PRESSED(record->event)) set_backlight_defaults();
      return false;
    case TOGGLE_BACKLIGHT:
      if (IS_PRESSED(record->event)) {
        if (g_config.effect) {
          last_effect = g_config.effect;
          g_config.effect = 0;
        } else {
          g_config.effect = last_effect;
        }
      }
      return false;
    case EFFECT...EFFECT_END:
      if (IS_PRESSED(record->event)) {
        uint8_t effect = keycode - EFFECT;
        g_config.effect = effect;
        backlight_config_save();
      }
      return false;
  }

  return true;
}

void matrix_init_user(void) {
  if (!eeconfig_is_enabled()) {
    eeconfig_init();
    set_backlight_defaults();
  }
}

uint32_t default_layer_state_set_kb(uint32_t state) {
  // persist changes to default layers
  eeconfig_update_default_layer(state);
  return state;
}

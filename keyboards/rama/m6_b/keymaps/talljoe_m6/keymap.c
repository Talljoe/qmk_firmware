#include QMK_KEYBOARD_H
#include "keyboards/zeal60/rgb_backlight_keycodes.h"

enum custom_keycodes {
  GT_PUSH = SAFE_RANGE,
  GT_SYNC,
  GT_CMT,
  SH_RW1,
  MP_5,
  GT_BRNC
};

enum layers {
  BASE,
  ALT,
  CONFIG,
  DANGER,
};

#define MP_CFG LT(CONFIG, GT_BRNC)
#define MP_ALT LT(ALT, SH_RW1)
#define LY_RST MO(DANGER)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) return true;

  switch(keycode) {
    case GT_PUSH:
      SEND_STRING("git push -u origin $(git rev-parse --abbrev-ref HEAD)\n");
      return false;
    case GT_SYNC:
      SEND_STRING("git sync\n");
      return false;
    case GT_CMT:
      SEND_STRING("git commit -a -m \"\"" SS_TAP(X_LEFT));
      return false;
    case SH_RW1:
      SEND_STRING("ssh runway1.nw\n");
      return false;
    case GT_BRNC:
      SEND_STRING("git checkout -b ");
      return false;
  }

  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT(
        SH_RW1 , MP_5   , MP_CFG   ,
        GT_PUSH, GT_SYNC, MP_ALT   ),

    [ALT] = LAYOUT(
        KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO),

    [CONFIG] =LAYOUT(
        LY_RST , KC_NO  , KC_NO  ,
        KC_NO  , EF_DEC , EF_INC ),

    [DANGER] =LAYOUT(
        KC_NO, KC_NO, KC_NO,
        RESET, KC_NO, KC_NO)
};

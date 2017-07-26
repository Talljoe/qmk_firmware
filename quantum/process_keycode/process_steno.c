#include "process_steno.h"
#include "quantum_keycodes.h"
#include "keymap_steno.h"
#include "virtser.h"

uint8_t state[4] = {0};
uint8_t pressed = 0;

void send_steno_state(void) {
  for (uint8_t i = 0; i < 4; ++i) {
    if (state[i]) {
      virtser_send(state[i]);
      state[i] = 0;
    }
  }
  virtser_send(0);
}

bool process_steno(uint16_t keycode, keyrecord_t *record) {
  if(keycode >= QK_STENO && keycode <= QK_STENO_MAX) {
    if(IS_PRESSED(record->event)) {
      ++pressed;
      state[TXB_GET_GROUP(keycode)] |= (keycode & 0xff);
    } else {
      --pressed;
      if (pressed <= 0) {
        pressed = 0; // protect against spurious up keys
        send_steno_state();
      }
    }
    return false;
  }

  return true;
}

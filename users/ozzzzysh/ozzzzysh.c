#include "ozzzzysh.h"

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

__attribute__ ((weak))
bool matrix_scan_keymap(void) {
  return true;
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        // SEQ_TWO_KEYS(KC_LALT, KC_4) {
        //     // SS_LALT();
        //     SEND_STRING(SS_DOWN(KC_LALT));
        //     SEND_STRING(SS_TAP(KC_F4));
        //     SEND_STRING(SS_UP(KC_LALT));
        // }
        // SEQ_TWO_KEYS(KC_D, KC_D) {
        //     SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
        // }
        // SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
        //     SEND_STRING("https://start.duckduckgo.com\n");
        // }
        // SEQ_TWO_KEYS(KC_A, KC_S) {
        //     register_code(KC_LGUI);
        //     register_code(KC_S);
        //     unregister_code(KC_S);
        //     unregister_code(KC_LGUI);
        // }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_MAKE:  // Compiles the firmware, and adds the flash command based on keyboard bootloader
            if (!record->event.pressed) {
            uint8_t temp_mod = get_mods();
            uint8_t temp_osm = get_oneshot_mods();
            clear_mods(); clear_oneshot_mods();
            SEND_STRING("make " QMK_KEYBOARD ":" QMK_KEYMAP);
    #ifndef FLASH_BOOTLOADER
            if ((temp_mod | temp_osm) & MOD_MASK_SHIFT)
    #endif
            {
                SEND_STRING(":flash");
            }
            if ((temp_mod | temp_osm) & MOD_MASK_CTRL) {
                SEND_STRING(" -j8 --output-sync");
            }
            tap_code(KC_ENT);
            set_mods(temp_mod);
        }
        break;

  }
  return process_record_keymap(keycode, record);
}
#include QMK_KEYBOARD_H

/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_ortho_5x12(KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, TD(TD_QUOT_PIPE), TD(TD_LSFT_CAPS), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, TD(TD_DOT_SLSH), KC_UP, KC_ENT, KC_LCTL, KC_LGUI, KC_LALT, KC_LALT, MO(3), LCTL_T(KC_SPC), KC_SPC, MO(4), LT(6,KC_APP), KC_LEFT, KC_DOWN, KC_RGHT),
	[1] = LAYOUT_ortho_5x12(KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSPC, KC_ESC, KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, TD(TD_QUOT_PIPE), TD(TD_LSFT_CAPS), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, TD(TD_DOT_SLSH), KC_UP, KC_ENT, KC_LCTL, KC_LGUI, KC_LALT, KC_LALT, MO(3), LCTL_T(KC_SPC), KC_SPC, MO(4), LT(6,KC_APP), KC_LEFT, KC_DOWN, KC_RGHT),
	[2] = LAYOUT_ortho_5x12(KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, TD(TD_TAB_ESC), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_GRV, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, TD(TD_QUOT_PIPE), TD(TD_LSFT_CAPS), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, TD(TD_DOT_SLSH), KC_UP, KC_ENT, KC_LCTL, KC_LGUI, KC_LALT, MO(3), KC_SPC, KC_SPC, KC_SPC, MO(4), DF(1), KC_LEFT, KC_DOWN, KC_RGHT),
	[3] = LAYOUT_ortho_5x12(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_4, KC_5, KC_6, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_1, KC_2, KC_3, KC_TRNS, KC_VOLU, KC_MPLY, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, MO(5), KC_DOT, KC_MPRV, KC_VOLD, KC_MNXT),
	[4] = LAYOUT_ortho_5x12(KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_TRNS, KC_TRNS, KC_LCBR, KC_QUOT, KC_RCBR, KC_TRNS, KC_TRNS, KC_BSPC, KC_UP, KC_BSPC, KC_DEL, KC_BSPC, KC_DEL, KC_TRNS, KC_LPRN, KC_DQUO, KC_RPRN, KC_TRNS, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, KC_TRNS, KC_TRNS, KC_LT, KC_LBRC, KC_GRV, KC_RBRC, KC_GT, KC_TRNS, KC_ASTG, CK_TOGG, KC_TRNS, CK_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(5), KC_UNDS, KC_UNDS, KC_TRNS, KC_TRNS, KC_TRNS, CK_DOWN, CK_RST),
	[5] = LAYOUT_ortho_5x12(RGB_TOG, RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, RGB_SPI, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD, RGB_M_R, KC_NO, RESET, DF(0), DF(1), DF(2), KC_NO, KC_NO, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN3, KC_TRNS, KC_NO, KC_BTN1, KC_ACL0, KC_ACL1, KC_ACL2, KC_NO, KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, SONG1, SONG2, SONG3, SONG4, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_SECRET_4, KC_SECRET_3, KC_SECRET_2, KC_SECRET_1),
	[6] = LAYOUT_ortho_5x12(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_CALC, LGUI(LSFT(KC_S)), KC_PSCR, KC_NO, KC_NO, LCTL(LSFT(KC_LBRC)), LCTL(KC_QUOT), KC_NO, KC_NO, KC_NO, LCTL(LSFT(KC_TAB)), KC_NO, LCTL(KC_TAB), LGUI(LSFT(KC_S)), KC_PSCR, KC_NO, KC_NO, LCTL(LSFT(KC_9)), LCTL(LSFT(KC_QUOT)), KC_NO, KC_NO, KC_NO, LCTL(LGUI(KC_LEFT)), LGUI(KC_TAB), LCTL(LGUI(KC_RGHT)), KC_NO, KC_NO, KC_NO, LCTL(LSFT(KC_COMM)), LCTL(KC_LBRC), KC_NO, KC_NO, KC_NO, KC_NO, LCTL(KC_Z), KC_NO, LCTL(KC_Y), KC_VOLU, KC_MPLY, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MPRV, KC_VOLD, KC_MNXT)
};

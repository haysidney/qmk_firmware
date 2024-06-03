#include QMK_KEYBOARD_H

// === Generic Tap Dance Plumbing ===
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

//td_state_t cur_dance(tap_dance_state_t *state);

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

// === Tap Dance Implementations ===

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t quot_bsls_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
static td_tap_t lsft_caps_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// === QUOT_BSLS ===
//void quot_bsls_finished(tap_dance_state_t *state, void *user_data);
//void quot_bsls_reset(tap_dance_state_t *state, void *user_data);
void quot_bsls_finished(tap_dance_state_t *state, void *user_data) {
    quot_bsls_tap_state.state = cur_dance(state);
    switch (quot_bsls_tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_QUOT); break;
        case TD_SINGLE_HOLD: register_code(KC_LSFT); register_code(KC_QUOT); break;
        case TD_DOUBLE_TAP: register_code(KC_BSLS); break;
        case TD_DOUBLE_HOLD: register_code(KC_LSFT); register_code(KC_BSLS); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_QUOT); register_code(KC_QUOT); break;
        default: break;
    }
}
void quot_bsls_reset(tap_dance_state_t *state, void *user_data) {
    switch (quot_bsls_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_QUOT); break;
        case TD_SINGLE_HOLD: unregister_code(KC_QUOT); unregister_code(KC_LSFT); break;
        case TD_DOUBLE_TAP: unregister_code(KC_BSLS); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_BSLS); unregister_code(KC_LSFT); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_QUOT); break;
        default: break;
    }
    quot_bsls_tap_state.state = TD_NONE;
}

// === LSFT_CAPS ===
static bool caps_lock = false;
#define DEBOUNCE_CAPS_DELAY 100
void lsft_caps_finished(tap_dance_state_t *state, void *user_data) {
    lsft_caps_tap_state.state = cur_dance(state);
    if (lsft_caps_tap_state.state == TD_DOUBLE_TAP) {
        if (!caps_lock) {
            register_code(KC_CAPS_LOCK);
            return;
        }
    }

    if (caps_lock) {
        register_code(KC_CAPS_LOCK);
    } else {
        register_code(KC_LSFT);
    }
}
void lsft_caps_reset(tap_dance_state_t *state, void *user_data) {
    if (lsft_caps_tap_state.state == TD_DOUBLE_TAP) {
        if (!caps_lock) {
            caps_lock = true;
            wait_ms(DEBOUNCE_CAPS_DELAY);
            unregister_code(KC_CAPS_LOCK);
            return;
        }
    }

    if (caps_lock) {
        caps_lock = false;
        wait_ms(DEBOUNCE_CAPS_DELAY);
        unregister_code(KC_CAPS_LOCK);
    } else {
        unregister_code(KC_LSFT);
    }

    lsft_caps_tap_state.state = TD_NONE;
}

// === Tap Dance Declarations ===
enum {
    TD_QUOT_BSLS,
    TD_LSFT_CAPS
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_QUOT_BSLS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, quot_bsls_finished, quot_bsls_reset),
    [TD_LSFT_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lsft_caps_finished, lsft_caps_reset)
};

// === Layout ===
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_5x12(KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_F13, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, TD(TD_QUOT_BSLS), TD(TD_LSFT_CAPS), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT, KC_LCTL, KC_LGUI, KC_LALT, MO(5), MO(2), KC_SPC, KC_SPC, MO(3), KC_NO, KC_NO, DF(1), DF(0)),
    [1] = LAYOUT_ortho_5x12(KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSPC, KC_F13, KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, TD(TD_QUOT_BSLS), TD(TD_LSFT_CAPS), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT, KC_LCTL, KC_LGUI, KC_LALT, MO(5), MO(2), KC_SPC, KC_SPC, MO(3), KC_NO, KC_NO, DF(1), DF(0)),
    [2] = LAYOUT_ortho_5x12(KC_ESC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_7, KC_8, KC_9, KC_NO, KC_NO, KC_BSPC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_4, KC_5, KC_6, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_1, KC_2, KC_3, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_0, MO(4), KC_DOT, KC_NO, KC_NO, KC_NO),
    [3] = LAYOUT_ortho_5x12(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LCBR, KC_QUOT, KC_RCBR, KC_NO, KC_NO, KC_BSPC, KC_UP, KC_BSPC, KC_DEL, KC_NO, KC_NO, KC_NO, KC_LPRN, KC_DQUO, KC_RPRN, KC_NO, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, KC_NO, KC_TRNS, KC_NO, KC_LBRC, KC_GRV, KC_RBRC, KC_NO, KC_NO, AS_TOGG, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, MO(4), KC_NO, KC_MINS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO),
    [4] = LAYOUT_ortho_5x12(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN3, KC_NO, KC_NO, KC_NO, KC_ACL2, KC_ACL1, KC_ACL0, KC_NO, KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, AS_TOGG, KC_TRNS, KC_NO, RGB_RMOD, RGB_MOD, RGB_TOG),
    [5] = LAYOUT_ortho_5x12(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F10, KC_F11, KC_F12, KC_NO, KC_NO, KC_NO, KC_ESC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F7, KC_F8, KC_F9, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F4, KC_F5, KC_F6, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)
};

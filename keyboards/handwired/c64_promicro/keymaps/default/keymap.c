// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_PLUS, KC_MINS, KC_AMPR, KC_HOME, KC_BSPC, KC_PGUP,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_AT  , KC_ASTR, KC_BSLS, KC_LGUI,          KC_PGDN,
        KC_LALT,          KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_COLN, KC_SCLN, KC_EQL , KC_ENT ,          KC_UP  ,
        KC_LCTL, KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT, KC_LEFT, KC_RGHT,          KC_DOWN,
                          KC_SPC
    ),
};

void gen_shifted_keycode(keyrecord_t *record, uint16_t kc_normal, uint16_t kc_lshift, uint16_t kc_rshift)
{
    if (!record->event.pressed)
        return;

    // Generate different keycodes based on left or right shift
    bool left  = keyboard_report->mods & MOD_BIT(KC_LSFT);
    bool right = keyboard_report->mods & MOD_BIT(KC_RSFT);

    if (left && !right) {
        // Left shifted keycode
        unregister_code(KC_LSFT);
        tap_code16(kc_lshift);
        register_code(KC_LSFT);
    } else if (right && !left) {
        // Right shifted keycode
        unregister_code(KC_RSFT);
        tap_code16(kc_rshift);
        register_code(KC_RSFT);
    } else {
        // Normal unshifted keycode
        tap_code16(kc_normal);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode) {
    case KC_2:
        // 2 to " and "
        gen_shifted_keycode(record, keycode, KC_DQUO, KC_DQUO);
        return false; // prevent raw press
        break;
    case KC_6:
        // 6 to & and ^
        gen_shifted_keycode(record, keycode, KC_AMPR, KC_CIRC);
        return false;
        break;
    case KC_7:
        // 7 to ' and `
        gen_shifted_keycode(record, keycode, KC_QUOT, KC_GRV);
        return false;
        break;
    case KC_8:
        // 8 to ( and (
        gen_shifted_keycode(record, keycode, KC_LPRN, KC_LPRN);
        return false;
        break;
    case KC_9:
        // 9 to ) and )
        gen_shifted_keycode(record, keycode, KC_RPRN, KC_RPRN);
        return false;
        break;
    case KC_MINS:
        // - to _ and _
        gen_shifted_keycode(record, keycode, KC_UNDS, KC_UNDS);
        return false;
        break;
    case KC_HOME:
        // Home to End and End
        gen_shifted_keycode(record, keycode, KC_END, KC_END);
        return false;
        break;
    case KC_BSPC:
        // 'Inst Del' key: Backspace to Delete and Delete
        gen_shifted_keycode(record, keycode, KC_DELETE, KC_DELETE);
        return false;
        break;
    case KC_COLN:
        // : to { and [
        gen_shifted_keycode(record, keycode, KC_LCBR, KC_LBRC);
        return false;
        break;
    case KC_SCLN:
        // ; to } and ]
        gen_shifted_keycode(record, keycode, KC_RCBR, KC_RBRC);
        return false;
        break;
    case KC_EQUAL:
        // = to ~ and ~
        gen_shifted_keycode(record, keycode, KC_TILDE, KC_TILDE);
        return false;
        break;
    }
    return true;
}
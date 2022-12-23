// Copyright 2022 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum custom_layer {
    _BASE,
    _FN1,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_all(
    KC_ESC,   KC_F2,   KC_GRAVE, KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,             KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  _______, KC_MPLY,
    KC_F3,   KC_F4,    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_BRIU,
    KC_F5,   KC_F6,    KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, _______, KC_ENT,  KC_BRID,
    KC_F7,   KC_F8,    KC_LSFT, _______, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, _______,   KC_PGDN,
    KC_F9,   KC_F10,   KC_LCTL,  KC_LGUI, KC_LALT, KC_SPC, MO(_FN1),   KC_BSPC,      _______, KC_SPC,  MO(_FN1), KC_RCTL, KC_RGUI, _______, _______, _______
  ),

  [_FN1] = LAYOUT_all(
    _______, _______, QK_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_DEL, _______,
    _______, _______, RGB_TOG, RGB_MOD, KC_LPRN, KC_RPRN,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, BL_UP,
    _______, _______, _______, _______, KC_LCBR, KC_RCBR, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______, _______, _______, BL_DOWN,
    _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, BL_BRTG,
    _______, _______, KC_LCTL, _______, _______, _______, _______, KC_DEL, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END
  )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return false;
}

// Copyright 2022 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum custom_layer {
    _BASE,
    _DEBUGGING,
    _GAMING,
    _FN1,
    _FN1_DEBUG
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_all(
    KC_ESC,   KC_F2,   KC_GRAVE, KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,             KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_BSPC, KC_MPLY,
    KC_F3,   KC_F4,    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_BRIU,
    KC_F5,   KC_F6,    MT(MOD_LCTL, KC_ESC),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, _______, KC_ENT,  KC_BRID,
    KC_F7,   KC_F8,    KC_LSFT, _______, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN,
    KC_F9,   KC_F10,   KC_LCTL,  KC_LCTL, KC_LGUI, KC_LALT, LT(_FN1, KC_SPC),   KC_BSPC,      _______, KC_SPC,  KC_BSPC, TG(_DEBUGGING), TG(_GAMING), KC_LEFT, KC_DOWN, KC_RIGHT
  ),

  [_DEBUGGING] = LAYOUT_all(
    _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,  _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, LT(_FN1_DEBUG, KC_SPC), _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_GAMING] = LAYOUT_all(
    _______, _______, _______, _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,  _______,  _______,  _______,  _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_SPC, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_FN1] = LAYOUT_all(
    _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_DEL, _______,
    _______, _______, RGB_TOG, RGB_MOD, _______, KC_LCBR, KC_RCBR, _______, _______, _______, _______, _______, _______, _______, _______, _______, BL_UP,
    _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, KC_GRAVE, _______, _______, BL_DOWN,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_TILD, _______, KC_PGUP, BL_BRTG,
    _______, _______, _______, _______, _______, _______, _______, KC_DEL, _______, KC_DEL, _______, _______, _______, KC_HOME, KC_PGDN, KC_END
  ),

  [_FN1_DEBUG] = LAYOUT_all(
    _______, _______, _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_DEL,  KC_DEL, _______,
    _______, _______, RGB_TOG, RGB_MOD, _______, KC_LCBR, KC_RCBR, _______, _______, _______, _______, _______, _______, _______, _______, _______, BL_UP,
    _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, KC_GRAVE, _______, _______, BL_DOWN,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_TILD, _______, KC_PGUP, BL_BRTG,
    _______, _______, _______, _______, _______, _______, _______, KC_DEL, _______, KC_DEL, _______, _______, _______, KC_HOME, KC_PGDN, KC_END
  )
};

#if defined(ENCODER_MAP_ENABLE)
// [layer count][NUM_ENCODERS is a macro and pre-defined][2 because the ENCODER_CCW_CW macro expands to an array of two key codes]
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE]   = { {_______, _______} , ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_DEBUGGING]   = { {_______, _______} , ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_GAMING] = { {_______, _______} , ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_FN1]    = { {_______, _______} , ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
    [_FN1_DEBUG]    = { {_______, _______} , ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
};
#else
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
#endif

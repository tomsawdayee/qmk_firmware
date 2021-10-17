/* Copyright 2020 Victor Lucachi
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
bool is_alt_tab_active = false;
bool is_encoder_a_key_active = false;
uint16_t alt_tab_timer = 0;
// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN1,
    _FN2,
    _FN3
};

enum custom_keycodes {
    PASS = SAFE_RANGE,
    ENCODER_B_PRESS
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base
 * ,--------------------.
 * |   7  |   8  |   9  |
 * |------+------+------|
 * |   4  |   5  |   6  |
 * |------+------+------|
 * |   1  |   2  |   3  |
 * `--------------------'
 */
[_BASE] = LAYOUT_ortho_3x3(
    KC_7,       LALT(LCMD(KC_LEFT)), LALT(LCMD(KC_RIGHT)),
    KC_4,       LCTL(LCMD(KC_Q)),       KC_6,
    KC__MUTE,       PASS,       ENCODER_B_PRESS
),

/* FN1
 * ,--------------------.
 * |   7  |   8  |   9  |
 * |------+------+------|
 * |   4  |   5  |   6  |
 * |------+------+------|
 * |   1  |   2  |   3  |
 * `--------------------'
 */
[_FN1] = LAYOUT_ortho_3x3(
    KC_7,       KC_8,       KC_9,
    KC_4,       KC_5,       KC_6,
    PASS,       KC_2,       KC_3
),

/* FN2
 * ,--------------------.
 * |      |      |      |
 * |------+------+------|
 * |      |      |      |
 * |------+------+------|
 * |      |      |      |
 * `--------------------'
 */
[_FN2] = LAYOUT_ortho_3x3(
    KC_TRNS,       KC_TRNS,       KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS
),

/* FN3
 * ,--------------------.
 * |      |      |      |
 * |------+------+------|
 * |      |      |      |
 * |------+------+------|
 * |      |      |      |
 * `--------------------'
 */
[_FN3] = LAYOUT_ortho_3x3(
    KC_TRNS,       KC_TRNS,       KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS
)
};

/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1250) {
      unregister_code(KC_LCMD);
      is_alt_tab_active = false;
    }
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case PASS:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("test");
        } else {
            // when keycode QMKBEST is released
        }
        break;
      case ENCODER_B_PRESS:
            if (record->event.pressed) {
                is_encoder_a_key_active = true;
            } else {
                is_encoder_a_key_active = false;
            }
            break;
        }
    return true;
};

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
      if (clockwise) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LCMD);
        }
        alt_tab_timer = timer_read();
        tap_code16(KC_TAB);
      } else {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LCMD);
        }
        alt_tab_timer = timer_read();
        tap_code16(LSFT(KC_TAB));
      }
  } else {
    if (is_encoder_a_key_active) {
        if (clockwise) {
            tap_code16(LCMD(KC_PPLS));
        } else {
            tap_code16(LCMD(KC_PMNS));
        }
    } else {
        if (clockwise) {
          tap_code16(LCMD(LSFT(KC_Z)));
        } else {
          tap_code16(LCMD(KC_Z));
        }
    }
  }
  return true;
}

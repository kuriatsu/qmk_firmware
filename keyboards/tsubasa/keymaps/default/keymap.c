/* Copyright 2021 kuriatsu
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
      KC_1       , KC_2     , KC_3   , KC_4   , KC_5    , KC_6     ,            KC_7     , KC_8    , KC_9    , KC_0     , KC_MINS, KC_EQL , \
      KC_TAB     , KC_Q     , KC_W   , KC_E   , KC_R    , KC_T     ,      KC_Y, KC_U     , KC_I    , KC_O    , KC_P     , KC_LBRACKET, KC_RBRACKET, \
      KC_LCTL    , KC_A     , KC_S   , KC_D   , KC_F    , KC_G     ,            KC_H     , KC_J    , KC_K    , KC_L     , KC_SCOLON  , KC_QUOTE   , \
      MO(_FN)    , KC_Z     , KC_X   , KC_C   , KC_V    , KC_B     ,            KC_N     , KC_M    , KC_COMMA, KC_DOT   , KC_SLASH   , \
      KC_ESCAPE  , KC_RGUI  , KC_LALT, KC_SPACE, KC_LSHIFT ,KC_PSCREEN,            KC_BSPACE, KC_ENTER, MO(_FN) , KC_BSLASH, KC_GRAVE   , G(KC_PGUP)\
    ),
    [_FN] = LAYOUT(
      KC_F1  , KC_F2  , KC_F3     , KC_F4     , KC_F5      , KC_F6  ,                KC_F7  , KC_F8  , KC_F9  , KC_F10   , KC_F11 , KC_F12 , \
      _______, XXXXXXX, KC_BTN1   , KC_MS_UP  , KC_BTN2    , RGB_TOG,                 KC_PGUP, XXXXXXX, KC_UP  , XXXXXXX, XXXXXXX, XXXXXXX  , XXXXXXX, \
      _______, XXXXXXX, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, RGB_MOD,              KC_PGDOWN, KC_LEFT, KC_DOWN, KC_RIGHT , XXXXXXX, XXXXXXX, \
      _______, XXXXXXX, XXXXXXX   , XXXXXXX   , RGB_VAI    , RGB_HUI,              KC_BRIU  , KC_BRID, XXXXXXX, XXXXXXX  , XXXXXXX, \
      _______,_______, _______    , KC_MS_ACCEL0, KC_MS_ACCEL2, _______,             KC_DELETE, _______, _______  , _______, _______,_______ \
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/\n");
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 1) { /* master encoder */
        if (IS_LAYER_ON(_FN)) {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        } else {
            if (clockwise) {
                tap_code(KC_TAB);
            } else {
                tap_code16(S(KC_TAB));
            }
        }
    } else { /* other encoder */
        if (IS_LAYER_ON(_FN)) {
            if (clockwise) {
                tap_code16(C(KC_Y));
            } else {
                tap_code16(C(KC_Z));
            }
        } else {
            if (clockwise) {
                tap_code(KC_WH_U);
            } else {
                tap_code(KC_WH_D);
            }
        }
    }
    return false;
}


#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }

    return rotation;
}

bool oled_task_user(void) {
    if (!is_keyboard_master()) {
        render_logo();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_logo();  // Renders a static logo
        oled_scroll_left();  // Turns on scrolling
    }
    return false;
}
#endif
// #ifdef OLED_ENABLE
// oled_rotation_t oled_init_user(oled_rotation_t rotation) {
//     // if (is_keyboard_master()) {
//     //     return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
//     // }
//
//     return OLED_ROTATION_180;
// }
// bool oled_task_user(void) {
//     oled_write_ln_P(PSTR("Hello, world!"), false);
//     return false;
// }
// #endif

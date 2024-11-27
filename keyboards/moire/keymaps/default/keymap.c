// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _FN1,
    _FN2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │ / │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ * │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ - │
     * ├───┼───┼───┼───┤
     * │ 0 │ . │Ent│ + │
     * └───┴───┴───┴───┘
     */
    [_BASE] = LAYOUT(
            KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,           KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL,
            KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,           KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,
            KC_LCTL,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,           KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,
                    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,           KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,
              LALT_T(KC_ESC), KC_LGUI, LSFT_T(KC_SPC),           LT(_FN1, KC_ENT), KC_BSPC, MO(_FN2)
    ),
    [_FN1] = LAYOUT(
            KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,          KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12,
            _______,KC_BTN1,KC_MS_U,KC_BTN2,XXXXXXX,XXXXXXX,        XXXXXXX,KC_PGDN,KC_PGUP,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
            _______,KC_MS_L,KC_MS_D,KC_MS_R,XXXXXXX,XXXXXXX,        KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,XXXXXXX, KC_GRV,
                    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,KC_BSLS,
                                    _______,_______,_______,        _______,_______,_______
            ),
    [_FN2] = LAYOUT(
            KC_KB_MUTE,KC_KB_VOLUME_DOWN,KC_KB_VOLUME_UP,XXXXXXX,XXXXXXX,XXXXXXX,       XXXXXXX,KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_DOWN,XXXXXXX,XXXXXXX,XXXXXXX,
            XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,RGB_TOG,        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,KC_PSCR,XXXXXXX,XXXXXXX,
            XXXXXXX,XXXXXXX,RGB_SAI,KC_DEL, XXXXXXX,XXXXXXX,        RGB_HUI,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                    XXXXXXX,XXXXXXX,XXXXXXX,RGB_VAI,XXXXXXX,        XXXXXXX,RGB_MOD,XXXXXXX,XXXXXXX,XXXXXXX,
                                    XXXXXXX,XXXXXXX,XXXXXXX,        XXXXXXX,XXXXXXX,XXXXXXX
            )
};


static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

// static void render_logo(void) {
//     static const char PROGMEM qmk_logo[] = {
//         0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
//         0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
//         0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
//     };

    oled_write_P(qmk_logo, false);
}


bool oled_task_user(void) {
    render_logo();
    return false;
}

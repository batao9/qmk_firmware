// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum keymap_layer {
    KL_BASE,
    KL_FN,
};

#define KC_FN MO(KL_FN)
#define LT_LNG1 LT(KL_FN, KC_LNG1)
#define LT_LNG2 LT(KL_FN, KC_LNG2)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
    ┌───┐┌───┬───┬───┬───┐┌───┬───┬───┬───┐┌───┬───┬───┬───┐┌───┐
    │Esc││F1 │F2 │F3 │F4 ││F5 │F6 │F7 │F8 ││F9 │F10│F11│F12││Del│
    └───┘└───┴───┴───┴───┘└───┴───┴───┴───┘└───┴───┴───┴───┘└───┘
    ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
    │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│
    ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
    │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │
    ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
    │ Alt  │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │
    ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
    │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ Shift│ ↑ │
    ├────┬───┴┬──┴─┬─┴──┬┴───┴──┬┴───┴─┬─┴──┬┴───┼───┴┬─┬───┼───┼───┐
    │Ctrl│Win │BS  │ EN │       │      │ JP │Ent │Alt │ │ ← │ ↓ │ → │
    └────┴────┴────┴────┴───────┴──────┴────┴────┴────┘ └───┴───┴───┘
     */
    [KL_BASE] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,     KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,      KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,      KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_LALT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,      KC_K,    KC_L,             KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,      KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,
        KC_LCTL, KC_LGUI, KC_BSPC, LT_LNG2,          KC_SPC,  KC_SPC,  LT_LNG1,   KC_ENT,           KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT
    ),

     /*
    ┌───┐┌───┬───┬───┬───┐┌───┬───┬───┬───┐┌───┬───┬───┬───┐┌───┐
    │Esc││MT │   │   │   ││   │   │   │   ││   │   │VLU│VLD││Del│
    └───┘└───┴───┴───┴───┘└───┴───┴───┴───┘└───┴───┴───┴───┘└───┘
    ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
    │Esc│F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│  Del  │
    ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
    │ Tab │   │ ↑ │   │   │   │   │   │ 7 │ 8 │ 9 │   │   │PSCR │
    ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
    │CpsLck│ ← │ ↓ │ → │   │   │NUM│ 4 │ 5 │ 6 │   │   │  Enter │
    ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
    │ Shift  │   │   │   │   │   │ 1 │ 2 │ 3 │   │   │Shift │pgu│
    ├────┬───┴┬──┴─┬─┴──┬┴───┴──┬┴───┴─┬─┴──┬┴───┼───┴┬─┬───┼───┼───┐
    │Ctrl│Win │    │ EN │       │  0   │ JP │    │Alt │ │hom│pgd│end│
    └────┴────┴────┴────┴───────┴──────┴────┴────┴────┘ └───┴───┴───┘
     */
    [KL_FN] = LAYOUT(
        KC_ESC,  KC_MUTE, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_VOLU, KC_VOLD, KC_DEL,
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,     KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        KC_TAB,  KC_NO,   KC_UP,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_P7,   KC_P8,   KC_P9,   KC_NO,   KC_NO,   KC_PSCR,
        KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,   KC_NO,   KC_NUM,  KC_P4,     KC_P5,   KC_P6,            KC_NO,   KC_NO,   KC_ENT,
        KC_LSFT,          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_P1,     KC_P2,   KC_P3,   KC_NO,   KC_NO,   KC_RSFT, KC_PGUP,
        KC_LCTL, KC_LGUI, KC_NO,   KC_LNG2,          KC_SPC,  KC_P0,   KC_LNG1,   KC_NO,            KC_RALT, KC_HOME, KC_PGDN, KC_END
    ),
};

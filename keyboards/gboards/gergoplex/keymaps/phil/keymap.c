/* Copyright 2023 Phil Jerkins <Phil@TheJerkins.net>
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

/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#define KC_CTL_Z MT(MOD_LCTL, KC_Z)
#define KC_SFT_X MT(MOD_LSFT, KC_X)
#define KC_GUI_C MT(MOD_LGUI, KC_C)
#define KC_ALT_V MT(MOD_LALT, KC_V)

#define KC_ALT_M MT(MOD_RALT, KC_M)
#define KC_GUI_COMM MT(MOD_RGUI, KC_COMM)
#define KC_SFT_DOT MT(MOD_RSFT, KC_DOT)
#define KC_CTL_SLSH MT(MOD_RCTL, KC_SLSH)

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

enum {
    _LYR_BASE, // default layer
    _LYR_SYMB, // symbols/nav
    _LYR_NPAD, // number pad
    _LYR_NFN,  // numbers/Fn keys
    _LYR_NAV2, // nav 2
    _LYR_BMOD  // base mods
};

/* Combomap
 *
 * ,-----------------------------.       ,-----------------------------.
 * |    TAB    |     |     |     |      |     |    HOME  PGUP  ESC     |
 * |-----+-----+-RMB-+-LMB-+-----|      |-LFT-+--UP-+--DN-+--RT-+------|
 * |     |    BKSP  DEL    |     |      |     |    END   PGDN  ENT     | 
 * |-----+-----+-----+-----+-----+      |------------------------------|
 * |     |     |     |     |     |      |     |     |     |     |      |
 * `-----+-----+-----+-----+-----'      `------------------------------'
 *  .-------------------------.           .-----------------.   
 *  |        |       |        |           |        |    |   |
 *  '-------------------------'           '-----------------' 
 */

// Blank template at the bottom
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// Keymap 0: Basic layer
[_LYR_BASE] = LAYOUT_split_3x5_3(
            KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,    KC_Y, KC_U,     KC_I,        KC_O,       KC_P,
            KC_A,     KC_S,     KC_D,     KC_F,     KC_G,    KC_H, KC_J,     KC_K,        KC_L,       KC_SCLN,
            KC_CTL_Z, KC_SFT_X, KC_GUI_C, KC_ALT_V, KC_B,    KC_N, KC_ALT_M, KC_GUI_COMM, KC_SFT_DOT, KC_CTL_SLSH,
            MO(_LYR_NFN), KC_LSFT, LT(_LYR_NPAD, KC_BSPC),     MO(_LYR_SYMB),   KC_SPC, KC_DEL // MO(_LYR_BMOD)
    ),
// Keymap 1: Symbols/Nav layer
[_LYR_SYMB] = LAYOUT_split_3x5_3(
            KC_TAB, KC_QUOT, KC_LPRN, KC_RPRN, KC_PSCR,            KC_DEL, KC_VOLU, KC_VOLD, KC_TRNS, KC_ESC,
            KC_MINS, KC_EQL, KC_LCBR, KC_RCBR, KC_ASTR,            KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_TRNS,
            MT(MOD_LCTL, KC_GRV), MT(MOD_LSFT, KC_BSLS), MT(MOD_LGUI, KC_LBRC), MT(MOD_LALT, KC_RBRC), KC_TRNS,
            KC_BSPC, KC_RALT, MT(MOD_RGUI, KC_BSPC), KC_RSFT, KC_RCTL,
            MO(_LYR_NAV2), KC_TRNS, KC_ENT,
            KC_TRNS, KC_TRNS, KC_TRNS
    ),
// Keymap 2: Number Pad layer
[_LYR_NPAD]  LAYOUT_split_3x5_3(
            KC_TRNS, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R,            KC_NUM, KC_P7, KC_P8, KC_P9, KC_PMNS,
            KC_BTN1, KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R,            KC_MS_U, KC_P4, KC_P5, KC_P6, KC_PPLS,
            KC_LCTL, MT(MOD_LSFT, KC_BTN3), KC_BTN2, MT(MOD_LALT, KC_BTN1), KC_TRNS,
            KC_MS_D, MT(MOD_RALT, KC_P1), MT(MOD_RGUI, KC_P2), MT(MOD_RSFT, KC_P3), MT(MOD_RCTL, KC_PPLS),
            KC_TRNS, KC_RALT, KC_TRNS,            KC_P0, KC_PDOT, KC_PENT
    ),
// Keymap 3: Numbers/Fn layer
[_LYR_NFN] = LAYOUT_split_3x5_3(
            KC_1, KC_2, KC_3, KC_4, KC_5,            KC_6, KC_7, KC_8, KC_9, KC_0,
            KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,            KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
            MT(MOD_LCTL, KC_F11), MT(MOD_LSFT, KC_F12), KC_LGUI, KC_LALT, KC_TRNS,
            KC_TRNS, KC_RALT, KC_RGUI, KC_RSFT, KC_RCTL,
            KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS
    ),
// Keymap 4: Nav Overlay layer
[_LYR_NAV2] = LAYOUT_split_3x5_3(
            KC_RALT, KC_RALT, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_INS, KC_HOME, KC_PGUP, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_DEL, KC_END, KC_PGDN, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_RALT, KC_RGUI, KC_RSFT, KC_RCTL,
            KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS
    )/*,
// Keymap 5: Modifiers Overlay
[_LYR_BMOD]  LAYOUT_split_3x5_3(
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            MT(MOD_LCTL, KC_Z), MT(MOD_LSFT, KC_X), MT(MOD_LGUI, KC_C), MT(MOD_LALT, KC_V), KC_TRNS,
            KC_TRNS, MT(MOD_RALT, KC_M), MT(MOD_RGUI, KC_COMM), MT(MOD_RSFT, KC_DOT), MT(MOD_RCTL, KC_SLSH),
            KC_TRNS, KC_SPC, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS
    )*/
};

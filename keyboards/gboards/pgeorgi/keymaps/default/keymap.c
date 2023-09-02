/*
 * Good on you for modifying your layout, this is the most nonQMK layout you will come across
 * There are three modes, Steno (the default), QWERTY (Toggleable) and a Momentary symbol layer
 *
 * Don't modify the steno layer directly, instead add chords using the keycodes and macros
 * from sten.h to the layout you want to modify.
 *
 * Observe the comment above processQWERTY!
 *
 * http://docs.gboards.ca
 */

/* Keyboard Layout
 * ,---------------------------------.    ,------------------------------.
 * | FN  | LSU | LFT | LP | LH | ST1 |    | ST3 | RF | RP | RL | RT | RD |
 * |-----+-----+-----+----+----|-----|    |-----|----+----+----+----+----|
 * | PWR | LSD | LK  | LW | LR | ST2 |    | ST4 | RR | BB | RG | RS | RZ |
 * `---------------------------------'    `------------------------------'
 *                   ,---------------,    .---------------.
 *                   | LNO | LA | LO |    | RE | RU | RNO |
 *                   `---------------'    `---------------'
 */

#define KC_CTL_Z MT(MOD_LCTL, KC_Z)
#define KC_SFT_X MT(MOD_LSFT, KC_X)
#define KC_GUI_C MT(MOD_LGUI, KC_C)
#define KC_ALT_V MT(MOD_LALT, KC_V)

#define KC_ALT_M MT(MOD_RALT, KC_M)
#define KC_GUI_COMM MT(MOD_RGUI, KC_COMM)
#define KC_SFT_DOT MT(MOD_RSFT, KC_DOT)
#define KC_CTL_SLSH MT(MOD_RCTL, KC_SLSH)


#define KC_CTL_GRV MT(MOD_LCTL, KC_GRV)
#define KC_SFT_BSLS MT(MOD_LSFT, KC_BSLS)
#define KC_GUI_LBRC MT(MOD_LGUI, KC_LBRC)
#define KC_ALT_RBRC MT(MOD_LALT, KC_RBRC)

#define KC_GUI_BSPC MT(MOD_RGUI, KC_BSPC)


#define KC_SFT_BTN3 MT(MOD_LSFT, KC_BTN3)
#define KC_ALT_BTN1 MT(MOD_LALT, KC_BTN1)

#define KC_ALT_P1 MT(MOD_RALT, KC_P1)
#define KC_GUI_P2 MT(MOD_RGUI, KC_P2)
#define KC_SFT_P3 MT(MOD_RSFT, KC_P3)
#define KC_CTL_PPLS MT(MOD_RCTL, KC_PPLS)


#define KC_CTL_F11 MT(MOD_LCTL, KC_F11)
#define KC_SFT_F12 MT(MOD_LSFT, KC_F12)

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"
#include "keymap_steno.h"

enum {
    _LYR_STEN,   // Steno Layer
    _LYR_QWERTY, // QWERTY layer
    _LYR_SYMB,   // Symbols/Nav layer
    _LYR_NPAD,   // Number Pad layer
    _LYR_NFN,    // Numbers/Fn layer
    _LYR_NAV2    // Nav Overlay layer
};

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_GUI_C:
            // Do not select the hold action when another key is tapped.
            return false;
        default:
            // Immediately select the hold action when another key is tapped.
            return true;
    }
}

// Blank template at the bottom
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// Keymap 0: Steno Layer
[_LYR_STEN] = LAYOUT(
        DF(_LYR_QWERTY), STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,       STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
        DF(_LYR_QWERTY), STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2,       STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
                                           STN_N1,  STN_A,   STN_O,         STN_E,   STN_U,   STN_N7
    ),
// Keymap 1: QWERTY layer
[_LYR_QWERTY] LAYOUT(
        KC_TAB, KC_Q, KC_W,     KC_E,     KC_R,     KC_T,    KC_Y, KC_U,     KC_I,        KC_O,       KC_P, KC_BSPC,
        // KC_A,     KC_S,     KC_D,     KC_F,     KC_G,    KC_H, KC_J,     KC_K,        KC_L,       KC_SCLN,
        DF(_LYR_STEN), KC_CTL_Z, KC_SFT_X, KC_GUI_C, KC_ALT_V, KC_B,    KC_N, KC_ALT_M, KC_GUI_COMM, KC_SFT_DOT, KC_CTL_SLSH, KC_ESC,
        MO(_LYR_NFN), KC_LSFT, LT(_LYR_NPAD, KC_BSPC),     MO(_LYR_SYMB),   KC_SPC, DF(_LYR_STEN)
    ),
// Keymap 2: Symbols/Nav layer
[_LYR_SYMB] = LAYOUT(
            KC_TRNS, KC_TAB, KC_QUOT, KC_LPRN, KC_RPRN, KC_PSCR,            KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_ESC, KC_TRNS,
            // KC_MINS, KC_EQL, KC_LCBR, KC_RCBR, KC_ASTR,            KC_DEL, KC_VOLU, KC_VOLD, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_CTL_GRV, KC_SFT_BSLS, KC_GUI_LBRC, KC_ALT_RBRC, KC_TRNS,
            KC_BSPC, KC_RALT, KC_GUI_BSPC, KC_RSFT, KC_RCTL, KC_TRNS,
            MO(_LYR_NAV2), KC_TRNS, KC_ENT,
            KC_TRNS, KC_TRNS, KC_TRNS
    ),
// Keymap 3: Number Pad layer
[_LYR_NPAD]  LAYOUT(
            KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R,            KC_NUM, KC_P7, KC_P8, KC_P9, KC_PMNS, KC_TRNS,
            // KC_BTN1, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R,            KC_MS_U, KC_P4, KC_P5, KC_P6, KC_PPLS,
            KC_TRNS, KC_LCTL, KC_SFT_BTN3, KC_BTN2, KC_ALT_BTN1, KC_TRNS,
            KC_MS_D, KC_ALT_P1, KC_GUI_P2, KC_SFT_P3, KC_CTL_PPLS, KC_TRNS,
            KC_TRNS, KC_RALT, KC_TRNS,            KC_P0, KC_PDOT, KC_PENT
    ),
// Keymap 4: Numbers/Fn layer
[_LYR_NFN] = LAYOUT(
            KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5,            KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS,
            // KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,            KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
            KC_TRNS, KC_CTL_F11, KC_SFT_F12, KC_LGUI, KC_LALT, KC_TRNS,
            KC_TRNS, KC_RALT, KC_RGUI, KC_RSFT, KC_RCTL, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS
    ),
// Keymap 5: Nav Overlay layer
[_LYR_NAV2] = LAYOUT(
            KC_TRNS, KC_RALT, KC_RALT, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_INS, KC_HOME, KC_PGUP, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_DEL, KC_END, KC_PGDN, KC_RCTL, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS
    )
};

// Don't fuck with this, thanks.
size_t keymapsCount  = ARRAY_SIZE(keymaps);

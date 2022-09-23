#include QMK_KEYBOARD_H

// TODO setup DANCE_33

/* const uint16_t layer1_left[][5][4] = { */
/*     {KC_Q, KC_W, KC_F, KC_P, KC_B} */
/* } */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Base Layer - alpha keys, shift, space, ctrl and to layer 1
	[0] = LAYOUT_ortho_4x12(
            KC_Q, KC_W, KC_F, KC_P, KC_B,               KC_NO, KC_NO,       KC_J, KC_L, KC_U, KC_Y, KC_BSPC,
            KC_A, KC_R, KC_S, KC_T, KC_G,               KC_NO, KC_NO,       KC_M, KC_N, KC_E, KC_I, KC_O,
            KC_Z, KC_X, KC_C, KC_D, KC_V,               KC_NO, KC_NO,       KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH,
            KC_NO, KC_NO, KC_NO, KC_SPC,KC_LSFT,        KC_NO, KC_NO,       KC_LCTL, OSL(1), KC_NO, KC_NO, KC_NO
        ),
    // Layer 1 - 'one shot' - punctuation and to other layers
	[1] = LAYOUT_ortho_4x12(
            KC_ESC, KC_AT, KC_HASH, KC_DLR, KC_PERC,    KC_NO, KC_NO,       KC_CIRC, KC_AMPR, KC_ASTR, KC_SCLN, KC_COLN,
            KC_TAB, KC_EQL, KC_NO, KC_NO, KC_SLSH,      KC_NO, KC_NO,       KC_BSLS, KC_LCBR, KC_RCBR, KC_PIPE, KC_ENT,
            KC_TILD, TD(DNC_33), LALT(KC_LBRACKET), LALT(LSFT(KC_LBRACKET)), KC_DQUO,      KC_NO, KC_NO,       KC_LBRC, KC_LPRN, KC_RPRN, KC_RBRC, TO(3),
            KC_NO, KC_NO, KC_NO, TO(0), KC_LSFT,        KC_NO, KC_NO,       KC_RALT, TO(2), KC_NO, KC_NO, KC_NO
        ),
	[2] = LAYOUT_ortho_4x12(
            KC_ESC, KC_MPLY, KC_MRWD, KC_MFFD, KC_UNDS, KC_NO, KC_NO,       KC_PMNS, KC_P7, KC_P8, KC_P9, KC_BSPC,
            KC_TAB, KC_NO, KC_VOLD, KC_VOLU, KC_PLUS,   KC_NO, KC_NO,       KC_PEQL, KC_P4, KC_P5, KC_P6, KC_ENT,
            TO(4), KC_PAST, KC_BRID, KC_BRIU, KC_PDOT,  KC_NO, KC_NO,       KC_NO, KC_P1, KC_P2, KC_P3, KC_NO,
            KC_NO, KC_NO, KC_NO, TO(0), KC_LGUI,        KC_NO, KC_NO,       KC_RALT, KC_NO, KC_NO, KC_NO, KC_NO
        ),
	[3] = LAYOUT_ortho_4x12(
            KC_ESC, KC_WH_L, KC_MS_U, KC_WH_R, KC_NO,   KC_NO, KC_NO,       KC_WBAK, KC_NO, KC_NO, KC_WFWD, KC_BSPC,
            KC_TAB, KC_MS_L, KC_MS_D, KC_MS_R, KC_LGUI, KC_NO, KC_NO,       KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_ENT,
            KC_GRV, KC_MS_R, KC_WH_U, KC_WH_D, KC_DEL,  KC_NO, KC_NO,       KC_MS_L, KC_ACL0, KC_ACL1, KC_ACL2, KC_TRNS,
            KC_NO, KC_NO, KC_NO, TO(0), KC_NO,          KC_NO, KC_NO,       KC_RALT, TO(1), KC_NO, KC_NO, KC_NO
        ),
	[4] = LAYOUT_ortho_4x12(
            BL_DEC, BL_INC, KC_NO, KC_NO, KC_NO,        KC_NO, KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOT,
            BL_OFF, BL_ON, KC_NO, KC_NO, KC_NO,         KC_NO, KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            BL_STEP, BL_BRTG, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_NO, TO(0), KC_NO,          KC_NO, KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
        )
};

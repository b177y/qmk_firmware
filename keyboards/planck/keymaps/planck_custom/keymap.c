#include QMK_KEYBOARD_H
#include "dance/dance.h"

/* const uint16_t layer1_left[][5][4] = { */
/*   {KC_Q,                      KC_W,                       KC_F,                       KC_P,                       KC_B}, */
/*   {KC_A,                      KC_R,                       KC_S,                       KC_T,                       KC_G}, */
/*   {KC_Z,                      KC_X,                       KC_C,                       KC_D,                       KC_V}, */
/*   {KC_NO,                     KC_NO,                      KC_NO,                      KC_SPC,                     KC_LSFT} */
/* } */

#define WS_0 MT(LGUI(KC_0), LALT(KC_0))
#define WS_1 MT(LGUI(KC_1), LALT(KC_1))
#define WS_2 MT(LGUI(KC_2), LALT(KC_2))
#define WS_3 MT(LGUI(KC_3), LALT(KC_3))
#define WS_4 MT(LGUI(KC_4), LALT(KC_4))
#define WS_5 MT(LGUI(KC_5), LALT(KC_5))
#define WS_6 MT(LGUI(KC_6), LALT(KC_6))
#define WS_7 MT(LGUI(KC_7), LALT(KC_7))
#define WS_8 MT(LGUI(KC_8), LALT(KC_8))
#define WS_9 MT(LGUI(KC_9), LALT(KC_9))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Base Layer - alpha keys, shift, space, ctrl and to layer 1
	[0] = LAYOUT_ortho_4x12(
            KC_Q, KC_W, KC_F, KC_P, KC_B,               KC_NO, KC_NO,       KC_J, KC_L, KC_U, KC_Y, KC_BSPC,
            KC_A, LT(5, KC_R), MT(MOD_LALT, KC_S), MT(MOD_LGUI,KC_T), KC_G,
                                                        KC_NO, KC_NO,       KC_M, MT(MOD_RGUI, KC_N), MT(MOD_RALT, KC_E), KC_I, KC_O,
            KC_Z, KC_X, KC_C, KC_D, KC_V,               KC_NO, KC_NO,       KC_K, KC_H, TD(TD_COMMA_HYPHEN), TD(TD_FULLSTOP_EXCL), TD(TD_FSLASH_USCORE),
            KC_NO, KC_NO, KC_NO, MT(MOD_MEH,KC_SPACE), OSM(MOD_LSFT), KC_NO, KC_NO,       KC_LCTL, OSL(1), KC_NO, KC_NO, KC_NO
        ),
    // Layer 1 - 'one shot' - punctuation and to other layers
	[1] = LAYOUT_ortho_4x12(
            KC_ESC, KC_AT, LSFT(KC_3), KC_DLR, KC_PERC,
                                                        KC_NO, KC_NO,       KC_CIRC, KC_AMPR, KC_ASTR, KC_SCLN, KC_COLN,
            KC_TAB, KC_EQL, TD(SCREENSHOT_FILE), TD(SCREENSHOT_CLIP), KC_QUOTE,
                                                        KC_NO, KC_NO,       TD(BKSL_HME), KC_LCBR, KC_RCBR, TD(PIPE_END), KC_ENT,
            KC_TILD, LALT(KC_3), KC_GRAVE, LCTL(KC_B), KC_DQUO,
                                                        KC_NO, KC_NO,       KC_LBRC, KC_LPRN, KC_RPRN, KC_RBRC, TO(3),
            KC_NO, KC_NO, KC_NO, TO(0), KC_LSFT,        KC_NO, KC_NO,       KC_RALT, TO(2), KC_NO, KC_NO, KC_NO
        ),
    // Layer 2 - numbers / control
	[2] = LAYOUT_ortho_4x12(
            KC_ESC, KC_MRWD, KC_MFFD, KC_MPLY, KC_UNDS, KC_NO, KC_NO,       KC_PMNS, KC_7, KC_8, KC_9, KC_BSPC,
            KC_TAB, KC_VOLD, KC_VOLU, KC_COLN, KC_PLUS, KC_NO, KC_NO,       KC_PEQL, KC_4, KC_5, KC_6, KC_ENT,
            TO(4),  KC_BRID, KC_BRIU, KC_ASTR, KC_PDOT, KC_NO, KC_NO,       KC_0, KC_1, KC_2, KC_3, KC_SLASH,
            KC_NO, KC_NO, KC_NO, TO(0), KC_LSFT,        KC_NO, KC_NO,       KC_SPACE, KC_LGUI, KC_NO, KC_NO, KC_NO
        ),
    // Layer 3 - navigation
	[3] = LAYOUT_ortho_4x12(
            KC_ESC, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U,   KC_NO, KC_NO,       LGUI(KC_LBRACKET), LCTL(LSFT(KC_TAB)), RCTL(KC_TAB), LGUI(KC_RBRACKET), KC_BSPC,
            KC_TAB, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_NO, KC_NO,       KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_ENT,
            KC_NO, KC_NO, LCTL(KC_W), LCTL(KC_B), KC_DEL,  KC_NO, KC_NO,       KC_MS_BTN1, KC_BTN2, KC_ACL0, KC_ACL1, KC_ACL2,
            KC_NO, KC_NO, KC_NO, TO(0), KC_LCTL,          KC_NO, KC_NO,       KC_RALT, TO(1), KC_NO, KC_NO, KC_NO
        ),
    // Layer 4 - keyboard config
	[4] = LAYOUT_ortho_4x12(
            RGB_TOG, KC_NO, KC_NO, KC_NO, KC_NO,
                                                        KC_NO, KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOT,
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,         KC_NO, KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_NO, TO(0), KC_NO,          KC_NO, KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
        )
    // Layer 5 - workspace switching
	[4] = LAYOUT_ortho_4x12(
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                                        KC_NO, KC_NO,       KC_NO, WS_7, WS_8, WS_9, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,         KC_NO, KC_NO,       KC_NO, WS_4, WS_5, WS_6, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO,       WS_0, WS_1, WS_2, WS_3, KC_NO,
            KC_NO, KC_NO, KC_NO, TO(0), KC_LSFT,          KC_NO, KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
        )
};


layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    // base layer purple
    case 0:
        rgblight_setrgb (0xCC,  0x00, 0xff);
        break;
    // layer 1 (symbols) blue
    case 1:
        rgblight_setrgb (0x00,  0x99, 0xff);
        break;
    // layer 2 (num / ctrl) green
    case 2:
        rgblight_setrgb (0x00,  0xFF, 0x00);
        break;
    // layer 3 (navigation) yellow
    case 3:
        rgblight_setrgb (0xFF,  0xFF, 0x00);
        break;
    // layer 4 (rgb toggle / reset) red
    case 4:
        rgblight_setrgb (0xFF,  0x00, 0x00);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (0xCC,  0x00, 0xff);
        break;
    }
  return state;
}



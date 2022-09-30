#include "dance/custom.h"
#include QMK_KEYBOARD_H

/* const uint16_t layer1_left[][5][4] = { */
/*   {KC_Q,                      KC_W,                       KC_F,                       KC_P,                       KC_B}, */
/*   {KC_A,                      KC_R,                       KC_S,                       KC_T,                       KC_G}, */
/*   {KC_Z,                      KC_X,                       KC_C,                       KC_D,                       KC_V}, */
/*   {KC_NO,                     KC_NO,                      KC_NO,                      KC_SPC,                     KC_LSFT} */
/* } */

enum tap_dance_codes {
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_15,
  DANCE_31,
  DANCE_32,
  DANCE_33,
  DANCE_54,
  DANCE_55,
  DANCE_56,
  DANCE_57,
  DANCE_58,
  DANCE_59,
  DANCE_60,
  DANCE_63,
  BKSL_HME,
  PIPE_END,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Base Layer - alpha keys, shift, space, ctrl and to layer 1
	[0] = LAYOUT_ortho_4x12(
            KC_Q, KC_W, KC_F, KC_P, KC_B,               KC_NO, KC_NO,       KC_J, KC_L, KC_U, KC_Y, KC_BSPC,
            KC_A, KC_R, MT(MOD_LALT, KC_S), MT(MOD_LGUI,KC_T), KC_G,        
                                                        KC_NO, KC_NO,       KC_M, MT(MOD_RGUI, KC_N), MT(MOD_RALT, KC_E), KC_I, KC_O,
            KC_Z, KC_X, KC_C, KC_D, KC_V,               KC_NO, KC_NO,       KC_K, KC_H, TD(DANCE_2), TD(DANCE_1), TD(DANCE_3),
            KC_NO, KC_NO, KC_NO, MT(MOD_MEH,KC_SPACE), OSM(MOD_LSFT), KC_NO, KC_NO,       KC_LCTL, OSL(1), KC_NO, KC_NO, KC_NO
        ),
    // Layer 1 - 'one shot' - punctuation and to other layers
	[1] = LAYOUT_ortho_4x12(
            KC_ESC, KC_AT, LSFT(KC_3), KC_DLR, KC_PERC, 
                                                        KC_NO, KC_NO,       KC_CIRC, KC_AMPR, KC_ASTR, KC_SCLN, KC_COLN,
            KC_TAB, KC_EQL, KC_NO, KC_NO, TD(DANCE_32),
                                                        KC_NO, KC_NO,       KC_BSLS, KC_LCBR, KC_RCBR, KC_PIPE, KC_ENT,
            KC_TILD, TD(DANCE_33), KC_GRAVE, LCTL(KC_B), KC_DQUO,
                                                        KC_NO, KC_NO,       KC_LBRC, KC_LPRN, KC_RPRN, KC_RBRC, TO(3),
            KC_NO, KC_NO, KC_NO, TO(0), KC_LSFT,        KC_NO, KC_NO,       KC_RALT, TO(2), KC_NO, KC_NO, KC_NO
        ),
    // Layer 2 - numbers / control
	[2] = LAYOUT_ortho_4x12(
            KC_ESC, KC_MRWD, KC_MFFD, KC_MPLY, KC_UNDS, KC_NO, KC_NO,       KC_PMNS, KC_P7, KC_P8, KC_P9, KC_BSPC,
            KC_TAB, KC_VOLD, KC_VOLU, KC_COLN, KC_PLUS, KC_NO, KC_NO,       KC_PEQL, KC_P4, KC_P5, KC_P6, KC_ENT,
            TO(4),  KC_BRID, KC_BRIU, KC_ASTR, KC_PDOT, KC_NO, KC_NO,       KC_P0, KC_P1, KC_P2, KC_P3, KC_SLASH,
            KC_NO, KC_NO, KC_NO, TO(0), KC_LSFT,        KC_NO, KC_NO,       KC_RALT, KC_LGUI, KC_NO, KC_NO, KC_NO
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

extern bool g_suspend_state;
#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF
uint16_t last_keycode = KC_NO;
uint8_t last_modifier = 0;

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state = {
    .is_press_action = true,
    .step = 0
};

void on_dance_2(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_2_dance_step(qk_tap_dance_state_t *state);
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_2_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_2(qk_tap_dance_state_t *state, void *user_data) {
	if(state->count == 3) {
		tap_code16(KC_COMM);
		tap_code16(KC_COMM);
		tap_code16(KC_COMM);
	}
	if(state->count > 3) {
		tap_code16(KC_COMM);
	}
}

uint8_t dance_2_dance_step(qk_tap_dance_state_t *state) {
	if (state->count == 1) {
		if (state->interrupted || !state->pressed) return SINGLE_TAP;
		else return SINGLE_HOLD;
	} else if (state->count == 2) {
		if (state->interrupted) return DOUBLE_SINGLE_TAP;
		else if (state->pressed) return DOUBLE_HOLD;
		else return DOUBLE_TAP;
	}
	return MORE_TAPS;
}
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data) {
	dance_state.step = dance_2_dance_step(state);
	switch (dance_state.step) {
		case SINGLE_TAP: register_code16(KC_COMM); break;
		case SINGLE_HOLD: register_code16(KC_MINS); break;
		case DOUBLE_TAP: register_code16(KC_COMM); register_code16(KC_COMM); break;
		case DOUBLE_SINGLE_TAP: tap_code16(KC_COMM); register_code16(KC_COMM);
	}
}

void dance_2_reset(qk_tap_dance_state_t *state, void *user_data) {
	wait_ms(10);
	switch (dance_state.step) {
		case SINGLE_TAP: unregister_code16(KC_COMM); break;
		case SINGLE_HOLD: unregister_code16(KC_MINS); break;
		case DOUBLE_TAP: unregister_code16(KC_COMM); break;
		case DOUBLE_SINGLE_TAP: unregister_code16(KC_MINS); break;
	}
	dance_state.step = 0;
}
void on_dance_3(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_3_dance_step(qk_tap_dance_state_t *state);
void dance_3_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_3_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_3(qk_tap_dance_state_t *state, void *user_data) {
	if(state->count == 3) {
		tap_code16(KC_SLASH);
		tap_code16(KC_SLASH);
		tap_code16(KC_SLASH);
	}
	if(state->count > 3) {
		tap_code16(KC_SLASH);
	}
}

uint8_t dance_3_dance_step(qk_tap_dance_state_t *state) {
	if (state->count == 1) {
		if (state->interrupted || !state->pressed) return SINGLE_TAP;
		else return SINGLE_HOLD;
	} else if (state->count == 2) {
		if (state->interrupted) return DOUBLE_SINGLE_TAP;
		else if (state->pressed) return DOUBLE_HOLD;
		else return DOUBLE_TAP;
	}
	return MORE_TAPS;
}
void dance_3_finished(qk_tap_dance_state_t *state, void *user_data) {
	dance_state.step = dance_3_dance_step(state);
	switch (dance_state.step) {
		case SINGLE_TAP: register_code16(KC_SLASH); break;
		case SINGLE_HOLD: register_code16(S(KC_MINS)); break;
		case DOUBLE_TAP: register_code16(KC_SLASH); register_code16(KC_SLASH); break;
		case DOUBLE_SINGLE_TAP: tap_code16(KC_SLASH); register_code16(KC_SLASH);
	}
}

void dance_3_reset(qk_tap_dance_state_t *state, void *user_data) {
	wait_ms(10);
	switch (dance_state.step) {
		case SINGLE_TAP: unregister_code16(KC_SLASH); break;
		case SINGLE_HOLD: unregister_code16(S(KC_MINS)); break;
		case DOUBLE_TAP: unregister_code16(KC_SLASH); break;
		case DOUBLE_SINGLE_TAP: unregister_code16(KC_SLASH); break;
	}
	dance_state.step = 0;
}
void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_1_dance_step(qk_tap_dance_state_t *state);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
	if(state->count == 3) {
		tap_code16(KC_DOT);
		tap_code16(KC_DOT);
		tap_code16(KC_DOT);
	}
	if(state->count > 3) {
		tap_code16(KC_DOT);
	}
}

uint8_t dance_1_dance_step(qk_tap_dance_state_t *state) {
	if (state->count == 1) {
		if (state->interrupted || !state->pressed) return SINGLE_TAP;
		else return SINGLE_HOLD;
	} else if (state->count == 2) {
		if (state->interrupted) return DOUBLE_SINGLE_TAP;
		else if (state->pressed) return DOUBLE_HOLD;
		else return DOUBLE_TAP;
	}
	return MORE_TAPS;
}
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
	dance_state.step = dance_1_dance_step(state);
	switch (dance_state.step) {
		case SINGLE_TAP: register_code16(KC_DOT); break;
		case SINGLE_HOLD: register_code16(KC_EXLM); break;
		case DOUBLE_TAP: register_code16(KC_DOT); register_code16(KC_DOT); break;
		case DOUBLE_SINGLE_TAP: tap_code16(KC_DOT); register_code16(KC_DOT);
	}
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
	wait_ms(10);
	switch (dance_state.step) {
		case SINGLE_TAP: unregister_code16(KC_DOT); break;
		case SINGLE_HOLD: unregister_code16(KC_EXLM); break;
		case DOUBLE_TAP: unregister_code16(KC_DOT); break;
		case DOUBLE_SINGLE_TAP: unregister_code16(KC_DOT); break;
	}
	dance_state.step = 0;
}

void on_dance_32(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_32_dance_step(qk_tap_dance_state_t *state);
void dance_32_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_32_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_32(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_QUOTE);
        tap_code16(KC_QUOTE);
        tap_code16(KC_QUOTE);
    }
    if(state->count > 3) {
        tap_code16(KC_QUOTE);
    }
}

uint8_t dance_32_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_32_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_32_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_QUOTE); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_QUOTE)); break;
        case DOUBLE_TAP: register_code16(KC_GRAVE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_QUOTE); register_code16(KC_QUOTE);
    }
}

void dance_32_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_QUOTE); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_QUOTE)); break;
        case DOUBLE_TAP: unregister_code16(KC_GRAVE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_QUOTE); break;
    }
    dance_state.step = 0;
}
void on_dance_33(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_33_dance_step(qk_tap_dance_state_t *state);
void dance_33_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_33_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_33(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LALT(KC_3));
        tap_code16(LALT(KC_3));
        tap_code16(LALT(KC_3));
    }
    if(state->count > 3) {
        tap_code16(LALT(KC_3));
    }
}

uint8_t dance_33_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_33_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_33_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(LALT(KC_3)); break;
        case SINGLE_HOLD: register_code16(LALT(LSFT(KC_2))); break;
        case DOUBLE_TAP: register_code16(LALT(KC_3)); register_code16(LALT(KC_3)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LALT(KC_3)); register_code16(LALT(KC_3));
    }
}

void dance_33_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(LALT(KC_3)); break;
        case SINGLE_HOLD: unregister_code16(LALT(LSFT(KC_2))); break;
        case DOUBLE_TAP: unregister_code16(LALT(KC_3)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LALT(KC_3)); break;
    }
    dance_state.step = 0;
}

void on_bksl_hme(qk_tap_dance_state_t *state, void *user_data);
uint8_t bksl_hme_dance_step(qk_tap_dance_state_t *state);
void bksl_hme_finished(qk_tap_dance_state_t *state, void *user_data);
void bksl_hme_reset(qk_tap_dance_state_t *state, void *user_data);

void on_bksl_hme(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_BSLS);
        tap_code16(KC_BSLS);
        tap_code16(KC_BSLS);
    }
    if(state->count > 3) {
        tap_code16(KC_BSLS);
    }
}

uint8_t bksl_hme_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void bksl_hme_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = bksl_hme_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_BSLS); break;
        case SINGLE_HOLD: register_code16(KC_HOME); break;
        case DOUBLE_TAP: register_code16(KC_BSLS); register_code16(KC_BSLS); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_BSLS); register_code16(KC_BSLS);
    }
}

void bksl_hme_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_BSLS); break;
        case SINGLE_HOLD: unregister_code16(KC_HOME); break;
        case DOUBLE_TAP: unregister_code16(KC_BSLS); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_BSLS); break;
    }
    dance_state.step = 0;
}

void on_pipe_end(qk_tap_dance_state_t *state, void *user_data);
uint8_t pipe_end_dance_step(qk_tap_dance_state_t *state);
void pipe_end_finished(qk_tap_dance_state_t *state, void *user_data);
void pipe_end_reset(qk_tap_dance_state_t *state, void *user_data);

void on_pipe_end(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_PIPE);
        tap_code16(KC_PIPE);
        tap_code16(KC_PIPE);
    }
    if(state->count > 3) {
        tap_code16(KC_PIPE);
    }
}

uint8_t pipe_end_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void pipe_end_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = pipe_end_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_PIPE); break;
        case SINGLE_HOLD: register_code16(KC_END); break;
        case DOUBLE_TAP: register_code16(KC_PIPE); register_code16(KC_PIPE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_PIPE); register_code16(KC_PIPE);
    }
}

void pipe_end_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_PIPE); break;
        case SINGLE_HOLD: unregister_code16(KC_END); break;
        case DOUBLE_TAP: unregister_code16(KC_PIPE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_PIPE); break;
    }
    dance_state.step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_32] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_32, dance_32_finished, dance_32_reset),
        [BKSL_HME] = ACTION_TAP_DANCE_FN_ADVANCED(on_bksl_hme, bksl_hme_finished, bksl_hme_reset),
        [PIPE_END] = ACTION_TAP_DANCE_FN_ADVANCED(on_pipe_end, pipe_end_finished, pipe_end_reset),
};

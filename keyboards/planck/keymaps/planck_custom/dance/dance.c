#include QMK_KEYBOARD_H

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

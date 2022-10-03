#include QMK_KEYBOARD_H
#include "common.h"

void on_fullstop_excl(qk_tap_dance_state_t *state, void *user_data) {
	if(state->count == 3) {
		tap_code16(KC_DOT);
		tap_code16(KC_DOT);
		tap_code16(KC_DOT);
	}
	if(state->count > 3) {
		tap_code16(KC_DOT);
	}
}

uint8_t fullstop_excl_step(qk_tap_dance_state_t *state) {
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

void fullstop_excl_finished(qk_tap_dance_state_t *state, void *user_data) {
	dance_state.step = fullstop_excl_step(state);
	switch (dance_state.step) {
		case SINGLE_TAP: register_code16(KC_DOT); break;
		case SINGLE_HOLD: register_code16(KC_EXLM); break;
		case DOUBLE_TAP: register_code16(KC_DOT); register_code16(KC_DOT); break;
		case DOUBLE_SINGLE_TAP: tap_code16(KC_DOT); register_code16(KC_DOT);
	}
}

void fullstop_excl_reset(qk_tap_dance_state_t *state, void *user_data) {
	wait_ms(10);
	switch (dance_state.step) {
		case SINGLE_TAP: unregister_code16(KC_DOT); break;
		case SINGLE_HOLD: unregister_code16(KC_EXLM); break;
		case DOUBLE_TAP: unregister_code16(KC_DOT); break;
		case DOUBLE_SINGLE_TAP: unregister_code16(KC_EXLM); break;
	}
	dance_state.step = 0;
}

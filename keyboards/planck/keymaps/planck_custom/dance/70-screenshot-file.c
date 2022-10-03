#include QMK_KEYBOARD_H
#include "common.h"

#define SCREENSHOT_FULL LGUI(LSFT(KC_3))
#define SCREENSHOT_AREA LGUI(LSFT(KC_4))

void on_screenshot_file(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(SCREENSHOT_AREA);
        tap_code16(SCREENSHOT_AREA);
        tap_code16(SCREENSHOT_AREA);
    }
    if(state->count > 3) {
        tap_code16(SCREENSHOT_AREA);
    }
}

uint8_t screenshot_file_dance_step(qk_tap_dance_state_t *state) {
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
void screenshot_file_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = screenshot_file_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(SCREENSHOT_AREA); break;
        case SINGLE_HOLD: register_code16(SCREENSHOT_FULL); break;
        case DOUBLE_TAP: register_code16(SCREENSHOT_AREA); register_code16(SCREENSHOT_AREA); break;
        case DOUBLE_SINGLE_TAP: tap_code16(SCREENSHOT_AREA); register_code16(SCREENSHOT_AREA);
    }
}

void screenshot_file_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(SCREENSHOT_AREA); break;
        case SINGLE_HOLD: unregister_code16(SCREENSHOT_FULL); break;
        case DOUBLE_TAP: unregister_code16(SCREENSHOT_AREA); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(SCREENSHOT_AREA); break;
    }
    dance_state.step = 0;
}

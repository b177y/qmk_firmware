#pragma once
#include QMK_KEYBOARD_H
#include "10-pipe-end.h"
#include "30-comma-hyphen.h"
#include "40-fullstop-excl.h"
#include "50-fslash-uscore.h"

enum tap_dance_codes {
  TD_COMMA_HYPHEN,
  TD_FULLSTOP_EXCL,
  TD_FSLASH_USCORE,
  DANCE_32,
  DANCE_33,
  BKSL_HME,
  PIPE_END,
};

void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_1_dance_step(qk_tap_dance_state_t *state);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_2(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_2_dance_step(qk_tap_dance_state_t *state);
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_2_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_3(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_3_dance_step(qk_tap_dance_state_t *state);
void dance_3_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_3_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_32(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_32_dance_step(qk_tap_dance_state_t *state);
void dance_32_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_32_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_33(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_33_dance_step(qk_tap_dance_state_t *state);
void dance_33_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_33_reset(qk_tap_dance_state_t *state, void *user_data);

void on_bksl_hme(qk_tap_dance_state_t *state, void *user_data);
uint8_t bksl_hme_dance_step(qk_tap_dance_state_t *state);
void bksl_hme_finished(qk_tap_dance_state_t *state, void *user_data);
void bksl_hme_reset(qk_tap_dance_state_t *state, void *user_data);



qk_tap_dance_action_t tap_dance_actions[] = {
        [TD_FULLSTOP_EXCL] = ACTION_TAP_DANCE_FN_ADVANCED(on_fullstop_excl, fullstop_excl_finished, fullstop_excl_reset),
        [TD_COMMA_HYPHEN] = ACTION_TAP_DANCE_FN_ADVANCED(on_comma_hyphen, comma_hyphen_finished, comma_hyphen_reset),
        [TD_FSLASH_USCORE] = ACTION_TAP_DANCE_FN_ADVANCED(on_fslash_uscore, fslash_uscore_finished, fslash_uscore_reset),
        /* [DANCE_32] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_32, dance_32_finished, dance_32_reset), */
        /* [DANCE_33] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_33, dance_33_finished, dance_33_reset), */
        /* [BKSL_HME] = ACTION_TAP_DANCE_FN_ADVANCED(on_bksl_hme, bksl_hme_finished, bksl_hme_reset), */
        [PIPE_END] = ACTION_TAP_DANCE_FN_ADVANCED(on_pipe_end, pipe_end_finished, pipe_end_reset),
};

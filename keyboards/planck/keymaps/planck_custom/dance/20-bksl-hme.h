#pragma once

void on_bksl_hme(qk_tap_dance_state_t *state, void *user_data);
uint8_t bksl_hme_dance_step(qk_tap_dance_state_t *state);
void bksl_hme_finished(qk_tap_dance_state_t *state, void *user_data);
void bksl_hme_reset(qk_tap_dance_state_t *state, void *user_data);

#pragma once

void on_screenshot_file(qk_tap_dance_state_t *state, void *user_data);
uint8_t screenshot_file_dance_step(qk_tap_dance_state_t *state);
void screenshot_file_finished(qk_tap_dance_state_t *state, void *user_data);
void screenshot_file_reset(qk_tap_dance_state_t *state, void *user_data);

#pragma once

void on_screenshot_clip(qk_tap_dance_state_t *state, void *user_data);
uint8_t screenshot_clip_dance_step(qk_tap_dance_state_t *state);
void screenshot_clip_finished(qk_tap_dance_state_t *state, void *user_data);
void screenshot_clip_reset(qk_tap_dance_state_t *state, void *user_data);

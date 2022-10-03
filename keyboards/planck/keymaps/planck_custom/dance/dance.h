#pragma once
#include QMK_KEYBOARD_H
#include "10-pipe-end.h"
#include "20-bksl-hme.h"
#include "30-comma-hyphen.h"
#include "40-fullstop-excl.h"
#include "50-fslash-uscore.h"
#include "60-screenshot-clip.h"
#include "70-screenshot-file.h"

enum tap_dance_codes {
  TD_COMMA_HYPHEN,
  TD_FULLSTOP_EXCL,
  TD_FSLASH_USCORE,
  BKSL_HME,
  PIPE_END,
  SCREENSHOT_CLIP,
  SCREENSHOT_FILE,
};

extern bool g_suspend_state;
#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF
uint16_t last_keycode = KC_NO;
uint8_t last_modifier = 0;


qk_tap_dance_action_t tap_dance_actions[] = {
        [TD_COMMA_HYPHEN] = ACTION_TAP_DANCE_FN_ADVANCED(on_comma_hyphen, comma_hyphen_finished, comma_hyphen_reset),
        [TD_FULLSTOP_EXCL] = ACTION_TAP_DANCE_FN_ADVANCED(on_fullstop_excl, fullstop_excl_finished, fullstop_excl_reset),
        [TD_FSLASH_USCORE] = ACTION_TAP_DANCE_FN_ADVANCED(on_fslash_uscore, fslash_uscore_finished, fslash_uscore_reset),
        [BKSL_HME] = ACTION_TAP_DANCE_FN_ADVANCED(on_bksl_hme, bksl_hme_finished, bksl_hme_reset),
        [PIPE_END] = ACTION_TAP_DANCE_FN_ADVANCED(on_pipe_end, pipe_end_finished, pipe_end_reset),
        [SCREENSHOT_CLIP] = ACTION_TAP_DANCE_FN_ADVANCED(on_screenshot_clip, screenshot_clip_finished, screenshot_clip_reset),
        [SCREENSHOT_FILE] = ACTION_TAP_DANCE_FN_ADVANCED(on_screenshot_file, screenshot_file_finished, screenshot_file_reset),
};

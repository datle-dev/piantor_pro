// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

// QWERTY left bottom home row mods (mod tap)
#define SFT_V LSFT_T(KC_V)
#define CTL_C LCTL_T(KC_C)
#define ALT_X LALT_T(KC_X)
#define GUI_Z LGUI_T(KC_Z)

// QWERTY right bottom home row mods (mod tap)
#define SFT_M RSFT_T(KC_M)
#define CTL_COMM RCTL_T(KC_COMM)
#define ALT_DOT RALT_T(KC_DOT)
#define GUI_SLSH RGUI_T(KC_SLSH)

// Gallium v2 left bottom home row mods (mod tap)
#define SFT_W LSFT_T(KC_W)
#define CTL_M LCTL_T(KC_M)
#define ALT_Q LALT_T(KC_Q)
#define GUI_X LGUI_T(KC_X)

// Gallium v2 right bottom home row mods (mod tap)
#define SFT_P RSFT_T(KC_P)
#define CTL_QUOT RCTL_T(KC_QUOT)
#define ALT_SCLN RALT_T(KC_SCLN)
#define GUI_DOT RGUI_T(KC_DOT)

// Layer taps
#define LT2_ENT LT(2, KC_ENT)
#define LT3_SPC LT(3, KC_SPC)
#define LT4_ESC LT(4, KC_ESC)
#define LT5_BSPC LT(5, KC_BSPC)
#define LT6_TAB LT(6, KC_TAB)
#define LT7_DEL LT(7, KC_DEL)

// =============================
// Keymap
// =============================

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // QWERTY
  [0] = LAYOUT_split_3x6_3(
    XXXXXXX, KC_Q,  KC_W,  KC_E,  KC_R,    KC_T,                          KC_Y,    KC_U,   KC_I,     KC_O,    KC_P,     XXXXXXX,
    XXXXXXX, KC_A,  KC_S,  KC_D,  KC_F,    KC_G,                          KC_H,    KC_J,   KC_K,     KC_L,    KC_SCLN,  XXXXXXX,
    XXXXXXX, GUI_Z, ALT_X, CTL_C, SFT_V,   KC_B,                          KC_N,    SFT_M,  CTL_COMM, ALT_DOT, GUI_SLSH, XXXXXXX,
                                  LT6_TAB, LT2_ENT, LT4_ESC,    LT5_BSPC, LT3_SPC, LT7_DEL
  ),

  // Gallium v2
  [1] = LAYOUT_split_3x6_3(
    XXXXXXX, KC_B,  KC_L,  KC_D,  KC_C,    KC_V,                          KC_J,    KC_F,   KC_O,     KC_U,     KC_COMM, XXXXXXX,
    XXXXXXX, KC_N,  KC_R,  KC_T,  KC_S,    KC_G,                          KC_Y,    KC_H,   KC_A,     KC_E,     KC_I,    XXXXXXX,
    XXXXXXX, GUI_X, ALT_Q, CTL_M, SFT_W,   KC_Z,                          KC_K,    SFT_P,  CTL_QUOT, ALT_SCLN, GUI_DOT, XXXXXXX,
                                  LT6_TAB, LT2_ENT, LT4_ESC,    LT5_BSPC, LT3_SPC, LT7_DEL
  ),

  // Shortcuts 1
  [2] = LAYOUT_split_3x6_3(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_2,    XXXXXXX,                      XXXXXXX, KC_2,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        _______, _______, _______,    _______, MO(8),   _______
  ),

  // Shortcuts 2
  [3] = LAYOUT_split_3x6_3(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_3,    XXXXXXX,                      XXXXXXX, KC_3,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        _______, MO(8),   _______,    _______, _______, _______
  ),

  // Navigation
  [4] = LAYOUT_split_3x6_3(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_PSCR, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_4,    XXXXXXX,                    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        _______, _______, _______,    MO(9), _______, _______
  ),

  // Numbers
  [5] = LAYOUT_split_3x6_3(
    XXXXXXX, KC_ASTR, KC_7, KC_8, KC_9, KC_SLSH,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_PLUS, KC_4, KC_5, KC_6, KC_MINS,                    XXXXXXX, KC_5,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_DOT,  KC_1, KC_2, KC_3, XXXXXXX,                    XXXXXXX, KC_RSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
                                  _______, KC_0, MO(9),    _______, _______, _______
  ),

  // Media
  [6] = LAYOUT_split_3x6_3(
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_6,    XXXXXXX,                      XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        _______, _______, _______,    _______, _______, MO(10)
  ),

  // Function keys
  [7] = LAYOUT_split_3x6_3(
    XXXXXXX, KC_F9, KC_F10, KC_F11, KC_F12, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
    XXXXXXX, KC_F5, KC_F6,  KC_F7,  KC_F8,  XXXXXXX,                      XXXXXXX, KC_7,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_F1, KC_F2,  KC_F3,  KC_F4,  XXXXXXX,                      XXXXXXX, KC_RSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
                                    MO(10), _______, _______,    _______, _______, _______
  ),

  // TBD
  [8] = LAYOUT_split_3x6_3(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_8,    XXXXXXX,                      XXXXXXX, KC_8,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        _______, _______, _______,    _______, _______, _______
  ),

  // TBD
  [9] = LAYOUT_split_3x6_3(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_9,    XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        _______, _______, _______,    _______, _______, _______
  ),

  // Special
  [10] = LAYOUT_split_3x6_3(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, DF(1),   DF(0),   XXXXXXX,                      XXXXXXX, KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        _______, _______, _______,    _______, _______, _______
  )
};

// =============================
// Leader
// =============================

void leader_start_user(void) {
  // Do something when the leader key is pressed
};

void leader_end_user(void) {
  if (leader_sequence_one_key(KC_A)) {
      SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_P2) SS_TAP(X_P2) SS_TAP(X_P4) SS_UP(X_LALT));
  } else if (leader_sequence_one_key(KC_B)) {
      SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_P2) SS_TAP(X_P2) SS_TAP(X_P5) SS_UP(X_LALT));
  } else if (leader_sequence_one_key(KC_E)) {
      SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_P2) SS_TAP(X_P3) SS_TAP(X_P8) SS_UP(X_LALT));
  } else if (leader_sequence_two_keys(KC_A, KC_E)) {
      SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_P2) SS_TAP(X_P2) SS_TAP(X_P4) SS_UP(X_LALT) "/" SS_DOWN(X_LALT) SS_TAP(X_P2) SS_TAP(X_P3) SS_TAP(X_P8) SS_UP(X_LALT));
  } else if (leader_sequence_two_keys(KC_P, KC_M)) {
      SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_P2) SS_TAP(X_P4) SS_TAP(X_P1) SS_UP(X_LALT));
  } else if (leader_sequence_two_keys(KC_D, KC_C)) {
      SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_P0) SS_TAP(X_P1) SS_TAP(X_P7) SS_TAP(X_P6) SS_UP(X_LALT) "C");
  } else if (leader_sequence_two_keys(KC_D, KC_F)) {
      SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_P0) SS_TAP(X_P1) SS_TAP(X_P7) SS_TAP(X_P6) SS_UP(X_LALT) "F");
  } else if (leader_sequence_two_keys(KC_E, KC_M)) {
      SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_P0) SS_TAP(X_P1) SS_TAP(X_P5) SS_TAP(X_P1) SS_UP(X_LALT));
  } else if (leader_sequence_two_keys(KC_S, KC_K)) {
      SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_P0) SS_TAP(X_P1) SS_TAP(X_P7) SS_TAP(X_P8) SS_UP(X_LALT));
  } else if (leader_sequence_two_keys(KC_K, KC_B)) {
      SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_P0) SS_TAP(X_P1) SS_TAP(X_P7) SS_TAP(X_P9) SS_UP(X_LALT));
  };
};

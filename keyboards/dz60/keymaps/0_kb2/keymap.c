#include QMK_KEYBOARD_H

#define BL 0
#define FL 2
#define ML 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Base Layer
    [BL] = LAYOUT(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  XXXXXXX, KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        MO(FL),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_DEL,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,  KC_SPC,  KC_SPC,           KC_RALT, MO(FL),  _______, TO(ML),  KC_RCTL
    ),

    // macOS Layer
    [ML] = LAYOUT(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  XXXXXXX, KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        MO(FL),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_DEL,
        KC_LCTL, KC_LALT, KC_LGUI,                   KC_SPC,  KC_SPC,  KC_SPC,           KC_RALT, MO(FL),  _______, TO(BL),  KC_RCTL
    ),

    // Function Layer
    [FL] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_DEL,
        _______, _______, KC_UP,   _______, _______, _______, _______, KC_PGUP, KC_HOME, KC_PGDN, _______, _______, _______, _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_DEL,           _______,
        _______, _______, _______, _______, KC_VOLD, KC_VOLU, _______, KC_END,  _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                   _______, _______, _______,          _______, _______, _______, _______, _______
    )

};


// changes underglow based on current layer
//from https://github.com/DanDobrick/qmk_firmware/blob/danDobrick-v60r-layout/keyboards/v60_type_r/keymaps/danDobrick/keymap.c#L146
#define BRIGHTNESS 180
layer_state_t layer_state_set_user(layer_state_t state) {
  switch(biton32(state)) {
  case FL:
    // Red
    rgblight_sethsv_noeeprom(0, 255, BRIGHTNESS);
    break;
  case ML:
    // green
    rgblight_sethsv_noeeprom(76, 255, BRIGHTNESS);
    break;
  default:
    // Default colors - teal
    rgblight_sethsv_noeeprom(200, 255, BRIGHTNESS);
    break;
  }
  return state;
}
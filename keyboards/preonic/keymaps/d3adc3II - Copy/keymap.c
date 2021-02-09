#include QMK_KEYBOARD_H
#include "muse.h"

enum preonic_layers {
  _QWERTY,  //0
  _GAME,    //1
  _DOTA,    //2
  _LOWER,   //3
  _RAISE,   //4
  _ADJUST  //6
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  GAME,
  DOTA,
  LOWER,
  RAISE,
  BACKLIT,
  TD_1_F1,
  TD_2_F2,
  TD_3_F3,
  TD_4_F4,
  TD_TAB_Z
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base QWERTY
 * ,----------------------------------------------------<>----------------------------Del.
 * |      |   1  |   2  |   3    |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+--------+------+------+------+-{}---+------+------+------+------|
 * | Tab  |   Q  |   W  |   E    |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Ldr  |
 * |------+------+------+--------+------+-------------+-()---+------+------+------+------|
 * | Grave|   A  |   S  |   D    |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+--------+------+------|------+-[]---+------+------+------+------|
 * | Sft  |   Z  |   X  |   C    |   V  |   B  |   N  |   M  |   ,  |   .  |   U  | tt 4 | 
 * |------+------+------+--------+------+------+------+------+------+------+------+------|
 * | Ctrl |      |  Win |  Alt   |Lower |    Space    |Raise |   /  |  L   |   D  |  R   |
   `-------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
  _______,    KC_1,    KC_2,    KC_3,        KC_4,    KC_5,     KC_6,    KC_7,     KC_8,    KC_9,    KC_0,    _______,
  KC_TAB,     KC_Q,    KC_W,    KC_E,        KC_R,    KC_T,     KC_Y,    KC_U,     KC_I,    KC_O,    KC_P,    KC_LEAD,
  KC_GESC,    KC_A,    KC_S,    KC_D,        KC_F,    KC_G,     KC_H,    KC_J,     KC_K,    KC_L,    KC_SCLN, KC_ENT,
  KC_LSFT,    KC_Z,    KC_X,    KC_C,        KC_V,    KC_B,     KC_N,    KC_M,     KC_COMM, KC_DOT,  KC_UP, TT(_RAISE),
  KC_LCTL,    _______, KC_LGUI, KC_LALT,     LOWER,   KC_SPC,   KC_SPC,  RAISE,    KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT
),
/* Game
 * ,-----------------------------------------------------------------------------------.ds
 * |      | 1/F1 | 2/F2 | 3/F3 | 4/F4 |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|  
 * |Tab/Z |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+-------------+------+------+------+------+------| 
 * |  `   |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      | Win  | Alt  | Lower |    Space    |Raise |  -  |   =  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_GAME] = LAYOUT_preonic_grid(
  _______,      TD(TD_1_F1), TD(TD_2_F2), TD(TD_3_F3),  TD(TD_4_F4),    KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,      KC_BSPC,
  TD(TD_TAB_Z), KC_Q,        KC_W,        KC_E,         KC_R,           KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,      KC_BSLS,
  KC_GRV,       KC_A,        KC_S,        KC_D,         KC_F,           KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,   KC_ENT,
  KC_LSFT,      KC_Z,        KC_X,        KC_C,         KC_V,           KC_B,      KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,   KC_QUOT,
  KC_LCTL,      _______,     KC_LGUI,     KC_LALT,      LOWER,          KC_SPC,    KC_SPC,   RAISE,    KC_MINS,  KC_EQL,   _______,   _______ 
),

/* Dota
 * ,-----------------------------------------------------------------------------------.
 * |      |  1   | 2    | 3    | 4    |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|  
 * |  Tab |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+-------------+------+------+------+------+------| 
 * |  `   |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      | Win  | Alt  | Lower |    Space    |Raise |  -  |   =  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_DOTA] = LAYOUT_preonic_grid(
  _______,      KC_1,        KC_2,        KC_3,         KC_4,           KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,      KC_BSPC,
  KC_TAB,       KC_Q,        KC_W,        KC_E,         KC_R,           KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,      KC_BSLS,
  KC_GRV,       KC_A,        KC_S,        KC_D,         KC_F,           KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,   KC_ENT,
  KC_LSFT,      KC_Z,        KC_X,        KC_C,         KC_V,           KC_B,      KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,   KC_QUOT,
  KC_LCTL,      _______,     KC_LGUI,     KC_LALT,      LOWER,          KC_SPC,    KC_SPC,   RAISE,    KC_MINS,  KC_EQL,   _______,   _______ 
),
/* Lower Special Chars
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |      |      |      |      |      |             
 * |------+------+------+------+------+------+-------------+------+------+------+------+
 * |      | ' "  |      |  !   |      |      |      |   _  |  |   |      |  %   |      |     
 * |------+------+------+------+------+------+-------------+------+------+------+------+
 * |      |  @   |   *  |  $   |      |      |   #  |   -  |      |      |      |      |    
 * |------+------+------+------+------+------+------|------+------+------+------+------+
 * |      |      |      |      |  &   |  \   |   ~  |  ^   |      |      |      |      |   
 * |------+------+------+------+------+------+------+------+------+------+------+------+
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
  _______, KC_F1,   KC_F2,    KC_F3,   KC_F4,   KC_F5,    _______, _______, _______, _______, _______, _______,
  _______, KC_QUOT, _______,  KC_EXLM, _______, _______,  _______, KC_UNDS, KC_PIPE, _______, KC_PERC, _______,
  _______, KC_AT,   KC_ASTR,  KC_DLR,  _______, _______,  KC_HASH, KC_MINS, _______, _______, _______, _______,
  _______, _______, _______,  _______, KC_AMPR, KC_BSLS,  KC_TILD, KC_CIRC, _______, _______, _______, _______,
  _______, _______, _______,  _______, _______, _______,  _______, _______, _______, _______, _______, _______
),
/* Raise NUMPAD
 * ,-----------------------------------------------------------------------------------.
 * | ____ |      |      |      |      |      |   +  |      |      |      |      |       |
 * |------+------+------+------+------+-------------+------+------+------+------+-------+
 * | ____ |   6  |   7  |   8  |   9  |   0  |   -  |      |      |      |  %   |       |
 * |------+------+------+------+------+-------------+------+------+------+------+-------+
 * | ____ |   1  |   2  |   3  |   4  |   5  |   *  |      |      |      |      |       |
 * |------+------+------+------+------+------|------+------+------+------+------+-------+
 * | ____ |      |      |      |      |      |   /  |  ^   |      |      |      |       |
 * |------+------+------+------+------+------+------+------+------+------+------+-------+
 * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | tg(3)| ____ |      |      |       |
 * `----------------------------------------------------------------------------------- '
 */
[_RAISE] = LAYOUT_preonic_grid(
  _______, _______, _______,  _______, _______, _______,  _______, _______, _______, _______, _______, _______,
  _______, _______, _______,  _______, _______, _______,  _______, _______, _______, _______, _______, _______,
  _______, _______, _______,  _______, _______, _______,  _______, _______, _______, _______, _______, _______,
  _______, _______, _______,  _______, _______, _______,  _______, _______, _______, _______, _______, _______,
  _______, _______, _______,  _______, _______, _______,  _______, _______, _______, _______, _______, _______
),
      
/* Adjust SETTINGS

 * ,-----------------------------------------------------------------------------------.
 * |      |QWERTY| GAME | DOTA |      |      |      |      |      |      |      |RESET |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |MAIL  |      |      |      |DEBUG |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |S-Off |S-On  |      |      |      |VLDN  | VLUP |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |  CAPS|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  _______, QWERTY,  GAME,    DOTA,     _______, _______, _______, _______, _______, _______, _______,  RESET,
  _______, _______, _______,  _______, _______, _______, _______, KC_VOLU, _______, _______, _______,  DEBUG,
  _______, _______, KC_ASOFF, KC_ASON, _______, _______, _______, KC_VOLD, KC_MAIL, _______, _______,  _______,
  _______, _______, _______,  _______, KC_CAPS, _______, _______, _______, _______, _______, _______,  _______,
  _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______  
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case GAME:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_GAME);
          }
          return false;
          break;
        case DOTA:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_DOTA);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
      }

//     #ifdef CONSOLE_ENABLE
//  uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
//#endif 
    return true;
};


LEADER_EXTERNS();
void matrix_scan_user(void) {
 

}


// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_TAB_Z] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_Z),
    [TD_1_F1] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_F1),
    [TD_2_F2] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_F2),
    [TD_3_F3] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_F3),
    [TD_4_F4] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_F4),   
};
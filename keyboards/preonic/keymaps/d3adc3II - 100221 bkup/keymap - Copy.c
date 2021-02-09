#include QMK_KEYBOARD_H
#include "muse.h"

enum preonic_layers {
  _QWERTY,  //0
  _GAME,    //1
  _DOTA,    //2
  _LOWER,   //3
  _RAISE,   //4
  _ADJUST  //5
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  GAME,
  DOTA,
  LOWER,
  RAISE,
  BACKLIT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
  _______,    KC_1,    KC_2,    KC_3,        KC_4,    KC_5,     KC_6,    KC_7,     KC_8,    KC_9,    KC_0,    KC_BSPC,
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
  _______,      _______, _______, _______,  _______,    KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,      KC_BSPC,
  _______, KC_Q,        KC_W,        KC_E,         KC_R,           KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,      KC_BSLS,
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
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}




//LEADER function
bool did_leader_succeed;
#ifdef AUDIO_ENABLE
float leader_start_song[][2] = SONG(ONE_UP_SOUND);
float leader_succeed_song[][2] = SONG(ALL_STAR);
float leader_fail_song[][2] = SONG(RICK_ROLL);
#endif
LEADER_EXTERNS();

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
  LEADER_DICTIONARY() {
    did_leader_succeed = leading = false;
    SEQ_ONE_KEY(KC_C) {
      SEND_STRING(SS_TAP(X_TAB));
      did_leader_succeed = true;
    }
    SEQ_ONE_KEY(KC_BSPC) {
      SEND_STRING(SS_TAP(X_DEL));
      did_leader_succeed = true;
    }
    SEQ_ONE_KEY(KC_7) {
      SEND_STRING("<>"SS_TAP(X_LEFT));
      did_leader_succeed = true;
    }
    SEQ_TWO_KEYS(KC_7, KC_7) {
      SEND_STRING("<");
      did_leader_succeed = true;
    }
    SEQ_THREE_KEYS(KC_7, KC_7, KC_7) {
      SEND_STRING(">");
      did_leader_succeed = true;
    }
    SEQ_ONE_KEY(KC_U) {
      SEND_STRING("{}"SS_TAP(X_LEFT));
      did_leader_succeed = true;
    }
    SEQ_TWO_KEYS(KC_U, KC_U) {
      SEND_STRING("{");
      did_leader_succeed = true;
    }
    SEQ_THREE_KEYS(KC_U, KC_U, KC_U) {
      SEND_STRING("}");
      did_leader_succeed = true;
    }
    SEQ_ONE_KEY(KC_J) {
      SEND_STRING("()"SS_TAP(X_LEFT));
      did_leader_succeed = true;
    }
    SEQ_TWO_KEYS(KC_J, KC_J) {
      SEND_STRING("(");
      did_leader_succeed = true;
    }
    SEQ_THREE_KEYS(KC_J, KC_J, KC_J) {
      SEND_STRING(")");
      did_leader_succeed = true;
    }
    SEQ_ONE_KEY(KC_M) {
      SEND_STRING("[]"SS_TAP(X_LEFT));
      did_leader_succeed = true;
    }
    SEQ_TWO_KEYS(KC_M, KC_M) {
      SEND_STRING("[");
      did_leader_succeed = true;
    }
    SEQ_THREE_KEYS(KC_M, KC_M, KC_M) {
      SEND_STRING("]");
      did_leader_succeed = true;
    }


    //String
    SEQ_THREE_KEYS(KC_P, KC_P, KC_P) {
      SEND_STRING("$$$3RRR");
      did_leader_succeed = true;
    }
    SEQ_ONE_KEY(KC_X) {
      SEND_STRING(SS_LCTL("x"));
      did_leader_succeed = true;
    }
    SEQ_ONE_KEY(KC_C) {
      SEND_STRING(SS_LCTL("c"));
      did_leader_succeed = true;
    }
    SEQ_TWO_KEYS(KC_C,KC_C) {
      SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
      did_leader_succeed = true;
    }
    SEQ_TWO_KEYS(KC_V, KC_V) {
      SEND_STRING(SS_LCTL("v"));
      did_leader_succeed = true;
    }
    SEQ_TWO_KEYS(KC_E, KC_D) {
      SEND_STRING(SS_LGUI("r") "cmd\n" SS_LCTL("c"));
      did_leader_succeed = true;
    }

leader_end();
  }
}
void leader_start(void) {
#ifdef AUDIO_ENABLE
    PLAY_SONG(leader_start_song);
#endif
}

void leader_end(void) {
  if (did_leader_succeed) {
#ifdef AUDIO_ENABLE
    PLAY_SONG(leader_succeed_song);
#endif
  } else {
#ifdef AUDIO_ENABLE
    PLAY_SONG(leader_fail_song);
#endif
  }
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}

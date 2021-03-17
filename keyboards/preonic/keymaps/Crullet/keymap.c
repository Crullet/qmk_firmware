/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"
#include "keymap_swedish.h"

enum preonic_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST,
  _MOVE
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  LOW_BSP,
  RSE_DEL,
  BACKLIT
};


// wait DELAY ms before unregistering media keys
#define MEDIA_KEY_DELAY 10

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

// Layer Navigation specific keys
#define LOW_BSP LT(_LOWER, KC_BSPC)
#define RSE_DEL LT(_RAISE, KC_DEL)
#define MOV_SPC LT(_MOVE, KC_SPC)
//Text navigation
#define JMP_LFT LCTL(KC_LEFT)
#define JMP_RGT LCTL(KC_RGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
|  Esc       1        2        3        4        5        6        7        8        9        0      Bspace
├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
|  Tab       Q        W        E        R        T        Y        U        I        O        P        Å
├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
|  Ctrl      A        S        D        F        G        H        J        K        L        Ö        Ä
├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
|  Shift     Z        X        C        V        B        N        M        ,        .        -        /
├────────┼────────┼────────┼────────┼────────┼────────┴────────┼────────┼────────┼────────┼────────┼────────┤
            Ctrl     Alt       Win    Lower         Space         Raise    Left     Down     Up       Right
└────────┴────────┴────────┴────────┴────────┴─────────────────┴────────┴────────┴────────┴────────┴────────┘
 */
[_QWERTY] = LAYOUT_preonic_grid(
  KC_ESC  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,KC_6    ,KC_7     ,KC_8    ,KC_9    ,KC_0    ,KC_BSPC  ,
  KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_Y    ,KC_U     ,KC_I    ,KC_O    ,KC_P    ,SE_ARNG  ,
  KC_LCTL ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_H    ,KC_J     ,KC_K    ,KC_L    ,SE_ODIA ,SE_ADIA  ,
  KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_N    ,KC_M     ,KC_COMM ,KC_DOT  ,SE_MINS ,KC_SFTENT,
  KC_MUTE ,SE_LABK ,KC_RALT ,KC_LGUI ,LOW_BSP ,KC_SPC  ,KC_SPC  ,RSE_DEL  ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT
),

/* Lower (Num & Nav)
┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
|            !        "        #        ¤        %        &        /        (        )        =
├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
|            Home    PgDn     PgUp     End                         7        8        9        /        \
├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
|            Left    Down     Up       Right              \        4        5        6        *        '
├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
|            Undo    Cut      Copy     Paste    Redo               1        2        3        +
├────────┼────────┼────────┼────────┼────────┼────────┴────────┼────────┼────────┼────────┼────────┼────────┤
|                                                      0
└────────┴────────┴────────┴────────┴────────┴─────────────────┴────────┴────────┴────────┴────────┴────────┘
 */
[_LOWER] = LAYOUT_preonic_grid(
    _______ ,SE_EXLM ,SE_DQUO ,SE_HASH ,SE_DLR  ,SE_PERC ,SE_CIRC ,SE_AMPR ,SE_LPRN ,SE_RPRN ,SE_EQL  ,_______ ,
    _______ ,KC_HOME ,KC_PGDN ,KC_PGUP ,KC_END  ,XXXXXXX ,XXXXXXX ,KC_7    ,KC_8    ,KC_9    ,KC_PSLS ,SE_BSLS ,
    _______ ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT,XXXXXXX ,SE_BSLS ,KC_4    ,KC_5    ,KC_6    ,KC_PAST ,SE_QUOT ,
    _______ ,C(KC_Z) ,C(KC_X) ,C(KC_C) ,C(KC_V) ,C(KC_Y) ,XXXXXXX ,KC_1    ,KC_2    ,KC_3    ,KC_PPLS ,_______ ,
    KC_NLCK ,_______ ,_______ ,_______ ,_______ ,KC_0    ,KC_0    ,_______ ,_______ ,_______ ,_______ ,_______
),

/* Raise (Sym)
┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
|            ?        @        £        ¤        €                 {        [        ]        }       Del    Custom shift numrow (on keycaps)
├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
|            ?        @        £        $        €        ^        {        [        ]        }        \     SWE AltGr numrow
├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
|            !        "        #        ¤        %        &        /        (        )        =        "     SWE shift numrow
├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
|            §        |        ¨        `        ´        '        "        <        >        _
├────────┼────────┼────────┼────────┼────────┼────────┴────────┼────────┼────────┼────────┼────────┼────────┤
|
└────────┴────────┴────────┴────────┴────────┴─────────────────┴────────┴────────┴────────┴────────┴────────┘
 */
[_RAISE] = LAYOUT_preonic_grid(
  KC_TILD, SE_QUES, SE_AT,   SE_PND,  SE_CURR, SE_EURO, XXXXXXX, SE_LCBR, SE_LBRC, SE_RBRC ,SE_RCBR, KC_DEL,
  KC_GRV,  SE_QUES, SE_AT,   SE_PND,  SE_DLR,  SE_EURO, SE_CIRC, SE_LCBR, SE_LBRC, SE_RBRC, SE_RCBR, SE_BSLS,
  KC_DEL,  SE_EXLM, SE_DQUO, SE_HASH, SE_CURR, SE_PERC, SE_AMPR, SE_SLSH, SE_LPRN, SE_RPRN, SE_EQL,  SE_DQUO,
  _______, SE_SECT, SE_CIRC, SE_DIAE, SE_GRV,  SE_ACUT, SE_QUOT, SE_DQUO, SE_LABK, SE_RABK, SE_UNDS, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Navigation (Mouse & Fn & Media)
┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
|
├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
|         ScrLeft   ScrDown  ScrUp   ScrRight                      F7       F8       F9      F12
├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
|         MouseL    MouseD   MouseU   MouseR                       F4       F5       F6      F11
├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
|          Prev     VolDown  VolUp    Next   Play/Pause            F1       F2       F3      F10
├────────┼────────┼────────┼────────┼────────┼────────┴────────┼────────┼────────┼────────┼────────┼────────┤
|
└────────┴────────┴────────┴────────┴────────┴─────────────────┴────────┴────────┴────────┴────────┴────────┘
 */
[_MOVE] = LAYOUT_preonic_grid(
  _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______,
  _______ ,KC_WH_L ,KC_WH_D ,KC_WH_U ,KC_WH_R ,XXXXXXX ,XXXXXXX ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F12  ,_______,
  _______ ,KC_MS_L ,KC_WH_D ,KC_MS_D ,KC_MS_R ,XXXXXXX ,XXXXXXX ,KC_F4   ,KC_F5   ,KC_F6   ,KC_F11  ,_______,
  _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F10  ,_______,
  _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______
),
/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | Reset|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|AudOff|      |      | RGB+ | HUE+ | SAT+ | BRT+ | SPD+ |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff| RGB- | HUE- | SAT- | BRT- | SPD- |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
|
├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
|           Reset
├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
|
├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
|
├────────┼────────┼────────┼────────┼────────┼────────┴────────┼────────┼────────┼────────┼────────┼────────┤
|
└────────┴────────┴────────┴────────┴────────┴─────────────────┴────────┴────────┴────────┴────────┴────────┘
 */
[_ADJUST] = LAYOUT_preonic_grid(
  KC_F12  ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,
  _______ ,RESET   ,_______ ,_______ ,_______ ,_______ ,_______ ,TERM_ON ,TERM_OFF,_______ ,_______ ,KC_F12  ,
  _______ ,MUV_IN  ,MU_MOD  ,AU_ON   ,AU_OFF  ,MI_OFF  ,_______ ,RGB_MOD ,RGB_HUI ,RGB_SAI ,RGB_VAI ,RGB_SPI ,
  _______ ,MUV_DE  ,MUV_IN  ,MU_ON   ,MU_OFF  ,MI_ON   ,_______ ,RGB_RMOD,RGB_HUD ,RGB_SAD ,RGB_VAD ,RGB_SPD ,
  RGB_TOG ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ , _______
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case COLEMAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAK);
          }
          return false;
          break;
        case DVORAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_DVORAK);
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
          //return false; //removed to enable layer tap
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          //return false; //removed to enable layer tap
          break;
        case LOW_BSP:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          //return false; //removed to enable layer tap
          break;
        case RSE_DEL:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          //return false; //removed to enable layer tap
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
    uint16_t held_keycode_timer = timer_read();
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
      register_code(KC_VOLU);
      while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY) {
      // no-op
    }
      unregister_code(KC_VOLU);
    } else {
      register_code(KC_VOLD);
      while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY) {
      // no-op
    }
      unregister_code(KC_VOLD);
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


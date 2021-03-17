#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _SYMB 1
#define _NUM 2
#define _NAV 3
#define _FN 4
#define _MOUSE 5
#define _MEDIA 6
#define _ADJUST 7

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYMB,
  NUM,
  NAV,
  FN,
  MOUSE,
  MEDIA,
  ADJUST
};

typedef struct {
  bool is_press_action;
  int state;
} tap;

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5, //send two single taps
  TRIPLE_TAP = 6,
  TRIPLE_HOLD = 7
};

//Tap dance enums
enum {
  L_BR = 0,
  R_BR = 1,
  S_CAP = 2,
  SOME_OTHER_DANCE
};

int cur_dance (qk_tap_dance_state_t *state);

//for the x tap dance. Put it here so it can be used in any keymap
void L_finished (qk_tap_dance_state_t *state, void *user_data);
void L_reset (qk_tap_dance_state_t *state, void *user_data);
void R_finished (qk_tap_dance_state_t *state, void *user_data);
void R_reset (qk_tap_dance_state_t *state, void *user_data);

// Shortcut to make keymap more readable
#define SYM_L   MO(_SYMB)

#define ALT_HOM LALT_T(KC_HOME)
#define ALT_END ALGR_T(KC_END)

//Text navigation
#define JMP_LFT LCTL(KC_LEFT)
#define JMP_RGT LCTL(KC_RGHT)

//Windows Navigation
#define WIN_DSK LGUI(KC_D)

// Layer Navigation specific keys
#define MED_ESC LT(_MEDIA, KC_ESC)
#define NUM_BSP LT(_NUM, KC_BSPC)
#define FN_DEL  LT(_FN, KC_DEL)
#define NAV_ENT LT(_NAV, KC_ENT)
#define SYM_SPC LT(_SYMB, KC_SPC)
#define MOU_TAB LT(_MOUSE, KC_TAB)

// Homerow mods
#define ALT_S  LALT_T(KC_S)
#define WIN_A  LGUI_T(KC_A)
#define CTL_D  LCTL_T(KC_D)
#define SFT_F  LSFT_T(KC_F)
#define ALTG_X ALTGR_T(KC_X)
#define ALT_L  LALT_T(KC_L)
#define WIN_OE LGUI_T(SE_OSLH)
#define CTL_K  LCTL_T(KC_K)
#define SFT_J  LSFT_T(KC_J)
#define ALTG_D ALTGR_T(KC_DOT)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { //Keyboard Layouts
	[_QWERTY] = LAYOUT(
/*
┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
|  Esc       1         2       3        4        5                                                    6        7       8         9       0      Desktop
├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
|  Tab       Q         W       E        R        T                                                    Y        U       I         O       P        Å
├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
|  Ctrl      A         S       D        F        G      <{[(                                )]}>      H        J       K         L       Ö        Ä
├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
|  Shift     Z         X       C        V        B                                  Vol+    Vol-      N        M       ,         .       -         /
├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
|            Win               Alt          Esc        Backspace  Del             Enter    Space         Tab           Left      Down     Up      Right
└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
*/
  KC_GESC  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5                                                ,KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,WIN_DSK ,
  KC_TAB   ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,SE_GRV                            ,SE_APOS ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,SE_AA   ,
  KC_LCTL  ,WIN_A   ,ALT_S   ,CTL_D   ,SFT_F   ,KC_G    ,TD(L_BR)                          ,TD(R_BR),KC_H    ,SFT_J   ,CTL_K   ,ALT_L   ,WIN_OE  ,SE_AE   ,
  TD(S_CAP),KC_Z    ,ALTG_X  ,KC_C    ,KC_V    ,KC_B    ,KC_VOLU ,KC_VOLD         ,KC_VOLU ,KC_VOLD ,KC_N    ,KC_M    ,KC_COMM ,ALTG_D  ,SE_MINS ,SE_SLSH ,
  XXXXXXX  ,KC_LGUI ,XXXXXXX ,KC_LALT      ,MED_ESC     ,NUM_BSP ,FN_DEL          ,NAV_ENT ,SYM_SPC     ,MOU_TAB      ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT

	),

	[_SYMB] = LAYOUT(
/*
┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
|
├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
|             ?       @        £         $        €                                                    ^        {       [        ]        }         \     SWE AltGr numrow
├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
|             !       "        #         ¤        %                                                    &        /       (        )        =         "     SWE shift numrow
├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
|              §      |        ¨         `        ´                                                    '        "       <        >         _
├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
|
└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
*/
   _______ ,_______ ,_______ ,_______ ,_______ ,_______                                             ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
   _______ ,SE_QUES ,SE_AT   ,SE_PND  ,SE_DLR  ,SE_EURO ,_______                           ,_______ ,SE_CIRC ,SE_LCBR ,SE_LBRC ,SE_RBRC ,SE_RCBR ,SE_BSLS ,
   _______ ,SE_EXLM ,SE_DQUO ,SE_HASH ,SE_CURR ,SE_PERC ,_______                           ,_______ ,SE_AMPR ,SE_SLSH ,SE_LPRN ,SE_RPRN ,SE_EQL  ,SE_DQUO ,
   _______ ,SE_SECT ,SE_CIRC ,SE_DIAE ,SE_GRV  ,SE_ACUT ,_______ ,_______         ,_______ ,_______ ,SE_QUOT ,SE_DQUO ,SE_LABK ,SE_RABK ,SE_UNDS ,_______ ,
   _______ ,_______ ,_______ ,_______      ,_______     ,_______ ,_______         ,_______ ,_______     ,_______      ,_______ ,_______ ,_______ ,_______
	),

	[_NUM] = LAYOUT(
  /*
┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
|
├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
|                                                                                                              7        8        9        /
├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
|                                                                                                      \       4        5        6        *
├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
|                                                                                                              1        2        3        +     NumEnter
├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
|                                                                                                                       0
└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
*/
  _______  ,_______ ,_______ ,_______ ,_______ ,_______                                             ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,
  _______  ,_______ ,_______ ,_______ ,_______ ,_______ ,_______                           ,XXXXXXX ,XXXXXXX ,KC_7    ,KC_8    ,KC_9    ,KC_PSLS ,XXXXXXX ,
  _______  ,_______ ,_______ ,_______ ,_______ ,_______ ,_______                           ,XXXXXXX ,SE_BSLS ,KC_4    ,KC_5    ,KC_6    ,KC_PAST ,XXXXXXX ,
  _______  ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______         ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_1    ,KC_2    ,KC_3    ,KC_PPLS ,XXXXXXX ,
  _______  ,_______ ,_______ ,_______      ,_______     ,_______ ,_______         ,XXXXXXX ,KC_P0       ,XXXXXXX      ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX

	),

	[_FN] = LAYOUT(
  /*
┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
|
├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
|                                                                                                              F7       F8       F9      F12
├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
|                                                                                                              F4       F5       F6      F11
├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
|                                                                                                              F1       F2       F3      F10
├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
|
└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
*/
_______  ,_______ ,_______ ,_______ ,_______ ,_______                                             ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
_______  ,_______ ,_______ ,_______ ,_______ ,_______ ,_______                           ,XXXXXXX ,XXXXXXX ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F12  ,XXXXXXX ,
_______  ,_______ ,_______ ,_______ ,_______ ,_______ ,_______                           ,XXXXXXX ,XXXXXXX ,KC_F4   ,KC_F5   ,KC_F6   ,KC_F11  ,XXXXXXX ,
_______  ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______         ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F10  ,XXXXXXX ,
_______  ,_______ ,_______ ,_______      ,_______     ,_______ ,_______         ,XXXXXXX ,XXXXXXX     ,XXXXXXX      ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX

	),

	[_NAV] = LAYOUT(
  /*
┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
|
├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
|            Home    PgDn     PgUp     End
├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
|            Left    Down     Up       Right
├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
|            Undo    Cut      Copy     Paste    Redo
├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
|
└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
*/
XXXXXXX  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX                                             ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
XXXXXXX  ,KC_HOME ,KC_PGDN ,KC_PGUP ,KC_END  ,XXXXXXX ,XXXXXXX                           ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
XXXXXXX  ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT,XXXXXXX ,XXXXXXX                           ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
XXXXXXX  ,C(KC_Z) ,C(KC_X) ,C(KC_C) ,C(KC_V) ,C(KC_Y) ,XXXXXXX ,XXXXXXX         ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
XXXXXXX  ,XXXXXXX ,XXXXXXX ,XXXXXXX      ,XXXXXXX     ,XXXXXXX ,XXXXXXX         ,_______ ,_______     ,_______      ,_______ ,_______ ,_______ ,_______

	),

	[_MOUSE] = LAYOUT(
  /*
┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
|
├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
|          ScrLeft  ScrDown  ScrUp    ScrRight
├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
|          MouseL   MouseD   MouseU   MouseR
├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
|          Prev     VolDown  VolUp    Next   Play/Pause
├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
|                                          Mouse2       Mouse3   Mouse1
└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
*/
XXXXXXX  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX                                             ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
XXXXXXX  ,KC_WH_L ,KC_WH_D ,KC_WH_U ,KC_WH_R ,XXXXXXX ,XXXXXXX                           ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
XXXXXXX  ,KC_MS_L ,KC_WH_D ,KC_MS_D ,KC_MS_R ,XXXXXXX ,XXXXXXX                           ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
XXXXXXX  ,KC_MPRV ,KC_VOLD ,KC_VOLU ,KC_MNXT ,KC_MPLY ,XXXXXXX ,XXXXXXX         ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
XXXXXXX  ,XXXXXXX ,XXXXXXX ,XXXXXXX      ,KC_BTN2     ,KC_BTN3 ,KC_BTN1         ,_______ ,_______     ,_______      ,_______ ,_______ ,_______ ,_______

	),

	[_Media] = LAYOUT(
  /*
┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
|
├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
|
├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
|
├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
|          Prev     VolDown  VolUp    Next   Play/Pause
├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
|
└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
*/
XXXXXXX  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX                                             ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
XXXXXXX  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX                           ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
XXXXXXX  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX                           ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
XXXXXXX  ,KC_MPRV ,KC_VOLD ,KC_VOLU ,KC_MNXT ,KC_MPLY ,XXXXXXX ,XXXXXXX         ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
XXXXXXX  ,XXXXXXX ,XXXXXXX ,XXXXXXX      ,XXXXXXX     ,XXXXXXX ,XXXXXXX         ,_______ ,_______     ,_______      ,_______ ,_______ ,_______ ,_______

	),

    	[_ADJUST] = LAYOUT(
  /*
┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
|
├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
|
├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
|
├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
|
├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
|
└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
*/
RESET    ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX                                             ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
XXXXXXX  ,XXXXXXX ,XXXXXXX ,RGB_TOG ,XXXXXXX ,XXXXXXX ,XXXXXXX                           ,KC_ASTG ,KC_ASUP ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
KC_CAPS  ,RGB_MOD ,RGB_HUI ,RGB_SAI ,RGB_VAI ,XXXXXXX ,XXXXXXX                           ,KC_ASRP ,KC_ASDN ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
XXXXXXX  ,RGB_RMOD,RGB_HUD ,RGB_SAD ,RGB_VAD ,XXXXXXX ,XXXXXXX ,XXXXXXX         ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
XXXXXXX  ,XXXXXXX ,XXXXXXX ,XXXXXXX      ,_______     ,_______ ,_______         ,_______ ,_______     ,_______      ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX

	),


  };

  bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
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
      }
    return true;
};

/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *ReMo
 * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)  return SINGLE_TAP;
    //key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    /*
     * DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
     * action when hitting 'pp'. Suggested use case for this return value is when you want to send two
     * keystrokes of the key, and not the 'double tap' action/macro.
    */
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  //Assumes no one is trying to type the same letter three times (at least not quickly).
  //If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
  //an exception here to return a 'TRIPLE_SINGLE_TAP', and define that enum just like 'DOUBLE_SINGLE_TAP'
  if (state->count == 3) {
    if (state->interrupted || !state->pressed)  return TRIPLE_TAP;
    else return TRIPLE_HOLD;
  }
  else return 8; //magic number. At some point this method will expand to work for more presses
}

//instanalize an instance of 'tap' for the 'L' tap dance.
static tap Ltap_state = {
  .is_press_action = true,
  .state = 0
};
void L_finished (qk_tap_dance_state_t *state, void *user_data) {
  Ltap_state.state = cur_dance(state);
  switch (Ltap_state.state) {
    case SINGLE_TAP: register_code(KC_LSFT);register_code(KC_8); break; //(
    case SINGLE_HOLD: register_code(KC_RALT);register_code(KC_7); break;//{
    case DOUBLE_TAP: register_code(KC_RALT);register_code(KC_8); break;//[
    case DOUBLE_HOLD: register_code(KC_NUBS); break; //<
    case DOUBLE_SINGLE_TAP: register_code(KC_X); unregister_code(KC_X); register_code(KC_X);
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
}
void L_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (Ltap_state.state) {
    case SINGLE_TAP:  unregister_code(KC_LSFT);unregister_code(KC_8); break;
    case SINGLE_HOLD: unregister_code((KC_RALT));unregister_code(KC_7); break;
    case DOUBLE_TAP:  unregister_code(KC_RALT);unregister_code(KC_8); break;
    case DOUBLE_HOLD: unregister_code(KC_NUBS);
    case DOUBLE_SINGLE_TAP: unregister_code(KC_X);
  }
  Ltap_state.state = 0;
}

//instanalize an instance of 'tap' for the 'R' tap dance.
static tap Rtap_state = {
  .is_press_action = true,
  .state = 0
};
void R_finished (qk_tap_dance_state_t *state, void *user_data) {
  Rtap_state.state = cur_dance(state);
  switch (Rtap_state.state) {
    case SINGLE_TAP: register_code(KC_LSFT);register_code(KC_9); break; // )
    case SINGLE_HOLD: register_code(KC_RALT);register_code(KC_0); break;// }
    case DOUBLE_TAP: register_code(KC_RALT);register_code(KC_9); break;// ]
    case DOUBLE_HOLD: register_code(KC_LSFT);register_code(KC_NUBS); break; // >
    case DOUBLE_SINGLE_TAP: register_code(KC_X); unregister_code(KC_X); register_code(KC_X);
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
}
void R_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (Rtap_state.state) {
    case SINGLE_TAP:  unregister_code(KC_LSFT);unregister_code(KC_9); break;
    case SINGLE_HOLD: unregister_code(KC_RALT);unregister_code(KC_0); break;
    case DOUBLE_TAP:  unregister_code(KC_RALT);unregister_code(KC_9); break;
    case DOUBLE_HOLD: unregister_code(KC_LSFT);unregister_code(KC_NUBS);
    case DOUBLE_SINGLE_TAP: unregister_code(KC_X);
  }
  Rtap_state.state = 0;
}
  // Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [L_BR]     = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL,L_finished, L_reset, 200),
  [R_BR]     = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL,R_finished, R_reset, 200),
  [S_CAP]    = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)     // Tap once for Shift, twice for Caps Lock
};

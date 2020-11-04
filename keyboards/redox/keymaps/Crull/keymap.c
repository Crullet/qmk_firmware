#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _SYMB 1
#define _NAV 2
#define _ADJUST 3
#define _NUM 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYMB,
  NAV,
  ADJUST,
  NUM,
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
  X_CTL = 0,
  SOME_OTHER_DANCE
};

int cur_dance (qk_tap_dance_state_t *state);

//for the x tap dance. Put it here so it can be used in any keymap
void x_finished (qk_tap_dance_state_t *state, void *user_data);
void x_reset (qk_tap_dance_state_t *state, void *user_data);

// Shortcut to make keymap more readable
#define SYM_L   MO(_SYMB)

#define ALT_HOM LALT_T(KC_HOME)

#define SFT_HOM SFT_T(KC_HOME)
#define ALT_END ALGR_T(KC_END)

#define TAP_SFT OSM(MOD_LSFT)
#define TAP_CTL OSM(MOD_LCTL)

//Text navigation
#define JMP_LFT LCTL(KC_LEFT)
#define JMP_RGT LCTL(KC_RGHT)

//Windows Navigation
#define WIN_DSK LGUI(KC_D)

//Swedish keys
#define SE_AA	RALT(KC_W)
#define SE_AE	RALT(KC_P)
#define SE_OE	RALT(KC_Q)

// Layer Navigation specific keys
#define ADJ_RBC LT(_ADJUST, KC_RBRC)
#define ADJ_BSL LT(_ADJUST, KC_BSLS)
#define ADJ_ENT LT(_ADJUST, KC_ENT) //Enter and settings when held

#define SYM_END LT(_SYMB, KC_END)
#define SYM_SPC LT(_SYMB, KC_SPC)

#define NAV_LBR LT(_NAV, KC_LBRC)
#define NAV_DEL LT(_NAV,KC_DEL)

#define NUM_BSP LT(_NUM, KC_BSPC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
	KC_GESC  , KC_1   , KC_2   , KC_3   , KC_4   , KC_5                                               , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , WIN_DSK,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	KC_TAB   , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_GRV                           , KC_QUOT, KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , SE_AA  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	KC_LSFT  , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_LBRC                          , KC_RBRC, KC_H   , KC_J   , KC_K   , KC_L   , SE_AE  , SE_OE  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	KC_LCTL  , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_VOLU, KC_VOLD        , KC_UNDO, KC_AGIN, KC_N   , KC_M   , KC_COMM, KC_DOT ,KC_SLSH ,KC_MINS ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
	KC_LGUI  ,XXXXXXX ,XXXXXXX , KC_LALT     , SFT_HOM    , NUM_BSP, NAV_DEL        ,ADJ_ENT , SYM_SPC    , ALT_END     , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),

	[_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
    _______  , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5                                              , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,KC_F11	,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    _______  , _______, _______, _______, _______, _______, _______                          , _______,_______ , KC_TILD, KC_DQUO, KC_TILD,KC_GRV ,KC_F12 ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	_______  , KC_EXLM, KC_AT  , KC_HASH, KC_DLR, KC_PERC , KC_LPRN                          , KC_RPRN,KC_CIRC , KC_AMPR, KC_ASTR, KC_LPRN,KC_RPRN ,KC_QUOT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	_______  , _______, _______, _______, _______, _______, _______, _______        , _______, _______,KC_QUOT , KC_DQUO,KC_SCLN ,KC_COLN ,KC_BSLS ,KC_EQL  ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
    _______  , _______, _______, _______     , _______    , _______, _______        , _______, _______    , _______     , KC_HOME ,KC_PGDN ,KC_PGUP ,KC_END
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),

	[_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
	XXXXXXX  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX                                            , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX  ,XXXXXXX , XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX , XXXXXXX                          , XXXXXXX,XXXXXXX , JMP_LFT, KC_UP  , JMP_RGT,XXXXXXX  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX  ,XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX                          , XXXXXXX,KC_HOME , KC_LEFT, KC_DOWN, KC_RGHT, KC_END , XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX  ,XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______        , _______, _______,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
    XXXXXXX  ,XXXXXXX ,XXXXXXX ,XXXXXXX      , _______    , _______, _______        , XXXXXXX, XXXXXXX    , _______     , _______,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),

	[_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
  	RESET    ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX                                             ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX  ,XXXXXXX ,XXXXXXX ,RGB_TOG ,XXXXXXX ,XXXXXXX ,XXXXXXX                           ,KC_ASTG ,KC_ASUP ,XXXXXXX ,XXXXXXX ,XXXXXXX , XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    KC_CAPS  ,RGB_MOD ,RGB_HUI ,RGB_SAI ,RGB_VAI ,XXXXXXX ,XXXXXXX                           ,KC_ASRP ,KC_ASDN ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX  ,RGB_RMOD ,RGB_HUD ,RGB_SAD ,RGB_VAD ,XXXXXXX ,XXXXXXX ,XXXXXXX         ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
    XXXXXXX  ,XXXXXXX ,XXXXXXX ,XXXXXXX      ,_______     ,_______ ,_______         ,_______ ,_______     ,_______      ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),

	[_NUM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
    _______  , _______, _______, _______, _______, _______                                            ,XXXXXXX ,KC_P7   ,KC_P8   ,KC_P9 ,XXXXXXX ,KC_NLCK	,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    _______  , _______, _______, _______, _______, _______, _______                          , _______,XXXXXXX , KC_P4  , KC_P5  , KC_P6  ,KC_PPLS ,KC_PMNS  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	_______  , _______, _______, _______, _______, _______, _______                           , _______,XXXXXXX, KC_P1  , KC_P2  , KC_P3  ,KC_PAST ,KC_PSLS  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	_______  , _______, _______, _______, _______, _______, _______, _______        , _______, KC_CALC,XXXXXXX , KC_P0  , KC_P2  , KC_P3  ,XXXXXXX ,KC_PEQL  ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
    _______  , _______, _______, _______     , _______    , _______, _______        , _______, _______    , _______     , _______, _______,_______ ,_______
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),
  };

/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
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

//instanalize an instance of 'tap' for the 'x' tap dance.
static tap xtap_state = {
  .is_press_action = true,
  .state = 0
};

void x_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: register_code(KC_X); break;
    case SINGLE_HOLD: register_code(KC_LCTRL); break;
    case DOUBLE_TAP: register_code(KC_ESC); break;
    case DOUBLE_HOLD: register_code(KC_LALT); break;
    case DOUBLE_SINGLE_TAP: register_code(KC_X); unregister_code(KC_X); register_code(KC_X);
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
}

void x_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: unregister_code(KC_X); break;
    case SINGLE_HOLD: unregister_code(KC_LCTRL); break;
    case DOUBLE_TAP: unregister_code(KC_ESC); break;
    case DOUBLE_HOLD: unregister_code(KC_LALT);
    case DOUBLE_SINGLE_TAP: unregister_code(KC_X);
  }
  xtap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [X_CTL]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,x_finished, x_reset)
};


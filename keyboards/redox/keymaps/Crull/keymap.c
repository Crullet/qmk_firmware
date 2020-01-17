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

// Shortcut to make keymap more readable
#define SYM_L   MO(_SYMB)

#define ALT_HOM LALT_T(KC_HOME)

#define TAP_SFT OSM(MOD_LSFT)
#define TAP_CTL OSM(MOD_LCTL)

//Swedish keys
#define SE_AA	RALT(KC_W)
#define SE_AE	RALT(KC_P)
#define SE_OE	RALT(KC_Q)

// Navigation specific keys
#define SYM_END LT(_SYMB, KC_END)
#define SYM_SPC LT(_SYMB, KC_SPC)
#define NAV_LBR LT(_NAV, KC_LBRC)
#define NAV_DEL LT(_NAV,KC_DEL)/
#define ADJ_RBC LT(_ADJUST, KC_RBRC)
#define ADJ_BSL LT(_ADJUST, KC_BSLS)
#define NUM_BSP LT(_NUM, KC_BSPC)
#define ADJ_ENT LT(_ADJUST, KC_ENT) //Enter and settings when held


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
	KC_GESC  , KC_1   , KC_2   , KC_3   , KC_4   , KC_5                                               , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , xxxxxxx,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	KC_TAB   , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,xxxxxxx                           , KC_QUOT, KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , SE_AA  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	TAP_SFT  , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_LBRC                          , KC_RBRC, KC_H   , KC_J   , KC_K   , KC_L   , SE_AE  , SE_OE  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	TAP_CTL  , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , xxxxxxx, xxxxxxx        , xxxxxxx, xxxxxxx, KC_N   , KC_M   , KC_COMM, KC_DOT ,KC_SCLN ,KC_MINS ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
	KC_LGUI  ,xxxxxxx ,xxxxxxx , xxxxxxx     , ALT_HOM    , NUM_BSP, NAV_DEL        ,ADJ_ENT , SYM_SPC    , SYM_END     , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),

	[_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
    _______  , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5                                              , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,_______	,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    _______  , KC_EXLM, KC_AT  , KC_LCBR, KC_RCBR, KC_PIPE, _______                          , _______,_______ , _______, _______, _______,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	KC_CAPS  , KC_HASH, KC_DLR , KC_LBRC, KC_RBRC, KC_GRV , KC_LPRN                          , KC_RPRN,_______ , _______, _______, _______,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	_______  , KC_PERC, KC_CIRC, KC_LPRN, KC_RPRN, KC_TILD, _______, _______        , _______, _______,_______ , _______,KC_SCLN ,KC_COLN ,KC_BSLS ,KC_EQL  ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
    _______  , _______, _______, _______     , _______    , _______, _______        , _______, _______    , _______     , KC_HOME ,KC_PGUP ,KC_PGDN ,KC_END
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),

	[_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
	xxxxxxx  , xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx                                            , xxxxxxx, KC_BTN3, KC_BTN4, KC_BTN5, xxxxxxx, KC_ACL0,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    xxxxxxx  ,xxxxxxx , xxxxxxx, KC_UP, xxxxxxx, xxxxxxx , xxxxxxx                          , xxxxxxx,KC_WH_U , KC_WH_L, KC_MS_U, KC_WH_R,xxxxxxx  ,KC_ACL1 ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    xxxxxxx  ,xxxxxxx , KC_LEFT, KC_DOWN, KC_RGHT, xxxxxxx, xxxxxxx                          , xxxxxxx,KC_WH_D , KC_MS_L, KC_MS_D, KC_MS_R,xxxxxxx ,KC_ACL2 ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    xxxxxxx  ,xxxxxxx , xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______, _______        , _______, _______,xxxxxxx ,xxxxxxx ,xxxxxxx ,xxxxxxx ,xxxxxxx ,xxxxxxx ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
    xxxxxxx  ,xxxxxxx ,xxxxxxx ,xxxxxxx      , _______    , _______, _______        , KC_BTN1, KC_BTN2    , _______     , _______,xxxxxxx ,xxxxxxx ,xxxxxxx
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),

	[_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
  	RESET    ,xxxxxxx ,xxxxxxx ,xxxxxxx ,xxxxxxx ,xxxxxxx                                             ,xxxxxxx ,xxxxxxx ,xxxxxxx ,xxxxxxx ,xxxxxxx ,xxxxxxx ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    xxxxxxx  ,xxxxxxx ,xxxxxxx ,RGB_TOG ,xxxxxxx ,xxxxxxx ,xxxxxxx                           ,xxxxxxx ,xxxxxxx ,xxxxxxx ,xxxxxxx ,xxxxxxx  xxxxxxx ,xxxxxxx ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    xxxxxxx  ,RGB_MOD ,RGB_HUI ,RGB_SAI ,RGB_VAI ,xxxxxxx ,xxxxxxx                           ,xxxxxxx ,xxxxxxx ,xxxxxxx ,xxxxxxx ,xxxxxxx ,xxxxxxx ,xxxxxxx ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    xxxxxxx  ,RGB_RMOD ,RGB_HUD ,RGB_SAD ,RGB_VAD ,xxxxxxx ,xxxxxxx ,xxxxxxx         ,xxxxxxx ,xxxxxxx ,xxxxxxx ,xxxxxxx ,xxxxxxx ,xxxxxxx ,xxxxxxx ,xxxxxxx ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
    xxxxxxx  ,xxxxxxx ,xxxxxxx ,xxxxxxx      ,_______     ,_______ ,_______         ,_______ ,_______     ,_______      ,xxxxxxx ,xxxxxxx ,xxxxxxx ,xxxxxxx
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),

	[_NUM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
    _______  , _______, _______, _______, _______, _______                                            ,xxxxxxx ,xxxxxxx ,xxxxxxx ,xxxxxxx ,xxxxxxx ,KC_NLCK	,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    _______  , _______, _______, _______, _______, _______, _______                          , _______,xxxxxxx , KC_P7  , KC_P8  , KC_P9  ,KC_PPLS ,KC_PMNS  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	_______  , _______, _______, _______, _______, _______, _______                          , _______,xxxxxxx , KC_P4  , KC_P5  , KC_P6  ,KC_PAST ,KC_PSLS  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	_______  , _______, _______, _______, _______, _______, _______, _______        , _______, _______,xxxxxxx , KC_P1  , KC_P2  , KC_P3  ,xxxxxxx ,KC_PEQL  ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
    _______  , _______, _______, _______     , _______    , _______, _______        , _______, _______    , _______     , KC_P0  , KC_PDOT,xxxxxxx ,xxxxxxx
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),
  };




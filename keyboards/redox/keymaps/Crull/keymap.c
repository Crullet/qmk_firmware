#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _SYMB 1
#define _NAV 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYMB,
  NAV,
  ADJUST,
};

// Shortcut to make keymap more readable
#define SYM_L   MO(_SYMB)

#define ALT_HOM LALT_T(KC_HOME)
#define ALT_END RALT_T(KC_END)

#define NAV_LBR LT(_NAV, KC_LBRC)
#define NAV_SLS LT(_NAV,KC_SLSH)

#define KC_ADRB LT(_ADJUST, KC_RBRC)
#define KC_ADBS LT(_ADJUST, KC_BSLS)

#define TAP_SFT OSM(MOD_LSFT)
#define TAP_CTL OSM(MOD_LCTL)

#define SE_AA	RALT(KC_W)
#define SE_AE	RALT(KC_P)
#define SE_OE	RALT(KC_Q)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
	KC_GESC  , KC_1   , KC_2   , KC_3   , KC_4   , KC_5                                               , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_QUES,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	KC_TAB   , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_GRV                           , KC_QUOT, KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , SE_AA  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	TAP_SFT  , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , MO(1)                            , MO(1)  , KC_H   , KC_J   , KC_K   , KC_L   , SE_AE  , SE_OE  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	TAP_CTL  , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , NAV_LBR, KC_ADRB        , KC_ADBS, NAV_SLS, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_UP  , OSM(MOD_RSFT),
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
	KC_LGUI  , KC_MYCM, KC_EQL , KC_MINS     , ALT_HOM    , KC_BSPC, KC_DEL         , KC_ENT , KC_SPC     , ALT_END     , KC_SCLN, KC_LEFT, KC_DOWN, KC_RGHT
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),

	[_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
	KC_TRNS  , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5                                              , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_NO	,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    KC_TRNS  , KC_EXLM, KC_AT  , KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS                          , KC_TRNS, KC_NO  , KC_P7  , KC_P8  , KC_P9  , KC_NO  , KC_NO  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	KC_CAPS  , KC_HASH, KC_DLR , KC_LBRC, KC_RBRC, KC_GRV , KC_TRNS                          , KC_TRNS, KC_NO  , KC_P4  , KC_P5  , KC_P6  , KC_NO  , KC_NO  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	KC_TRNS  , KC_PERC, KC_CIRC, KC_LPRN, KC_RPRN, KC_TILD, KC_TRNS, KC_TRNS        , KC_TRNS, KC_TRNS, KC_NO  , KC_P1  , KC_P2  , KC_P3  , KC_NO  , KC_NO  ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
    KC_TRNS  , KC_TRNS, KC_TRNS, KC_TRNS     , KC_TRNS    , KC_TRNS, KC_TRNS        , KC_TRNS, KC_TRNS    , KC_P0       , KC_P0  , KC_PDOT, KC_NO  , KC_NO
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),

	[_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
	KC_TRNS  , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS                                            , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	KC_NO    , KC_NO  , KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_TRNS                          , KC_TRNS, KC_NO  , KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, KC_NO  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    KC_NO    , KC_NO  , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_TRNS                          , KC_TRNS, KC_NO  , KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_NO  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    KC_NO    , KC_NO  , KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_TRNS, KC_TRNS        , KC_TRNS, KC_TRNS, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
    KC_NO    , KC_NO  , KC_NO  , KC_NO       , KC_BTN1    , KC_BTN2, KC_TRNS        , KC_TRNS, KC_TRNS    , KC_MPLY     , KC_MSTP, KC_NO  , KC_NO  , KC_NO
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),

	[_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
  	RESET    , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5                                              , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_NLCK,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  	KC_NO    , KC_NO  , KC_NO  , RGB_TOG, RGB_MOD, KC_NO  , KC_NO                            , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	KC_NO    , KC_NO  , RGB_HUI, RGB_SAI, RGB_VAI, KC_NO  , KC_NO                            , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  	KC_NO    , KC_NO  , RGB_HUD, RGB_SAD, RGB_VAD, KC_NO  , KC_TRNS, KC_NO          , KC_NO  , KC_TRNS, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
  	KC_NO   , KC_NO  , KC_NO  , KC_NO       , KC_NO      , KC_NO  , KC_NO          , KC_NO  , KC_NO      , KC_NO       , KC_NO  , KC_NO  , KC_NO  , KC_NO
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),
  };




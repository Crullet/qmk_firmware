/*
Copyright 2018 Mattia Dal Ben <matthewdibi@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Use I2C or Serial, not both */
#define USE_SERIAL
// #define USE_I2C

/* Select hand configuration */
#define MASTER_LEFT
//#define MASTER_RIGHT
#define EE_HANDS

/*#undef RGBLED_NUM
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 14
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
*/

// default but used in macros
#define TAPPING_TERM 250

// Prevent normal rollover on alphas from accidentaly triggering mods.
#define IGNORE_MOD_TAP_INTERUPPT
#define PERMISSIVE_HOLD

//Enable rapid switch from tap to hold, disables double tap hold auto-repeat
//#define TAPPING_FORCE_HOLD

// Auto Shift
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#define NO_AUTO_SHIFT_SPECIAL

//Mouse Key speed and acceleration
#undef  MOUDEKEY_DELAY
#define MOUSEKEY_DELAY 0
#undef  MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16
#undef  MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELA
#undef  MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 16
#undef  MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 64

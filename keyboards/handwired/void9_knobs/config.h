/*
Copyright 2020 Victor Lucachi

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

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID 0xF055
#define PRODUCT_ID 0x3534
#define DEVICE_VER 0x0001
#define MANUFACTURER Tom
#define PRODUCT VOID9
#define DESCRIPTION A handwired 3x3 Macropad

/* key matrix size */
#define MATRIX_ROWS 3
#define MATRIX_COLS 3

#define MATRIX_ROW_PINS { F4, F5, F6 }
#define MATRIX_COL_PINS { D1, D0, D4 }

/* Encoder pins */
#define ENCODERS_PAD_A { B1, B4}
#define ENCODERS_PAD_B { B2, D7}

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

#define ENCODER_RESOLUTIONS { 4, 4 }/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5
#define ENCODER_DIRECTION_FLIP

/* Tap dance max time */
#define TAPPING_TERM 200

/* disable these deprecated features by default */
#ifndef LINK_TIME_OPTIMIZATION_ENABLE
  #define NO_ACTION_MACRO
  #define NO_ACTION_FUNCTION
#endif

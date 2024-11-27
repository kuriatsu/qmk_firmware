// Copyright 2023 kuriatsu (@kuriatsu)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

// #define MASTER_RIGHT

#define OLED_DC_PIN GP18
#define OLED_CS_PIN GP19
#define OLED_DISPLAY_64X32

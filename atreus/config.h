#pragma once

#include "config_common.h"

#undef MATRIX_ROW_PINS
#undef MATRIX_COL_PINS
#undef UNUSED_PINS


#undef TAPPING_TERM
#define TAPPING_TERM 180
#undef IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD

// Pin configuration for github.com/ibnuda/atreus/tree/promicro
#define MATRIX_ROW_PINS { F4, B2, B4, B5 }
#define MATRIX_COL_PINS { F5, F6, F7, B1, B3, B6, E6, D7, C6, D4, D0 }
#define UNUSED_PINS

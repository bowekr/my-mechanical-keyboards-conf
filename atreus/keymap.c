// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER  1
#define _RAISE  2
#define _SYMBOL 3
#define _ADJUST 4

#define ______   KC_TRNS
#define N        KC_TRANS

#define KC_UNDR LSFT(KC_MINS)
#define KC_QUES LSFT(KC_SLSH)

#define SH_ESC  SFT_T(KC_ESC)
#define ALT_ENT ALT_T(KC_ENT)

#define AL_E ALT_T(KC_E)
#define AL_T ALT_T(KC_T)
#define CT_N CTL_T(KC_N)
#define CT_O CTL_T(KC_O)
#define GU_H LGUI_T(KC_H)
#define GU_U LGUI_T(KC_U)
#define SH_A SFT_T(KC_A)
#define SH_S SFT_T(KC_S)

#define LW_BSPC LT(_LOWER, KC_BSPC)
#define RS_SPC  LT(_RAISE, KC_SPC)

#define RAISE   MO(_RAISE)
#define LOWER   MO(_LOWER)
#define ADJUST  MO(_ADJUST)
#define SYMBOL  MO(_SYMBOL)

#define SW_QW   DF(_QWERTY)

#define EXPLORER LGUI(KC_E)
#define LOCKGUI  LGUI(KC_L)
#define TASKMGR  LCTL(LSFT(KC_ESC))
#define CALTDEL  LCTL(LALT(KC_DELT))
#define PREVWIN  LCTL(KC_LEFT) // OSX Prev Desktop -> LCTL + LEFT
#define NEXTWIN  LCTL(KC_RIGHT) // OSX Next Desktop -> LCTL + RIGHT
#define PREVTAB  LCTL(KC_PGDN)
#define NEXTTAB  LCTL(KC_PGUP)

#define SH_Z SFT_T(KC_Z)
#define SH_SL SFT_T(KC_SLSH)

#define M_COPY LGUI(KC_C)
#define M_PASTE LGUI(KC_V)
#define M_UNDO LGUI(KC_Z)
#define M_TILD LGUI(KC_GRAVE)
#define M_TMUX_LEADER LCTL(KC_F)
#define M_VIM_LEADER LCTL(KC_W)
#define M_SELECT_ALL LGUI(KC_A)
#define M_ABORT LCTL(KC_C)

enum custom_keycodes  {
    ALTAB = SAFE_RANGE
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,   KC_U,    KC_I,    KC_O,    KC_P    ,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN ,
    SH_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,   KC_M,    KC_COMM, KC_DOT,  SH_SL,
    SYMBOL,  KC_TAB,  KC_LALT, SH_ESC,  LW_BSPC, KC_LGUI, KC_LCTL, RS_SPC, ALT_ENT, KC_MINS, KC_QUOT, KC_ENT ),

  [_RAISE] = LAYOUT(
    KC_ESC,   ______,  KC_UP, ______, ______,                     ______,     ______, ______, ______, ______,
    KC_GRAVE, KC_LEFT, KC_DOWN, KC_RIGHT,  ______,                ______,     KC_7,          KC_8,     KC_9,    KC_0,
    KC_EQL,   ______,  ______,  ______,  ______,                   ______,     KC_4,          KC_5,     KC_6,    KC_UNDERSCORE,
    ______,   ______,  ______,  ______, ADJUST,  KC_LCTL, KC_LALT, ______,     KC_1,          KC_2,     KC_3,    KC_ENT),


  [_SYMBOL] = LAYOUT(
    KC_EXLM,     KC_AT,   KC_HASH,     KC_DOLLAR, KC_PERCENT,               KC_CIRCUMFLEX, KC_AMPR,  KC_ASTR, KC_PLUS, ______,
    LCTL(KC_A),  ______,  LCTL(KC_E),  ______,  ______,                   ______, ______, ______, ______, ______,
    ______,      ______,  M_ABORT,     ______,  ______,                   ______, ______, ______, ______, ______,
    ______,      ______,  ______,      ______,  ______, ______, ______,   ______, ______, ______, ______, ______),

  [_LOWER] = LAYOUT(
    M_TILD,       M_VIM_LEADER, ______, ______,         ______,                    KC_LPRN, KC_RPRN, ______,  ______,  KC_MINS,
    M_SELECT_ALL, ______,       ______, M_TMUX_LEADER,  ______,                    KC_LCBR, KC_RCBR, ______,  KC_0,    KC_DQUO,
    M_UNDO,       ______,       M_COPY, M_PASTE,        ______,                    KC_LBRC, KC_RBRC, ______,  KC_UP,   KC_UNDERSCORE,
    ______,       ______,       ______, ______,         ______, KC_LCTL, KC_TRNS,  ADJUST,  ALT_ENT, KC_LEFT, KC_DOWN, KC_RIGHT),

  [_ADJUST] = LAYOUT(
    ______,  EXPLORER, ______,  NEXTTAB, NEXTWIN,                PREVWIN, PREVTAB, ______,  ______, LOCKGUI ,
    TASKMGR, ______,   ______,  ______,  ______,                  SW_QW,   ______,  KC_LGUI, ______, CALTDEL ,
    ______,  ______,   ______,  ______,  RESET,                  ______,  ______,  ______,  ______, ______  ,
    ______,  ______,   ______,  ______,  ______, ______, ______, ______,  ______,  ______,  ______, ______ ),
};

const uint16_t PROGMEM fn_actions[] = {
};

/*const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {*/
    /*return MACRO_NONE;*/
/*};*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case GOVARS:
            if (record->event.pressed) {
                SEND_STRING(":=")
            }
            break;
    }

    return true;
}

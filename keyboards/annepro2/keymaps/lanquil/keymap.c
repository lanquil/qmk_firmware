// Forked from codetector
//
// Docs:
// https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md

#include <stdint.h>
#include "annepro2.h"
#include "qmk_ap2_led.h"

enum anne_pro_layers {
  _BASE_LAYER,
  _KEYPAD_LAYER,
  _ARROW_LAYER,
  _FN_LAYER,
};

// This is ROW*MATRIX_COLS + COL
#define CAPS_LOCATION (MATRIX_COLS * 2 + 0)

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
  * Layer _BASE_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |  `  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |   \    |
  * |-----------------------------------------------------------------------------------------+
  * | Esc     |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  | L_GUI | Alt ( |               Space             | Alt ) |  Fn1  | Menu  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  * Layer HOLD in _BASE_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
  * |-----------------------------------------------------------------------------------------+
  * |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
  * |-----------------------------------------------------------------------------------------+
  * | Arrow_L |     |     |     |     |     |     |     |     |     |     |     |             |
  * |-----------------------------------------------------------------------------------------+
  * |            |     |     |     |     |     |     |     |     |     |     |                |
  * |-----------------------------------------------------------------------------------------+
  * |       |       |       |                                 |       | Fn_L  |       |       |
  * \-----------------------------------------------------------------------------------------/
  */
  [_BASE_LAYER] = KEYMAP( /* Base */
    KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
    LT(_ARROW_LAYER, KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LAPO,      KC_SPC,             KC_RAPC, MO(_FN_LAYER), KC_APPLICATION, KC_RCTL
  ),
  /*
  * Layer _KEYPAD_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |     |     |     |     |     |  %  |  =  |  /  |  *  |     |     |     |     |           |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |     |     |     |     |  ,  |  7  |  8  |  9  |  -  |     |     |     |        |
  * |-----------------------------------------------------------------------------------------+
  * | Esc     |     |     |     |     |Enter|  4  |  5  |  6  |  +  |     |     |   NumLock   |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |     |     |     |     | Bksp|  1  |  2  |  3  |  .  |     |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  | L_GUI | Alt ( |                 0               | Alt ) |  Fn1  | Menu  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  * Layer HOLD in _KEYPAD_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
  * |-----------------------------------------------------------------------------------------+
  * |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
  * |-----------------------------------------------------------------------------------------+
  * | Arrow_L |     |     |     |     |     |     |     |     |     |     |     |             |
  * |-----------------------------------------------------------------------------------------+
  * |            |     |     |     |     |     |     |     |     |     |     |                |
  * |-----------------------------------------------------------------------------------------+
  * |       |       |       |                                 |       | Fn_L  |       |       |
  * \-----------------------------------------------------------------------------------------/
  */
  [_KEYPAD_LAYER] = KEYMAP( /* Base */
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PERCENT, KC_KP_EQUAL, KC_KP_SLASH, KC_KP_ASTERISK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_KP_COMMA, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_MINUS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    LT(_ARROW_LAYER, KC_ESC), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_KP_ENTER, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_PLUS, XXXXXXX, XXXXXXX, KC_NUM_LOCK,
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_DOT, XXXXXXX, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LAPO,      KC_KP_0,             KC_RAPC, MO(_FN_LAYER), KC_APPLICATION, KC_RCTL
  ),
  /* Layer _ARROW_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
  * |-----------------------------------------------------------------------------------------+
  * |        |     |     |     |     |     |     |     |     |     |     | Home| End |        |
  * |-----------------------------------------------------------------------------------------+
  * |         |     |     |     |     |     | Left| Down| Up  |Right| PgU | PgD |             |
  * |-----------------------------------------------------------------------------------------+
  * |            |     |     |     |     |     |     |     |     | Ins | Del |                |
  * |-----------------------------------------------------------------------------------------+
  * |       |       |       |                                 |       |       |       |       |
  * \-----------------------------------------------------------------------------------------/
  */
  [_ARROW_LAYER] = KEYMAP( /* Base */
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_END, _______,
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INSERT, KC_DELETE, _______,
    _______, _______, _______,      _______,              _______, _______, _______, _______
  ),
  /* Layer _FN_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |Sleep| F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |    Del    |
  * |-----------------------------------------------------------------------------------------+
  * | MsBut3 |     | MsU |MsWhl|MsWUp|     |L_Int|L_Frq| L_On|L_Off|  PS | Home| End |Keypad_L|
  * |-----------------------------------------------------------------------------------------+
  * | CapsLock| MsL | MsD | MsR |MsWDw|     | Left| Down| Up  |Right| PgU | PgD | Base_Layer  |
  * |-----------------------------------------------------------------------------------------+
  * | MsButton1  |BtUnp| Bt1 | Bt2 | Bt3 | USB |VolUp|VolDw| Mute| Ins | Del |     Shift      |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |       |  Alt  |       MsAccel1                  |R_Macro|       | Fn_L  | Macro |
  * \-----------------------------------------------------------------------------------------/
  */
  [_FN_LAYER] = KEYMAP( /* Base */
    KC_SYSTEM_SLEEP, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DELETE,
    KC_MS_BTN3, XXXXXXX, KC_MS_UP, KC_MS_BTN2, KC_MS_WH_UP, XXXXXXX, KC_AP_LED_NEXT_INTENSITY, KC_AP_LED_SPEED, KC_AP_LED_ON, KC_AP_LED_OFF, KC_PSCR, KC_HOME, KC_END, DF(_KEYPAD_LAYER),
    KC_CAPS, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_WH_DOWN, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_PGUP, KC_PGDN, DF(_BASE_LAYER),
    KC_MS_BTN1, KC_AP2_BT_UNPAIR, KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT3, KC_AP2_USB, KC_VOLU, KC_VOLD, KC_MUTE, KC_INSERT, KC_DELETE, KC_RSFT,
    KC_LCTL, _______, KC_LALT,      KC_MS_ACCEL1,             DYN_REC_START1, _______, DF(_FN_LAYER), DYN_MACRO_PLAY1
  ),
};

const uint16_t keymaps_size = sizeof(keymaps);


void matrix_init_user(void) {

}

void matrix_scan_user(void) {
}

// Code to run after initializing the keyboard
void keyboard_post_init_user(void) {
    // Here are two common functions that you can use. For more LED functions, refer to the file "qmk_ap2_led.h"
    annepro2LedEnable();
    // Additionally, it also chooses the first LED profile by default. Refer to the "profiles" array in main.c in
    // annepro2-shine to see the order. Replace "i" with the index of your preferred profile. (i.e the RED profile is index 0)
    annepro2LedSetProfile(14);

    // Slower animation speed
    annepro2LedNextAnimationSpeed();
    // annepro2LedNextAnimationSpeed(); // even slower
    // annepro2LedNextAnimationSpeed(); // slowest
}

layer_state_t layer_state_set_user(layer_state_t layer) {
  switch(get_highest_layer(layer)) {
    case _FN_LAYER:
      annepro2LedSetForegroundColor(0x20, 0xFF, 0x4c);
      // annepro2LedSetForegroundColor(0x60, 0xFF, 0x60);
      // annepro2LedSetForegroundColor(0x00, 0xFF, 0x66);
      // annepro2LedSetForegroundColor(0x20, 0xFF, 0x79);
      break;
    case _KEYPAD_LAYER:
      annepro2LedSetForegroundColor(0x00, 0x00, 0xFF);  // blue
      break;
    default:
      annepro2LedResetForegroundColor();  // Reset back to the current profile
      break;
  }
  return layer;
}

// The function to handle the caps lock logic
// It's called after the capslock changes state or after entering layers 1 and 2.
bool led_update_user(led_t leds) {
  if (leds.caps_lock) {
    // Set the caps-lock to red
    const annepro2Led_t color = {
        .p.red = 0xff,
        .p.green = 0x00,
        .p.blue = 0x00,
        .p.alpha = 0xff
    };

    annepro2LedMaskSetKey(2, 0, color);
    /* NOTE: Instead of colouring the capslock only, you can change the whole
       keyboard with annepro2LedSetForegroundColor */
  } else {
    // Reset the capslock if there is no layer active
    if(!layer_state_is(_FN_LAYER) && !layer_state_is(_KEYPAD_LAYER)) {
      const annepro2Led_t color = {
          .p.red = 0xff,
          .p.green = 0x00,
          .p.blue = 0x00,
          .p.alpha = 0x00
      };
      annepro2LedMaskSetKey(2, 0, color);
    }
  }

  return true;
}

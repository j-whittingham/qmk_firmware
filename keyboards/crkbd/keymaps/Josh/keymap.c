#include QMK_KEYBOARD_H
#include <stdio.h>
#include "crkbd.h"

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _NAV 1
#define _MOUSE 2
#define _NUMB 3
#define _SYMB 4
#define _FUNC 5
#define _CTRL 6

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NAV,
  MOUSE,
  NUMB,
  SYMB,
  FUNC,
  CTRL,
  BACKLIT,
  RGBRST
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

//Tap Dance Declarations
enum {
  TD_TAB_ESC = 0
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_TAB_ESC]  = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_ESC)
// Other declarations would go here, separated by commas, if you have them
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT( 
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
    TD(TD_TAB_ESC) , LT(6, KC_Q)     , KC_W      , KC_E          , KC_R   , KC_T  , KC_Y        , KC_U        , KC_I  , KC_O,KC_P, KC_BSPC,
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
    KC_LCTL, KC_A        , LT(5,KC_S), LT(4,KC_D), KC_F          , KC_G   , KC_H  , KC_J        , KC_K        , KC_L  , KC_SCLN  , KC_QUOT,
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
    KC_LSFT, LGUI_T(KC_Z), KC_X      , KC_C      , KC_V          , KC_B   , KC_N  , KC_M        , KC_COMM     , KC_DOT, KC_SLSH  , KC_ENT ,
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
                                       KC_LALT   , LSFT_T(KC_DEL),LT(3,KC_BSPC),LT(3,KC_ENT),KC_SPC, LT(1,KC_TAB)
//                                   .-----------+---------------+-------, ,------+-------------+-------------.
),

[_NAV] = LAYOUT( 
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
    KC_ESC ,KC_NO        ,KC_NO      ,KC_NO      ,KC_NO          ,KC_CUT  ,KC_NO  ,KC_PGUP      ,KC_UP        ,KC_PGDN,KC_NO     ,KC_BSPC,
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
    KC_LCTL,KC_NO        ,KC_NO      ,LT(2,KC_NO),KC_NO          ,KC_COPY ,KC_NO  ,KC_LEFT      ,KC_DOWN      ,KC_RGHT,KC_NO     ,KC_DEL,
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
    KC_LSFT,KC_NO        ,KC_NO      ,KC_NO      ,KC_NO          ,KC_PSTE ,KC_NO  ,KC_HOME      ,KC_END       ,KC_INS ,KC_NO     ,KC_ENT,
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
                                      KC_LALT    ,LSFT_T(KC_DEL) ,KC_BSPC , KC_ENT,KC_SPC       ,KC_TRNS
//                                   .-----------+---------------+-------, ,------+-------------+-------------.
),

[_MOUSE] = LAYOUT( 
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
    KC_ESC ,KC_NO        ,KC_NO      ,KC_NO      ,KC_NO          ,KC_NO   ,KC_ACL0,KC_WH_U      ,KC_MS_U      ,KC_WH_D,KC_NO   ,KC_BSPC,
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
    KC_LCTL,KC_NO        ,KC_NO      ,KC_TRNS    ,KC_NO          ,KC_NO   ,KC_ACL1,KC_MS_L      ,KC_MS_D      ,KC_MS_R,KC_NO   ,KC_DEL,
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
    KC_LSFT,KC_NO        ,KC_NO      ,KC_NO      ,KC_NO          ,KC_NO   ,KC_ACL2,KC_BTN1      ,KC_BTN2      ,KC_BTN3,KC_NO   ,KC_ENT,
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
                                      KC_LALT    ,KC_LSFT        ,KC_BSPC , KC_ENT,KC_SPC       ,KC_TRNS
//                                   .-----------+---------------+-------, ,------+-------------+-------------.
),

[_NUMB] = LAYOUT( 
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
    KC_ESC ,KC_1         ,KC_2       ,KC_3       ,KC_4           ,KC_5    , KC_6  ,KC_7         ,KC_8         ,KC_9   ,KC_0      ,KC_BSPC,
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
    KC_LCTL,KC_LBRC      ,KC_EQL     ,KC_PLUS    ,KC_ASTR        ,KC_LPRN , KC_COMM,KC_4         ,KC_5         ,KC_6   ,KC_LT   ,KC_DEL,
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
    KC_LSFT,KC_RBRC      ,KC_F2      ,KC_MINS    ,KC_SLSH        ,KC_RPRN , KC_DOT  ,KC_1         ,KC_2         ,KC_3   ,KC_GT     ,KC_ENT,
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
                                      KC_LALT    ,KC_LSFT        ,KC_TRNS , KC_TRNS ,KC_0      ,KC_NO
//                                   .-----------+---------------+-------, ,------+-------------+-------------.
),

[_SYMB] = LAYOUT( 
// .-------+-------------+-----------+-----------+---------------+------------, ,-------+-------------+-------------+-------+----------+--------.
    KC_ESC ,KC_NO        ,KC_RO      ,KC_NO      ,KC_PLUS        ,KC_SLSH      , KC_EXLM,KC_DLR       ,KC_AMPR      ,LSFT(KC_3),KC_CIRC,KC_BSPC,
// .-------+-------------+-----------+-----------+---------------+------------, ,-------+-------------+-------------+-------+----------+--------.
    KC_LCTL,KC_NO        ,KC_MINS    ,KC_TRNS    ,KC_EQL         ,KC_NUBS      , LSFT(KC_2),KC_LPRN   ,KC_UNDS      ,KC_RPRN,KC_LCBR   ,KC_DEL,
// .-------+-------------+-----------+-----------+---------------+------------, ,-------+-------------+-------------+-------+----------+--------.
    KC_LSFT,KC_GRV       ,LSFT(KC_NUHS),KC_NO    ,KC_ASTR        ,LSFT(KC_NUBS), KC_NUHS,KC_LBRC      ,KC_PERC      ,KC_RBRC,KC_RCBR   ,KC_ENT,
// .-------+-------------+-----------+-----------+---------------+------------, ,-------+-------------+-------------+-------+----------+--------.
                                      KC_LALT    ,KC_LSFT        ,KC_BSPC      , KC_ENT ,KC_SPC       ,KC_TAB
//                                   .-----------+---------------+------------, ,-------+-------------+-------------.
),

[_FUNC] = LAYOUT( 
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
    KC_NO  ,KC_NO        ,KC_NO      ,KC_NO      ,KC_NO          ,KC_NO   ,KC_NO  ,KC_F7        ,KC_F8        ,KC_F9  ,KC_F10    ,KC_NO,
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
    KC_NO  ,KC_NO        ,KC_TRNS    ,KC_F2      ,KC_F4          ,KC_NO   ,KC_NO  ,KC_F4        ,KC_F5        ,KC_F6  ,KC_F11    ,KC_NO,
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
    KC_NO  ,KC_NO        ,KC_NO      ,KC_NO      ,KC_NO          ,KC_NO   ,KC_NO  ,KC_F1        ,KC_F2        ,KC_F3  ,KC_F12    ,KC_NO,
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
                                      KC_NO      ,KC_NO          ,KC_NO   , KC_NO ,KC_NO        ,KC_NO
//                                   .-----------+---------------+-------, ,------+-------------+-------------.
),

[_CTRL] = LAYOUT(
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
    RESET  ,KC_TRNS      ,RGB_VAD    ,RGB_TOG    ,RGB_VAI        ,KC_NO   , KC_NO ,KC_MPLY      ,KC_VOLU      ,KC_MUTE,KC_NO     ,KC_SLCK,
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
    EEP_RST,RGB_HUI      ,BL_DEC     ,BL_TOGG    ,BL_INC         ,RGB_SAI , KC_NO ,KC_MPRV      ,KC_VOLD      ,KC_MNXT,KC_NO     ,KC_CAPS,
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
    KC_NO  ,RGB_HUD      ,RGB_RMOD   ,BL_BRTG    ,RGB_MOD        ,RGB_SAD , KC_NO ,KC_BRID      ,KC_BRIU      ,KC_NO  ,KC_NO     ,KC_NLCK,
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
                                      KC_NO      ,KC_NO          ,KC_NO   , KC_NO ,KC_NO        ,KC_NO
//                                   .-----------+---------------+-------, ,------+-------------+-------------.
)

// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
//                                   .-----------+---------------+-------, ,------+-------------+-------------.
};


int RGB_current_mode;

// RGB Layer code

// Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 4, HSV_RED},       // Light 4 LEDs, starting with LED 6
    {12, 4, HSV_RED}       // Light 4 LEDs, starting with LED 12
);
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_nav_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {9, 2, HSV_CYAN}
);
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_numbers_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {11, 2, HSV_PURPLE}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_qwerty_layer,
    my_nav_layer,
    my_numbers_layer 
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // Both layers will light up if both kb layers are active
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    return state;
}

// bool led_update_user(led_t led_state) {
//     rgblight_set_layer_state(0, led_state.caps_lock);
//     return true;
// }





void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

char wpmstr[20];

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    //matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
    //matrix_write_ln(matrix, sprintf(wpmstr,"%d", get_current_wpm()));
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);

}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  // switch (keycode) {
  //   case LOWER:
  //     if (record->event.pressed) {
  //       layer_on(_LOWER);
  //       update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
  //     } else {
  //       layer_off(_LOWER);
  //       update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
  //     }
  //     return false;
  //   case RAISE:
  //     if (record->event.pressed) {
  //       layer_on(_RAISE);
  //       update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
  //     } else {
  //       layer_off(_RAISE);
  //       update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
  //     }
  //     return false;
  //   case ADJUST:
  //       if (record->event.pressed) {
  //         layer_on(_ADJUST);
  //       } else {
  //         layer_off(_ADJUST);
  //       }
  //       return false;
  //     break;
  // }
return true;
}
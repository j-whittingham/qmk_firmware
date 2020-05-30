#include QMK_KEYBOARD_H
#include "split_util.h"

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum crkbd_layers {
  _QWERTY,
  _NAV,
  _MOUSE,
  _NUMB,
  _SYMB,
  _FUNC,
  _CTRL
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
    KC_LCTL,LSFT(KC_3)   ,KC_MINS    ,KC_TRNS    ,KC_EQL         ,KC_NUBS      , LSFT(KC_2),KC_LPRN   ,KC_UNDS      ,KC_RPRN,KC_LCBR   ,KC_DEL,
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
    RESET  ,KC_TRNS      ,RGB_TOG    ,RGB_MOD    ,KC_NO          ,KC_NO   , KC_NO ,KC_MPLY      ,KC_VOLU      ,KC_MUTE,KC_NO     ,KC_SLCK,
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
    EEP_RST,RGB_HUI      ,RGB_VAI    ,RGB_SAI    ,KC_NO          ,KC_NO   , KC_NO ,KC_MPRV      ,KC_VOLD      ,KC_MNXT,KC_NO     ,KC_CAPS,
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
    KC_NO  ,RGB_HUD      ,RGB_VAD    ,RGB_SAD    ,KC_NO          ,KC_NO   , KC_NO ,KC_BRID      ,KC_BRIU      ,KC_NO  ,KC_NO     ,KC_NLCK,
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

 
#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!isLeftHand){
    return OLED_ROTATION_180;  // flips the slave display 180
  } else {
    return OLED_ROTATION_270;  // flips the master display to be portrait
  }
  return rotation;
}

const char *read_logo(void);  
void oled_task_user(void){
    if (isLeftHand){
    switch (biton32(layer_state)){
        case 0:
            oled_write_ln_P(PSTR("QWERT"), false);
            break;
        case 1:
            oled_write_ln_P(PSTR("NAVIG"), false);
            break;
        case 2:
            oled_write_ln_P(PSTR("MOUSE"), false);
            break;
        case 3:
            oled_write_ln_P(PSTR("NUMBR"), false);
            break;
        case 4:
            oled_write_ln_P(PSTR("SYMBL"), false);
            break;
        case 5:
            oled_write_ln_P(PSTR("FUNCT"), false);
            break;
        case 6:
            oled_write_ln_P(PSTR("CONTR"), false);
            break;
        default:
            oled_write_ln_P(PSTR("?????"), false);
    }
    } else {
      oled_write(read_logo(), false);
    }
}
#endif






uint16_t get_tapping_term(uint16_t keycode) {
    switch (keycode) {
        case LT(6, KC_Q):
            return TAPPING_TERM + 100;
        default:
            return TAPPING_TERM;
    }
}

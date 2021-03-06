#include QMK_KEYBOARD_H
#include "split_util.h"

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

enum crkbd_layers {
  _QWERTY,
  _NAV,
  _NUMB,
  _FUNC,
  _GAME
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT( 
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
    LGUI_T(KC_TAB), KC_Q , KC_W      , KC_E      , KC_R          , KC_T    , KC_Y , KC_U        , KC_I        , KC_O  , KC_P      ,KC_BSPC,
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
    KC_LCTL, KC_A        , KC_S      , KC_D      ,LT(_NUMB,KC_F) , KC_G    , KC_H , KC_J        , KC_K        , KC_L  , KC_SCLN  , LT(_FUNC,KC_QUOT),
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
    LSFT_T(KC_ESC), KC_Z, KC_X       , KC_C      , KC_V          , KC_B    , KC_N , KC_M        , KC_COMM     , KC_DOT, KC_SLSH  , KC_MINS ,
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
                                       KC_LALT   , KC_LSFT ,LT(_FUNC,KC_DEL),KC_ENT, KC_SPC     , LT(_NAV,KC_NO)
//                                   .-----------+---------------+-------, ,------+-------------+-------------.
),

[_NAV] = LAYOUT( 
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
    KC_LGUI ,KC_NO       ,KC_F2      ,KC_NO      ,KC_NO          ,KC_NO   ,KC_NO  ,KC_PGUP      ,KC_UP        ,KC_PGDN,KC_NO     ,KC_BSPC,
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
    KC_LCTL,KC_NO        ,KC_NO      ,KC_NO      ,KC_NO          ,KC_NO   ,KC_NO  ,KC_LEFT      ,KC_DOWN      ,KC_RGHT,KC_NO     ,KC_NO,
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
    KC_LSFT,KC_NO        ,KC_NO      ,KC_NO      ,KC_NO          ,KC_NO   ,KC_NO  ,KC_HOME      ,KC_END       ,KC_INS ,KC_NO     ,KC_NO,
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
                                      KC_LALT    ,KC_LSFT        ,KC_DEL  , KC_ENT,KC_SPC       ,KC_TRNS
//                                   .-----------+---------------+-------, ,------+-------------+-------------.
),

[_NUMB] = LAYOUT( 
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
    KC_NUHS, LSFT(KC_1)  ,LSFT(KC_9) ,LSFT(KC_0) ,KC_GRV   ,LSFT(KC_2) ,LSFT(KC_3),KC_7         ,KC_8         ,KC_9   ,KC_NO     ,KC_BSPC,
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
    KC_LCTL, LSFT(KC_5)  ,KC_SLSH     ,KC_MINS   ,KC_TRNS    ,LSFT(KC_7)  , KC_EQL, KC_4        ,KC_5         ,KC_6 ,LSFT(KC_SCLN),KC_QUOT,
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
    KC_LSFT, LSFT(KC_6)  ,LSFT(KC_8) ,LSFT(KC_EQL),KC_NUBS        ,KC_NO  , KC_DOT  ,KC_1       ,KC_2         ,KC_3   ,KC_SLSH   ,LSFT(KC_MINS),
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
                                      KC_LALT    ,KC_LSFT        ,KC_DEL  , KC_ENT, KC_SPC      ,KC_0
//                                   .-----------+---------------+-------, ,------+-------------+-------------.
),

[_FUNC] = LAYOUT( 
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
    KC_NO  ,KC_NO        ,KC_F2      ,KC_NO      ,KC_NO          ,KC_NO   ,KC_NO  ,KC_F7        ,KC_F8        ,KC_F9  ,KC_F10    ,KC_NO,
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
    KC_LCTL,KC_NO        ,KC_NO      ,KC_NO      ,KC_NO          ,KC_NO   ,KC_NO  ,KC_F4        ,KC_F5        ,KC_F6  ,KC_F11    ,KC_TRNS,
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
    KC_LSFT,KC_NO        ,KC_NO      ,KC_NO      ,KC_LBRC        ,KC_RBRC ,KC_NO  ,KC_F1        ,KC_F2        ,KC_F3  ,KC_F12    ,TG(_GAME),
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
                                      KC_NO      ,KC_LSFT        ,KC_TRNS ,KC_LEAD,KC_NO        ,KC_NO
//                                   .-----------+---------------+-------, ,------+-------------+-------------.
),

[_GAME] = LAYOUT( 
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
    KC_TAB , KC_Q        , KC_W      , KC_E      , KC_R          , KC_T    , KC_Y , KC_U        , KC_I        , KC_O  , KC_P      ,KC_BSPC,
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
    KC_LCTL, KC_A        , KC_S      , KC_D      ,KC_F           , KC_G    , KC_H , KC_J        , KC_K        , KC_L  , KC_SCLN  , KC_DEL,
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
    KC_LSFT, KC_Z        , KC_X      , KC_C      , KC_V          , KC_B    , KC_N , KC_M        , KC_COMM     , KC_DOT, KC_SLSH  ,TG(_GAME),
// .-------+-------------+-----------+-----------+---------------+-------, ,------+-------------+-------------+-------+----------+--------.
                                       KC_LALT   , KC_SPC        ,KC_ENT   ,KC_ENT, KC_ESC      , KC_NO
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
    if (!isLeftHand){
    switch (biton32(layer_state)){
        case _QWERTY:
            oled_write_ln_P(PSTR("QWERT"), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR("NAVIG"), false);
            break;
        case _NUMB:
            oled_write_ln_P(PSTR("NUMBR"), false);
            break;
        case _FUNC:
            oled_write_ln_P(PSTR("FUNCT"), false);
            break;
        case _GAME:
            oled_write_ln_P(PSTR("GAME"), false);
            break;
        default:
            oled_write_ln_P(PSTR("?????"), false);
    }
    } else {
      oled_write(read_logo(), false);
    }
}
#endif

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_F1) {
      SEND_STRING("j.whittingham\"live.co.uk");
    }
    SEQ_ONE_KEY(KC_F2) {
      SEND_STRING("joshua.whittingham\"pwc.com");
    }
    SEQ_ONE_KEY(KC_F3) {
      SEND_STRING("test");
    }
    SEQ_ONE_KEY(KC_F4) {
      SEND_STRING("test");
    }
    SEQ_ONE_KEY(KC_F5) {
      SEND_STRING("test");
    }
    SEQ_ONE_KEY(KC_F6) {
      SEND_STRING("test");
    }
    SEQ_ONE_KEY(KC_F7) {
      SEND_STRING("test");
    }
    SEQ_ONE_KEY(KC_F8) {
      SEND_STRING("test");
    } 
    SEQ_ONE_KEY(KC_F9) {
      SEND_STRING("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
    }
    // SEQ_TWO_KEYS(KC_D, KC_D) {
    //   SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
    // }
    // SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
    //   SEND_STRING("https://start.duckduckgo.com\n");
    // }
    // SEQ_TWO_KEYS(KC_A, KC_S) 
    //   register_code(KC_LGUI);
    //   register_code(KC_S);
    //   unregister_code(KC_S);
    //   unregister_code(KC_LGUI);
    // }
  }
}
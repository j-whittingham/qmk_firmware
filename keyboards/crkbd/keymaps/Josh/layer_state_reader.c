

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "crkbd.h"

char layer_state_str[24];
const char *read_layer_state(void) {
  switch (layer_state)
  {
  case 0:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Qwerty");
    break;
  case 2:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Navigation");
    break;
  case 6:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Mouse");
    break;
  case 8:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Number");
    break;
  case 16:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Symbol");
    break;
  case 32:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Function");
    break;
  case 64:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Control");
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state);
  }

  return layer_state_str;
}
#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _BASE 0
#define _L1   1
#define _L2   2
#define _L3   3
#define _RGB  4

#define BS_L1 LT(_L1, KC_BSPC)
#define SP_L2 LT(_L2, KC_SPACE)

#define TG_L0 TO(0)
#define TG_L3 TO(3)
#define TG_L4 TO(4)

#define CUT   LCTL(KC_X)
#define COPY  LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define UNDO  LCTL(KC_Z)

// enum custom_keycodes {
//   QWERTY = SAFE_RANGE,
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    * ┌───┬───┐  ┌───┬───┬───┬───┬───┬───┬───┐   ┌───┬───┬───┬───┬───┬───┬───┬───┬───┐
    * |_L3|esc|  │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │   │ 7 │ 8 │ 9 │ 0 │ - │ = │ins│del│hom|
    * ├───┼───┤  ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘ ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┼───┤
    * | F1|F2 |  │ tab │ q │ w │ e │ r │ t │   │ y │ u │ i │ o │ p │ [ │ ] │  \  │pUp|
    * ├───┼───┤  ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐  └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
    * | F3|F4 |  │ caps │ a │ s │ d │ f │ g │   │ h | j │ k │ l │ ; │ ' │  enter │pUp|
    * ├───┼───┤  ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐ └─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
    * | F5|F6 |  │ shift  │ z │ x │ c │ v │ b │   │ n │ m │ < │ > │ / │shift │ ↑ │pDn|
    * ├───┼───┤  ├────┬───┴┬──┴─┬─┴───┴──┬┴───┤   ├───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
    * | F7|F8 |  │esc |gui │alt │bs / _L1│ctl │   │ sp / _L2 │alt│ctl│gui│ ← │ ↓ │ → |
    * └───┴───┘  └────┴────┴────┴────────┴────┘   └──────────┴───┴───┴───┴───┴───┴───┘
    */
    [_BASE] = LAYOUT_65_with_macro(
        TG_L3,   KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_INS,  KC_DEL, KC_HOME, \
        KC_F1,   KC_F2,   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_END, \
        KC_F3,   KC_F4,   KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_PGUP, \
        KC_F5,   KC_F6,   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN, \
        KC_F7,   KC_F8,   KC_ESC,  KC_LGUI, KC_LALT, BS_L1,   KC_LCTL,          _______, SP_L2,   KC_RALT, KC_RCTL, KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    /*
    * ┌───┬───┐  ┌───┬───┬───┬───┬───┬───┬───┐   ┌───┬───┬───┬───┬───┬───┬───┬───┬───┐
    * |rst|   |  │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │rst|
    * ├───┼───┤  ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘ ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┼───┤
    * |   |   |  │     │   │   │   │   │   │   │hom│ ↑ │end│pUp│   │   │   │     │   |
    * ├───┼───┤  ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐  └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
    * |   |   |  │      │shf│gui│alt│ctl│   │   │ ← | ↓ │ → │pDn│   │   │        │   |
    * ├───┼───┤  ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐ └─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
    * | F9|F10|  │        │   │   │   │   │   │   │   │   │   │   │   │      │   │   |
    * ├───┼───┤  ├────┬───┴┬──┴─┬─┴───┴──┬┴───┤   ├───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
    * |F11|F12|  │    |    │    │        │    │   │    del   │   │   │   │   │   │   |
    * └───┴───┘  └────┴────┴────┴────────┴────┘   └──────────┴───┴───┴───┴───┴───┴───┘
    */
    [_L1] = LAYOUT_65_with_macro(
        RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______, _______, _______, _______ , \
        _______, _______, _______, KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, _______, _______, \
        KC_F9,   KC_F10,  _______, UNDO,    CUT,     COPY,    PASTE,   _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        KC_F11,  KC_F12,  _______, _______, _______, _______, _______,          _______, KC_DEL,  _______, _______, _______, _______, _______, _______
    ),

    /*
    * ┌───┬───┐  ┌───┬───┬───┬───┬───┬───┬───┐   ┌───┬───┬───┬───┬───┬───┬───┬───┬───┐
    * |rst|   |  │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │rst|
    * ├───┼───┤  ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘ ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┼───┤
    * |   |   |  │     │   │   │   │   │   │   │b1 │ ↑ │b2 │wUp│   │   │   │     │_L4|
    * ├───┼───┤  ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐  └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
    * |   |   |  │      │   │   │   │   │   │   │ ← | ↓ │ → │wDn│   │   │        │   |
    * ├───┼───┤  ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐ └─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
    * |   |   |  │        │   │   │   │   │   │   │ac0│ac1│ac2│   |   │      │   │   |
    * ├───┼───┤  ├────┬───┴┬──┴─┬─┴───┴──┬┴───┤   ├───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
    * |   |   |  │    |    │    │        │    │   │          │   │   │   │   │   │   |
    * └───┴───┘  └────┴────┴────┴────────┴────┘   └──────────┴───┴───┴───┴───┴───┴───┘
    */
    [_L2] = LAYOUT_65_with_macro(
        RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, _______, _______, _______, TG_L4, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______, _______, _______, \
        KC_F9,   KC_F10,  _______, _______, _______, _______, _______, _______, _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, _______, _______, \
        KC_F11,  KC_F12,  _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /*
    * ┌───┬───┐  ┌───┬───┬───┬───┬───┬───┬───┐   ┌───┬───┬───┬───┬───┬───┬───┬───┬───┐
    * |_L0|   |  │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   |
    * ├───┼───┤  ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘ ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┼───┤
    * |   |   |  │     │   │   │   │   │   │   │   │   │   │   │   │   │   │     │   |
    * ├───┼───┤  ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐  └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
    * |   |   |  │      │   │   │   │   │   │   │   |   │   │   │   │   │        │   |
    * ├───┼───┤  ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐ └─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
    * |   |   |  │        │   │   │   │   │   │   │   │   │   │   │   │      │   │   |
    * ├───┼───┤  ├────┬───┴┬──┴─┬─┴───┴──┬┴───┤   ├───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
    * |   |   |  │    |    │    │ backSp │    │   │  space   │   │   │   │   │   │   |
    * └───┴───┘  └────┴────┴────┴────────┴────┘   └──────────┴───┴───┴───┴───┴───┴───┘
    */
    [_L3] = LAYOUT_65_with_macro(
        TG_L0,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, KC_BSPC, _______,          _______, KC_SPC,  _______, _______, _______, _______, _______, _______
    ),

    /*
    * ┌───┬───┐  ┌───┬───┬───┬───┬───┬───┬───┐   ┌───┬───┬───┬───┬───┬───┬───┬───┬───┐
    * |_L0|   |  │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │_L0|
    * ├───┼───┤  ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘ ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┼───┤
    * |   |   |  │     │   │   │   │   │   │   │   │   │   │   │   │   │   │     │_L0|
    * ├───┼───┤  ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐  └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
    * |   |   |  │      │   │   │   │   │   │   │   |   │   │   │   │   │        │   |
    * ├───┼───┤  ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐ └─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
    * |   |   |  │        │   │   │   │   │   │   │   │   │   │   │   │      │VAI│RGB|
    * ├───┼───┤  ├────┬───┴┬──┴─┬─┴───┴──┬┴───┤   ├───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
    * |   |   |  │    |    │    │        │    │   │          │   │   │   │HUI│MOD│SAI|
    * └───┴───┘  └────┴────┴────┴────────┴────┘   └──────────┴───┴───┴───┴───┴───┴───┘
    */
    [_RGB] = LAYOUT_65_with_macro(
        TG_L0,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TG_L0, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TG_L0, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_VAI, RGB_TOG, \
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, RGB_HUI, RGB_MOD, RGB_SAI
    )
};


// encoders
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code16(C(KC_PGDN));
        } else {
            tap_code16(C(KC_PGUP));
        }
    } else if (index == 1) {
        if (!is_alt_tab_active) {
            is_alt_tab_active = true;
            register_code(KC_LALT);
        }
        if (clockwise) {
            alt_tab_timer = timer_read();
            tap_code16(KC_TAB);
        } else {
            alt_tab_timer = timer_read();
            tap_code16(S(KC_TAB));
        }
    }
}

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 750) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}


// layer-activated RGB underglow
const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 4, 0, 255, 200}
);
const rgblight_segment_t PROGMEM layer0[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 16, 11, 176, 200}
);
const rgblight_segment_t PROGMEM layer1[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 16, 128, 255, 200}
);
const rgblight_segment_t PROGMEM layer2[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 16, 191, 255, 200}
);
const rgblight_segment_t PROGMEM layer3[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 16, 160, 255, 200}
);
const rgblight_segment_t PROGMEM layer4[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 16, 43, 255, 200}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer0,
    layer1,
    layer2,
    layer3,
    layer4,
    capslock_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(5, led_state.caps_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    // rgblight_set_layer_state(0, layer_state_cmp(state, _BASE));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _L1));
    rgblight_set_layer_state(2, layer_state_cmp(state, _L2));
    rgblight_set_layer_state(3, layer_state_cmp(state, _L3));
    // rgblight_set_layer_state(4, layer_state_cmp(state, _L4));
    return state;
}

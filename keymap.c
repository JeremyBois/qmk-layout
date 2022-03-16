#include "config.h"
#include QMK_KEYBOARD_H
#include "features/customCodes.h"
#include "g/keymap_combo.h"

#include "features/encoder.h"
#include "features/utility.h"
#include "features/swapper.h"
#include "features/switcher.h"
#include "features/leader.h"

//
// ***
// LAYOUT
// ***
//

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * QWERTY
     * ,------------------------------------------.                    ,-----------------------------------------.
     * |      |       |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+-------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |   Q   |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |      |
     * |------+-------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |   A   |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  | Bspc |      |
     * |------+-------+------+------+------+------| MUTE  |    |       |------+------+------+------+------+------|
     * |      |   Z   |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |      |
     * |      | Shift | Ctrl |  Alt |  GUI |      |       |    |       |      | Ralt | Alt  | Ctrl | Shift|      |
     * `------------------------------------------/       /     \      \-----------------------------------------'
     *          |      |     |   NAV  | NUM    | / Space /       \Enter \ |  SYM   |  DEF   |       |      |
     *          |      |     |   NAV  | NUM    |/       /         \      \|  SYM   |        |       |      |
     *          `------------------------------'-------'           '------'--------------------------------'
     */
    [_DEFAULT] = LAYOUT(
      XXXXXXX,  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                  KC_6,    KC_7,    KC_8,   KC_9,   KC_0,      XXXXXXX,
      XXXXXXX,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                  KC_Y,    KC_U,    KC_I,   KC_O,   KC_P,      XXXXXXX,
      XXXXXXX,  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                  KC_H,    KC_J,    KC_K,   KC_L,   KC_BSPC,   XXXXXXX,
XXXXXXX, LSFT_T(KC_Z), LCTL_T(KC_X), LALT_T(KC_C), LGUI_T(KC_V), KC_B, KC_MUTE,
                                    XXXXXXX, KC_N, RALT_T(KC_M), LALT_T(KC_COMM), RCTL_T(KC_DOT), RSFT_T(KC_SLSH), XXXXXXX,
                    XXXXXXX, XXXXXXX, MHL_NAV, OSL_NUM, KC_SPC,
                                                        KC_ENT, OSL_SYM, TO(_DEFAULT), XXXXXXX, XXXXXXX
    ),

    /*
     * COLEMAK (TODO)
     * ,------------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |       |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+-------|                    |------+------+------+------+------+------|
     * |      |   Q  |   W  |   F  |   P  |   G   |                    |   J  |   L  |   U  |   Y  | Bspc |      |
     * |------+------+------+------+------+-------|                    |------+------+------+------+------+------|
     * |      |   A  |   R  |   S  |   T  |   D   |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |      |
     * |------+------+------+------+------+-------|  MUTE |    |       |------+------+------+------+------+------|
     * |      |   Z  |   X  |   C  |   V  |   B   |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |      |
     * |      | Ctrl | Shift|  Alt |  Gui |       |       |    |       |      | Ralt | Alt  | Shift| Ctrl |      |
     * `------------------------------------------/       /     \      \-----------------------------------------'
     *          |      |     |   NAV  | NUM    | / Space /       \Enter \ |  SYM   |  DEF   |       |      |
     *          |      |     |   NAV  | NUM    |/       /         \      \|  SYM   |        |       |      |
     *          `------------------------------'-------'           '------'--------------------------------'
     */
    [_COLEMAK] = LAYOUT(
      _______,  _______, _______, _______, _______,  _______,        _______, _______, _______, _______, _______, _______,
      _______,   KC_Q,      KC_W,    KC_F,    KC_P,     KC_G,           KC_J,    KC_L,    KC_U,    KC_Y, KC_BSPC, _______,
      _______,   KC_A,      KC_R,    KC_S,    KC_T,     KC_D,           KC_H,    KC_N,    KC_E,    KC_I,    KC_O, _______,
XXXXXXX, LSFT_T(KC_Z), LCTL_T(KC_X), LALT_T(KC_C), LGUI_T(KC_V), KC_B, KC_MUTE,
                                     XXXXXXX, KC_K, RALT_T(KC_M), LALT_T(KC_COMM), RCTL_T(KC_DOT), RSFT_T(KC_SLSH), XXXXXXX,
                    _______, _______, _______, _______, _______,
                                                        _______, _______, _______, _______, _______
    ),

    /* NAV
     * ,------------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |       |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+-------+------|                    |------+------+------+------+------+------|
     * |      | CTab | WH_L |  MU  | WH_R  | WH_U |                    | PgUp | Home |  Up  | End  | Bspc |      |
     * |------+------+------+------+-------+------|                    |------+------+------+------+------+------|
     * |      | ATab |  ML  |  MD  |  MR   | WH_D |-------.    ,-------| PgDo | Left | Down | Right| Bspc |      |
     * |------+------+------+------+-------+------|  MUTE |    |       |------+------+------+------+------+------|
     * |      | Undo | Cut  | Copy | Paste |LDesk |-------|    |-------|RDesk | MB1  | MB2  | MB3  | Com  |      |
     * |      | Shift| Ctrl |  Alt |  Gui  |      |       |    |       |      |      |      | Ctrl | Shift|      |
     * `------------------------------------------/       /     \      \-----------------------------------------'
     *          |      |     |   NAV  | NUM    | / Space /       \Enter \ |  SYM   |  DEF   |       |      |
     *          |      |     |   NAV  | NUM    |/       /         \      \|  SYM   |        |       |      |
     *          `------------------------------'-------'           '------'--------------------------------'
     */
    [_NAV] = LAYOUT(
      _______, _______,  _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______,
      _______, SW_CTAB,  KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U,              KC_PGUP, KC_HOME, KC_UP,    KC_END,  KC_BSPC, _______,
      _______, SW_ATAB,  KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,              KC_PGDN, KC_LEFT, KC_DOWN,  KC_RGHT, KC_BSPC, _______,
 _______, LSFT_T(C_Z), LCTL_T(C_X), LALT_T(C_C), LGUI_T(C_V), C(A(KC_LEFT)), _______,
                                                       _______, C(A(KC_RIGHT)), KC_BTN1, KC_BTN2, RCTL_T(KC_BTN3), RSFT_T(C_SLSH), _______,
                    _______, _______, _______, _______, _______,
                                                        _______, _______, _______, _______, _______
    ),

    /* NUM
     * ,------------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |       |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+-------|                    |------+------+------+------+------+------|
     * |      |  F10 |  F1  |  F2  |  F3  |  F4   |                    |  F5  |  F6  |  F7  |  F8  |  F9  |      |
     * |------+------+------+------+------+-------|                    |------+------+------+------+------+------|
     * |      |  0   |   1  |   2  |   3  |   4   |-------.    ,-------|   5  |   6  |   7  |   8  |  9   |      |
     * |------+------+------+------+------+-------|  MUTE |    |       |------+------+------+------+------+------|
     * |      | Undo | Cut  | Copy |Paste |       |-------|    |-------|  F11 |  F12 |  ,   |  .   |  /   |      |
     * |      | Shift| Ctrl |  Alt |  Gui |       |       |    |       |      |      | Alt  | Ctrl | Shift|      |
     * `------------------------------------------/       /     \      \-----------------------------------------'
     *          |      |     |   NAV  | NUM    | / Space /       \Enter \ |  SYM   |  DEF   |       |      |
     *          |      |     |   NAV  | NUM    |/       /         \      \|  SYM   |        |       |      |
     *          `------------------------------'-------'           '------'--------------------------------'
     */
    [_NUM] = LAYOUT(
      _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,  _______,
      _______,  KC_F10,   KC_F1,   KC_F2,  KC_F3,    KC_F4,        KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  _______,
      _______,    KC_0,    KC_1,    KC_2,   KC_3,     KC_4,         KC_5,    KC_6,    KC_7,    KC_8,    KC_9,  _______,
_______, LSFT_T(C_Z), LCTL_T(C_X), LALT_T(C_C), LGUI_T(C_V), XXXXXXX, _______,
                                             _______, KC_F11, KC_F12, LALT_T(KC_COMM), RCTL_T(KC_DOT), RSFT_T(KC_SLSH), _______,
                    _______, _______, _______, _______, _______,
                                                        _______, _______, _______, _______, _______
    ),

    /* SYM
     * ,------------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |       |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+-------|                    |------+------+------+------+------+------|
     * |      |  `   |  @   |  #   |  $   |   %   |                    |  ^   |   &  |  *   |   !  |ADJUST|      |
     * |------+------+------+------+------+-------|                    |------+------+------+------+------+------|
     * |      |  |   |  -   |  +   |  '   |   <   |-------.    ,-------|  [   |  {   |  (   |   ;  |   :  |      |
     * |------+------+------+------+------+-------|  MUTE |    |       |------+------+------+------+------+------|
     * |      |  ~   |  _   |  =   |  "   |   >   |-------|    |-------|  ]   |  }   |  )   |   ?  |   \  |      |
     * `------------------------------------------/       /     \      \-----------------------------------------'
     *          |      |     |   NAV  | NUM    | / Space /       \Enter \ |  SYM   |  DEF   |       |      |
     *          |      |     |   NAV  | NUM    |/       /         \      \|  SYM   |        |       |      |
     *          `------------------------------'-------'           '------'--------------------------------'
     */
    [_SYM] = LAYOUT(
      _______, _______, _______, _______, _______, _______,               _______,  _______,  _______,  _______,  _______, _______,
      _______, C_GRV,   KC_AT,   KC_HASH, KC_DLR,  KC_PERC,               KC_CIRC, KC_AMPR, KC_ASTR, KC_EXLM, TO(_ADJUST), _______,
      _______, KC_PIPE,  KC_MINS, KC_PLUS, C_QUOT, KC_LT,                KC_LBRC, KC_LCBR, KC_LPRN, KC_SCLN, KC_COLN, _______,
      _______, C_TILD,  KC_UNDS, KC_EQL,  C_DQUOT, KC_GT, _______,   _______, KC_RBRC, KC_RCBR, KC_RPRN, KC_QUES,  KC_BSLS, _______,
                    _______, _______, _______, _______, _______,
                                                        _______, _______, _______, _______, _______
    ),

    /* ADJUST
     * ,---------------------------------------------.                    ,-----------------------------------------.
     * |       |      |      |       |       |       |                    |      |      |      |      |      |      |
     * |-------+------+------+-------+-------+-------|                    |------+------+------+------+------+------|
     * |       |RGB_MO |hue ^ |sat ^ | bri ^ |  BRIU |                    | VOLU | MRWD | STOP | MFFD |RESET |      |
     * |-------|-------+------+------+-------+-------+                    |------+------+------+------+------------+|
     * |       |RGB_TO |huedn |satdn |bridn  |  BRID |-------.    ,-------| VOLD | PREV | PLAY | NEXT |EEPRST|      |
     * |-------+------+------+-------+-------+-------|  MUTE |    |       |------+------+------+------+------------+|
     * |       |      |      |       |QWERTY |COLEMAK|-------|    |-------| PSCR |      |      |      |DEBUG |      |
     * `--------------------------------------------/       /      \      \-----------------------------------------'
     *          |      |      |      |           | /       /        \      \  |        | DEF  |       |      |
     *          |      |      |      |           |/       /          \      \ |        |      |       |      |
     *          `----------------------------------------'            '------''------------------------------'
     */
      [_ADJUST] = LAYOUT(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                  XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, KC_BRIU,                  KC_VOLU, KC_MRWD, KC_MEDIA_STOP, KC_MFFD,   RESET, XXXXXXX,
      XXXXXXX, RGB_TOG, RGB_HUD, RGB_SAD, RGB_VAD, KC_BRID,                  KC_VOLD, KC_MPRV,       KC_MPLY, KC_MNXT, EEP_RST, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(_DEFAULT), DF(_COLEMAK),_______,      _______, KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DEBUG,
                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                        XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX
    )
    };


//
// ***
// RGB LED
// ***
//

#define INDICATOR_BRIGHTNESS 15


#ifdef RGBLIGHT_LAYERS
#    define HSV_RED_LAYER    11, 176, 80
#    define HSV_TURQUOISE_LAYER  123,  90, 65
#    define HSV_GREEN_LAYER  85, 255, 75
#    define HSV_BLUE_LAYER   170, 255, 65
#    define HSV_GREEN_INDICATOR  85, 255, 20
#    define HSV_ORANGE_INDICATOR 28, 255, 20
#    define HSV_WHITE_INDICATOR  0, 0, 10

    // Layers
    // Light LEDs 6 to 9 and 12 to 15 red when caps lock is active.
    const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS({1, 6,  HSV_RED_LAYER},  // Under-glow
                                                                                   {7, 1 , HSV_RED_LAYER},
                                                                                   {16, 2, HSV_RED_LAYER},
                                                                                   {26, 2, HSV_RED_LAYER}  // Bottom row
    );

    // Indicator is orange        || QWERTY
    const rgblight_segment_t PROGMEM qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_ORANGE_INDICATOR});

    // Indicator is white         || COLEMAK
    const rgblight_segment_t PROGMEM colemak_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_WHITE_INDICATOR});

    // Left columns are green     || NAVIGATION
    const rgblight_segment_t PROGMEM navigation_layer[] = RGBLIGHT_LAYER_SEGMENTS({8, 8, HSV_GREEN_LAYER});

    // Middle columns are turquoise || NUMPAD
    const rgblight_segment_t PROGMEM numpad_layer[] = RGBLIGHT_LAYER_SEGMENTS({18, 8, HSV_TURQUOISE_LAYER});

    // Middle columns are blue    ||  SYM
     const rgblight_segment_t PROGMEM symbol_layer[] = RGBLIGHT_LAYER_SEGMENTS({18, 8, HSV_BLUE_LAYER});

    // Light LEDs 6 to 9 and 12 to 15 white  || ADJUST
    const rgblight_segment_t PROGMEM adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS({1, 6,  HSV_TURQUOISE_LAYER}, // Under-glow
                                                                              {7, 1 , HSV_TURQUOISE_LAYER},
                                                                              {16, 2, HSV_TURQUOISE_LAYER},
                                                                              {26, 2, HSV_TURQUOISE_LAYER}  // Bottom row
    );

    // Now define the array of layers. Later layers take precedence
    const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
        my_capslock_layer,
        qwerty_layer,
        colemak_layer,     // Overrides other layers
        navigation_layer,  // Overrides other layers
        numpad_layer,      // Overrides other layers
        symbol_layer,      // Overrides other layers
        adjust_layer       // Overrides other layers
    );

    void keyboard_post_init_user(void) {
        // Enable the LED layers
        rgblight_layers = my_rgb_layers;
    }

    bool led_update_user(led_t led_state) {
        rgblight_set_layer_state(0, led_state.caps_lock);
        return true;
    }

    layer_state_t default_layer_state_set_user(layer_state_t state) {
        // Allow to switch between different layout
        rgblight_set_layer_state(1, layer_state_cmp(state, _DEFAULT));
        rgblight_set_layer_state(2, layer_state_cmp(state, _COLEMAK));
        return state;
    }

    layer_state_t layer_state_set_user(layer_state_t state) {
        // Allow to switch between different additional layout
        rgblight_set_layer_state(3, layer_state_cmp(state, _NAV));
        rgblight_set_layer_state(4, layer_state_cmp(state, _NUM));
        rgblight_set_layer_state(5, layer_state_cmp(state, _SYM));
        rgblight_set_layer_state(6, layer_state_cmp(state, _ADJUST));
        return state;
    }

#endif
// clang-format on

//
// ***
// COMBOS
// ***
//
/*
 * ,------------------------------------------.                    ,-----------------------------------------.
 * |  x   |   x   |  x   |  x   |  x   |  x   |                    |  x   |  x   |  x   |  x   |  x   |   x  |
 * |------+-------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  x   |      CAPS    |     ESC     |      |                    |      |     ESC     |  LAUNCHER   |   x  |
 * |------+-------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  x   |       |     TAB   LEADER   |      |-------.    ,-------|      |    BACK    DEL     |      |   x  |
 * |------+-------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |  x   |       |      |      |      |      |-------|    |-------|      |      |      |      |      |   x  |
 * `------------------------------------------/       /     \      \-----------------------------------------'
 *          |     |      |       |         | /       /       \      \ |        |        |       |      |
 *          |     |      |       |         |/       /         \      \|        |        |       |      |
 *          `------------------------------'-------'           '------'--------------------------------'
 */

uint16_t get_combo_term(uint16_t index, combo_t* combo) {
    switch (index) {
        // Home / Tight combos
        case tab:
        case leader:
        case back:
        case del:
            return COMBO_TERM;
        // Top (should be quick enough to avoid impacting normal typing)
        case escape_l:
        case escape_r:
            return COMBO_TERM - 20;
        default:
            return COMBO_TERM;
    }
}

bool get_combo_must_tap(uint16_t index, combo_t* combo) {
    switch (index) {
        case escape_l:
        case escape_r:
        case caps:
        case launcher:
        case back:
        case del:
        case tab:
        case leader:
            return false;
        default:
            return true;
    }
}

//
// ***
// TAP HOLD
// ***
//

//
// ***
// CUSTOM KEYCODE HANDLING
// ***
//

// Custom swappers
bool sw_ctab_active     = false;
bool sw_atab_active     = false;
bool old_sw_ctab_active = false;
bool old_sw_atab_active = false;

// Custom layer switchers
oneshot_state osl_symbol_state = os_up_unqueued;
oneshot_state osl_numpad_state = os_up_unqueued;
oneshot_state mhl_nav_state    = os_up_unqueued;

bool is_oneshot_cancel_key(uint16_t keycode) {
    // Escape and moved layer
    switch (keycode) {
        case TO(_DEFAULT):
        case KC_ESC:
        case C_CHORD:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_layer_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case TO(_DEFAULT):
        case MHL_NAV:
        case OSL_SYM:
        case OSL_NUM:
        case KC_ESC:
        case C_CHORD:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case TO(_DEFAULT):
        case MHL_NAV:
        case OSL_SYM:
        case OSL_NUM:
        // Allow modifier on one shot layer
        case LSFT_T(C_Z):
        case LCTL_T(C_X):
        case LALT_T(C_C):
        case LGUI_T(C_V):
        case LALT_T(KC_COMM):
        case RCTL_T(KC_DOT):
        case RSFT_T(KC_SLSH):
        case KC_LCTL:
        case KC_RCTL:
        case KC_LALT:
        case KC_RALT:
        case KC_LGUI:
        case KC_LSFT:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_mod_key(uint16_t keycode) {
    switch (keycode) {
        // Could be useful to add support for sticky modifiers
        // on a one shot layer --> Register modifier then exit the layer
        default:
            return false;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    // Process leader key sequences (no timer)
    if (!process_leader(keycode, record)) {
        return false;
    }

    // Swapper on one key (no timer)
    update_swapper(&sw_ctab_active, &old_sw_ctab_active, KC_LCTL, KC_TAB, SW_CTAB, keycode, record);
    update_swapper(&sw_atab_active, &old_sw_atab_active, KC_LALT, KC_TAB, SW_ATAB, keycode, record);

    // Custom layer change (no timer)
    bool notHandled = update_oneshot_layer(&osl_symbol_state, _SYM, OSL_SYM, keycode, record);
    notHandled      = update_oneshot_layer(&osl_numpad_state, _NUM, OSL_NUM, keycode, record);
    notHandled      = update_move_hold_layer(&mhl_nav_state, _NAV, MHL_NAV, keycode, record);

    if (!notHandled) {
        return false;
    }

    // Discard keys used to end a swapper
    if ((!sw_atab_active && old_sw_atab_active) || (!sw_ctab_active && old_sw_ctab_active)) {
        return false;
    }

    // Custom keycodes
    switch (keycode) {
        case C_CHORD:
            if (record->event.pressed) {
                start_leading();
            }
            return false;
        // https://docs.qmk.fm/#/mod_tap?id=intercepting-mod-taps
        // Intercept to send key with modifier on tap
        case LSFT_T(C_Z):
            if (record->tap.count && record->event.pressed) {
                tap_code16(C(KC_Z)); // Send C(KC_Z) on tap
                return false;
            }
            break;
        case LCTL_T(C_X):
            if (record->tap.count && record->event.pressed) {
                tap_code16(C(KC_X)); // Send C(KC_X) on tap
                return false;
            }
            break;
        case LALT_T(C_C):
            if (record->tap.count && record->event.pressed) {
                tap_code16(C(KC_C)); // Send C(KC_C) on tap
                return false;
            }
            break;
        case LGUI_T(C_V):
            if (record->tap.count && record->event.pressed) {
                tap_code16(C(KC_V)); // Send C(KC_V) on tap
                return false;
            }
            break;
        case RSFT_T(C_SLSH):
            if (record->tap.count && record->event.pressed) {
                tap_code16(C(KC_SLSH)); // Send C(KC_SLSH) on tap
                return false;
            }
            break;
        case C_GRV:
            if (record->event.pressed) {
                // Handle dead key to print ` or ~
                tap_undead_key(KC_GRV);
                return false;
            }
            break;
        case C_TILD:
            if (record->event.pressed) {
                // Handle dead key to print ~
                tap_undead_key(S(KC_GRV));
                return false;
            }
            break;
        case C_QUOT:
            if (record->event.pressed) {
                // Handle dead key to print ' or "
                tap_undead_key(KC_QUOT);
                return false;
            }
            break;
        case C_DQUOT:
            if (record->event.pressed) {
                // Handle dead key to print "
                tap_undead_key(KC_DQUO);
                return false;
            }
            break;
    }

    // Return false to ignore further processing of key
    // Return true to let qmk handles it
    return true;
};

//
// Leader
//
void* leader_start_func(uint16_t keycode) {
    switch (keycode) {
        case KC_T: // Colemak
        case KC_F: // Qwerty
            // é
            tap_code16(ALGR(KC_E));
            break;
        case KC_E:
            // è
            tap_key_with_mods(KC_GRV, 0U);
            tap_code16(KC_E);
            break;
        case KC_U:
            // ù
            tap_key_with_mods(KC_GRV, 0U);
            tap_code16(KC_U);
            break;
        case KC_A:
            // à
            tap_key_with_mods(KC_GRV, 0U);
            tap_code16(KC_A);
            break;
        case KC_P: // Colemak
        case KC_R: // Qwerty
            // ë
            tap_code16(S(KC_QUOT));
            tap_code16(KC_E);
            break;
        case KC_Y:
            // ÿ
            tap_code16(S(KC_QUOT));
            tap_code16(KC_Y);
            break;
        case KC_C:
            // ç
            tap_code16(ALGR(KC_COMM));
            break;
        default:
            return NULL;
    }

    return NULL;
}

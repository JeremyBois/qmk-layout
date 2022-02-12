#include QMK_KEYBOARD_H

#include "features/encoder.h"
#include "features/utility.h"
#include "features/swapper.h"
#include "features/switcher.h"
#include "features/leader.h"

//
// ***
// CUSTOM KEYCODE HANDLING
// ***
//

#ifdef VIA_ENABLE
enum custom_keycodes {
    C_GRV = USER00,
    C_TILD,
    C_QUOT,
    C_DQUOT,
    C_CHORD,
    SW_CTAB,  // Ctrl-tab
    SW_ATAB,  // Alt-tab
    OSL_SYM,  // One shot layer without timer
    OSL_NUM,  //
    MHL_NAV,  // Move hold layer without timer
    MHL_NUM,  //
    OS_LALT,  // One shot mod without timers
    OS_LCTL,
    OS_RCTL
}
#else
enum custom_keycodes {
    C_GRV = SAFE_RANGE,
    C_TILD,
    C_QUOT,
    C_DQUOT,
    C_CHORD,
    SW_CTAB,  // Ctrl-tab
    SW_ATAB,  // Alt-tab
    OSL_SYM,  // One shot layer without timer
    OSL_NUM,  //
    MHL_NAV,  // Move hold layer without timer
    MHL_NUM,  //
    OS_LALT,  // One shot mod without timers
    OS_LCTL,
    OS_RCTL
};
#endif

//
// ***
// LAYOUT
// ***
//

enum custom_layers {
    _QWERTY = 0,
    _GAME,
    _COLEMAK,
    _NAV,
    _NUM,
    _SYM,
    _ADJUST
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * QWERTY
     * ,------------------------------------------.                    ,-----------------------------------------.
     * | ESC  |   1   |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | DEL  |
     * |------+-------+------+------+------+------|                    |------+------+------+------+------+------|
     * | ESC  |   Q   |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | DEL  |
     * |------+-------+------+------+------+------|                    |------+------+------+------+------+------|
     * | TAB  |   A   |   S  |  D   |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  | BSPC |
     * |------+-------+------+------+------+------| MUTE  |    |       |------+------+------+------+------+------|
     * | CTRL |   Z   |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | RCTR |
     * `------------------------------------------/       /     \      \-----------------------------------------'
     *          | LGUI | NAV  | LALT | DEFAULT | /Space  /       \Enter \  |  SYM   | LCTR |  NUM  |  RALT|
     *          |      |      |      |         |/       /         \      \ |        |      |       |      |
     *          `--------------------------------------'           '------''------------------------------'
     */
    [_QWERTY] = LAYOUT(
      KC_ESC,   KC_1, KC_2, KC_3, KC_4, KC_5,                  KC_6,  KC_7,  KC_8, KC_9, KC_0,    KC_DEL,
      KC_ESC,   KC_Q, KC_W, KC_E, KC_R, KC_T,                  KC_Y,  KC_U,  KC_I, KC_O, KC_P,    KC_DEL,
      KC_TAB,   KC_A, KC_S, KC_D, KC_F, KC_G,                  KC_H,  KC_J,  KC_K, KC_L, KC_SCLN, KC_BSPC,
      KC_LCTL,  KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE,     XXXXXXX, KC_N, KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RCTL,
               KC_LGUI, MHL_NAV, OS_LALT, TO(0), MT(MOD_LSFT, KC_SPC),
                                                        MT(MOD_LSFT, KC_ENT),  OSL_SYM, OS_LCTL, MHL_NUM, KC_RALT
    ),

    /*
     * QWERTY GAME
     * ,------------------------------------------.                    ,-----------------------------------------.
     * | ESC  |   1   |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | DEL  |
     * |------+-------+------+------+------+------|                    |------+------+------+------+------+------|
     * | ESC  |   Q   |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | DEL  |
     * |------+-------+------+------+------+------|                    |------+------+------+------+------+------|
     * | TAB  |   A   |   S  |  D   |  F   |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  | BSPC |
     * |------+-------+------+------+------+------| MUTE  |    |       |------+------+------+------+------+------|
     * | CTRL |   Z   |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | RCTR |
     * `------------------------------------------/       /     \      \-----------------------------------------'
     *          | LGUI | NAV  | LALT | DEFAULT | /Space  /       \Enter \  |  SYM   | LCTR |  NUM  |  RALT|
     *          |      |      |      |         |/       /         \      \ |        |      |       |      |
     *          `--------------------------------------'           '------''------------------------------'
     */
    [_GAME] = LAYOUT(
      _______, KC_1,  KC_2,  KC_3,  KC_4, KC_5,                       KC_6,   KC_7,   KC_8,   KC_9,   KC_0,    _______,
      _______, KC_Q,  KC_W,  KC_E,  KC_R, KC_T,                       KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,    _______,
      _______, KC_A,  KC_S,  KC_D,  KC_F, KC_G,                       KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN, _______,
      _______, KC_Z,  KC_X,  KC_C,  KC_V, KC_B, KC_MUTE,     XXXXXXX, KC_N, KC_M, KC_COMM,  KC_DOT, KC_SLSH, _______,
                _______, _______, _______, _______, _______,
                                                        _______, _______, _______, _______, _______
    ),

    /*
     * COLEMAK
     * ,------------------------------------------.                    ,-----------------------------------------.
     * | ESC  |   1  |   2  |   3  |   4  |   5   |                    |   6  |   7  |   8  |   9  |   0  | DEL  |
     * |------+------+------+------+------+-------|                    |------+------+------+------+------+------|
     * | ESC  |   Q  |   W  |   F  |   P  |   G   |                    |   J  |   L  |   U  |   Y  |   ;  | DEL  |
     * |------+------+------+------+------+-------|                    |------+------+------+------+------+------|
     * | TAB  |   A  |   R  |   S  |   T  |   D   |-------.    ,-------|   H  |   N  |   E  |   I  |   O  | BSPC |
     * |------+------+------+------+------+-------|  MUTE |    |       |------+------+------+------+------+------|
     * | CTRL |   Z  |   X  |   C  |   V  |   B   |-------|    |-------|   K  |   M  |   ,  |   .  |   /  | RCTR |
     * `------------------------------------------/      /      \      \-----------------------------------------'
     *          | LGUI | NAV  | LALT | DEFAULT | /Space /        \Enter \  |  SYM   | LCTR |  NUM  |  RALT|
     *          |      |      |      |         |/      /          \      \ |        |      |       |      |
     *          `-------------------------------------'            '------''------------------------------'
     */
    [_COLEMAK] = LAYOUT(
      _______,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                  KC_6,  KC_7, KC_8, KC_9, KC_0,  _______,
      _______,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                  KC_J,  KC_L, KC_U, KC_Y, KC_SCLN,  _______,
      _______,   KC_A,   KC_R,    KC_S,    KC_T,    KC_D,                  KC_H,  KC_N, KC_E, KC_I, KC_O,  _______,
      _______,  KC_Z,   KC_X, KC_C, KC_V, KC_B, KC_MUTE,      XXXXXXX, KC_K,  KC_M, KC_COMM,  KC_DOT, KC_SLSH, _______,
                _______, _______, _______, _______, _______,
                                                        _______, _______, _______, _______, _______
    ),

    /* NAV
     * ,------------------------------------------.                    ,-----------------------------------------.
     * | ESC  |  A1  |  A2  |  A3  |  A4   |      |                    |      |      |      |      |      | DEL  |
     * |------+------+------+------+-------+------|                    |------+------+------+------+------+------|
     * | ESC  |      | WH_L |  MU  | WH_R  | WH_U |                    | PgUp | Home |  Up  | End  | MB4  | DEL  |
     * |------+------+------+------+-------+------|                    |------+------+------+------+------+------|
     * | TAB  |      |  ML  |  MD  |  MR   | WH_D |-------.    ,-------| PgDo | Left | Down | Right| MB5  | BSPC |
     * |------+------+------+------+-------+------|  MUTE |    |       |------+------+------+------+------+------|
     * | LCTR | Undo | Cut  | Copy | Paste | Undo |-------|    |-------| ATab | MB1  | MB2  | CTab | Com  | RCTR |
     * `------------------------------------------/      /      \      \-----------------------------------------'
     *          | LGUI | NAV  | LALT | DEFAULT | /Space /        \Enter \  |  SYM   | LCTR |  NUM  |  RALT|
     *          |      |      |      |         |/      /          \      \ |        |      |       |      |
     *          `-------------------------------------'            '------''------------------------------'
     */
    [_NAV] = LAYOUT(
      _______, A(KC_1),  A(KC_2), A(KC_3), A(KC_4), XXXXXXX,              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
      _______, XXXXXXX,  KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U,              KC_PGUP, KC_HOME, KC_UP,    KC_END,  KC_BTN4, _______,
      _______, XXXXXXX,  KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,              KC_PGDN, KC_LEFT, KC_DOWN,  KC_RGHT, KC_BTN5, _______,
      _______, C(KC_Z),  C(KC_X), C(KC_C), C(KC_V), C(KC_Y), _______,  _______, SW_ATAB, KC_BTN1, KC_BTN2, SW_CTAB, C(KC_SLSH), _______,
                _______, _______, _______, _______, _______,
                                                        _______, _______, _______, _______, _______
    ),

    /* NUM
     * ,------------------------------------------.                    ,-----------------------------------------.
     * | F11  |  F1  |  F2  |  F3  |  F4  |  F5   |                    |  F6  |  F7  |  F8  | F9   | F10  | F12  |
     * |------+------+------+------+------+-------|                    |------+------+------+------+------+------|
     * | ESC  |      |   4  |   5  |   6  |  F11  |                    |  F11 |  F4  |  F5  |  F6  |      | DEL  |
     * |------+------+------+------+------+-------|                    |------+------+------+------+------+------|
     * | TAB  |  0   |   1  |   2  |   3  |  F10  |-------.    ,-------|  F10 |  F1  |  F2  |  F3  |      | BSPC |
     * |------+------+------+------+------+-------|  MUTE |    |       |------+------+------+------+------+------|
     * | LCTR |      |   7  |   8  |   9  |  F12  |-------|    |-------|  F12 |  F7  |  F8  |  F9  |      | NUML |
     * `------------------------------------------/      /      \      \-----------------------------------------'
     *          | LGUI | NAV  | LALT | DEFAULT | /Space /        \Enter \  |  SYM   | LCTR |  NUM  | RALT |
     *          |      |      |      |         |/      /          \      \ |        |      |       |      |
     *          `-------------------------------------'            '- ----''------------------------------'
     */
    [_NUM] = LAYOUT(
      KC_F11,  KC_F1,   KC_F2, KC_F3,  KC_F4, KC_F5,               KC_F6,   KC_F7,  KC_F8,  KC_F9,  KC_F10,  KC_F12,
      _______, KC_PAST, KC_P4, KC_P5,  KC_P6, KC_F11,              KC_F11,  KC_F4,  KC_F5,  KC_F6,  XXXXXXX, _______,
      _______, KC_P0,   KC_P1, KC_P2,  KC_P3, KC_F10,              KC_F10,  KC_F1,  KC_F2,  KC_F3,  XXXXXXX, _______,
      _______, KC_PSLS, KC_P7, KC_P8,  KC_P9, KC_F12, _______,   _______, KC_F12, KC_F7, KC_F8, KC_F9, XXXXXXX, KC_NUM,
                _______, _______, _______, _______, _______,
                                                        _______, _______, _______, _______, _______
    ),

    /* SYM
     * ,------------------------------------------.                    ,-----------------------------------------.
     * | F11  |  F1  |  F2  |  F3  |  F4  |  F5   |                    |  F6  |  F7  |  F8  | F9   | F10  | F12  |
     * |------+------+------+------+------+-------|                    |------+------+------+------+------+------|
     * | ESC  |  !   |  @   |  #   |  $   |   %   |                    |  ^   |   &  |  *   |  ;   |   :  | DEL  |
     * |------+------+------+------+------+-------|                    |------+------+------+------+------+------|
     * | TAB  |  `   |  -   |  +   |Chord |   '   |-------.    ,-------|  [   |  {   |  (   |  <   |   |  | BSPC |
     * |------+------+------+------+------+-------|  MUTE |    |       |------+------+------+------+------+------|
     * | CAPS |  ~   |  _   |  =   |  \   |   "   |-------|    |-------|  ]   |  }   |  )   |  >   |   ?  |ADJUST|
     * `------------------------------------------/      /      \      \-----------------------------------------'
     *          | LGUI | NAV  | LALT | DEFAULT | /BSPC  /        \DEL   \  |  SYM   | LCTR |  NUM  |  RALT|
     *          |      |      |      |         |/      /          \      \ |        |      |       |      |
     *          `-------------------------------------'            '- ----''------------------------------'
     */
    [_SYM] = LAYOUT(
      KC_F11,  KC_F1,   KC_F2,  KC_F3,   KC_F4,  KC_F5,                 KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F12,
      _______, KC_EXLM, KC_AT,  KC_HASH, KC_DLR, KC_PERC,               KC_CIRC, KC_AMPR, KC_ASTR, KC_SCLN, KC_COLN, _______,
      _______, C_GRV, KC_MINS, KC_PLUS, C_CHORD, C_QUOT,                KC_LBRC, KC_LCBR, KC_LPRN, KC_LT, KC_PIPE, _______,
      KC_CAPS, C_TILD, KC_UNDS, KC_EQL, KC_BSLS, C_DQUOT, _______,   _______, KC_RBRC, KC_RCBR, KC_RPRN, KC_GT, KC_QUES, TO(_ADJUST),
                _______, _______, _______, _______, KC_BSPC,
                                                        KC_DEL, _______, _______, _______, _______
    ),

    /* ADJUST
     * ,------------------------------------------.                     ,-----------------------------------------.
     * |RESET  | DEBUG|      |QWERTY|_GAME |COLEMAK|                    |      |      |      |      |      |      |
     * |-------+------+------+------+------+-------|                    |------+------+------+------+------+------|
     * |EEPRST |      |RGB_MO|RGB_TO|      | BRIU  |                    |      | MRWD | STOP | MFFD |      |      |
     * |-------+------+------+------+------+-------|                    |------+------+------+------+------+------|
     * |       |hue^  |sat ^ | bri ^|      | BRID  |-------.    ,-------| Pscr | PREV | PLAY | NEXT |      |      |
     * |-------+------+------+------+------+-------|  MUTE |    |       |------+------+------+------+------+------|
     * |       |huedn |sat d |bri dn|      |       |-------|    |-------|      |      |      |      |      |      |
     * `------------------------------------------/       /      \      \-----------------------------------------'
     *          | LGUI | NAV  | LALT | DEFAULT | /       /        \      \  |  SYM   | LCTR |  NUM  |  RALT|
     *          |      |      |      |         |/       /          \      \ |        |      |       |      |
     *          `--------------------------------------'            '------''------------------------------'
     */
      [_ADJUST] = LAYOUT(
      RESET, DEBUG, XXXXXXX, DF(_QWERTY), DF(_GAME), DF(_COLEMAK),           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      EEP_RST, XXXXXXX, RGB_MOD, RGB_TOG, XXXXXXX, KC_BRIU,                  XXXXXXX, KC_MRWD, KC_MEDIA_STOP, KC_MFFD, XXXXXXX, XXXXXXX,
      XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, KC_BRID,                  KC_PSCR, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
      XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,_______,      _______, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                    _______, XXXXXXX, _______, _______, XXXXXXX,
                                                        XXXXXXX, XXXXXXX, _______, _______, _______
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

    // Indicator is green         || GAME
    const rgblight_segment_t PROGMEM game_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_GREEN_INDICATOR});

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
        game_layer,
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
        rgblight_set_layer_state(1, layer_state_cmp(state, _QWERTY));
        rgblight_set_layer_state(2, layer_state_cmp(state, _GAME));
        rgblight_set_layer_state(3, layer_state_cmp(state, _COLEMAK));
        return state;
    }

    layer_state_t layer_state_set_user(layer_state_t state) {
        // Allow to switch between different additional layout
        rgblight_set_layer_state(4, layer_state_cmp(state, _NAV));
        rgblight_set_layer_state(5, layer_state_cmp(state, _NUM));
        rgblight_set_layer_state(6, layer_state_cmp(state, _SYM));
        rgblight_set_layer_state(7, layer_state_cmp(state, _ADJUST));
        return state;
    }

#endif
// clang-format on

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

// Custom one shot modifiers
oneshot_state os_lctl_state = os_up_unqueued;
oneshot_state os_rctl_state = os_up_unqueued;
oneshot_state os_lalt_state = os_up_unqueued;
oneshot_state os_lsft_state = os_up_unqueued;

// Custom layer switchers
oneshot_state osl_symbol_state = os_up_unqueued;
// oneshot_state  osl_numpad_state = os_up_unqueued;
movehold_state mhl_nav_state    = mh_cleared;
movehold_state mhl_numpad_state = mh_cleared;

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case TO(0):
        case MHL_NAV:
        case MHL_NUM:
        case KC_ESC:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case MHL_NAV:
        case MHL_NUM:
        case OSL_SYM:
        case OSL_NUM:
        case KC_LCTL:
        case KC_LALT:
        case KC_LSFT:
        case OS_LALT:
        case OS_LCTL:
        case OS_RCTL:
            return true;
        default:
            return false;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    // Process leader key sequences
    if (!process_leader(keycode, record)) {
        return false;
    }

    // Swapper on one key (no timer)
    update_swapper(&sw_ctab_active, &old_sw_ctab_active, KC_LCTL, KC_TAB, SW_CTAB, keycode, record);
    update_swapper(&sw_atab_active, &old_sw_atab_active, KC_LALT, KC_TAB, SW_ATAB, keycode, record);

    // Custom layer change (no timer)
    update_move_hold_layer(&mhl_nav_state, _NAV, MHL_NAV, keycode, record);
    update_move_hold_layer(&mhl_numpad_state, _NUM, MHL_NUM, keycode, record);

    // Custom one shot layer (no timer)
    update_oneshot_layer(&osl_symbol_state, _SYM, OSL_SYM, keycode, record);
    // update_oneshot_layer(&osl_numpad_state, _NUM, OSL_NUM, keycode, record);

    // Custom one shot modifiers (no timer)
    update_oneshot(&os_lalt_state, KC_LALT, OS_LALT, keycode, record);
    update_oneshot(&os_lctl_state, KC_LCTL, OS_LCTL, keycode, record);
    update_oneshot(&os_rctl_state, KC_RCTL, OS_RCTL, keycode, record);

    // Discard key used to end a swapper
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
        case C_GRV:
            if (record->event.pressed) {
                // Handle dead key to print ` or ~
                tap_code16(KC_GRV);
                tap_code16(KC_SPC);
                return false;
            }
            break;
        case C_TILD:
            if (record->event.pressed) {
                // Handle dead key to print ~
                tap_code16(S(KC_GRV));
                tap_code16(KC_SPC);
                return false;
            }
            break;
        case C_QUOT:
            if (record->event.pressed) {
                // Handle dead key to print ' or "
                tap_code16(KC_QUOT);
                tap_code16(KC_SPC);
                return false;
            }
            break;
        case C_DQUOT:
            if (record->event.pressed) {
                // Handle dead key to print "
                tap_code16(KC_DQUO);
                tap_code16(KC_SPC);
                return false;
            }
            break;
    }
    return true;
};

//
// Leader
//
void* leader_start_func(uint16_t keycode) {
    switch (keycode) {
        case KC_W:
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
        case KC_R:
            // ë
            tap_code16(S(KC_QUOT));
            tap_code16(KC_E);
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

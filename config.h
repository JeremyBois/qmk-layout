#pragma once

//
// Optimization
// https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/
//

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
// */
#define MASTER_LEFT
// #define MASTER_RIGHT

// Encoder resolution on both sides
// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_encoders.md
#define ENCODER_RESOLUTIONS \
    { 4, 2 }

// Handle RGB
#ifdef RGBLIGHT_ENABLE
#    define RGB_DI_PIN D3
#    define RGBLED_NUM 72
#    define RGBLED_SPLIT \
        { 36, 36 }

#    define RGBLIGHT_LIMIT_VAL 130  // Limit to avoid controller to crash
#    define RGBLIGHT_HUE_STEP 20
#    define RGBLIGHT_SAT_STEP 20
#    define RGBLIGHT_VAL_STEP 20

#    define RGBLIGHT_SLEEP  // Turn off LEDs when computer sleeping (+72)

#    ifdef RGB_MATRIX_ENABLE
#        define DRIVER_LED_TOTAL RGBLED_NUM
#        define RGB_MATRIX_SPLIT RGBLED_SPLIT
#        define SPLIT_TRANSPORT_MIRROR

#        define RGB_MATRIX_MAXIMUM_BRIGHTNESS 130  // Limit to avoid controller to crash
#        define RGB_MATRIX_HUE_STEP 20
#        define RGB_MATRIX_SAT_STEP 20
#        define RGB_MATRIX_VAL_STEP 20
#        define RGB_MATRIX_SPD_STEP 20

// Save space by removing unused animations (all ^^)
#        undef ENABLE_RGB_MATRIX_ALPHAS_MODS
#        undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#        undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#        undef ENABLE_RGB_MATRIX_BREATHING
#        undef ENABLE_RGB_MATRIX_BAND_SAT
#        undef ENABLE_RGB_MATRIX_BAND_VAL
#        undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#        undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#        undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#        undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#        undef ENABLE_RGB_MATRIX_CYCLE_ALL
#        undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#        undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#        undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#        undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#        undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#        undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#        undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#        undef ENABLE_RGB_MATRIX_DUAL_BEACON
#        undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
#        undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#        undef ENABLE_RGB_MATRIX_RAINDROPS
#        undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#        undef ENABLE_RGB_MATRIX_HUE_BREATHING
#        undef ENABLE_RGB_MATRIX_HUE_PENDULUM
#        undef ENABLE_RGB_MATRIX_HUE_WAVE
#        undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#        undef ENABLE_RGB_MATRIX_PIXEL_RAIN

#        undef ENABLE_RGB_MATRIX_TYPING_HEATMAP
#        undef ENABLE_RGB_MATRIX_DIGITAL_RAIN

#        undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#        undef ENABLE_RGB_MATRIX_SOLID_REACTIVE
#        undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#        undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#        undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#        undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#        undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#        undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#        undef ENABLE_RGB_MATRIX_SPLASH
#        undef ENABLE_RGB_MATRIX_MULTISPLASH
#        undef ENABLE_RGB_MATRIX_SOLID_SPLASH
#        undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#    endif
#endif

// How many taps before triggering the toggle
#define TAPPING_TOGGLE 2
// Delay between register / unregister for a keycode
#define TAP_CODE_DELAY 10

// Control difference between a hold and a tap
#ifdef TAPPING_TERM
#    undef TAPPING_TERM
#endif
#define TAPPING_TERM 220  // Tapping duration in ms

// https://github.com/qmk/qmk_firmware/blob/master/docs/tap_hold.md#permissive-hold
// Does not work with tap dance
// #define PERMISSIVE_HOLD

// https://github.com/qmk/qmk_firmware/blob/master/docs/tap_hold.md#ignore-mod-tap-interrupt
#define IGNORE_MOD_TAP_INTERRUPT

// https://github.com/qmk/qmk_firmware/blob/master/docs/tap_hold.md#hold-on-other-key-press
// #define HOLD_ON_OTHER_KEY_PRESS

// One shot settings
#define ONESHOT_TAP_TOGGLE 10  // Sticky key activation (high to only support it in code)
#define ONESHOT_TIMEOUT 4000   // Sticky key duration

// Combo settings
#ifdef COMBO_ENABLE
#    define EXTRA_SHORT_COMBOS
#    undef COMBO_TERM
#    define COMBO_TERM 400  // Default combo timeout is 200ms.
#endif

// Leader settings
#ifdef LEADER_ENABLE
#    define LEADER_NO_TIMEOUT
#    define LEADER_TIMEOUT 400  // Default leader timeout is 200ms.
#endif

// Pimoroni trackball settings
#ifdef POINTING_DEVICE_ENABLE
// #    define PIMORONI_TRACKBALL_INTERVAL_MS 6  // Default is 8ms
// #    define PIMORONI_TRACKBALL_ROTATE         // Change according to your particular installed trackball orientation.
#    define PIMORONI_TRACKBALL_INVERT_Y
#    define PIMORONI_TRACKBALL_INVERT_X
#endif

// NKRO Settings
#ifdef NKRO_ENABLE
#    define FORCE_NKRO  // Force NKRO if enabled.
#endif

// Color for layers
#define RGBLIGHT_LAYERS
// #define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF   // Keep LED for layer even if RGB leds disabled (default is disabled)
// #define RGBLIGHT_LAYERS_RETAIN_VAL         // Keep LED defined brightness for layers (default is override)

// Limit to 8 layers to save space
#define LAYER_STATE_8BIT

// Mouse settings
// https://www.reddit.com/r/olkb/comments/72u8ou/qmk_mouse_keys_rock/
#ifdef MOUSEKEY_ENABLE
#    define MOUSEKEY_INTERVAL 16
#    define MOUSEKEY_DELAY 0
#    define MOUSEKEY_TIME_TO_MAX 80
#    define MOUSEKEY_MAX_SPEED 6
#    define MOUSEKEY_WHEEL_DELAY 0
#    define MOUSEKEY_WHEEL_MAX_SPEED 8
#    define MOUSEKEY_WHEEL_TIME_TO_MAX 40
#endif

// NOT WORKING YET
// Allow more layer on VIA software
// #define DYNAMIC_KEYMAP_LAYER_COUNT 5
// NOT WORKING YET

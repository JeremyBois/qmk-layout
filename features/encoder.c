#ifdef ENCODER_ENABLE

#    include "encoder.h"
#    include "customCodes.h"

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            if (!layer_state_is(_NAV)) {
                tap_code(KC_VOLU);
            } else {
                tap_code16(LALT(LCTL(KC_RGHT)));
            }
        } else {
            if (!layer_state_is(_NAV)) {
                tap_code(KC_VOLD);
            } else {
                tap_code16(LALT(LCTL(KC_LEFT)));
            }
        }
    } else if (index == 1) {
        // Scroll history
        if (clockwise) {
            tap_code16(C(KC_Y));
        } else {
            tap_code16(C(KC_Z));
        }
    }
    return true;
}

#endif

#ifdef ENCODER_ENABLE

#    include "encoder.h"
#    include "customCodes.h"

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Scroll history
        // Reversed direction on the right side
        if (clockwise) {
            tap_code16(C(A(KC_LEFT)));
        } else {
            tap_code16(C(A(KC_RIGHT)));
        }
    }
    return true;
}

#endif

#include "switcher.h"

void update_oneshot(oneshot_state *state, uint16_t mod, uint16_t trigger, uint16_t keycode, keyrecord_t *record) {
    if (keycode == trigger) {
        if (record->event.pressed) {
            // Trigger keydown
            if (*state == os_up_unqueued) {
                register_code(mod);
            }
            *state = os_down_unused;
        } else {
            // Trigger keyup
            switch (*state) {
                case os_down_unused:
                    // If we didn't use the mod while trigger was held, queue it.
                    *state = os_up_queued;
                    break;
                case os_down_used:
                    // If we did use the mod while trigger was held, unregister it.
                    *state = os_up_unqueued;
                    unregister_code(mod);
                    break;
                default:
                    break;
            }
        }
    } else {
        if (record->event.pressed) {
            if (is_oneshot_cancel_key(keycode) && *state != os_up_unqueued) {
                // Cancel oneshot on designated cancel keydown.
                *state = os_up_unqueued;
                unregister_code(mod);
            }
        } else {
            if (!is_oneshot_ignored_key(keycode)) {
                // On non-ignored keyup, consider the oneshot used.
                switch (*state) {
                    case os_down_unused:
                        *state = os_down_used;
                        break;
                    case os_up_queued:
                        *state = os_up_unqueued;
                        unregister_code(mod);
                        break;
                    default:
                        break;
                }
            }
        }
    }
}

bool update_oneshot_layer(oneshot_state *state, uint16_t layer, uint16_t trigger, uint16_t keycode, keyrecord_t *record) {
    if (keycode == trigger) {
        if (record->event.pressed) {
            // Trigger keydown
            if (*state == os_up_unqueued) {
                layer_on(layer);
            }
            *state = os_down_unused;
            return false;
        } else {
            // Trigger keyup
            switch (*state) {
                case os_down_unused:
                    // If we didn't use the layer while trigger was held, queue it.
                    *state = os_up_queued;
                    return false;
                case os_down_used:
                    // If we did use the layer while trigger was held, turn it off.
                    *state = os_up_unqueued;
                    layer_off(layer);
                    return false;
                default:
                    break;
            }
        }
    } else {
        if (record->event.pressed) {
            if (is_oneshot_layer_cancel_key(keycode) && *state != os_up_unqueued) {
                // Cancel oneshot layer on designated cancel keydown.
                *state = os_up_unqueued;
                layer_off(layer);
                return false;
            }
            uint8_t key_layer = read_source_layers_cache(record->event.key);
            if (key_layer == layer) {
                // On non-ignored keyup, consider the oneshot used.
                switch (*state) {
                    case os_down_unused:
                        *state = os_down_used;
                        return true;
                    case os_up_queued:
                        if (is_oneshot_mod_key(keycode)) {
                            *state = os_up_unqueued;
                            layer_off(layer);
                            return false;
                        } else {
                            *state = os_up_queued_used;
                        }
                        return true;
                    case os_up_queued_used:
                        *state = os_up_unqueued;
                        layer_off(layer);
                        return false;
                    default:
                        break;
                }
            }
        } else {
            // Ignore key ups from other layers
            uint8_t key_layer = read_source_layers_cache(record->event.key);
            if (key_layer == layer) {
                // On non-ignored keyup, consider the oneshot used.
                switch (*state) {
                    case os_up_queued:
                        *state = os_up_unqueued;
                        layer_off(layer);
                        return true;
                    case os_up_queued_used:
                        *state = os_up_unqueued;
                        layer_off(layer);
                        return true;
                    default:
                        break;
                }
            }
        }
    }
    return true;
}

bool update_move_hold_layer(oneshot_state *state, uint16_t layer, uint16_t trigger, uint16_t keycode, keyrecord_t *record) {
    if (keycode == trigger) {
        if (record->event.pressed) {
            // Trigger keydown
            if (*state == os_up_unqueued) {
                layer_move(layer);
            }
            *state = os_down_unused;
            return false;
        } else {
            // Trigger keyup
            switch (*state) {
                case os_down_unused:
                    // If we didn't use the layer while trigger was held, queue it.
                    *state = os_up_queued;
                    return false;
                case os_down_used:
                    // If we did use the layer while trigger was held, turn it off.
                    *state = os_up_unqueued;
                    layer_off(layer);
                    return false;
                default:
                    break;
            }
        }
    } else {
        uint8_t key_layer = read_source_layers_cache(record->event.key);
        if (key_layer == layer) {
            if (record->event.pressed) {
                // Reset state to make it work if we use another key to change layer
                switch (*state) {
                    case os_down_unused:
                        // Handle hold case
                        *state = os_down_used;
                        return true;
                    case os_up_queued:
                        // Handle tap case
                        *state = os_up_queued_used;
                        return true;
                    case os_up_queued_used:
                        // Handle tap case
                        *state = os_up_unqueued;
                        return false;
                    default:
                        break;
                }
            } else {
                // Reset state to make it work if we use another key to change layer
                switch (*state) {
                    case os_up_queued:
                        // Force reset of layer state
                        *state = os_up_unqueued;
                        return true;
                    case os_up_queued_used:
                        // Force reset of layer state
                        *state = os_up_unqueued;
                        return true;
                    default:
                        break;
                }
            }
        }
    }
    return true;
}

bool update_on_hold_layer(oneshot_state *state, uint16_t layer, uint16_t trigger, uint16_t keycode, keyrecord_t *record) {
    if (keycode == trigger) {
        if (record->event.pressed) {
            // Trigger keydown
            if (*state == os_up_unqueued) {
                layer_on(layer);
            }
            *state = os_down_unused;
            return false;
        } else {
            // Trigger keyup
            switch (*state) {
                case os_down_unused:
                    // If we didn't use the layer while trigger was held, queue it.
                    *state = os_up_queued;
                    return false;
                case os_down_used:
                    // If we did use the layer while trigger was held, turn it off.
                    *state = os_up_unqueued;
                    layer_off(layer);
                    return false;
                default:
                    break;
            }
        }
    } else {
        uint8_t key_layer = read_source_layers_cache(record->event.key);
        if (key_layer == layer) {
            if (record->event.pressed) {
                // Reset state to make it work if we use another key to change layer
                switch (*state) {
                    case os_down_unused:
                        // Handle hold case
                        *state = os_down_used;
                        return true;
                    case os_up_queued:
                        // Handle tap case
                        *state = os_up_queued_used;
                        return true;
                    case os_up_queued_used:
                        // Handle tap case
                        *state = os_up_unqueued;
                        return false;
                    default:
                        break;
                }
            } else {
                // Reset state to make it work if we use another key to change layer
                switch (*state) {
                    case os_up_queued:
                        // Force reset of layer state
                        *state = os_up_unqueued;
                        return true;
                    case os_up_queued_used:
                        // Force reset of layer state
                        *state = os_up_unqueued;
                        return true;
                    default:
                        break;
                }
            }
        }
    }
    return true;
}

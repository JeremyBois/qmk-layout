#pragma once

//
// ***
// LAYER SETTINGS
// ***
//
enum custom_layers { _DEFAULT = 0, _COLEMAK, _NUM, _NAV, _SYM, _ADJUST };

//
// ***
// CUSTOM KEYCODE HANDLING
// ***
//
enum custom_keycodes {
#ifdef VIA_ENABLE
    C_GRV = USER00,
#else
    C_GRV = SAFE_RANGE,
#endif
    C_TILD,
    C_QUOT,
    C_DQUOT,
    C_CHORD,
    SW_CTAB, // Ctrl-tab
    SW_ATAB, // Alt-tab
    OSL_SYM, // One shot layer without timer
    OSL_NUM, //
    MHL_NAV  // On move/hold layer without timer
};

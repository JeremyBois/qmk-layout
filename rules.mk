MCU = atmega32u4
BOOTLOADER = qmk-dfu

# VIA Setup support (Does not yet support 5 layouts)
VIA_ENABLE = no
DYNAMIC_KEYMAP_ENABLE = no

SPLIT_KEYBOARD = yes			# Split keyboard
LTO_ENABLE = yes				# Save space by link time optimization

# Options
RGBLIGHT_ENABLE = yes			# RGB lighting (+3826)
ENCODER_ENABLE = yes		    # Rotary encoders (+1112)
EXTRAKEY_ENABLE = yes			# Audio control and System control (+450)
MOUSEKEY_ENABLE = yes			# Mouse keys (+1482). Not required for trackball usage
LEADER_ENABLE = yes             # Combinaisons with a leader key

# Unused
BOOTMAGIC_ENABLE = no           # Software way to enter boot mode
OLED_ENABLE = no                # Must be disabled if OLEDs are not installed (+3608-4774 with pet)
CONSOLE_ENABLE = no             # Console for debug (+4686)
UNICODE_ENABLE = no             # Allow to send unicode characters
SPACE_CADET_ENABLE = no 		# Save space by not using space cadet left/right shift (+350)
NKRO_ENABLE = no				# 6KRO by default. NKRO works if enabled (+328)
COMBO_ENABLE = no               # Allow to write combo
TAP_DANCE_ENABLE = no           # Allow tap dance combinations

# Split sources
SRC += features/encoder.c
SRC += features/tapdance.c
SRC += features/swapper.c
SRC += features/switcher.c

# VIA keymap for Sofle

Features:

- Support for Qwerty / Colemak

- Consistent hold / tap for modifiers
  - no timer
    - hold the trigger while tapping another key
      - send trigger + key
    - tap/release the trigger before hitting another key
      - queue the modifier for next non modifier key (sticky)
  - sticky modifiers
    - remain activated on layer switch
    - user defined entry point to select key that cancel queued modifiers
    - user defined entry point to selet key thatt does not affect queueing

- Consistent layer hold / move
  - no timer
    - hold the trigger while tapping another key
      - key from layer while holding
    - tap/release the trigger before hitting another key
      - change layer (move or activate)
  - hold + one shot layer
  - hold + move layer
  - hold + activate layer

- Navigation layer
  - mouse, 4 buttons and scroll
  - arrows, begin, end
  - auto ctrl for common task (paste, copy, ...)
  - hold + move layer

- Numpad layer
  - no timer
  - numbers on the left
  - function keys on the right
  - hold / one shot layer

- Symbol layer
  - shifted keys without shift required
  - access to leader key for chording
  - hold / one shot layer

- Easy shift
  - shift layer for avoid keeping shift hold for symbols / punctuations
  - shift on hold space/enter to tap upper case character
  - space / enter en tap but shift on hold

- Leader key sequence to input accentuated character
  - no timer
  - works on upper and lower character
  - e, u, i, c

- Encoder controls
  - left : volume up/down/mute
  - right : undo/redo or back/forward

- RGB support
  - persistent layer (external columns)
  - one shot layer (middle columns)
  - caps lock (lower row)
  - adjust layer (lower row)
  - indicator LED for current layout


## TODO

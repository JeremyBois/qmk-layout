# VIA keymap for Sofle

Features:

- Modes for Qwerty/Qwerty for games/Colemak

- Reduce hold shift
  - shift layer for avoid keeping shift hold for symbols / punctuations
  - shift on hold space/enter to tap upper case character

- Tap dance to input accentuated character
  - works on upper and lower character
  - e, u, i, c

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
  - shortcuts (paste, copy, ...)

- Numpad layer
  - everything on the left part

- Symbol layer
  - shifted keys without shift required
  - less finger mouvement

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

  - Trouver une meilleure place pour backspace / delete
  - Remplacer la gestion de `leader key` par une implémentation sans timer

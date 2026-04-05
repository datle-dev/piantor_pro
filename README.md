# Dat Le - Piantor Pro Keymap

This is a keymap for a beekeeb piantor pro.

## Files

-   `keymap.c`
-   `config.h`
-   `rules.mk`
-   `combos.def`

## Keymap

### Thumb Button Layout

The left thumb buttons are enter (center), escape (inside), and tab (outside).
The right thumb buttons are space (center), backspace (inside), and delete (outside).
Inside is the direction towards the center of the body;
outside is the direction away from the center.

This configuration puts the most used thumb buttons in the center and inside.
The outside thumb button is more awkward, as it involves slightly tucking the thumb beneath the palm and index finger.

### Bottom Row Modifiers

The 4 keys on the bottom row for each hand are mod-tap.
Instead of home row modifiers, the bottom row was chosen to help decrease unintentional misfires.
From the inside going outwards, the modifiers are shift, control, alt, and GUI.
This order places the most common modifiers under the strongest fingers.

### Layer Overview

The base layer, 0, is QWERTY.
The next layer, 1, is the Gallium v2 layout.
The switch between QWERTY and Gallium v2 is achieved through toggling the default layers,
using `DF(0)` and `DF(1)`, respectively.
Note that `DF()` is a temporary switch and only persists until the keyboard loses power.

The remaining layers are all momentarily activated through a combination of
layer-tap via `LT()` and momentary activation via `MO()`.
This activation is achieved by holding the thumb buttons, which are layer-tap.

The left thumb layers are 2 (center), 4 (inside), and 6 (outside).
The right thumb layers are 3 (center), 5 (inside), and 7 (outside).

The two center thumb buttons held together momentarily activate layer 8.
The two inside buttons activate layer 9.
And the two outside activate 10.

This configuration yields 9 additional layers, which is admittedly an excessive amount.
However, instead of trying to fit as many keycodes into as few layers as possible,
keycodes can be organized by intent or functionality in smaller groups.

### Navigation Layer

The navigation layer places the arrow keys on the home row of the right hand in Vim fashion:

-   `h` = left
-   `j` = down
-   `k` = up
-   `l` = right

Similarly, home/end and page up/down are placed on the top row of the right hand
in an order that corresponds to its directionality
i.e. home/end corresponds to left/right, and page up/down correspond to arrow up/down.

Though the left thumb is being held to enter this navigation layer,
the bottom row has each modifier in the same layout as the base layer's mod-tap keys.
This allows for use of control and shift when navigating lines of code to
jump to the beginning and ends of character sequences,
make selections per character or per character sequence,
or jump to the beginning or end of lines.
Likewise, some editors have additional functionality involving the alt key,
such as VSCode's multiline editing features.

## Flashing Instructions

These instructions are for flashing the keyboard using QMK CLI on Windows 10/11.

1. Assuming the keymap `dle_piantor_pro` exists in `keyboards/beekeeb/piantor_pro/keymaps/`,
   input the following command via the QMK CLI to compile the `.uf2` for the ProMicro RP2040 in `.build/`.

    ```
    qmk compile -kb beekeeb/piantor_pro -km dle_piantor_pro
    ```

    Note that compared to the chocofi with the SeaPicro, the piantor pro already has a ProMicro RP2040 and doesn't require a conversion.

2. If the chocofi keyboard is connected, disconnect it at the USB-C port.
3. Disconnect the TRS cable connecting the left and right halves.
4. Plug in only the chocofi left half to the computer via the USB-C port.
5. Double-tap the physical reset key on the thumb-side of the chocofi left half.
    - This puts the keyboard into DFU (Bootloader) mode
    - The RP2040 will appear as a drive upon entering bootloader mode
6. Copy the compiled `.uf2` from `.build/` and paste it into the RP2040 drive
    - The drive will automatically eject after a successful copy + paste
7. Disconnect the chocofi left half from the computer at the USB-C port.
8. Repeat steps 4 thru 7 for the right half.
9. Reconnect the TRS cable to connect the left and right halves.
10. Reconnect the chocofi left half to the computer via the USB-C port.

## Combos

`COMBO_ENABLE = yes` has been added to `rules.mk` to enable combos.

Combo timeout has been configured by adding the following to `config.h`:

```c
#define COMBO_VARIABLE_LEN
#define COMBO_TERM 30
```

`VPATH += keyboards/gboards/` has been added to `rules.mk`,
and `g/keymap_combo.h` has been added to `keymap.c`.
With the above configured,
combos are defined separately in the combos dictionary: `combos.def`.

In `combos.def`, combos are defined using `COMB()` where the arguments are:

1. name
2. result
3. chord key #1
4. chord key #2

### Combo Sequences

For the tables below, finger designations are:

1. index
2. middle
3. ring
4. pinky

All combos are either adjacent keys (1-2, 2-3, 3-4) or 2 keys apart (1-3, 2-4).
For musicians of many instruments, the coordination required for 2-key-apart combos should feel natural.
1-4 is a possible combo, but has been deprioritized in favor of the aforementioned.

This yields 5 possible combos per row of keys without having to move the index or pinky fingers laterally.
The total number of combos possible within this framework is 30:
5 combos per row for top, home, and bottom rows of both the left and right hands.
This is sufficient for all major symbols with a few empty spots to spare.

#### Left Hand - Top Row

| Result | Key 1 | Key 2 | Designation |
| :----: | :---: | :---: | :---------: |
|   (    |   R   |   E   |     1-2     |
|   [    |   E   |   W   |     2-3     |
|   <    |   W   |   Q   |     3-4     |
|   {    |   R   |   W   |     1-3     |
|   ~    |   E   |   Q   |     2-4     |

#### Left Hand - Home Row

| Result | Key 1 | Key 2 | Designation |
| :----: | :---: | :---: | :---------: |
|   -    |   F   |   D   |     1-2     |
|   \_   |   D   |   S   |     2-3     |
|   +    |   S   |   A   |     3-4     |
|   =    |   F   |   S   |     1-3     |
|   @    |   D   |   A   |     2-4     |

#### Left Hand - Bottom Row

| Result | Key 1 | Key 2 | Designation |
| :----: | :---: | :---: | :---------: |
|   /    |   V   |   C   |     1-2     |
|   \    |   C   |   X   |     2-3     |
|   \*   |   X   |   Z   |     3-4     |
|   \|   |   V   |   X   |     1-3     |
|        |   C   |   Z   |     2-4     |

#### Right Hand - Top Row

| Result | Key 1 | Key 2 | Designation |
| :----: | :---: | :---: | :---------: |
|   )    |   U   |   I   |     1-2     |
|   ]    |   I   |   O   |     2-3     |
|   >    |   O   |   P   |     3-4     |
|   }    |   U   |   O   |     1-3     |
|   ^    |   I   |   P   |     2-4     |

#### Right Hand - Home Row

| Result | Key 1 | Key 2 | Designation |
| :----: | :---: | :---: | :---------: |
|   '    |   J   |   K   |     1-2     |
|   "    |   K   |   L   |     2-3     |
|   `    |   L   |   ;   |     3-4     |
|   #    |   J   |   L   |     1-3     |
|   %    |   K   |   ;   |     2-4     |
|   :    |   H   |   K   |     1-2     |
|   ;    |   H   |   L   |     1-3     |

#### Right Hand - Bottom Row

| Result | Key 1 | Key 2 | Designation |
| :----: | :---: | :---: | :---------: |
|   &    |   M   |   ,   |     1-2     |
|   !    |   ,   |   .   |     2-3     |
|   ?    |   .   |   /   |     3-4     |
|   $    |   M   |   .   |     1-3     |
|        |   ,   |   /   |     2-4     |

#### Both Hands - Home Row

| Result  | Key 1 | Key 2 |
| :-----: | :---: | :---: |
| QK_LEAD |   F   |   J   |

## Leader Key

`LEADER_ENABLE = yes` has been added to `rules.mk` to enable the leader key,
which is then added to the keymap using the `QK_LEAD` keycode.
The configured leader key is the combo `F + J`, which is defined in `combos.def`.

Per-key timeout has been configured by adding the following to `config.h`:

```c
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 500
```

The default recommendation of lowering timeout to below 300 ms when using per-key timing felt too rushed.
500 ms felt more comfortable when inputting the leader key sequences in a relaxed fashion.

### Alt Code Sequences

For sequences that are alt codes (degree symbol, em dash, etc), the leader key sequence uses `SEND_STRING` to accomplish the following:

-   send key down for left alt via `SS_DOWN(X_LALT)`
-   send tap for the numpad keys via `SS_TAP(X_P*)`
-   send key up for left alt via `SS_UP(X_LALT)`

Note that the arguments for `SS_*()` functions used within `SEND_STRING()` are prefixed with `X_` instead of `KC_`.

### Leader Key Sequences

| Result | Key 1 | Key 2 | Key 3 | Key 4 | Key 5 |      Note       |
| :----: | :---: | :---: | :---: | :---: | :---: | :-------------: |
|   °C   |   D   |   C   |       |       |       |                 |
|   °F   |   D   |   F   |       |       |       |                 |
|   —    |   E   |   M   |       |       |       |   **em** dash   |
|   ²    |   S   |   K   |       |       |       | "**sk**uared";  |
|   ³    |   K   |   B   |       |       |       | "**k**u**b**ed" |

## Miscellaneous Configuration

### Raspberry PI RP2040

`BOOTLOADER = rp2040` has been added to `rules.mk`.

`#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET` has been added to `config.h`.

### Caps Word

`CAPS_WORD_ENABLE = yes` has been added to `rules.mk` to enable caps word.

`#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD` has been added to `config.h`,
which enables caps word activation by pressing left shift + right shift.

### Tapping Term

`#define TAPPING_TERM 200` has been added to `config.h`.
200 ms is the default tapping term.

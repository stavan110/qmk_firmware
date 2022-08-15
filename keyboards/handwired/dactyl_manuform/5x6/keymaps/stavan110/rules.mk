BOOTLOADER=qmk-dfu
CONSOLE_ENABLE = yes
MOUSEKEY_ENABLE = yes
TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes
NKRO_ENABLE = no
STENO_ENABLE = yes
STENO_PROTOCOL = geminipr
SWAP_HANDS_ENABLE = no
SEL_WORD_ENABLE = yes

# Space savings
LTO_ENABLE = yes
COMMAND_ENABLE = no
KEY_LOCK_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no

# Load the necessary external C files if and only if
# the associated config option has been enabled
ifeq ($(strip $(COMBO_ENABLE)), yes)
	SRC += combos.c
endif
ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
	SRC += tapdance.c
endif
# ifeq ($(strip $(SWAP_HANDS_ENABLE)), yes)
# 	SRC += swap_hand.c
# endif
ifeq ($(strip $(SEL_WORD_ENABLE)), yes)
	SRC += features/select_word.c
endif

#----------------------------------------------------------------------------
# make gergo:germ:dfu
# Make sure you have dfu-programmer installed!
#----------------------------------------------------------------------------
# Firmware options
MOUSEKEY_ENABLE         = yes
DEBOUNCE_TYPE           = sym_eager_pk

#Debug options
VERBOSE                 = no
DEBUG_MATRIX_SCAN_RATE  = no
DEBUG_MATRIX            = no
CONSOLE_ENABLE          = no

#Combos!
COMBO_ENABLE = yes
VPATH                  +=  keyboards/gboards/

ifeq ($(strip $(DEBUG_MATRIX)), yes)
    OPT_DEFS += -DDEBUG_MATRIX
endif

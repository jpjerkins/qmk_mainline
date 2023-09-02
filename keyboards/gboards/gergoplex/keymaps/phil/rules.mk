#----------------------------------------------------------------------------
# make gergo:germ:dfu
# Make sure you have dfu-programmer installed!
#----------------------------------------------------------------------------
# Firmware options
DEBOUNCE_TYPE           = sym_eager_pk  # Set the debounce type
MOUSEKEY_ENABLE         = yes           # Mouse keys
EXTRAKEY_ENABLE         = no            # Audio control and System control
CONSOLE_ENABLE          = no            # Console for debug
COMMAND_ENABLE          = no            # Commands for debug and configuration
NKRO_ENABLE             = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE        = no            # Enable keyboard backlight functionality
RGBLIGHT_ENABLE         = no            # Enable keyboard RGB underglow
AUDIO_ENABLE            = no            # Audio output
STENO_ENABLE            = yes           # Enable steno
STENO_PROTOCOL          = geminipr      # Enable the Gemini PR steno protocol

#Debug options
VERBOSE                 = no
DEBUG_MATRIX_SCAN_RATE  = no
DEBUG_MATRIX            = no
CONSOLE_ENABLE          = no

#Combos!
COMBO_ENABLE            = yes
VPATH                  +=  keyboards/gboards/

# ifeq ($(strip $(DEBUG_MATRIX)), yes)
#     OPT_DEFS += -DDEBUG_MATRIX
# endif

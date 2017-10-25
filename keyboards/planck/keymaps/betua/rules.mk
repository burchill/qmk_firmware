# Build Options
#   change to "no" to disable the options, or define them in the Makefile in 
#   the appropriate keymap folder that will get included automatically
#

BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration(+1000)
     # Mouse keys(+4700)
EXTRAKEY_ENABLE = no       # Audio control and System control(+450)
CONSOLE_ENABLE = no         # Console for debug(+400)
COMMAND_ENABLE = no
TAP_DANCE_ENABLE = yes 


ifndef QUANTUM_DIR
	include ../../../../Makefile
endif



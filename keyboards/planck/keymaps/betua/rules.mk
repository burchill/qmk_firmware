# Build Options
#   change to "no" to disable the options, or define them in the Makefile in 
#   the appropriate keymap folder that will get included automatically
#

CONSOLE_ENABLE = yes         # Console for debug(+400)
BOOTMAGIC_ENABLE = yes       # Virtual DIP switch configuration(+1000)
     # Mouse keys(+4700)
EXTRAKEY_ENABLE = yes       # Audio control and System control(+450)
CONSOLE_ENABLE = yes         # Console for debug(+400)
COMMAND_ENABLE = yes
TAP_DANCE_ENABLE = yes 


ifndef QUANTUM_DIR
	include ../../../../Makefile
endif



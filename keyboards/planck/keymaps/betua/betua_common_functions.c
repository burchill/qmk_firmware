extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _TAPMODS,
  _RLAYER,
  _LOWER,
  _RAISE,
  _ADJUST,
  _CUSTOM
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  BACKLIT,
  M_PIPE,
  M_GROUP_BY,
  M_NEXT_CHUNK
};

//Tap Dance Declarations
enum {
  TD_SP_ENT = 0,
  TD_FUCK_ME_SILLY
};





//**************** Definitions needed for quad function to work *********************//
//Enums used to clearly convey the state of the tap dance
enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4, 
  DOUBLE_SINGLE_TAP = 5 //send SINGLE_TAP twice - NOT DOUBLE_TAP
  // Add more enums here if you want for triple, quadruple, etc. 
};

typedef struct {
  bool is_press_action;
  int state;
} tap;

int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    //If count = 1, and it has been interrupted - it doesn't matter if it is pressed or not: Send SINGLE_TAP
    if (state->interrupted || state-> pressed == 0) return SINGLE_TAP;
    else return SINGLE_HOLD;
  }
  //If count = 2, and it has been interrupted - assume that user is trying to type the letter associated
  //with single tap. In example below, that means to send `xx` instead of `Escape`.
  else if (state->count == 2) {
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  } 
  else return 6; //magic number. At some point this method will expand to work for more presses
}

//**************** Definitions needed for quad function to work *********************//

//*********************** RIGHT BRACKET / 
//instanalize an instance of 'tap' for the 'x' tap dance.
// static tap td_rbkt_state = { 
//   .is_press_action = true,
//   .state = 0
// };
// 
// void x_finished (qk_tap_dance_state_t *state, void *user_data) {
//   td_rbkt_state.state = cur_dance(state);
//   switch (td_rbkt_state.state) {
//     case SINGLE_TAP: register_code(KC_X); break;
//     case SINGLE_HOLD: register_code(KC_LCTRL); break;
//     case DOUBLE_TAP: register_code(KC_ESC); break;
//     case DOUBLE_HOLD: register_code(KC_LALT); break;
//     case DOUBLE_SINGLE_TAP: register_code(KC_X); unregister_code(KC_X); register_code(KC_X);
//     //Last case is for fast typing. Assuming your key is `f`:
//     //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
//     //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
//   }
// }
// 
// void x_reset (qk_tap_dance_state_t *state, void *user_data) {
//   switch (td_rbkt_state.state) {
//     case SINGLE_TAP: unregister_code(KC_X); break;
//     case SINGLE_HOLD: unregister_code(KC_LCTRL); break;
//     case DOUBLE_TAP: unregister_code(KC_ESC); break;
//     case DOUBLE_HOLD: unregister_code(KC_LALT);
//     case DOUBLE_SINGLE_TAP: unregister_code(KC_X);
//   }
//   td_rbkt_state.state = 0;
// }



const uint16_t PROGMEM fn_actions[] = {
    // Equivalent to ACTION_MODS_TAP_KEY(MOD_RCTL, KC_RBRC)  CTRL, }
    [0] = ACTION_MACRO_TAP(0),
    // Equivalent to ACTION_MODS_TAP_KEY(MOD_RALT, KC_RABK)  ALT, >
    [1] = ACTION_MACRO_TAP(1),
    // Equivalent to ACTION_MODS_TAP_KEY(MOD_LCTL, KC_LBRC)  CTRL, {
    [2] = ACTION_MACRO_TAP(2),
    // Equivalent to ACTION_MODS_TAP_KEY(MOD_LALT, KC_LABK)  ALT, <
    [3] = ACTION_MACRO_TAP(3),

    // Equivalent to ACTION_LAYER_TAP_KEY(_LW, KC_LPRN)
    //[1] = ACTION_MACRO_TAP(1)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch(id) {
        case 0: // ACTION_MODS_TAP_KEY(MOD_RCTL, KC_RBRC)
      		if (record->event.pressed) {
  		      register_mods(MOD_RCTL);
  		      record->tap.interrupted = 0;
 		     } else {
  		      unregister_mods(MOD_RCTL);
		
  		      if (record->tap.count && !record->tap.interrupted) {
  		        add_weak_mods(MOD_LSFT);
  		        register_code(KC_RBRC);
  		        unregister_code(KC_RBRC);
  		        del_weak_mods(MOD_LSFT);
  		      }
		
  		      record->tap.count = 0;
  		    }
  		    break;
  		    
  		case 1: // ACTION_MODS_TAP_KEY(MOD_RALT, KC_RABK)
      		if (record->event.pressed) {
  		      register_mods(MOD_RALT);
  		      record->tap.interrupted = 0;
 		     } else {
  		      unregister_mods(MOD_RALT);
		
  		      if (record->tap.count && !record->tap.interrupted) {
  		        add_weak_mods(MOD_LSFT);
  		        register_code(KC_DOT);
  		        unregister_code(KC_DOT);
  		        del_weak_mods(MOD_LSFT);
  		      }
		
  		      record->tap.count = 0;
  		    }
  		    break;  
  		
  		case 2: // ACTION_MODS_TAP_KEY(MOD_RCTL, KC_LBRC)
      		if (record->event.pressed) {
  		      register_mods(MOD_LCTL);
  		      record->tap.interrupted = 0;
 		     } else {
  		      unregister_mods(MOD_LCTL);
		
  		      if (record->tap.count && !record->tap.interrupted) {
  		        add_weak_mods(MOD_LSFT);
  		        register_code(KC_LBRC);
  		        unregister_code(KC_LBRC);
  		        del_weak_mods(MOD_LSFT);
  		      }
		
  		      record->tap.count = 0;
  		    }
  		    break;  
  		    
  		case 3: // ACTION_MODS_TAP_KEY(MOD_LALT, KC_LABK)
      		if (record->event.pressed) {
  		      register_mods(MOD_LALT);
  		      record->tap.interrupted = 0;
 		     } else {
  		      unregister_mods(MOD_LALT);
		
  		      if (record->tap.count && !record->tap.interrupted) {
  		        add_weak_mods(MOD_LSFT);
  		        register_code(KC_COMMA);
  		        unregister_code(KC_COMMA);
  		        del_weak_mods(MOD_LSFT);
  		      }
		
  		      record->tap.count = 0;
  		    }
  		    break;      
  		  
    }
    return MACRO_NONE;
};
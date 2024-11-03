/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum custom_keycodes {
    KC_M_MVLU = SAFE_RANGE, // move line up
    KC_M_MVLD,				// move line down
    KC_M_BACK,				// go back
    KC_M_FRWD,				// go forward
    KC_M_BLKC,				// block comment
    KC_M_WNDUP,				// move window up
    KC_M_WNDDN,				// move window down
    KC_M_WNDLT,				// move window left
    KC_M_WNDRT,				// move window right
    KC_M_PKDEF,				// peek definition
    KC_M_FNREF,				// find references
	UPPER,					// switch to UPPER layer
	LOWER,					// switch to LOWER layer
};

enum layers {
	L_BASE,
	L_UPPER,
	L_LOWER,
	L_ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, UPPER,  KC_SPC,     KC_ENT,   LOWER, KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

  [L_UPPER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_PGUP, XXXXXXX, KC_M_WNDUP, XXXXXXX, XXXXXXX,                    KC_APP, KC_HOME,   KC_UP,  KC_END, KC_SCLN,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_PGDN, KC_M_WNDLT, KC_M_WNDDN, KC_M_WNDRT, XXXXXXX,             XXXXXXX, KC_LEFT, KC_DOWN,KC_RIGHT, KC_SLSH, KC_PSCR,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [L_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_PIPE, KC_LCBR, KC_LBRC, KC_PLUS, KC_UNDS,                      KC_MINS,  KC_EQL, KC_RBRC, KC_RCBR, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX,  KC_GRV, KC_LPRN, XXXXXXX,                      XXXXXXX, KC_RPRN, KC_TILD,  XXXXXXX, XXXXXXX, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [L_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_F11,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, KC_M_FNREF, KC_M_PKDEF, XXXXXXX,                XXXXXXX, KC_M_BLKC, KC_M_MVLU, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_M_BACK, KC_M_MVLD, KC_M_FRWD, XXXXXXX, QK_BOOTLOADER,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

// if we're currently moving a window
static bool in_move_window = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		// go to upper layer, if both layers active go to adjust layer
		case UPPER: {
			if (record->event.pressed) {
				layer_on(L_UPPER);
				update_tri_layer(L_LOWER, L_UPPER, L_ADJUST);
			} else {
				if (in_move_window) {
					SEND_STRING(SS_UP(X_LGUI));
					in_move_window = false;
				}
				layer_off(L_UPPER);
				update_tri_layer(L_LOWER, L_UPPER, L_ADJUST);
			}
			return false;
		} break;
		
		// go to lower layer, if both layers active go to adjust layer
		case LOWER: {
			if (record->event.pressed) {
				layer_on(L_LOWER);
				update_tri_layer(L_LOWER, L_UPPER, L_ADJUST);
			} else {
				layer_off(L_LOWER);
				update_tri_layer(L_LOWER, L_UPPER, L_ADJUST);
			}
			return false;
		} break;
		
		// go back (ALT + LEFT)
        case KC_M_BACK: {
			if (record->event.pressed) {
				SEND_STRING(SS_LALT(SS_TAP(X_LEFT)));
			}
		} break;
		
		// go forward (ALT + RIGHT)
        case KC_M_FRWD: {
			if (record->event.pressed) {
				SEND_STRING(SS_LALT(SS_TAP(X_RIGHT)));
			}
		} break;
		
		// toggle block comment (vscode)
        case KC_M_BLKC: {
			if (record->event.pressed) {
				SEND_STRING(SS_LALT(SS_LSFT("a")));
			}
        } break;
		
		// move line down (vscode)
        case KC_M_MVLD: {
			if (record->event.pressed) {
				register_code(KC_LALT);
				register_code(KC_DOWN);
			} else {
				unregister_code(KC_DOWN);
				unregister_code(KC_LALT);
			}
        } break;
		
		// move line up (vscode)
        case KC_M_MVLU: {
			if (record->event.pressed) {
				register_code(KC_LALT);
				register_code(KC_UP);
			} else {
				unregister_code(KC_UP);
				unregister_code(KC_LALT);
			}
        } break;
		
		// peek definition (vscode)
        case KC_M_PKDEF: {
			if (record->event.pressed) {
				SEND_STRING(SS_LALT(SS_TAP(X_F12)));
			}
		} break;
		
		// find references (vscode)
        case KC_M_FNREF: {
			if (record->event.pressed) {
				SEND_STRING(SS_LSFT(SS_TAP(X_F12)));
			}
		} break;
		
		// move window down (enters window move state)
        case KC_M_WNDDN: {
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LGUI));
				SEND_STRING(SS_TAP(X_DOWN));
				in_move_window = true;
			}
        } break;
		
		// move window left (enters window move state)
        case KC_M_WNDLT: {
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LGUI));
				SEND_STRING(SS_TAP(X_LEFT));
				in_move_window = true;
			}
        } break;
		
		// move window right (enters window move state)
        case KC_M_WNDRT: {
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LGUI));
				SEND_STRING(SS_TAP(X_RIGHT));
				in_move_window = true;
			}
		} break;
		
		// move window up (enters window move state)
        case KC_M_WNDUP: {
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LGUI));
				SEND_STRING(SS_TAP(X_UP));
				in_move_window = true;
			}
        } break;
		
        default:
            break;
    }
	
	return true;
}

// OLED stuff, just display the CORNE logo
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }
    return rotation;
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_set_cursor(0, 1);
        oled_render_logo();
    } else {
        oled_render_logo();
    }
	return false;
}

#endif // OLED_ENABLE


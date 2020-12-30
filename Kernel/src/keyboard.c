#include "../include/keyboard.h"

//Ascii key codes, codes without a character (control, alt, etc) are based on the window virtual key codes
const unsigned char keyboardmap[] = {
	0x00, 0x00,
	0x1B, 0x1B, //Escape
	0x31, 0x21,
	0x32, 0x40,
	0x33, 0x23,
	0x34, 0x24,
	0x35, 0x25,
	0x36, 0x5E,
	0x37, 0x26,
	0x38, 0x2A,
	0x39, 0x28,
	0x30, 0x29,
	0x2D, 0x5F,
	0x3D, 0x2B,
	0x08, 0x08, //Backspace
	0x09, 0x09, //Tab
	0x71, 0x51,
	0x77, 0x57,
	0x65, 0x45,
	0x72, 0x52,
	0x74, 0x54,
	0x79, 0x59,
	0x75, 0x55,
	0x69, 0x49,
	0x6F, 0x4F,
	0x70, 0x50,
	0x5B, 0x7B,
	0x5D, 0x7D,
	0x0D, 0x0D, //Enter
	0xA2, 0xA2, //LControl
	0x61, 0x41,
	0x73, 0x53,
	0x64, 0x44,
	0x66, 0x46,
	0x67, 0x47,
	0x68, 0x48,
	0x6A, 0x4A,
	0x6B, 0x4B,
	0x6C, 0x4C,
	0x3B, 0x3A,
	0x27, 0x22,
	0x60, 0x7E,
	0xA0, 0xA0, //LShift
	0x5C, 0x7C,
	0x7A, 0x5A,
	0x78, 0x58,
	0x63, 0x43,
	0x76, 0x56,
	0x62, 0x42,
	0x6E, 0x4E,
	0x6D, 0x4D,
	0x2C, 0x3C,
	0x2E, 0x3E,
	0x2F, 0x3F,
	0xA1, 0xA1, //RShift

	0x2A, 0x2A,
	0xA4, 0xA4, //LAlt
	0x20, 0x20, //Space
	0x14, 0x14, //CapsLock
	0x70, 0x70, //F1 -> F10
	0x71, 0x71,
	0x72, 0x72,
	0x73, 0x73,
	0x74, 0x74,
	0x75, 0x75,
	0x76, 0x76,
	0x77, 0x77,
	0x78, 0x78,
	0x79, 0x79,
	0x90, 0x90, //NumLock
	0x91, 0x91, //ScrollLock
	0x37, 0x37, //Keypad 7 -> 9
	0x38, 0x38,
	0x39, 0x39,
	0x2D, 0x2D, //Keypad -
	0x34, 0x34, //Keypad 4 -> 6
	0x35, 0x35,
	0x36, 0x36,
	0x2B, 0x2B, //Keypad +
	0x31, 0x31, //Keypad 1 -> 3
	0x32, 0x32,
	0x33, 0x33,
	0x30, 0x30, //Keypad 0
	0x2E, 0x2E, //Keypad .

	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

	0x80, 0x80,
	0x81, 0x81,
};

//Variables used as a bool
char capslock = 0;
char shift = 0;

void int_kb(void) {
	unsigned char keycode = inb(0x60);
	if (keycode < 0x81) {
		unsigned char key = keyboardmap[(int)keycode * 2];
		if (key == 0xA0 || key == 0xA1) {
			shift = 1;
		}
		else if (key == 0x14) {
			if (capslock == 0) {
				capslock = 1;
			}
			else {
				capslock = 0;
			}
		}
		else {
			if (shift != capslock) {
				key = keyboardmap[(int)keycode * 2 + 1];
			}
			ProcKey(key);
		}
	}
	else {
		keycode -= 0x80;
		unsigned char key = keyboardmap[(int)keycode * 2];
		if (key == 0xA0 || key == 0xA1) {
			shift = 0;
		}
	}
}
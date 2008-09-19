#ifdef WIN32
#include "Win32.h"
#endif

enum EMUCMD {
	EMUCMD_LOADSTATE1,EMUCMD_LOADSTATE2,EMUCMD_LOADSTATE3,EMUCMD_LOADSTATE4,EMUCMD_LOADSTATE5,
	EMUCMD_LOADSTATE6,EMUCMD_LOADSTATE7,EMUCMD_LOADSTATE8,EMUCMD_LOADSTATE9,
	EMUCMD_SAVESTATE1,EMUCMD_SAVESTATE2,EMUCMD_SAVESTATE3,EMUCMD_SAVESTATE4,EMUCMD_SAVESTATE5,
	EMUCMD_SAVESTATE6,EMUCMD_SAVESTATE7,EMUCMD_SAVESTATE8,EMUCMD_SAVESTATE9,
	EMUCMD_TURBOMODE,EMUCMD_FRAMEADVANCE,EMUCMD_PAUSE,EMUCMD_SPEEDDEC,EMUCMD_SPEEDINC,
	EMUCMD_FRAMECOUNTER,EMUCMD_RWTOGGLE,
	EMUCMDMAX
};

struct EMUCMDTABLE
{
	int cmd;
	int key;
	int keymod;
	char* name;
};

extern struct EMUCMDTABLE EmuCommandTable[];

static struct { int nCode; char* szName; } RealKeyNames[] = {
	{ VK_ESCAPE,               "ESCAPE" },
	{ 1,                       "1" },
	{ 2,                       "2" },
	{ 3,                       "3" },
	{ 4,                       "4" },
	{ 5,                       "5" },
	{ 6,                       "6" },
	{ 7,                       "7" },
	{ 8,                       "8" },
	{ 9,                       "9" },
	{ 0,                       "0" },
	{ VK_OEM_MINUS,            "MINUS" },
	{ VK_BACK,                 "BACKSPACE" },
	{ VK_TAB,                  "TAB" },
//	{ 'Q',                    "Q" },
//	{ VK_W,                    "W" },
//	{ VK_E,                    "E" },
//	{ VK_R,                    "R" },
//	{ VK_T,                    "T" },
//	{ VK_Y,                    "Y" },
//	{ VK_U,                    "U" },
//	{ VK_I,                    "I" },
//	{ VK_O,                    "O" },
//	{ VK_P,                    "P" },
	{ VK_OEM_4,                "OPENING BRACKET" },
	{ VK_OEM_6,                "CLOSING BRACKET" },
	{ VK_RETURN,               "ENTER" },
	{ VK_LCONTROL,             "LEFT CONTROL" },
//	{ VK_A,                    "A" },
//	{ VK_S,                    "S" },
//	{ VK_D,                    "D" },
//	{ VK_F,                    "F" },
//	{ VK_G,                    "G" },
//	{ VK_H,                    "H" },
//	{ VK_J,                    "J" },
//	{ VK_K,                    "K" },
//	{ VK_L,                    "L" },
	{ VK_OEM_1,                "SEMICOLON" },
	{ VK_OEM_7,                "APOSTROPHE" },
	{ VK_OEM_3,                "ACCENT GRAVE" },
	{ VK_LSHIFT,               "LEFT SHIFT" },
	{ VK_BACK,                 "BACKSLASH" },
//	{ VK_Z,                    "Z" },
//	{ VK_X,                    "X" },
//	{ VK_C,                    "C" },
//	{ VK_V,                    "V" },
//	{ VK_B,                    "B" },
//	{ VK_N,                    "N" },
//	{ VK_M,                    "M" },
	{ VK_OEM_COMMA,            "COMMA" },
	{ VK_OEM_PERIOD,           "PERIOD" },
	{ VK_OEM_2,                "SLASH" },
	{ VK_RSHIFT,               "RIGHT SHIFT" },
	{ VK_MULTIPLY,             "NUMPAD MULTIPLY" },
	{ VK_MENU,                 "ALT" },
	{ VK_SPACE,                "SPACE" },
	{ VK_CAPITAL,              "CAPSLOCK" },
	{ VK_F1,                   "F1" },
	{ VK_F2,                   "F2" },
	{ VK_F3,                   "F3" },
	{ VK_F4,                   "F4" },
	{ VK_F5,                   "F5" },
	{ VK_F6,                   "F6" },
	{ VK_F7,                   "F7" },
	{ VK_F8,                   "F8" },
	{ VK_F9,                   "F9" },
	{ VK_F10,                  "F10" },
	{ VK_NUMLOCK,              "NUMLOCK" },
	{ VK_SCROLL,               "SCROLLLOCK" },
	{ VK_NUMPAD7,              "NUMPAD 7" },
	{ VK_NUMPAD8,              "NUMPAD 8" },
	{ VK_NUMPAD9,              "NUMPAD 9" },
	{ VK_SUBTRACT,             "NUMPAD SUBTRACT" },
	{ VK_NUMPAD4,              "NUMPAD 4" },
	{ VK_NUMPAD5,              "NUMPAD 5" },
	{ VK_NUMPAD6,              "NUMPAD 6" },
	{ VK_ADD,                  "NUMPAD ADD" },
	{ VK_NUMPAD1,              "NUMPAD 1" },
	{ VK_NUMPAD2,              "NUMPAD 2" },
	{ VK_NUMPAD3,              "NUMPAD 3" },
	{ VK_NUMPAD0,              "NUMPAD 0" },
	{ VK_DECIMAL,              "NUMPAD DECIMAL POINT" },
	{ VK_F11,                  "F11" },
	{ VK_F12,                  "F12" },
	{ VK_F13,                  "F13" },
	{ VK_F14,                  "F14" },
	{ VK_F15,                  "F15" },
	{ VK_RCONTROL,             "RIGHT CONTROL" },
	{ VK_DIVIDE,               "NUMPAD DIVIDE" },
	{ VK_SNAPSHOT,             "PRINTSCREEN" },
	{ VK_PAUSE,                "PAUSE" },
	{ VK_HOME,                 "HOME" },
	{ VK_UP,                   "ARROW UP" },
	{ VK_PRIOR,                "PAGE UP" },
	{ VK_LEFT,                 "ARROW LEFT" },
	{ VK_RIGHT,                "ARROW RIGHT" },
	{ VK_END,                  "END" },
	{ VK_DOWN,                 "ARROW DOWN" },
	{ VK_NEXT,                 "PAGE DOWN" },
	{ VK_INSERT,               "INSERT" },
	{ VK_DELETE,               "DELETE" },
	{ VK_LWIN,                 "LEFT WINDOWS" },
	{ VK_RWIN,                 "RIGHT WINDOWS" },
	{ 0,                        NULL }
};

/*
*   This file is part of LeafEdit
*   Copyright (C) 2019-2020 DeadPhoenix8091, Epicpkmn11, Flame, RocketRobz, StackZ, TotallyNotGuy
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*   Additional Terms 7.b and 7.c of GPLv3 apply to this file:
*       * Requiring preservation of specified reasonable legal notices or
*         author attributions in that material or in the Appropriate Legal
*         Notices displayed by works containing it.
*       * Prohibiting misrepresentation of the origin of that material,
*         or requiring that modified versions of such material be marked in
*         reasonable ways as different from the original version.
*/

#include "interpreter.h"
#include "leafedit_api.h"

void UnixSetupFunc() {}

/* list of all library functions and their prototypes */
struct LibraryFunction UnixFunctions[] =
{
	// Msg.
	{ msg_warn,				"void msg_warn(char* warning);" },
	{ msg_waitMsg,			"void msg_waitMsg(char* message);" },
	{ msg_splash,			"void msg_splash(char* notification);" },
	{ msg_prompt, 			"int msg_prompt(char* message);" },
	// String Getter.
	{ getItem,				"char *getItem(unsigned int ID);"},
	// Keyboard.
	{ keyboard_string,		"char *keyboard_string(char* message);"},
	{ keyboard_value,		"int keyboard_value(char* message);"},
	// List Selections.
	{ selectList,			"int selectList(char* message, char** contents, int options);"},
	// Misc.
	{ setChangesMade,		"void setChangesMade();"},
	{ download_file,		"void download_file(char* URL, char* Path, char* Message);"}, 
	{ file_select,			"char* file_select(char* Path, char* Text);"},
	// End.
	{ NULL,					NULL }
};

void PlatformLibraryInit(Picoc *pc)
{
	IncludeRegister(pc, "leafedit.h", &UnixSetupFunc, &UnixFunctions[0], "");
}
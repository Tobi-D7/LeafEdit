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

#ifndef LEAFEDIT_API_H
#define LEAFEDIT_API_H

#include "picoc.h"

#include <3ds.h>

// Message stuff.
void msg_warn(struct ParseState*, struct Value*, struct Value**, int);
void msg_waitMsg(struct ParseState*, struct Value*, struct Value**, int);
void msg_splash(struct ParseState*, struct Value*, struct Value**, int);
void msg_prompt(struct ParseState*, struct Value*, struct Value**, int);

// Get String names.
void getItem(struct ParseState* Parser, struct Value* ReturnValue, struct Value** Param, int NumArgs);

// Open the Keyboard and return a char* or int.
void keyboard_string(struct ParseState* Parser, struct Value* ReturnValue, struct Value** Param, int NumArgs);
void keyboard_value(struct ParseState* Parser, struct Value* ReturnValue, struct Value** Param, int NumArgs);

// List stuff.
void selectList(struct ParseState* Parser, struct Value* ReturnValue, struct Value** Param, int NumArgs);

// Misc.
void setChangesMade(struct ParseState* Parser, struct Value* ReturnValue, struct Value** Param, int NumArgs);
void download_file(struct ParseState* Parser, struct Value* ReturnValue, struct Value** Param, int NumArgs);
void file_select(struct ParseState* Parser, struct Value* ReturnValue, struct Value** Param, int NumArgs);

#endif
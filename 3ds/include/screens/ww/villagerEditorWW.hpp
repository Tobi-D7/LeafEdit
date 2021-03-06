/*
*   This file is part of LeafEdit
*   Copyright (C) 2019-2020 Universal-Team
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

#ifndef _LEAFEDIT_VILLAGER_EDITOR_WW_HPP
#define _LEAFEDIT_VILLAGER_EDITOR_WW_HPP

#include "common.hpp"
#include "Item.hpp"
#include "screenCommon.hpp"
#include "Villager.hpp"

#include "structs.hpp"
#include <vector>

class VillagerEditorWW : public Screen {
public:
	void Draw(void) const override;
	void Logic(u32 hDown, u32 hHeld, touchPosition touch) override;
	VillagerEditorWW(std::unique_ptr<Villager> &refVillager): villager(refVillager) { }
private:
	std::unique_ptr<Villager> &villager;
	u8 miscItems[4];
	std::unique_ptr<Item> villagerItems[11];
	int villagerMode = 0, Selection = 0, itemSelection = 0, keyRepeatDelay = 0;
	
	void DrawSubMenu(void) const;
	void DrawItems(void) const;
	void DrawBox(void) const;
	void updateInfo(void) const;
	void subLogic(u32 hDown, u32 hHeld, touchPosition touch);
	void ItemLogic(u32 hDown, u32 hHeld, touchPosition touch);

	const std::vector<ButtonType> mainButtons = {
		{15, 34, 102, 20, "VILLAGER_REPLACE"}, // Replace.
		{15, 97, 102, 20, "VILLAGER_PERSONALITY"}, // Personality.
		{15, 159, 102, 20, "ITEMS"}, // Items.
		{175, 34, 102, 20, ""}, // Catchphrase.
		{175, 97, 102, 20, ""}, // Status.
		{175, 159, 102, 20, ""} // ?.
	};

	const std::vector<Structs::ButtonPos> items = {
		{25, 40, 30, 30}, // Furniture 0.
		{65, 40, 30, 30}, // Furniture 1.
		{105, 40, 30, 30}, // Furniture 2.
		{145, 40, 30, 30}, // Furniture 3.
		{185, 40, 30, 30}, // Furniture 4.
		{25, 80, 30, 30}, // Furniture 5.
		{65, 80, 30, 30}, // Furniture 6.
		{105, 80, 30, 30}, // Furniture 7.
		{145, 80, 30, 30}, // Furniture 8.
		{185, 80, 30, 30}, // Furniture 9.
		{25, 140, 30, 30}, // Shirt.
		{65, 140, 30, 30}, // Umbrella.
		{105, 140, 30, 30}, // Song.
		{145, 140, 30, 30}, // Wallpaper.
		{185, 140, 30, 30} // Carpet.
	};
};

#endif
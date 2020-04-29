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

#ifndef TOWNMAPEDITOR_HPP
#define TOWNMAPEDITOR_HPP

#include "Acre.hpp"
#include "common.hpp"
#include "Item.hpp"
#include "structs.hpp"

class TownMapEditor : public Screen
{
public:
	void Draw(void) const override;
	void Logic(u32 hDown, u32 hHeld, touchPosition touch) override;
	TownMapEditor();
private:
	// Specific stuff.
	u32 maxAcres;
	std::unique_ptr<Item> MapItems[5120]; // Complete Town Map Items.
	std::unique_ptr<Acre> FullAcres[42]; // Complete Acres. 36 on AC:WW, but 42 on AC:NL & AC:WA.

	/* Main Screen. */
	void DrawMapScreen(void) const;
	void MapScreenLogic(u32 hDown, u32 hHeld, touchPosition touch);

	// Town Map Editor Selection & Positions.
	int currentPosX = 0;
	int currentPosY = 0;
	int currentAcre = 0;
	int MapSelection = 0;
	int PositionX = 16;
	int PositionY = 16;
	// Modes. Acre Editor & Town Map Editor.
	int Mode = 1;
	int selectMode = 0; // No sub Selection.

	// General Item stuff.
	u16 itemID = 0;
	u16 itemFlag = 0;

	// Utilities Draw.
	void DrawGrid(void) const;
	void DrawTownMap() const;
	void DrawInformation() const;
	void DrawCurrentPos(void) const;
	// Converter's.
	void convertToSelection();
	void convertToPosition();
	int SelectionToAcre(int selection) const;

	// Operations.
	void injectTo(int MapSlot);
	void remove(u16 ID);
	void setAll(u16 ID);
	void replace(u16 oldID, u16 newID);
	void removeWeeds();
	void waterFlowers();
	void updateStuff();

	void DrawTempItem(void) const;
	void TempItemLogic(u32 hDown, u32 hHeld, touchPosition touch);
	
	/* Acres Screen. */
	void DrawAcres(void) const;
	void AcresLogic(u32 hDown, u32 hHeld, touchPosition touch);
	void DrawMap(void) const;
	void DrawFullMap(void) const;
	void DrawTopSelection(void) const;
	u8 selectedAcre = 0;
	bool FastMode = false; // Scrolling speed.
	int selection = 0;

	std::vector<Structs::ButtonPos> tempItemPos = {
		{20, 40, 280, 30}, // ID.
		{20, 90, 280, 30}, // Flag.
		{20, 140, 280, 30} // Name.
	};

	// Display AC:WW Top Screen Map.
	const std::vector<Structs::ButtonPos> WWMapPos = {
		{5, 40, 32, 32} ,{37, 40, 32, 32}, {69, 40, 32, 32}, {101, 40, 32, 32},
		{5, 72, 32, 32}, {37, 72, 32, 32}, {69, 72, 32, 32}, {101, 72, 32, 32},
		{5, 104, 32, 32}, {37, 104, 32, 32}, {69, 104, 32, 32}, {101, 104, 32, 32},
		{5, 136, 32, 32}, {37, 136, 32, 32}, {69, 136, 32, 32}, {101, 136, 32, 32}
	};

	// Town Map Display [NL / Top Screen.]
	const std::vector<Structs::ButtonPos> townPos = {
		{5, 40, 40, 40},{45, 40, 40, 40},{85, 40, 40, 40},
		{125, 40, 40, 40},{165, 40, 40, 40},

		{5, 80, 40, 40},{45, 80, 40, 40},{85, 80, 40, 40},
		{125, 80, 40, 40},{165, 80, 40, 40},

		{5, 120, 40, 40},{45, 120, 40, 40},{85, 120, 40, 40},
		{125, 120, 40, 40},{165, 120, 40, 40},

		{5, 160, 40, 40},{45, 160, 40, 40},{85, 160, 40, 40},
		{125, 160, 40, 40},{165, 160, 40, 40}
	};
	// Display AC:NL's Town Map [Not fully.]
	const std::vector<Structs::ButtonPos> acreTownPos = {
		{60, 40, 40, 40},{100, 40, 40, 40},{140, 40, 40, 40},
		{180, 40, 40, 40},{220, 40, 40, 40},

		{60, 80, 40, 40},{100, 80, 40, 40},{140, 80, 40, 40},
		{180, 80, 40, 40},{220, 80, 40, 40},

		{60, 120, 40, 40},{100, 120, 40, 40},{140, 120, 40, 40},
		{180, 120, 40, 40},{220, 120, 40, 40},

		{60, 160, 40, 40},{100, 160, 40, 40},{140, 160, 40, 40},
		{180, 160, 40, 40},{220, 160, 40, 40}
	};
	// Display AC:NL's fully Map.
	const std::vector<Structs::ButtonPos> acreMapPos = {
		{20, 0, 40, 40},{60, 0, 40, 40},{100, 0, 40, 40},
		{140, 0, 40, 40},{180, 0, 40, 40},{220, 0, 40, 40},{260, 0, 40, 40},

		{20, 40, 40, 40},{60, 40, 40, 40},{100, 40, 40, 40},
		{140, 40, 40, 40},{180, 40, 40, 40},{220, 40, 40, 40},{260, 40, 40, 40},

		{20, 80, 40, 40},{60, 80, 40, 40},{100, 80, 40, 40},
		{140, 80, 40, 40},{180, 80, 40, 40},{220, 80, 40, 40},{260, 80, 40, 40},

		{20, 120, 40, 40},{60, 120, 40, 40},{100, 120, 40, 40},
		{140, 120, 40, 40},{180, 120, 40, 40},{220, 120, 40, 40},{260, 120, 40, 40},

		{20, 160, 40, 40},{60, 160, 40, 40},{100, 160, 40, 40},
		{140, 160, 40, 40},{180, 160, 40, 40},{220, 160, 40, 40},{260, 160, 40, 40},

		{20, 200, 40, 40},{60, 200, 40, 40},{100, 200, 40, 40},
		{140, 200, 40, 40},{180, 200, 40, 40},{220, 200, 40, 40},{260, 200, 40, 40}
	};
	// Display AC:WW's full Town Map.
	const std::vector<Structs::ButtonPos> wwPos = {
		// First Line.
		{64, 16, 32, 32},
		{96, 16, 32, 32},
		{128, 16, 32, 32},
		{160, 16, 32, 32},
		{192, 16, 32, 32},
		{224, 16, 32, 32},
		// Second Line.
		{64, 48, 32, 32},
		{96, 48, 32, 32},
		{128, 48, 32, 32},
		{160, 48, 32, 32},
		{192, 48, 32, 32},
		{224, 48, 32, 32},
		// Third Line.
		{64, 80, 32, 32},
		{96, 80, 32, 32},
		{128, 80, 32, 32},
		{160, 80, 32, 32},
		{192, 80, 32, 32},
		{224, 80, 32, 32},
		// Fourth Line.
		{64, 112, 32, 32},
		{96, 112, 32, 32},
		{128, 112, 32, 32},
		{160, 112, 32, 32},
		{192, 112, 32, 32},
		{224, 112, 32, 32},
		// Fifth Line.
		{64, 144, 32, 32},
		{96, 144, 32, 32},
		{128, 144, 32, 32},
		{160, 144, 32, 32},
		{192, 144, 32, 32},
		{224, 144, 32, 32},
		// Sixth Line.
		{64, 176, 32, 32},
		{96, 176, 32, 32},
		{128, 176, 32, 32},
		{160, 176, 32, 32},
		{192, 176, 32, 32},
		{224, 176, 32, 32}
	};

	// Display Button.
	const std::vector<ButtonType> mainButtons = {
		{220, 25, 90, 30, "Acres"},
		{220, 55, 90, 30, "TempItem"},
		{220, 85, 90, 30, "Clear Weeds"},
		{220, 115, 90, 30, "Water Flowers"},
		{220, 145, 90, 30, "Item Misc"}
	};

	// Display Operations.
	const std::vector<ButtonType> operationBtn = {
		{95, 34, 130, 48, "Remove items"},
		{95, 97, 130, 48, "Fill Town"},
		{95, 159, 130, 48, "Replace Items"}
	};

	const std::vector<Structs::ButtonPos> icons = {
		{286, 213, 27, 27} // Back Icon.
	};
};

#endif
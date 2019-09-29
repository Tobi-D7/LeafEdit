	/*
*   This file is part of LeafEdit
*   Copyright (C) 2019 VoltZ, Epicpkmn11, Flame, RocketRobz, TotallyNotGuy
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

#include "core/villagerManagement.hpp"

#include "core/save/offsets.h"
#include "core/save/villager.h"
#include "core/save/save.h"

#include "gui/screens/villagerEditor.hpp"
#include "gui/screens/screenCommon.hpp"

#include <3ds.h>
#include <sys/stat.h>
#include <unistd.h>

extern Save* SaveFile;
extern std::vector<std::string> g_villagerDatabase;
extern std::string villagerNameText;

extern int getSpecies(int id);

void VillagerEditor::Draw(void) const
{
	if (editorMode == 1) {
		DrawSubMenu();
	} else if (editorMode == 2) {
		DrawVillagerSelection();
	}
}

void VillagerEditor::Logic(u32 hDown, u32 hHeld, touchPosition touch) {
	if (editorMode == 1) {
		SubMenuLogic(hDown, hHeld, touch);
	} else if (editorMode == 2) {
		VillagerSelectionLogic(hDown, hHeld, touch);
	}
}


void VillagerEditor::SubMenuLogic(u32 hDown, u32 hHeld, touchPosition touch) {

	// Selection Logic.
	if (hDown & KEY_RIGHT) {
		if(currentSlot < 5)	currentSlot++;
	} else if (hDown & KEY_LEFT) {
		if(currentSlot > 1)	currentSlot--;
	} else if (hDown & KEY_UP) {
		if(currentRow > 1)	currentRow--;
	} else if (hDown & KEY_DOWN) {
		if(subMenuPage == 4) {
		} else {
			if(currentRow < 2)	currentRow++;
		}
	}

	if (hDown & KEY_A) {
		if (currentSlot == 1 && currentRow == 1 && subMenuPage == 1) {
			editorMode = 2;
		}
	}

	if (hDown & KEY_R) {
		if(subMenuPage == 3) {
			if(currentRow == 2) {
				if(currentSlot == 1 || currentSlot == 2 || currentSlot == 3 || currentSlot == 4 || currentSlot == 5) {
					subMenuPage = 4;
					currentRow = 1;
					currentSlot = 5;
				}
			} else {
				subMenuPage++;
			}
		} else {
			if(subMenuPage < 4)	subMenuPage++;
		}
	} else if (hDown & KEY_L) {
		if(subMenuPage > 1)	subMenuPage--;
	}


	if (hDown & KEY_B) {
		Gui::screenBack();
		return;
	}
}

// Villager Editor Screen.
void VillagerEditor::DrawSubMenu(void) const
{
	std::string Title;
	Title += Lang::title;
	Title += " - ";
	Title += "Villager";
	Title += " ";
	Title += "Editor";
	Title += " - ";
	Title += "SubMenu";

	// Initial String.
	std::string currentPage = Lang::misc[0];
	currentPage += " ";

	// currentPage
	for (int i = 1; i < 5; i++) {
		if (subMenuPage == i) {
			currentPage += std::to_string(i);
		}
	}

	currentPage += " / 4";

	Gui::DrawTop();

	Gui::DrawString((400-Gui::GetStringWidth(0.8f, currentPage.c_str()))/2, 212, 0.8f, Config::barText, currentPage.c_str(), 400);
	Gui::DrawString((400-Gui::GetStringWidth(0.8f, Title.c_str()))/2, 2, 0.8f, Config::barText, Title.c_str(), 400);

	if (subMenuPage == 1) {
		Gui::sprite(0, sprites_villagerBox_idx, 5, 30);
		VillagerManagement::DrawVillager(93, 10, 28);
		std::string GroupOne = "Alligator";
		Gui::DrawString((400-Gui::GetStringWidth(0.55f, GroupOne.c_str()))/2-125-35, 83, 0.55f, Config::boxText, GroupOne.c_str(), 70);

		Gui::sprite(0, sprites_villagerBox_idx, 85, 30);
		VillagerManagement::DrawVillager(1, 90, 28);
		std::string GroupTwo = "Anteater";
		Gui::DrawString((400-Gui::GetStringWidth(0.55f, GroupTwo.c_str()))/2-45-35, 83, 0.55f, Config::boxText, GroupTwo.c_str(), 70);

		Gui::sprite(0, sprites_villagerBox_idx, 165, 30);
		VillagerManagement::DrawVillager(9, 170, 28);
		std::string GroupThree = "Bear";
		Gui::DrawString((400-Gui::GetStringWidth(0.55f, GroupThree.c_str()))/2+35-35, 83, 0.55f, Config::boxText, GroupThree.c_str(), 70);

		Gui::sprite(0, sprites_villagerBox_idx, 245, 30);
		VillagerManagement::DrawVillager(23, 250, 28);
		std::string GroupFour = "Bird";
		Gui::DrawString((400-Gui::GetStringWidth(0.55f, GroupFour.c_str()))/2+115-35, 83, 0.55f, Config::boxText, GroupFour.c_str(), 70);

		Gui::sprite(0, sprites_villagerBox_idx, 325, 30);
		VillagerManagement::DrawVillager(38, 330, 28);
		std::string GroupFive = "Bull";
		Gui::DrawString((400-Gui::GetStringWidth(0.55f, GroupFive.c_str()))/2+195-35, 83, 0.55f, Config::boxText, GroupFive.c_str(), 70);

		// Second Row!

		Gui::sprite(0, sprites_villagerBox_idx, 5, 140);
		VillagerManagement::DrawVillager(48, 10, 138);
		std::string GroupSix = "Cat";
		Gui::DrawString((400-Gui::GetStringWidth(0.55f, GroupSix.c_str()))/2-125-35, 193, 0.55f, Config::boxText, GroupSix.c_str(), 70);

		Gui::sprite(0, sprites_villagerBox_idx, 85, 140);
		VillagerManagement::DrawVillager(82, 90, 138);
		std::string GroupSeven = "Chicken";
		Gui::DrawString((400-Gui::GetStringWidth(0.55f, GroupSeven.c_str()))/2-45-35, 193, 0.55f, Config::boxText, GroupSeven.c_str(), 70);

		Gui::sprite(0, sprites_villagerBox_idx, 165, 140);
		VillagerManagement::DrawVillager(89, 170, 138);
		std::string GroupEight = "Cow";
		Gui::DrawString((400-Gui::GetStringWidth(0.55f, GroupEight.c_str()))/2+35-35, 193, 0.55f, Config::boxText, GroupEight.c_str(), 70);

		Gui::sprite(0, sprites_villagerBox_idx, 245, 140);
		VillagerManagement::DrawVillager(68, 250, 138);
		std::string GroupNine = "Cub";
		Gui::DrawString((400-Gui::GetStringWidth(0.55f, GroupNine.c_str()))/2+115-35, 193, 0.55f, Config::boxText, GroupNine.c_str(), 70);

		Gui::sprite(0, sprites_villagerBox_idx, 325, 140);
		VillagerManagement::DrawVillager(101, 330, 138);
		std::string GroupTen = "Deer";
		Gui::DrawString((400-Gui::GetStringWidth(0.55f, GroupTen.c_str()))/2+195-35, 193, 0.55f, Config::boxText, GroupTen.c_str(), 70);





	} else if (subMenuPage == 2) {

		Gui::sprite(0, sprites_villagerBox_idx, 5, 30);
		VillagerManagement::DrawVillager(115, 10, 28);
		std::string GroupEleven = "Dog";
		Gui::DrawString((400-Gui::GetStringWidth(0.55f, GroupEleven.c_str()))/2-125-35, 83, 0.55f, Config::boxText, GroupEleven.c_str(), 70);

		Gui::sprite(0, sprites_villagerBox_idx, 85, 30);
		VillagerManagement::DrawVillager(142, 90, 28);
		std::string GroupTwelve = "Duck";
		Gui::DrawString((400-Gui::GetStringWidth(0.55f, GroupTwelve.c_str()))/2-45-35, 83, 0.55f, Config::boxText, GroupTwelve.c_str(), 70);

		Gui::sprite(0, sprites_villagerBox_idx, 165, 30);
		VillagerManagement::DrawVillager(283, 170, 28);
		std::string GroupThirteen = "Eagle";
		Gui::DrawString((400-Gui::GetStringWidth(0.55f, GroupThirteen.c_str()))/2+35-35, 83, 0.55f, Config::boxText, GroupThirteen.c_str(), 70);

		Gui::sprite(0, sprites_villagerBox_idx, 245, 30);
		VillagerManagement::DrawVillager(148, 250, 28);
		std::string GroupFourteen = "Elephant";
		Gui::DrawString((400-Gui::GetStringWidth(0.55f, GroupFourteen.c_str()))/2+115-35, 83, 0.55f, Config::boxText, GroupFourteen.c_str(), 70);

		Gui::sprite(0, sprites_villagerBox_idx, 325, 30);
		VillagerManagement::DrawVillager(159, 330, 28);
		std::string GroupFifteen = "Frog";
		Gui::DrawString((400-Gui::GetStringWidth(0.55f, GroupFifteen.c_str()))/2+195-35, 83, 0.55f, Config::boxText, GroupFifteen.c_str(), 70);

		// Second Row!

		Gui::sprite(0, sprites_villagerBox_idx, 5, 140);
		VillagerManagement::DrawVillager(176, 10, 138);
		std::string GroupSixteen = "Goat";
		Gui::DrawString((400-Gui::GetStringWidth(0.55f, GroupSixteen.c_str()))/2-125-35, 193, 0.55f, Config::boxText, GroupSixteen.c_str(), 70);

		Gui::sprite(0, sprites_villagerBox_idx, 85, 140);
		VillagerManagement::DrawVillager(181, 90, 138);
		std::string GroupSeventeen = "Gorilla";
		Gui::DrawString((400-Gui::GetStringWidth(0.55f, GroupSeventeen.c_str()))/2-45-35, 193, 0.55f, Config::boxText, GroupSeventeen.c_str(), 70);

		Gui::sprite(0, sprites_villagerBox_idx, 165, 140);
		VillagerManagement::DrawVillager(190, 170, 138);
		std::string GroupEightteen = "Hamster";
		Gui::DrawString((400-Gui::GetStringWidth(0.55f, GroupEightteen.c_str()))/2+35-35, 193, 0.55f, Config::boxText, GroupEightteen.c_str(), 70);

		Gui::sprite(0, sprites_villagerBox_idx, 245, 140);
		VillagerManagement::DrawVillager(199, 250, 138);
		std::string GroupNineteen = "Hippo";
		Gui::DrawString((400-Gui::GetStringWidth(0.55f, GroupNineteen.c_str()))/2+115-35, 193, 0.55f, Config::boxText, GroupNineteen.c_str(), 70);

		Gui::sprite(0, sprites_villagerBox_idx, 325, 140);
		VillagerManagement::DrawVillager(208, 330, 138);
		std::string GroupTwenty = "Horse";
		Gui::DrawString((400-Gui::GetStringWidth(0.55f, GroupTwenty.c_str()))/2+195-35, 193, 0.55f, Config::boxText, GroupTwenty.c_str(), 70);


	} else if (subMenuPage == 3) {
		
		Gui::sprite(0, sprites_villagerBox_idx, 5, 30);
		VillagerManagement::DrawVillager(232, 10, 28);
		std::string GroupTwentyone = "Kangaroo";
		Gui::DrawString((400-Gui::GetStringWidth(0.55f, GroupTwentyone.c_str()))/2-125-35, 83, 0.55f, Config::boxText, GroupTwentyone.c_str(), 70);

		Gui::sprite(0, sprites_villagerBox_idx, 85, 30);
		VillagerManagement::DrawVillager(224, 90, 28);
		std::string GroupTwentytwo = "Koala";
		Gui::DrawString((400-Gui::GetStringWidth(0.55f, GroupTwentytwo.c_str()))/2-45-35, 83, 0.55f, Config::boxText, GroupTwentytwo.c_str(), 70);

		Gui::sprite(0, sprites_villagerBox_idx, 165, 30);
		VillagerManagement::DrawVillager(239, 170, 28);
		std::string GroupTwentythree = "Lion";
		Gui::DrawString((400-Gui::GetStringWidth(0.55f, GroupTwentythree.c_str()))/2+35-35, 83, 0.55f, Config::boxText, GroupTwentythree.c_str(), 70);

		Gui::sprite(0, sprites_villagerBox_idx, 245, 30);
		VillagerManagement::DrawVillager(247, 250, 28);
		std::string GroupTwentyfour = "Monkey";
		Gui::DrawString((400-Gui::GetStringWidth(0.55f, GroupTwentyfour.c_str()))/2+115-35, 83, 0.55f, Config::boxText, GroupTwentyfour.c_str(), 70);

		Gui::sprite(0, sprites_villagerBox_idx, 325, 30);
		VillagerManagement::DrawVillager(258, 330, 28);
		std::string GroupTwentyfive = "Mouse";
		Gui::DrawString((400-Gui::GetStringWidth(0.55f, GroupTwentyfive.c_str()))/2+195-35, 83, 0.55f, Config::boxText, GroupTwentyfive.c_str(), 70);

		// Second Row!

		Gui::sprite(0, sprites_villagerBox_idx, 5, 140);
		VillagerManagement::DrawVillager(272, 10, 138);
		std::string GroupTwentysix = "Octopus";
		Gui::DrawString((400-Gui::GetStringWidth(0.55f, GroupTwentysix.c_str()))/2-125-35, 193, 0.55f, Config::boxText, GroupTwentysix.c_str(), 70);

		Gui::sprite(0, sprites_villagerBox_idx, 85, 140);
		VillagerManagement::DrawVillager(278, 90, 138);
		std::string GroupTwentyseven = "Ostrich";
		Gui::DrawString((400-Gui::GetStringWidth(0.55f, GroupTwentyseven.c_str()))/2-45-35, 193, 0.55f, Config::boxText, GroupTwentyseven.c_str(), 70);

		Gui::sprite(0, sprites_villagerBox_idx, 165, 140);
		VillagerManagement::DrawVillager(300, 170, 138);
		std::string GroupTwentyeight = "Penguin";
		Gui::DrawString((400-Gui::GetStringWidth(0.55f, GroupTwentyeight.c_str()))/2+35-35, 193, 0.55f, Config::boxText, GroupTwentyeight.c_str(), 70);

		Gui::sprite(0, sprites_villagerBox_idx, 245, 140);
		VillagerManagement::DrawVillager(305, 250, 138);
		std::string GroupTwentynine = "Pig";
		Gui::DrawString((400-Gui::GetStringWidth(0.55f, GroupTwentynine.c_str()))/2+115-35, 193, 0.55f, Config::boxText, GroupTwentynine.c_str(), 70);

		Gui::sprite(0, sprites_villagerBox_idx, 325, 140);
		VillagerManagement::DrawVillager(337, 330, 138);
		std::string GroupThirty = "Rabbit";
		Gui::DrawString((400-Gui::GetStringWidth(0.55f, GroupThirty.c_str()))/2+195-35, 193, 0.55f, Config::boxText, GroupThirty.c_str(), 70);


	} else if (subMenuPage == 4) {
		
		Gui::sprite(0, sprites_villagerBox_idx, 5, 30);
		VillagerManagement::DrawVillager(342, 10, 28);
		std::string GroupThirtyone = "Rhino";
		Gui::DrawString((400-Gui::GetStringWidth(0.55f, GroupThirtyone.c_str()))/2-125-35, 83, 0.55f, Config::boxText, GroupThirtyone.c_str(), 70);

		Gui::sprite(0, sprites_villagerBox_idx, 85, 30);
		VillagerManagement::DrawVillager(349, 90, 28);
		std::string GroupThirtytwo = "Sheep";
		Gui::DrawString((400-Gui::GetStringWidth(0.55f, GroupThirtytwo.c_str()))/2-45-35, 83, 0.55f, Config::boxText, GroupThirtytwo.c_str(), 70);

		Gui::sprite(0, sprites_villagerBox_idx, 165, 30);
		VillagerManagement::DrawVillager(362, 170, 28);
		std::string GroupThirtythree = "Squirrel";
		Gui::DrawString((400-Gui::GetStringWidth(0.55f, GroupThirtythree.c_str()))/2+35-35, 83, 0.55f, Config::boxText, GroupThirtythree.c_str(), 70);

		Gui::sprite(0, sprites_villagerBox_idx, 245, 30);
		VillagerManagement::DrawVillager(382, 250, 28);
		std::string GroupThirtyfour = "Tiger";
		Gui::DrawString((400-Gui::GetStringWidth(0.55f, GroupThirtyfour.c_str()))/2+115-35, 83, 0.55f, Config::boxText, GroupThirtyfour.c_str(), 70);

		Gui::sprite(0, sprites_villagerBox_idx, 325, 30);
		VillagerManagement::DrawVillager(388, 330, 28);
		std::string GroupThirtyfive = "Wolf";
		Gui::DrawString((400-Gui::GetStringWidth(0.55f, GroupThirtyfive.c_str()))/2+195-35, 83, 0.55f, Config::boxText, GroupThirtyfive.c_str(), 70);
	}

	// Draw Selection.
	DrawSelection();

	Gui::DrawBottom();
}

void VillagerEditor::DrawSelection(void) const
{
		// First Row.
	if (currentSlot == 1 && currentRow == 1) {
		Gui::drawAnimatedSelector(5, 30, 70, 70, .030f, C2D_Color32(0, 0, 0, 0));
	} else if (currentSlot == 2 && currentRow == 1) {
		Gui::drawAnimatedSelector(85, 30, 70, 70, .030f, C2D_Color32(0, 0, 0, 0));
	} else if (currentSlot == 3 && currentRow == 1) {
		Gui::drawAnimatedSelector(165, 30, 70, 70, .030f, C2D_Color32(0, 0, 0, 0));
	} else if (currentSlot == 4 && currentRow == 1) {
		Gui::drawAnimatedSelector(245, 30, 70, 70, .030f, C2D_Color32(0, 0, 0, 0));
	} else if (currentSlot == 5 && currentRow == 1) {
		Gui::drawAnimatedSelector(325, 30, 70, 70, .030f, C2D_Color32(0, 0, 0, 0));

		// Second Row.
	} else if (currentSlot == 1 && currentRow == 2) {
		Gui::drawAnimatedSelector(5, 140, 70, 70, .030f, C2D_Color32(0, 0, 0, 0));
	} else if (currentSlot == 2 && currentRow == 2) {
		Gui::drawAnimatedSelector(85, 140, 70, 70, .030f, C2D_Color32(0, 0, 0, 0));
	} else if (currentSlot == 3 && currentRow == 2) {
		Gui::drawAnimatedSelector(165, 140, 70, 70, .030f, C2D_Color32(0, 0, 0, 0));
	} else if (currentSlot == 4 && currentRow == 2) {
		Gui::drawAnimatedSelector(245, 140, 70, 70, .030f, C2D_Color32(0, 0, 0, 0));
	} else if (currentSlot == 5 && currentRow == 2) {
		Gui::drawAnimatedSelector(325, 140, 70, 70, .030f, C2D_Color32(0, 0, 0, 0));
	}
}


void VillagerEditor::DrawVillagerSelection(void) const {
	Gui::DrawTop();
	u32 villager = 93;
	for (u32 y = 0; y < 2; y++) {
		for (u32 x = 0; x < 5; x++, villager++) {
			villagerNameText = g_villagerDatabase[villager];
			Gui::sprite(0, sprites_villagerBox_idx, 15 + x * 75, 40 + y * 90);
			VillagerManagement::DrawVillager(villager, 15 + x * 75, 35 + y * 90);
			Gui::DrawString(15 + x * 75, 95 + y * 90, 0.45f, WHITE, villagerNameText, 400);
		}
	}
}

void VillagerEditor::VillagerSelectionLogic(u32 hDown, u32 hHeld, touchPosition touch) {
	if (hDown & KEY_B) {
		editorMode = 1;
	}
}
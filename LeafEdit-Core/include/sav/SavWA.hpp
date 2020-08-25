/*
*   This file is part of LeafEdit-Core
*   Copyright (C) 2020 Universal-Team
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

#ifndef _LEAFEDIT_CORE_SAV_WA_HPP
#define _LEAFEDIT_CORE_SAV_WA_HPP

#include "Island.hpp"
#include "IslandWA.hpp"
#include "Player.hpp"
#include "PlayerWA.hpp"
#include "Sav.hpp"
#include "Shop.hpp"
#include "ShopWA.hpp"
#include "Town.hpp"
#include "TownWA.hpp"
#include "types.hpp"
#include "Villager.hpp"
#include "VillagerWA.hpp"

#include <string>

class Island;
class IslandWA;
class Player;
class PlayerWA;
class Shop;
class ShopWA;
class Town;
class TownWA;
class Villager;
class VillagerWA;
class SavWA : public Sav {
protected:
	std::shared_ptr<u8[]> dataPointer;
	u32 saveSize;
public:
	SavWA(std::shared_ptr<u8[]> dt, u32 ssize) : Sav(dt, ssize), dataPointer(dt), saveSize(ssize) { }
	virtual ~SavWA() {}
	void Finish(void) override;

	std::unique_ptr<Player> player(int player, int index = 0) const override;
	std::unique_ptr<Villager> villager(int villager) const override;
	std::unique_ptr<Town> town() const override;
	std::unique_ptr<Island> island() const override;
	std::unique_ptr<Shop> shop() const override;

	SaveType getType() const override { return SaveType::WA; }
	WWRegion getRegion() const override { return WWRegion::UNKNOWN; }
	
	int maxVillager() const override { return 9; }
private:
	u8 *savePointer() const {
		return dataPointer.get();
	}
};

#endif
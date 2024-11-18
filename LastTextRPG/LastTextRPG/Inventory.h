#pragma once
#include "pch.h"
#include "Item.h"

class Inventory {
public:
	void AddItem(Item* item);
	void Render(string type);
	Item* SelectEuip(string type);
	size_t WeaponSize() { return invenWeapon.size(); }
	size_t ArmorSize() { return invenArmor.size(); }
	int FightInventory();
private:
	unordered_map<int, Item*> invenPotion;
	unordered_map<int, int> invenPotionCount;

	unordered_map<int, Item*> invenWeapon;
	unordered_map<int, int> invenWeaponCount;

	unordered_map<int, Item*> invenArmor;
	unordered_map<int, int> invenArmorCount;
};
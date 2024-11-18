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
	unordered_map<string, Item*> invenPotion;
	unordered_map<string, int> invenPotionCount;

	unordered_map<string, Item*> invenWeapon;
	unordered_map<string, int> invenWeaponCount;

	unordered_map<string, Item*> invenArmor;
	unordered_map<string, int> invenArmorCount;
};
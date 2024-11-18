#pragma once
#include "pch.h"
#include "Item.h"
#include "Potion.h"
#include "Weapon.h"
#include "Armor.h"

class Inventory {
public:
	~Inventory();
public:
	void AddItem(Item* item);
	void Render(string type);
	Item* SelectEuip(string type);
	size_t WeaponSize() { return invenWeapon.size(); }
	size_t ArmorSize() { return invenArmor.size(); }
	int FightInventory();
private:
	unordered_map<int, Potion*> invenPotion;
	unordered_map<int, int> invenPotionCount;

	unordered_map<int, Weapon*> invenWeapon;
	unordered_map<int, int> invenWeaponCount;

	unordered_map<int, Armor*> invenArmor;
	unordered_map<int, int> invenArmorCount;
};
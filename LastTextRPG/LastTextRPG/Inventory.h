#pragma once
#include "pch.h"
#include "Item.h"

class Inventory {
public:
	void AddItem(Item* item);
	void useItem(const string& itemName);
	void RenderPotion();
	int RenderWeapon();
	int RenderArmor();
	void EquipItem(string type);
	void UnequipItem(string type);
private:
	unordered_map<string, Item*> inven;
	unordered_map<string, int> invenCount;
};
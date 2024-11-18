#pragma once
#include "Item.h"
class Armor :public Item {
public:
	Armor(int _index, const string& _strName, int _iPrice, int _defenseBoost) :Item(_index, _strName, _iPrice), iDefenseBoost(_defenseBoost) {}
	Armor(const Armor& other) : Item(other.itemIndex, other.strName, other.iPrice), iDefenseBoost(other.iDefenseBoost) {}
	int Get_DefenseBoost() { return iDefenseBoost; }
	virtual void use();
private:
	int iDefenseBoost;
};
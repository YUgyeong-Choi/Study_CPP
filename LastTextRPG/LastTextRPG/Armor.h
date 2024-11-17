#pragma once
#include "Item.h"
class Armor :public Item {
public:
	Armor(const string& _strName, int _iPrice, int _defenseBoost) :Item(_strName, _iPrice), iDefenseBoost(_defenseBoost) {}
	int Get_DefenseBoost() { return iDefenseBoost; }
	virtual void use();
private:
	int iDefenseBoost;
};
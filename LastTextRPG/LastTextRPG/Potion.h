#pragma once
#include "Item.h"

class Potion :public Item {
public:
	Potion(int _index, const string& _strName, int _iPrice, int _iHealAmount) :Item(_index, _strName, _iPrice), healAmount(_iHealAmount) {}
	int Get_healAmount() { return healAmount; }
	virtual void use();
private:
	int healAmount;
};
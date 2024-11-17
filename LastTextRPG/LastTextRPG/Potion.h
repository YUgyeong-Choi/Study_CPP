#pragma once
#include "Item.h"

class Potion :public Item {
public:
	Potion(const string& _strName, int _iPrice, int _iHealAmount) :Item(_strName, _iPrice), healAmount(_iHealAmount) {}
	virtual void use();
public:
	int healAmount;
};
#pragma once
#include "Equipment.h"
class Armor :public Equipment {
public:
	Armor(const string& _strName, int _iPrice, int _defenseBoost) :Equipment(_strName, _iPrice, _defenseBoost) {}

	virtual void use();
};
#pragma once
#include "Equipment.h"

class Weapon :public Equipment {
public:
	Weapon(const string& _strName, int _iPrice, int _attackBoost) :Equipment(_strName, _iPrice, _attackBoost) {}

	virtual void use();
	virtual void equip();
	virtual void unequip();
};
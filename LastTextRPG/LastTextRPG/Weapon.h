#pragma once
#include "Item.h"
class Weapon :public Item{
public:
	Weapon(int _index, const string& _strName, int _iPrice, int _attackBoost) :Item(_index, _strName, _iPrice), iAttackBoost(_attackBoost) {}
	int Get_AttackBoost() { return iAttackBoost; }
	virtual void use();

private:
	int iAttackBoost;
};
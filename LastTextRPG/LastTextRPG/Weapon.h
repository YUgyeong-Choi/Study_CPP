#pragma once
#include "Item.h"
class Weapon :public Item{
public:
	Weapon(int _index, const string& _strName, int _iPrice, int _attackBoost) :Item(_index, _strName, _iPrice), iAttackBoost(_attackBoost) {}
	Weapon(const Weapon& other) : Item(other.itemIndex, other.strName, other.iPrice), iAttackBoost(other.iAttackBoost) {}
	int Get_AttackBoost() { return iAttackBoost; }
	virtual void use();

private:
	int iAttackBoost;
};
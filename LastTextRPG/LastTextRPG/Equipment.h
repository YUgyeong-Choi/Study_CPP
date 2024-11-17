#pragma once
#include "Item.h"

class Equipment : public Item {
public:
	Equipment(const string& _strName, int _iPrice, int _statBoost) :Item(_strName, _iPrice), statBoost(_statBoost) {}
	
	virtual void use() PURE;
public:
	int statBoost;
};
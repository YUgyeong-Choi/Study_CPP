#pragma once
#include "Item.h"
#include "pch.h"
class WearItem :public Item {
public:
	WearItem();
	WearItem(const char _szName[32], int _iHp, int _iAttack, int _iPrice, ITEMTYPE _It_Type, STATE _IsWear);
	virtual ~WearItem();

private:
	STATE IsWear;
};
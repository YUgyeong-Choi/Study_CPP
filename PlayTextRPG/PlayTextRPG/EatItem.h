#pragma once
#include "Item.h"
#include "pch.h"
class EatItem :public Item {
public:
	EatItem();
	EatItem(const char _szName[32], int _iHp, int _iAttack, int _iPrice, ITEMTYPE _It_Type);
	virtual ~EatItem();

};
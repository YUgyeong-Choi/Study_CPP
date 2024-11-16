#pragma once
#include "Define.h"
class Item {
public:
	Item();
	Item(const char _szName[32], int _iHp,int _iAttack, int _iPrice, ITEMTYPE _It_Type);
	Item(const char _szName[32], int _iHp,int _iAttack, int _iPrice, ITEMTYPE _It_Type, STATE _IsWear);
	~Item();
public:
	ItemInfo Get_ItemInfo() {return m_Item;}
protected:
	ItemInfo m_Item;
};
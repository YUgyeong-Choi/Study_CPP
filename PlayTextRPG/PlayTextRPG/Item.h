#pragma once
#include "Define.h"
class Item {
public:
	Item();
	Item(const char _szName[32], int _iHp,int _iAttack, int _iPrice, ITEMTYPE _iIT_Type);
	~Item();
public:
	ItemInfo Get_ItemInfo() {return m_Item;}
private:
	ItemInfo m_Item;
	ITEMTYPE m_ItemType;
};
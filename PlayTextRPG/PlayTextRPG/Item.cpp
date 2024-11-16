#include "Item.h"
#include "pch.h"

Item::Item()
{
	memset(&m_Item, 0, sizeof(m_Item));
}

Item::Item(const char _szName[32], int _iHp, int _iAttack, int _iPrice, ITEMTYPE _iIt_Type)
{
}

Item::Item(const char _szName[32], int _iHp, int _iAttack, int _iPrice, ITEMTYPE _It_Type, STATE _IsWear)
{
}


Item::~Item()
{
}
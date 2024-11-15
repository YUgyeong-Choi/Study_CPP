#include "Item.h"
#include "pch.h"

Item::Item()
{
	memset(&m_Item, 0, sizeof(m_Item));
	m_ItemType = NONE;
}

Item::Item(const char _szName[32], int _iHp, int _iAttack, int _iPrice, ITEMTYPE _iIt_Type)
{
	strcpy_s(m_Item.szName, sizeof(m_Item.szName), _szName);
	m_Item.iHp = _iHp;
	m_Item.iAttack = _iAttack;
	m_Item.iPrice = _iPrice;
	m_ItemType = _iIt_Type;
}

Item::~Item()
{
}
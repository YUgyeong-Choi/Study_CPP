#include "WearItem.h"

WearItem::WearItem()
{
}

WearItem::WearItem(const char _szName[32], int _iHp, int _iAttack, int _iPrice, ITEMTYPE _It_Type, STATE _IsWear)
{
	strcpy_s(m_Item.szName, sizeof(m_Item.szName), _szName);
	m_Item.iHp = _iHp;
	m_Item.iAttack = _iAttack;
	m_Item.iPrice = _iPrice;
	m_Item.type = _It_Type;
	IsWear = _IsWear;

}

WearItem::~WearItem()
{
}

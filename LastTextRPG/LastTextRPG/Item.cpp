#include "Item.h"
#include "pch.h"

Item::Item(int _index, const string& _strName, int _iPrice)
{
	itemIndex = _index;
	strName = _strName;
	iPrice = _iPrice;
}

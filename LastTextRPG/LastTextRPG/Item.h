#pragma once
#include "Define.h"

class Item {
public:
	Item(int _index, const string& _strName, int _iPrice);
public:
	string Get_ItemName() { return strName; }
	int Get_ItemIndex() { return itemIndex; }
	int Get_ItemPrice() { return iPrice; }
	virtual void use() PURE;
protected:
	int itemIndex;
	string strName;
	int iPrice;

};
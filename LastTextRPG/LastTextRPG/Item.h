#pragma once
#include "Define.h"

class Item {
public:
	Item(const string& _strName, int _iPrice);
public:
	string Get_ItemName() { return strName; }
	int Get_ItemPrice() { return iPrice; }
	virtual void use() PURE;
protected:
	string strName;
	int iPrice;

};
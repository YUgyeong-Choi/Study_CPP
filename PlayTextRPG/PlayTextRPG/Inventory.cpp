#include "Inventory.h"
#include "pch.h"

Inventory::Inventory()
{
}

Inventory::~Inventory()
{
}

void Inventory::BuyItem()
{
}

void Inventory::Render()
{
	for (auto a : ItemCount) {
		if (a.second > 0) {
			cout<< ItemsInfo[a.first]->Get_ItemInfo().szName << endl;
			cout<< "°³¼ö: "<<a.second << endl;
		}
		
	}
}

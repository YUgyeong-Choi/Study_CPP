#pragma once
#include "Define.h"
class Inventory {
public:
	Inventory();
public:
	void Render();
	ItemInfo* Get_InventoryInfo() { return items; }
	void Fight_Render();
	void Add_Items(int _index);
private:
	ItemInfo items[6];
};
#pragma once
#include "Item.h"

class Inventory {
public:
	Inventory();
	~Inventory();
public:
	void BuyItem();
	void Render();
	//아이템 사용
	//보유 아이템 Render
private:
	map<char[32], Item*> ItemsInfo;
	map<char[32], int> ItemCount;
};
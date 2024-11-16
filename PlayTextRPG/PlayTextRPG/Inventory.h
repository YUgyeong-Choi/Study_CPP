#pragma once
#include "Item.h"

class Inventory {
public:
	Inventory();
	~Inventory();
public:
	void BuyItem();
	void Render();
	//������ ���
	//���� ������ Render
private:
	map<char[32], Item*> ItemsInfo;
	map<char[32], int> ItemCount;
};
#pragma once
#include "Item.h"
#include "Player.h"
#include "Inventory.h"
class Shop {
public:
	Shop();
	virtual ~Shop();
public:
	void Set_PlayerInfo(Player* _pPlayer) { m_pPlayer = _pPlayer; }
	void Update();
	void Release();
protected:
	Player* m_pPlayer;
	vector<Item*> shopItems;
};
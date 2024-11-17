#pragma once
#include "Player.h"
#include "Shop.h"

class ShopMenu{
public:
	ShopMenu();
	~ShopMenu();
public:
	void Update();
	void Release();
	void Set_PlayerInfo(Player* _pPlayer) { m_pPlayer = _pPlayer; }
private:
	Player* m_pPlayer;
	Shop* m_shop;
};
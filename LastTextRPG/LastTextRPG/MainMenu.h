#pragma once
#include "Player.h"
#include "ShopMenu.h"
#include "InvenMenu.h"

class MainMenu {
public:
	MainMenu();
	~MainMenu();
public:
	void Update();
	void Release();
	void Set_PlayerInfo(Player* _pPlayer) { m_pPlayer = _pPlayer; }
private:
	Player* m_pPlayer;
	ShopMenu* shopMenu;
	InvenMenu* invenMenu;
};
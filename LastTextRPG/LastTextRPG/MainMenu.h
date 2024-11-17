#pragma once
#include "Player.h"
#include "Field.h"
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
	Field* field;
	ShopMenu* shopMenu;
	InvenMenu* invenMenu;
};
#pragma once
#include "Player.h"

class MainMenu {
public:
	MainMenu();
	~MainMenu();
public:
	void Update();
	void Set_PlayerInfo(Player* _pPlayer) { m_pPlayer = _pPlayer; }
private:
	Player* m_pPlayer;
};
#pragma once
#include "Player.h"
#include "Field.h"

class Mainmenu {
public:
	Mainmenu();
	~Mainmenu();
public:
	void Release();
	void Update();
	void Set_PlayerInfo(Player* pPlayer);
private:
	Player* m_pPlayer;
	Field* m_pField;
};
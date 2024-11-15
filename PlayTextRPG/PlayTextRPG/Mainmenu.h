#pragma once
#include "Player.h"
#include "Field.h"
#include "Storemenu.h"
#include "Minigame.h"

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
	Storemenu* m_pStoremenu;
	Minigame* m_pMinigame;
};
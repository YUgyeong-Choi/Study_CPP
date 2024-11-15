#pragma once
#include "Define.h"
#include "Player.h"
#include "Store.h"

class Storemenu {
public:
	Storemenu();
public:
	void Update();
	void Set_PlayerInfo(Player* _pPlayer);
private:
	Player* m_pPlayer;
	Store* m_pStore;
};
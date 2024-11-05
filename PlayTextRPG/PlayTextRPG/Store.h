#pragma once
#include "Define.h"
#include "Player.h"

class Store {
public:
	Store();
public:
	void Update();
	void Set_PlayerInfo(Player* _pPlayer);
private:
	Player* m_pPlayer;
	ItemInfo items[7];
};
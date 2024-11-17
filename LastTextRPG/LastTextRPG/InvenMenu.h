#pragma once
#include "Player.h"
class InvenMenu {
public:
	InvenMenu() :m_pPlayer(nullptr) {}
	void Set_PlayerInfo(Player* _pPlayer) { m_pPlayer = _pPlayer; }
	void Update();
private:
	Player* m_pPlayer;
};
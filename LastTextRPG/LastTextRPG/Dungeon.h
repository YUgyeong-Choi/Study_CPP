#pragma once
#include "Player.h"
#include "Monster.h"

class Dungeon {
public:
	Dungeon();
	virtual ~Dungeon();
public:
	void Update();
	void Release();
	void Set_PlayerInfo(Player* _pPlayer);
	virtual Monster* Set_Monster();
private:
	void Render_Map();
	bool Check_Clear();
	bool Fight();
private:
	char map[5][5][2];
	Player* m_pPlayer;
	Monster* m_pMonster;
	int coolTime;
	int originAttack;
};
#pragma once
#include "Player.h"
#include "Monster.h"

class LowDungeon {
public:
	LowDungeon();
	~LowDungeon();
public:
	void Update();
	void Release();
	void Set_PlayerInfo(Player* _pPlayer);
private:
	void Render_Map();
	bool Check_Clear();
	void Fight(Player* _pPlayer, Monster* _pMonster);
private:
	char map[5][5][2];
	Player* m_pPlayer;
	Monster* m_pMonster;
};
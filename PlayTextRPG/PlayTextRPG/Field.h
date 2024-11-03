#pragma once
#include "Player.h"
#include "LowDungeon.h"
#include "MiddleDungeon.h"
#include "HighDungeon.h"


class Field {
public:
	enum Stage{LOW = 1, MIDDLE, HIGH};
public:
	Field();
	~Field();
public:
	void Update();
	void Release();
	void Set_PlayerInfo(Player* _pPlayer);
private:
	Player* m_pPlayer;
	Dungeon* m_pDungeon;
};
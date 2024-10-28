#pragma once
#include "Monster.h"
#include "Player.h"

class Field {
public:
	Field();
	~Field();
public:
	void Initialize();
	void Update();
	void Release();
	void Set_Player(Player* _pPlayer);
private:
	void Fight();
private:
	Player* m_pPlayer;
	Monster* m_pMonster;
};
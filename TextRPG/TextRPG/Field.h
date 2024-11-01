#pragma once
#include "Monster.h"
#include "Player.h"
#include "Obj.h"

class Field {
public:
	Field();
	~Field();
public:
	void Initialize();
	void Update();
	void Release();
	void Set_Player(Obj* _pPlayer);
private:
	void Fight();
private:
	Obj* m_pPlayer;
	Obj* m_pMonster;
};
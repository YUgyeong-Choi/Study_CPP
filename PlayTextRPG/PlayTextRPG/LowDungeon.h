#pragma once
#include "Dungeon.h"
#include "Player.h"
#include "Monster.h"

class LowDungeon :public Dungeon{
public:
	LowDungeon();
	~LowDungeon();
public:
	virtual Monster* Set_Monster();
};
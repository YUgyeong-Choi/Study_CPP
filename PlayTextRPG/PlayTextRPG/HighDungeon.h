#pragma once
#include "Dungeon.h"

class HighDungeon :public Dungeon {
public:
	HighDungeon();
	~HighDungeon();
public:
	Monster* Set_Monster();
};
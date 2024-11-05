#pragma once
#include "Player.h"

class Fighter :public Player {
public:
	Fighter();
	~Fighter();
public:
	void Skill1();
	int Skill2();
};
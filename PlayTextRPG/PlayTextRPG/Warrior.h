#pragma once
#include "Player.h"

class Warrior :public Player {
public:
	Warrior();
	~Warrior();
public:
	void Skill1();
	int Skill2();
};
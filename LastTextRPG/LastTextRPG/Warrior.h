#pragma once
#include "Player.h"
class Warrior :public Player {
public:
	Warrior();
	~Warrior();
public:
	virtual void Skill1();
	virtual int Skill2();
};
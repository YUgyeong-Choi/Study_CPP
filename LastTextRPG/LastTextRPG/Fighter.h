#pragma once
#include "Player.h"
class Fighter :public Player {
public:
	Fighter();
	~Fighter();
public:
	virtual void Skill1();
	virtual int Skill2();
};
#pragma once
#include "Player.h"
class Mage :public Player {
public: 
	Mage();
	~Mage();
public:
	virtual void Skill1();
	virtual int Skill2();
};
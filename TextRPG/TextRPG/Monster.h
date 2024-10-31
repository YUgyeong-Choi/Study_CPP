#pragma once
#include "Define.h"
#include "Obj.h"

class Monster :public Obj{
public:
	Monster();
	Monster(const char* pName, int _iHp, int _iAttack);
	~Monster();
};
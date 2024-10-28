#pragma once
#include "Define.h"

class Monster {
public:
	Monster(const char* pName, int _iHp, int _iAttack);
	~Monster();
public:
	void Initialize();
	void Release();
	void Render();
	INFO Get_Info() { return info; }
	void Set_Damage(int _iAttack) { info.m_iHp -= _iAttack; }
private:
	INFO info;
};
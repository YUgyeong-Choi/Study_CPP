#pragma once
#include "Define.h"

class Obj {
public:
	Obj();
	Obj(const char* pName, int _iHp, int _iAttack);
	~Obj();
public:
	void Render();
	INFO Get_Info() const { return m_info; }
	void Set_Damage(int _iAttack) { m_info.m_iHp -= _iAttack; }

protected:
	INFO m_info;
};


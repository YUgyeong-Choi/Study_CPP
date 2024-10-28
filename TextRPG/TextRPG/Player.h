#pragma once
#include "Define.h"

class Player {
public:
	enum JOB{WARRIOR=1, MAGE, THIEF, END};
public:
	Player();
	~Player();
public:
	void Release();
	bool Load_Data();
	bool Save_Data();
	void Create_Obj(const char* pName, int _iHp, int _iAttack);
	bool Select_Job();
	void Render();
	INFO Get_Info() { return info; }
	void Set_Damage(int _iAttack) { info.m_iHp -= _iAttack; }
	void Set_Hp(int _iHp) { info.m_iHp = _iHp; }
private:
	INFO info;
};
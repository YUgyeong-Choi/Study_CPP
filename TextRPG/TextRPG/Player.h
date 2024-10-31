#pragma once
#include "Define.h"
#include "Obj.h"

class Player:public Obj{
public:
	enum JOB{WARRIOR=1, MAGE, THIEF, END};
public:
	Player();
	Player(const char* pName, int _iHp, int _iAttack);
	~Player();
public:
	bool Load_Data();
	bool Save_Data();
	void Create_Obj(const char* pName, int _iHp, int _iAttack);
	bool Select_Job();
	void Set_Hp(int _iHp) { m_info.m_iHp = _iHp; }
};
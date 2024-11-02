#pragma once
#include "Define.h"

class Player {
public:
	Player();
	~Player();
public:
	void Render();
	PlayerInfo Get_Info() { return m_playerInfo; }
	void Set_Player_Name(const char* szName);
	void Set_Hp(int _iAttack) { m_playerInfo.iHp -= _iAttack; }
	virtual void InitializeStat();
	virtual void Skill1();
	virtual void Skill2();
	virtual void Render_Detail();
protected:
	PlayerInfo 	m_playerInfo;
};
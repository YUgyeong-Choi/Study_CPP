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
	void Set_FullHp() {m_playerInfo.iHp = iMaxHp; }
	void Set_OriginAttack() { m_playerInfo.iAttack = iMaxAttack; }
	void Set_Stage() { m_playerInfo.Stage++; }
	virtual void InitializeStat();
	virtual void Skill1();
	virtual int Skill2();
	virtual void Render_Detail();
protected:
	PlayerInfo 	m_playerInfo;
	int iMaxHp;
	int iMaxAttack;
};
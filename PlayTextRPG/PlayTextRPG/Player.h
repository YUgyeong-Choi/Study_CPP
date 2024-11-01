#pragma once
#include "Define.h"

class Player {
public:
	Player();
	~Player();
public:
	PlayerInfo Get_Info() { return m_playerInfo; }
	virtual void InitializeStat();
	virtual void Skill1();
	virtual void Skill2();
protected:
	PlayerInfo 	m_playerInfo;
};
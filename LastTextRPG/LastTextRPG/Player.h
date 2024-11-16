#pragma once
#include "Define.h"

class Player {
public:
	Player();
	virtual ~Player();
public:
	void Set_Player_Name(const char* _szName);
	PlayerInfo Get_PlayerInfo() { return m_PlayerInfo; }
	virtual void Skill1() PURE;
	virtual int Skill2() PURE;
protected:
	PlayerInfo m_PlayerInfo;
};
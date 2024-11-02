#pragma once
#include "Define.h"

class Monster {
public:
	Monster();
public:
	MonsterInfo Get_Info() { return m_monsterInfo; }
	void Render();
	void Set_Hp(int _iAttack) { m_monsterInfo.iHp -= _iAttack; }
	//virtual void Skill1();
private:
	MonsterInfo m_monsterInfo;
};

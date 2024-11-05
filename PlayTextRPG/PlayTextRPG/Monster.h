#pragma once
#include "Define.h"

class Monster {
public:
	Monster(const char* name, int hp, int attack, int money);
public:
	MonsterInfo Get_Info() { return m_monsterInfo; }
	void Render();
	void Set_Hp(int _iAttack) { m_monsterInfo.iHp -= _iAttack; }
private:
	MonsterInfo m_monsterInfo;
};

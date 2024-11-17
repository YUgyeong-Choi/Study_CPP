#pragma once
#include "pch.h"
#include "Define.h"

class Monster {
public:
	Monster(const string& name, int hp, int attack, int money);
public:
	MonsterInfo Get_MonsterInfo() { return m_monsterInfo; }
	void Render();
	void Set_Hp(int _iAttack) { m_monsterInfo.iHp += _iAttack; }
private:
	MonsterInfo m_monsterInfo;
};
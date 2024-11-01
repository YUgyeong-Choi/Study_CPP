#include "Warrior.h"
#include "pch.h"

Warrior::Warrior()
{
	strcpy_s(m_playerInfo.Job, sizeof(m_playerInfo.Job), "ภüป็");
	m_playerInfo.iHp = 300;
	m_playerInfo.iAttack = 25;
}

Warrior::~Warrior()
{
}

void Warrior::Skill1()
{
}

void Warrior::Skill2()
{
}

#include "Fighter.h"
#include "pch.h"

Fighter::Fighter()
{
	strcpy_s(m_playerInfo.Job, sizeof(m_playerInfo.Job), "∞›≈ı∞°");
	m_playerInfo.iHp = 350;
	m_playerInfo.iAttack = 20;
}

Fighter::~Fighter()
{
}

void Fighter::Skill1()
{
}

void Fighter::Skill2()
{
}

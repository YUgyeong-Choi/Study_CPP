#include "Fighter.h"
#include "pch.h"

Fighter::Fighter()
{
	m_PlayerInfo.job = FIGHTER;
	m_PlayerInfo.iHp = 130;
	m_PlayerInfo.iAttack = 30;

	// 첫 번째 스킬
	strcpy_s(m_PlayerInfo.skills[0].skillName, sizeof(m_PlayerInfo.skills[0].skillName), "연속 공격 ");
	strcpy_s(m_PlayerInfo.skills[0].skillInfo, sizeof(m_PlayerInfo.skills[0].skillInfo), "격투가가 연속으로 2회 공격한다");
	m_PlayerInfo.skills[0].cool = 3;

	// 두 번째 스킬
	strcpy_s(m_PlayerInfo.skills[1].skillName, sizeof(m_PlayerInfo.skills[1].skillName), "회피");
	strcpy_s(m_PlayerInfo.skills[1].skillInfo, sizeof(m_PlayerInfo.skills[1].skillInfo), "2턴간 몬스터의 공격을 회피한다");
	m_PlayerInfo.skills[1].cool = 2;

	iMaxHp = m_PlayerInfo.iHp;
}

Fighter::~Fighter()
{
}

void Fighter::Skill1()
{
}

int Fighter::Skill2()
{
	return 0;
}

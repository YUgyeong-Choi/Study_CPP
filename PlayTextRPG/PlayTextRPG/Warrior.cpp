#include "Warrior.h"
#include "pch.h"

Warrior::Warrior()
{
	strcpy_s(m_playerInfo.Job, sizeof(m_playerInfo.Job), "전사");
	m_playerInfo.iHp = 300;
	m_playerInfo.iAttack = 25;

	// 첫 번째 스킬
	strcpy_s(m_playerInfo.skills[0].skillName, sizeof(m_playerInfo.skills[0].skillName), "광폭화");
	strcpy_s(m_playerInfo.skills[0].skillInfo, sizeof(m_playerInfo.skills[0].skillInfo), "일정 시간 동안 공격력이 30% 증가하지만, 받는 피해가 15% 증가");

	// 두 번째 스킬
	strcpy_s(m_playerInfo.skills[1].skillName, sizeof(m_playerInfo.skills[1].skillName), "최후의 일격");
	strcpy_s(m_playerInfo.skills[1].skillInfo, sizeof(m_playerInfo.skills[1].skillInfo), "강력한 일격으로 적에게 큰 피해를 줌. HP가 낮을수록 피해가 더 강력해짐");
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

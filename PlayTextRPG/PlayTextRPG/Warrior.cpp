#include "Warrior.h"
#include "pch.h"

Warrior::Warrior()
{
	strcpy_s(m_playerInfo.Job, sizeof(m_playerInfo.Job), "전사");
	m_playerInfo.iHp = 150;
	m_playerInfo.iAttack = 25;

	// 첫 번째 스킬
	strcpy_s(m_playerInfo.skills[0].skillName, sizeof(m_playerInfo.skills[0].skillName), "강타");
	strcpy_s(m_playerInfo.skills[0].skillInfo, sizeof(m_playerInfo.skills[0].skillInfo), "3판 동안 추가피해 5");
	m_playerInfo.skills[0].cool = 4;

	// 두 번째 스킬
	strcpy_s(m_playerInfo.skills[1].skillName, sizeof(m_playerInfo.skills[1].skillName), "최후의 일격");
	strcpy_s(m_playerInfo.skills[1].skillInfo, sizeof(m_playerInfo.skills[1].skillInfo), "다음 공격이 강력한 일격으로 적에게 2배 강한 피해를 줌");
	m_playerInfo.skills[1].cool = 6;


	iOriginHp = m_playerInfo.iHp;
	iOriginAttack = m_playerInfo.iAttack;
	iUpgradeAttack = iOriginAttack;
}

Warrior::~Warrior()
{
}

void Warrior::Skill1()
{
	m_playerInfo.iAttack += 5;
}

int Warrior::Skill2()
{
	return m_playerInfo.iAttack * 2;
}

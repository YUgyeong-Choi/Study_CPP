#include "Mage.h"
#include "pch.h"

Mage::Mage()
{
	m_PlayerInfo.job = MAGE;
	m_PlayerInfo.iHp = 100;
	m_PlayerInfo.iAttack = 35;

	// 첫 번째 스킬
	strcpy_s(m_PlayerInfo.skills[0].skillName, sizeof(m_PlayerInfo.skills[0].skillName), "화염구 ");
	strcpy_s(m_PlayerInfo.skills[0].skillInfo, sizeof(m_PlayerInfo.skills[0].skillInfo), "화염구를 날려 10의 추가피해를 줌");
	m_PlayerInfo.skills[0].cool = 3;

	// 두 번째 스킬
	strcpy_s(m_PlayerInfo.skills[1].skillName, sizeof(m_PlayerInfo.skills[1].skillName), "최후의 일격");
	strcpy_s(m_PlayerInfo.skills[1].skillInfo, sizeof(m_PlayerInfo.skills[1].skillInfo), "다음 공격이 강력한 일격으로 적에게 2배 강한 피해를 줌");
	m_PlayerInfo.skills[1].cool = 5;
}

Mage::~Mage()
{
}

void Mage::Skill1()
{
}

int Mage::Skill2()
{
	return 0;
}

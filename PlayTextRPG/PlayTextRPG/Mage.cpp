#include "Mage.h"
#include "pch.h"

Mage::Mage()
{
	strcpy_s(m_playerInfo.Job, sizeof(m_playerInfo.Job), "마법사");
	m_playerInfo.iHp = 100;
	m_playerInfo.iAttack = 35;

	// 첫 번째 스킬
	strcpy_s(m_playerInfo.skills[0].skillName, sizeof(m_playerInfo.skills[0].skillName), "화염구 ");
	strcpy_s(m_playerInfo.skills[0].skillInfo, sizeof(m_playerInfo.skills[0].skillInfo), "화염구를 날려 10의 추가피해를 줌");
	m_playerInfo.skills[0].cool = 3;

	// 두 번째 스킬
	strcpy_s(m_playerInfo.skills[1].skillName, sizeof(m_playerInfo.skills[1].skillName), "최후의 일격");
	strcpy_s(m_playerInfo.skills[1].skillInfo, sizeof(m_playerInfo.skills[1].skillInfo), "다음 공격이 강력한 일격으로 적에게 2배 강한 피해를 줌");
	m_playerInfo.skills[1].cool = 5;


	iOriginHp = m_playerInfo.iHp;
	iOriginAttack = m_playerInfo.iAttack;
	iUpgradeAttack = iOriginAttack;
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

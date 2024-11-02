#include "Mage.h"
#include "pch.h"

Mage::Mage()
{
	strcpy_s(m_playerInfo.Job, sizeof(m_playerInfo.Job), "¸¶¹ý»ç");
	m_playerInfo.iHp = 200;
	m_playerInfo.iAttack = 35;
}

Mage::~Mage()
{
}

void Mage::Skill1()
{
}

void Mage::Skill2()
{
}

#include "Mage.h"
#include "pch.h"

Mage::Mage()
{
	m_PlayerInfo.job = MAGE;
	m_PlayerInfo.iHp = 100;
	m_PlayerInfo.iAttack = 35;

	// ù ��° ��ų
	strcpy_s(m_PlayerInfo.skills[0].skillName, sizeof(m_PlayerInfo.skills[0].skillName), "ȭ���� ");
	strcpy_s(m_PlayerInfo.skills[0].skillInfo, sizeof(m_PlayerInfo.skills[0].skillInfo), "ȭ������ ���� 10�� �߰����ظ� ��");
	m_PlayerInfo.skills[0].cool = 3;

	// �� ��° ��ų
	strcpy_s(m_PlayerInfo.skills[1].skillName, sizeof(m_PlayerInfo.skills[1].skillName), "������ �ϰ�");
	strcpy_s(m_PlayerInfo.skills[1].skillInfo, sizeof(m_PlayerInfo.skills[1].skillInfo), "���� ������ ������ �ϰ����� ������ 2�� ���� ���ظ� ��");
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

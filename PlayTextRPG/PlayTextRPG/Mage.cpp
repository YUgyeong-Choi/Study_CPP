#include "Mage.h"
#include "pch.h"

Mage::Mage()
{
	strcpy_s(m_playerInfo.Job, sizeof(m_playerInfo.Job), "������");
	m_playerInfo.iHp = 100;
	m_playerInfo.iAttack = 35;

	// ù ��° ��ų
	strcpy_s(m_playerInfo.skills[0].skillName, sizeof(m_playerInfo.skills[0].skillName), "ȭ���� ");
	strcpy_s(m_playerInfo.skills[0].skillInfo, sizeof(m_playerInfo.skills[0].skillInfo), "ȭ������ ���� 10�� �߰����ظ� ��");
	m_playerInfo.skills[0].cool = 3;

	// �� ��° ��ų
	strcpy_s(m_playerInfo.skills[1].skillName, sizeof(m_playerInfo.skills[1].skillName), "������ �ϰ�");
	strcpy_s(m_playerInfo.skills[1].skillInfo, sizeof(m_playerInfo.skills[1].skillInfo), "���� ������ ������ �ϰ����� ������ 2�� ���� ���ظ� ��");
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

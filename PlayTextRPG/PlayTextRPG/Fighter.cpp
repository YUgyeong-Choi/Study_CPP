#include "Fighter.h"
#include "pch.h"

Fighter::Fighter()
{
	strcpy_s(m_playerInfo.Job, sizeof(m_playerInfo.Job), "������");
	m_playerInfo.iHp = 130;
	m_playerInfo.iAttack = 30;

	// ù ��° ��ų
	strcpy_s(m_playerInfo.skills[0].skillName, sizeof(m_playerInfo.skills[0].skillName), "���� ���� ");
	strcpy_s(m_playerInfo.skills[0].skillInfo, sizeof(m_playerInfo.skills[0].skillInfo), "�������� �������� 2ȸ �����Ѵ�");
	m_playerInfo.skills[0].cool = 3;

	// �� ��° ��ų
	strcpy_s(m_playerInfo.skills[1].skillName, sizeof(m_playerInfo.skills[1].skillName), "ȸ��");
	strcpy_s(m_playerInfo.skills[1].skillInfo, sizeof(m_playerInfo.skills[1].skillInfo), "2�ϰ� ������ ������ ȸ���Ѵ�");
	m_playerInfo.skills[1].cool = 2;


	iOriginHp = m_playerInfo.iHp;
	iOriginAttack = m_playerInfo.iAttack;
	iUpgradeAttack = iOriginAttack;
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

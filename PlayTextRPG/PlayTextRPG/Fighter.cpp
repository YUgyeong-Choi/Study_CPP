#include "Fighter.h"
#include "pch.h"

Fighter::Fighter()
{
	strcpy_s(m_playerInfo.Job, sizeof(m_playerInfo.Job), "������");
	m_playerInfo.iHp = 120;
	m_playerInfo.iAttack = 18;

	// ù ��° ��ų
	strcpy_s(m_playerInfo.skills[0].skillName, sizeof(m_playerInfo.skills[0].skillName), "���� ���� ");
	strcpy_s(m_playerInfo.skills[0].skillInfo, sizeof(m_playerInfo.skills[0].skillInfo), "�������� �������� 2ȸ �����Ѵ�");
	m_playerInfo.skills[0].cool = 3;

	// �� ��° ��ų
	strcpy_s(m_playerInfo.skills[1].skillName, sizeof(m_playerInfo.skills[1].skillName), "ȸ��");
	strcpy_s(m_playerInfo.skills[1].skillInfo, sizeof(m_playerInfo.skills[1].skillInfo), "2�ϰ� ������ ������ ȸ���Ѵ�");
	m_playerInfo.skills[1].cool = 2;


	iMaxHp = m_playerInfo.iHp;
	iMaxAttack = m_playerInfo.iAttack;
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

#include "Fighter.h"
#include "pch.h"

Fighter::Fighter()
{
	m_PlayerInfo.job = FIGHTER;
	m_PlayerInfo.iHp = 130;
	m_PlayerInfo.iAttack = 30;

	// ù ��° ��ų
	strcpy_s(m_PlayerInfo.skills[0].skillName, sizeof(m_PlayerInfo.skills[0].skillName), "���� ���� ");
	strcpy_s(m_PlayerInfo.skills[0].skillInfo, sizeof(m_PlayerInfo.skills[0].skillInfo), "�������� �������� 2ȸ �����Ѵ�");
	m_PlayerInfo.skills[0].cool = 3;

	// �� ��° ��ų
	strcpy_s(m_PlayerInfo.skills[1].skillName, sizeof(m_PlayerInfo.skills[1].skillName), "ȸ��");
	strcpy_s(m_PlayerInfo.skills[1].skillInfo, sizeof(m_PlayerInfo.skills[1].skillInfo), "2�ϰ� ������ ������ ȸ���Ѵ�");
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

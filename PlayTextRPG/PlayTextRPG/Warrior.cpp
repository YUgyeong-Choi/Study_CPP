#include "Warrior.h"
#include "pch.h"

Warrior::Warrior()
{
	strcpy_s(m_playerInfo.Job, sizeof(m_playerInfo.Job), "����");
	m_playerInfo.iHp = 150;
	m_playerInfo.iAttack = 20;

	// ù ��° ��ų
	strcpy_s(m_playerInfo.skills[0].skillName, sizeof(m_playerInfo.skills[0].skillName), "��Ÿ");
	strcpy_s(m_playerInfo.skills[0].skillInfo, sizeof(m_playerInfo.skills[0].skillInfo), "3�� ���� �߰����� 10");
	m_playerInfo.skills[0].cool = 3;

	// �� ��° ��ų
	strcpy_s(m_playerInfo.skills[1].skillName, sizeof(m_playerInfo.skills[1].skillName), "������ �ϰ�");
	strcpy_s(m_playerInfo.skills[1].skillInfo, sizeof(m_playerInfo.skills[1].skillInfo), "���� ������ ������ �ϰ����� ������ 2�� ���� ���ظ� ��");
	m_playerInfo.skills[1].cool = 5;


	iMaxHp = m_playerInfo.iHp;
	iMaxAttack = m_playerInfo.iAttack;
}

Warrior::~Warrior()
{
}

void Warrior::Skill1()
{
	m_playerInfo.iAttack *= 1.3;
}

int Warrior::Skill2()
{
	return m_playerInfo.iAttack * 2;
}

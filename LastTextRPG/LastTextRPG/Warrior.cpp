#include "Warrior.h"
#include "pch.h"

Warrior::Warrior()
{
	m_PlayerInfo.job = WARRIOR;
	m_PlayerInfo.iHp = 150;
	m_PlayerInfo.iAttack = 25;

	// ù ��° ��ų
	strcpy_s(m_PlayerInfo.skills[0].skillName, sizeof(m_PlayerInfo.skills[0].skillName), "��Ÿ");
	strcpy_s(m_PlayerInfo.skills[0].skillInfo, sizeof(m_PlayerInfo.skills[0].skillInfo), "3�� ���� �߰����� 5");
	m_PlayerInfo.skills[0].cool = 4;

	// �� ��° ��ų
	strcpy_s(m_PlayerInfo.skills[1].skillName, sizeof(m_PlayerInfo.skills[1].skillName), "������ �ϰ�");
	strcpy_s(m_PlayerInfo.skills[1].skillInfo, sizeof(m_PlayerInfo.skills[1].skillInfo), "���� ������ ������ �ϰ����� ������ 2�� ���� ���ظ� ��");
	m_PlayerInfo.skills[1].cool = 6;

}

Warrior::~Warrior()
{
}

void Warrior::Skill1()
{
}

int Warrior::Skill2()
{
	return 0;
}

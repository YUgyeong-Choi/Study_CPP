#include "Warrior.h"
#include "pch.h"

Warrior::Warrior()
{
	strcpy_s(m_playerInfo.Job, sizeof(m_playerInfo.Job), "����");
	m_playerInfo.iHp = 150;
	m_playerInfo.iAttack = 25;

	// ù ��° ��ų
	strcpy_s(m_playerInfo.skills[0].skillName, sizeof(m_playerInfo.skills[0].skillName), "��Ÿ");
	strcpy_s(m_playerInfo.skills[0].skillInfo, sizeof(m_playerInfo.skills[0].skillInfo), "3�� ���� �߰����� 5");
	m_playerInfo.skills[0].cool = 4;

	// �� ��° ��ų
	strcpy_s(m_playerInfo.skills[1].skillName, sizeof(m_playerInfo.skills[1].skillName), "������ �ϰ�");
	strcpy_s(m_playerInfo.skills[1].skillInfo, sizeof(m_playerInfo.skills[1].skillInfo), "���� ������ ������ �ϰ����� ������ 2�� ���� ���ظ� ��");
	m_playerInfo.skills[1].cool = 6;


	iOriginHp = m_playerInfo.iHp;
	iOriginAttack = m_playerInfo.iAttack;
	iUpgradeAttack = iOriginAttack;
}

Warrior::~Warrior()
{
}

void Warrior::Skill1()
{
	m_playerInfo.iAttack += 5;
}

int Warrior::Skill2()
{
	return m_playerInfo.iAttack * 2;
}

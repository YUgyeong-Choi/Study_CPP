#include "Warrior.h"
#include "pch.h"

Warrior::Warrior()
{
	strcpy_s(m_playerInfo.Job, sizeof(m_playerInfo.Job), "����");
	m_playerInfo.iHp = 300;
	m_playerInfo.iAttack = 25;

	// ù ��° ��ų
	strcpy_s(m_playerInfo.skills[0].skillName, sizeof(m_playerInfo.skills[0].skillName), "����ȭ");
	strcpy_s(m_playerInfo.skills[0].skillInfo, sizeof(m_playerInfo.skills[0].skillInfo), "���� �ð� ���� ���ݷ��� 30% ����������, �޴� ���ذ� 15% ����");

	// �� ��° ��ų
	strcpy_s(m_playerInfo.skills[1].skillName, sizeof(m_playerInfo.skills[1].skillName), "������ �ϰ�");
	strcpy_s(m_playerInfo.skills[1].skillInfo, sizeof(m_playerInfo.skills[1].skillInfo), "������ �ϰ����� ������ ū ���ظ� ��. HP�� �������� ���ذ� �� ��������");
}

Warrior::~Warrior()
{
}

void Warrior::Skill1()
{
}

void Warrior::Skill2()
{
}

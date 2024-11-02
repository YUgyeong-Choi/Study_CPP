#include "Player.h"
#include "pch.h"

Player::Player()
{
    strcpy_s(m_playerInfo.szName, "");
    strcpy_s(m_playerInfo.Job, "");
    m_playerInfo.iHp = 0;
    m_playerInfo.iAttack = 0;
    m_playerInfo.iMoney = 0;
    m_playerInfo.Stage = 1;

    for (int i = 0; i < 2; ++i) {
        strcpy_s(m_playerInfo.skills[i].skillName, "");
        strcpy_s(m_playerInfo.skills[i].skillInfo, "");
    }
}

Player::~Player()
{
}

void Player::Render()
{
    cout << "====================================" << endl;
    cout << "이름: " << m_playerInfo.szName << endl;
    cout << "Hp: " << m_playerInfo.iHp;
    cout << "Attack Damage: " << m_playerInfo.iAttack;
}

void Player::Set_Player_Name(const char* szName)
{
    strcpy_s(m_playerInfo.szName, sizeof(m_playerInfo.szName), szName);
}

void Player::InitializeStat()
{
}

void Player::Skill1()
{
}

void Player::Skill2()
{
}

void Player::Render_Detail()
{
    cout << "============== 내 정보==============" << endl;
    cout << "이름:" << m_playerInfo.szName << '\t' << "직업:" << m_playerInfo.Job << endl;
    cout << "Hp: " << m_playerInfo.iHp << endl;
    cout << "Attack Damage: " << m_playerInfo.iAttack << endl;
    cout << "Money: " << m_playerInfo.iMoney << endl;
    cout << "스킬 1-" << m_playerInfo.skills[0].skillName<<" : "<< m_playerInfo.skills[0].skillInfo << endl;
    cout << "스킬 2-" << m_playerInfo.skills[1].skillName<<" : "<< m_playerInfo.skills[1].skillInfo << endl;
    cout << "====================================" << endl;
}

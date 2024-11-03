#include "Player.h"
#include "pch.h"
#include "Color.h"

Player::Player()
{
    strcpy_s(m_playerInfo.szName, "");
    strcpy_s(m_playerInfo.Job, "");
    m_playerInfo.iHp = 0;
    m_playerInfo.iAttack = 0;
    m_playerInfo.iMoney = 0;
    m_playerInfo.Stage = 1;
    iMaxHp = 0;
    iMaxAttack = 0;

    for (int i = 0; i < 2; ++i) {
        strcpy_s(m_playerInfo.skills[i].skillName, "");
        strcpy_s(m_playerInfo.skills[i].skillInfo, "");
        m_playerInfo.skills[i].cool = 0;
    }
}

Player::~Player()
{
}

void Player::Render()
{
    setColor(RED);
    cout << "====================================" << endl; setColor(GRAY);
    cout << m_playerInfo.szName << endl;
    cout << "Hp: " << m_playerInfo.iHp << endl;
    cout << "Attack Damage: " << m_playerInfo.iAttack << endl;
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

int Player::Skill2()
{
    return 0;
}

void Player::Render_Detail()
{
    system("cls");
    setColor(YELLOW);
    cout << "============== 내 정보==============" << endl; setColor(GRAY);
    cout << "이름:" << m_playerInfo.szName << '\t' << "직업:" << m_playerInfo.Job << endl;
    cout << "Hp: " << m_playerInfo.iHp << endl;
    cout << "Attack Damage: " << m_playerInfo.iAttack << endl;
    cout << "Money: " << m_playerInfo.iMoney << endl;
    cout << "스킬 1-" << m_playerInfo.skills[0].skillName<<" : "<< m_playerInfo.skills[0].skillInfo << endl;
    cout << "스킬 1 쿨타임: " << m_playerInfo.skills[0].cool<<endl;
    cout << "스킬 2-" << m_playerInfo.skills[1].skillName<<" : "<< m_playerInfo.skills[1].skillInfo << endl;
    cout << "스킬 2 쿨타임: " << m_playerInfo.skills[1].cool<<endl; setColor(YELLOW);
    cout << "====================================" << endl; setColor(GRAY);
}

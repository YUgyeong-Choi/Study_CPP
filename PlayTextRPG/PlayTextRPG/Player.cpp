#include "Player.h"
#include "pch.h"

Player::Player()
{
}

Player::~Player()
{
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
}

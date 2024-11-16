#include "Player.h"
#include "pch.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Set_Player_Name(const char* _szName)
{
	strcpy_s(m_PlayerInfo.szName, sizeof(m_PlayerInfo.szName), _szName);
}

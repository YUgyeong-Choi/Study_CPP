#include "Monster.h"
#include "pch.h"

Monster::Monster()
{
}

Monster::Monster(const char* pName, int _iHp, int _iAttack)
{
	strcpy_s(m_info.m_SzName, sizeof(m_info.m_SzName), pName);
	m_info.m_iAttack = _iAttack;
	m_info.m_iHp = _iHp;
}

Monster::~Monster()
{
}

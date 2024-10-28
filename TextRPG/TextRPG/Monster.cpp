#include "Monster.h"
#include "pch.h"


Monster::Monster(const char* pName, int _iHp, int _iAttack)
{
	strcpy_s(info.m_SzName, sizeof(info.m_SzName), pName);
	info.m_iAttack = _iAttack;
	info.m_iHp = _iHp;
}

Monster::~Monster()
{
	Release();
}

void Monster::Initialize(){}

void Monster::Release(){}

void Monster::Render()
{
	cout << "================================" << endl;
	cout << "이름 : " << info.m_SzName << endl;
	cout << "체력 : " << info.m_iHp << "\t공격력 : " << info.m_iAttack << endl;
}

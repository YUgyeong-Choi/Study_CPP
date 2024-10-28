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
	cout << "�̸� : " << info.m_SzName << endl;
	cout << "ü�� : " << info.m_iHp << "\t���ݷ� : " << info.m_iAttack << endl;
}

#include "Monster.h"
#include "pch.h"

Monster::Monster()
{
	info = nullptr;
}

Monster::~Monster()
{
	Release();
}

void Monster::Initialize()
{
	if (!info) info = new INFO;
}

void Monster::Release()
{
	SAFE_DELETE(info);
}

void Monster::Create_Obj(const char* pName, int _iAttack, int _iHp)
{
	strcpy_s(info->m_SzName, sizeof(info->m_SzName), pName);
	info->m_iAttack = _iAttack;
	info->m_iHp = _iHp;
}

INFO Monster::Get_Info()
{
	return *info;
}

void Monster::Get_Attack(int _iHp)
{
	info->m_iHp = _iHp;
}

void Monster::Render()
{
	cout << "================================" << endl;
	cout << "이름 : " << info->m_SzName << endl;
	cout << "체력 : " << info->m_iHp << "\t공격력 : " << info->m_iAttack << endl;
}

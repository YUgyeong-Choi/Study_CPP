#include "Obj.h"
#include "pch.h"

Obj::Obj()
{
}

Obj::Obj(const char* pName, int _iHp, int _iAttack)
{
	strcpy_s(m_info.m_SzName, sizeof(m_info.m_SzName), pName);
	m_info.m_iAttack = _iAttack;
	m_info.m_iHp = _iHp;
}

Obj::~Obj()
{
}

void Obj::Render()
{
	cout << "================================" << endl;
	cout << "이름 : " << m_info.m_SzName << endl;
	cout << "체력 : " << m_info.m_iHp << "\t공격력 : " << m_info.m_iAttack << endl;
}

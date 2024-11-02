#include "Monster.h"
#include "pch.h"

Monster::Monster()
{
    strcpy_s(m_monsterInfo.szName, "ΩΩ∂Û¿”"); 
    m_monsterInfo.iHp = 50;           
    m_monsterInfo.iAttack = 5;       
}

void Monster::Render()
{
    cout << "====================================" << endl;
    cout << m_monsterInfo.szName << endl;
    cout << "Hp: " << m_monsterInfo.iHp << endl;
    cout << "Attack Damage: " << m_monsterInfo.iAttack << endl;
}

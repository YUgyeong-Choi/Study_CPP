#include "Monster.h"
#include "pch.h"

Monster::Monster(const char* name, int hp, int attack) {
    strcpy_s(m_monsterInfo.szName,sizeof(m_monsterInfo.szName), name);
    m_monsterInfo.iHp = hp;
    m_monsterInfo.iAttack = attack;
}

void Monster::Render()
{
    cout << "====================================" << endl;
    cout << m_monsterInfo.szName << endl;
    cout << "Hp: " << m_monsterInfo.iHp << endl;
    cout << "Attack Damage: " << m_monsterInfo.iAttack << endl;
}

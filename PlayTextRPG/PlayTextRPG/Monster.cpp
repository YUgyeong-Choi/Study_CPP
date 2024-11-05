#include "Monster.h"
#include "pch.h"
#include "Color.h"

Monster::Monster(const char* name, int hp, int attack, int money) {
    strcpy_s(m_monsterInfo.szName,sizeof(m_monsterInfo.szName), name);
    m_monsterInfo.iHp = hp;
    m_monsterInfo.iAttack = attack;
    m_monsterInfo.iMoney = money;
}

void Monster::Render()
{
    setColor(RED);
    cout << "====================================" << endl; setColor(GRAY);
    cout << m_monsterInfo.szName << endl;
    cout << "Hp: " << m_monsterInfo.iHp << endl;
    cout << "Attack Damage: " << m_monsterInfo.iAttack << endl;
}

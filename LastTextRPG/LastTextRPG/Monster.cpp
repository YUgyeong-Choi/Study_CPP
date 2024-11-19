#include "Monster.h"
#include "Color.h"

Monster::Monster(const string& name, int hp, int attack, int money) {
    m_monsterInfo.strName = name;
    m_monsterInfo.iHp = hp;
    m_monsterInfo.iAttack = attack;
    m_monsterInfo.iMoney = money;
}

void Monster::Render()
{
    setColor(RED);
    cout << "====================================" << endl; setColor(GRAY);
    cout << m_monsterInfo.strName << endl;
    cout << "Hp: " << m_monsterInfo.iHp << endl;
    cout << "Attack Damage: " << m_monsterInfo.iAttack << endl;
}

#include "MiddleDungeon.h"
#include "pch.h"
MiddleDungeon::MiddleDungeon()
{
}

MiddleDungeon::~MiddleDungeon()
{
}



Monster* MiddleDungeon::Set_Monster() {
    Monster* _pMonster = nullptr;
    int monsterChoice = rand() % 2 + 1;

    if (monsterChoice == 1) {
        _pMonster = new Monster("���� ���", 80, 15);
    }
    else if (monsterChoice == 2) {
        _pMonster = new Monster("����", 90, 12);
    }

    return _pMonster;
}

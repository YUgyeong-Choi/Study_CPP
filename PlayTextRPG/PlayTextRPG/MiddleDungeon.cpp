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
        _pMonster = new Monster("유령 기사", 150, 25, 20);
    }
    else if (monsterChoice == 2) {
        _pMonster = new Monster("망자", 130, 20,17);
    }

    return _pMonster;
}

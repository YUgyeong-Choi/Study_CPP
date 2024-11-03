#include "LowDungeon.h"
#include "pch.h"

LowDungeon::LowDungeon()
{
}

LowDungeon::~LowDungeon()
{
}

Monster* LowDungeon::Set_Monster() {
    Monster* _pMonster = nullptr; 
    int monsterChoice = rand() % 2 + 1;

    if (monsterChoice == 1) {
        _pMonster = new Monster("그림자 쥐", 50, 10);
    }
    else if (monsterChoice == 2) {
        _pMonster = new Monster("독사", 60, 8);
    }

    return _pMonster; 
}

#include "HighDungeon.h"
#include "pch.h"
HighDungeon::HighDungeon()
{
}

HighDungeon::~HighDungeon()
{
}

Monster* HighDungeon::Set_Monster() {
    Monster* _pMonster = nullptr;
    int monsterChoice = rand() % 2 + 1;

    if (monsterChoice == 1) {
        _pMonster = new Monster("¿ë¾Ï ±«¹°", 120, 20);
    }
    else if (monsterChoice == 2) {
        _pMonster = new Monster("ºÒ²É Á¤·É", 300, 18);
    }

    return _pMonster;
}
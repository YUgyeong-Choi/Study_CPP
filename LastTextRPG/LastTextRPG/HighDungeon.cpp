#include "HighDungeon.h"

Monster* HighDungeon::Set_Monster() {
    Monster* _pMonster = nullptr;
    int monsterChoice = rand() % 2 + 1;

    if (monsterChoice == 1) {
        _pMonster = new Monster("��� ����", 300, 55, 50);
    }
    else if (monsterChoice == 2) {
        _pMonster = new Monster("�Ҳ� ����", 250, 40, 45);
    }

    return _pMonster;
}
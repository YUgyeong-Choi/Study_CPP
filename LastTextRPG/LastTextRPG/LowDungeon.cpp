#include "LowDungeon.h"


Monster* LowDungeon::Set_Monster() {
    Monster* _pMonster = nullptr;
    int monsterChoice = rand() % 2 + 1;

    if (monsterChoice == 1) {
        _pMonster = new Monster("�׸��� ��", 60, 10, 8);
    }
    else if (monsterChoice == 2) {
        _pMonster = new Monster("����", 80, 15, 10);
    }

    return _pMonster;
}

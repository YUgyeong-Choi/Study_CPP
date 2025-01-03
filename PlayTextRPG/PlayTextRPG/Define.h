#pragma once

#define PURE = 0

template<typename T>
void	SAFE_DELETE(T & Temp)
{
    if (Temp)
    {
        delete Temp;
        Temp = nullptr;
    }
}

template<typename T>
void	SAFE_DELETE_ARRAY(T& Temp)
{
    if (Temp)
    {
        delete[] Temp;
        Temp = nullptr;
    }
}

enum ITEMTYPE { NONE, IT_WEAPON, IT_ARMOR, IT_POTION};
enum STATE { EQUIP, UNEQUIP };


typedef struct {
    char skillName[32];
    char skillInfo[128];
    int cool;
} SkillInfo;


typedef struct {
    char szName[32];
    char Job[32];
    int iHp;
    int iAttack;
    int iMoney;
    int Stage;
    int weaponLevel;
    SkillInfo skills[2];
} PlayerInfo;


typedef struct {
    char szName[32];
    int iHp;
    int iAttack;
    int iMoney;
} MonsterInfo;

typedef struct {
    char szName[32];
    int iHp;
    int iAttack;
    int iPrice;
    ITEMTYPE type;
}ItemInfo;



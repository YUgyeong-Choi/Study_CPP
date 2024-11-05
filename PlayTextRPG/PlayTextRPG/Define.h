#pragma once
#define SAFE_DELETE(p) if(p) { delete p; p = nullptr;}
#define SAFE_DELETE_ARRAY(p) if(p) { delete [] p; p = nullptr;}


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
    int add;
    int iPriceOrCount;
}ItemInfo;
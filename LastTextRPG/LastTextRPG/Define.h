#pragma once
#include "pch.h"
#define PURE = 0

template<typename T>
void	SAFE_DELETE(T& Temp)
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

enum JOB { WARRIOR = 1, MAGE, FIGHTER };

typedef struct {
    char skillName[32];
    char skillInfo[128];
    int cool;
} SkillInfo;


typedef struct {
    string strName;
    JOB job;
    int iHp;
    int iAttack;
    int iDefend;
    int iMoney;
    int Stage;
    SkillInfo skills[2];
} PlayerInfo;
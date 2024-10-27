#pragma once
#include "Define.h"

class Monster {
public:
	Monster();
	~Monster();
public:
	void Initialize();
	void Release();
	void Render();
	void Create_Obj(const char* pName, int _iAttack, int _iHp);
	INFO Get_Info();
	void Get_Attack(int _iHp);
private:
	INFO* info;
};
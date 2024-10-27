#pragma once
#include "Define.h"

class Player {
public:
	Player();
	~Player();
public:
	void Initialize();
	void Release();
	bool Load_Data();
	bool Save_Data();
	void Create_Obj(const char* pName, int _iAttack, int _iHp);
	bool Select_Job();
	void Render();
	INFO Get_Info();
	void Get_Attack(int _iHp);
	void Die();
private:
	INFO* info;
};
#pragma once
#include "Player.h"
class Login {
public:
	Login();
	~Login();
public:
	void Update();
	void Release();
private:
	Player* Select_Job();
private:
	Player* m_pPlayer;
};
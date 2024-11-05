#pragma once
#include "Player.h"
#include "Mainmenu.h"

class Login {
public:
	enum JOB { WARRIOR = 1, MAGE, FIGHTER, END };
public:
	Login();
	~Login();
public:
	void Update();
	void Release();
private:
	bool Select_Job();
	void Create_Name();
private:
	Player* m_pPlayer;
	Mainmenu* m_pMainmenu;
};
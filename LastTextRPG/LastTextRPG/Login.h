#pragma once
#include "Player.h"
#include "MainMenu.h"

class Login {
public:
	Login();
	~Login();
public:
	void Release();
	void Update();
private:
	bool Select_Job();
	void Create_Name();
private:
	Player* m_pPlayer;
	MainMenu* m_pMenu;
};
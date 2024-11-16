#pragma once
#include "Login.h"
class MainGame {
public:
	MainGame();
    ~MainGame();
public:
	void Update();
	void Release();
private:
	Login* m_pLogin;
};
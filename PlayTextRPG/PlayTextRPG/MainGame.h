#pragma once
#include "Login.h"
class MainGame {
public:
	MainGame();
	~MainGame();
public:
	void Initialize();
	void Update();
	void Release();
private:
	Login* m_Login;
};
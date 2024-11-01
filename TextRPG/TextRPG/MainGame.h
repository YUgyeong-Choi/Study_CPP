#pragma once
#include "Player.h"
#include "Obj.h"
#include "Field.h"

class MainGame {
public:
	MainGame();
	~MainGame();
public:
	void Initialize();
	void Update();
	void Release();
private:
	Obj* m_pPlayer;
	Field* m_pField;
};
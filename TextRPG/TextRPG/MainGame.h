#pragma once
#include "Player.h"
#include "Monster.h"

class MainGame {
public:
	MainGame();
	~MainGame();
public:
	void Initialize();
	void Update();
	void Release();
	void Field();
	void Fight(Player* player, Monster* monster);
private:
	Player* player;
};
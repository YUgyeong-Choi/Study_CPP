#pragma once
#include "Student.h"
class MainGame {
public:
	MainGame();
	~MainGame();
public:
	void Initialize();
	void Update();
	void Release();
private:
	Student* student;
};
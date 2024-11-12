#pragma once
#include "VectorStudent.h"
#include "Define.h"
#include <vector>
using namespace std;

class MainGame2 {
public:
	void Update();
	void Input_Data();
	void Output_Data();
	void Search_Data();
private:
	vector<INFO> students;
};
#pragma once
#include "Define.h"
class Student {
public:
	Student();
	~Student();
public:
	void Release();
	void Input_Data();
	void Output_Data();
	void Search_Data();
private:
	INFO* m_tStudent;
	int m_iSize;
};
#include "MainGame.h"
#include "pch.h"

MainGame::MainGame(){
	student = nullptr;
}

MainGame::~MainGame() {
	Release();
}

void MainGame::Initialize()
{
	if(!student) student = new Student;
}

void MainGame::Update()
{
	int iInput(0);
	while (1) {
		system("cls");
		cout << "1.입력 2.출력 3.검색 4.종료: ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			student->Input_Data();
			break;
		case 2:
			student->Output_Data();
			break;
		case 3:
			student->Search_Data();
			break;
		case 4:
			cout << "프로그램을 종료합니다" << endl;
			return;
		default:
			continue;
		}
	}
}

void MainGame::Release()
{
	SAFE_DELETE(student);
}

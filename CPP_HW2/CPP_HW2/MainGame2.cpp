#include "MainGame2.h"
#include <iostream>
using namespace std;

void MainGame2::Update()
{
	int iInput(0);
	while (1) {
		system("cls");
		cout << "1.입력 2.출력 3.검색 4.종료: ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			Input_Data();
			break;
		case 2:
			Output_Data();
			break;
		case 3:
			Search_Data();
			break;
		case 4:
			cout << "프로그램을 종료합니다" << endl;
			return;
		default:
			continue;
		}
	}
}

void MainGame2::Input_Data()
{
	int iAdd(0);
	cout << "추가할 인원을 입력하세요: ";
	cin >> iAdd;

	INFO data;
	for (int i = 0; i < iAdd; ++i) {
		system("cls");
		data = {};
		cout << "이름을 입력하세요: ";
		cin >> data.szName;
		cout << "국어점수를 입력하세요: ";
		cin >> data.iKor;
		cout << "영어점수를 입력하세요: ";
		cin >> data.iEng;
		cout << "수학점수를 입력하세요: ";
		cin >> data.iMath;
		data.iTotal = data.iKor + data.iEng + data.iEng;
		data.fAver = (float)data.iTotal / 3.f;
		students.push_back(data);
		system("pause");
	}
}

void MainGame2::Output_Data()
{
	for (int i = 0; i < students.size(); ++i) {
		cout << "이름:\t국어:\t영어:\t수학:\t총점:\t평균:\t" << endl;
		cout << students[i].szName << '\t' << students[i].iKor << '\t' << students[i].iEng << '\t' << students[i].iMath << '\t' << students[i].iTotal << '\t' << students[i].fAver << endl;
	}
	system("pause");
}

void MainGame2::Search_Data()
{
	char inputName[32];
	cout << "검색할 이름을 입력하세요: ";
	cin >> inputName;
	for (int i = 0; i < students.size(); ++i) {
		if (!strcmp(inputName, students[i].szName)) {
			cout << "이름:\t국어:\t영어:\t수학:\t총점:\t평균:\t" << endl;
			cout << students[i].szName << '\t' << students[i].iKor << '\t' << students[i].iEng << '\t' << students[i].iMath << '\t' << students[i].iTotal << '\t' << students[i].fAver << endl;
		}
	}
	system("pause");
}

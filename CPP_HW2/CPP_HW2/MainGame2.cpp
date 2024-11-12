#include "MainGame2.h"
#include <iostream>
using namespace std;

void MainGame2::Update()
{
	int iInput(0);
	while (1) {
		system("cls");
		cout << "1.�Է� 2.��� 3.�˻� 4.����: ";
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
			cout << "���α׷��� �����մϴ�" << endl;
			return;
		default:
			continue;
		}
	}
}

void MainGame2::Input_Data()
{
	int iAdd(0);
	cout << "�߰��� �ο��� �Է��ϼ���: ";
	cin >> iAdd;

	INFO data;
	for (int i = 0; i < iAdd; ++i) {
		system("cls");
		data = {};
		cout << "�̸��� �Է��ϼ���: ";
		cin >> data.szName;
		cout << "���������� �Է��ϼ���: ";
		cin >> data.iKor;
		cout << "���������� �Է��ϼ���: ";
		cin >> data.iEng;
		cout << "���������� �Է��ϼ���: ";
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
		cout << "�̸�:\t����:\t����:\t����:\t����:\t���:\t" << endl;
		cout << students[i].szName << '\t' << students[i].iKor << '\t' << students[i].iEng << '\t' << students[i].iMath << '\t' << students[i].iTotal << '\t' << students[i].fAver << endl;
	}
	system("pause");
}

void MainGame2::Search_Data()
{
	char inputName[32];
	cout << "�˻��� �̸��� �Է��ϼ���: ";
	cin >> inputName;
	for (int i = 0; i < students.size(); ++i) {
		if (!strcmp(inputName, students[i].szName)) {
			cout << "�̸�:\t����:\t����:\t����:\t����:\t���:\t" << endl;
			cout << students[i].szName << '\t' << students[i].iKor << '\t' << students[i].iEng << '\t' << students[i].iMath << '\t' << students[i].iTotal << '\t' << students[i].fAver << endl;
		}
	}
	system("pause");
}

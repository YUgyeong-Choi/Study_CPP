#include "Minigame.h"
#include "pch.h"
#include "Color.h"

Minigame::Minigame()
{
	m_pPlayer = nullptr;
}

Minigame::~Minigame()
{
}

void Minigame::Update()
{
	system("cls"); setColor(SKYBLUE);
	cout << endl << endl << "�����忡 "; setColor(GRAY);
	cout<<"�� ���� ȯ���Ѵ�.." << endl << endl;
	system("pause");
	system("cls");
	cout << endl << endl << "���� �ִ� ��� ���� "; setColor(RED);
	cout << "Ai"; setColor(GRAY);
	cout<<"�� �ۼ��� �ڵ���.." << endl << endl;
	cout << endl << endl << "���� ������ϰ� �ڵ� ������ ���� �ƴѰ� ����..." << endl << endl;
	cout << endl << endl << "�׷� ������ ������ �� ������ ���� ����� !" << endl << endl;
	system("pause");
	
	while (1) {
		int _iInput(0);
		system("cls");
		setColor(YELLOW);
		cout << "============ ���� ��� =============" << endl; setColor(GRAY);
		cout << "1. ����������" << endl;
		cout << "2. ���� ���߱�" << endl;
		cout << "3. ����" << endl;
		setColor(YELLOW);
		cout << "====================================" << endl; setColor(GRAY);

		cin >> _iInput;


		system("pause");
	}
}

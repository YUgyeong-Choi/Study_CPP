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
	cout << endl << endl << "도박장에 "; setColor(GRAY);
	cout<<"온 것을 환영한다.." << endl << endl;
	system("pause");
	system("cls");
	cout << endl << endl << "여기 있는 모든 것은 "; setColor(RED);
	cout << "Ai"; setColor(GRAY);
	cout<<"가 작성한 코드지.." << endl << endl;
	cout << endl << endl << "나야 고생안하고 코드 넣으니 개꿀 아닌가 하하..." << endl << endl;
	cout << endl << endl << "그럼 통장이 텅장이 될 때까지 즐기다 가라고 !" << endl << endl;
	system("pause");
	
	while (1) {
		int _iInput(0);
		system("cls");
		setColor(YELLOW);
		cout << "============ 게임 목록 =============" << endl; setColor(GRAY);
		cout << "1. 가위바위보" << endl;
		cout << "2. 숫자 맞추기" << endl;
		cout << "3. 블랙잭" << endl;
		setColor(YELLOW);
		cout << "====================================" << endl; setColor(GRAY);

		cin >> _iInput;


		system("pause");
	}
}

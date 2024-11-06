#include "Minigame.h"
#include "pch.h"
#include "Color.h"

Minigame::Minigame()
{
	m_pPlayer = nullptr;
	rouletteGame = nullptr;
}

Minigame::~Minigame()
{
	Release();
}

void Minigame::Update()
{
	system("cls"); setColor(SKYBLUE);
	cout << endl << "�����忡 "; setColor(GRAY);
	cout<<"�� ���� ȯ���Ѵ�.." << endl << endl;
	system("pause");
	system("cls");
	cout << endl << endl << "���� �ִ� ��� ���� "; setColor(RED);
	cout << "Ai"; setColor(GRAY);
	cout<<"�� �ۼ��� �ڵ���.." << endl;
	cout << "���� ������ϰ� �ڵ� ������ ���� �ƴѰ� ����..." << endl;
	cout << "�׷� ������ ������ �� ������ ���� ����� !" << endl << endl<<endl;
	system("pause");
	
	while (1) {
		int _iInput(0);
		system("cls");
		setColor(YELLOW);
		cout << "============ ���� ��� =============" << endl; setColor(GRAY);
		cout << "1. ����������" << endl;
		cout << "2. �귿" << endl;
		cout << "3. ����" << endl;
		setColor(YELLOW);
		cout << "====================================" << endl; setColor(GRAY);
		cout << "4. �ڷ� ����" << endl;
		cin >> _iInput;

		switch (_iInput) {
		case 1:
			break;
		case 2:
			rouletteGame = new Roulette;
			rouletteGame->Set_PlayerInfo(m_pPlayer);
			rouletteGame->Update();
			SAFE_DELETE(rouletteGame);
			break;
		case 3:
			break;
		case 4:
			return;
		default:
			return;
		}

		system("pause");
	}
}

void Minigame::Release()
{
	SAFE_DELETE(rouletteGame);
}

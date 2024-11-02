#include "LowDungeon.h"
#include "pch.h"
#include <ctime>


LowDungeon::LowDungeon()
{
	m_pPlayer = nullptr;
	m_pMonster = nullptr;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			map[i][j][0] = '*';
			map[i][j][1] = 'f';
		}
	}

	srand(unsigned(time(0)));
	int count = 0;

	while (count < 6) {
		int i = std::rand() % 5;
		int j = std::rand() % 5;

		if (map[i][j][1] == 'f' && !(i == 2 && j == 2)) {
			map[i][j][1] = 't';
			count++;
		}
	}

	map[2][2][0] = '?';
}

LowDungeon::~LowDungeon()
{
	Release();
}

void LowDungeon::Update()
{
	int x(2), y(2);
	int _iInput(0);

	while (1) {

		Render_Map();
		cout << "1.�� 2.�Ʒ� 3.�� 4.�� 5.���� ����: " << endl;
		cin >> _iInput;
		switch (_iInput) {
		case 1:
			if (x > 0) {
				map[x][y][0] = ' ';
				map[--x][y][0] = '?';
			}
			break;
		case 2:
			if (x < 4) {
				map[x][y][0] = ' ';
				map[++x][y][0] = '?';
			}
			break;
		case 3:
			if (y > 0) {
				map[x][y][0] = ' ';
				map[x][--y][0] = '?';
			}
			break;
		case 4:
			if (y < 4) {
				map[x][y][0] = ' ';
				map[x][++y][0] = '?';
			}
			break;
		case 5:
			cout << "������ �����ϴ�" << endl;
			return;
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
			continue;
		}


		if (map[x][y][1] == 't') {
			Fight(m_pPlayer, m_pMonster);
		}

		if (Check_Clear()) {
			cout << "���� Ŭ����" << endl;
			break;
		}
	}
}

void LowDungeon::Release()
{
	SAFE_DELETE(m_pMonster);
}

void LowDungeon::Set_PlayerInfo(Player* _pPlayer)
{
	m_pPlayer = _pPlayer;
}

void LowDungeon::Render_Map()
{
	cout << "============= �ϱ޴��� =============" << endl;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cout << map[i][j][0]<< " ";
		}
		cout << endl;
	}
	cout << "====================================" << endl;
}

bool LowDungeon::Check_Clear()
{
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (map[i][j][0] == '*') {
				return false;
			}
		}
	}

	return true;
}

void LowDungeon::Fight(Player* _pPlayer, Monster* _pMonster)
{
	int _iInput(0);

	while (1) {
		cout << "! ���͸� ������ !" << endl << endl;
		_pMonster = new Monster;
		_pMonster->Render();
		_pPlayer->Render();
		cout << "====================================" << endl;
		cout << "1.�⺻ ����" << " 2." << _pPlayer->Get_Info().skills[0].skillName << " 3." << _pPlayer->Get_Info().skills[1].skillName << endl;
		cout << "4.����" << endl;
		cin >> _iInput;
		switch (_iInput)
		{
		case 1:
			_pPlayer->Set_Hp(_pMonster->Get_Info().iAttack);
			_pMonster->Set_Hp(_pPlayer->Get_Info().iAttack);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			cout << "���� ���ϴ�" << endl;
			return;
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
			continue;
		}

		
	}

	SAFE_DELETE(_pMonster);
}

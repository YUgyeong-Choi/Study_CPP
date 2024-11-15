#include "Mainmenu.h"
#include "pch.h"
#include "Define.h"
#include <limits>
#include "Color.h"

Mainmenu::Mainmenu()
{
	m_pPlayer = nullptr; 
	m_pField = nullptr;
	m_pStoremenu = nullptr;
	m_pMinigame = nullptr;
}

Mainmenu::~Mainmenu()
{
	Release();
}

void Mainmenu::Release()
{
	SAFE_DELETE(m_pField);
	SAFE_DELETE(m_pStoremenu);
	SAFE_DELETE(m_pMinigame);
}

void Mainmenu::Update()
{
	int _iInput(0);
	while (1) {
		system("cls");
		setColor(YELLOW);
		cout << "============= Main Menu ============" << endl; setColor(GRAY);
		cout << "1. �����" << endl;
		cout << "2. �κ��丮 & ���" << endl;
		cout << "3. ����" << endl;
		cout << "4. ���� ���� ���" << endl; setColor(RED);
		cout << "5. ����" << endl; setColor(YELLOW);
		cout << "====================================" << endl; setColor(GRAY);
		cout << "6. �ڷ� ����" << endl; 
		cin >> _iInput;
		cin.ignore();
		switch (_iInput)
		{
		case 1:
			m_pField = new Field;
			m_pField->Set_PlayerInfo(m_pPlayer);
			m_pField->Update();
			break;
		case 2:
			m_pPlayer->Render_Inventory();
			break;
		case 3:
			m_pStoremenu = new Storemenu;
			m_pStoremenu->Set_PlayerInfo(m_pPlayer);
			m_pStoremenu->Update();
			SAFE_DELETE(m_pStoremenu);
			break;
		case 4:
			m_pPlayer->Render_Detail();
			break;
		case 5:
			m_pMinigame = new Minigame;
			m_pMinigame->Set_PlayerInfo(m_pPlayer);
			m_pMinigame->Update();
			SAFE_DELETE(m_pMinigame);
		case 6:
			return;
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
			continue;
		}
	}
}

void Mainmenu::Set_PlayerInfo(Player* pPlayer)
{
	m_pPlayer = pPlayer;
}

#include "Mainmenu.h"
#include "pch.h"
#include "Define.h"
#include <limits>
#include "Color.h"

Mainmenu::Mainmenu()
{
	m_pPlayer = nullptr; 
	m_pField = nullptr;
	m_pStore = nullptr;
}

Mainmenu::~Mainmenu()
{
	Release();
}

void Mainmenu::Release()
{
	SAFE_DELETE(m_pField);
	SAFE_DELETE(m_pStore);
}

void Mainmenu::Update()
{
	int _iInput(0);
	while (1) {
		system("cls");
		setColor(YELLOW);
		cout << "============= Main Menu ============" << endl; setColor(GRAY);
		cout << "1. �����" << endl;
		cout << "2. �κ��丮" << endl;
		cout << "3. ����" << endl;
		cout << "4. ���� ���� ���" << endl; setColor(YELLOW);
		cout << "====================================" << endl; setColor(GRAY);
		cout << "5. �ڷ� ����" << endl; 
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
			m_pStore = new Store;
			m_pStore->Set_PlayerInfo(m_pPlayer);
			m_pStore->Update();
			SAFE_DELETE(m_pStore);
			break;
		case 4:
			m_pPlayer->Render_Detail();
			break;
		case 5:
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

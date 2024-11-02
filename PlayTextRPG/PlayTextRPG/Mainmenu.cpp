#include "Mainmenu.h"
#include "pch.h"

Mainmenu::Mainmenu()
{
	m_pPlayer = nullptr;
	m_pField = nullptr;
}

Mainmenu::~Mainmenu()
{
	Release();
}

void Mainmenu::Release()
{
	if(m_pField) SAFE_DELETE(m_pField);
}

void Mainmenu::Update()
{
	int _iInput(0);
	while (1) {
		cout << "============= Main Menu ============" << endl;
		cout << "1. �����" << endl;
		cout << "2. �κ��丮" << endl;
		cout << "3. ����" << endl;
		cout << "4. ���� ���� ���" << endl;
		cout << "5. �ڷ� ����" << endl;
		cout << "====================================" << endl;
		cin >> _iInput;
		switch (_iInput)
		{
		case 1:
			m_pField = new Field;
			m_pField->Set_PlayerInfo(m_pPlayer);
			m_pField->Update();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //gpt����
			m_pPlayer->Render_Detail();
			cout << "�ƹ� ��ư ������ �ڷ� ���ϴ�" << endl;
			cin.get();
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

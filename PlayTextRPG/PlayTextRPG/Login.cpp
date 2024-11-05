#include "Login.h"
#include "pch.h"
#include "Warrior.h"
#include "Fighter.h"
#include "Mage.h"
#include "Color.h"

Login::Login()
{
	m_pPlayer = nullptr;
	m_pMainmenu = nullptr;
}

Login::~Login()
{
	Release();
}

void Login::Update()
{
	while (1) {
		system("cls");
		bool bIsSelect = false;
		if (m_pPlayer) SAFE_DELETE(m_pPlayer);
		if (m_pMainmenu) SAFE_DELETE(m_pMainmenu);

		int _iInput(0);
		cout << "========== �� �÷��̾� �� ==========" << endl; setColor(GRAY);
		cout << "1.              " << endl;
		cout << "2.              " << endl;
		cout << "3.              " << endl; setColor(YELLOW);
		cout << "====================================" << endl; setColor(GRAY);
		cout << "4. ���� �����ϱ�" << endl;
		cout << "5. ���� �����ϱ�" << endl;

		cin >> _iInput;
		switch (_iInput) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			bIsSelect = Select_Job();
			if (bIsSelect) {
				break;
			}
			else {
				continue;
			}
		case 5:
			cout << "������ �����մϴ�" << endl;
			return;
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
			continue;
		}

		if (bIsSelect) {
			m_pMainmenu = new Mainmenu;
			m_pMainmenu->Set_PlayerInfo(m_pPlayer);
			m_pMainmenu->Update();
		}
	}
}

void Login::Release() 
{
	SAFE_DELETE(m_pPlayer);
	SAFE_DELETE(m_pMainmenu);
}

bool Login::Select_Job()
{
	while (1) {
		system("cls");
		int _iInput(0);
		setColor(YELLOW);
		cout << "============= ���� ���� ============" << endl; setColor(GRAY);
		cout << "1. ����" << endl;
		cout << "2. ������" << endl;
		cout << "3. ������" << endl; setColor(YELLOW);
		cout << "====================================" << endl; setColor(GRAY);
		cout << "4. �ڷ� ����" << endl;
		
		cin >> _iInput;
		switch (_iInput)
		{
		case WARRIOR:
			m_pPlayer = new Warrior;
			Create_Name();
			return true;
		case MAGE:
			m_pPlayer = new Mage;
			Create_Name();
			return true;
		case FIGHTER:
			m_pPlayer = new Fighter;
			Create_Name();
			return true;
		case END:
			return false;
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
			continue;
		}
	}
}

void Login::Create_Name() {
	char _szName[32];

	while (true) {
		system("cls");
		setColor(YELLOW);
		cout << m_pPlayer->Get_Info().Job << "�� �����ϼ̽��ϴ� !" << endl;
		cout << "����� �г����� �ۼ����ּ��� "<<endl;
		setColor(GRAY);
		cin >> _szName;

		if (strlen(_szName) > 0) {
			m_pPlayer->Set_Player_Name(_szName);
			break; 
		}
		else {
			cout << "�ٽ� �г����� �Է��ϼ���" << endl;
		}
	}
}

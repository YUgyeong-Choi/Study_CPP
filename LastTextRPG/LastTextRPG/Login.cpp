#include "Login.h"
#include "pch.h"
#include "Define.h"
#include "Warrior.h"
#include "Mage.h"
#include "Fighter.h"


Login::Login():m_pPlayer(nullptr), m_pMenu(nullptr)
{}

Login::~Login()
{
	Release();
}

void Login::Release()
{
	SAFE_DELETE(m_pPlayer);
	SAFE_DELETE(m_pMenu);
}

void Login::Update()
{
	while (1) {
		system("cls");
		bool bIsSelect = false;
		if (m_pPlayer) SAFE_DELETE(m_pPlayer);
		if (m_pMenu) SAFE_DELETE(m_pMenu);

		int _iInput(0);
		cout << "========== �� �÷��̾� �� ==========" << endl;
		cout << "1.              " << endl;
		cout << "2.              " << endl;
		cout << "3.              " << endl;
		cout << "====================================" << endl;
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
			m_pMenu = new MainMenu;
			m_pMenu->Set_PlayerInfo(m_pPlayer);
			m_pMenu->Update();
		}
		system("pause");
	}
}

bool Login::Select_Job()
{
	while (1) {
		system("cls");
		int _iInput(0);
		cout << "============= ���� ���� ============" << endl; 
		cout << "1. ����" << endl;
		cout << "2. ������" << endl;
		cout << "3. ������" << endl;
		cout << "====================================" << endl; 
		cout << "4. �ڷ� ����" << endl;

		cin >> _iInput;
		switch (_iInput)
		{
		case WARRIOR:
			m_pPlayer = new Warrior;
			Create_Name();
			m_pPlayer->Init_Inven();
			return true;
		case MAGE:
			m_pPlayer = new Mage;
			Create_Name();
			m_pPlayer->Init_Inven();
			return true;
		case FIGHTER:
			m_pPlayer = new Fighter;
			Create_Name();
			m_pPlayer->Init_Inven();
			return true;
		case 4:
			return false;
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
			continue;
		}

		system("pause");
	}
}

void Login::Create_Name() {
	string _strName;

	while (true) {
		system("cls");
		cout << "����� �г����� �ۼ����ּ��� " << endl;
		cin >> _strName;

		if (_strName.length() > 0) {
			m_pPlayer->Set_Player_Name(_strName);
			break;
		}
		else {
			cout << "�ٽ� �г����� �Է��ϼ���" << endl;
		}
		system("pause");
	}
}


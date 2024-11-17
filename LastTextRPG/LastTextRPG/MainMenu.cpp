#include "MainMenu.h"

MainMenu::MainMenu():m_pPlayer(nullptr), shopMenu(nullptr), invenMenu(nullptr)
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::Update()
{
	int _iInput(0);
	while (1) {
		system("cls");
		cout << "============= Main Menu ============" << endl; 
		cout << "1. �����" << endl;
		cout << "2. ����" << endl;
		cout << "3. �κ��丮 & ���" << endl;
		cout << "4. ���� ���� ���" << endl; 
		cout << "5. ����" << endl; 
		cout << "====================================" << endl; 
		cout << "6. �ڷ� ����" << endl;
		cin >> _iInput;
		cin.ignore();
		switch (_iInput)
		{
		case 1:
			break;
		case 2:
			shopMenu = new ShopMenu;
			shopMenu->Set_PlayerInfo(m_pPlayer);
			shopMenu->Update();
			SAFE_DELETE(shopMenu);
			break;
		case 3:
			invenMenu = new InvenMenu;
			invenMenu->Set_PlayerInfo(m_pPlayer);
			invenMenu->Update();
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			return;
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
			continue;
		}
		system("pause");
	}
}

void MainMenu::Release()
{
	SAFE_DELETE(shopMenu);
}

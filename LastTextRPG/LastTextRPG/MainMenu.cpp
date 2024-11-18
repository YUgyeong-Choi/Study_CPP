#include "MainMenu.h"

MainMenu::MainMenu():m_pPlayer(nullptr), field(nullptr), shopMenu(nullptr), invenMenu(nullptr)
{
}

MainMenu::~MainMenu()
{
	Release();
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

		switch (_iInput)
		{
		case 1:
			field = new Field;
			field->Set_PlayerInfo(m_pPlayer);
			field->Update();
			SAFE_DELETE<Field*>(field);
			break;
		case 2:
			shopMenu = new ShopMenu;
			shopMenu->Set_PlayerInfo(m_pPlayer);
			shopMenu->Update();
			SAFE_DELETE<ShopMenu*>(shopMenu);
			break;
		case 3:
			invenMenu = new InvenMenu;
			invenMenu->Set_PlayerInfo(m_pPlayer);
			invenMenu->Update();
			SAFE_DELETE<InvenMenu*>(invenMenu);
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
	SAFE_DELETE<Field*>(field);
	SAFE_DELETE<ShopMenu*>(shopMenu);
	SAFE_DELETE<InvenMenu*>(invenMenu);
}

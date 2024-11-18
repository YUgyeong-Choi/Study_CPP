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
		cout << "1. 사냥터" << endl;
		cout << "2. 상점" << endl;
		cout << "3. 인벤토리 & 장비" << endl;
		cout << "4. 스탯 정보 출력" << endl; 
		cout << "5. 도박" << endl; 
		cout << "====================================" << endl; 
		cout << "6. 뒤로 가기" << endl;
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
			cout << "잘못 입력하셨습니다" << endl;
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

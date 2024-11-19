#include "ShopMenu.h"
#include "PotionShop.h"
#include "WeaponShop.h"
#include "ArmorShop.h"
#include "Color.h"

ShopMenu::ShopMenu() :m_pPlayer(nullptr), m_shop(nullptr)
{}

ShopMenu::~ShopMenu()
{
}

void ShopMenu::Update()
{
	int _iInput(0);
	while (1) {
		system("cls"); setColor(YELLOW);
		cout << "============ 상점 ===============" << endl; setColor(GRAY);
		cout << "1. 물약 상점" << endl;
		cout << "2. 무기 상점" << endl;
		cout << "3. 방어구 상점" << endl; setColor(YELLOW);
		cout << "=================================" << endl; setColor(GRAY);
		cout << "4. 뒤로 가기" << endl;
	
		cin >> _iInput;
		switch (_iInput)
		{
		case 1:
			m_shop = new PotionShop;
			break;
		case 2:
			m_shop = new WeaponShop;
			break;
		case 3:
			m_shop = new ArmorShop;
			break;
		case 4:
			return;
		default:
			break;
		}

		if (m_shop) {
			m_shop->Set_PlayerInfo(m_pPlayer);
			m_shop->Update();
			SAFE_DELETE<Shop*>(m_shop);
		}
		system("pause");
	}
}

void ShopMenu::Release()
{
	SAFE_DELETE<Shop*>(m_shop);
}

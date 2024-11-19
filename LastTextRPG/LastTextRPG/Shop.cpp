#include "Shop.h"
#include "Color.h"

Shop::Shop():m_pPlayer(nullptr)
{
}

Shop::~Shop()
{
	Release();
}

void Shop::Update()
{
	while (1) {
		system("cls");
		for (size_t i = 0; i < shopItems.size(); ++i) {
			cout << i + 1 << ". " << shopItems[i]->Get_ItemName() << endl;
			cout << "가격: " << shopItems[i]->Get_ItemPrice() << endl;
			cout << "설명: ";
			shopItems[i]->use(); setColor(SKYBLUE);
			cout << "=========================" << endl; setColor(GRAY);
		}

		for (size_t i = 0; i < shopItems.size(); ++i) {
			cout << i + 1 << "." << shopItems[i]->Get_ItemName() << endl;
		}
		cout << shopItems.size() + 1 << ".뒤로 가기" << endl;

		cout << "보유액: " << m_pPlayer->Get_PlayerInfo().iMoney << endl << endl;

		int _iInput(0);
		cin >> _iInput;
		if (1 <= _iInput && _iInput <= shopItems.size()) {
			if (m_pPlayer->Get_PlayerInfo().iMoney >= shopItems[_iInput - 1]->Get_ItemPrice()) {
				m_pPlayer->Add_PlayerMoney(-shopItems[_iInput - 1]->Get_ItemPrice());
				m_pPlayer->Get_InvenInfo()->AddItem(shopItems[_iInput-1]);

				cout << "구매하셨습니다" << endl;
			}
			else {
				cout << "돈이 부족합니다" << endl;
				cout << "보유액: " << m_pPlayer->Get_PlayerInfo().iMoney << endl;
			}
		}
		else if (_iInput == shopItems.size() + 1) {
			return;
		}
		else {
			cout << "잘못 입력하셨습니다" << endl;
			continue;
		}

		system("pause");
	}
}

void Shop::Release()
{
	for_each(shopItems.begin(), shopItems.end(), SAFE_DELETE<Item*>);
}

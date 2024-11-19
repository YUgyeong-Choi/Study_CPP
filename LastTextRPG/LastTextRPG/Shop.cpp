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
			cout << "����: " << shopItems[i]->Get_ItemPrice() << endl;
			cout << "����: ";
			shopItems[i]->use(); setColor(SKYBLUE);
			cout << "=========================" << endl; setColor(GRAY);
		}

		for (size_t i = 0; i < shopItems.size(); ++i) {
			cout << i + 1 << "." << shopItems[i]->Get_ItemName() << endl;
		}
		cout << shopItems.size() + 1 << ".�ڷ� ����" << endl;

		cout << "������: " << m_pPlayer->Get_PlayerInfo().iMoney << endl << endl;

		int _iInput(0);
		cin >> _iInput;
		if (1 <= _iInput && _iInput <= shopItems.size()) {
			if (m_pPlayer->Get_PlayerInfo().iMoney >= shopItems[_iInput - 1]->Get_ItemPrice()) {
				m_pPlayer->Add_PlayerMoney(-shopItems[_iInput - 1]->Get_ItemPrice());
				m_pPlayer->Get_InvenInfo()->AddItem(shopItems[_iInput-1]);

				cout << "�����ϼ̽��ϴ�" << endl;
			}
			else {
				cout << "���� �����մϴ�" << endl;
				cout << "������: " << m_pPlayer->Get_PlayerInfo().iMoney << endl;
			}
		}
		else if (_iInput == shopItems.size() + 1) {
			return;
		}
		else {
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
			continue;
		}

		system("pause");
	}
}

void Shop::Release()
{
	for_each(shopItems.begin(), shopItems.end(), SAFE_DELETE<Item*>);
}

#include "InvenMenu.h"
void InvenMenu::Update()
{
	int _iInput(0);
	while (1) {
		system("cls");
		cout << "========== �κ��丮 ===========" << endl;
		cout << "1. ���� " << endl;
		cout << "2. ����" << endl;
		cout << "3. ��" << endl;
		cout << "===============================" << endl;
		cout << "4. �ڷ� ����" << endl;
		cin >> _iInput;
		switch (_iInput)
		{
		case 1:
			m_pPlayer->Get_InvenInfo()->Render("potion");
			break;
		case 2:
			if (m_pPlayer->Get_InvenInfo()->WeaponSize() != 0) {
				int _iInput2(0);
				while (1) {
					system("cls");
					m_pPlayer->Get_InvenInfo()->Render("weapon");
					Item* item = nullptr;
					cout << "1.���� 2.���� ���� 3.������" << endl;
					cin >> _iInput2;
					switch (_iInput2)
					{
					case 1:
						item  = m_pPlayer->Get_InvenInfo()->SelectEuip("weapon");
						if (item != nullptr) {
							m_pPlayer->equip(item);
						}
						break;
					case 2:
						m_pPlayer->unequip("weapon");
						break;
					case 3:
						return;
					default:
						cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
						continue;
					}
				}
			}
			break;
		case 3:
			m_pPlayer->Get_InvenInfo()->Render("armor");
			if (m_pPlayer->Get_InvenInfo()->ArmorSize() != 0) {
				int _iInput2(0);
				while (1) {
					system("cls");
					Item* item = nullptr;
					cout << "1.���� 2.���� ���� 3.������" << endl;
					cin >> _iInput2;
					switch (_iInput2)
					{
					case 1:
						item = m_pPlayer->Get_InvenInfo()->SelectEuip("armor");
						if (item != nullptr) {
							m_pPlayer->equip(item);
						}
						break;
					case 2:
						m_pPlayer->unequip("armor");
						break;
					case 3:
						return;
					default:
						cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
						continue;
					}
				}
			}
			break;
		case 4:
			return;
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
			continue;
		}
		system("pause");
	}
}

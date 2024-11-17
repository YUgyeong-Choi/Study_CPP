#include "InvenMenu.h"
void InvenMenu::Update()
{
	int _iInput(0);
	while (1) {
		system("cls");
		cout << "========== 인벤토리 ===========" << endl;
		cout << "1. 물약 " << endl;
		cout << "2. 무기" << endl;
		cout << "3. 방어구" << endl;
		cout << "===============================" << endl;
		cout << "4. 뒤로 가기" << endl;
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
					cout << "1.장착 2.장착 해제 3.나가기" << endl;
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
						cout << "잘못 입력하셨습니다" << endl;
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
					cout << "1.장착 2.장착 해제 3.나가기" << endl;
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
						cout << "잘못 입력하셨습니다" << endl;
						continue;
					}
				}
			}
			break;
		case 4:
			return;
		default:
			cout << "잘못 입력하셨습니다" << endl;
			continue;
		}
		system("pause");
	}
}

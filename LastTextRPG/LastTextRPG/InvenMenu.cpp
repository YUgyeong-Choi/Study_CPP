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
			m_pPlayer->Get_InvenInfo()->RenderPotion();
			break;
		case 2:
			if (m_pPlayer->Get_InvenInfo()->RenderWeapon() != 0){
				SelectEquip("weapon");
			}
			break;
		case 3:
			if (m_pPlayer->Get_InvenInfo()->RenderArmor() != 0) {
				SelectEquip("armor");
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

void InvenMenu::SelectEquip(string type)
{
	while (1) {
		int _iInput(0);
		cout << "1.장착 2.탈착 3.나가기" << endl;
		cin >> _iInput;
		switch (_iInput)
		{
		case 1:
			m_pPlayer->Get_InvenInfo()->EquipItem(type);
			break;
		case 2:
			m_pPlayer->Get_InvenInfo()->EquipItem(type);
			break;
		case 3:
			return;
		default:
			cout << "잘못 입력하셨습니다" << endl;
			continue;
		}
	}
}
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
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
			continue;
		}
		system("pause");
	}
}

void InvenMenu::SelectEquip(string type)
{
	while (1) {
		int _iInput(0);
		cout << "1.���� 2.Ż�� 3.������" << endl;
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
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
			continue;
		}
	}
}
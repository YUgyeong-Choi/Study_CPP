#include "WeaponStore.h"
#include "WearItem.h"
#include "Color.h"


WeaponStore::WeaponStore()
{
	items.push_back(new WearItem("�ʱ� ����", 0, 50, 50, IT_WEAPON, EQUIP));
	items.push_back(new WearItem("�߱� ����", 0, 100, 150, IT_WEAPON, EQUIP));
	items.push_back(new WearItem("��� ����", 0, 150, 300, IT_WEAPON, EQUIP));
}

WeaponStore::~WeaponStore()
{
}

void WeaponStore::Render()
{
	setColor(YELLOW);
	cout << "============= ���� ���� =============" << endl; setColor(GRAY);
	for (size_t i = 0; i < items.size(); ++i) {
		cout << i + 1 << ". " << items[i]->Get_ItemInfo().szName << endl;
		cout << "���ݷ��� " << items[i]->Get_ItemInfo().iAttack << "��ŭ �ø��ϴ�" << endl;
		cout << "����: " << items[i]->Get_ItemInfo().iPrice << endl;
		setColor(BLUE); cout << "------------------------------------" << endl; setColor(GRAY);
	}

	setColor(YELLOW);
	cout << "===================================" << endl; setColor(GRAY);
}

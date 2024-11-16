#include "ArmorStore.h"
#include "Color.h"
#include "WearItem.h"


ArmorStore::ArmorStore()
{
	items.push_back(new WearItem("�ʱ� ��", 40, 0, 40, IT_ARMOR, EQUIP));
	items.push_back(new WearItem("�߱� ��", 80, 0, 120, IT_ARMOR, EQUIP));
	items.push_back(new WearItem("��� ��", 120, 0, 260, IT_ARMOR, EQUIP));
}

ArmorStore::~ArmorStore()
{
}

void ArmorStore::Render()
{
	setColor(YELLOW);
	cout << "=========== �� ���� ============" << endl; setColor(GRAY);
	for (size_t i = 0; i < items.size(); ++i) {
		cout << i + 1 << ". " << items[i]->Get_ItemInfo().szName << endl;
		cout << "������ " << items[i]->Get_ItemInfo().iHp << "��ŭ �ø��ϴ�" << endl;
		cout << "����: " << items[i]->Get_ItemInfo().iPrice << endl;
		setColor(BLUE); cout << "------------------------------------" << endl; setColor(GRAY);
	}

	setColor(YELLOW);
	cout << "===================================" << endl; setColor(GRAY);
}

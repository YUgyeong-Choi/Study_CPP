#include "PotionStore.h"
#include "Color.h"
#include "EatItem.h"

PotionStore::PotionStore()
{
	items.push_back(new EatItem("ȸ�� ���� (��)", 30, 0 ,15, IT_POTION));
	items.push_back(new EatItem("ȸ�� ���� (��)", 70, 0 ,30, IT_POTION));
	items.push_back(new EatItem("ȸ�� ���� (��)", 150, 0 ,60, IT_POTION));
}

PotionStore::~PotionStore()
{
}

void PotionStore::Render()
{
	setColor(YELLOW);
	cout << "============= ������ ==============" << endl; setColor(GRAY);
	for (size_t i = 0; i<items.size(); ++i) {
		cout << i+1 << ". " << items[i]->Get_ItemInfo().szName << endl;
		cout << "ü���� " << items[i]->Get_ItemInfo().iHp << "ȸ�� ��ŵ�ϴ�" << endl;
		cout << "����: " << items[i]->Get_ItemInfo().iPrice << endl;
		setColor(BLUE); cout << "------------------------------------" << endl; setColor(GRAY);
	}

	setColor(YELLOW);
	cout << "===================================" << endl; setColor(GRAY);
}
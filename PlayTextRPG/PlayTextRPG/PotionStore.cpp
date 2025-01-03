#include "PotionStore.h"
#include "Color.h"
#include "EatItem.h"

PotionStore::PotionStore()
{
	items.push_back(new EatItem("회복 포션 (소)", 30, 0 ,15, IT_POTION));
	items.push_back(new EatItem("회복 포션 (중)", 70, 0 ,30, IT_POTION));
	items.push_back(new EatItem("회복 포션 (대)", 150, 0 ,60, IT_POTION));
}

PotionStore::~PotionStore()
{
}

void PotionStore::Render()
{
	setColor(YELLOW);
	cout << "============= 아이템 ==============" << endl; setColor(GRAY);
	for (size_t i = 0; i<items.size(); ++i) {
		cout << i+1 << ". " << items[i]->Get_ItemInfo().szName << endl;
		cout << "체력을 " << items[i]->Get_ItemInfo().iHp << "회복 시킵니다" << endl;
		cout << "가격: " << items[i]->Get_ItemInfo().iPrice << endl;
		setColor(BLUE); cout << "------------------------------------" << endl; setColor(GRAY);
	}

	setColor(YELLOW);
	cout << "===================================" << endl; setColor(GRAY);
}

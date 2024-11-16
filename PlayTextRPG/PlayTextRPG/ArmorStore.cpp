#include "ArmorStore.h"
#include "Color.h"
#include "WearItem.h"


ArmorStore::ArmorStore()
{
	items.push_back(new WearItem("초급 방어구", 40, 0, 40, IT_ARMOR, EQUIP));
	items.push_back(new WearItem("중급 방어구", 80, 0, 120, IT_ARMOR, EQUIP));
	items.push_back(new WearItem("고급 방어구", 120, 0, 260, IT_ARMOR, EQUIP));
}

ArmorStore::~ArmorStore()
{
}

void ArmorStore::Render()
{
	setColor(YELLOW);
	cout << "=========== 방어구 상점 ============" << endl; setColor(GRAY);
	for (size_t i = 0; i < items.size(); ++i) {
		cout << i + 1 << ". " << items[i]->Get_ItemInfo().szName << endl;
		cout << "방어력을 " << items[i]->Get_ItemInfo().iHp << "만큼 올립니다" << endl;
		cout << "가격: " << items[i]->Get_ItemInfo().iPrice << endl;
		setColor(BLUE); cout << "------------------------------------" << endl; setColor(GRAY);
	}

	setColor(YELLOW);
	cout << "===================================" << endl; setColor(GRAY);
}

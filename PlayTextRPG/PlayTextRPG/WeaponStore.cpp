#include "WeaponStore.h"
#include "WearItem.h"
#include "Color.h"


WeaponStore::WeaponStore()
{
	items.push_back(new WearItem("초급 무기", 0, 50, 50, IT_WEAPON, EQUIP));
	items.push_back(new WearItem("중급 무기", 0, 100, 150, IT_WEAPON, EQUIP));
	items.push_back(new WearItem("고급 무기", 0, 150, 300, IT_WEAPON, EQUIP));
}

WeaponStore::~WeaponStore()
{
}

void WeaponStore::Render()
{
	setColor(YELLOW);
	cout << "============= 무기 상점 =============" << endl; setColor(GRAY);
	for (size_t i = 0; i < items.size(); ++i) {
		cout << i + 1 << ". " << items[i]->Get_ItemInfo().szName << endl;
		cout << "공격력을 " << items[i]->Get_ItemInfo().iAttack << "만큼 올립니다" << endl;
		cout << "가격: " << items[i]->Get_ItemInfo().iPrice << endl;
		setColor(BLUE); cout << "------------------------------------" << endl; setColor(GRAY);
	}

	setColor(YELLOW);
	cout << "===================================" << endl; setColor(GRAY);
}

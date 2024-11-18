#include "Inventory.h"
#include "Potion.h"
#include "Weapon.h"
#include "Armor.h"

void Inventory::AddItem(Item* item)
{
	if (dynamic_cast<Potion*>(item)) {
		if (invenPotion.find(item->Get_ItemIndex()) == invenPotion.end()) {
			invenPotion[item->Get_ItemIndex()] = item;
		}
		invenPotionCount[item->Get_ItemIndex()] += 1;
	}

	if (dynamic_cast<Weapon*>(item)) {
		if (invenWeapon.find(item->Get_ItemIndex()) == invenWeapon.end()) {
			invenWeapon[item->Get_ItemIndex()] = item;
		}
		invenWeaponCount[item->Get_ItemIndex()] += 1;
	}

	if (dynamic_cast<Armor*>(item)) {
		if (invenArmor.find(item->Get_ItemIndex()) == invenArmor.end()) {
			invenArmor[item->Get_ItemIndex()] = item;
		}
		invenArmorCount[item->Get_ItemIndex()] += 1;
	}
}

//void Inventory::useItem(const string& itemName)
//{
//	if (inven.find(itemName) != inven.end() && invenCount[itemName] > 0) {
//		inven[itemName]->use();
//		invenCount[itemName]--;
//		if (Potion* potion = dynamic_cast<Potion*>(inven[itemName])) {
//			//player->usePotion(potion);
//		}
//		if (Equipment* equipItem = dynamic_cast<Equipment*>(inven[itemName])) {
//			//player->equip(equipItem);
//		}
//	}
//}

void Inventory::Render(string type) {
	system("cls");
	if (type == "potion") {
		int size(0);
		cout << "============ 물약 ============" << endl;
		for (const auto& pair : invenPotion) {
			cout << size + 1 << "번째 아이템" << endl;
			cout << "이름:" << pair.first << "\t보유 개수: " << invenPotionCount[pair.first] << endl;
			pair.second->use();
			size++;

			cout << "====================" << endl;
		}
		if (size == 0) {
			cout << "비어 있습니다" << endl;
		}
	}

	if (type == "weapon") {
		int size(0);
		cout << "============ 무기 ============" << endl;
		for (const auto& pair : invenWeapon) {
			cout << size + 1 << "번째 아이템" << endl;
			cout << "이름:" << pair.first << "\t보유 개수: " << invenWeaponCount[pair.first] << endl;
			pair.second->use();
			size++;

			cout << "====================" << endl;
		}
		if (size == 0) {
			cout << "비어 있습니다" << endl;
		}
	}

	if (type == "armor") {
		int size(0);
		cout << "============ 방어구 ============" << endl;
		for (const auto& pair : invenArmor) {
			cout << size + 1 << "번째 아이템"  << endl;
			cout << "이름:" << pair.first << "\t보유 개수: " << invenArmorCount[pair.first] << endl;
			pair.second->use();
			size++;

			cout << "====================" << endl;
		}
		if (size == 0) {
			cout << "비어 있습니다" << endl;
		}
	}
}

Item* Inventory::SelectEuip(string type)
{
	int size(0);
	int _iInput(0);
	while (1) {
		system("cls");
		if (type == "weapon") {
			cout << "============ 무기 ============" << endl;
			for (const auto& pair : invenWeapon) {
				cout << size + 1 << "번째 아이템" << endl;
				cout << "이름:" << pair.first << "\t보유 개수: " << invenWeaponCount[pair.first] << endl;
				pair.second->use();
				size++;
				cout << "====================" << endl;
			}

			size = 0;
			for (const auto& pair : invenWeapon) {
				cout << size + 1 << ". " << pair.first << endl;
				size++;
			}

		}

		if (type == "armor") {
			cout << "============ 방어구 ============" << endl;
			for (const auto& pair : invenArmor) {
				cout << size + 1 << "번째 아이템" << endl;
				cout << "이름:" << pair.first << "\t보유 개수: " << invenArmorCount[pair.first] << endl;
				pair.second->use();
				size++;
				cout << "====================" << endl;
			}

			size = 0;
			for (const auto& pair : invenArmor) {
				cout << size + 1 << ". " << pair.first << endl;
				size++;
			}
			cout << size + 1 << ". 뒤로 가기" << endl;
		}

		cin >> _iInput;

		if (1 <= _iInput && _iInput <= size) {
			if (type == "weapon") {
				size = 0;
				for (const auto& pair : invenWeapon) {
					size++;
					if (size == _iInput) {
						return pair.second;
					}
				}
			}
			if (type == "armor") {
				size = 0;
				for (const auto& pair : invenArmor) {
					size++;
					if (size == _iInput) {
						return pair.second;
					}
				}
			}
		}
		else if (_iInput == size + 1) {
			return nullptr;
		}
		system("pause");
	}

}

int Inventory::FightInventory()
{
	vector<Item*> potionItems;
	int size(0);
	while (1) {
		cout << "============ 물약 ============" << endl;
		for (const auto& pair : invenPotion) {
			cout << size + 1 << "번째 아이템" << endl;
			cout << "이름:" << pair.first << "\t보유 개수: " << invenPotionCount[pair.first] << endl;
			potionItems.push_back(pair.second);
			size++;
			
		}
		if (size == 0) {
			cout << "비어 있습니다" << endl;
			system("pause");
			return 0;
		}

		size = 0;
		for (const auto& item : potionItems) {
			cout << size + 1 << ". "  << item->Get_ItemName() << endl;
			size++;
		}
		cout << size + 1 << ". 뒤로 가기" << endl;



		int _iInput(0);
		cin >> _iInput;
		if (1 <= _iInput && size >= _iInput) {
			if (Potion* potion = dynamic_cast<Potion*>(potionItems[_iInput - 1])) {
				potion->use();
				invenPotionCount[potion->Get_ItemIndex()]--;
				if (invenPotionCount[potion->Get_ItemIndex()] == 0) {
					invenPotion.erase(potion->Get_ItemIndex());
				}
				return potion->Get_healAmount();
			}
		}
		else if (_iInput == size + 1) {
			return 0;
		}
		else {
			continue;
		}
	}
}

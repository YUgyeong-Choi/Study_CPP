#include "Inventory.h"
#include "Armor.h"
#include "Color.h"

Inventory::~Inventory()
{
	for (auto& pair : invenPotion) {
		SAFE_DELETE<Potion*>(pair.second);
	}
	invenPotion.clear();

	for (auto& pair : invenWeapon) {
		SAFE_DELETE<Weapon*>(pair.second);
	}
	invenWeapon.clear();

	for (auto& pair : invenArmor) {
		SAFE_DELETE<Armor*>(pair.second);
	}
	invenArmor.clear();
}

void Inventory::AddItem(Item* item)
{
	if (dynamic_cast<Potion*>(item)) {
		Potion* potion = new Potion(*dynamic_cast<Potion*>(item));
		if (invenPotion.find(item->Get_ItemIndex()) == invenPotion.end()) {
			invenPotion[item->Get_ItemIndex()] = potion;
		}
		invenPotionCount[item->Get_ItemIndex()] += 1;
	}

	if (dynamic_cast<Weapon*>(item)) {
		Weapon* weapon = new Weapon(*dynamic_cast<Weapon*>(item));
		if (invenWeapon.find(item->Get_ItemIndex()) == invenWeapon.end()) {
			invenWeapon[item->Get_ItemIndex()] = weapon;
		}
		invenWeaponCount[item->Get_ItemIndex()] += 1;
	}

	if (dynamic_cast<Armor*>(item)) {
		Armor* armor = new Armor(*dynamic_cast<Armor*>(item));
		if (invenArmor.find(item->Get_ItemIndex()) == invenArmor.end()) {
			invenArmor[item->Get_ItemIndex()] = armor;
		}
		invenArmorCount[item->Get_ItemIndex()] += 1;
	}
}

void Inventory::Render(string type) {
	system("cls");
	if (type == "potion") {
		int size(0); setColor(YELLOW);
		cout << "============ 물약 ============" << endl; setColor(GRAY);
		for (const auto& pair : invenPotion) {
			cout << size + 1 << "번째 아이템" << endl;
			cout << "이름:" << pair.second->Get_ItemName() << "\t보유 개수: " << invenPotionCount[pair.first] << endl;
			pair.second->use();
			size++;
			setColor(YELLOW);
			cout << "====================" << endl; setColor(GRAY);
		}
		if (size == 0) {
			cout << "비어 있습니다" << endl;
		}
	}

	if (type == "weapon") {
		int size(0); setColor(YELLOW);
		cout << "============ 무기 ============" << endl; setColor(GRAY);
		for (const auto& pair : invenWeapon) {
			cout << size + 1 << "번째 아이템" << endl;
			cout << "이름:" << pair.second->Get_ItemName() << "\t보유 개수: " << invenWeaponCount[pair.first] << endl;
			pair.second->use();
			size++;
			setColor(YELLOW);
			cout << "====================" << endl; setColor(GRAY);
		}
		if (size == 0) {
			cout << "비어 있습니다" << endl;
		}
	}

	if (type == "armor") {
		int size(0); setColor(YELLOW);
		cout << "============ 방어구 ============" << endl; setColor(GRAY);
		for (const auto& pair : invenArmor) {
			cout << size + 1 << "번째 아이템"  << endl;
			cout << "이름:" << pair.second->Get_ItemName() << "\t보유 개수: " << invenArmorCount[pair.first] << endl;
			pair.second->use();
			size++;
			setColor(YELLOW);
			cout << "====================" << endl; setColor(GRAY);
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
			setColor(YELLOW);
			cout << "============ 무기 ============" << endl; setColor(GRAY);
			for (const auto& pair : invenWeapon) {
				cout << size + 1 << "번째 아이템" << endl;
				cout << "이름:" << pair.second->Get_ItemName() << "\t보유 개수: " << invenWeaponCount[pair.first] << endl;
				pair.second->use();
				size++; setColor(YELLOW);
				cout << "====================" << endl; setColor(GRAY);
			}

			size = 0;
			for (const auto& pair : invenWeapon) {
				cout << size + 1 << ". " << pair.second->Get_ItemName() << endl;
				size++;
			}

		}

		if (type == "armor") {
			setColor(YELLOW);
			cout << "============ 방어구 ============" << endl; setColor(GRAY);
			for (const auto& pair : invenArmor) {
				cout << size + 1 << "번째 아이템" << endl;
				cout << "이름:" << pair.second->Get_ItemName() << "\t보유 개수: " << invenArmorCount[pair.first] << endl;
				pair.second->use();
				size++; setColor(YELLOW);
				cout << "====================" << endl; setColor(GRAY);
			}

			size = 0;
			for (const auto& pair : invenArmor) {
				cout << size + 1 << ". " << pair.second->Get_ItemName() << endl;
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
	vector<Potion*> potionItems;
	int size(0);
	while (1) {
		setColor(YELLOW);
		cout << "============ 물약 ============" << endl; setColor(GRAY);
		for (const auto& pair : invenPotion) {
			cout << size + 1 << "번째 아이템" << endl;
			cout << "이름:" << pair.second->Get_ItemName() << "\t보유 개수: " << invenPotionCount[pair.first] << endl;
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
			if (Potion* potion = potionItems[_iInput - 1]) {
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

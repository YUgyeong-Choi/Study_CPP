#include "Inventory.h"
#include "Potion.h"
#include "Weapon.h"
#include "Armor.h"
#include "Equipment.h"

void Inventory::AddItem(Item* item)
{
	if (inven.find(item->Get_ItemName()) == inven.end()) {
		inven[item->Get_ItemName()] = item;
	}
	invenCount[item->Get_ItemName()] += 1;
}

void Inventory::useItem(const string& itemName)
{
	if (inven.find(itemName) != inven.end() && invenCount[itemName] > 0) {
		inven[itemName]->use();
		invenCount[itemName]--;
		if (Potion* potion = dynamic_cast<Potion*>(inven[itemName])) {
			//player->usePotion(potion);
		}
		if (Equipment* equipItem = dynamic_cast<Equipment*>(inven[itemName])) {
			//player->equip(equipItem);
		}
	}
}

void Inventory::RenderPotion()
{
	system("cls");
	int size(0);
	cout << "========== ���� ==========" << endl;
	for (const auto& pair : inven) {
		if (dynamic_cast<Potion*>(pair.second)) {
			cout << "�̸�: " << pair.first << "\t���� ���� : " << invenCount[pair.first] << endl;
			pair.second->use();
			cout << "==========================" << endl;
			size++;
		}
	}
	if (size == 0) {
		cout << "����ֽ��ϴ�" << endl;
	}
	system("pause");
}

int Inventory::RenderWeapon()
{
	system("cls");
	int size(0);
	cout << "============= ���� =============" << endl;
	for (const auto& pair : inven) {
		if (dynamic_cast<Weapon*>(pair.second)) {
			cout << size + 1 << "��°" << endl;
			cout << "�̸�: " << pair.first << "\t���� ���� : " << invenCount[pair.first] << endl;
			pair.second->use();
			cout << "==========================" << endl;
			size++;
		}
	}
	if (size == 0) {
		cout << "����ֽ��ϴ�" << endl;
	}
	return size;
}

int Inventory::RenderArmor()
{
	system("cls");
	int size(0);
	cout << "========== �� ==========" << endl;
	for (const auto& pair : inven) {
		if (dynamic_cast<Armor*>(pair.second)) {
			cout << size + 1 << "��°" << endl;
			cout << "�̸�: " << pair.first << "\t���� ���� : " << invenCount[pair.first] << endl;
			pair.second->use();
			cout << "==========================" << endl;
			size++;
		}
	}
	if (size == 0) {
		cout << "����ֽ��ϴ�" << endl;
	}
	return size;
}

void Inventory::EquipItem(string type)
{
	int size = 0;
	if (type == "weapon") {
		size = RenderWeapon();
	}
	//for()
}

void Inventory::UnequipItem(string type)
{
}

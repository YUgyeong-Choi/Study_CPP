#include "Inventory.h"
#include "Color.h"
#include "pch.h"

Inventory::Inventory()
{
	items[0] = { "���� ����", 30, 0, 0 };
	items[1] = { "���� ����", 70, 0,0 };
	items[2] = { "���� ����", 150, 0,0 };
}

void Inventory::Render()
{
	system("cls");
	setColor(SKYBLUE);
	cout << "============== �� ������ ===========" << endl; setColor(GRAY);
	for (int i = 0; i < 3; ++i) {
		cout << items[i].szName << " : " << items[i].iPrice<<endl;
	}
	setColor(SKYBLUE);
	cout << "====================================" << endl; setColor(GRAY);
	cout << "�ƹ� ��ư ������ �ڷ� ���ϴ�" << endl;
	cin.get();
}

void Inventory::Fight_Render()
{
	setColor(SKYBLUE);
	cout << "============== �� ������ ===========" << endl; setColor(GRAY);
	for (int i = 0; i < 3; ++i) {
		cout << items[i].szName << " : " << items[i].iPrice << endl;
	}
	setColor(SKYBLUE);
	cout << "====================================" << endl; setColor(GRAY);
	cout << "4.�ڷ� ����" << endl;
}

void Inventory::Add_Items(int _index)
{
	items[_index].iPrice++;
}
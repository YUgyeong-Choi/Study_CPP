#include "Inventory.h"
#include "Color.h"
#include "pch.h"

Inventory::Inventory()
{
	items[0] = { "소형 포션", 30, 0, 0 };
	items[1] = { "중형 포션", 70, 0,0 };
	items[2] = { "대형 포션", 150, 0,0 };
}

void Inventory::Render()
{
	system("cls");
	setColor(SKYBLUE);
	cout << "============== 내 아이템 ===========" << endl; setColor(GRAY);
	for (int i = 0; i < 3; ++i) {
		cout << items[i].szName << " : " << items[i].iPrice<<endl;
	}
	setColor(SKYBLUE);
	cout << "====================================" << endl; setColor(GRAY);
	cout << "아무 버튼 누르면 뒤로 갑니다" << endl;
	cin.get();
}

void Inventory::Fight_Render()
{
	setColor(SKYBLUE);
	cout << "============== 내 아이템 ===========" << endl; setColor(GRAY);
	for (int i = 0; i < 3; ++i) {
		cout << items[i].szName << " : " << items[i].iPrice << endl;
	}
	setColor(SKYBLUE);
	cout << "====================================" << endl; setColor(GRAY);
	cout << "4.뒤로 가기" << endl;
}

void Inventory::Add_Items(int _index)
{
	items[_index].iPrice++;
}
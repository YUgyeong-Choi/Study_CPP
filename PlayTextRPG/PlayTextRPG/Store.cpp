#include "Store.h"
#include "Color.h"

Store::Store()
{
	m_pPlayer = nullptr;
}

Store::~Store()
{
	Release();
}

void Store::Release()
{
	for_each(items.begin(), items.end(), SAFE_DELETE<Item*>);
	items.clear();
}

void Store::Update()
{
	int _iInput(0);
	while (1) {
		system("cls");
		Render();
		for (size_t i = 0; i < items.size(); ++i) {
			cout << i + 1 << ". " << items[i]->Get_ItemInfo().szName << endl;
		}
		cout << items.size() + 1 << ". 나가기" << endl;
		int _iInput(0);
		cin >> _iInput;

		if (1 <= _iInput && _iInput <= items.size()) {
			//dkdk
		}
		else if (_iInput == items.size() + 1) {
			return;
		}
		else {
			cout << "잘못 입력하셨습니다" << endl;
			continue;
		}
		system("pause");
	}
}



#include "Store.h"
#include "Color.h"

Store::Store()
{
	m_pPlayer = nullptr;
	items.clear();
}

Store::~Store()
{
}

void Store::Update()
{
	int _iInput(0);
	while (1) {
		Render();
		for (size_t i = 0; i < items.size(); ++i) {
			cout << i + 1 << ". " << items[i]->Get_ItemInfo().szName << endl;
		}
		cout << items.size() + 1 << ". ������" << endl;
		int _iInput(0);
		cin >> _iInput;

		if (1 <= _iInput && _iInput <= items.size()) {
			//�����ϴ� ����
		}
		else if (_iInput == items.size() + 1) {
			return;
		}
		else {
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
			continue;
		}
	}
}



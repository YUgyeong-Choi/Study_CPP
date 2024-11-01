#include "Login.h"
#include "pch.h"
#include "Warrior.h"
#include "Fighter.h"
#include "Mage.h"

Login::Login()
{
	m_pPlayer = nullptr;
}

Login::~Login()
{
	Release();
}

void Login::Update()
{
	while (1) {
		int _iInput(0);
		cout << "=======================" << endl;
		cout << "�� �÷��̾��" << endl;
		cout << "1.              " << endl;
		cout << "2.              " << endl;
		cout << "3.              " << endl;
		cout << "=======================" << endl;
		cout << "4. ���� �����ϱ�" << endl;
		cout << "5. ���� �����ϱ�" << endl;

		cin >> _iInput;
		switch (_iInput) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			m_pPlayer = Select_Job();
			break;
		case 5:
			cout << "������ �����մϴ�" << endl;
			return;
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
			continue;
		}
	}

}

void Login::Release() 
{
	SAFE_DELETE(m_pPlayer);
}

Player* Login::Select_Job()
{
	Player* a = new Warrior;
	while (1) {
		int _iInput(0);
		cout << "==========������ �����ϼ���==========" << endl;
		
		a->Skill1();
		a->Skill2();
		cout << a->Get_Info().Job << endl;
		break;
	}

    return a;
}
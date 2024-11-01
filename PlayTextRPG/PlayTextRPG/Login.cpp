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
		cout << "내 플레이어들" << endl;
		cout << "1.              " << endl;
		cout << "2.              " << endl;
		cout << "3.              " << endl;
		cout << "=======================" << endl;
		cout << "4. 새로 생성하기" << endl;
		cout << "5. 게임 종료하기" << endl;

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
			cout << "게임을 종료합니다" << endl;
			return;
		default:
			cout << "잘못 입력하셨습니다" << endl;
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
		cout << "==========직업을 선택하세요==========" << endl;
		
		a->Skill1();
		a->Skill2();
		cout << a->Get_Info().Job << endl;
		break;
	}

    return a;
}
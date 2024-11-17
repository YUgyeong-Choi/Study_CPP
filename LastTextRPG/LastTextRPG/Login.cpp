#include "Login.h"
#include "pch.h"
#include "Define.h"
#include "Warrior.h"
#include "Mage.h"
#include "Fighter.h"


Login::Login():m_pPlayer(nullptr), m_pMenu(nullptr)
{}

Login::~Login()
{
	Release();
}

void Login::Release()
{
	SAFE_DELETE(m_pPlayer);
	SAFE_DELETE(m_pMenu);
}

void Login::Update()
{
	while (1) {
		system("cls");
		bool bIsSelect = false;
		if (m_pPlayer) SAFE_DELETE(m_pPlayer);
		if (m_pMenu) SAFE_DELETE(m_pMenu);

		int _iInput(0);
		cout << "========== 내 플레이어 들 ==========" << endl;
		cout << "1.              " << endl;
		cout << "2.              " << endl;
		cout << "3.              " << endl;
		cout << "====================================" << endl;
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
			bIsSelect = Select_Job();
			if (bIsSelect) {
				break;
			}
			else {
				continue;
			}
		case 5:
			cout << "게임을 종료합니다" << endl;
			return;
		default:
			cout << "잘못 입력하셨습니다" << endl;
			continue;
		}

		if (bIsSelect) {
			m_pMenu = new MainMenu;
			m_pMenu->Set_PlayerInfo(m_pPlayer);
			m_pMenu->Update();
		}
		system("pause");
	}
}

bool Login::Select_Job()
{
	while (1) {
		system("cls");
		int _iInput(0);
		cout << "============= 직업 선택 ============" << endl; 
		cout << "1. 전사" << endl;
		cout << "2. 마법사" << endl;
		cout << "3. 격투가" << endl;
		cout << "====================================" << endl; 
		cout << "4. 뒤로 가기" << endl;

		cin >> _iInput;
		switch (_iInput)
		{
		case WARRIOR:
			m_pPlayer = new Warrior;
			Create_Name();
			m_pPlayer->Init_Inven();
			return true;
		case MAGE:
			m_pPlayer = new Mage;
			Create_Name();
			m_pPlayer->Init_Inven();
			return true;
		case FIGHTER:
			m_pPlayer = new Fighter;
			Create_Name();
			m_pPlayer->Init_Inven();
			return true;
		case 4:
			return false;
		default:
			cout << "잘못 입력하셨습니다" << endl;
			continue;
		}

		system("pause");
	}
}

void Login::Create_Name() {
	string _strName;

	while (true) {
		system("cls");
		cout << "사용할 닉네임을 작성해주세요 " << endl;
		cin >> _strName;

		if (_strName.length() > 0) {
			m_pPlayer->Set_Player_Name(_strName);
			break;
		}
		else {
			cout << "다시 닉네임을 입력하세요" << endl;
		}
		system("pause");
	}
}


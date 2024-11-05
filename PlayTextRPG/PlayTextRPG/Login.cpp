#include "Login.h"
#include "pch.h"
#include "Warrior.h"
#include "Fighter.h"
#include "Mage.h"
#include "Color.h"

Login::Login()
{
	m_pPlayer = nullptr;
	m_pMainmenu = nullptr;
}

Login::~Login()
{
	Release();
}

void Login::Update()
{
	while (1) {
		system("cls");
		bool bIsSelect = false;
		if (m_pPlayer) SAFE_DELETE(m_pPlayer);
		if (m_pMainmenu) SAFE_DELETE(m_pMainmenu);

		int _iInput(0);
		cout << "========== 내 플레이어 들 ==========" << endl; setColor(GRAY);
		cout << "1.              " << endl;
		cout << "2.              " << endl;
		cout << "3.              " << endl; setColor(YELLOW);
		cout << "====================================" << endl; setColor(GRAY);
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
			m_pMainmenu = new Mainmenu;
			m_pMainmenu->Set_PlayerInfo(m_pPlayer);
			m_pMainmenu->Update();
		}
	}
}

void Login::Release() 
{
	SAFE_DELETE(m_pPlayer);
	SAFE_DELETE(m_pMainmenu);
}

bool Login::Select_Job()
{
	while (1) {
		system("cls");
		int _iInput(0);
		setColor(YELLOW);
		cout << "============= 직업 선택 ============" << endl; setColor(GRAY);
		cout << "1. 전사" << endl;
		cout << "2. 마법사" << endl;
		cout << "3. 격투가" << endl; setColor(YELLOW);
		cout << "====================================" << endl; setColor(GRAY);
		cout << "4. 뒤로 가기" << endl;
		
		cin >> _iInput;
		switch (_iInput)
		{
		case WARRIOR:
			m_pPlayer = new Warrior;
			Create_Name();
			return true;
		case MAGE:
			m_pPlayer = new Mage;
			Create_Name();
			return true;
		case FIGHTER:
			m_pPlayer = new Fighter;
			Create_Name();
			return true;
		case END:
			return false;
		default:
			cout << "잘못 입력하셨습니다" << endl;
			continue;
		}
	}
}

void Login::Create_Name() {
	char _szName[32];

	while (true) {
		system("cls");
		setColor(YELLOW);
		cout << m_pPlayer->Get_Info().Job << "을 선택하셨습니다 !" << endl;
		cout << "사용할 닉네임을 작성해주세요 "<<endl;
		setColor(GRAY);
		cin >> _szName;

		if (strlen(_szName) > 0) {
			m_pPlayer->Set_Player_Name(_szName);
			break; 
		}
		else {
			cout << "다시 닉네임을 입력하세요" << endl;
		}
	}
}

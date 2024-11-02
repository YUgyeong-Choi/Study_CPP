#include "Mainmenu.h"
#include "pch.h"

Mainmenu::Mainmenu()
{
	m_pPlayer = nullptr;
	m_pField = nullptr;
}

Mainmenu::~Mainmenu()
{
	Release();
}

void Mainmenu::Release()
{
	SAFE_DELETE(m_pField);
}

void Mainmenu::Update()
{
	int _iInput(0);
	while (1) {
		cout << "============= Main Menu ============" << endl;
		cout << "1. 사냥터" << endl;
		cout << "2. 인벤토리" << endl;
		cout << "3. 상점" << endl;
		cout << "4. 스탯 정보 출력" << endl;
		cout << "5. 뒤로 가기" << endl;
		cout << "====================================" << endl;
		cin >> _iInput;
		switch (_iInput)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			return;
		default:
			cout << "잘못 입력하셨습니다" << endl;
			continue;
		}
	}
}

void Mainmenu::Set_PlayerInfo(Player* pPlayer)
{
	m_pPlayer = pPlayer;
}

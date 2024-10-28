#include "MainGame.h"
#include "pch.h"
#include "Define.h"

MainGame::MainGame()
{
	m_pPlayer = nullptr;
	m_pField = nullptr;
}

MainGame::~MainGame()
{
	Release();
}

void MainGame::Initialize()
{
    if (!m_pPlayer) {
		m_pPlayer = new Player;
    }

    if (!m_pField) {
		m_pField = new Field;
    }

	m_pField->Set_Player(m_pPlayer);
}

void MainGame::Update()
{
	int iInput(0);
	while (1) {
        system("cls");
		cout << "1.���� �ҷ����� 2.���� �����ϱ� 3.����: ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			if (m_pPlayer->Load_Data()) {
				m_pField->Update();
			}
			else {
				continue;
			}
			break;
		case 2:
			if (m_pPlayer->Select_Job()) {
				m_pField->Update();
			}
			else {
				continue;
			}
			break;
		case 3:
			cout << "���α׷��� �����մϴ�." << endl;
			m_pPlayer->Save_Data();
			return;
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
			continue;
		}
	}
}

void MainGame::Release()
{
	SAFE_DELETE(m_pPlayer);
	SAFE_DELETE(m_pField);
}

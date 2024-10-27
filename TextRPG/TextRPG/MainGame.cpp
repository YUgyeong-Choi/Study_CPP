#include "MainGame.h"
#include "pch.h"
#include <stdlib.h>

MainGame::MainGame()
{
	player = nullptr;
}

MainGame::~MainGame()
{
	Release();
}

void MainGame::Initialize()
{
    if (!player) {
        player = new Player;
        player->Initialize();
    }
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
			if (player->Load_Data()) {
				Field();
			}
			else {
				continue;
			}
			break;
		case 2:
			if (player->Select_Job()) {
                cout << "3" << endl;
				Field();
			}
			else {
				return;
			}
			break;
		case 3:
			cout << "���α׷��� �����մϴ�." << endl;
            player->Save_Data();
			return;
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
			continue;
		}
	}
}

void MainGame::Release()
{
	SAFE_DELETE(player);
}

void MainGame::Field()
{
    int     iInput(0);
    Monster* monster = new Monster;
    monster->Initialize();

    bool    bSave(false);

    while (true)
    {
        system("cls");
        player->Render();
        cout << "1.�ʱ� 2.�߱� 3.��� 4.�� �ܰ�: ";
        cin >> iInput;

        switch (iInput)
        {
        case 1:
            monster->Create_Obj("�ʱ�", 3, 30);
            break;

        case 2:
            monster->Create_Obj("�߱�", 6, 60);
            break;

        case 3:
            monster->Create_Obj("���", 9, 90);
            break;

        case 4:
            return;

        default:
            cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
            continue;
        }

		Fight(player, monster);
    }
}

void MainGame::Fight(Player* player, Monster* monster)
{
    int iInput(0);

    while (true)
    {
        system("cls");
        player->Render();
        monster->Render();

        cout << "1. ���� 2. ���� : ";
        cin >> iInput;

        switch (iInput)
        {
        case 1:
            player->Get_Attack(player->Get_Info().m_iHp - monster->Get_Info().m_iAttack);
            monster->Get_Attack(monster->Get_Info().m_iHp - player->Get_Info().m_iAttack);
            break;

        case 2:
            cout << "�������ϴ�" << endl;
            return;

        default:
            cout << "�߸� �Է�" << endl;
            break;
        }

        if (0 >= player->Get_Info().m_iHp)
        {
            cout << "���" << endl;
            player->Die();
            system("pause");
            break;
        }

        if (0 >= monster->Get_Info().m_iHp)
        {
            cout << "�¸�" << endl;
            system("pause");
            break;
        }

    }
}

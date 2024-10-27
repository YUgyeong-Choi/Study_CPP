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
		cout << "1.게임 불러오기 2.새로 시작하기 3.종료: ";
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
			cout << "프로그램을 종료합니다." << endl;
            player->Save_Data();
			return;
		default:
			cout << "잘못 입력하셨습니다." << endl;
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
        cout << "1.초급 2.중급 3.고급 4.전 단계: ";
        cin >> iInput;

        switch (iInput)
        {
        case 1:
            monster->Create_Obj("초급", 3, 30);
            break;

        case 2:
            monster->Create_Obj("중급", 6, 60);
            break;

        case 3:
            monster->Create_Obj("고급", 9, 90);
            break;

        case 4:
            return;

        default:
            cout << "잘못 입력하셨습니다" << endl;
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

        cout << "1. 공격 2. 도망 : ";
        cin >> iInput;

        switch (iInput)
        {
        case 1:
            player->Get_Attack(player->Get_Info().m_iHp - monster->Get_Info().m_iAttack);
            monster->Get_Attack(monster->Get_Info().m_iHp - player->Get_Info().m_iAttack);
            break;

        case 2:
            cout << "도망갑니다" << endl;
            return;

        default:
            cout << "잘못 입력" << endl;
            break;
        }

        if (0 >= player->Get_Info().m_iHp)
        {
            cout << "사망" << endl;
            player->Die();
            system("pause");
            break;
        }

        if (0 >= monster->Get_Info().m_iHp)
        {
            cout << "승리" << endl;
            system("pause");
            break;
        }

    }
}

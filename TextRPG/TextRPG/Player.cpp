#include "Player.h"
#include "pch.h"
#include "Define.h"

Player::Player()
{
	info = nullptr;
}

Player::~Player()
{
    Release();
}

void Player::Initialize()
{
	if (!info) info = new INFO;
}


void Player::Release()
{
    SAFE_DELETE(info);
}

bool Player::Load_Data()
{
    FILE* pLoadFile = NULL;

    errno_t err = fopen_s(&pLoadFile, "../Data/Save.txt", "rb");

    if (0 == err)
    {
        fread((info), sizeof(INFO), 1, pLoadFile);

        cout << "불러오기 성공" << endl;

        fclose(pLoadFile);

        return true;
    }

    else
        cout << "불러오기 실패" << endl;

    return false;
}

bool Player::Save_Data()
{
    FILE* pSaveFile = NULL;

    errno_t err = fopen_s(&pSaveFile, "../Data/Save.txt", "wb");

    if (0 == err)
    {
        fwrite(info, sizeof(INFO), 1, pSaveFile);
        
        cout << "저장 성공" << endl;

        fclose(pSaveFile);
        return true;
    }

    else
        cout << "저장 실패" << endl;

    return false;
}

void Player::Create_Obj(const char* pName, int _iAttack, int _iHp)
{
    strcpy_s(info->m_SzName, sizeof(info->m_SzName), pName);
    info->m_iAttack = _iAttack;
    info->m_iHp = _iHp;
}


bool Player::Select_Job()
{
    int         iInput(0);
    bool bSelect = false;

    while (!bSelect)
    {
        system("cls");
        cout << "직업을 선택하세요(1. 전사 2. 도적 3. 마법사 4. 종료) : ";
        cin >> iInput;

        switch (iInput)
        {
        case WARRIOR:
            Create_Obj("전사", 10, 100);
            bSelect = true;
            break;

        case MAGE:
            Create_Obj("마법사", 10, 100);
            bSelect = true;
            break;

        case THIEF:
            Create_Obj("도적", 10, 100);
            bSelect = true;
            break;
        case END:
            cout << "게임을 종료합니다" << endl;
            return false;

        default:
            cout << "잘못 입력하셨습니다" << endl;
            break;
        }
    }

    return true;
}

void Player::Render()
{
    cout << "================================" << endl;
    cout << "이름 : " << info->m_SzName << endl;
    cout << "체력 : " << info->m_iHp << "\t공격력 : " << info->m_iAttack << endl;
}

INFO Player::Get_Info()
{
    return *info;
}

void Player::Get_Attack(int _iHp)
{
    info->m_iHp = _iHp;
}

void Player::Die()
{
    info->m_iHp = 100;
}

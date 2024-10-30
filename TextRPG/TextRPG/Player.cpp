#include "Player.h"
#include "pch.h"


Player::Player()
{
}

Player::~Player()
{
    Release();
}

void Player::Release(){}

bool Player::Load_Data()
{
    FILE* pLoadFile = NULL;

    errno_t err = fopen_s(&pLoadFile, "../Data/Save.txt", "rb");

    if (0 == err)
    {
        fread(&info, sizeof(INFO), 1, pLoadFile);

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
        fwrite(&info, sizeof(INFO), 1, pSaveFile);
        
        cout << "저장 성공" << endl;

        fclose(pSaveFile);
        return true;
    }

    else
        cout << "저장 실패" << endl;

    return false;
}

void Player::Create_Obj(const char* pName, int _iHp, int _iAttack)
{
    strcpy_s(info.m_SzName, sizeof(info.m_SzName), pName);
    info.m_iHp = _iHp;
    info.m_iAttack = _iAttack;
}


bool Player::Select_Job()
{
    int         iInput(0);
    bool bSelect = false;

    while (!bSelect)
    {
        system("cls");
        cout << "직업을 선택하세요(1. 전사 2. 마법사 3. 도적 4. 종료) : ";
        cin >> iInput;

        switch (iInput)
        {
        case Player::WARRIOR:
            Create_Obj("전사", 100, 10);
            bSelect = true;
            break;

        case Player::MAGE:
            Create_Obj("마법사", 100, 10);
            bSelect = true;
            break;

        case Player::THIEF:
            Create_Obj("도적", 100, 10);
            bSelect = true;
            break;
        case Player::END:
            cout << "게임을 종료합니다" << endl;
            return false;

        default:
            cout << "잘못 입력하셨습니다" << endl;
            break;
        }
    }

    return true;
}

void Player::Render() const
{
    cout << "================================" << endl;
    cout << "이름 : " << info.m_SzName << endl;
    cout << "체력 : " << info.m_iHp << "\t공격력 : " << info.m_iAttack << endl;
}

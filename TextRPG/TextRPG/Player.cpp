#include "Player.h"
#include "pch.h"


Player::Player()
{
}

Player::Player(const char* pName, int _iHp, int _iAttack)
{
    strcpy_s(m_info.m_SzName, sizeof(m_info.m_SzName), pName);
    m_info.m_iAttack = _iAttack;
    m_info.m_iHp = _iHp;
}

Player::~Player()
{
}

bool Player::Load_Data()
{
    FILE* pLoadFile = NULL;

    errno_t err = fopen_s(&pLoadFile, "../Data/Save.txt", "rb");

    if (0 == err)
    {
        fread(&m_info, sizeof(INFO), 1, pLoadFile);

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
        fwrite(&m_info, sizeof(INFO), 1, pSaveFile);
        
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
    strcpy_s(m_info.m_SzName, sizeof(m_info.m_SzName), pName);
    m_info.m_iHp = _iHp;
    m_info.m_iAttack = _iAttack;
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
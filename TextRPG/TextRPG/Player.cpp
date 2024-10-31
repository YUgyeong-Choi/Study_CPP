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

        cout << "�ҷ����� ����" << endl;

        fclose(pLoadFile);

        return true;
    }

    else
        cout << "�ҷ����� ����" << endl;

    return false;
}

bool Player::Save_Data()
{
    FILE* pSaveFile = NULL;

    errno_t err = fopen_s(&pSaveFile, "../Data/Save.txt", "wb");

    if (0 == err)
    {
        fwrite(&m_info, sizeof(INFO), 1, pSaveFile);
        
        cout << "���� ����" << endl;

        fclose(pSaveFile);
        return true;
    }

    else
        cout << "���� ����" << endl;

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
        cout << "������ �����ϼ���(1. ���� 2. ������ 3. ���� 4. ����) : ";
        cin >> iInput;

        switch (iInput)
        {
        case Player::WARRIOR:
            Create_Obj("����", 100, 10);
            bSelect = true;
            break;

        case Player::MAGE:
            Create_Obj("������", 100, 10);
            bSelect = true;
            break;

        case Player::THIEF:
            Create_Obj("����", 100, 10);
            bSelect = true;
            break;
        case Player::END:
            cout << "������ �����մϴ�" << endl;
            return false;

        default:
            cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
            break;
        }
    }

    return true;
}
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
        fwrite(info, sizeof(INFO), 1, pSaveFile);
        
        cout << "���� ����" << endl;

        fclose(pSaveFile);
        return true;
    }

    else
        cout << "���� ����" << endl;

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
        cout << "������ �����ϼ���(1. ���� 2. ���� 3. ������ 4. ����) : ";
        cin >> iInput;

        switch (iInput)
        {
        case WARRIOR:
            Create_Obj("����", 10, 100);
            bSelect = true;
            break;

        case MAGE:
            Create_Obj("������", 10, 100);
            bSelect = true;
            break;

        case THIEF:
            Create_Obj("����", 10, 100);
            bSelect = true;
            break;
        case END:
            cout << "������ �����մϴ�" << endl;
            return false;

        default:
            cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
            break;
        }
    }

    return true;
}

void Player::Render()
{
    cout << "================================" << endl;
    cout << "�̸� : " << info->m_SzName << endl;
    cout << "ü�� : " << info->m_iHp << "\t���ݷ� : " << info->m_iAttack << endl;
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

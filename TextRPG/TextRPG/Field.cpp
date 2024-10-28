#include "Field.h"
#include "pch.h"

Field::Field()
{
    m_pPlayer = nullptr;
    m_pMonster = nullptr;
}

Field::~Field()
{
    Release();
}

void Field::Initialize()
{
}

void Field::Update()
{
    int     iInput(0);
    bool    bSave(false);

    while (true)
    {
        system("cls");
        m_pPlayer->Render();
        cout << "1.�ʱ� 2.�߱� 3.��� 4.�� �ܰ�: ";
        cin >> iInput;

        switch (iInput)
        {
        case 1:
            m_pMonster = new Monster("�ʱ�", 30, 3);
            break;

        case 2:
            m_pMonster = new Monster("�߱�", 60, 6);
            break;

        case 3:
            m_pMonster = new Monster("���", 90, 9);
            break;

        case 4:
            return;

        default:
            cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
            continue;
        }

        Fight();
    }
}

void Field::Release()
{
}

void Field::Set_Player(Player* _pPlayer)
{
    m_pPlayer = _pPlayer;
}

void Field::Fight()
{
    int iInput(0);

    while (true)
    {
        system("cls");
        m_pPlayer->Render();
        m_pMonster->Render();

        cout << "1. ���� 2. ���� : ";
        cin >> iInput;

        switch (iInput)
        {
        case 1:
            m_pPlayer->Set_Damage(m_pMonster->Get_Info().m_iAttack);
            m_pMonster->Set_Damage(m_pPlayer->Get_Info().m_iAttack);
            break;
        case 2:
            cout << "�������ϴ�" << endl;
            return;

        default:
            cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
            break;
        }

        if (0 >= m_pPlayer->Get_Info().m_iHp)
        {
            cout << "���" << endl;
            m_pPlayer->Set_Hp(100);
            system("pause");
            break;
        }

        if (0 >= m_pMonster->Get_Info().m_iHp)
        {
            cout << "�¸�" << endl;
            SAFE_DELETE(m_pMonster);
            system("pause");
            break;
        }
    }
}

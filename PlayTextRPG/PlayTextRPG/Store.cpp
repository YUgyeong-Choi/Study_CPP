#include "Store.h"
#include "pch.h"
#include "Color.h"

Store::Store()
{
    m_pPlayer = nullptr;
    // ���� ������ �ʱ�ȭ
    items[0] = { "���� ����", 30, 15 };
    items[1] = { "���� ����", 70, 30 };
    items[2] = { "���� ����", 150, 60 };

    // ���� ��ȭ ������ �ʱ�ȭ
    items[3] = { "1�ܰ� ��ȭ", 50, 50 };
    items[4] = { "2�ܰ� ��ȭ", 100, 100 };
    items[5] = { "3�ܰ� ��ȭ", 150, 200 };

}

void Store::Update()
{
    int _iInput(0);
    while (1) {
        system("cls");
        cout << "���� �Ӵ�: " << m_pPlayer->Get_Info().iMoney << endl;
        setColor(DARK_VOILET);
        cout << "=============== ���� ===============" << endl; setColor(GRAY);
        for (int i = 0; i < 3; ++i) {
            cout << i+1 << ". " << items[i].szName << endl;
            cout << "����: ü���� " << items[i].add << "��ŭ ȸ����ŵ�ϴ�" << endl;
            cout << "����: " << items[i].iPriceOrCount << endl;
        }

        int weaponIndex = 3 + m_pPlayer->Get_Info().weaponLevel; 
        if (weaponIndex < 6) { 
            cout << "4. " << items[weaponIndex].szName << endl;
            cout << "����: ���� �������� " << items[weaponIndex].add << "%��ŭ ��ȭ��ŵ�ϴ�" << endl;
            cout << "����: " << items[weaponIndex].iPriceOrCount << endl;
        }

        setColor(DARK_VOILET);
        cout << "====================================" << endl; setColor(GRAY);
        cout << "7.�ڷ� ����" << endl;

        cin >> _iInput;

        if (1 <= _iInput && _iInput <= 3) {
            if (items[_iInput - 1].iPriceOrCount > m_pPlayer->Get_Info().iMoney) {
                cout << "���� �����ϴ�..." << endl;
            }
            else {
                m_pPlayer->Sub_PlayerMoney(items[_iInput - 1].iPriceOrCount);
                m_pPlayer->Add_Items(_iInput - 1);
                cout << items[_iInput - 1].szName << "�� �����߽��ϴ�" << endl;
            }
        }
        else if (4 <=_iInput&&_iInput<=6) {
            m_pPlayer->Sub_PlayerMoney(items[_iInput - 1].iPriceOrCount);
            m_pPlayer->Set_Attack(items[_iInput - 1].add);
            cout << "���⸦ ��ȭ�߽��ϴ�" << endl;
        }
        else if (_iInput == 7) {
            cout << "������ �����ϴ�" << endl;
            return;
        }
        else {
            cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
            continue;
        }
    }

}

void Store::Set_PlayerInfo(Player* _pPlayer)
{
    m_pPlayer = _pPlayer;
}

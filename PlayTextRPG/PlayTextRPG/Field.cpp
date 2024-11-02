#include "Field.h"
#include "pch.h"

Field::Field()
{
	m_pPlayer = nullptr;
    m_pLowDungeon = nullptr;
}

Field::~Field()
{
	Release();
}

void Field::Update() {
    int _iInput(0);

    while (true) {
        cout << "============= ���� ���� ============" << endl;
        cout << "1. �ϱ� ���� ����" << endl;
        cout << "2. �߱� ���� ����" << endl;
        cout << "3. ��� ���� ����" << endl;

        cout << "============= ���� ���� ============" << endl;

        struct DungeonOption {
            int stageRequirement;
            const char* entryText;
            const char* clearText;
        };

        DungeonOption bossOptions[] = {
            {LOW, "�ϱ� ���� ���� ����", "�ϱ� ���� ��Ŭ����"},
            {MIDDLE, "�߱� ���� ���� ����", "�߱� ���� ��Ŭ����"},
            {HIGH, "��� ���� ���� ����", "��� ���� ��Ŭ����"}
        };

        for (int i = 0; i < 3; ++i) {
            if (m_pPlayer->Get_Info().Stage > bossOptions[i].stageRequirement) {
                cout << (i + 4) << ". " << bossOptions[i].entryText << endl;
            }
            else {
                cout << (i + 4) << ". " << bossOptions[i].entryText << " (" << bossOptions[i].clearText << ")" << endl;
            }
        }

        cout << "====================================" << endl;

        cin >> _iInput;

        if (_iInput >= 1 && _iInput <= 3) {
            m_pLowDungeon = new LowDungeon;
            m_pLowDungeon->Set_PlayerInfo(m_pPlayer);
            m_pLowDungeon->Update();
            break;
        }
        else if (_iInput >= 4 && _iInput <= 6) {
            int index = _iInput - 4;
            if (m_pPlayer->Get_Info().Stage <= bossOptions[index].stageRequirement) {
                cout << bossOptions[index].clearText << endl;
                continue;
            }
            break;
        }
        else {
            cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
        }
    }
}


void Field::Release()
{
    SAFE_DELETE(m_pLowDungeon);
}

void Field::Set_PlayerInfo(Player* _pPlayer)
{
	m_pPlayer = _pPlayer;
}

#include "Field.h"
#include "LowDungeon.h"
#include "MidDungeon.h"
#include "HighDungeon.h"

Field::Field():m_pPlayer(nullptr), m_pDungeon(nullptr)
{
}

Field::~Field()
{
    Release();
}

void Field::Update() {
    int _iInput(0);

    while (true) {
        system("cls");
        cout << "============= ���� ���� ============" << endl; 
        cout << "1. ��ο� ���� ���� (Level.1)" << endl;
        cout << "2. ������ �� (Level.2)" << endl;
        cout << "3. ȭ���� ���� (Level.3)" << endl;
        cout << "============= ���� ���� ============" << endl; 

        struct DungeonOption {
            int stageRequirement;
            const char* entryText;
        };

        DungeonOption bossOptions[] = {
            {LOW, "Level 1, ���� ����"},
            {MIDDLE, "Level 2, ���� ����"},
            {HIGH, "Level 3, ���� ����"}
        };

        for (int i = 0; i < 3; ++i) {
            if (m_pPlayer->Get_PlayerInfo().Stage > bossOptions[i].stageRequirement) {
                cout << (i + 4) << ". " << bossOptions[i].entryText << endl;
            }
            else {
                cout << (i + 4) << ". " << bossOptions[i].entryText << " ( ��Ŭ���� ) " << endl;
            }
        }
        cout << "====================================" << endl; 
        cout << "7. �ڷ� ����" << endl;

        cin >> _iInput;

        if (_iInput >= 1 && _iInput <= 3) {
            switch (_iInput) {
            case 1:
                cout << "��ο� ���� ������ �����մϴ� (Level.1)" << endl; 
                m_pDungeon = new LowDungeon;
                break;
            case 2:
                cout << "������ ���� �����մϴ� (Level.2)" << endl; 
                m_pDungeon = new MiddleDungeon;
                break;
            case 3:
                cout << "ȭ���� �������� �����մϴ� (Level.3)" << endl; 
                m_pDungeon = new HighDungeon;
                break;
            }

            system("pause");

            m_pDungeon->Set_PlayerInfo(m_pPlayer);
            m_pDungeon->Update();

        }
        else if (_iInput >= 4 && _iInput <= 6) {
            int index = _iInput - 4;
            if (m_pPlayer->Get_PlayerInfo().Stage <= bossOptions[index].stageRequirement) {
                cout << "������ Ŭ�����ϰ� ���ּ���" << endl;
                cin.ignore();
                cin.get();
                continue;
            }

        }
        else if (_iInput == 7) {
            cout << "�޴� ȭ������ ���ϴ�" << endl;
            system("pause");
            return;
        }
        else {
            cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
            continue;
        }
    }
}


void Field::Release()
{
    SAFE_DELETE(m_pDungeon);
}

void Field::Set_PlayerInfo(Player* _pPlayer)
{
    m_pPlayer = _pPlayer;
}

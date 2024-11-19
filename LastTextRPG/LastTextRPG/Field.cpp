#include "Field.h"
#include "LowDungeon.h"
#include "MidDungeon.h"
#include "HighDungeon.h"
#include "Color.h"

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
        cout << m_pPlayer->Get_PlayerInfo().Stage << "�ܰ�" << endl; setColor(YELLOW);
        cout << "============= ���� ���� ============" << endl; setColor(GRAY);
        cout << "1. ��ο� ���� ���� (Level.1)" << endl;
        cout << "2. ������ �� (Level.2)" << endl;
        cout << "3. ȭ���� ���� (Level.3)" << endl; setColor(YELLOW);
        cout << "============= ���� ���� ============" << endl; setColor(GRAY);

        struct DungeonOption {
            int stageRequirement;
            const char* entryText;
        };

        DungeonOption bossOptions[] = {
            {0, "Level 1, ���� ����"},
            {1, "Level 2, ���� ����"},
            {2, "Level 3, ���� ����"}
        };

        for (int i = 0; i < 3; ++i) {
            if (m_pPlayer->Get_PlayerInfo().Stage > i) {
                cout << (i + 4) << ". " << bossOptions[i].entryText << endl;
            }
            else {
                cout << (i + 4) << ". " << bossOptions[i].entryText << " ( ��Ŭ���� ) " << endl;
            }
        }
        setColor(YELLOW);
        cout << "====================================" << endl; setColor(GRAY);
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
        else if (_iInput == 4) {
            if (m_pPlayer->Get_PlayerInfo().Stage >= 1) {
                //���� ����
            }   
            else {
                cout << "�ϱ� ������ Ŭ�����ϰ� ���ּ���" << endl;
            }
        }
        else if (_iInput == 5) {
            if (m_pPlayer->Get_PlayerInfo().Stage >= 2) {
                //���� ����
            }
            else {
                cout << "�߱� ������ Ŭ�����ϰ� ���ּ���" << endl;
            }
        }
        else if (_iInput == 6) {
            if (m_pPlayer->Get_PlayerInfo().Stage >= 3) {
                //���� ����
            }
            else {
                cout << "��� ������ Ŭ�����ϰ� ���ּ���" << endl;
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
    SAFE_DELETE<Dungeon*>(m_pDungeon);
}

void Field::Set_PlayerInfo(Player* _pPlayer)
{
    m_pPlayer = _pPlayer;
}

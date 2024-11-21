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

    struct DungeonOption {
        int stageRequirement;
        const char* entryText;
    };

    DungeonOption Options[] = {
        {0, "��ο� ���� ���� (Level 1)"},
        {1, "������ �� (Level.2)"},
        {2, "ȭ���� ���� (Level.3)"}
    };

    while (true) {
        system("cls");setColor(YELLOW);
        cout << "============= ���� ���� ============" << endl; setColor(GRAY);
        for (int i = 0; i < 3; ++i) {
            if (m_pPlayer->Get_PlayerInfo().Stage >= i) {
                cout << (i + 1) << ". " << Options[i].entryText << endl;
            }
            else {
                cout << (i + 1) << ". " << Options[i].entryText << " ( ��Ŭ���� ) " << endl;
            }
        } 
        setColor(YELLOW);
        cout << "====================================" << endl; setColor(GRAY);
        cout << "4. �ڷ� ����" << endl;

        cin >> _iInput;

        if (_iInput >= 1 && _iInput <= 3) {
            switch (_iInput) {
            case 1:
                if (m_pPlayer->Get_PlayerInfo().Stage >= _iInput - 1) {
                    cout << "��ο� ���� ������ �����մϴ� (Level.1)" << endl;
                    m_pDungeon = new LowDungeon;
                }
                else {
                    cout << "�� �ܰ踦 ���� �������ּ���" << endl;
                    system("pause");
                    continue;
                }
                break;
            case 2:
                if (m_pPlayer->Get_PlayerInfo().Stage >= _iInput - 1) {
                    cout << "������ ���� �����մϴ� (Level.2)" << endl;
                    m_pDungeon = new MiddleDungeon;
                }
                else {
                    cout << "�� �ܰ踦 ���� �������ּ���" << endl;
                    system("pause");
                    continue;
                }
                break;
            case 3:
                if (m_pPlayer->Get_PlayerInfo().Stage >= _iInput - 1) {
                    cout << "ȭ���� �������� �����մϴ� (Level.3)" << endl;
                    m_pDungeon = new HighDungeon;
                }
                else {
                    cout << "�� �ܰ踦 ���� �������ּ���" << endl;
                    continue;
                }
                break;
            }

            system("pause");

            m_pDungeon->Set_PlayerInfo(m_pPlayer);
            m_pDungeon->Update();

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

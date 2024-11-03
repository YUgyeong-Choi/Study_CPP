#include "Field.h"
#include "pch.h"
#include "Color.h"

Field::Field()
{
	m_pPlayer = nullptr;
    m_pDungeon = nullptr;
}

Field::~Field()
{
	Release();
}

void Field::Update() {
    int _iInput(0);

    while (true) {
        system("cls");
        setColor(YELLOW);
        cout << "============= ���� ���� ============" << endl; setColor(GRAY);
        cout << "1. �ϱ� ���� ����" << endl;
        cout << "2. �߱� ���� ����" << endl;
        cout << "3. ��� ���� ����" << endl;
        setColor(YELLOW);
        cout << "============= ���� ���� ============" << endl; setColor(GRAY);

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
        setColor(YELLOW);
        cout << "====================================" << endl; setColor(GRAY);
        cout << "7. ����" << endl;

        cin >> _iInput;

        if (_iInput >= 1 && _iInput <= 3) {
            switch (_iInput) {
            case 1:
                setColor(BLUE);
                cout << "��ο� ���� ������ �����մϴ� (Level.1)" << endl; setColor(GRAY);
                m_pDungeon = new LowDungeon; 
                break;
            case 2:
                setColor(BLUE);
                cout << "������ ���� �����մϴ� (Level.2)" << endl; setColor(GRAY);
                m_pDungeon = new MiddleDungeon;
                break;
            case 3:
                setColor(BLUE);
                cout << "ȭ���� �������� �����մϴ� (Level.3)" << endl; setColor(GRAY);
                m_pDungeon = new HighDungeon; 
                break;
            }

            m_pDungeon->Set_PlayerInfo(m_pPlayer);
            m_pDungeon->Update();
            
        }
        else if (_iInput >= 4 && _iInput <= 6) {
            int index = _iInput - 4;
            if (m_pPlayer->Get_Info().Stage <= bossOptions[index].stageRequirement) {
                cout << bossOptions[index].clearText << endl;
                continue;
            }
            
        }
        else if (_iInput == 7) {
            cout << "�޴� ȭ������ ���ϴ�" << endl;
            return;
        }
        else {
            cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
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

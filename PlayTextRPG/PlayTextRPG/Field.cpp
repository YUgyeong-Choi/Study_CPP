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
        cout << "============= 던전 선택 ============" << endl; setColor(GRAY);
        cout << "1. 어두운 숲의 동굴 (Level.1)" << endl;
        cout << "2. 버려진 성 (Level.2)" << endl;
        cout << "3. 화산의 심장 (Level.3)" << endl;
        setColor(YELLOW);
        cout << "============= 보스 선택 ============" << endl; setColor(GRAY);

        struct DungeonOption {
            int stageRequirement;
            const char* entryText;
        };

        DungeonOption bossOptions[] = {
            {LOW, "Level 1, 던전 입장"},
            {MIDDLE, "Level 2, 던전 입장"},
            {HIGH, "Level 3, 던전 입장"}
        };

        for (int i = 0; i < 3; ++i) {
            if (m_pPlayer->Get_Info().Stage > bossOptions[i].stageRequirement) {
                cout << (i + 4) << ". " << bossOptions[i].entryText << endl;
            }
            else {
                cout << (i + 4) << ". " << bossOptions[i].entryText << " ( 미클리어 ) " << endl;
            }
        }
        setColor(YELLOW);
        cout << "====================================" << endl; setColor(GRAY);
        cout << "7. 뒤로 가기" << endl;

        cin >> _iInput;

        if (_iInput >= 1 && _iInput <= 3) {
            switch (_iInput) {
            case 1:
                setColor(BLUE);
                cout << "어두운 숲의 동굴로 입장합니다 (Level.1)" << endl; setColor(GRAY);
                m_pDungeon = new LowDungeon; 
                break;
            case 2:
                setColor(BLUE);
                cout << "버려진 성로 입장합니다 (Level.2)" << endl; setColor(GRAY);
                m_pDungeon = new MiddleDungeon;
                break;
            case 3:
                setColor(BLUE);
                cout << "화산의 심장으로 입장합니다 (Level.3)" << endl; setColor(GRAY);
                m_pDungeon = new HighDungeon; 
                break;
            }

            cin.ignore();
            cin.get();

            m_pDungeon->Set_PlayerInfo(m_pPlayer);
            m_pDungeon->Update();
            
        }
        else if (_iInput >= 4 && _iInput <= 6) {
            int index = _iInput - 4;
            if (m_pPlayer->Get_Info().Stage <= bossOptions[index].stageRequirement) {
                cout << "던전을 클리어하고 와주세요" << endl;
                cin.ignore();
                cin.get();
                continue;
            }
            
        }
        else if (_iInput == 7) {
            cout << "메뉴 화면으로 갑니다" << endl;
            cin.ignore();
            cin.get();
            return;
        }
        else {
            cout << "잘못 입력하셨습니다" << endl;
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

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
        {0, "어두운 숲의 동굴 (Level 1)"},
        {1, "버려진 성 (Level.2)"},
        {2, "화산의 심장 (Level.3)"}
    };

    while (true) {
        system("cls");setColor(YELLOW);
        cout << "============= 던전 선택 ============" << endl; setColor(GRAY);
        for (int i = 0; i < 3; ++i) {
            if (m_pPlayer->Get_PlayerInfo().Stage >= i) {
                cout << (i + 1) << ". " << Options[i].entryText << endl;
            }
            else {
                cout << (i + 1) << ". " << Options[i].entryText << " ( 미클리어 ) " << endl;
            }
        } 
        setColor(YELLOW);
        cout << "====================================" << endl; setColor(GRAY);
        cout << "4. 뒤로 가기" << endl;

        cin >> _iInput;

        if (_iInput >= 1 && _iInput <= 3) {
            switch (_iInput) {
            case 1:
                if (m_pPlayer->Get_PlayerInfo().Stage >= _iInput - 1) {
                    cout << "어두운 숲의 동굴로 입장합니다 (Level.1)" << endl;
                    m_pDungeon = new LowDungeon;
                }
                else {
                    cout << "전 단계를 깨고 입장해주세요" << endl;
                    system("pause");
                    continue;
                }
                break;
            case 2:
                if (m_pPlayer->Get_PlayerInfo().Stage >= _iInput - 1) {
                    cout << "버려진 성로 입장합니다 (Level.2)" << endl;
                    m_pDungeon = new MiddleDungeon;
                }
                else {
                    cout << "전 단계를 깨고 입장해주세요" << endl;
                    system("pause");
                    continue;
                }
                break;
            case 3:
                if (m_pPlayer->Get_PlayerInfo().Stage >= _iInput - 1) {
                    cout << "화산의 심장으로 입장합니다 (Level.3)" << endl;
                    m_pDungeon = new HighDungeon;
                }
                else {
                    cout << "전 단계를 깨고 입장해주세요" << endl;
                    continue;
                }
                break;
            }

            system("pause");

            m_pDungeon->Set_PlayerInfo(m_pPlayer);
            m_pDungeon->Update();

        }
        else if (_iInput == 7) {
            cout << "메뉴 화면으로 갑니다" << endl;
            system("pause");
            return;
        }
        else {
            cout << "잘못 입력하셨습니다" << endl;
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

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
        cout << "============= 던전 선택 ============" << endl;
        cout << "1. 하급 던전 입장" << endl;
        cout << "2. 중급 던전 입장" << endl;
        cout << "3. 고급 던전 입장" << endl;

        cout << "============= 보스 선택 ============" << endl;

        struct DungeonOption {
            int stageRequirement;
            const char* entryText;
            const char* clearText;
        };

        DungeonOption bossOptions[] = {
            {LOW, "하급 보스 던전 입장", "하급 던전 미클리어"},
            {MIDDLE, "중급 보스 던전 입장", "중급 던전 미클리어"},
            {HIGH, "고급 보스 던전 입장", "고급 던전 미클리어"}
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
            cout << "잘못 입력하셨습니다" << endl;
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

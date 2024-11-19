#include "Dungeon.h"
#include "Color.h"

Dungeon::Dungeon():m_pPlayer(nullptr), m_pMonster(nullptr) , coolTime(0){
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            map[i][j][0] = '*';
            map[i][j][1] = 'f';
        }
    }

    srand(unsigned(time(0)));
    int count = 0;

    while (count < 6) {
        int i = std::rand() % 5;
        int j = std::rand() % 5;

        if (map[i][j][1] == 'f' && !(i == 2 && j == 2)) {
            map[i][j][1] = 't';
            count++;
        }
    }

    map[2][2][0] = '?';
}


Dungeon::~Dungeon() {
    Release();
}


void Dungeon::Update() {
    int iX = 2, iY = 2;
    int _iInput = 0;
    bool checkWin = true;

    while (true) {
        system("cls");
        Render_Map();
        cout << "1.위 2.아래 3.좌 4.우 5.던전 퇴장: " << endl;
        cin >> _iInput;

        switch (_iInput) {
        case 1:
            if (iX > 0) {
                if (checkWin == false) {
                    map[iX][iY][0] = '*';
                    checkWin = true;
                }
                else {
                    map[iX][iY][0] = ' ';
                }
                iX--;
                map[iX][iY][0] = '?';
            }
            break;
        case 2:
            if (iX < 4) {
                if (checkWin == false) {
                    map[iX][iY][0] = '*';
                    checkWin = true;
                }
                else {
                    map[iX][iY][0] = ' ';
                }
                iX++;
                map[iX][iY][0] = '?';
            }
            break;
        case 3:
            if (iY > 0) {
                if (checkWin == false) {
                    map[iX][iY][0] = '*';
                    checkWin = true;
                }
                else {
                    map[iX][iY][0] = ' ';
                }
                iY--;
                map[iX][iY][0] = '?';
            }
            break;
        case 4:
            if (iY < 4) {
                if (checkWin == false) {
                    map[iX][iY][0] = '*';
                    checkWin = true;
                }
                else {
                    map[iX][iY][0] = ' ';
                }
                iY++;
                map[iX][iY][0] = '?';
            }
            break;
        case 5:
            cout << "던전을 나갑니다" << endl;
            return;
        default:
            cout << "잘못 입력하셨습니다" << endl;
            continue;
        }

        if (map[iX][iY][1] == 't') {
            cout << "! 몬스터를 만났다 !" << endl << endl;
            system("pause");
            checkWin = Fight();
            SAFE_DELETE(m_pMonster);

        }

        if (checkWin) map[iX][iY][1] = 'f';

        if (checkWin == false) {
            cout << "플레이어 사망, 던전을 나갑니다" << endl;
            return;
        }

        if (Check_Clear()) {
            m_pPlayer->Set_Stage();
            cout << "던전 클리어" << endl;
            break;
        }
    }
}


void Dungeon::Release() {
    if (m_pMonster) SAFE_DELETE(m_pMonster);
}


void Dungeon::Set_PlayerInfo(Player* _pPlayer) {
    m_pPlayer = _pPlayer;
    originAttack = m_pPlayer->Get_PlayerInfo().iAttack;
}

Monster* Dungeon::Set_Monster()
{
    return nullptr;
}


void Dungeon::Render_Map() {
    setColor(YELLOW);
    cout << "============= 던전 =============" << endl; setColor(GRAY);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << map[i][j][0] << " ";
        }
        cout << endl;
    }setColor(YELLOW);
    cout << "=================================" << endl; setColor(GRAY);
}

bool Dungeon::Check_Clear() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (map[i][j][0] == '*') {
                return false;
            }
        }
    }
    return true;
}


bool Dungeon::Fight() {
    int _iInput(0);

    m_pMonster = Set_Monster();

    while (1) {
        system("cls");
        m_pMonster->Render();
        m_pPlayer->Render(); setColor(YELLOW);
        cout << "====================================" << endl; setColor(GRAY);
        cout << "1.기본 공격" << '\t' << " 2." << m_pPlayer->Get_PlayerInfo().skills[0].skillName << '\t' << " 3." << m_pPlayer->Get_PlayerInfo().skills[1].skillName << endl;
        cout << "4.인벤토리" << '\t' << "5.도망" << endl;
        cin >> _iInput;
        switch (_iInput) {
        case 1:
            m_pPlayer->Set_Hp(-m_pMonster->Get_MonsterInfo().iAttack);
            m_pMonster->Set_Hp(-m_pPlayer->Get_PlayerInfo().iAttack);
            break;
        case 2:
            if (0 == coolTime) {
                coolTime = m_pPlayer->Get_PlayerInfo().skills[0].cool;
                m_pPlayer->Skill1();
                cout << m_pPlayer->Get_PlayerInfo().skills[0].skillName << "을 사용하셨습니다" << endl;
                m_pPlayer->Set_Hp(-m_pMonster->Get_MonsterInfo().iAttack);
                m_pMonster->Set_Hp(-m_pPlayer->Get_PlayerInfo().iAttack);
            }
            else {
                cout << "쿨타임 입니다" << endl;
                continue;
            }
            break;
        case 3:
            if (0 == coolTime) {
                coolTime = m_pPlayer->Get_PlayerInfo().skills[1].cool;
                cout << m_pPlayer->Get_PlayerInfo().skills[1].skillName << "을 사용하셨습니다" << endl;
                m_pPlayer->Set_Hp(-m_pMonster->Get_MonsterInfo().iAttack);
                m_pMonster->Set_Hp(-m_pPlayer->Skill2());
            }
            else {
                cout << "쿨타임 입니다" << endl;
                continue;
            }
            break;
        case 4:
            m_pPlayer->usePotion(m_pPlayer->Get_InvenInfo()->FightInventory());
            continue;
        case 5:
            m_pPlayer->Set_InitAttack(originAttack);
            cout << "도망 갑니다" << endl;
            return false;
        default:
            cout << "잘못 입력하셨습니다" << endl;
            system("pause");
            continue;
        }

        if (coolTime == 0) {
            cout << "쿨타임이 완료되었습니다" << endl;
            m_pPlayer->Set_InitAttack(originAttack);
            system("pause");
        }
        else if(coolTime >0){
            cout << "남은 쿨타임: " << coolTime << endl;
            coolTime--;
            system("pause");
        }

        if (0 >= m_pPlayer->Get_PlayerInfo().iHp) {
            m_pPlayer->Set_FullHp();
            cout << "졌다..." << endl;
            system("pause");
            return false;
        }

        if (0 >= m_pMonster->Get_MonsterInfo().iHp) {
            m_pPlayer->Add_PlayerMoney(m_pMonster->Get_MonsterInfo().iMoney);
            cout << m_pMonster->Get_MonsterInfo().strName << "가 죽었다" << endl;
            cout << "승리, 맵으로 돌아갑니다" << endl;
            system("pause");
            return true;
        }
    }
}
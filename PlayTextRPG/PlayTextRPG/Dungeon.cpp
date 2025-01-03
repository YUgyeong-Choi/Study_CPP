#include "Dungeon.h"
#include "pch.h"
#include <ctime>
#include "Color.h"

Dungeon::Dungeon() {
    m_pPlayer = nullptr;
    m_pMonster = nullptr;
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
            cin.ignore();
            cin.get();
            m_pPlayer->Set_InitAttack();
            checkWin = Fight(m_pPlayer, m_pMonster);
            SAFE_DELETE(m_pMonster);

        }

        if (checkWin) map[iX][iY][1] = 'f';

        if (checkWin == false && 0 >= m_pPlayer->Get_Info().iHp) {
            m_pPlayer->Set_FullHp();
            m_pPlayer->Set_InitAttack();
            cout << "플레이어 사망, 던전을 나갑니다" << endl;
            return;
        }

        if (Check_Clear()) {
            m_pPlayer->Set_Stage();
            cout << "던전 클리어" << endl;
            m_pPlayer->Set_InitAttack();
            break;
        }
    }
}


void Dungeon::Release() {
    if (m_pMonster) SAFE_DELETE(m_pMonster);
}


void Dungeon::Set_PlayerInfo(Player* _pPlayer) {
    m_pPlayer = _pPlayer;
}

Monster* Dungeon::Set_Monster()
{
    return nullptr;
}


void Dungeon::Render_Map() {
    setColor(BLUE);
    cout << "============= 던전 =============" << endl; setColor(GRAY);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << map[i][j][0] << " ";
        }
        cout << endl;
    }
    setColor(BLUE);
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


bool Dungeon::Fight(Player* _pPlayer, Monster* _pMonster) {
    int _iInput(0);
    int _iCoolTime(0);
    
    _pMonster = Set_Monster();

    while (1) {
        system("cls");
        _pMonster->Render();
        _pPlayer->Render(); 
        setColor(RED);
        cout << "====================================" << endl; setColor(GRAY);
        cout << "1.기본 공격" << '\t' << " 2." << _pPlayer->Get_Info().skills[0].skillName << '\t' << " 3." << _pPlayer->Get_Info().skills[1].skillName << endl;
        cout << "4.인벤토리"<<'\t' << "5.도망" << endl;
        cin >> _iInput;
        switch (_iInput) {
        case 1:
            _pPlayer->Set_Hp(_pMonster->Get_Info().iAttack);
            _pMonster->Set_Hp(_pPlayer->Get_Info().iAttack);
            break;
        case 2:
            if (_iCoolTime == 0) {
                _iCoolTime = _pPlayer->Get_Info().skills[0].cool;
                _pPlayer->Skill1();
                cout << _pPlayer->Get_Info().skills[0].skillName << "를 사용하셨습니다" << endl;
                _pPlayer->Set_Hp(_pMonster->Get_Info().iAttack);
                break;
            }
            else {
                cout << "쿨타임 입니다: " << _iCoolTime << endl;
                cin.ignore();
                cin.get();
                continue;
            }
        case 3:
            if (_iCoolTime == 0) {
                _iCoolTime = _pPlayer->Get_Info().skills[1].cool;
                _pMonster->Set_Hp(_pPlayer->Skill2());
                cout << _pPlayer->Get_Info().skills[1].skillName << "를 사용하셨습니다" << endl;
                _pPlayer->Set_Hp(_pMonster->Get_Info().iAttack);
                cin.ignore();
                cin.get();
                break;
            }
            else {
                cout << "쿨타임 입니다: " << _iCoolTime << endl;
                cin.ignore();
                cin.get();
                continue;
            }
        case 4:
            _pPlayer->Fight_Inventory();
            continue;
        case 5:
            _pPlayer->Set_InitAttack();
            cout << "도망 갑니다" << endl;
            cin.ignore();
            cin.get();
            return false;
        default:
            cout << "잘못 입력하셨습니다" << endl;
            cin.ignore();
            cin.get();
            continue;
        }

        if (0 < _iCoolTime) _iCoolTime--;

        if (_iCoolTime == 0) {
            _pPlayer->Set_InitAttack();
            cout << "스킬 쿨타임이 완료되었습니다" << endl;
            cin.ignore();
            cin.get();
        }

        if (0 >= _pPlayer->Get_Info().iHp) {
            cout << "졌다..." << endl;
            cin.ignore();
            cin.get();
            return false;
        }

        if (0 >= _pMonster->Get_Info().iHp) {
            _pPlayer->Add_PlayerMoney(_pMonster->Get_Info().iMoney);
            cout << _pMonster->Get_Info().szName << "가 죽었다" << endl;
            cout << "승리, 맵으로 돌아갑니다" << endl;
            cin.ignore();
            cin.get();
            return true;
        }
    }
}
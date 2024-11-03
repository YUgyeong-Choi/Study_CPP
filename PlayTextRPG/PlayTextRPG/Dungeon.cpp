#include "Dungeon.h"
#include "pch.h"
#include <ctime>

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
        Render_Map();
        cout << "1.�� 2.�Ʒ� 3.�� 4.�� 5.���� ����: " << endl;
        cin >> _iInput;

        if (checkWin == false) {
            map[iX][iY][0] = '*';
            checkWin = true;
        }
        else {
            map[iX][iY][0] = ' ';
        }

        switch (_iInput) {
        case 1:
            if (iX > 0) {
                iX--;
                map[iX][iY][0] = '?';
            }
            break;
        case 2:
            if (iX < 4) {
                iX++;
                map[iX][iY][0] = '?';
            }
            break;
        case 3:
            if (iY > 0) {
                iY--;
                map[iX][iY][0] = '?';
            }
            break;
        case 4:
            if (iY < 4) {
                iY++;
                map[iX][iY][0] = '?';
            }
            break;
        case 5:
            cout << "������ �����ϴ�" << endl;
            return;
        default:
            cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
            continue;
        }

        if (map[iX][iY][1] == 't') {
            cout << "! ���͸� ������ !" << endl << endl;

            checkWin = Fight(m_pPlayer, m_pMonster);
            SAFE_DELETE(m_pMonster);
        }

        if (checkWin) map[iX][iY][1] = 'f';

        if (checkWin == false && 0 >= m_pPlayer->Get_Info().iHp) {
            cout << "�÷��̾� ���, ������ �����ϴ�" << endl;
            return;
        }

        if (Check_Clear()) {
            m_pPlayer->Set_Stage();
            cout << "���� Ŭ����" << endl;

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
    cout << "============= ���� =============" << endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << map[i][j][0] << " ";
        }
        cout << endl;
    }
    cout << "=================================" << endl;
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

// ���� �޼���
bool Dungeon::Fight(Player* _pPlayer, Monster* _pMonster) {
    int _iInput(0);
    int _iCoolTime(0);
    
    _pMonster = Set_Monster();

    while (1) {
        _pMonster->Render();
        _pPlayer->Render();
        cout << "====================================" << endl;
        cout << "1.�⺻ ����" << " 2." << _pPlayer->Get_Info().skills[0].skillName << " 3." << _pPlayer->Get_Info().skills[1].skillName << endl;
        cout << "4.����" << endl;
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
                cout << _pPlayer->Get_Info().skills[0].skillName << "�� ����ϼ̽��ϴ�" << endl;
                _pPlayer->Set_Hp(_pMonster->Get_Info().iAttack);
                break;
            }
            else {
                cout << "��Ÿ�� �Դϴ�: " << _iCoolTime << endl;
                continue;
            }
        case 3:
            if (_iCoolTime == 0) {
                _iCoolTime = _pPlayer->Get_Info().skills[1].cool;
                _pMonster->Set_Hp(_pPlayer->Skill2());
                cout << _pPlayer->Get_Info().skills[1].skillName << "�� ����ϼ̽��ϴ�" << endl;
                _pPlayer->Set_Hp(_pMonster->Get_Info().iAttack);
                break;
            }
            else {
                cout << "��Ÿ�� �Դϴ�: " << _iCoolTime << endl;
                continue;
            }
        case 4:
            _pPlayer->Set_OriginAttack();
            cout << "���� ���ϴ�" << endl;
            return false;
        default:
            cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
            continue;
        }

        if (0 < _iCoolTime) _iCoolTime--;

        if (_iCoolTime == 0) {
            _pPlayer->Set_OriginAttack();
            cout << "��ų ��Ÿ���� �Ϸ�Ǿ����ϴ�" << endl;
        }

        if (0 >= _pPlayer->Get_Info().iHp) {
            _pPlayer->Set_OriginAttack();
            _pPlayer->Set_FullHp();
            cout << "����..." << endl;
            return false;
        }

        if (0 >= _pMonster->Get_Info().iHp) {
            _pPlayer->Set_OriginAttack();
            cout << _pMonster->Get_Info().szName << "�� �׾���" << endl;
            cout << "�¸�, ������ ���ư��ϴ�" << endl;
            return true;
        }
    }
}
#include "Player.h"
#include "pch.h"
#include "Color.h"

Player::Player()
{
    strcpy_s(m_playerInfo.szName, "");
    strcpy_s(m_playerInfo.Job, "");
    m_playerInfo.iHp = 0;
    m_playerInfo.iAttack = 0;
    m_playerInfo.iMoney = 0;
    m_playerInfo.Stage = 1;
    m_playerInfo.weaponLevel = 0;
    iOriginHp = 0;
    iOriginAttack = 0;
    iUpgradeAttack = 0;

    for (int i = 0; i < 2; ++i) {
        strcpy_s(m_playerInfo.skills[i].skillName, "");
        strcpy_s(m_playerInfo.skills[i].skillInfo, "");
        m_playerInfo.skills[i].cool = 0;
    }

    m_playerInventory = new Inventory;
}

Player::~Player()
{
    SAFE_DELETE(m_playerInventory);
}

void Player::Render()
{
    setColor(RED);
    cout << "====================================" << endl; setColor(GRAY);
    cout << m_playerInfo.szName << endl;
    cout << "Hp: " << m_playerInfo.iHp << endl;
    cout << "Attack Damage: " << m_playerInfo.iAttack << endl;
}

void Player::Set_Player_Name(const char* szName)
{
    strcpy_s(m_playerInfo.szName, sizeof(m_playerInfo.szName), szName);
}

void Player::Set_UpgradeHp()
{
    m_playerInfo.iHp += 10;
    iOriginHp = m_playerInfo.iHp;
}


void Player::Set_Attack(int _add)
{
    iUpgradeAttack = m_playerInfo.iAttack* (100 + _add) / 100; 
    m_playerInfo.iAttack = iUpgradeAttack;
    m_playerInfo.weaponLevel++;

}

void Player::Skill1()
{
}

int Player::Skill2()
{
    return 0;
}

void Player::Render_Detail()
{
    system("cls");
    setColor(YELLOW);
    cout << "============== 내 정보==============" << endl; setColor(GRAY);
    cout << "이름:" << m_playerInfo.szName << '\t' << "직업:" << m_playerInfo.Job << endl;
    cout << "Hp: " << m_playerInfo.iHp << endl;

    if (m_playerInfo.weaponLevel == 0) {
        cout << "Attack Damage: " << m_playerInfo.iAttack << endl;
    }
    else if(m_playerInfo.weaponLevel == 1) {
        cout << "Attack Damage: " << m_playerInfo.iAttack;
        cout << '\t' << "( " << iOriginAttack << " * 1.5 )" << endl;
    }
    else if (m_playerInfo.weaponLevel == 2) {
        cout << "Attack Damage: " << m_playerInfo.iAttack;
        cout << '\t' << "( " << iOriginAttack << " * 2.0 )" << endl;
    }
    else {
        cout << "Attack Damage: " << m_playerInfo.iAttack;
        cout << '\t' << "( " << iOriginAttack << " * 2.5 )" << endl;
    }

    cout << "Money: " << m_playerInfo.iMoney << endl;
    cout << "스킬 1-" << m_playerInfo.skills[0].skillName<<" : "<< m_playerInfo.skills[0].skillInfo << endl;
    cout << "스킬 1 쿨타임: " << m_playerInfo.skills[0].cool-1<<endl;
    cout << "스킬 2-" << m_playerInfo.skills[1].skillName<<" : "<< m_playerInfo.skills[1].skillInfo << endl;
    cout << "스킬 2 쿨타임: " << m_playerInfo.skills[1].cool-1<<endl; setColor(YELLOW);
    cout << "====================================" << endl; setColor(GRAY);
    cout << "아무 버튼 누르면 뒤로 갑니다" << endl;
    cin.get();
}

void Player::Fight_Inventory()
{
    int _iInput(0);
    while (1) {
        system("cls");
        m_playerInventory->Fight_Render();
        cin >> _iInput;
     
        if (1 <= _iInput && _iInput <= 3) {
            int index = _iInput - 1; 
            int item = m_playerInventory->Get_InventoryInfo()[index].iPrice; 

            if (item <= 0) {
                cout << "아이템을 보유하고 있지 않습니다" << endl;
                cin.ignore();
                cin.get();
            }
            else {
                m_playerInfo.iHp += m_playerInventory->Get_InventoryInfo()[index].iHp;
                m_playerInventory->Add_Items(-index);
                cout << "아이템을 사용했습니다" << endl;
                cin.ignore();
                cin.get();
            }
        }
        else if (_iInput == 4) {
            return;
        }
        else {
            cout << "잘못 입력하셨습니다" << endl;
        }
    }   
}

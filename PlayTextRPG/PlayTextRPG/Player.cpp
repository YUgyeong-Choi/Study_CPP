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
    cout << "============== �� ����==============" << endl; setColor(GRAY);
    cout << "�̸�:" << m_playerInfo.szName << '\t' << "����:" << m_playerInfo.Job << endl;
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
    cout << "��ų 1-" << m_playerInfo.skills[0].skillName<<" : "<< m_playerInfo.skills[0].skillInfo << endl;
    cout << "��ų 1 ��Ÿ��: " << m_playerInfo.skills[0].cool-1<<endl;
    cout << "��ų 2-" << m_playerInfo.skills[1].skillName<<" : "<< m_playerInfo.skills[1].skillInfo << endl;
    cout << "��ų 2 ��Ÿ��: " << m_playerInfo.skills[1].cool-1<<endl; setColor(YELLOW);
    cout << "====================================" << endl; setColor(GRAY);
    cout << "�ƹ� ��ư ������ �ڷ� ���ϴ�" << endl;
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
                cout << "�������� �����ϰ� ���� �ʽ��ϴ�" << endl;
                cin.ignore();
                cin.get();
            }
            else {
                m_playerInfo.iHp += m_playerInventory->Get_InventoryInfo()[index].iHp;
                m_playerInventory->Add_Items(-index);
                cout << "�������� ����߽��ϴ�" << endl;
                cin.ignore();
                cin.get();
            }
        }
        else if (_iInput == 4) {
            return;
        }
        else {
            cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
        }
    }   
}

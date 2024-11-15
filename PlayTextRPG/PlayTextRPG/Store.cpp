#include "Store.h"
#include "pch.h"
#include "Color.h"

Store::Store()
{
    m_pPlayer = nullptr;
    // 포션 아이템 초기화
    items[0] = { "소형 포션", 30, 0,15 };
    items[1] = { "중형 포션", 70, 0,30 };
    items[2] = { "대형 포션", 150, 0,60 };


    // 무기 강화 아이템 초기화
    items[3] = { "1단계 강화", 0,50, 50 };
    items[4] = { "2단계 강화", 0,100, 150 };
    items[5] = { "3단계 강화", 0,150, 300 };

    // Hp 강화 아이템 초기화
    items[6] = { "Hp 증가", 10, 0,20 };
}

void Store::Update()
{
    int _iInput(0);
    while (1) {
        system("cls");
        cout << "보유 머니: " << m_pPlayer->Get_Info().iMoney << endl;
        setColor(DARK_VOILET);
        cout << "=============== 상점 ===============" << endl; setColor(GRAY);
        for (int i = 0; i < 3; ++i) {
            cout << i+1 << ". " << items[i].szName << endl;
            cout << "설명: 체력을 " << items[i].iHp << "만큼 회복시킵니다" << endl;
            cout << "가격: " << items[i].iPriceOrCount << endl;
        }
 
        int weaponIndex = m_pPlayer->Get_Info().weaponLevel+3;
        if (3<=weaponIndex && weaponIndex<=5 ) { 
            cout << "4. " << items[weaponIndex].szName << endl;
            cout << "설명: 기존 데미지의 " << items[weaponIndex].iAttack << "%만큼 강화시킵니다" << endl;
            cout << "가격: " << items[weaponIndex].iPriceOrCount << endl;
        }
        else if (weaponIndex == 6) {
            cout << "4. 무기 강화가 완료되었습니다" << endl;
        }

        cout << "5. Hp 증가";
        cout << "설명: 영구적으로" << items[6].iHp << items[6].szName << endl;
        cout << "가격: " << items[6].iPriceOrCount << endl;

        setColor(DARK_VOILET);
        cout << "====================================" << endl; setColor(GRAY);
        cout << "6.뒤로 가기" << endl;

        cin >> _iInput;

        if (1 <= _iInput && _iInput <= 3) {
            if (items[_iInput - 1].iPriceOrCount > m_pPlayer->Get_Info().iMoney) {
                cout << "돈이 없습니다..." << endl;
            }
            else {
                m_pPlayer->Add_PlayerMoney(-items[_iInput - 1].iPriceOrCount);
                m_pPlayer->Add_Items(_iInput - 1);
                cout << items[_iInput - 1].szName << "을 구매했습니다" << endl;
            }
        }
        else if (_iInput == 4) {
            if (m_pPlayer->Get_Info().weaponLevel < 3) {
                if (items[weaponIndex].iPriceOrCount > m_pPlayer->Get_Info().iMoney) {
                    cout << "돈이 부족합니다..." << endl;
                }
                else {
                    m_pPlayer->Add_PlayerMoney(-items[m_pPlayer->Get_Info().weaponLevel].iPriceOrCount);
                    m_pPlayer->Set_Attack(items[m_pPlayer->Get_Info().weaponLevel].iAttack);
                    cout << "무기를 강화했습니다!" << endl;
                }
            }
            else {
                cout << "무기 강화가 최대 상태입니다." << endl;
            }
        }
        else if (_iInput == 5) {
            if (items[_iInput - 1].iPriceOrCount > m_pPlayer->Get_Info().iMoney) {
                cout << "돈이 없습니다..." << endl;
            }
            else {
                m_pPlayer->Set_UpgradeHp();
                cout << "Hp가 상승하였습니다" << endl;
            }
        }
        else if (_iInput == 6) {
            cout << "상점을 나갑니다" << endl;
            system("pause");
            return;
        }
        else {
            cout << "잘못 입력하셨습니다" << endl;
            continue;
        }

        system("pause");
    }

}

void Store::Set_PlayerInfo(Player* _pPlayer)
{
    m_pPlayer = _pPlayer;
}

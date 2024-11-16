#include "Storemenu.h"
#include "pch.h"
#include "Color.h"

Storemenu::Storemenu()
{
    m_pPlayer = nullptr;
    m_pStore = nullptr;
}

void Storemenu::Update()
{
    int _iInput(0);
    while (1) {
        system("cls");
        setColor(YELLOW);
        cout << "============== 상점 ===============" << endl; setColor(GRAY); 
        cout << "1. 포션 상점" << endl;
        cout << "2. 무기 상점" << endl;
        cout << "3. 장비 상점" << endl;
        cout << "4. 판매 상점" << endl;
        setColor(YELLOW);
        cout << "====================================" << endl; setColor(GRAY);
        cout << "5. 뒤로 가기" << endl;

        cin >> _iInput;
        switch (_iInput)
        {
        case 1:
            m_pStore = new PotionStore;

            break;
        case 2:
            m_pStore = new WeaponStore;
            break;
        case 3:
            m_pStore = new ArmorStore;
            break;
        case 4:
            //판매 상점
            continue;
        case 5:
            return;
        default:
            cout << "잘못 입력하셨습니다" << endl;
            continue;
        }

        if (m_pStore != nullptr) {
            m_pStore->Set_PlayerInfo(m_pPlayer);
            m_pStore->Update();
        }

        SAFE_DELETE(m_pStore);
        system("pause");
    }



    //int _iInput(0);
    //while (1) {
    //    system("cls");
    //    cout << "보유 머니: " << m_pPlayer->Get_Info().iMoney << endl;
    //    setColor(DARK_VOILET);
    //    cout << "=============== 상점 ===============" << endl; setColor(GRAY);
    //    for (int i = 0; i < 3; ++i) {
    //        cout << i+1 << ". " << items[i].szName << endl;
    //        cout << "설명: 체력을 " << items[i].iHp << "만큼 회복시킵니다" << endl;
    //        cout << "가격: " << items[i].iPriceOrCount << endl;
    //    }
 
    //    int weaponIndex = m_pPlayer->Get_Info().weaponLevel+3;
    //    if (3<=weaponIndex && weaponIndex<=5 ) { 
    //        cout << "4. " << items[weaponIndex].szName << endl;
    //        cout << "설명: 기존 데미지의 " << items[weaponIndex].iAttack << "%만큼 강화시킵니다" << endl;
    //        cout << "가격: " << items[weaponIndex].iPriceOrCount << endl;
    //    }
    //    else if (weaponIndex == 6) {
    //        cout << "4. 무기 강화가 완료되었습니다" << endl;
    //    }

    //    cout << "5. Hp 증가";
    //    cout << "설명: 영구적으로" << items[6].iHp << items[6].szName << endl;
    //    cout << "가격: " << items[6].iPriceOrCount << endl;

    //    setColor(DARK_VOILET);
    //    cout << "====================================" << endl; setColor(GRAY);
    //    cout << "6.뒤로 가기" << endl;

    //    cin >> _iInput;

    //    if (1 <= _iInput && _iInput <= 3) {
    //        if (items[_iInput - 1].iPriceOrCount > m_pPlayer->Get_Info().iMoney) {
    //            cout << "돈이 없습니다..." << endl;
    //        }
    //        else {
    //            m_pPlayer->Add_PlayerMoney(-items[_iInput - 1].iPriceOrCount);
    //            m_pPlayer->Add_Items(_iInput - 1);
    //            cout << items[_iInput - 1].szName << "을 구매했습니다" << endl;
    //        }
    //    }
    //    else if (_iInput == 4) {
    //        if (m_pPlayer->Get_Info().weaponLevel < 3) {
    //            if (items[weaponIndex].iPriceOrCount > m_pPlayer->Get_Info().iMoney) {
    //                cout << "돈이 부족합니다..." << endl;
    //            }
    //            else {
    //                m_pPlayer->Add_PlayerMoney(-items[m_pPlayer->Get_Info().weaponLevel].iPriceOrCount);
    //                m_pPlayer->Set_Attack(items[m_pPlayer->Get_Info().weaponLevel].iAttack);
    //                cout << "무기를 강화했습니다!" << endl;
    //            }
    //        }
    //        else {
    //            cout << "무기 강화가 최대 상태입니다." << endl;
    //        }
    //    }
    //    else if (_iInput == 5) {
    //        if (items[_iInput - 1].iPriceOrCount > m_pPlayer->Get_Info().iMoney) {
    //            cout << "돈이 없습니다..." << endl;
    //        }
    //        else {
    //            m_pPlayer->Set_UpgradeHp();
    //            cout << "Hp가 상승하였습니다" << endl;
    //        }
    //    }
    //    else if (_iInput == 6) {
    //        cout << "상점을 나갑니다" << endl;
    //        system("pause");
    //        return;
    //    }
    //    else {
    //        cout << "잘못 입력하셨습니다" << endl;
    //        continue;
    //    }

    //    system("pause");
    //}

}

void Storemenu::Set_PlayerInfo(Player* _pPlayer)
{
    m_pPlayer = _pPlayer;
}

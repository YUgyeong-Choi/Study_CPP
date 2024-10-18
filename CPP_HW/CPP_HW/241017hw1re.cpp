/*
 cout << "pPlayer의 값: "<<pPlayer << endl;
 fwrite(pPlayer, sizeof(INFO), 1, pSaveFile);
 pPlayer의 값인 0000028C6D1450E0는 INFO 구조체의 메모리 주소입니다. 
 이 주소는 pPlayer가 가리키고 있는 실제 데이터가 아닙니다. 
 fwrite 함수는 pPlayer가 가리키는 메모리 주소에서 시작하는 INFO 구조체의 데이터를 바이너리 형식으로 파일에 씁니다.
*/

#include <iostream>
#include <bitset>

#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif
#endif

using namespace std;

typedef struct tagInfo
{
    char    szName[32];
    int     iAttack;
    int     iHp;

}INFO;

enum JOB { WARRIOR = 1, MAGE, THIEF, LOADING, END };

INFO* Select_Job();
void        Main_Game(INFO* pPlayer);
void        Render(INFO* pInfo);
void        Field(INFO* pPlayer);
void        Create_Obj(INFO** ppMonster, const char* pName, int _iAttack, int _iHp);
int         Fight(INFO* pPlayer, INFO* pMonster);

bool        Save_Data(INFO* pPlayer);
bool        Load_Data(INFO** ppPlayer);
void PrintBinary(const INFO* pPlayer);

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    INFO* pPlayer = Select_Job();

    if (nullptr == pPlayer)
    {
        cout << "플레이어 할당 안됨" << endl;
        return 0;
    }

    Main_Game(pPlayer);

    if (nullptr != pPlayer)
    {
        delete pPlayer;
        pPlayer = nullptr;
    }

    return 0;
}

INFO* Select_Job()
{
    INFO* pTemp(nullptr);
    int         iInput(0);
    bool        bSelect(false);

    while (!bSelect)
    {
        system("cls");

        cout << "직업을 선택하세요(1. 전사 2. 도적 3. 마법사 4. 불러오기 5. 종료) : ";
        cin >> iInput;

        switch (iInput)
        {
        case WARRIOR:
            pTemp = new INFO;

            strcpy_s(pTemp->szName, sizeof(pTemp->szName), "전사");
            pTemp->iAttack = 10;
            pTemp->iHp = 100;
            bSelect = true;
            break;

        case MAGE:
            Create_Obj(&pTemp, "마법사", 10, 100);
            bSelect = true;
            break;

        case THIEF:
            Create_Obj(&pTemp, "도적", 10, 100);
            bSelect = true;
            break;

        case LOADING:
            bSelect = Load_Data(&pTemp);
            break;

        case END:
            cout << "게임을 종료합니다" << endl;
            bSelect = true;
            break;

        default:
            cout << "잘못 입력하셨습니다" << endl;
            break;
        }
    }

    return pTemp;
}
void        Main_Game(INFO* pPlayer)
{
    int iInput(0);

    while (true)
    {
        system("cls");

        Render(pPlayer);
        cout << "1. 사냥터 2. 종료 : ";
        cin >> iInput;

        switch (iInput)
        {
        case 1:
            Field(pPlayer);
            break;

        case 2:
            return;
        }
    }
}

void        Render(INFO* pInfo)
{
    cout << "================================" << endl;
    cout << "이름 : " << pInfo->szName << endl;
    cout << "체력 : " << pInfo->iHp << "\t공격력 : " << pInfo->iAttack << endl;
}

void        Field(INFO* pPlayer)
{
    int     iInput(0);

    INFO* pMonster = nullptr;

    bool    bSave(false);

    while (true)
    {
        system("cls");

        Render(pPlayer);
        cout << "1. 초급 2. 중급 3. 고급 4. 저장하기 5. 전 단계 : ";
        cin >> iInput;

        switch (iInput)
        {
        case 1:
            Create_Obj(&pMonster, "초급", 3, 30);
            break;

        case 2:
            Create_Obj(&pMonster, "중급", 6, 60);
            break;

        case 3:
            Create_Obj(&pMonster, "고급", 9, 90);
            break;

        case 4:
            bSave = Save_Data(pPlayer);
            break;

        case 5:
            return;

        default:
            cout << "잘못 입력하셨습니다" << endl;
            continue;
        }

        if (bSave)
        {
            bSave = false;
            continue;
        }

        int iResult = Fight(pPlayer, pMonster);

        if (1 == iResult)
        {
            pPlayer->iHp = 100;
        }

        if (nullptr != pMonster)
        {
            delete pMonster;
            pMonster = nullptr;
        }
    }
}
void        Create_Obj(INFO** ppInfo, const char* pName, int _iAttack, int _iHp)
{
    (*ppInfo) = new INFO;

    strcpy_s((*ppInfo)->szName, sizeof((*ppInfo)->szName), pName);
    (*ppInfo)->iAttack = _iAttack;
    (*ppInfo)->iHp = _iHp;
}

int Fight(INFO* pPlayer, INFO* pMonster)
{
    int iInput(0);

    while (true)
    {
        system("cls");

        Render(pPlayer);
        Render(pMonster);

        cout << "1. 공격 2. 도망 : ";
        cin >> iInput;

        switch (iInput)
        {
        case 1:
            pMonster->iHp -= pPlayer->iAttack;
            pPlayer->iHp -= pMonster->iAttack;
            break;

        case 2:
            return 0;

        default:
            cout << "잘못 입력" << endl;
            break;
        }

        if (0 >= pPlayer->iHp)
        {
            cout << "사망" << endl;
            system("pause");

            return 1;
        }

        if (0 >= pMonster->iHp)
        {
            cout << "승리" << endl;

            system("pause");
            return 0;
        }

    }
}

void PrintBinary(const INFO* pPlayer) {
    const size_t size = sizeof(INFO);
    for (size_t i = 0; i < size; ++i) {
        // 각 바이트를 비트셋으로 변환하고 출력
        std::bitset<8> byteBits(*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(pPlayer) + i));
        std::cout << byteBits << ' ';
    }
    std::cout << std::endl;
}

bool Save_Data(INFO* pPlayer)
{
    FILE* pSaveFile = NULL;

    errno_t err = fopen_s(&pSaveFile, "../Data/Save.txt", "wb");

    if (0 == err)
    {
        cout << "pPlayer의 값: "<<pPlayer << endl;
        fwrite(pPlayer, sizeof(INFO), 1, pSaveFile);
        //PrintBinary(pPlayer);

        cout << "저장 성공" << endl;

        fclose(pSaveFile);

        system("pause");
        return true;
    }

    else
        cout << "저장 실패" << endl;

    return false;
}

bool Load_Data(INFO** ppPlayer)
{
    FILE* pLoadFile = NULL;

    *ppPlayer = new INFO;

    errno_t err = fopen_s(&pLoadFile, "../Data/Save.txt", "rb");

    if (0 == err)
    {
        fread((*ppPlayer), sizeof(INFO), 1, pLoadFile);

        cout << "불러오기 성공" << endl;

        fclose(pLoadFile);

        system("pause");
        return true;
    }

    else
        cout << "저장 실패" << endl;

    return false;
}

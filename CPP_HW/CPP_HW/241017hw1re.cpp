/*
 cout << "pPlayer�� ��: "<<pPlayer << endl;
 fwrite(pPlayer, sizeof(INFO), 1, pSaveFile);
 pPlayer�� ���� 0000028C6D1450E0�� INFO ����ü�� �޸� �ּ��Դϴ�. 
 �� �ּҴ� pPlayer�� ����Ű�� �ִ� ���� �����Ͱ� �ƴմϴ�. 
 fwrite �Լ��� pPlayer�� ����Ű�� �޸� �ּҿ��� �����ϴ� INFO ����ü�� �����͸� ���̳ʸ� �������� ���Ͽ� ���ϴ�.
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
        cout << "�÷��̾� �Ҵ� �ȵ�" << endl;
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

        cout << "������ �����ϼ���(1. ���� 2. ���� 3. ������ 4. �ҷ����� 5. ����) : ";
        cin >> iInput;

        switch (iInput)
        {
        case WARRIOR:
            pTemp = new INFO;

            strcpy_s(pTemp->szName, sizeof(pTemp->szName), "����");
            pTemp->iAttack = 10;
            pTemp->iHp = 100;
            bSelect = true;
            break;

        case MAGE:
            Create_Obj(&pTemp, "������", 10, 100);
            bSelect = true;
            break;

        case THIEF:
            Create_Obj(&pTemp, "����", 10, 100);
            bSelect = true;
            break;

        case LOADING:
            bSelect = Load_Data(&pTemp);
            break;

        case END:
            cout << "������ �����մϴ�" << endl;
            bSelect = true;
            break;

        default:
            cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
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
        cout << "1. ����� 2. ���� : ";
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
    cout << "�̸� : " << pInfo->szName << endl;
    cout << "ü�� : " << pInfo->iHp << "\t���ݷ� : " << pInfo->iAttack << endl;
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
        cout << "1. �ʱ� 2. �߱� 3. ��� 4. �����ϱ� 5. �� �ܰ� : ";
        cin >> iInput;

        switch (iInput)
        {
        case 1:
            Create_Obj(&pMonster, "�ʱ�", 3, 30);
            break;

        case 2:
            Create_Obj(&pMonster, "�߱�", 6, 60);
            break;

        case 3:
            Create_Obj(&pMonster, "���", 9, 90);
            break;

        case 4:
            bSave = Save_Data(pPlayer);
            break;

        case 5:
            return;

        default:
            cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
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

        cout << "1. ���� 2. ���� : ";
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
            cout << "�߸� �Է�" << endl;
            break;
        }

        if (0 >= pPlayer->iHp)
        {
            cout << "���" << endl;
            system("pause");

            return 1;
        }

        if (0 >= pMonster->iHp)
        {
            cout << "�¸�" << endl;

            system("pause");
            return 0;
        }

    }
}

void PrintBinary(const INFO* pPlayer) {
    const size_t size = sizeof(INFO);
    for (size_t i = 0; i < size; ++i) {
        // �� ����Ʈ�� ��Ʈ������ ��ȯ�ϰ� ���
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
        cout << "pPlayer�� ��: "<<pPlayer << endl;
        fwrite(pPlayer, sizeof(INFO), 1, pSaveFile);
        //PrintBinary(pPlayer);

        cout << "���� ����" << endl;

        fclose(pSaveFile);

        system("pause");
        return true;
    }

    else
        cout << "���� ����" << endl;

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

        cout << "�ҷ����� ����" << endl;

        fclose(pLoadFile);

        system("pause");
        return true;
    }

    else
        cout << "���� ����" << endl;

    return false;
}

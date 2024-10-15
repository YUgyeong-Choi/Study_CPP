#include <iostream>

using namespace std;

typedef struct tagInfo
{
    char  szName[32];
    int   iKor, iEng, iMath, iTotal;
    float fAver;

}INFO;

enum NUMBER
{
    INPUT = 1,
    OUTPUT,
    SEARCH,
    END
};

void    Input_Data(INFO pStudent[], int _iCount);
void    Output_Data(INFO pStudent[], int _iCount);
void    Search_Data(INFO pStudent[], int _iCount);


int main()
{
    const       int iCount(3);

    INFO        tStudent[iCount] = { };

    int         iInput(0);

    while (true)
    {
        system("cls");

        cout << "1. �Է� 2. ��� 3. �˻� 4. ���� : ";
        cin >> iInput;

        void (*pFunc[3])(INFO*, int) = { Input_Data, Output_Data, Search_Data };

        if (4 == iInput)
            return 0;

        pFunc[iInput - 1](tStudent, iCount);

        system("pause");
    }

    return 0;
}

void Input_Data(INFO pStudent[], int _iCount)
{
    for (int i = 0; i < _iCount; ++i)
    {
        cout << "�̸� �Է� : ";
        cin >> pStudent[i].szName;

        cout << "���� �Է� : ";
        cin >> pStudent[i].iKor;

        cout << "���� �Է� : ";
        cin >> pStudent[i].iEng;

        cout << "���� �Է� : ";
        cin >> pStudent[i].iMath;

        pStudent[i].iTotal = pStudent[i].iKor + pStudent[i].iEng + pStudent[i].iMath;
        pStudent[i].fAver = (float)pStudent[i].iTotal / 3.f;
    }

}

void Output_Data(INFO pStudent[], int _iCount)
{
    for (int i = 0; i < _iCount; ++i)
    {
        cout << "�̸� : " << pStudent[i].szName << endl;
        cout << "���� : " << pStudent[i].iKor << endl;
        cout << "���� : " << pStudent[i].iEng << endl;
        cout << "���� : " << pStudent[i].iMath << endl;
        cout << "���� : " << pStudent[i].iTotal << endl;
        cout << "��� : " << pStudent[i].fAver << endl;
        cout << "------------------------------------" << endl;
    }
}

void Search_Data(INFO pStudent[], int _iCount)
{
    char    szFindName[32] = "";

    cout << "ã�� �л��� �̸��� �Է��ϼ��� : ";
    cin >> szFindName;

    for (int i = 0; i < _iCount; ++i)
    {
        if (!strcmp(szFindName, pStudent[i].szName))
        {
            cout << "�̸� : " << pStudent[i].szName << endl;
            cout << "���� : " << pStudent[i].iKor << endl;
            cout << "���� : " << pStudent[i].iEng << endl;
            cout << "���� : " << pStudent[i].iMath << endl;
            cout << "���� : " << pStudent[i].iTotal << endl;
            cout << "��� : " << pStudent[i].fAver << endl;
            cout << "------------------------------------" << endl;

            return;
        }
    }

    cout << "ã�� �л��� �����ϴ�. ��ܿ��� ������ �л����� �ֽ��ϴ�." << endl;

    for (int i = 0; i < _iCount; ++i)
    {
        cout << "�̸� : " << pStudent[i].szName << endl;
    }
}

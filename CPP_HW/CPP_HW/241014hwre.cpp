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

        cout << "1. 입력 2. 출력 3. 검색 4. 종료 : ";
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
        cout << "이름 입력 : ";
        cin >> pStudent[i].szName;

        cout << "국어 입력 : ";
        cin >> pStudent[i].iKor;

        cout << "영어 입력 : ";
        cin >> pStudent[i].iEng;

        cout << "수학 입력 : ";
        cin >> pStudent[i].iMath;

        pStudent[i].iTotal = pStudent[i].iKor + pStudent[i].iEng + pStudent[i].iMath;
        pStudent[i].fAver = (float)pStudent[i].iTotal / 3.f;
    }

}

void Output_Data(INFO pStudent[], int _iCount)
{
    for (int i = 0; i < _iCount; ++i)
    {
        cout << "이름 : " << pStudent[i].szName << endl;
        cout << "국어 : " << pStudent[i].iKor << endl;
        cout << "영어 : " << pStudent[i].iEng << endl;
        cout << "수학 : " << pStudent[i].iMath << endl;
        cout << "총점 : " << pStudent[i].iTotal << endl;
        cout << "평균 : " << pStudent[i].fAver << endl;
        cout << "------------------------------------" << endl;
    }
}

void Search_Data(INFO pStudent[], int _iCount)
{
    char    szFindName[32] = "";

    cout << "찾는 학생의 이름을 입력하세요 : ";
    cin >> szFindName;

    for (int i = 0; i < _iCount; ++i)
    {
        if (!strcmp(szFindName, pStudent[i].szName))
        {
            cout << "이름 : " << pStudent[i].szName << endl;
            cout << "국어 : " << pStudent[i].iKor << endl;
            cout << "영어 : " << pStudent[i].iEng << endl;
            cout << "수학 : " << pStudent[i].iMath << endl;
            cout << "총점 : " << pStudent[i].iTotal << endl;
            cout << "평균 : " << pStudent[i].fAver << endl;
            cout << "------------------------------------" << endl;

            return;
        }
    }

    cout << "찾는 학생이 없습니다. 명단에는 다음의 학생들이 있습니다." << endl;

    for (int i = 0; i < _iCount; ++i)
    {
        cout << "이름 : " << pStudent[i].szName << endl;
    }
}

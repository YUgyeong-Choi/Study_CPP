#include <iostream>

using namespace std;

int main()
{
    FILE* pLoadFile = NULL;         // ����
    FILE* pSaveFile = NULL;         // �纻

    errno_t errLoad = fopen_s(&pLoadFile, "../Data/Image.jpg", "rb");
    errno_t errSave = fopen_s(&pSaveFile, "../Data/Copy2.jpg", "wb");

    fseek(pLoadFile, 0, SEEK_END); // Ŀ���� ���� �� �ڷ�

    int     iIndex = ftell(pLoadFile); // Ŀ�� ��ġ ����
   
    char* pCh = new char[iIndex]; //���� ũ�� ��ŭ �Ҵ�

    fseek(pLoadFile, 0, SEEK_SET); // Ŀ�� ������ ��

    fread(pCh, sizeof(char), iIndex, pLoadFile); //�ѱ��ھ� � �ִ��� ���� �о��
    fwrite(pCh, sizeof(char), iIndex, pSaveFile); //�ѱ��ھ� � �ִ��� ���� �ۼ���

    cout << "���� ���� ����" << endl;

    delete[] pCh; //�Ҵ� ����
    pCh = nullptr;

    fclose(pLoadFile);
    fclose(pSaveFile);

    return 0;
}
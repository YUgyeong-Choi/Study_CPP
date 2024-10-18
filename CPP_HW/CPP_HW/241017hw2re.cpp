#include <iostream>

using namespace std;

int main()
{
    FILE* pLoadFile = NULL;         // 원본
    FILE* pSaveFile = NULL;         // 사본

    errno_t errLoad = fopen_s(&pLoadFile, "../Data/Image.jpg", "rb");
    errno_t errSave = fopen_s(&pSaveFile, "../Data/Copy2.jpg", "wb");

    fseek(pLoadFile, 0, SEEK_END); // 커서를 글자 맨 뒤로

    int     iIndex = ftell(pLoadFile); // 커서 위치 얻음
   
    char* pCh = new char[iIndex]; //글자 크기 만큼 할당

    fseek(pLoadFile, 0, SEEK_SET); // 커서 앞으로 감

    fread(pCh, sizeof(char), iIndex, pLoadFile); //한글자씩 몇개 있는지 적고 읽어옴
    fwrite(pCh, sizeof(char), iIndex, pSaveFile); //한글자씩 몇개 있는지 적고 작성함

    cout << "파일 복사 성공" << endl;

    delete[] pCh; //할당 제거
    pCh = nullptr;

    fclose(pLoadFile);
    fclose(pSaveFile);

    return 0;
}
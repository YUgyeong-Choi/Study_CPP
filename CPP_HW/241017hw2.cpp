#include <iostream>
using namespace std;

//이미지 복사
int main() {
	FILE* pOriginFile = NULL;
	errno_t errOrigin = fopen_s(&pOriginFile, "../Data/Image.jpg", "rb");

	FILE* pCopyFile = NULL;
	errno_t errCopy = fopen_s(&pCopyFile, "../Data/Image2.jpg", "wb");

	int byte;

	if (0 == errOrigin && 0 == errCopy) {
		while ((byte = fgetc(pOriginFile)) != EOF) {
			fputc(byte, pCopyFile);
		}
	}
	else {
		cout << "파일 개방 실패";
	}

	return 0;
}
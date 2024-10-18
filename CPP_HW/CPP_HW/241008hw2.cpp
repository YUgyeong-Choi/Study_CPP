#include <iostream>
#include <ctime>
using namespace std;

void GetRandomLotto(int* _iArray, int _iLength); //중복되지 않은 랜덤 값 얻는 함수
void BubbleSort(int* _iArray, int _iLength); // 오름차순으로 정렬

//로또 만들기
int main() {
	srand(unsigned(time(NULL)));

	for (int i = 0; i < 5; i++) {
		int iArray[6] = { 0 };
		int _iLength = sizeof(iArray) / sizeof(int);
		GetRandomLotto(iArray, _iLength);
		BubbleSort(iArray, _iLength);

		for (int i = 0; i < _iLength; i++) {
			cout << iArray[i] << '\t';
		}
		cout << endl;
	}

	return 0;
}

void GetRandomLotto(int* _iArray, int _iLength)
{
	int _iRandomNum(0);

	for (int i = 0; i < _iLength; i++) {
		while (1) {
			bool _bCheck = true;
			_iRandomNum = rand() % 45 + 1;
			for (int j = 0; j < _iLength; j++) {
				if (_iArray[j] == _iRandomNum) {
					_bCheck = false;
				}
			}

			if (_bCheck == true) {
				break;
			}
		}
		_iArray[i] = _iRandomNum;
	}
}

void BubbleSort(int* _iArray, int _iLength)
{
	for (int i = 0; i < _iLength; ++i) {
		for (int j = 0; j < _iLength - i - 1; ++j) {
			if (_iArray[j] > _iArray[j + 1]) {
				int _iTemp = _iArray[j];
				_iArray[j] = _iArray[j + 1];
				_iArray[j + 1] = _iTemp;
			}
		}
	}

}

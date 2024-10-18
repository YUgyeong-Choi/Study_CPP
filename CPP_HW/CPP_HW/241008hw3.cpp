#include <iostream>
#include <ctime>
using namespace std;

void GetRandomNum(int* _iArray, int _iLength); // 무작위 3개 추출
void GetAnswer(int* _iArray, int* _iAnswer, int _iLength); //입력 받는 곳
int CheckStrike(int* _iArray, int* _iAnswer, int _iLength); //스트라이크 체크
int CheckBall(int* _iArray, int* _iAnswer, int _iLength); //볼 체크


//야구 게임
int main() {
	srand(unsigned(time(NULL)));

	int iArray[3] = { 0 };
	int iAnswer[3] = { 0 };
	int _iLength = sizeof(iArray) / sizeof(int); //Answer도 같은 길이라고 가정
	GetRandomNum(iArray, _iLength);

	int i = 0;
	for (i = 0; i < 9; ++i) {
		system("cls");
		int _iStrike(0), _iBall(0);
		cout << i+1 << "회차 입니다" << endl;
		
		GetAnswer(iArray, iAnswer, _iLength);
		_iStrike = CheckStrike(iArray, iAnswer, _iLength);
		_iBall = CheckBall(iArray, iAnswer, _iLength);
		cout << _iStrike << " 스트라이크   " << _iBall << " 볼" << endl;
		

		if (_iStrike == 3) {
			break;
		}
		system("pause");
	}

	if (i != 9) {
		cout << "********************" << endl;
		cout << "승리" << endl;
		cout << "********************" << endl;
	}
	else {
		cout << "********************" << endl;
		cout << "패배" << endl;
		cout << "********************" << endl;
	}

	return 0;
}

void GetRandomNum(int* _iArray, int _iLength)
{
	int _iRandomNum(0);

	for (int i = 0; i < _iLength; i++) {
		while (1) {
			bool _bCheck = true;
			_iRandomNum = rand() % 9 + 1;
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

void GetAnswer(int* _iArray, int* _iAnswer, int _iLength)
{
	cout << "정답: ";
	for (int i = 0; i < _iLength; ++i) {
		cout << _iArray[i] << " ";
	}
	cout << endl;


	while (1) {
		bool _bCheck = true;

		cout << "3개의 숫자를 입력하세요: ";
		cin >> _iAnswer[0] >> _iAnswer[1] >> _iAnswer[2];

		for (int i = 0; i < _iLength; ++i) {
			if (1 > _iAnswer[i] || 9 < _iAnswer[i]) {
				_bCheck = false;
			}
		}

		if (_bCheck == true) {
			break;
		}
		else {
			cout << "1 ~ 9 사이로 입력하셔야 합니다" << endl;
		}
	}
}

int CheckStrike(int* _iArray, int* _iAnswer, int _iLength)
{
	int _iCount(0);
	for (int i = 0; i < _iLength; ++i) {
		if (_iArray[i] == _iAnswer[i]) {
			_iCount++;
		}
	}
	return _iCount;
}

int CheckBall(int* _iArray, int* _iAnswer, int _iLength)
{
	int _iCount(0);
	for (int i = 0; i < _iLength; ++i) {
		for (int j = 0; j < _iLength; ++j) {
			if (_iArray[i] == _iAnswer[j]) {
				_iCount++;
			}
		}
	}

	return _iCount;
}

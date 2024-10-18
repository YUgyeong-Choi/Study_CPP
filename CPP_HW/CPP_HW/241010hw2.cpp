#include <iostream>
#include <ctime>
using namespace std;

void GetRandomArray(int (*_iArray)[5]);
int InputMyNum(int _iTime, int* _iAnswerArray, int(*_iMyArray)[5]);
int InputPcNum(int _iTime, int* _iAnswerArray, int(*_iPcArray)[5]);
bool CheckAnswerArray(int _iNum,int _iTime, int* _iAnswerArray);
void CheckStar(int _iNum, int(*_iMyArray)[5], int(*_iPcArray)[5]);
void PrintArray(int(*_iMyArray)[5]);
int CheckBingo(int(*_iMyArray)[5]);

int main() {
	srand(unsigned(time(NULL)));

	int _iMyBingo(0), _iPcBingo(0);
	int iMyArray[5][5] = { 0 };
	int iPcArray[5][5] = { 0 };
	int iAnswerArray[25] = { 0 };

	GetRandomArray(iMyArray);
	GetRandomArray(iPcArray);
	

	int _iTime(0);
	while (1) {
		system("cls");
		if (_iTime == 0) PrintArray(iMyArray);

		int _iNum(0);
		_iNum = InputMyNum(_iTime, iAnswerArray, iMyArray);
		CheckStar(_iNum, iMyArray, iPcArray);
		PrintArray(iMyArray);
		_iTime++;

		_iMyBingo = CheckBingo(iMyArray);
		_iPcBingo = CheckBingo(iPcArray);

		cout << "사용자 빙고: " << _iMyBingo << "개" << endl;
		cout << "컴퓨터 빙고: " << _iPcBingo << "개" << endl;

		if (_iMyBingo == 5) {
			cout << "사용자 승리" << endl;
			break;
		}
		else if (_iPcBingo == 5) {
			cout << "컴퓨터 승리" << endl;
			break;
		}


		_iNum = InputPcNum(_iTime, iAnswerArray, iMyArray);
		CheckStar(_iNum, iMyArray, iPcArray);
		PrintArray(iMyArray);
		_iTime++;

		_iMyBingo = CheckBingo(iMyArray);
		_iPcBingo = CheckBingo(iPcArray);

		cout << "사용자 빙고: " << _iMyBingo << "개" << endl;
		cout << "컴퓨터 빙고: " << _iPcBingo << "개" << endl;

		if (_iMyBingo == 5) {
			cout << "사용자 승리" << endl;
			break;
		}
		else if (_iPcBingo == 5) {
			cout << "컴퓨터 승리" << endl;
			break;
		}
		
		system("pause");
	}

	return 0;
}

void GetRandomArray(int(*_iArray)[5])
{
	int iRandomArray[25] = { 0 };
	int _iNum(0);

	for (int i = 0; i < 25; ++i) {
		iRandomArray[i] = i + 1;
	}

	int iDst(0), iSrc(0);
	for (int i = 0; i < 500; ++i) {
		iDst = rand() % 25;
		iSrc = rand() % 25;
		swap(iRandomArray[iDst], iRandomArray[iSrc]);
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			_iArray[i][j] = iRandomArray[_iNum];
			_iNum++;
		}
	}
}

int InputMyNum(int _iTime, int* _iAnswerArray, int(*_iMyArray)[5])
{
	int _iInput(0);
	while (1) {
		cout << "숫자를 입력하세요: ";
		cin >> _iInput;
		if (CheckAnswerArray(_iInput, _iTime, _iAnswerArray)) {
			_iAnswerArray[_iTime] = _iInput;
			break;
		}
		else {
			cout << "이미 선택한 숫자입니다" << endl;
		}
	}
	return _iInput;
}

int InputPcNum(int _iTime, int* _iAnswerArray, int(*_iPcArray)[5])
{
	int _iInput(0);
	while (1) {
		_iInput = rand() % 25 + 1;
		if (CheckAnswerArray(_iInput, _iTime, _iAnswerArray)) {
			_iAnswerArray[_iTime] = _iInput;
			cout <<endl<< "컴퓨터는 " << _iInput << "을 골랐어요" << endl;
			break;
		}
	}
	return _iInput;
}

bool CheckAnswerArray(int _iNum, int _iTime, int* _iAnswerArray)
{
	for (int i = 0; i < _iTime; i++) {
		if (_iAnswerArray[i] == _iNum) {
			return false;
		}
	}

	return true;
}

void CheckStar(int _iNum, int(*_iMyArray)[5], int(*_iPcArray)[5])
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (_iNum == _iMyArray[i][j]) {
				_iMyArray[i][j] = 0;
			}

			if (_iNum == _iPcArray[i][j]) {
				_iPcArray[i][j] = 0;
			}
		}
	}
}

void PrintArray(int(*_iMyArray)[5])
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << _iMyArray[i][j] << "\t";
		}
		cout << endl;
	}
}

int CheckBingo(int(*_iMyArray)[5])
{
	int iCheckBingo(0);
	int iCheckNum(0);
	// 가로빙고
	for (int i = 0; i < 5; i++) {
		iCheckNum = 0;
		for (int j = 0; j < 5; j++) {
			if (_iMyArray[i][j] == 0) iCheckNum++;
		}

		if (iCheckNum == 5) {
			iCheckBingo++;
		}
	}

	// 세로빙고
	for (int i = 0; i < 5; i++) {
		iCheckNum = 0;
		for (int j = 0; j < 5; j++) {
			if (_iMyArray[j][i] == 0) iCheckNum++;
		}

		if (iCheckNum == 5) {
			iCheckBingo++;
		}
	}

	// 왼쪽에서 오른쪽으로 대각선 빙고
	iCheckNum = 0;
	for (int i = 0; i < 5; i++) {
		if (_iMyArray[i][i] == 0) {
			iCheckNum++;
		}
		if (iCheckNum == 5) {
			iCheckBingo++;
		}
	}

	// 오른쪽에서 왼쪽으로 대각선 빙고
	iCheckNum = 0; 
	for (int i = 0; i < 5; i++) {
		if (_iMyArray[i][4 - i] == 0) {
			iCheckNum++;
		}
	}
	if (iCheckNum == 5) {
		iCheckBingo++;
	}

	return iCheckBingo;
}

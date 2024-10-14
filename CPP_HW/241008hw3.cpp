#include <iostream>
#include <ctime>
using namespace std;

void GetRandomNum(int* _iArray, int _iLength); // ������ 3�� ����
void GetAnswer(int* _iArray, int* _iAnswer, int _iLength); //�Է� �޴� ��
int CheckStrike(int* _iArray, int* _iAnswer, int _iLength); //��Ʈ����ũ üũ
int CheckBall(int* _iArray, int* _iAnswer, int _iLength); //�� üũ


//�߱� ����
int main() {
	srand(unsigned(time(NULL)));

	int iArray[3] = { 0 };
	int iAnswer[3] = { 0 };
	int _iLength = sizeof(iArray) / sizeof(int); //Answer�� ���� ���̶�� ����
	GetRandomNum(iArray, _iLength);

	int i = 0;
	for (i = 0; i < 9; ++i) {
		system("cls");
		int _iStrike(0), _iBall(0);
		cout << i+1 << "ȸ�� �Դϴ�" << endl;
		
		GetAnswer(iArray, iAnswer, _iLength);
		_iStrike = CheckStrike(iArray, iAnswer, _iLength);
		_iBall = CheckBall(iArray, iAnswer, _iLength);
		cout << _iStrike << " ��Ʈ����ũ   " << _iBall << " ��" << endl;
		

		if (_iStrike == 3) {
			break;
		}
		system("pause");
	}

	if (i != 9) {
		cout << "********************" << endl;
		cout << "�¸�" << endl;
		cout << "********************" << endl;
	}
	else {
		cout << "********************" << endl;
		cout << "�й�" << endl;
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
	cout << "����: ";
	for (int i = 0; i < _iLength; ++i) {
		cout << _iArray[i] << " ";
	}
	cout << endl;


	while (1) {
		bool _bCheck = true;

		cout << "3���� ���ڸ� �Է��ϼ���: ";
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
			cout << "1 ~ 9 ���̷� �Է��ϼž� �մϴ�" << endl;
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

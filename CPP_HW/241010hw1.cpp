#include <iostream>
using namespace std;

// 1. 2���� �迭�� �̿��Ͽ� ������ ���·� ���� ����� �ؿͶ�
/*
1	2	3				7	4	1				9	8	7				3	6	9				1	2	3
4	5	6	-90�� ȸ��>	8	5	2 - 90�� ȸ�� >	6	5	4 - 90�� ȸ�� >	2	5	8 - 90�� ȸ�� >	4	5	6
7	8	9				9	6	3				3	2	1				1	4	7				7	8	9
*/

int main() {
	int iArray[3][3] = {0};

	int _iNum(1);

	cout << "ù ��°" << endl;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			iArray[i][j] = _iNum;
			_iNum++;
			cout << iArray[i][j] << '\t';
		}
		cout << "\n";
	}

	_iNum = 1;
	cout << "�� ��°" << endl;
	for (int i = 0; i < 3; ++i) {
		for (int j = 2; j >=0 ; --j) {
			_iNum;
			cout << iArray[j][i] << '\t';
		}
		cout << "\n";
	}

	_iNum = 1;
	cout << "�� ��°" << endl;
	for (int i = 2; i >= 0; --i) {
		for (int j = 2; j >= 0; --j) {
			_iNum;
			cout << iArray[i][j] << '\t';
		}
		cout << "\n";
	}

	_iNum = 1;
	cout << "�� ��°" << endl;
	for (int i = 2; i >= 0; --i) {
		for (int j = 0; j < 3; ++j) {
			_iNum;
			cout << iArray[j][i] << '\t';
		}
		cout << "\n";
	}




	return 0;
}
#include <iostream>
using namespace std;

// 숫자 이동시키기
int main() {
	int iArray[5][5] = { 0 };
	int _iXIndex(0), _iYIndex(0);

	int _iNum(0);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			iArray[i][j] = _iNum;
			_iNum++;
		}
	}

	while (1) {
		system("cls");
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				cout<<iArray[i][j]<<'\t';
			}
			cout << endl;
		}

		cout << endl;
		while (1) {
			int _iChoose(0);
			cout << "2(아래쪽) 4(왼쪽) 6(오른쪽) 8(위쪽): ";
			cin >> _iChoose;

			if (_iChoose == 2) {
				if (4 == _iXIndex) {
					cout << "아래쪽 예외" << endl;
					continue;
				}
				else {
					_iXIndex++;
					swap(iArray[_iXIndex-1][_iYIndex], iArray[_iXIndex][_iYIndex]);
					break;
				}
				
			}
			else if (_iChoose == 4) {
				if (0 == _iYIndex) {
					cout << "왼쪽 예외" << endl;
					continue;
				}
				else {
					_iYIndex--;
					swap(iArray[_iXIndex][_iYIndex+1], iArray[_iXIndex][_iYIndex]);
					break;
				}
			}
			else if (_iChoose == 6) {
				if (4 == _iXIndex) {
					cout << "오른쪽 예외" << endl;
					continue;
				}
				else {
					_iYIndex++;
					swap(iArray[_iXIndex][_iYIndex-1], iArray[_iXIndex][_iYIndex]);
					break;
				}
			}
			else if(_iChoose == 8){
				if (0 == _iXIndex) {
					cout << "위쪽 예외" << endl;
					continue;
				}
				else {
					_iXIndex--;
					swap(iArray[_iXIndex+1][_iYIndex], iArray[_iXIndex][_iYIndex]);
					break;
				}
			}
			else {
				cout << "잘못된 입력" << endl;
			}
		}
		system("pause");
	}

	return 0;
}
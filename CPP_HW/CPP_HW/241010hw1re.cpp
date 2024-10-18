#include <iostream>
using namespace std;

void Render(int _iArray[][3]);

// ù���� ������ �� �ٲ� �� ij��ġ �ٲٸ� ��
int main() {
	int iArray[3][3] = {};
	int iRotation[3][3] = {};

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			iArray[i][j] = i * 3 + j + 1;
		}
	}

	Render(iArray);

	for (int k = 0; k < 4; ++k) {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				iRotation[j][3 - i - 1] = iArray[i][j];
			}
		}

		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				iArray[i][j] = iRotation[i][j];
			}
		}
		cout << "====================" << endl;
		Render(iArray);
	}

	return 0;
}

void Render(int _iArray[][3])
{
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cout << _iArray[i][j]<<'\t';
		}
		cout << endl;
	}
}

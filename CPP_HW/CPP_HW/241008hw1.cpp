#include <iostream>
using namespace std;

int main() {
	int iArray[25] = {0};

	for (int i = 1; i <= 25; i++) {
		iArray[i - 1] = i;
	}

	int _iIndex(0);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << iArray[_iIndex] << '\t';
			_iIndex++;
		}
		cout << endl;
	}


	return 0;
}
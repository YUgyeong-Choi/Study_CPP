#include <iostream>
#include <ctime>
using namespace std;

//Ȧ¦ ����
int main() {
	int _iInput(0), _iTime(0), _iWin(0);

	srand(unsigned(time(NULL)));
	while (1) {
		while (1) {
			cout << "1.Ȧ 2.¦ 3.����" << endl;
			cin >> _iInput;
			if (1 <= _iInput && 3 >= _iInput) {
				break;
			}
		}

		if (rand()%2 == 1 && _iInput == 1) {
			_iWin++;
		}
		else if (rand() % 2 == 0 && _iInput == 2) {
			_iWin++;
		}
		else if (_iInput == 3) {
			cout << _iWin << "�� " << _iTime - _iWin << "��" << endl;
			break;
		}

		_iTime++;
		if (_iTime == 5) {
			cout << _iWin << "�� " << _iTime - _iWin << "��" << endl;
			break;
		}
	}
	return 0;
}
#include <iostream>
using namespace std;

int main() {
	int _iGub(0), _iDan(0);
	cout << "�ܰ� �� �Է��ϼ���" << endl;
	cin >> _iGub >> _iDan;

	for (int i = 2; i <= _iGub; i++) {
		for (int j = 1; j <= _iDan; j++) {
			cout << i << " * " << j << " = " << i * j << endl;
		}
	}

	return 0;
}
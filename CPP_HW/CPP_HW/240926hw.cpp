#include <iostream>
using namespace std;

// ��� �ű��
int main() {
	float fAver(0);

	cout << "���� ��� ���� �Է����ּ���: " << endl;
	cin >> fAver;
	
	if (0.0f > fAver || 100.0f < fAver) {
		cout<<"�߸��� �� �Է�" << endl;
	}

	if (90.0f <= fAver && 100.0f >= fAver) {
		cout << "A" << endl;
	}else if (80.0f <= fAver && 90.0f > fAver) {
		cout << "B" << endl;
	}else if (70.0f <= fAver && 80.0f > fAver) {
		cout << "C" << endl;
	}else if (60.0f <= fAver && 70.0f > fAver) {
		cout << "D" << endl;
	}
	else {
		cout << "F" << endl;
	}
	return 0;
}
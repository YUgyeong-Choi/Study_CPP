#include <iostream>
using namespace std;

// 1. ���ڿ��� �Է� �ް� null���ڸ� ������ ������ ���ڿ��� ���̸� ���ϴ� �Լ� �����
int main() {
	char szName[1000] = "";
	cin >> szName;
	
	int i = 0;
	while (true) {
		if (szName[i] == '\0') {
			break;
		}
		i++;
	}

	cout << i << endl;

	return 0;
}
#include <iostream>
using namespace std;

// 2. �Է� ���� ���ڿ��� ������ ����϶�.
int main() {
	char szName[1000] = "";
	cin >> szName;

	int iCount = 0;
	while (true) {
		if (szName[iCount] == '\0') {
			break;
		}
		iCount++;
	}

	for (int i = iCount-1; i >=0; --i) {
		cout << szName[i];
	}

	return 0;
}
#include <iostream>
using namespace std;

// 1. 문자열을 입력 받고 null문자를 제외한 순수한 문자열의 길이를 구하는 함수 만들기
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
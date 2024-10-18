#include <iostream>
using namespace std;

//이중 for 문을 이용한 구구단
int main() {
	for (int i = 2; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cout << i << " * " << j << " = " << i * j << endl;
		}
	}
	return 0;
}
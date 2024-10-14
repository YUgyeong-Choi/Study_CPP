#include <iostream>
using namespace std;

//º°Âï±â
int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j <= i; j++) {
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < 5; i++) {
		for (int j = 5; j - i > 0; j--) {
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5 - i-1; j++) {
			cout << " ";
		}
		for (int j = 5; j > 5 - i-1; j--) {
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < i; j++) {
			cout << " ";
		}
		for (int j = 0; j < 5-i; j++) {
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}
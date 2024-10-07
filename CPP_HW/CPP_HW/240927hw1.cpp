#include <iostream>
using namespace std;

//±¸±¸´Ü
int main() {
	int _iGugudan(2), i(1);

	while (_iGugudan <= 9) {
		cout << _iGugudan << " * " << i << " = " << _iGugudan * i <<endl;
		i++;
		if (i == 10) {
			i = 1;
			_iGugudan++;
		}
	}

	return 0;
}
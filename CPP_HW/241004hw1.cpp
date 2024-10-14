#include <iostream>
using namespace std;

int Factorial(int _iNumber);

int main() {

	cout<<Factorial(5);
	return 0;
}

int Factorial(int _iNumber)
{
	if (_iNumber == 1 || _iNumber == 0) {
		return 1;
	}

	return _iNumber * Factorial(_iNumber-1);
}

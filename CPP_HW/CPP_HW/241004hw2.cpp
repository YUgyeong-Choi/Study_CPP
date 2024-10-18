#include <iostream>
using namespace std;

void Temp(int* _iDst, int* _iSrc);

int main() {
	int _iDst(10), _iSrc(20);
	Temp(&_iDst, &_iSrc);
	cout << _iDst << " " << _iSrc;
	return 0;
}

void Temp(int* _iDst, int* _iSrc)
{
	int temp = *_iDst;
	*_iDst = *_iSrc;
	*_iSrc = temp;
}

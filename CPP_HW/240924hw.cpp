#include <iostream>
using namespace std;

// �հ� ���
int main() {
	int _iKor(0), _iEng(0), _iMath(0), _iSum(0);
	float _iAver(0);

	cout << "���� ���� ���� ������ �Է����ּ���: ";
	cin >> _iKor >> _iEng >> _iMath;

	_iSum = _iKor + _iEng + _iMath;
	_iAver = _iSum / 3.f;
	cout << "����" << '\t' << "����" << '\t' << "����" << '\t' << "����" << '\t' << "���" << endl;
	cout << _iKor << '\t' << _iEng << '\t' << _iMath << '\t' << _iSum << '\t' << _iAver;
	return 0;
}
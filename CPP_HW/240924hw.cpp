#include <iostream>
using namespace std;

// 합과 평균
int main() {
	int _iKor(0), _iEng(0), _iMath(0), _iSum(0);
	float _iAver(0);

	cout << "국어 영어 수학 점수를 입력해주세요: ";
	cin >> _iKor >> _iEng >> _iMath;

	_iSum = _iKor + _iEng + _iMath;
	_iAver = _iSum / 3.f;
	cout << "국어" << '\t' << "영어" << '\t' << "수학" << '\t' << "총점" << '\t' << "평균" << endl;
	cout << _iKor << '\t' << _iEng << '\t' << _iMath << '\t' << _iSum << '\t' << _iAver;
	return 0;
}
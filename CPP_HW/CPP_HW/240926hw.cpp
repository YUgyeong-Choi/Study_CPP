#include <iostream>
using namespace std;

// 등급 매기기
int main() {
	float fAver(0);

	cout << "성적 평균 값을 입력해주세요: " << endl;
	cin >> fAver;
	
	if (0.0f > fAver || 100.0f < fAver) {
		cout<<"잘못된 값 입력" << endl;
	}

	if (90.0f <= fAver && 100.0f >= fAver) {
		cout << "A" << endl;
	}else if (80.0f <= fAver && 90.0f > fAver) {
		cout << "B" << endl;
	}else if (70.0f <= fAver && 80.0f > fAver) {
		cout << "C" << endl;
	}else if (60.0f <= fAver && 70.0f > fAver) {
		cout << "D" << endl;
	}
	else {
		cout << "F" << endl;
	}
	return 0;
}
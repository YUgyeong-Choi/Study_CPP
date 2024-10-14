#include <iostream>
using namespace std;

//자판기 게임
int main() {
	int _iMoney(0), _iInput(0),_iCoke(100), _iCider(200), _iFanta(300);

	while (1) {
		cout << "소지금을 입력하세요" << endl;
		cin >> _iMoney;

		if (0 <= _iMoney) {
			break;
		}
	}

	while (1) {
		system("cls");
		cout << "메뉴" << endl;
		cout << "1.콜라 : 100원" << endl;
		cout << "2.사이다 : 200원" << endl;
		cout << "3.환타 : 300원" << endl;
		cout << "4.반환" << endl;
		cout << "====================" << endl;

		while (1) {
			cin >> _iInput;
			if (1 <= _iInput && 4 >= _iInput) {
				break;
			}
			else {
				cout << "다시 선택해주세요" << endl;
			}
		}

		if (_iInput == 1) {
			if (_iMoney >= _iCoke) {
				_iMoney -= _iCoke;
				cout << "콜라 구매 완료" << endl;
				cout << "보유 잔액 : " << _iMoney << endl;
			}
			else {
				cout << "잔액이 부족합니다" << endl;
			}
		}else if (_iInput == 2) {
			if (_iMoney >= _iCider) {
				_iMoney -= _iCider;
				cout << "사이다 구매 완료" << endl;
				cout << "보유 잔액 : " << _iMoney << endl;
			}
			else {
				cout << "잔액이 부족합니다" << endl;
			}
		}
		else if (_iInput == 3) {
			if (_iMoney >= _iFanta) {
				_iMoney -= _iFanta;
				cout << "환타 구매 완료" << endl;
				cout << "보유 잔액 : " << _iMoney << endl;
			}
			else {
				cout << "잔액이 부족합니다" << endl;
			}
		}
		else {
			cout << "거스름 돈은 " << _iMoney << "원 입니다" << endl;
			break;
		}
		system("pause");
	}

	return 0;
}
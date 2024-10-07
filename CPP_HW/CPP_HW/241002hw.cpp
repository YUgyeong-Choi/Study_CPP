#include <iostream>
using namespace std;

int InputMoney(); // 소지금 입력
int PrintMenu(); //메뉴판 출력 및 번호 선택
int Purchase(int _iMoney, int _iCost); //구매


//자판기 게임 with 함수
int main() {
	int _iMoney(0), _iInput(0), _iCoke(100), _iCider(200), _iFanta(300);

	_iMoney = InputMoney();
	while (1) {
		system("cls");
		_iInput = PrintMenu();

		if (_iInput == 1) {
			_iMoney = Purchase(_iMoney, _iCoke);
		}
		else if (_iInput == 2) {
			_iMoney = Purchase(_iMoney, _iCider);
		}
		else if (_iInput == 3) {
			_iMoney = Purchase(_iMoney, _iFanta);
		}
		else {
			cout << "거스름 돈은 " << _iMoney << "원 입니다" << endl;
			break;
		}
		system("pause");
	}

	return 0;
}

int InputMoney()
{
	int _iMoney(0);
	while (1) {
		cout << "소지금을 입력하세요" << endl;
		cin >> _iMoney;

		if (0 <= _iMoney) {
			break;
		}
	}

	return _iMoney;
}

int PrintMenu()
{
	int _iInput(0);
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
	return _iInput;
}

int Purchase(int _iMoney, int _iCost)
{
	if (_iMoney >= _iCost) {
		_iMoney -= _iCost;
		cout << "콜라 구매 완료" << endl;
		cout << "보유 잔액 : " << _iMoney << endl;
	}
	else {
		cout << "잔액이 부족합니다" << endl;
	}
	return _iMoney;
}

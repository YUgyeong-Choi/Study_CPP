#include <iostream>
using namespace std;

//���Ǳ� ����
int main() {
	int _iMoney(0), _iInput(0),_iCoke(100), _iCider(200), _iFanta(300);

	while (1) {
		cout << "�������� �Է��ϼ���" << endl;
		cin >> _iMoney;

		if (0 <= _iMoney) {
			break;
		}
	}

	while (1) {
		system("cls");
		cout << "�޴�" << endl;
		cout << "1.�ݶ� : 100��" << endl;
		cout << "2.���̴� : 200��" << endl;
		cout << "3.ȯŸ : 300��" << endl;
		cout << "4.��ȯ" << endl;
		cout << "====================" << endl;

		while (1) {
			cin >> _iInput;
			if (1 <= _iInput && 4 >= _iInput) {
				break;
			}
			else {
				cout << "�ٽ� �������ּ���" << endl;
			}
		}

		if (_iInput == 1) {
			if (_iMoney >= _iCoke) {
				_iMoney -= _iCoke;
				cout << "�ݶ� ���� �Ϸ�" << endl;
				cout << "���� �ܾ� : " << _iMoney << endl;
			}
			else {
				cout << "�ܾ��� �����մϴ�" << endl;
			}
		}else if (_iInput == 2) {
			if (_iMoney >= _iCider) {
				_iMoney -= _iCider;
				cout << "���̴� ���� �Ϸ�" << endl;
				cout << "���� �ܾ� : " << _iMoney << endl;
			}
			else {
				cout << "�ܾ��� �����մϴ�" << endl;
			}
		}
		else if (_iInput == 3) {
			if (_iMoney >= _iFanta) {
				_iMoney -= _iFanta;
				cout << "ȯŸ ���� �Ϸ�" << endl;
				cout << "���� �ܾ� : " << _iMoney << endl;
			}
			else {
				cout << "�ܾ��� �����մϴ�" << endl;
			}
		}
		else {
			cout << "�Ž��� ���� " << _iMoney << "�� �Դϴ�" << endl;
			break;
		}
		system("pause");
	}

	return 0;
}
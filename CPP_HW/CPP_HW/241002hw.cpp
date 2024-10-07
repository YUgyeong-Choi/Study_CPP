#include <iostream>
using namespace std;

int InputMoney(); // ������ �Է�
int PrintMenu(); //�޴��� ��� �� ��ȣ ����
int Purchase(int _iMoney, int _iCost); //����


//���Ǳ� ���� with �Լ�
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
			cout << "�Ž��� ���� " << _iMoney << "�� �Դϴ�" << endl;
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
		cout << "�������� �Է��ϼ���" << endl;
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
	return _iInput;
}

int Purchase(int _iMoney, int _iCost)
{
	if (_iMoney >= _iCost) {
		_iMoney -= _iCost;
		cout << "�ݶ� ���� �Ϸ�" << endl;
		cout << "���� �ܾ� : " << _iMoney << endl;
	}
	else {
		cout << "�ܾ��� �����մϴ�" << endl;
	}
	return _iMoney;
}

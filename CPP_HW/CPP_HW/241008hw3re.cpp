#include <iostream>
#include <ctime>
using namespace std;

void Get_Swap_Random(int _iArray[]); //swap�� �̿��� ���
void Get_Dupli_Random(int _iArray[]); //�ߺ� Ȯ���� �̿��� ���
void Get_Input(int _iAnswer[]);
void Check(int _iArray[], int _iAnswer[], int _iCheck[]);

int main() {
	srand(unsigned(time(NULL)));
	int iArray[3] = { 0 };
	int iAnswer[3] = { 0 };
	int iCheck[2] = { 0 };
	int i = 0;

	//Get_Swap_Random(iArray);
	Get_Dupli_Random(iArray);

	for (  ; i < 9; ++i) {
		cout << i + 1 << "ȸ�� �Դϴ�" << endl;
		
		cout << "����: ";
		for (int j = 0; j < 3; ++j) {
			cout << iArray[j] << " ";
		}
		cout << endl;

		Get_Input(iAnswer);

		Check(iArray, iAnswer, iCheck);
		cout << "��Ʈ����ũ:" << iCheck[0] << " ��:" << iCheck[1]<<endl;
		if (iCheck[0] == 3) {
			cout << "�¸�" << endl;
			break;
		}

		if (i == 9) {
			cout << "�й�"<<endl;
		}
	}



	return 0;
}

void Get_Swap_Random(int _iArray[])
{
	int iOneToNine[9] = {0};
	for (int i = 1; i <= 9; ++i) {
		iOneToNine[i - 1] = i;
	}

	for (int i = 0; i < 5000; ++i) {
		int a = rand() % 9;
		int b = rand() % 9;

		swap(iOneToNine[a], iOneToNine[b]);
	}

	_iArray[0] = iOneToNine[0];
	_iArray[1] = iOneToNine[1];
	_iArray[2] = iOneToNine[2];
}

void Get_Dupli_Random(int _iArray[])
{
	for (int i = 0; i < 3; ++i) {
		_iArray[i] = rand() % 9 + 1;
		for (int j = 0; j < i; ++j) {
			if (_iArray[j] == _iArray[i]) {
				i--;
				continue;
			}
		}
	}
}

void Get_Input(int _iAnswer[])
{
	cout << "3���� ���ڸ� �Է��ϼ���: ";
	cin >> _iAnswer[0] >> _iAnswer[1] >> _iAnswer[2];
}

void Check(int _iArray[], int _iAnswer[], int _iCheck[])
{
	_iCheck[0] = 0;
	_iCheck[1] = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (_iArray[i] == _iAnswer[j] && i == j) _iCheck[0]++;
			else if (_iArray[i] == _iAnswer[j]) _iCheck[1]++;
		}
	}
}

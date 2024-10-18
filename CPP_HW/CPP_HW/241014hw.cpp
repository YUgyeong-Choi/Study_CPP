#include <iostream>
#include <string>
using namespace std;

//1. ����ǥ �����(����ü�� Ȱ���� ��)
//3���� �л��� ���� ����� ���α׷��� �����, �̸� ���� ���� ���� ���� ��� ���ؼ� ���
//�̸� �˻��ؼ� ���ϴ� �л� ���� ã�� ���

struct StudentInfo {
	char cName[30];
	int iKor;
	int iEng;
	int iMath;
	int iSum;
	float fAver;
};

void Input(StudentInfo* students);
void PrintAllStudent(StudentInfo* students);
void ChooseStudent(StudentInfo* students);

int main() {
	StudentInfo students[100];
	Input(students);
	PrintAllStudent(students);
	ChooseStudent(students);

	return 0;
}

void Input(StudentInfo* students)
{
	for (int i = 0; i < 3; i++) {
		cout << "�̸��� ����, ����, ���� ������ �Է����ּ���: ";
		cin >> students[i].cName;
		cin >> students[i].iKor;
		cin >> students[i].iEng;
		cin >> students[i].iMath;
		students[i].iSum = students[i].iKor + students[i].iEng + students[i].iMath;
		students[i].fAver = students[i].iSum / 3.f;
	}
}

void PrintAllStudent(StudentInfo* students)
{
	for (int i = 0; i < 3; i++) {
		cout << "�̸�\t����\t����\t����\t����\t���" << endl;
		cout << students[i].cName << '\t' << students[i].iKor << '\t' << students[i].iEng << '\t' << students[i].iMath << '\t' << students[i].iSum << '\t' << students[i].fAver << endl;
	}
}

void ChooseStudent(StudentInfo* students)
{
	char cInputName[100];
	cout << "���ϴ� �л��� �̸��� �ۼ��ϼ���: ";
	cin >> cInputName;
	for (int i = 0; i < 3; ++i) {
		if (!(strcmp(students[i].cName, cInputName))) {
			cout << "�̸�\t����\t����\t����\t����\t���" << endl;
			cout << students[i].cName << '\t' << students[i].iKor << '\t' << students[i].iEng << '\t' << students[i].iMath << '\t' << students[i].iSum << '\t' << students[i].fAver << endl;
			break;
		}
	}

}

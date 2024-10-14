#include <iostream>
#include <string>
using namespace std;

//1. 성적표 만들기(구조체를 활용할 것)
//3명의 학생의 성적 입출력 프로그램을 만들기, 이름 국어 영어 수학 총점 평균 구해서 출력
//이름 검색해서 원하는 학생 정보 찾기 기능

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
		cout << "이름과 국어, 영어, 수학 점수를 입력해주세요: ";
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
		cout << "이름\t국어\t영어\t수학\t총점\t평균" << endl;
		cout << students[i].cName << '\t' << students[i].iKor << '\t' << students[i].iEng << '\t' << students[i].iMath << '\t' << students[i].iSum << '\t' << students[i].fAver << endl;
	}
}

void ChooseStudent(StudentInfo* students)
{
	char cInputName[100];
	cout << "원하는 학생의 이름을 작성하세요: ";
	cin >> cInputName;
	for (int i = 0; i < 3; ++i) {
		if (!(strcmp(students[i].cName, cInputName))) {
			cout << "이름\t국어\t영어\t수학\t총점\t평균" << endl;
			cout << students[i].cName << '\t' << students[i].iKor << '\t' << students[i].iEng << '\t' << students[i].iMath << '\t' << students[i].iSum << '\t' << students[i].fAver << endl;
			break;
		}
	}

}

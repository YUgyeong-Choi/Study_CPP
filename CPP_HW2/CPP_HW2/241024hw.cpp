#include <iostream>
#include <string>
using namespace std;

//성적 출력 with class 동적 배열
class Student {
private:
	char m_szName[32];
	int m_iKor;
	int m_iEng;
	int m_iMath;
	int m_iTotal;
	float m_fAver;
public:
	void Set_Name(char szName[32]) {
		strcpy_s(m_szName, sizeof(m_szName), szName);
	}
	void Set_Kor(int iKor) {
		m_iKor = iKor;
	}
	void Set_Eng(int iEng) {
		m_iEng = iEng;
	}
	void Set_Math(int iMath) {
		m_iMath = iMath;
	}
	void Set_Total() {
		m_iTotal = m_iKor + m_iEng + m_iMath;
	}
	void Set_Aver() {
		m_fAver = (float)m_iTotal / 3.f;
	}

	char* Get_Name() {
		return m_szName;
	}
	int Get_Kor() {
		return m_iKor;
	}
	int Get_Eng() {
		return m_iEng;
	}
	int Get_Math() {
		return m_iMath;
	}
	int Get_Total() {
		return m_iTotal;
	}
	float Get_Aver() {
		return m_fAver;
	}

};

void Add_Students(Student* tStudents, int* iCount);
void Render_Students(Student* tStudents, int* iCount);
void Search_Student(Student* tStudents, int* iCount);

int main() {
	Student* tStudents = new Student[100];
	void(*pProg[3])(Student*, int*) = { Add_Students ,Render_Students ,Search_Student };
	int iInput(0);
	int iCount(0);

	while (1) {
		cout << "1.입력 2.출력 3.검색 4.종료: ";
		cin >> iInput;

		if (0 >= iInput || 5 <= iInput) {
			cout << "잘못 입력하셨습니다" << endl;
			continue;
		}

		if (4 == iInput) {
			cout << "프로그램을 종료합니다" << endl;
			return 0;
		}
		else {
			pProg[iInput - 1](tStudents, &iCount);
		}
	}

	delete[] tStudents;
	tStudents = nullptr;

	return 0;
}

void Add_Students(Student* tStudents,int* iCount)
{
	int iInput(0);
	char szName[32] = {};
	int iScore(0);

	while (1) {
		cout << "몇 명을 입력받겠습니까?" << endl;
		cin >> iInput;
		if (0<iInput) {
			*iCount += iInput;
			break;
		}
	}

	for (int i = iInput; i > 0; --i) {
		cout << "이름 입력 : ";
		cin >> szName;
		tStudents[*iCount-i].Set_Name(szName);

		cout << "국어 입력 : ";
		cin >> iScore;
		tStudents[*iCount-i].Set_Kor(iScore);

		cout << "영어 입력 : ";
		cin >> iScore;
		tStudents[*iCount-i].Set_Eng(iScore);

		cout << "수학 입력 : ";
		cin >> iScore;
		tStudents[*iCount-i].Set_Math(iScore);

		tStudents[*iCount-i].Set_Total();
		tStudents[*iCount-i].Set_Aver();
		cout << "==============================" << endl;
	}
	
}

void Render_Students(Student* tStudents, int* iCount)
{
	for (int i = 0; i < *iCount; ++i) {
		cout << "이름\t국어\t영어\t수학\t총점\t평균" << endl;
		cout << tStudents[i].Get_Name() << '\t' << tStudents[i].Get_Kor() << '\t' << tStudents[i].Get_Eng() << '\t' << tStudents[i].Get_Math() << '\t' << tStudents[i].Get_Total() << '\t' << tStudents[i].Get_Aver() << endl;
	}
}

void Search_Student(Student* tStudents, int* iCount)
{
	char cInputName[100];
	cout << "원하는 학생의 이름을 작성하세요: ";
	cin >> cInputName;
	for (int i = 0; i < *iCount; ++i) {
		if (!(strcmp(tStudents[i].Get_Name(), cInputName))) {
			cout << "이름\t국어\t영어\t수학\t총점\t평균" << endl;
			cout << tStudents[i].Get_Name() << '\t' << tStudents[i].Get_Kor() << '\t' << tStudents[i].Get_Eng() << '\t' << tStudents[i].Get_Math() << '\t' << tStudents[i].Get_Total() << '\t' << tStudents[i].Get_Aver() << endl;
			break;
		}
	}
}

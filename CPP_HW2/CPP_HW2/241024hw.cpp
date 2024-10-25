#include <iostream>
#include <string>
using namespace std;

//���� ��� with class ���� �迭
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
		cout << "1.�Է� 2.��� 3.�˻� 4.����: ";
		cin >> iInput;

		if (0 >= iInput || 5 <= iInput) {
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
			continue;
		}

		if (4 == iInput) {
			cout << "���α׷��� �����մϴ�" << endl;
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
		cout << "�� ���� �Է¹ްڽ��ϱ�?" << endl;
		cin >> iInput;
		if (0<iInput) {
			*iCount += iInput;
			break;
		}
	}

	for (int i = iInput; i > 0; --i) {
		cout << "�̸� �Է� : ";
		cin >> szName;
		tStudents[*iCount-i].Set_Name(szName);

		cout << "���� �Է� : ";
		cin >> iScore;
		tStudents[*iCount-i].Set_Kor(iScore);

		cout << "���� �Է� : ";
		cin >> iScore;
		tStudents[*iCount-i].Set_Eng(iScore);

		cout << "���� �Է� : ";
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
		cout << "�̸�\t����\t����\t����\t����\t���" << endl;
		cout << tStudents[i].Get_Name() << '\t' << tStudents[i].Get_Kor() << '\t' << tStudents[i].Get_Eng() << '\t' << tStudents[i].Get_Math() << '\t' << tStudents[i].Get_Total() << '\t' << tStudents[i].Get_Aver() << endl;
	}
}

void Search_Student(Student* tStudents, int* iCount)
{
	char cInputName[100];
	cout << "���ϴ� �л��� �̸��� �ۼ��ϼ���: ";
	cin >> cInputName;
	for (int i = 0; i < *iCount; ++i) {
		if (!(strcmp(tStudents[i].Get_Name(), cInputName))) {
			cout << "�̸�\t����\t����\t����\t����\t���" << endl;
			cout << tStudents[i].Get_Name() << '\t' << tStudents[i].Get_Kor() << '\t' << tStudents[i].Get_Eng() << '\t' << tStudents[i].Get_Math() << '\t' << tStudents[i].Get_Total() << '\t' << tStudents[i].Get_Aver() << endl;
			break;
		}
	}
}

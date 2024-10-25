#include "Student.h"
#include "pch.h"

Student::Student() {
	m_tStudent = nullptr;
	m_iSize = 0;
}

Student::~Student() {
	Release();
}

void Student::Release()
{
	SAFE_DELETE_ARRAY(m_tStudent);
}

void Student::Input_Data()
{
	int iAdd(0);
	cout << "추가할 인원을 입력하세요: ";
	cin >> iAdd;

	if (!m_tStudent) {
		m_tStudent = new INFO[iAdd];
	}
	else {
		INFO* temp = new INFO[m_iSize+iAdd];
		memcpy(temp, m_tStudent, sizeof(INFO)*m_iSize);
		Release();
		m_tStudent = temp;
	}

	for (int i = m_iSize; i < m_iSize + iAdd; ++i) {
		cout << "이름을 입력하세요: ";
		cin >> m_tStudent[i].szName;
		cout << "국어점수를 입력하세요: ";
		cin >> m_tStudent[i].iKor;
		cout << "영어점수를 입력하세요: ";
		cin >> m_tStudent[i].iEng;
		cout << "수학점수를 입력하세요: ";
		cin >> m_tStudent[i].iMath;
		m_tStudent[i].iTotal = m_tStudent[i].iKor + m_tStudent[i].iEng + m_tStudent[i].iEng;
		m_tStudent[i].fAver = (float)m_tStudent[i].iTotal / 3.f;
	}

	m_iSize += iAdd;
}

void Student::Output_Data()
{
	for (int i = 0; i < m_iSize; ++i) {
		cout << "이름:\t국어:\t영어:\t수학:\t총점:\t평균:\t" << endl;
		cout << m_tStudent[i].szName << '\t' << m_tStudent[i].iKor << '\t' << m_tStudent[i].iEng << '\t' << m_tStudent[i].iMath << '\t' << m_tStudent[i].iTotal << '\t' << m_tStudent[i].fAver << endl;
	}
	system("pause");
}

void Student::Search_Data()
{
	char inputName[32];
	cout << "검색할 이름을 입력하세요: ";
	cin >> inputName;
	for (int i = 0; i < m_iSize; ++i) {
		if (!strcmp(inputName, m_tStudent[i].szName)) {
			cout << "이름:\t국어:\t영어:\t수학:\t총점:\t평균:\t" << endl;
			cout << m_tStudent[i].szName << '\t' << m_tStudent[i].iKor << '\t' << m_tStudent[i].iEng << '\t' << m_tStudent[i].iMath << '\t' << m_tStudent[i].iTotal << '\t' << m_tStudent[i].fAver << endl;
		}
	}
	system("pause");
}

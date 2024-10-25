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
	cout << "�߰��� �ο��� �Է��ϼ���: ";
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
		cout << "�̸��� �Է��ϼ���: ";
		cin >> m_tStudent[i].szName;
		cout << "���������� �Է��ϼ���: ";
		cin >> m_tStudent[i].iKor;
		cout << "���������� �Է��ϼ���: ";
		cin >> m_tStudent[i].iEng;
		cout << "���������� �Է��ϼ���: ";
		cin >> m_tStudent[i].iMath;
		m_tStudent[i].iTotal = m_tStudent[i].iKor + m_tStudent[i].iEng + m_tStudent[i].iEng;
		m_tStudent[i].fAver = (float)m_tStudent[i].iTotal / 3.f;
	}

	m_iSize += iAdd;
}

void Student::Output_Data()
{
	for (int i = 0; i < m_iSize; ++i) {
		cout << "�̸�:\t����:\t����:\t����:\t����:\t���:\t" << endl;
		cout << m_tStudent[i].szName << '\t' << m_tStudent[i].iKor << '\t' << m_tStudent[i].iEng << '\t' << m_tStudent[i].iMath << '\t' << m_tStudent[i].iTotal << '\t' << m_tStudent[i].fAver << endl;
	}
	system("pause");
}

void Student::Search_Data()
{
	char inputName[32];
	cout << "�˻��� �̸��� �Է��ϼ���: ";
	cin >> inputName;
	for (int i = 0; i < m_iSize; ++i) {
		if (!strcmp(inputName, m_tStudent[i].szName)) {
			cout << "�̸�:\t����:\t����:\t����:\t����:\t���:\t" << endl;
			cout << m_tStudent[i].szName << '\t' << m_tStudent[i].iKor << '\t' << m_tStudent[i].iEng << '\t' << m_tStudent[i].iMath << '\t' << m_tStudent[i].iTotal << '\t' << m_tStudent[i].fAver << endl;
		}
	}
	system("pause");
}

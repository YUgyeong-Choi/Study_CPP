#include "MyString.h"
#include "pch.h"
MyString::MyString() : m_myStr(nullptr), m_size(0){}

MyString::MyString(const char* data) {
	m_size = strlen(data);
	m_myStr = new char[m_size + 1];
	strcpy_s(m_myStr, m_size + 1, data);
}

MyString::MyString(MyString& data) {
	m_size = strlen(data.m_myStr);
	m_myStr = new char[m_size + 1];
	strcpy_s(m_myStr, m_size + 1, data.m_myStr);
}
MyString::~MyString() {
	Release();
}
const char* MyString::Get_String()
{
	if (m_myStr != nullptr) {
		return m_myStr;
	}
	return "";
}
void MyString::Release() {
	SAFE_DELETE_ARRAY<char*>(m_myStr);
}

MyString& MyString::operator = (const char* data) {
	Release();
	m_size = strlen(data);
	m_myStr = new char[m_size + 1];
	strcpy_s(m_myStr, m_size + 1, data);
}
MyString& MyString::operator = (MyString& data){
	Release();
	m_size = strlen(data.m_myStr);
	m_myStr = new char[m_size + 1];
	strcpy_s(m_myStr, m_size + 1, data.m_myStr);
}

MyString& MyString::operator=(MyString&& data)
{
	Release();
	m_size = strlen(data.m_myStr);
	m_myStr = new char[m_size + 1];
	strcpy_s(m_myStr, m_size + 1, data.m_myStr);
	return *this;
}

MyString MyString::operator + (const char* data){
	m_size = m_size + strlen(data);
	char* tempStr = new char[m_size + 1];
	strcpy_s(tempStr, m_size + 1, m_myStr);
	strcat_s(tempStr, m_size + 1, data);

	MyString temp(tempStr);
	SAFE_DELETE_ARRAY<char*>(tempStr);
	return temp;
}

MyString MyString::operator + (MyString& data){
	m_size = m_size + strlen(data.m_myStr);
	char* tempStr = new char[m_size + 1];
	strcpy_s(tempStr, m_size + 1, m_myStr);
	strcat_s(tempStr, m_size + 1, data.m_myStr);

	MyString temp(tempStr);
	SAFE_DELETE_ARRAY<char*>(tempStr);
	return temp;
}

bool MyString::operator ==(const char* data){
	return !strcmp(m_myStr, data);
}

bool MyString::operator == (MyString & data) {
	return !strcmp(m_myStr, data.m_myStr);
}
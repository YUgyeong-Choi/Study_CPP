#include "pch.h"
#include <string>


class MyString {
public:
	MyString() { memset(szName, 0, sizeof(szName)); }
	~MyString(){}
public:
	MyString& operator =(const char* data) {
		int i = 0;
		while (data[i] != '\0' && i < sizeof(szName) - 1) {
			szName[i] = data[i];
			++i;
		}
		szName[i] = '\0'; 
		return *this;
	}

	MyString operator +(const char* data) {
		MyString newString;

		int i = 0;
		while (szName[i] != '\0' && i < sizeof(newString.szName) - 1) {
			newString.szName[i] = szName[i];
			++i;
		}

		int j = 0;
		while (data[j] != '\0' && i < sizeof(newString.szName) - 1) {
			newString.szName[i] = data[j];
			++i;
			++j;
		}

		newString.szName[i] = '\0';

		return newString;
	}

	bool operator ==(const char* data) {
		int i = 0;
		while (szName[i] != '\0') ++i;
		int j = 0;
		while (data[j] != '\0') ++j;
		
		if (i != j) return false; //���̰� ���� ������ ��ȯ

		int k = 0;
		while (szName[k] != '\0') {
			if (szName[k] != data[k]) return false;
			++k;
		}
		return true;
	}

	bool operator ==(const MyString& data) {
		int i = 0;
		while (szName[i] != '\0') ++i;
		int j = 0;
		while (data.szName[j] != '\0') ++j;

		if (i != j) return false; //���̰� ���� ������ ��ȯ

		int k = 0;
		while (szName[k] != '\0') {
			if (szName[k] != data.szName[k]) return false;
			++k;
		}
		return true;
	}

public:
	void Render() {
		for (int i = 0; i < sizeof(szName) - 1; ++i) { 
			if (szName[i] == '\0') {
				break;  
			}
			cout << szName[i];
		}
		cout << endl;
	}
	
private:
	char szName[32];
};


int main() {
	MyString str1;
	str1 = "aaa";
	str1.Render();
	
	MyString str2;
	str2 = str1 + "bbb";
	str2.Render();

	if (str1 == "aaa") {
		cout << "�����ϴ�" << endl;
	}
	else {
		cout << "�ٸ��ϴ�" << endl;
	}

	if (str1 == str2) {
		cout << "�����ϴ�" << endl;
	}
	else {
		cout << "�ٸ��ϴ�" << endl;
	}
	return 0;
}
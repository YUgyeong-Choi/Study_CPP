#include "pch.h"
#include "MyString.h"

int main() {
	MyString test1("aaa");
	MyString test2("bbb");

	if (test1 == test2)
		cout << "��ġ��" << endl;

	else
		cout << "����ġ" << endl;

	test1 = test1 + test2;
	if (test1 == "aaabbb")
		cout << "��ġ��" << endl;
	else
		cout << "����ġ" << endl;



	return 0;
}
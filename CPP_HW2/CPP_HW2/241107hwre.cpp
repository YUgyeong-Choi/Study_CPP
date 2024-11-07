#include "pch.h"
#include "MyString.h"

int main() {
	MyString test1("aaa");
	MyString test2("bbb");

	if (test1 == test2)
		cout << "일치함" << endl;

	else
		cout << "불일치" << endl;

	test1 = test1 + test2;
	if (test1 == "aaabbb")
		cout << "일치함" << endl;
	else
		cout << "불일치" << endl;



	return 0;
}
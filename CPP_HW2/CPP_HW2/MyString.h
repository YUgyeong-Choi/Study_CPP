#pragma once
class MyString {
public:
	MyString();
	MyString(const char* data);
	MyString(MyString& data);
	~MyString();
public:
	void Release();
	const char* Get_String();

	MyString& operator = (const char* data);
	MyString& operator = (MyString& data);
	MyString& operator = (MyString&& data); // test1 = test1 + test2가 안되는 경우

	MyString operator + (const char* data);
	MyString operator + (MyString & data);

	bool operator ==(const char* data);
	bool operator == (MyString & data);

private:
	char* m_myStr;
	int m_size;

};

template<typename T>
void SAFE_DELETE_ARRAY(T& p) {
	if (p) {
		delete[] p;
		p = nullptr;
	}
}
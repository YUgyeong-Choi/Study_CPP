#include "pch.h"

// this 포인터 : 생성된 객체의 주소를 가리키는 포인터

class CObj
{
private:
	CObj() : m_iA(500) { cout << "생성자 호출" << endl; }
	~CObj() { cout << "소멸자 호출" << endl; }

public:
	CObj* Clone()
	{
		return new CObj(*this);
	}

	void	Destroy()
	{
		cout << "destory 호출" << endl;
		delete this;
	}

	static CObj* Create()
	{
		CObj* pInstance = new CObj;
		return pInstance;
	}

private:
	int		m_iA;
};

int main()
{
	CObj* pObj = CObj::Create();
	cout << &pObj << endl;
	CObj* pObj2 = pObj->Clone(); //얕은 복사
	cout << &pObj2 << endl;
	pObj->Destroy();

	return 0;
}
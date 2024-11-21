#include "pch.h"

// this ������ : ������ ��ü�� �ּҸ� ����Ű�� ������

class CObj
{
private:
	CObj() : m_iA(500) { cout << "������ ȣ��" << endl; }
	~CObj() { cout << "�Ҹ��� ȣ��" << endl; }

public:
	CObj* Clone()
	{
		return new CObj(*this);
	}

	void	Destroy()
	{
		cout << "destory ȣ��" << endl;
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
	CObj* pObj2 = pObj->Clone(); //���� ����
	cout << &pObj2 << endl;
	pObj->Destroy();

	return 0;
}
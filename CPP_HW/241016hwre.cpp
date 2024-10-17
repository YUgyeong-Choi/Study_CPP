#include <iostream>
#include <string>
using namespace std;

typedef struct taginfo {
	char szName[32];
	int iHealth;
	int iAttack;
}INFO;

INFO* Select_Job();
void Create_Obj(INFO** ppInfo, const char* pName, int _iAttack, int _iHp);

//�򰥸��� �κи� ����
int main() {
	INFO* pPlayer = Select_Job();

	if (nullptr != pPlayer)
	{
		delete pPlayer;
		pPlayer = nullptr;
	}
	return 0;
}

INFO* Select_Job()
{
	INFO* pTemp(nullptr);
	//pTemp�� �ּҰ� a�� ���� nullptr
	Create_Obj(&pTemp, "������", 10, 100);

	return pTemp;
}


void Create_Obj(INFO** ppInfo, const char* pName, int _iAttack, int _iHp)
{
	//ppInfo�� pTemp�� �ּ�, �׷� *ppInfo�� pTemp�� ��
	(*ppInfo) = new INFO; //new INFO�� �ϸ� ������ A��� �޸𸮸� �Ҵ� ����
	//pTemp�� �ּҴ� a, ���� A(�����޸��ּ�)�� ��

	strcpy_s((*ppInfo)->szName, sizeof((*ppInfo)->szName), pName);
	(*ppInfo)->iAttack = _iAttack;
	(*ppInfo)->iHealth = _iHp;
}
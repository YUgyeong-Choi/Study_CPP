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

//헷갈리는 부분만 복습
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
	//pTemp의 주소가 a고 값은 nullptr
	Create_Obj(&pTemp, "마법사", 10, 100);

	return pTemp;
}


void Create_Obj(INFO** ppInfo, const char* pName, int _iAttack, int _iHp)
{
	//ppInfo는 pTemp의 주소, 그럼 *ppInfo는 pTemp의 값
	(*ppInfo) = new INFO; //new INFO를 하면 힙에서 A라는 메모리를 할당 받음
	//pTemp의 주소는 a, 값은 A(동적메모리주소)가 됨

	strcpy_s((*ppInfo)->szName, sizeof((*ppInfo)->szName), pName);
	(*ppInfo)->iAttack = _iAttack;
	(*ppInfo)->iHealth = _iHp;
}
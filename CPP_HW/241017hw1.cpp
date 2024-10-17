//���� �����
#include <iostream>
#include <string>
using namespace std;

#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif
#endif

#define MIN_STR 32
#define SAFE_DELETE(p) if(p) {delete p; p=nullptr;}

typedef struct taginfo {
	char szName[MIN_STR];
	int iHp;
	int iAttack;
}INFO;

enum JOB
{
	WARRIOR=1, MAGE, THIEF, END
};

void Select_Start(INFO** pPlayer);
INFO* Get_Data();
void Save_Data(INFO* pPlayer);
INFO* Select_Job();
void Create_Obj(INFO** ppInfo, const char* szName, int _iHp, int _iAttack);
void Main_Game(INFO* pPlayer);
void Render(INFO* pInfo);
void Field(INFO* pPlayer);
int Fight(INFO* pPlayer, INFO* pMonster);

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	INFO* pPlayer(nullptr);
	Select_Start(&pPlayer);

	if (nullptr == pPlayer)
	{
		cout << "�÷��̾� �Ҵ� �ȵ�" << endl;
		return 0;
	}

	Main_Game(pPlayer);

	if (nullptr != pPlayer) SAFE_DELETE(pPlayer);
	

	return 0;
}

INFO* Select_Job() {
	INFO* pTemp(nullptr);
	int _iInput(0);
	bool _bSelect = false;
	while (!_bSelect) {
		system("cls");
		cout << "������ �����ϼ��� (1.���� 2.������ 3.���� 4.������)";
		cin >> _iInput;
		switch (_iInput) {
		case WARRIOR:
			Create_Obj(&pTemp, "����", 100, 10);
			_bSelect = true;
			break;
		case MAGE:
			Create_Obj(&pTemp, "������", 100, 10);
			_bSelect = true;
			break;
		case THIEF:
			Create_Obj(&pTemp, "����", 100, 10);
			_bSelect = true;
			break;
		case END:
			cout << "������ �����մϴ�" << endl;
			_bSelect = true;
			break;
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
			continue;
		}
	}
	return pTemp;
}

void Create_Obj(INFO** ppInfo, const char* szName, int _iHp, int _iAttack) {
	(*ppInfo) = new INFO;

	strcpy_s((*ppInfo)->szName, sizeof((*ppInfo)->szName), szName);
	(*ppInfo)->iHp = _iHp;
	(*ppInfo)->iAttack = _iAttack;
}

void Select_Start(INFO** pPlayer)
{
	INFO* pTemp;
	int _iInput(0);
	while (1) {
		cout << "1. ���� �ҷ�����" << endl;
		cout << "2. ó������ �ϱ�" << endl;
		cin >> _iInput;

		switch (_iInput)
		{
		case 1:
			pTemp = Get_Data();
			if (pTemp != nullptr) {
				*pPlayer = pTemp;
			}
			else {
				continue;
			}
			return;
		case 2:
			*pPlayer = Select_Job();
			return;
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
			continue;
		}
	}
}

INFO* Get_Data()
{
	INFO* temp = new INFO;
	INFO* pTemp;
	pTemp = temp;
	int count(0);
	char szInput[32]="";
	char oneChar;
	FILE* pFile = NULL;
	errno_t err = fopen_s(&pFile, "../Data/Player.text", "rt");
	if (0 == err) {
		while ((oneChar = fgetc(pFile)) != EOF) {
			if (oneChar == '\n') {
				switch (count)
				{
				case 0:
					strcpy_s(pTemp->szName, sizeof(pTemp->szName), szInput);
					strcpy_s(szInput, sizeof(szInput), "");
					count++;
					break;
				case 1:
					pTemp->iHp = stoi(szInput);
					strcpy_s(szInput, sizeof(szInput), "");
					count++;
					break;
				case 2:
					pTemp->iAttack = stoi(szInput);
					strcpy_s(szInput, sizeof(szInput), "");
					count++;
					break;
				default:
					cout << "�׷����� wpqkf" << endl;
					break;
				}
			}
			else {
				char tempStr[2] = { oneChar, '\0' };
				strcat_s(szInput, sizeof(szInput), tempStr);

			}
		}
		fclose(pFile);
		return pTemp;
	}
	else {
		cout << "����� ������ �����ϴ�" << endl;
		return nullptr;
	}
}

void Save_Data(INFO* pPlayer)
{
	FILE* pFile = NULL;
	errno_t err = fopen_s(&pFile, "../Data/Player.text", "wt");
	if (0 == err) {
		fputs(pPlayer->szName, pFile);
		fputc('\n', pFile);
		fputs(to_string(pPlayer->iHp).c_str(), pFile);
		fputc('\n', pFile);
		fputs(to_string(pPlayer->iAttack).c_str(), pFile);
		fputc('\n', pFile);

		cout << "���� ����" << endl;
		fclose(pFile);
	}
	else {
		cout << "���� ���� ����" << endl;
	}
}

void Main_Game(INFO* pPlayer) {
	int _iInput(0);
	while (1) {
		system("cls");
		Render(pPlayer);
		cout << "1.�����\t2.����" << endl;
		cin >> _iInput;
		switch (_iInput)
		{
		case 1:
			Field(pPlayer);
			break;
		case 2:
			Save_Data(pPlayer);
			return;
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
			continue;
		}
	}
}
void Render(INFO* pInfo) {
	cout << "====================" << endl;
	cout << "�̸�: " << pInfo->szName << endl;
	cout << "ü��: " << pInfo->iHp << "\t���ݷ�: " << pInfo->iAttack << endl;
}

void Field(INFO* pPlayer) {
	int _iInput(0);
	INFO* pMonster(nullptr);

	while (1) {
		system("cls");
		Render(pPlayer);
		cout << "1.�ʱ� 2.�߱� 3.��� 4.���ܰ�: ";
		cin >> _iInput;
		switch (_iInput)
		{
		case 1:
			Create_Obj(&pMonster, "�ʱ�", 30, 3);
			break;
		case 2:
			Create_Obj(&pMonster, "�߱�", 60, 6);
			break;
		case 3:
			Create_Obj(&pMonster, "���", 90, 9);
			break;
		case 4:
			return;
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
			continue;
		}

		if (Fight(pPlayer, pMonster)) {
			pPlayer->iHp = 100;
		}

		if (pMonster != nullptr) SAFE_DELETE(pMonster);
	}

}

int Fight(INFO* pPlayer, INFO* pMonster) {
	int _iInput(0);
	while (1) {
		system("cls");
		Render(pPlayer);
		Render(pMonster);
		cout << "1.���� 2.����: ";
		cin >> _iInput;
		switch (_iInput)
		{
		case 1:
			pPlayer->iHp -= pMonster->iAttack;
			pMonster->iHp -= pPlayer->iAttack;
			break;
		case 2:
			return 0;
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
			continue;
		}

		if (0 >= pPlayer->iHp) {
			cout << "�÷��̾� �й�" << endl;
			system("pause");
			return 1;
		}

		if (0 >= pMonster->iHp) {
			cout << "�÷��̾� �¸�" << endl;
			system("pause");
			return 0;
		}
	}
}
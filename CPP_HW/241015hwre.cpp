#include <iostream>
#include <string>
using namespace std;

typedef struct taginfo {
	char szName[32];
	int iHealth;
	int iAttack;
}INFO;

enum JOB
{
	WARRIOR=1, MAGE, THIEF
};

INFO Select_Job();
void Render(INFO* pInfo);
void Field(INFO* pPlayer);
void Create_Monster(INFO* pMonster);
void Fight(INFO* pPlayer, INFO* pMonster);

int main() {
	INFO tPlayer = {};

	tPlayer = Select_Job();
	while (1) {
		system("cls");
		Render(&tPlayer);
		int _iInput(0);
		while (1) {
			cout << "1.����� 2.����: ";
			cin >> _iInput;
			if (_iInput == 1 || _iInput == 2) break;
		}

		if (_iInput == 1) {
			Field(&tPlayer);
		}
		else if(_iInput == 2){
			return 0;
		}

	}

	return 0;
}

INFO Select_Job() {
	int _iInput(0);
	INFO temp = {};
	
	while (1) {
		system("cls");
		cout << "������ �����ϼ��� (1.���� 2.������ 3.����): ";
		cin >> _iInput;
		if (1 <= _iInput && 3 >= _iInput) {
			break;
		}
	}
	
	switch (_iInput)
	{
	case WARRIOR:
		strcpy_s(temp.szName, sizeof(temp.szName), "����");
		temp.iHealth = 100;
		temp.iAttack = 10;
		break;
	case MAGE:
		strcpy_s(temp.szName, sizeof(temp.szName), "������");
		temp.iHealth = 100;
		temp.iAttack = 10;
		break;
	case THIEF:
		strcpy_s(temp.szName, sizeof(temp.szName), "����");
		temp.iHealth = 100;
		temp.iAttack = 10;
		break;
	default:
		break;
	}

	return temp;
}


void Render(INFO* pInfo) {
	cout << "=========================" << endl;
	cout << "����: " << pInfo->szName << endl;
	cout << "ü��: " << pInfo->iHealth << "\t���ݷ�: " << pInfo->iAttack << endl;
}

void Field(INFO* pPlayer) {
	int _iInput(0);
	INFO     tMonster[3] = {};

	while (1) {
		system("cls");
		Render(pPlayer);
		while (1) {
			cout << "1.�ʱ� 2.�߱� 3.��� 4.���ܰ�: ";
			cin >> _iInput;
			if (1 <= _iInput && 4 >= _iInput) {
				break;
			}
		}

		if (_iInput == 4) {
			return;
		}
		else {
			Create_Monster(tMonster);
			Fight(pPlayer, &tMonster[_iInput - 1]);
		}
	}
}

void Create_Monster(INFO* pMonster) {
	strcpy_s(pMonster[0].szName, sizeof(pMonster[0].szName), "�ʱ�");
	strcpy_s(pMonster[1].szName, sizeof(pMonster[1].szName), "�߱�");
	strcpy_s(pMonster[2].szName, sizeof(pMonster[2].szName), "���");

	for (int i = 0; i < 3; ++i) {
		pMonster[i].iHealth = (i + 1) * 30;
		pMonster[i].iAttack = (i + 1) * 3;
	}
}

void Fight(INFO* pPlayer, INFO* pMonster) {
	int _iInput(0);

	while (1) {
		system("cls");
		Render(pPlayer);
		Render(pMonster);
		while (1) {
			cout << "1.���� 2.����: ";
			cin >> _iInput;
			if (_iInput == 1 || _iInput == 2) break;
		}

		if (_iInput == 1) {
			pPlayer->iHealth -= pMonster->iAttack;
			pMonster->iHealth -= pPlayer->iAttack;
		}
		else {
			return;
		}

		if (0 >= pPlayer->iHealth) {
			cout << "�÷��̾� ���" << endl;
			pPlayer->iHealth = 100;
			system("pause");
			return;
		}
		else if (0 >= pMonster->iHealth) {
			cout << "�÷��̾� �¸�" << endl;
			system("pause");
			return;
		}
	}
}
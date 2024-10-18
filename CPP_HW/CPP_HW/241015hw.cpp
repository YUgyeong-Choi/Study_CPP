#include <iostream>
#include <string>
using namespace std;

typedef struct tagInfo {
	char szName[32];
	int iHealth;
	int iAttack;

}INFO;

INFO Choose_Job();
void Output_Data(INFO _job);

int main() {
	INFO myJob = Choose_Job();
	INFO monsters[3] = { "�ʱ�", 30, 3, "�߱�", 60, 6, "���", 90, 9 };
	INFO pvpMonster;
	int _iStage(0);
	int _iDifficult(0);

	while (1) {
		system("cls");
		Output_Data(myJob);

		if (_iStage == 0) {
			int _iInput(0);
			cout << "1.����� 2.����: ";
			cin >> _iInput;
			if (_iInput == 2) {
				break;
			}
			_iStage++;
		}
		else if(_iStage == 1){
			cout << "1.�ʱ� 2.�߱� 3.��� 4.���ܰ�" << endl;
			cin >> _iDifficult;
			if (_iDifficult == 4) {
				_iStage--;
				continue;
			}
			pvpMonster = monsters[_iDifficult - 1];
			_iStage++;
		}else if(_iStage == 2){
			int _iInput(0);
			Output_Data(pvpMonster);
			cout << "1.���� 2.����";
			cin >> _iInput;

			if (_iInput == 1) {
				myJob.iHealth -= pvpMonster.iAttack;
				pvpMonster.iHealth -= myJob.iAttack;
			}
			else if (_iInput == 2) {
				_iStage--;
			}

			if (myJob.iHealth <= 0) {
				cout << "�÷��̾� ���"<<endl;
				myJob.iHealth = 100;
				_iStage--;
			}
			if (pvpMonster.iHealth <= 0) {
				cout << "�¸�"<<endl;
				_iStage--;
			}
		}
	
		system("pause");
	}
	return 0;
}

INFO Choose_Job()
{
	INFO Jobs[3] = { "����", 100, 10, "������", 100, 10 , "����", 100, 10 };
	int _iInput(0);
	cout << "������ �����ϼ��� (1.���� 2.������ 3.����)";
	cin >> _iInput;

	return Jobs[_iInput-1];
}

void Output_Data(INFO _job)
{
	cout << "=========================" << endl;
	cout << "����: " << _job.szName << endl;
	cout << "ü��: " << _job.iHealth << '\t' << "���ݷ�: " << _job.iAttack << endl;
}

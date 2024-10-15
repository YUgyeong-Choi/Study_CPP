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
	INFO monsters[3] = { "초급", 30, 3, "중급", 60, 6, "고급", 90, 9 };
	INFO pvpMonster;
	int _iStage(0);
	int _iDifficult(0);

	while (1) {
		system("cls");
		Output_Data(myJob);

		if (_iStage == 0) {
			int _iInput(0);
			cout << "1.사냥터 2.종료: ";
			cin >> _iInput;
			if (_iInput == 2) {
				break;
			}
			_iStage++;
		}
		else if(_iStage == 1){
			cout << "1.초급 2.중급 3.고급 4.전단계" << endl;
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
			cout << "1.공격 2.도망";
			cin >> _iInput;

			if (_iInput == 1) {
				myJob.iHealth -= pvpMonster.iAttack;
				pvpMonster.iHealth -= myJob.iAttack;
			}
			else if (_iInput == 2) {
				_iStage--;
			}

			if (myJob.iHealth <= 0) {
				cout << "플레이어 사망"<<endl;
				myJob.iHealth = 100;
				_iStage--;
			}
			if (pvpMonster.iHealth <= 0) {
				cout << "승리"<<endl;
				_iStage--;
			}
		}
	
		system("pause");
	}
	return 0;
}

INFO Choose_Job()
{
	INFO Jobs[3] = { "전사", 100, 10, "마법사", 100, 10 , "도적", 100, 10 };
	int _iInput(0);
	cout << "직업을 선택하세요 (1.전사 2.마법사 3.도적)";
	cin >> _iInput;

	return Jobs[_iInput-1];
}

void Output_Data(INFO _job)
{
	cout << "=========================" << endl;
	cout << "직업: " << _job.szName << endl;
	cout << "체력: " << _job.iHealth << '\t' << "공격력: " << _job.iAttack << endl;
}

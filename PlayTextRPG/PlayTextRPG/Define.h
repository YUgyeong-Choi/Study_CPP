#pragma once
#define SAFE_DELETE(p) if(p) { delete p; p = nullptr;}
#define SAFE_DELETE_ARRAY(p) if(p) { delete [] p; p = nullptr;}

typedef struct tagInfo {
	char szName[32]="";
	char Job[32]="";
	int iHp=0, iAttack=0, iMoney=0, Stage=0;
}PlayerInfo;

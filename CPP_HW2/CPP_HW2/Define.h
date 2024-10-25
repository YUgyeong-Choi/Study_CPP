#pragma once

#define SAFE_DELETE(p) if(p) { delete p; p = nullptr;}
#define SAFE_DELETE_ARRAY(p) if(p) { delete [] p; p = nullptr;}

typedef struct tagInfo {
	char szName[32];
	int iKor, iEng, iMath, iTotal;
	float fAver;
}INFO;
#pragma once

#define SAFE_DELETE(p) if(p) { delete p; p = nullptr;}
#define SAFE_DELETE_ARRAY(p) if(p) { delete [] p; p = nullptr;}

typedef struct tagInfo {
	char m_SzName[32];
	int m_iHp;
	int m_iAttack;
}INFO;

#pragma once
#include "Define.h"
#include "Inventory.h"

class Player {
public:
	Player();
	virtual ~Player();
public:
	void Render();
	void Render_Detail();
	void Render_Inventory() { m_playerInventory->Render(); }
	void Fight_Inventory();
	PlayerInfo Get_Info() { return m_playerInfo; }
	void Set_Player_Name(const char* szName);
	void Set_UpgradeHp();
	void Set_Hp(int _iAttack) { m_playerInfo.iHp -= _iAttack; }
	void Set_FullHp() {m_playerInfo.iHp = iOriginHp; }
	void Set_InitAttack() { m_playerInfo.iAttack = iUpgradeAttack; }
	void Set_Stage() { m_playerInfo.Stage++; }
	void Set_Attack(int _add);
	void Add_PlayerMoney(int _iMoney) { m_playerInfo.iMoney += _iMoney; }
	void Add_Items(int _iIndex) { m_playerInventory->Add_Items(_iIndex); }
	virtual void Skill1();
	virtual int Skill2();
protected:
	PlayerInfo 	m_playerInfo;
	Inventory* m_playerInventory;
	int iOriginHp;
	int iOriginAttack;
	int iUpgradeAttack;
};
#pragma once
#include "Define.h"
#include "Inventory.h"
#include "Weapon.h"
#include "Armor.h"

class Player {
public:
	Player();
	virtual ~Player();
public:
	void Set_Player_Name(const string& _StrName); //플레이어 이름 설정
	void Render();
	void Release(); 
	
	PlayerInfo Get_PlayerInfo() { return m_PlayerInfo; } //플레이어 정보 리턴
	
	//던전 관련 함수
	void Set_Hp(int _iAttack) { m_PlayerInfo.iHp += _iAttack; } //Hp 설정
	void Set_FullHp() { m_PlayerInfo.iHp = iMaxHp; } //Hp 설정
	void Set_Stage() { m_PlayerInfo.Stage++; }
	void Set_InitAttack(int _iAttack) { m_PlayerInfo.iAttack = _iAttack; }
	virtual void Skill1() PURE;
	virtual int Skill2() PURE;


	// 인벤토리 아이템 관련
	void Init_Inven(); //인벤토리 초기화
	Inventory* Get_InvenInfo() { return m_Inven; } //인벤토리 깊은 복사
	void usePotion(int healAmount);
	void equip(Item* equipItem);
	void unequip(string type);

	//돈
	void Add_PlayerMoney(int _money) { m_PlayerInfo.iMoney += _money; }
protected:
	PlayerInfo m_PlayerInfo;
	Inventory* m_Inven;
	Weapon* WeaponItem;
	Armor* ArmorItem;
	int iMaxHp;
};
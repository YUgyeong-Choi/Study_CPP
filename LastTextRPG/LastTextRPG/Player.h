#pragma once
#include "Define.h"
#include "Potion.h"
#include "Inventory.h"
#include "Weapon.h"
#include "Armor.h"

class Player {
public:
	Player();
	virtual ~Player();
public:
	void Set_Player_Name(const string& _StrName); //플레이어 이름 설정
	void Init_Inven(); //인벤토리 초기화
	void Release(); //소멸
	void Add_PlayerMoney(int _money) { m_PlayerInfo.iMoney += _money; }

	PlayerInfo Get_PlayerInfo() { return m_PlayerInfo; } //플레이어 정보 리턴
	virtual void Skill1() PURE;
	virtual int Skill2() PURE;

	// 인벤토리 아이템 관련
	Inventory* Get_InvenInfo() { return m_Inven; } //인벤토리 깊은 복사
	void usePotion(Potion* potion);
	void equip(Equipment* equipItem);
	void unequip();
protected:
	PlayerInfo m_PlayerInfo;
	Inventory* m_Inven;
	Weapon* WeaponItem;
	Armor* ArmorItem;
	int iMaxHp;
};
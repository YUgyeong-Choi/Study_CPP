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
	void Set_Player_Name(const string& _StrName); //�÷��̾� �̸� ����
	void Init_Inven(); //�κ��丮 �ʱ�ȭ
	void Release(); //�Ҹ�
	void Add_PlayerMoney(int _money) { m_PlayerInfo.iMoney += _money; }

	PlayerInfo Get_PlayerInfo() { return m_PlayerInfo; } //�÷��̾� ���� ����
	virtual void Skill1() PURE;
	virtual int Skill2() PURE;

	// �κ��丮 ������ ����
	Inventory* Get_InvenInfo() { return m_Inven; } //�κ��丮 ���� ����
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
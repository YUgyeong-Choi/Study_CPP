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
	void Set_Player_Name(const string& _StrName); //�÷��̾� �̸� ����
	void Render();
	void Release(); 
	
	PlayerInfo Get_PlayerInfo() { return m_PlayerInfo; } //�÷��̾� ���� ����
	
	//���� ���� �Լ�
	void Set_Hp(int _iAttack) { m_PlayerInfo.iHp += _iAttack; } //Hp ����
	void Set_FullHp() { m_PlayerInfo.iHp = iMaxHp; } //Hp ����
	void Set_Stage() { m_PlayerInfo.Stage++; }
	void Set_InitAttack(int _iAttack) { m_PlayerInfo.iAttack = _iAttack; }
	virtual void Skill1() PURE;
	virtual int Skill2() PURE;


	// �κ��丮 ������ ����
	void Init_Inven(); //�κ��丮 �ʱ�ȭ
	Inventory* Get_InvenInfo() { return m_Inven; } //�κ��丮 ���� ����
	void usePotion(int healAmount);
	void equip(Item* equipItem);
	void unequip(string type);

	//��
	void Add_PlayerMoney(int _money) { m_PlayerInfo.iMoney += _money; }
protected:
	PlayerInfo m_PlayerInfo;
	Inventory* m_Inven;
	Weapon* WeaponItem;
	Armor* ArmorItem;
	int iMaxHp;
};
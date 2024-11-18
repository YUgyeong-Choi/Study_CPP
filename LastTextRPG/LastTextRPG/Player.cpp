#include "Player.h"
#include "pch.h"

Player::Player()
{
	m_PlayerInfo.strName = "";
	m_PlayerInfo.iMoney = 3000;
	m_PlayerInfo.Stage = 0;
	m_Inven = nullptr;
	WeaponItem = nullptr;
	ArmorItem = nullptr;
}

Player::~Player()
{
	Release();
}

void Player::Set_Player_Name(const string& _StrName)
{
	m_PlayerInfo.strName = _StrName;
}

void Player::Render()
{
	cout << "====================================" << endl;
	cout << m_PlayerInfo.strName << endl;
	cout << "Hp: " << m_PlayerInfo.iHp << endl;
	cout << "Attack Damage: " << m_PlayerInfo.iAttack << endl;
}

void Player::RenderDetail()
{
	cout << "===============================" << endl;
	cout << "이름: " << m_PlayerInfo.strName;
	if (m_PlayerInfo.job == WARRIOR) cout << "\t직업: 전사" << endl;
	else if (m_PlayerInfo.job == MAGE) cout << "\t직업: 마법사" << endl;
	else if (m_PlayerInfo.job == FIGHTER) cout << "\t직업: 격투가" << endl;
	if (ArmorItem != nullptr) {
		cout << "HP: " << m_PlayerInfo.iHp - ArmorItem->Get_DefenseBoost() << "\tArmor: " << ArmorItem->Get_DefenseBoost() << endl;
	}
	else {
		cout << "HP: " << m_PlayerInfo.iHp<< "\tArmor: 0"  << endl;
	}

	if (WeaponItem != nullptr) {
		cout << "HP: " << m_PlayerInfo.iHp - WeaponItem->Get_AttackBoost() << "\Weapon: " << WeaponItem->Get_AttackBoost() << endl;
	}
	else {
		cout << "Attack: " << m_PlayerInfo.iAttack  << "\tWeapon: 0" << endl;
	}


	
	
}

void Player::Init_Inven()
{
	m_Inven = new Inventory;
}

void Player::Release()
{
	SAFE_DELETE<Inventory*>(m_Inven);
	SAFE_DELETE<Weapon*>(WeaponItem);
	SAFE_DELETE<Armor*>(ArmorItem);
}

void Player::usePotion(int healAmount)
{
	m_PlayerInfo.iHp += healAmount;
	if (m_PlayerInfo.iHp > iMaxHp) {
		m_PlayerInfo.iHp = iMaxHp;
	}

}

void Player::equip(Item* equipItem)
{
	if (Weapon* weapon = dynamic_cast<Weapon*>(equipItem)) {
		if (WeaponItem != nullptr && WeaponItem->Get_ItemName() == weapon->Get_ItemName()) {
			cout << "이미 착용 중,,," << endl;
			system("pause");
			return;
		}
	
		if (WeaponItem) unequip("weapon");

		WeaponItem = weapon;
		m_PlayerInfo.iAttack += weapon->Get_AttackBoost();
		WeaponItem->use();
	}
	else if (Armor* armor = dynamic_cast<Armor*>(equipItem)) {
		if(ArmorItem != nullptr && ArmorItem->Get_ItemName() == armor->Get_ItemName()){
			cout << "이미 착용 중,,," << endl;
			system("pause");
			return ;
		}


		if (ArmorItem) unequip("armor");

		ArmorItem = armor;
		m_PlayerInfo.iHp += armor->Get_DefenseBoost();
		iMaxHp += armor->Get_DefenseBoost();
		ArmorItem->use();
	}

	system("pause");
}

void Player::unequip(string type)
{
	if (type == "weapon") {
		if (WeaponItem != nullptr) {
			m_PlayerInfo.iAttack -= WeaponItem->Get_AttackBoost();
			cout << WeaponItem->Get_ItemName() << " 착용을 해제 합니다" << endl;
			WeaponItem = nullptr;
		}
		else {
			cout << "착용된 무기가 없습니다" << endl;
		}
	}

	if (type == "armor") {
		if (ArmorItem != nullptr) {
			m_PlayerInfo.iHp -= ArmorItem->Get_DefenseBoost();
			cout << ArmorItem->Get_ItemName() << " 착용을 해제 합니다" << endl;
			ArmorItem = nullptr;
		}
		else {
			cout << "착용된 방어구가 없습니다" << endl;
		}
	}

	system("pause");
}

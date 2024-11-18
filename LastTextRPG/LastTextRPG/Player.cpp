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
	cout << "�̸�: " << m_PlayerInfo.strName;
	if (m_PlayerInfo.job == WARRIOR) cout << "\t����: ����" << endl;
	else if (m_PlayerInfo.job == MAGE) cout << "\t����: ������" << endl;
	else if (m_PlayerInfo.job == FIGHTER) cout << "\t����: ������" << endl;
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
			cout << "�̹� ���� ��,,," << endl;
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
			cout << "�̹� ���� ��,,," << endl;
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
			cout << WeaponItem->Get_ItemName() << " ������ ���� �մϴ�" << endl;
			WeaponItem = nullptr;
		}
		else {
			cout << "����� ���Ⱑ �����ϴ�" << endl;
		}
	}

	if (type == "armor") {
		if (ArmorItem != nullptr) {
			m_PlayerInfo.iHp -= ArmorItem->Get_DefenseBoost();
			cout << ArmorItem->Get_ItemName() << " ������ ���� �մϴ�" << endl;
			ArmorItem = nullptr;
		}
		else {
			cout << "����� ���� �����ϴ�" << endl;
		}
	}

	system("pause");
}

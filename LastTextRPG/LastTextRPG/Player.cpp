#include "Player.h"
#include "pch.h"

Player::Player()
{
	m_PlayerInfo.strName = "";
	m_PlayerInfo.iDefend = 0;
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

void Player::Init_Inven()
{
	m_Inven = new Inventory;
}

void Player::Release()
{
	SAFE_DELETE(m_Inven);
}

void Player::usePotion(Potion* potion)
{
	m_PlayerInfo.iHp += potion->healAmount;
	if (m_PlayerInfo.iHp > iMaxHp) {
		m_PlayerInfo.iHp = iMaxHp;
	}

	potion->use();
}

void Player::equip(Item* equipItem)
{
	if (Weapon* weapon = dynamic_cast<Weapon*>(equipItem)) {
		if (WeaponItem) unequip("weapon");

		WeaponItem = weapon;
		m_PlayerInfo.iAttack += weapon->Get_AttackBoost();
		WeaponItem->use();
	}
	else if (Armor* armor = dynamic_cast<Armor*>(equipItem)) {
		if (ArmorItem) unequip("armor");

		ArmorItem = armor;
		m_PlayerInfo.iDefend += armor->Get_DefenseBoost();
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
			m_PlayerInfo.iDefend -= ArmorItem->Get_DefenseBoost();
			cout << ArmorItem->Get_ItemName() << " 착용을 해제 합니다" << endl;
			ArmorItem = nullptr;
		}
		else {
			cout << "착용된 방어구가 없습니다" << endl;
		}
	}

	system("pause");
}

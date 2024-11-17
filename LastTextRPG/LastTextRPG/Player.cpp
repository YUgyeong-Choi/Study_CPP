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

void Player::equip(Equipment* equipItem)
{
	if (Weapon* weapon = dynamic_cast<Weapon*>(equipItem)) {
		if (WeaponItem) unequip();

		WeaponItem = weapon;
		m_PlayerInfo.iAttack += weapon->statBoost;
		WeaponItem->use();
	}
	else if (Armor* armor = dynamic_cast<Armor*>(equipItem)) {
		if (ArmorItem) unequip();

		ArmorItem = armor;
		m_PlayerInfo.iDefend += armor->statBoost;
		ArmorItem->use();
	}
}

void Player::unequip()
{
}

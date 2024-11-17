#include "Weapon.h"

void Weapon::use()
{
	cout << strName << "을 착용하여 공격력이 " << statBoost << "만큼 올라갑니다" << endl;
}

void Weapon::equip()
{
	cout << strName << "을 착용하여 공격력이 " << statBoost << "만큼 올라갑니다" << endl;
}

void Weapon::unequip()
{
}

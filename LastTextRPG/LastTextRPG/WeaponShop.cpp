#include "WeaponShop.h"
#include "Weapon.h"

WeaponShop::WeaponShop()
{
	shopItems.push_back(new Weapon(3, "�ʱ� ����", 50, 50));
	shopItems.push_back(new Weapon(4, "�߱� ����", 150, 100));
	shopItems.push_back(new Weapon(5, "��� ����", 300, 150));
}

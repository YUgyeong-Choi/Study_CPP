#include "WeaponShop.h"
#include "Weapon.h"

WeaponShop::WeaponShop()
{
	shopItems.push_back(new Weapon("�ʱ� ����", 50, 50));
	shopItems.push_back(new Weapon("�߱� ����", 150, 100));
	shopItems.push_back(new Weapon("��� ����", 300, 150));
}

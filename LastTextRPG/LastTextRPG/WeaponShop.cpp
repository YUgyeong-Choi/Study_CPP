#include "WeaponShop.h"
#include "Weapon.h"

WeaponShop::WeaponShop()
{
	shopItems.push_back(new Weapon("초급 무기", 50, 50));
	shopItems.push_back(new Weapon("중급 무기", 150, 100));
	shopItems.push_back(new Weapon("고급 무기", 300, 150));
}

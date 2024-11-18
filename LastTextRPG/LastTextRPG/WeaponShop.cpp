#include "WeaponShop.h"
#include "Weapon.h"

WeaponShop::WeaponShop()
{
	shopItems.push_back(new Weapon(3, "초급 무기", 50, 50));
	shopItems.push_back(new Weapon(4, "중급 무기", 150, 100));
	shopItems.push_back(new Weapon(5, "고급 무기", 300, 150));
}

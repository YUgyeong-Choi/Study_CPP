#include "ArmorShop.h"
#include "Armor.h"

ArmorShop::ArmorShop()
{
	shopItems.push_back(new Armor(6, "초급 방어구", 40, 40));
	shopItems.push_back(new Armor(7, "중급 방어구", 110, 80));
	shopItems.push_back(new Armor(8, "고급 방어구", 210, 120));
}

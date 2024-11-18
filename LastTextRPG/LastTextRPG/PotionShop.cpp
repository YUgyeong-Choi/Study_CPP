#include "PotionShop.h"
#include "Potion.h"

PotionShop::PotionShop()
{
	shopItems.push_back(new Potion(0, "HP 물약 (소)", 15, 30));
	shopItems.push_back(new Potion(1, "HP 물약 (중)", 30, 70));
	shopItems.push_back(new Potion(2, "HP 물약 (대)", 60, 150));
}

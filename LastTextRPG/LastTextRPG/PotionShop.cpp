#include "PotionShop.h"
#include "Potion.h"

PotionShop::PotionShop()
{
	shopItems.push_back(new Potion(0, "HP ���� (��)", 15, 30));
	shopItems.push_back(new Potion(1, "HP ���� (��)", 30, 70));
	shopItems.push_back(new Potion(2, "HP ���� (��)", 60, 150));
}

#include "PotionShop.h"
#include "Potion.h"

PotionShop::PotionShop()
{
	shopItems.push_back(new Potion("HP ���� (��)", 15, 30));
	shopItems.push_back(new Potion("HP ���� (��)", 30, 70));
	shopItems.push_back(new Potion("HP ���� (��)", 60, 150));
}

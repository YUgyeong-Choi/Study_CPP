#include "ArmorShop.h"
#include "Armor.h"

ArmorShop::ArmorShop()
{
	shopItems.push_back(new Armor(6, "�ʱ� ��", 40, 40));
	shopItems.push_back(new Armor(7, "�߱� ��", 110, 80));
	shopItems.push_back(new Armor(8, "��� ��", 210, 120));
}

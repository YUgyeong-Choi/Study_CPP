#include "ArmorShop.h"
#include "Armor.h"

ArmorShop::ArmorShop()
{
	shopItems.push_back(new Armor("�ʱ� ��", 40, 40));
	shopItems.push_back(new Armor("�߱� ��", 110, 80));
	shopItems.push_back(new Armor("��� ��", 210, 120));
}

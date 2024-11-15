#pragma once
#include "Store.h"
class WeaponStore :public Store {
public:
	WeaponStore();
	~WeaponStore();
public:
	virtual void Render();
};
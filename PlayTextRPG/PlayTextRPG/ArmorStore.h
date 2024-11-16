#pragma once
#include "Store.h"
class ArmorStore :public Store {
public:
	ArmorStore();
	~ArmorStore();
public:
	virtual void Render();
};
#pragma once
#include "Store.h"
class PotionStore :public Store {
public:
	PotionStore();
	~PotionStore();
public:
	virtual void Render();
};
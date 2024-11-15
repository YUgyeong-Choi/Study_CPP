#pragma once
#include "Store.h"
class PostionStore :public Store {
public:
	PostionStore();
	~PostionStore();
public:
	virtual void Render();
};
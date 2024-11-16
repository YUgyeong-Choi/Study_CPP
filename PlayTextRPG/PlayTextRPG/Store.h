#pragma once
#include "Define.h"
#include "pch.h"
#include "Player.h"
#include "Item.h"


class Store {
public:
	Store();
	virtual ~Store();
public:
	void Release();
	void Update();
	void Set_PlayerInfo(Player* _pPlayer) { m_pPlayer = _pPlayer; }
	//todo »ç°í ÆÈ±â
public:
	virtual void Render() PURE;
protected:
	Player* m_pPlayer;
	vector<Item*> items;
};
#include "Player.h"
#include "Roulette.h"
class Minigame {
public:
	Minigame();
	~Minigame();
public:
	void Update();
	void Release();
	void Set_PlayerInfo(Player* _pPlayer) { m_pPlayer = _pPlayer; }

private:
	Player* m_pPlayer;
	Roulette* rouletteGame;
};
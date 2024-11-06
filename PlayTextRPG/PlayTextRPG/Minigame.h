#include "Player.h"
class Minigame {
public:
	Minigame();
	~Minigame();
public:
	void Update();
	void Set_PlayerInfo(Player* _pPlayer) { m_pPlayer = _pPlayer; }

private:
	Player* m_pPlayer;
};
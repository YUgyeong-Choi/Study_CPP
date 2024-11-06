#pragma once
#include "pch.h"
#include <vector>
#include "Player.h"

class Roulette {
public:
    // ������: �귿 ���� �迭�� ������ ���ڷ� �޾Ƽ� ����
    Roulette();
    void Update();
    void Set_PlayerInfo(Player* _pPlayer) { m_pPlayer = _pPlayer; }

private:
    vector<int> rouletteNumbers;  // �귿 ���� �迭
    void Render(int i);
    bool Info();
    // �귿�� ȸ����Ű�鼭 ����� ����ϴ� �Լ�
    int spinAndDisplay();

    // ������ ����ϴ� �Լ�
    int calculatePayout(int finalResult, int money);
private:
    Player* m_pPlayer;
};

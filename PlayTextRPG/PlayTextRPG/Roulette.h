#pragma once
#include "pch.h"
#include <vector>
#include "Player.h"

class Roulette {
public:
    // 생성자: 룰렛 숫자 배열을 생성자 인자로 받아서 설정
    Roulette();
    void Update();
    void Set_PlayerInfo(Player* _pPlayer) { m_pPlayer = _pPlayer; }

private:
    vector<int> rouletteNumbers;  // 룰렛 숫자 배열
    void Render(int i);
    bool Info();
    // 룰렛을 회전시키면서 결과를 출력하는 함수
    int spinAndDisplay();

    // 배당금을 계산하는 함수
    int calculatePayout(int finalResult, int money);
private:
    Player* m_pPlayer;
};

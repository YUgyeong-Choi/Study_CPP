#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <cstdlib>  // system() 함수 사용을 위한 헤더
#include <random>   // 난수 생성 헤더

using namespace std;

// 룰렛을 회전시키면서 결과를 출력하는 함수
void spinAndDisplay(const vector<int>& roulette) {
    int delay = 50;  // 초기 지연 시간 (밀리초)

    // 난수 생성기 초기화
    random_device rd;  // 랜덤 시드를 얻기 위한 장치
    mt19937 gen(rd()); // Mersenne Twister 엔진을 사용하여 난수 생성기 초기화
    uniform_int_distribution<> dist(410, 500);  // 410에서 500 사이의 랜덤 값 생성

    int maxDelay = dist(gen);  // 410에서 500 사이의 랜덤 값으로 maxDelay 설정

    int spinCount = roulette.size();
    int half = spinCount / 2;  // 배열을 반으로 나누기

    vector<int> results;  // 룰렛의 결과를 저장할 벡터

    // 룰렛 회전 효과 (무한 루프)
    int i = 0; // 회전 인덱스 초기화
    while (delay < maxDelay) {  // delay가 maxDelay보다 작을 때만 계속 회전
        // 화면을 지우고 출력 (OS에 따라 다를 수 있음)
        system("cls");  // 윈도우에서 화면 지우기 (리눅스/유닉스는 clear)

        // 첫 번째 절반 출력
        for (int j = 0; j < half; j++) {
            cout << roulette[j] << '\t';
        }
        cout << endl;

        for (int j = 0; j < half; j++) {
            if (j == i) {
                cout << "!";  // 화살표 느낌을 주는 '!' 출력
            }
            else {
                cout << '\t';
            }
        }

        cout << endl;

        // 두 번째 절반 출력
        for (int j = half; j < spinCount; j++) {
            cout << roulette[j] << '\t';
        }
        cout << endl;

        for (int j = half; j < spinCount; j++) {
            if (j == i) {
                cout << "!";  // 화살표 느낌을 주는 '!' 출력
            }
            else {
                cout << '\t';
            }
        }

        cout << endl;

        // 지연 시간 증가 (점차 느려지게)
        if (delay < maxDelay) {
            delay += 10;  // 점차적으로 지연 시간을 늘려줌
        }

        // 지연 시간 적용
        this_thread::sleep_for(chrono::milliseconds(delay));

        // 회전 인덱스 업데이트
        i = (i + 1) % spinCount;  // 룰렛 배열을 순환하며 계속 회전

        // 회전 결과 저장
        results.push_back(roulette[i]);
    }

    // 최종 룰렛 결과 출력
    int finalResult = results.back();  // 멈췄을 때의 결과
    cout << "\n최종 룰렛 결과: " << finalResult << endl;

    // 배당금 계산 (배팅 금액을 100원으로 가정)
    double betAmount = 100;
    double payout = 0;

    // 결과에 따른 배당금 계산
    if (finalResult == 1) payout = betAmount * 1;
    else if (finalResult == 3) payout = betAmount * 3;
    else if (finalResult == 5) payout = betAmount * 5;
    else if (finalResult == 10) payout = betAmount * 10;
    else if (finalResult == 20) payout = betAmount * 20;

    // 배당금 출력
    cout << "당신의 배당금: " << payout << "원" << endl;
}

int main() {
    // 룰렛의 숫자 배열 (순서는 그대로)
    vector<int> roulette = { 1, 3, 1, 10, 1, 3, 1, 5, 1, 5, 3, 1, 10, 1, 3, 1, 5, 1, 3, 1, 20, 1, 3, 1, 5 };

    // 룰렛 회전 및 출력 시작
    spinAndDisplay(roulette);

    return 0;
}
#include "Roulette.h"
#include "Color.h"
#include <chrono>
#include <thread>
#include <cstdlib>  // system() 함수 사용을 위한 헤더
#include <random>   // 난수 생성 헤더

using namespace std;

// 생성자: 룰렛 숫자 배열을 받아서 초기화
Roulette::Roulette(){
    m_pPlayer = nullptr;
    rouletteNumbers= { 1, 3, 1, 10, 1, 3, 1, 5, 1, 5, 3, 1, 10, 1, 3, 1, 5, 1, 3, 1, 20, 1, 3, 1, 5 };
    
}

// 룰렛을 회전시키는 함수
void Roulette::Update() {
    int i(0);
    
    if (!Info()) return; //뒤로가기 누르면 나감

    while (1) {
        system("cls");
        Render(i);

        int number(0);
        int money(0);
        while (1) {
            cout << "선택할 숫자를 입력하세요(1,3,5,10,20): " << endl;
            cin >> number;
            if (number != 1 && number != 3 && number != 5 && number != 10 && number != 20) {
                cout << "잘못된 입력입니다. 1, 3, 5, 10, 20 중에서 입력해주세요." << endl;
                continue;
            }
            break;
        }

        while (1) {
            cout << "얼마를 넣으시겠습니까?: " << endl;
            cin >> money;
            if (money <= 0) {
                cout << "잘못된 값입니다" << endl;
                continue;
            }

            if (money > m_pPlayer->Get_Info().iMoney) {
                cout << "잔액이 부족합니다" << endl;
                cout << "나의 돈: " << m_pPlayer->Get_Info().iMoney << endl;
                continue;
            }
            break;
        }

        i = spinAndDisplay();
        int result = rouletteNumbers[i];
       
        if (number == result) {
            int payment = calculatePayout(result, money);
            cout << payment<<" 배당금을 얻었습니다!" << endl;
            m_pPlayer->Add_PlayerMoney(payment + money);
            cout << "나의 돈: " << m_pPlayer->Get_Info().iMoney << endl;

            system("pause");
        }
        else {
            cout << "돈을 잃었습니다" << endl;
            m_pPlayer->Sub_PlayerMoney(money);
            cout << "나의 돈: " << m_pPlayer->Get_Info().iMoney << endl;
            system("pause");
        }

        bool isContinue = false;
        while (1) {
            int _iInput(0);
            cout << "1. 계속하기 2.나가기" << endl;
            cin >> _iInput;

            switch (_iInput)
            {
            case 1:
                isContinue = true;
                break;
            case 2:
                return;
            default:
                cout<<"잘못 입력하셨습니다"<<endl;
                continue;
            }

            if (isContinue) break;
        }

    }
}

void Roulette::Render(int i)
{
    int spinCount = rouletteNumbers.size();
    int half = spinCount / 2;
    for (int j = 0; j < half; j++) {
        cout << rouletteNumbers[j] << '\t';
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
        cout << rouletteNumbers[j] << '\t';
    }
    cout << endl;

    for (int j = half; j < spinCount; j++) {
        if (j == i) {
            cout << "!";  // 화살표 느낌을 주는 '!' 출력
        }
        else {
            setColor(YELLOW); cout << '\t'; setColor(GRAY);
        }
    }
    cout << endl;
}

bool Roulette::Info()
{
    system("cls");
    cout << endl;
    cout << "따다닥 따닥.. 따.. 닥.." << endl;
    cout << "!!!! Welcome To 룰렛 !!!!" << endl << endl;
    system("pause");

    system("cls");
    cout << "룰렛에 대한 간단한 설명을 해주겠네" << endl << endl;
    cout << "==================================" << endl;
    cout << "1. 배팅할 숫자를 입력하기" << endl;
    cout << "2. 배팅할 돈을 입력하기" << endl;
    cout << "3. 룰렛이 돌아갈 동안 기다리기" << endl;
    cout << "==================================" << endl;
    cout << "허허.. 참 간단하지?" << endl << endl;

    int _iInput(0);
    while (1) {
        setColor(YELLOW);
        cout << "1. 룰렛 하러가기" << endl;
        cout << "2. 뒤로가기" << endl;
        setColor(GRAY);
        cin >> _iInput;
        switch (_iInput)
        {
        case 1:
            return true;
        case 2:
            return false;
        default:
            cout << "잘못 입력하셨습니다" << endl;
            continue;
        }
    }
}

// 룰렛 회전 효과 및 결과 출력
int Roulette::spinAndDisplay() {
    int delay = 50;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(410, 500);
    int maxDelay = dist(gen);  // 410에서 500 사이의 랜덤 값으로 maxDelay 설정
    int spinCount = rouletteNumbers.size();
    int half = spinCount / 2;

    int i = 0;  // 회전 인덱스 초기화
    while (delay < maxDelay) { 
        system("cls");
        // 첫 번째 절반 출력
        for (int j = 0; j < half; j++) {
            cout << rouletteNumbers[j] << '\t';
        }
        cout << endl;

        for (int j = 0; j < half; j++) {
            if (j == i) {
                cout << "!";  // 화살표 느낌을 주는 '!' 출력
            }
            else {
                setColor(YELLOW); cout << '\t'; setColor(GRAY);
            }
        }

        cout << endl;

        // 두 번째 절반 출력
        for (int j = half; j < spinCount; j++) {
            cout << rouletteNumbers[j] << '\t';
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

    }
    return i-1;
}

// 배당금 계산 함수
int Roulette::calculatePayout(int finalResult, int money) {
    int payout = 0;

    if (finalResult == 1) payout = money * 1;
    else if (finalResult == 3) payout = money * 3;
    else if (finalResult == 5) payout = money * 5;
    else if (finalResult == 10) payout = money * 10;
    else if (finalResult == 20) payout = money * 20;

    return payout;
}
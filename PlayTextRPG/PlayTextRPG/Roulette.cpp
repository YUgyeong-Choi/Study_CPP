#include "Roulette.h"
#include "Color.h"
#include <chrono>
#include <thread>
#include <cstdlib>  // system() �Լ� ����� ���� ���
#include <random>   // ���� ���� ���

using namespace std;

// ������: �귿 ���� �迭�� �޾Ƽ� �ʱ�ȭ
Roulette::Roulette(){
    m_pPlayer = nullptr;
    rouletteNumbers= { 1, 3, 1, 10, 1, 3, 1, 5, 1, 5, 3, 1, 10, 1, 3, 1, 5, 1, 3, 1, 20, 1, 3, 1, 5 };
    
}

// �귿�� ȸ����Ű�� �Լ�
void Roulette::Update() {
    int i(0);
    
    if (!Info()) return; //�ڷΰ��� ������ ����

    while (1) {
        system("cls");
        Render(i);

        int number(0);
        int money(0);
        while (1) {
            cout << "������ ���ڸ� �Է��ϼ���(1,3,5,10,20): " << endl;
            cin >> number;
            if (number != 1 && number != 3 && number != 5 && number != 10 && number != 20) {
                cout << "�߸��� �Է��Դϴ�. 1, 3, 5, 10, 20 �߿��� �Է����ּ���." << endl;
                continue;
            }
            break;
        }

        while (1) {
            cout << "�󸶸� �����ðڽ��ϱ�?: " << endl;
            cin >> money;
            if (money <= 0) {
                cout << "�߸��� ���Դϴ�" << endl;
                continue;
            }

            if (money > m_pPlayer->Get_Info().iMoney) {
                cout << "�ܾ��� �����մϴ�" << endl;
                cout << "���� ��: " << m_pPlayer->Get_Info().iMoney << endl;
                continue;
            }
            break;
        }

        i = spinAndDisplay();
        int result = rouletteNumbers[i];
       
        if (number == result) {
            int payment = calculatePayout(result, money);
            cout << payment<<" ������ ������ϴ�!" << endl;
            m_pPlayer->Add_PlayerMoney(payment + money);
            cout << "���� ��: " << m_pPlayer->Get_Info().iMoney << endl;

            system("pause");
        }
        else {
            cout << "���� �Ҿ����ϴ�" << endl;
            m_pPlayer->Sub_PlayerMoney(money);
            cout << "���� ��: " << m_pPlayer->Get_Info().iMoney << endl;
            system("pause");
        }

        bool isContinue = false;
        while (1) {
            int _iInput(0);
            cout << "1. ����ϱ� 2.������" << endl;
            cin >> _iInput;

            switch (_iInput)
            {
            case 1:
                isContinue = true;
                break;
            case 2:
                return;
            default:
                cout<<"�߸� �Է��ϼ̽��ϴ�"<<endl;
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
            cout << "!";  // ȭ��ǥ ������ �ִ� '!' ���
        }
        else {
            cout << '\t';
        }
    }
    cout << endl;

    // �� ��° ���� ���
    for (int j = half; j < spinCount; j++) {
        cout << rouletteNumbers[j] << '\t';
    }
    cout << endl;

    for (int j = half; j < spinCount; j++) {
        if (j == i) {
            cout << "!";  // ȭ��ǥ ������ �ִ� '!' ���
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
    cout << "���ٴ� ����.. ��.. ��.." << endl;
    cout << "!!!! Welcome To �귿 !!!!" << endl << endl;
    system("pause");

    system("cls");
    cout << "�귿�� ���� ������ ������ ���ְڳ�" << endl << endl;
    cout << "==================================" << endl;
    cout << "1. ������ ���ڸ� �Է��ϱ�" << endl;
    cout << "2. ������ ���� �Է��ϱ�" << endl;
    cout << "3. �귿�� ���ư� ���� ��ٸ���" << endl;
    cout << "==================================" << endl;
    cout << "����.. �� ��������?" << endl << endl;

    int _iInput(0);
    while (1) {
        setColor(YELLOW);
        cout << "1. �귿 �Ϸ�����" << endl;
        cout << "2. �ڷΰ���" << endl;
        setColor(GRAY);
        cin >> _iInput;
        switch (_iInput)
        {
        case 1:
            return true;
        case 2:
            return false;
        default:
            cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
            continue;
        }
    }
}

// �귿 ȸ�� ȿ�� �� ��� ���
int Roulette::spinAndDisplay() {
    int delay = 50;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(410, 500);
    int maxDelay = dist(gen);  // 410���� 500 ������ ���� ������ maxDelay ����
    int spinCount = rouletteNumbers.size();
    int half = spinCount / 2;

    int i = 0;  // ȸ�� �ε��� �ʱ�ȭ
    while (delay < maxDelay) { 
        system("cls");
        // ù ��° ���� ���
        for (int j = 0; j < half; j++) {
            cout << rouletteNumbers[j] << '\t';
        }
        cout << endl;

        for (int j = 0; j < half; j++) {
            if (j == i) {
                cout << "!";  // ȭ��ǥ ������ �ִ� '!' ���
            }
            else {
                setColor(YELLOW); cout << '\t'; setColor(GRAY);
            }
        }

        cout << endl;

        // �� ��° ���� ���
        for (int j = half; j < spinCount; j++) {
            cout << rouletteNumbers[j] << '\t';
        }
        cout << endl;

        for (int j = half; j < spinCount; j++) {
            if (j == i) {
                cout << "!";  // ȭ��ǥ ������ �ִ� '!' ���
            }
            else {
                cout << '\t';
            }
        }

        cout << endl;

        // ���� �ð� ���� (���� ��������)
        if (delay < maxDelay) {
            delay += 10;  // ���������� ���� �ð��� �÷���
        }

        // ���� �ð� ����
        this_thread::sleep_for(chrono::milliseconds(delay));

        // ȸ�� �ε��� ������Ʈ
        i = (i + 1) % spinCount;  // �귿 �迭�� ��ȯ�ϸ� ��� ȸ��

    }
    return i-1;
}

// ���� ��� �Լ�
int Roulette::calculatePayout(int finalResult, int money) {
    int payout = 0;

    if (finalResult == 1) payout = money * 1;
    else if (finalResult == 3) payout = money * 3;
    else if (finalResult == 5) payout = money * 5;
    else if (finalResult == 10) payout = money * 10;
    else if (finalResult == 20) payout = money * 20;

    return payout;
}
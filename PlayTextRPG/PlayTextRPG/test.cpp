#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <cstdlib>  // system() �Լ� ����� ���� ���

using namespace std;

// �귿�� ȸ����Ű�鼭 ����� ����ϴ� �Լ�
void spinAndDisplay(const vector<int>& roulette) {
    int delay = 50;  // �ʱ� ���� �ð� (�и���)
    int maxDelay = 200;  // �ִ� ���� �ð� (�и���)

    int spinCount = roulette.size();
    int half = spinCount / 2;  // �迭�� ������ ������

    // �귿 ȸ�� ȿ�� (���� ����)
    int i = 0; // ȸ�� �ε��� �ʱ�ȭ
    while (delay < maxDelay) {  // delay�� maxDelay���� ���� ���� ��� ȸ��
        // ȭ���� ����� ��� (OS�� ���� �ٸ� �� ����)
        system("cls");  // �����쿡�� ȭ�� ����� (������/���н��� clear)

        // ù ��° ���� ���
        for (int j = 0; j < half; j++) {
            cout << roulette[j] << '\t';
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
            cout << roulette[j] << '\t';
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

        // ���� ��� (���� �ݾ��� 100������ ����)
        double betAmount = 100;
        double payout = 0;
        int spinResult = roulette[i];
        if (spinResult == 1) payout = betAmount * 1;
        else if (spinResult == 3) payout = betAmount * 3;
        else if (spinResult == 5) payout = betAmount * 5;
        else if (spinResult == 10) payout = betAmount * 10;
        else if (spinResult == 20) payout = betAmount * 20;

        // ���� ���
        cout << "����� ����: " << payout << "��" << endl;

        // ���� �ð� ���� (���� ��������)
        if (delay < maxDelay) {
            delay += 10;  // ���������� ���� �ð��� �÷���
        }

        // ���� �ð� ����
        this_thread::sleep_for(chrono::milliseconds(delay));

        // ȸ�� �ε��� ������Ʈ
        i = (i + 1) % spinCount;  // �귿 �迭�� ��ȯ�ϸ� ��� ȸ��

    }

    // ���� �귿 ��� ���
    int finalResult = roulette[i];  // ������ ���� ���
    cout << "\n���� �귿 ���: " << finalResult << endl;
}

int main() {
    // �귿�� ���� �迭 (������ �״��)
    vector<int> roulette = { 1, 3, 1, 10, 1, 3, 1, 5, 1, 5, 3, 1, 10, 1, 3, 1, 5, 1, 3, 1, 20, 1, 3, 1, 5 };

    // �귿 ȸ�� �� ��� ����
    spinAndDisplay(roulette);

    return 0;
}
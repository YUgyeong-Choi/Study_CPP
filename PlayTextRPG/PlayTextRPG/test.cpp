#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    char array[5][5][2];

    // �迭 �ʱ�ȭ
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            array[i][j][0] = '*'; // ù ��° ��Ҵ� '*'�� �ʱ�ȭ
            array[i][j][1] = 'f'; // �� ��° ��Ҵ� 'f'�� �ʱ�ȭ
        }
    }

    // ��� ��Ҵ� �׻� 'f'�� ����
    array[2][2][1] = 'f';

    // �������� 6�� ��Ҹ� 't'�� ���� (����� ����)
    std::srand(std::time(0)); // ���� �õ� �ʱ�ȭ
    int count = 0;

    while (count < 6) {
        int i = std::rand() % 5; // 0���� 4���� ����
        int j = std::rand() % 5; // 0���� 4���� ����

        // �̹� 't'�� ������ ���� �����ϰ�, ����� ����
        if (array[i][j][1] == 'f' && !(i == 2 && j == 2)) {
            array[i][j][1] = 't'; // 't'�� ����
            count++;
        }
    }

    // ��� ���
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout << array[i][j][0] << array[i][j][1] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
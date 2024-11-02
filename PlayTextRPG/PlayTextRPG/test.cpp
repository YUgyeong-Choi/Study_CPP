#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    char array[5][5][2];

    // 배열 초기화
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            array[i][j][0] = '*'; // 첫 번째 요소는 '*'로 초기화
            array[i][j][1] = 'f'; // 두 번째 요소는 'f'로 초기화
        }
    }

    // 가운데 요소는 항상 'f'로 유지
    array[2][2][1] = 'f';

    // 랜덤으로 6개 요소를 't'로 변경 (가운데는 제외)
    std::srand(std::time(0)); // 랜덤 시드 초기화
    int count = 0;

    while (count < 6) {
        int i = std::rand() % 5; // 0부터 4까지 랜덤
        int j = std::rand() % 5; // 0부터 4까지 랜덤

        // 이미 't'로 설정된 경우는 무시하고, 가운데는 제외
        if (array[i][j][1] == 'f' && !(i == 2 && j == 2)) {
            array[i][j][1] = 't'; // 't'로 변경
            count++;
        }
    }

    // 결과 출력
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout << array[i][j][0] << array[i][j][1] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
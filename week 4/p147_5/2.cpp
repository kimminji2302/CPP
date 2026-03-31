#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    int n, bullets;

    std::cout << "탄창 크기(n): ";
    std::cin >> n;

    std::cout << "총알 개수: ";
    std::cin >> bullets;

    std::vector<int> gun(n, 0);

    std::srand(std::time(0));

    // 총알 여러 개 넣기
    int count = 0;
    while (count < bullets) {
        int pos = std::rand() % n;
        if (gun[pos] == 0) {
            gun[pos] = 1;
            count++;
        }
    }

    int turn = 0;
    int player = 1;

    std::cout << "\n게임 시작!\n";

    while (bullets > 0) {
        std::cout << "플레이어 " << player << ": ";

        if (gun[turn] == 1) {
            std::cout << "탕! 💥\n";
            gun[turn] = 0;
            bullets--;
        } else {
            std::cout << "살았다 😄\n";
        }

        turn = (turn + 1) % n;
        player++;
    }

    std::cout << "\n게임 종료!\n";

    return 0;
}
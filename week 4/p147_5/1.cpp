#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    int n;
    std::cout << "탄창 크기(n): ";
    std::cin >> n;

    std::srand(std::time(0));

    int bullet = std::rand() % n; // 총알 위치

    int turn = 0;
    int player = 1;

    while (true) {
        std::cout << "플레이어 " << player << ": ";

        if (turn == bullet) {
            std::cout << "탕! 💥\n";
            break;
        } else {
            std::cout << "살았다 😄\n";
        }

        turn = (turn + 1) % n;
        player++;
    }

    return 0;
}
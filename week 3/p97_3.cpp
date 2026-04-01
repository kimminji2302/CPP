#include <iostream>

int main() {
    int n;
    std::cin >> n;

    double hap = 0.0;

    for (int i = 0; i <= n; i++) {
        hap += (i % 2 == 0 ? 1.0 : -1.0) / (2 * i + 1);
    }

    std::cout << 4 * hap;

    return 0;
}
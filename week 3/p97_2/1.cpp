#include <iostream>

int main() {
    int num;
    std::cin >> num;

    int man = num / 10000;
    int cheon = (num % 10000) / 1000;
    int baek = (num % 1000) / 100;
    int sip = (num % 100) / 10;
    int il = num % 10;

    if (man) std::cout << man << "만 ";
    if (cheon) std::cout << cheon << "천 ";
    if (baek) std::cout << baek << "백 ";
    if (sip) std::cout << sip << "십 ";
    if (il) std::cout << il;

    return 0;
}
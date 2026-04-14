#include "5.hpp"
#include <iostream>
using namespace std;

int main() {
    MyTime t1, t2, t3;

    t1.read();
    t2.read();

    t3 = t1.add(t2);

    cout << "결과: ";
    t3.print();

    return 0;
}
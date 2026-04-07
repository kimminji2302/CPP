#include <iostream>
using namespace std;

struct MyTime {
    int h, m;
};

void addTime(MyTime t1, MyTime t2, MyTime &t3) {
    t3.h = t1.h + t2.h;
    t3.m = t1.m + t2.m;
    if (t3.m >= 60) { t3.h++; t3.m -= 60; }
}

int main() {
    MyTime t1 = {2, 50}, t2 = {1, 30};
    MyTime t3;

    addTime(t1, t2, t3);

    cout << t3.h << ":" << t3.m;
}
//참조방식
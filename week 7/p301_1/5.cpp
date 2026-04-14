#include <iostream>
#include <iomanip>
#include "5.hpp"

using namespace std;

void MyTime::convert(double duration) {
    int total = (int)(duration * 1000);

    hour = total / (3600 * 1000);
    total %= (3600 * 1000);

    minute = total / (60 * 1000);
    total %= (60 * 1000);

    second = total / 1000;
    millisecond = total % 1000;
}

void MyTime::print() {
    cout << setfill('0');
    cout << setw(2) << hour << ":"
         << setw(2) << minute << ":"
         << setw(2) << second << ":"
         << setw(3) << millisecond << endl;
}

MyTime MyTime::add(MyTime t) {
    MyTime result;

    result.millisecond = millisecond + t.millisecond;
    result.second = second + t.second;
    result.minute = minute + t.minute;
    result.hour = hour + t.hour;

    if (result.millisecond >= 1000) {
        result.second += result.millisecond / 1000;
        result.millisecond %= 1000;
    }

    if (result.second >= 60) {
        result.minute += result.second / 60;
        result.second %= 60;
    }

    if (result.minute >= 60) {
        result.hour += result.minute / 60;
        result.minute %= 60;
    }

    return result;
}

void MyTime::reset() {
    hour = 0;
    minute = 0;
    second = 0;
    millisecond = 0;
}

void MyTime::read() {
    cout << "시 분 초 밀리초 입력: ";
    cin >> hour >> minute >> second >> millisecond;
}
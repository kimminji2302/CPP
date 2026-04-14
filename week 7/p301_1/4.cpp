#include <iostream>
using namespace std;

class MyTime {
private:
    int hour;
    int minute;
    int second;
    int millisecond;

public:
    void read() {
        cout << "시 분 초 밀리초 입력: ";
        cin >> hour >> minute >> second >> millisecond;
    }
};
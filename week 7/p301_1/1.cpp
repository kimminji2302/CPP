#include <iostream>
using namespace std;

class MyTime {
private:
    int hour;
    int minute;
    int second;
    int millisecond;

public:
    // 초(double)를 시:분:초:밀리초로 변환
    inline void convert(double duration) {
        int total_ms = (int)(duration * 1000);

        hour = total_ms / (3600 * 1000);
        total_ms %= (3600 * 1000);

        minute = total_ms / (60 * 1000);
        total_ms %= (60 * 1000);

        second = total_ms / 1000;
        millisecond = total_ms % 1000;
    }

    // 출력 함수
    inline void print() {
        cout << hour << ":"
             << minute << ":"
             << second << ":"
             << millisecond << endl;
    }

    // 시간 덧셈
    inline MyTime add(MyTime t) {
        MyTime result;

        result.millisecond = millisecond + t.millisecond;
        result.second = second + t.second + result.millisecond / 1000;
        result.millisecond %= 1000;

        result.minute = minute + t.minute + result.second / 60;
        result.second %= 60;

        result.hour = hour + t.hour + result.minute / 60;
        result.minute %= 60;

        return result;
    }

    // 초기화
    inline void reset() {
        hour = minute = second = millisecond = 0;
    }
};

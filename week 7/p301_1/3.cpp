#include <iostream>
#include <iomanip>
using namespace std;

class MyTime {
private:
    int hour;
    int minute;
    int second;
    int millisecond;

public:
    void print() {
        cout << setfill('0');
        cout << setw(2) << hour << ":"
             << setw(2) << minute << ":"
             << setw(2) << second << ":"
             << setw(3) << millisecond << endl;
    }
};
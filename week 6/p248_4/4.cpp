#include <iostream>
using namespace std;

#define MAX_X 80
#define MAX_Y 40

int b[MAX_Y][MAX_X];

int main() {
    int x, y;
    char ch;

    while (1) {
        cout << "입력: ";
        cin >> ch;

        if (ch == 'P' || ch == 'p') {
            cin >> x >> y;
            b[y][x] = 2;
            cout << "깃발 표시\n";
        }
        else {
            x = ch - '0';
            cin >> y;
            b[y][x] = 1;
            cout << "열기\n";
        }
    }
}
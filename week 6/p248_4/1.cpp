#include <iostream>
using namespace std;

#define MAX_X 80
#define MAX_Y 40

int a[MAX_Y][MAX_X];
int b[MAX_Y][MAX_X];

int x, y;

int main() {
    cout << "크기 입력: ";
    cin >> x >> y;

    cout << "가로: " << x << ", 세로: " << y << endl;
}
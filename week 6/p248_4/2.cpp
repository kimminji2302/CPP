#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAX_X 80
#define MAX_Y 40

int a[MAX_Y][MAX_X];
int b[MAX_Y][MAX_X];

int x = 10, y = 10;
int n;

int main() {
    srand(time(0));

    cout << "지뢰 수: ";
    cin >> n;

    for (int i = 0; i < y; i++)
        for (int j = 0; j < x; j++) {
            a[i][j] = 0;
            b[i][j] = 0;
        }

    int c = 0;
    while (c < n) {
        int xx = rand() % x;
        int yy = rand() % y;

        if (a[yy][xx] != 9) {
            a[yy][xx] = 9;
            c++;
        }
    }

    cout << "지뢰 배치 완료\n";
}
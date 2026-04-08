#include <iostream>
using namespace std;

#define MAX_X 80
#define MAX_Y 40

int a[MAX_Y][MAX_X];
int b[MAX_Y][MAX_X];

int x = 10, y = 10;

int main() {
    // 테스트용 값
    a[0][0] = 9;

    cout << "  ";
    for (int i = 0; i < x; i++) cout << i << " ";
    cout << endl;

    for (int i = 0; i < y; i++) {
        cout << i << " ";
        for (int j = 0; j < x; j++) {
            if (b[i][j] == 0) cout << "# ";
            else if (b[i][j] == 2) cout << "P ";
            else {
                if (a[i][j] == 9) cout << "* ";
                else cout << a[i][j] << " ";
            }
        }
        cout << endl;
    }
}
#include <iostream>
using namespace std;

void printMap(int map[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (map[i][j] == 0)
                cout << "□ ";
            else
                cout << "■ ";
        }
        cout << endl;
    }
}
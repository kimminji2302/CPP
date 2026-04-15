#include <iostream>
#include <string>
using namespace std;

struct WordPair {
    string eng;
    string kor;
};

int main() {
    WordPair w;

    w.eng = "apple";
    w.kor = "사과";

    cout << w.eng << " : " << w.kor << endl;

    return 0;
}
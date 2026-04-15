#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define MAXWORDS 100

struct WordPair {
    string eng;
    string kor;
};

class MyDic {
private:
    WordPair words[MAXWORDS];
    int nWords;

public:
    MyDic() {
        nWords = 0;
    }

    void add(string eng, string kor) {
        if (nWords >= MAXWORDS) return;

        words[nWords].eng = eng;
        words[nWords].kor = kor;
        nWords++;
    }

    void load(string filename) {
        ifstream fin(filename);

        if (!fin) {
            cout << "파일 열기 실패" << endl;
            return;
        }

        nWords = 0;

        while (!fin.eof()) {
            fin >> words[nWords].eng >> words[nWords].kor;
            if (fin.fail()) break;
            nWords++;
        }

        fin.close();
    }

    void store(string filename) {
        ofstream fout(filename);

        for (int i = 0; i < nWords; i++) {
            fout << words[i].eng << " " << words[i].kor << endl;
        }

        fout.close();
    }

    void print() {
        for (int i = 0; i < nWords; i++) {
            cout << i << " : " << words[i].eng << " - " << words[i].kor << endl;
        }
    }

    string getEng(int id) {
        return words[id].eng;
    }

    string getKor(int id) {
        return words[id].kor;
    }
};

int main() {
    MyDic dic;

    dic.add("apple", "사과");
    dic.add("banana", "바나나");
    dic.add("cat", "고양이");

    dic.store("dic.txt");

    MyDic dic2;
    dic2.load("dic.txt");

    dic2.print();

    cout << "0번 영어: " << dic2.getEng(0) << endl;
    cout << "1번 한글: " << dic2.getKor(1) << endl;

    return 0;
}
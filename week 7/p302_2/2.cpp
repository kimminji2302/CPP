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

    // 단어 추가
    void add(string eng, string kor) {
        if (nWords >= MAXWORDS) {
            cout << "단어장 가득참" << endl;
            return;
        }

        words[nWords].eng = eng;
        words[nWords].kor = kor;
        nWords++;
    }

    // 파일에서 읽기
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

    // 파일에 저장
    void store(string filename) {
        ofstream fout(filename);

        for (int i = 0; i < nWords; i++) {
            fout << words[i].eng << " " << words[i].kor << endl;
        }

        fout.close();
    }

    // 출력
    void print() {
        cout << "===== 단어장 =====" << endl;

        for (int i = 0; i < nWords; i++) {
            cout << i << " : "
                 << words[i].eng << " - "
                 << words[i].kor << endl;
        }
    }

    // 영어 반환
    string getEng(int id) {
        if (id < 0 || id >= nWords) return "error";
        return words[id].eng;
    }

    // 한글 반환
    string getKor(int id) {
        if (id < 0 || id >= nWords) return "error";
        return words[id].kor;
    }
};

int main() {
    MyDic dic;

    dic.add("apple", "사과");
    dic.add("banana", "바나나");

    dic.print();

    return 0;
}
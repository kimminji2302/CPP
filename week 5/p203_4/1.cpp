#include <iostream>   // 입출력
#include <cstdlib>    // 랜덤 숫자 생성 함수 제공
#include <ctime>      // 시간(현재 시간 가져오기)
#include <fstream>    // 파일 저장, 읽기

#define MAX 5         // 최대 크기

struct Game {
    int s;                 // 퍼즐 크기
    char a[MAX][MAX];      // 퍼즐 배열
    char st[MAX][MAX];     // 시작 상태 저장
    int x,y;               // 빈칸 위치
    int cnt;               // 이동 횟수
    char log[1000];        // 이동 기록
    int k;                 // 기록 개수
};

// (1) 퍼즐 크기 확장 + (5) 문자 퍼즐

void init(Game &g,int n){
    g.s=n;                 // 퍼즐 크기 저장
    char c='A';            // 문자 시작

    for(int i=0;i<n;i++)   
        for(int j=0;j<n;j++) // 행, 열 반복
            if(i==n-1 && j==n-1)
                g.a[i][j]=' '; 
            else
                g.a[i][j]=c++; // 문자 채우기

    g.x=n-1; g.y=n-1;      // 빈칸 위치
    g.cnt=0; g.k=0;        // 초기화
}

// 출력 + 이동 (기본 기능)

void print(Game &g){
    for(int i=0;i<g.s;i++){
        for(int j=0;j<g.s;j++)
            std::cout<<g.a[i][j]<<" "; // 퍼즐 출력
        std::cout<<"\n";
    }
    std::cout<<"\n";
}

void move(Game &g,char d){
    int nx=g.x, ny=g.y;     // 현재 위치

    if(d=='w') nx--;        // 위
    if(d=='s') nx++;        // 아래
    if(d=='a') ny--;        // 왼쪽
    if(d=='d') ny++;        // 오른쪽

    if(nx>=0 && nx<g.s && ny>=0 && ny<g.s){ // 범위 체크
        char t=g.a[nx][ny]; // 이동 값
        g.a[nx][ny]=' ';
        g.a[g.x][g.y]=t;

        g.x=nx; g.y=ny;     // 위치 갱신
        g.log[g.k++]=d;     // 이동 기록 저장
        g.cnt++;            // 이동 횟수 증가
    }
}

// (2) 리플레이 기능

void replay(Game g){
    std::cout<<"리플레이\n";

    for(int i=0;i<g.s;i++)         // 시작 상태 복원
        for(int j=0;j<g.s;j++)
            g.a[i][j]=g.st[i][j];

    for(int i=0;i<g.k;i++){        // 기록 재생
        print(g);
        move(g,g.log[i]);
    }
    print(g);
}

// (3) 게임 저장

void save(Game &g){
    std::ofstream f("save.dat",std::ios::binary); // 이진 파일 열기
    f.write((char*)&g,sizeof(g));                 // 전체 저장
}

// (4) 이어하기 (불러오기)

int load(Game &g){
    std::ifstream f("save.dat",std::ios::binary); // 파일 열기
    if(!f) return 0;                              // 없으면 실패
    f.read((char*)&g,sizeof(g));                  // 그대로 읽기
    return 1;
}

// (6) 랭킹 저장

struct Rank{int m,t;};

void rankSave(int m,int t){
    Rank r[11]; int n=0;

    std::ifstream f("rank.dat",std::ios::binary); // 기존 데이터 읽기
    while(f.read((char*)&r[n],sizeof(Rank))) n++;

    r[n].m=m; r[n].t=t; n++; // 새 기록 추가

    for(int i=0;i<n-1;i++)   // 간단 정렬
        for(int j=i+1;j<n;j++)
            if(r[i].m>r[j].m){
                Rank tmp=r[i];
                r[i]=r[j];
                r[j]=tmp;
            }

    std::ofstream o("rank.dat",std::ios::binary); // 저장
    for(int i=0;i<n && i<10;i++)
        o.write((char*)&r[i],sizeof(Rank));
}

// 메인

int main(){
    Game g;
    srand(time(0)); // 랜덤 초기화

    int n;
    std::cout<<"1 새게임 2 이어하기: ";
    std::cin>>n;

    if(n==2 && load(g)); // 이어하기
    else{
        int s;
        std::cout<<"크기(3/5): ";
        std::cin>>s;

        init(g,s); // 퍼즐 생성

        for(int i=0;i<100;i++) // 섞기
            move(g,"wasd"[rand()%4]);

        for(int i=0;i<g.s;i++) // 시작 상태 저장
            for(int j=0;j<g.s;j++)
                g.st[i][j]=g.a[i][j];
    }

    char c;
    while(1){
        print(g);
        std::cout<<"w a s d / r 저장 / q 종료: ";
        std::cin>>c;

        if(c=='q') break;
        if(c=='r'){ save(g); break; }

        move(g,c);

        int ok=1; char ch='A';
        for(int i=0;i<g.s;i++)
            for(int j=0;j<g.s;j++)
                if(i==g.s-1 && j==g.s-1){
                    if(g.a[i][j]!=' ') ok=0;
                } else if(g.a[i][j]!=ch++) ok=0;

        if(ok){
            std::cout<<"완료\n";
            rankSave(g.cnt,0);
            replay(g);
            break;
        }
    }
}
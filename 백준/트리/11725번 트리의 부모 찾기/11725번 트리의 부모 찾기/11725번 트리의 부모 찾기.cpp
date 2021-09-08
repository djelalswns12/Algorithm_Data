// 9372번 상근이의 여행.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class node {
public:
    int ori;
    int des;
    node(int ori, int des) {
        this->ori = ori;
        this->des = des;
    }
};
class vertex {
public:
    int num;
    int par;
    vertex(int num, int par) {
        this->num = num;
        this->par = par;
    }
};
class nodes {
public:
    vector<node> edges;
    vector<priority_queue<int,vector<int>,greater<int>>> q;
    vector<vertex> vertexs;
    void Push(node n) {
        //n.ori 부모인덱스
        q.at(n.ori - 1).push(n.des);
        q.at(n.des - 1).push(n.ori);
        edges.push_back(n);
    }
    void Resize(int n) {
        q.resize(n);
        for (int i = 0; i < n; i++) {
            vertexs.push_back(vertex(i + 1, -1));
        }
    }
    void DFS2(vertex* one,int par) {
        if (one->par != -1) {
            return;
        }
        one->par = par;
        while (q.at((one->num) - 1).empty() == false) {
            DFS2(&vertexs.at(q.at((one->num) - 1).top()-1),one->num);
            q.at((one->num) - 1).pop();
        }
    }
    void DFS(vertex* one,int par) {
     
        if (one->par != -1) {
            return;
        }
        //cout << one->num << "\n";
        one->par = par;
        for (int i = 0; i < edges.size(); i++) {
            if (edges.at(i).des == one->num)
            {
                DFS(&vertexs.at(edges.at(i).ori - 1),one->num);
                continue;
            }
            if (edges.at(i).ori == one->num) {
                DFS(&vertexs.at(edges.at(i).des - 1),one->num);
                continue;
            }
        }
        return;
    }
    void qShow() {
        for (int i = 0; i < q.size(); i++) {
            while (q.at(i).empty() == false) {
                cout << q.at(i).top()<<"\t";
                q.at(i).pop();
            }
            cout << "\n\n";
        }
    }
};
int main()
{
    int N;
    int a,b;
    nodes one;
    cin >> N;
    one.Resize(N);
    for (int i = 1; i < N; i++) {
        cin >> a >> b;
        if (a < b) {
            one.Push(node(a, b));
        }
        else {
            one.Push(node(b,a));
        }
    }
    one.DFS2(&one.vertexs.at(0),1);

    for (int i = 1; i < one.vertexs.size(); i++) {
       cout << one.vertexs.at(i).par<<"\n";
       // cout << one.vertexs.at(i).num << ":" << one.vertexs.at(i).par<<"\n";
    }

}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

// 9372번 상근이의 여행.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;
class node {
public:
    int ori;
    int des;
    int par;
    node(int ori, int des) {
        this->ori = ori;
        this->des = des;
        par = 0;
    }
};
class nodes {
public:
    vector<node> list;
    vector<node> stack;
    int answer = 0;
    int MAX_NODE;
    void Push(node n) {
        list.push_back(n);
    }
    void DFS(node find) {
        stack.push_back(find);
        for (int i = 0; i < list.size(); i++) {
                if (SameNode(find, list.at(i)) == true) {
                    DFS(list.at(i));
                }
        }
    }
    void GetStack() {
        cout <<stack.size()<<"\n";
       /* for (int i = 0; i < stack.size(); i++) {
            cout <<"("<<stack.at(i).ori << "," << stack.at(i).des<<")\n";
        }*/
    }
    bool SameNode(node find,node one) {
        if (find.ori == one.ori) {
            if (InParent(one.des)) {
                return false;
            }
            return true;
        }
        if (find.ori == one.des) {
            if (InParent(one.ori)) {
                return false;
            }
            return true;
        }
        if (find.des == one.ori) {
            if (InParent(one.des)) {
                return false;
            }
            return true;
        }
        if (find.des == one.des) {
            if (InParent(one.ori)) {
                return false;
            }
            return true;
        }
        return false;
    }
    bool InParent(int one) {
        for (int j = 0; j < stack.size(); j++) {
                if (one == stack.at(j).ori || one == stack.at(j).des) {
                    return true;
                }
        }
        return false;
    }
};
int main()
{
    int T;
    int N, M;
    int a, b;
    cin >> T;
    nodes* list = new nodes[T];
    for (int i = 0; i < T; i++) {
        cin >> N >> M;
        list->MAX_NODE = N;
        for (int j = 0; j < M; j++) {
            cin >> a >> b;
            list[i].Push(node(a, b));
        }
    }
    for (int i = 0; i < T; i++) {
        list[i].DFS(list[i].list.at(0));
        list[i].GetStack();
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

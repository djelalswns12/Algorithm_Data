// 6416번 트리인가.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;
class tree {
public:

    bool isTree;
    map<int, int> list;
    set<int> nodes;
    vector<pair<int, int>> edge;
    vector<int> stack;
    tree() {
        isTree = true;
    }
    void Push(int u, int v) {
        list.insert(make_pair(u,u));
        list.insert(make_pair(v,v));
        edge.push_back(make_pair(u, v));
    }
    bool MakeTree() {
        for (auto item : edge) {
            if (list.at(item.second) == item.second) {
                if (list.at(item.second) != list.at(item.first)) {
                    list.at(item.second) = list.at(item.first);
                }
                else {
                    //cout << "오류1";
                    return false;
                }
                //바뀔놈이 부모인 모든아이를 탐색해서 바뀔값으로 설정
                for (auto i = list.begin(); i != list.end(); i++)
                {
                    if (i->second == item.second) {
                        i->second = list.at(item.second);
                    }
                }
            }
            else {
                //Tree 아님
                //cout << "오류2";
                return false;
            }
        }
        //루트 여부 확인
        int rootNum = list.begin()->second;
        for (auto i = list.begin(); i != list.end(); i++)
        {
            if (rootNum != i->second) {
                //cout << "오류3";
                return false;
            }
        }
        return true;
    }
};

int main()
{
    int u, v;
    bool end = false;
    vector<tree*> list;
    while (true) {
        if (end == true) {
            break;
        }
        tree* one = new tree();
        while (true) {
            cin >> u >> v;
            if (u == -1 && v == -1) {
                end = true;
                break;
            }
            if (u == 0 && v == 0) {
                list.push_back(one);
                break;
            }
            one->Push(u, v);
        }
    }
    int index = 1;
    for (auto item : list) {
        if (item->MakeTree() == true) {
            cout << "Case " << index << " is a tree." << "\n";
        }
        else {
            cout << "Case " << index << " is not a tree." << "\n";
        }
        index++;
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

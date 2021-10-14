// 2606번 바이러스.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <map>
#include <queue>
using namespace std;
map<int, priority_queue<int, vector<int>, greater<int>>> m;
vector<bool> visit;
vector<int> answer;
void dfs(int start) {
    if(start!=1)
    answer.push_back(start);

    visit.at(start) = true;
    while (!m.at(start).empty()) {
        int next = m.at(start).top();
        m.at(start).pop();
        if (!visit.at(next)) {
            dfs(next);
        }
    }
}
int main()
{
    int node, cnt, ori, des;
    cin >> node >> cnt;

    visit=vector<bool>(node + 1, false);
    for (int i = 0; i< node; i++) {
        m.insert(make_pair(i + 1, priority_queue<int, vector<int>, greater<int>>()));
    }

    for (int i = 0; i < cnt; i++) {
        cin >> ori >> des;
        m.at(ori).push(des);
        m.at(des).push(ori);
    }
    //dfs
    dfs(1);
    cout << answer.size();
}

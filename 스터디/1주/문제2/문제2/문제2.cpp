// 문제2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>

using namespace std;
priority_queue<int, vector<int>, less<int>> q;
vector<pair<int, int>> list;
void dfs(vector<bool> visit,int happy,int hp) {
    q.push(happy);
    for (int i = 0; i < list.size(); i++) {
        if (visit.at(i) == false) {
            visit.at(i) = true;
            if (hp - list.at(i).first > 0) {
                dfs(visit, happy + list.at(i).second, hp - list.at(i).first);
            }
            else {
                q.push(happy);
            }
        }
    }
}

int main()
{
    int cnt;
    int hp,happy;
    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        cin >> hp;
        list.push_back(make_pair(hp, 0));
    }
    for (int i = 0; i < cnt; i++) {
        cin >> happy;
        list.at(i).second = happy;
    }
    dfs(vector<bool>(list.size(), false),0,100);
    cout << q.top();
}

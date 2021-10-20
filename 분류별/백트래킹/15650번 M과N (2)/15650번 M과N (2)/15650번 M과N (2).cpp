// N과 M(1).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> ans;
vector<bool> visit;
vector<bool> lock;
void dfs(vector<int>& v, vector<bool>& visit, int size, vector<int>& answer, int start) {
    if (answer.size() >= size) {
        for (int d : answer) {
            cout << d << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = start; i < v.size(); i++) {
        if (visit.at(i) == false) {
            answer.push_back(v.at(i));
            visit.at(i) = true;
            dfs(v, visit, size, answer, i + 1);
            answer.pop_back();
            visit.at(i) = false;
        }
    }
}
int main()
{
    int N, M;
    vector<int> v;

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        v.push_back(i);
    }
    visit = vector<bool>(N, false);
    lock = vector<bool>(N, false);
    vector<int> answer;
    dfs(v, visit, M, answer, 0);
    for (auto v : ans) {
        for (int d : v) {
            cout << d << " ";
        }
        cout << "\n";
    }
}


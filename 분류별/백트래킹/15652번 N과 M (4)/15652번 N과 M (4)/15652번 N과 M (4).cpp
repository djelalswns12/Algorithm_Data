// 15651번 N과 M (3).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;
void dfs() {

}
vector<int> v;
vector<bool> visit;
void dfs(vector<int>& answer, int size, int start) {
    if (answer.size() >= size) {
        for (int d : answer) {
            cout << d << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = start; i < v.size(); i++) {
        answer.push_back(v.at(i));
        dfs(answer, size, i);
        answer.pop_back();
    }
}
int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        v.push_back(i);
        visit.push_back(false);
    }
    vector<int> answer;
    dfs(answer, M, 0);
}
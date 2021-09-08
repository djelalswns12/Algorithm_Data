// 1715번 카드 정렬하기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int main()
{
    priority_queue<int,vector<int>,greater<int>> q;
    int cnt;
    int num;
    int answer=0;
    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        cin >> num;
        q.push(num);
    }
    vector<int> stack;
    int f, s;
    while (q.size()>0) {
        stack.push_back(q.top());
        q.pop();
        if (stack.size() > 1) {
            f = stack.back();
            stack.pop_back();
            s = stack.back();
            stack.pop_back();
            answer += f + s;
            q.push(f + s);
        }
    }
    cout << answer;
}
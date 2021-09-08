// 1655번 가운데를 말해요.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int main()
{
    cin.tie(0);
    priority_queue<int,vector<int>,greater<int>> rightq;
    priority_queue<int> leftq;
    int cnt;
    int num;
    int sel=0;
    vector<int> answer;
    answer.reserve(10000);
    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        cin >> num;
        if (i == 0) {
            sel = num;
            answer.push_back(sel);
            continue;
        }
        if (num >= sel) {
            rightq.push(num);
            if (rightq.size() > leftq.size()+1) {
                leftq.push(sel);
                sel=rightq.top();

                rightq.pop();
            }
        }
        else {
            leftq.push(num);
            if (leftq.size() > rightq.size()) {
                rightq.push(sel);
                sel = leftq.top();
                leftq.pop();
            }

        }
        answer.push_back(sel);
    }
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << "\n";
    }
}
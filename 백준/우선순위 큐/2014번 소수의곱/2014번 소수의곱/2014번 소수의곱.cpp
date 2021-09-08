// 2014번 소수의곱.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
using namespace std;
int main()
{
    priority_queue<long long, vector<long long>, greater<>> answer;//
    priority_queue<long long, vector<long long>, less<>> real_answer;//
    priority_queue<long long, vector<long long>, greater<int>> min_q;//최소
    map<long long ,long long> m;
    set<long long > s;
    int K, N;
    int num;

    cin >> K >> N;
    vector<long long> list;
    
    for (int i = 0; i < K; i++) {
        cin >> num;
        min_q.push(num);
    }
    list.reserve(N);
   
    while (!min_q.empty()) {
        list.push_back(min_q.top());
        s.insert(min_q.top());
        min_q.pop();
    }
    long long num2;
    while (real_answer.size()<N) {
        for (int i = 0; i < list.size(); i++) {
            num2 = (*s.begin()) * list.at(i);
            s.insert(num2);
        }
        real_answer.push(*s.begin());
        s.erase(s.begin());
    }
    cout << real_answer.top();

 
}
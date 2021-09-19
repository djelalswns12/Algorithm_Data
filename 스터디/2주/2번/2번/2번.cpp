#include <iostream>
#include <queue>
#include <cmath>
#include <string>
#include <set>
#include <vector>
using namespace std;
vector<int> list;
set<double> s;
void solution(int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
           // cout << "i:"<<i<<"--"<<(j + 1) / (double)(i + 1)<<"\n";
            s.insert((j + 1) / (double)(i + 1));
        }
        list.push_back((s.size() * 2) + 3);
    }
}
int main()
{
    int cnt;
    cin >> cnt;

    vector<int> answer;
    int d;
    solution(1000);
    for (int i = 0; i < cnt; i++) {
        cin >> d;
        answer.push_back(list.at(d-1));
    }
    for (int d : answer) {
        cout << d << "\n";
    }
}


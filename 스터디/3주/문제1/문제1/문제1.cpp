// 문제1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> list;
vector<vector<long long>> visit;


void fast(int cnt) {
    int cal;
    for (int i = 0; i < list.size(); i++) {
        for (int j = 0; j < list.size(); j++) {
            if (visit.at(i).at(j) > 0) {
                if (i == cnt - 1 && j == cnt - 1)
                    break;
                cal = list.at(i).at(j);
                if (i + cal < cnt) {
                    visit.at(i + cal).at(j) += visit.at(i).at(j);
                }
                if (j + cal < cnt) {
                    visit.at(i).at(j + cal) += visit.at(i).at(j);
                }
            }
        }
    }
}
int main()
{
    int cnt,num;
    cin >> cnt;
    list = vector<vector<int>>(cnt);
    visit = vector<vector<long long>>(cnt,vector<long long>(cnt,0));
    visit.at(0).at(0) = 1;
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < cnt; j++) {
            cin >> num;
            list.at(i).push_back(num);
        }
    }
    fast(cnt);
    cout << visit.at(cnt-1).at(cnt-1);
}

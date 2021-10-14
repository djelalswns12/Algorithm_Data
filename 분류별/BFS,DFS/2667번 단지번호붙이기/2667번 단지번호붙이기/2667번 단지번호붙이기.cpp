// 2667번 단지번호붙이기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<vector<int>> v;
vector<vector<bool>> visit;

int main()
{
    int cnt;
    string s;
    cin >> cnt;
    vector<int> answer;
    v = vector<vector<int>>(cnt);
    for (int i = 0; i < cnt; i++) {
            cin >> s;
            for (int j = 0; j < s.length(); j++) {
                if(s.at(j)=='0')
                v.at(i).push_back(0);
                else
                v.at(i).push_back(1);
            }
    }
    visit = vector<vector<bool>>(cnt,vector<bool>(cnt,false));
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.at(i).size(); j++) {
            if (visit.at(i).at(j) == false) {
                if (v.at(i).at(j) == 1) {
                    //cout << i << "/" << j << "\n";
                    queue<pair<int, int>> q;
                    int size = 0;
                    q.push(make_pair(i, j));
                    visit.at(i).at(j) = true;
                    size++;
                    while (!q.empty()) {
                        int row;
                        int col;
                        for (int t = 0; t < 2; t++) {
                            row = q.front().first + (2 * t) - 1;
                            col = q.front().second;
                            if(row>=0 && row<cnt && col >= 0 && col < cnt){
                                if (visit.at(row).at(col) == false) {
                                    if (v.at(row).at(col) == 1) {
                                        visit.at(row).at(col) = true;
                                        q.push(make_pair(row, col));
                                        size++;
                                    }
                                }
                            }
                        }
                        for (int t = 0; t < 2; t++) {
                            row = q.front().first;
                            col = q.front().second + (2 * t) - 1;
                            if (row >= 0 && row < cnt && col >= 0 && col < cnt) {
                                if (visit.at(row).at(col) == false) {
                                    if (v.at(row).at(col) == 1) {
                                        visit.at(row).at(col) = true;
                                        q.push(make_pair(row, col));
                                        size++;
                                    }
                                }
                            }
                        }
                        //cout << q.front().first << "/" << q.front().second << "\n";
                        q.pop();
                    }
                    answer.push_back(size);
                }
            }
        }
    }
    cout << answer.size()<<"\n";
    sort(answer.begin(), answer.end());
    for (int n : answer) {
        cout << n << "\n";
    }
}

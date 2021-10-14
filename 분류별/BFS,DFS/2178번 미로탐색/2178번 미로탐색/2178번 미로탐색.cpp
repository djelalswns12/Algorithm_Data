// 2178번 미로탐색.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>> v;
vector<vector<bool>> visit;
vector<vector<pair<int,int>>> memo;
int main()
{
    int r, c;
    string s;
    cin >> r >> c;
    v = vector<vector<int>>(r, vector<int>(c, 0));
    visit = vector<vector<bool>>(r, vector<bool>(c, false));
    memo = vector<vector<pair<int,int>>>(r, vector<pair<int,int>>(c, pair<int,int>()));
    for (int i = 0; i < r; i++) {
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            if (s.at(j) == '1') {
                v.at(i).at(j) = 1;
            }
        }
    }
            if (v.at(0).at(0) == 1) {
                queue<pair<int,int>> q;
                q.push(make_pair(0, 0));
                visit.at(0).at(0) = true;
                memo.at(0).at(0) = q.front();
                while (!q.empty()) {
                    if (q.front().first == r - 1 && q.front().second == c - 1) {
                        break;
                    }
                    int row;
                    int col;
                    for (int t = 0; t < 2; t++) {
                        row = q.front().first+(2*t)-1;
                        col = q.front().second;
                        if (row >= 0 && row < r && col >= 0 && col < c) {
                            if (visit.at(row).at(col) == false) {
                                if (v.at(row).at(col) == 1) {
                                    visit.at(row).at(col) = true;
                                    q.push(make_pair(row, col));
                                    memo.at(row).at(col) = q.front();
                                }
                            }
                        }
                    }
                    for (int t = 0; t < 2; t++) {
                        row = q.front().first;
                        col = q.front().second + (2 * t) - 1;
                        if (row >= 0 && row < r && col >= 0 && col < c) {
                            if (visit.at(row).at(col) == false) {
                                if (v.at(row).at(col) == 1) {
                                    visit.at(row).at(col) = true;
                                    q.push(make_pair(row, col));
                                    memo.at(row).at(col) = q.front();
                                }
                            }
                        }
                    }
                    q.pop();
                }

            }


    int size = 0;
    auto pair = memo.at(r - 1).at(c - 1);
     while (pair.first != 0 || pair.second != 0) {
         //cout << pair.first << "/" << pair.second << "\n";
         pair = memo.at(pair.first).at(pair.second);
         size++;
     }
     cout << size+2;
}

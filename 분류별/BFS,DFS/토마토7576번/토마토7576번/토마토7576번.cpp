// 토마토7576번.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>> v;
vector<vector<bool>> visit;
int main()
{
    int r, c, num;
    cin >> c >> r;
    v = vector<vector<int>>(r, vector<int>(c));
    visit = vector<vector<bool>>(r, vector<bool>(c));
    queue<pair<int, int>> q;
    queue<pair<int, int>> tmp_q;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> num;
            v.at(i).at(j) = num;
            if (num == 1) {
                q.push(make_pair(i, j));
            }
        }
    }
    int time = 0;
    int end = 0;
    while (end==0) {
        while (!q.empty()) {
            //cout << q.front().first << "/" << q.front().second << "\n";
            int row = q.front().first;
            int col = q.front().second;
            visit.at(row).at(col) = true;
            int t_r, t_c;
            for (int k = 0; k < 2; k++) {
                t_r = row + (2 * k) - 1;
                t_c = col;
                if (t_r >= 0 && t_r < r && t_c >= 0 && t_c < c) {
                    if (v.at(t_r).at(t_c) == 0) {
                        if (visit.at(t_r).at(t_c) == false) {
                            v.at(t_r).at(t_c) = 1;
                            tmp_q.push(make_pair(t_r, t_c));
                        }
                    }
                }
            }
            for (int k = 0; k < 2; k++) {
                t_r = row;
                t_c = col + (2 * k) - 1;
                if (t_r >= 0 && t_r < r && t_c >= 0 && t_c < c) {
                    if (v.at(t_r).at(t_c) == 0) {
                        if (visit.at(t_r).at(t_c) == false) {
                            v.at(t_r).at(t_c) = 1;
                            tmp_q.push(make_pair(t_r, t_c));
                        }
                    }
                }
            }
            q.pop();
        }

        end = 1;
        while (!tmp_q.empty()) {
            end = 0;
            q.push(tmp_q.front());
            tmp_q.pop();
        }
        if (end == 0) {
            time++;
        }
    }
    int chk = true;
    for (auto d : v) {
        for (int n : d) {
            if (n == 0) {
                chk = false;
                break;
            }
        }
    }
    if (chk) {
        cout << time;
    }
    else cout << -1;
}

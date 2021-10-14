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
    int num, r, c, cnt,ori,des;
    cin >> num;
    vector<int> answer;
    vector<int> list;

    for (int w = 0; w < num; w++) {
        cin >> r >> c >> cnt;
        v = vector<vector<int>>(r, vector<int>(c, 0));
        visit = vector<vector<bool>>(r, vector<bool>(c, false));
        for (int e = 0; e < cnt; e++) {
            cin >> ori >> des;
            v.at(ori).at(des) = 1;
        }
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
                                if (row >= 0 && row < r && col >= 0 && col < c) {
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
                                if (row >= 0 && row < r && col >= 0 && col < c) {
                                    if (visit.at(row).at(col) == false) {
                                        if (v.at(row).at(col) == 1) {
                                            visit.at(row).at(col) = true;
                                            q.push(make_pair(row, col));
                                            size++;
                                        }
                                    }
                                }
                            }
                            //cout <<"------------" <<q.front().first << "/" << q.front().second << "\n";
                            q.pop();
                        }
                        answer.push_back(size);
                    }
                }
            }
        }
        list.push_back(answer.size());
        answer.clear();
    }
    for (int d : list) {
        cout << d<<"\n";
    }
}

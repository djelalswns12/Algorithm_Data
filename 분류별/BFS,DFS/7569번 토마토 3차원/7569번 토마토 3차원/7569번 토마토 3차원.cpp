
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class node {
public:
    int h;
    int r;
    int c;
    node(int h,int r,int c) {
        this->h = h;
        this->r = r;
        this->c = c;
    }
};
int main()
{
    int dr[] = { 1,0,-1,0 };
    int dc[] = { 0,1,0,-1 };
    int r, c, h,num;
    cin >> c >> r >> h;
    vector<vector<int>> v[101];
    vector<vector<bool>> visit[101];
    queue<node> q;
    queue<node> tmp_q;
    int time = 0;
    for (int i = 0; i < h; i++) {
        //높이
        visit[i] = vector<vector<bool>>(r, vector<bool>(c, false));
        v[i] = vector<vector<int>>(r, vector<int>(c, 0));
        for (int k = 0; k < r; k++) {
            //세로
            for (int j = 0; j < c; j++) {
                //가로
                cin >> num;
                v[i].at(k).at(j) = num;
                if (num == 1) {
                    q.push(node(i, k, j));
                }
            }
        }
    }
    while (true) {
        while (!q.empty()) {
            node t = q.front();
            visit[t.h].at(t.r).at(t.c) = true;
            //4방향
            for (int i = 0; i < 4; i++) {
                int row = t.r + dr[i];
                int col = t.c + dc[i];
                if (row >= 0 && row < r && col >= 0 && col < c) {
                    if (visit[t.h].at(row).at(col) == false) {
                        if (v[t.h].at(row).at(col) == 0) {
                            tmp_q.push(node(t.h, row, col));
                            v[t.h].at(row).at(col) = 1;
                            visit[t.h].at(row).at(col) = true;
                        }
                    }
                }
            }
            //위아래
            for (int k = 0; k < 2; k++) {
                if (t.h + (2 * k) - 1 < h && t.h + (2 * k) - 1 >= 0) {
                    if (visit[t.h + (2 * k) - 1].at(t.r).at(t.c) == false) {
                        if (v[t.h + (2 * k) - 1].at(t.r).at(t.c) == 0) {
                            tmp_q.push(node(t.h + (2 * k) - 1, t.r, t.c));
                            v[t.h + (2 * k) - 1].at(t.r).at(t.c) = 1;
                            visit[t.h + (2 * k) - 1].at(t.r).at(t.c) = true;
                        }
                    }
                }
            }
            q.pop();
        }
        if (tmp_q.empty()) {
            break;
        }
        else {
            time++;
            while (!tmp_q.empty()) {
                q.push(tmp_q.front());
                tmp_q.pop();
            }
        }
    }
    bool chk = true;
    for (int i = 0; i < h; i++) {
        //높이
        for (int k = 0; k < r; k++) {
            //세로
            for (int j = 0; j < c; j++) {
                //가로
                if (v[i].at(k).at(j) == 0) {
                    chk = false;
                    break;
                }
            }
        }
    }
    if (chk) {
        cout << time;
    }
    else {
        cout << -1;
    }
}

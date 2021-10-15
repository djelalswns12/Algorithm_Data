// 나이트의 이동.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	int dr[] = { 2,1,-1,-2,-2,-1, 1, 2 };
	int dc[] = { 1,2, 2, 1,-1,-2,-2,-1 };

	int t, size;
	pair<int, int> ori;
	pair<int, int> des;
	int r, c;

	cin >> t;
	vector<vector<int>> v;
	vector<vector<bool>> visit;
	vector<int> ans;
	for (int i = 0; i < t; i++) {

		cin >> size;
		visit = vector<vector<bool>>(size, vector<bool>(size, false));
		cin >> r >> c;
		ori = make_pair(r, c);
		cin >> r >> c;
		des = make_pair(r, c);

		queue<pair<pair<int,int>, int>> q;
		q.push(make_pair(make_pair(ori.first, ori.second),0));
		visit.at(ori.first).at(ori.second) = true;
		while (!q.empty()) {
			//cout << q.front().first.first << "/" << q.front().first.second << "\n";
			if (q.front().first.first == des.first && q.front().first.second == des.second) {
				ans.push_back(q.front().second);
				break;
			}
			for (int i = 0; i < 8; i++) {
				int row = q.front().first.first+dr[i];
				int col = q.front().first.second+dc[i];
				int time = q.front().second;
				if (row >= 0 && row < size && col >= 0 && col < size) {
					if (visit.at(row).at(col) == false) {
						q.push(make_pair(make_pair(row, col),time+1));
						visit.at(row).at(col) = true;
					}
				}
			}
			q.pop();
		}
	}
	for (int a : ans) {
		cout << a<<"\n";
	}
}


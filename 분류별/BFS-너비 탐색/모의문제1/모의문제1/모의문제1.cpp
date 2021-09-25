// 모의문제1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<vector<int>> list;
vector<vector<bool>> visit;
bool find(int i, int j) {
	if (visit.at(i).at(j) == false) {
		if (list.at(i).at(j) == 1) {
			visit.at(i).at(j) = true;
			return true;
		}
	}
	return false;
}
int bfs(int i, int j, int cnt) {
	int num = 0;
	int row, col;
	queue<pair<int, int>> q;
	if (list.at(i).at(j) == 1 && visit.at(i).at(j) == false) {
		q.push(make_pair(i, j));
		while (!q.empty()) {
			num++;
			visit.at(q.front().first).at(q.front().second) = true;
			for (int k = 0; k < 2; k++) {
				row = q.front().first + (2 * k) - 1;
				col = q.front().second;
				if (row >= 0 && row < cnt && col >= 0 && col < cnt) {
					if (find(row, col))q.push(make_pair(row, col));
				}
			}
			for (int k = 0; k < 2; k++) {
				row = q.front().first;
				col = q.front().second + (2 * k) - 1;
				if (row >= 0 && row < cnt && col >= 0 && col < cnt) {
					if (find(row, col))q.push(make_pair(row, col));
				}
			}
			q.pop();
		}
	}
	return num;
}

int main() {
	vector<int> answer;
	int cnt;
	int num;
	cin >> cnt;
	list = vector<vector<int>>(cnt);
	visit = vector<vector<bool>>(cnt, vector<bool>(cnt, false));
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			cin >> num;
			list.at(i).push_back(num);
		}
	}
	int size;
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			size = bfs(i, j, cnt);
			if (size > 0) {
				answer.push_back(size);
			}
		}
	}
	sort(answer.begin(), answer.end());
	cout << answer.size() << "\n";
	for (int a : answer) {
		cout << a << " ";
	}
}
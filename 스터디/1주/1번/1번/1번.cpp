#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<int>> list;
vector<bool> visit;
vector<int> chk;
int bfs(int idx, int N) {
	visit = vector<bool>(N + 1, false);
	int answer = 0;
	queue<int> q;
	q.push(idx);
	//cout << idx << "-size:" << list.at(q.front()).size() << "\n";
	while (!q.empty()) {
		visit.at(q.front()) = true;
		//cout << idx<<"idx is up\n";
		answer++;
		for (int i = 0; i < list.at(q.front()).size(); i++) {
			if (visit.at(list.at(q.front()).at(i)) == false) {
				visit.at(list.at(q.front()).at(i)) = true;
				q.push(list.at(q.front()).at(i));
				//cout << idx << "push" << list.at(q.front()).at(i)<<"\n";
			}
		}
		q.pop();
	}
	return answer;
}

struct cmp {
	bool operator()(pair<int, int>& n1, pair<int, int>& n2) {
		if (n1.first < n2.first) {
			return true;
		}
		else if (n1.first > n2.first) {
			return false;
		}
		else {
			if (n1.second > n2.second) {
				return true;
			}
			else {
				return false;
			}
		}
	}
};
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	int ori, des;
	cin >> N >> M;
	for (int i = 0; i <= N; i++) {
		list.push_back(vector<int>());
		visit.push_back(false);
	}
	for (int i = 0; i < M; i++) {
		cin >> des >> ori;
		list.at(ori).push_back(des);
	}
	vector<int> answer;
	int cnt = -1;
	for (int i = 1; i <= N; i++) {
		cnt = bfs(i, N);
		q.push(make_pair(cnt, i));
	}
	int max = -1;
	while (q.empty() == false) {
		if (q.top().first < max) {
			break;
		}
		max = q.top().first;
		cout << q.top().second << " ";
		q.pop();
	}
}
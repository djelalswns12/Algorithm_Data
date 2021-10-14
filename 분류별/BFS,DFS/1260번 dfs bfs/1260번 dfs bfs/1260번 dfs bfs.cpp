#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

#define maxsort(x) sort(x.begin(),x.end(),greater<int>()); // 내림차순
#define minsort(x) sort(x.begin(),x.end()); // 오름차순

using ll = long long;
using pqmax = priority_queue<int, vector<int>, less<int>>;//Top is MAX 내림차순
using pqmin = priority_queue<int, vector<int>, greater<int>>;//Top is MIN  오름차순
using mapmax = map<int, int, greater<int>>;//Top is MAX 내림차순
using mapmin = map<int, int, less<int>>;//Top is MIN 오름차순
using setmax = set<int, greater<int>>;//Top is MAX 내림차순
using setmin = set<int, less<int>>;//Top is MIN 오름차순


vector<string> split(string ids, string target) {
	vector<string> names;
	size_t cur, pre = 0;
	cur = ids.find(target);
	while (cur != string::npos) {
		string substring = ids.substr(pre, cur - pre);
		if (substring.length() > 0) {
			names.push_back(substring);
		}
		pre = cur + target.length();
		cur = ids.find(target, pre);
	}
	if (ids.substr(pre, cur - pre).length() > 0) {
		names.push_back(ids.substr(pre, cur - pre));
	}
	return names;
}
vector<bool> visit;
map<int, pqmin> m;
int cnt, edges, start;
vector<int> dfs_a;
vector<int> bfs_a;
void dfs(int num) {
	dfs_a.push_back(num);
	visit.at(num) = true;
	while (m.find(num)!=m.end()) {
		if (m.at(num).empty()) {
			break;
		}
		int top = m.at(num).top();
		m.at(num).pop();
		if (!visit.at(top)) {
			dfs(top);
		}
	}
}
void bfs(int num){
	queue<pair<int,pqmin>> q;
	q.push(make_pair(num, m.at(num)));
	visit.at(num) = true;
	while (!q.empty()) {
		while (!q.front().second.empty()) {
			if (!visit.at(q.front().second.top())) {
				q.push(make_pair(q.front().second.top(), m.at(q.front().second.top())));
				visit.at(q.front().second.top()) = true;
			}
			q.front().second.pop();
		}
		bfs_a.push_back(q.front().first);
		q.pop();
	}
}

int main()
{

	int ori, des;

	cin >> cnt >> edges >> start;
	for (int i = 1; i < cnt + 1; i++) {
		m.insert(make_pair(i, pqmin()));
	}
	for (int i = 0; i < edges; i++) {
		cin >> ori >> des;
			m.at(ori).push(des);
			m.at(des).push(ori);
	}

	visit = vector<bool>(cnt+1, false);
	//dfs
	bfs(start);

	visit = vector<bool>(cnt + 1, false);
	dfs(start);
	//bfs

	for (auto i : dfs_a) {
		cout << i << " ";
	}
	cout << "\n";
	for (auto i : bfs_a) {
		cout << i << " ";
	}
}


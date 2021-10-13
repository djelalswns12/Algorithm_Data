#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

#define maxsort(x) sort(x.begin(),x.end()); // 내림차순
#define minsort(x) sort(x.begin(),x.end(),greater<int>); // 오름차순

using ll = long long;
using pqmax = priority_queue<int, vector<int>, less<int>>;//Top is MAX
using pqmin = priority_queue<int, vector<int>, greater<int>>;//Top is MIN
using mapmax = map<int, int, greater<int>>;//Top is MAX
using mapmin = map<int, int, less<int>>;//Top is MIN
using setmax = set<int, greater<int>>;//Top is MAX
using setmin = set<int>;//Top is MIN


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
int num;
vector<vector<int>> list;
vector<vector<bool>> visit;
vector<pair<int, int>> answer;
bool dfs(int i, int j) {
	visit.at(i).at(j) = true;
	if (i == num - 1 && j == num - 1) {
		return true;
	}

	int row = i + 1;
	int col = j;
	if (row >= 0 && row < num) {
		if (list.at(row).at(col) == 0) {
			if (visit.at(row).at(col) == false) {
				if (dfs(row, col)) {
					answer.push_back(make_pair(row, col));
					return true;
				}
			}
		}
	}
	row = i;
	col = j + 1;
	if (col >= 0 && col < num) {
		if (list.at(row).at(col) == 0) {
			if (visit.at(row).at(col) == false) {
				if (dfs(row, col)) {
					answer.push_back(make_pair(row, col));
					return true;
				}
			}
		}
	}
	row = i - 1;
	col = j;
	if (row >= 0 && row < num) {
		if (list.at(row).at(col) == 0) {
			if (visit.at(row).at(col) == false) {
				if (dfs(row, col)) {
					answer.push_back(make_pair(row, col));
					return true;
				}
			}
		}
	}
	row = i;
	col = j - 1;
	if (col >= 0 && col < num) {
		if (list.at(row).at(col) == 0) {
			if (visit.at(row).at(col) == false) {
				if (dfs(row, col)) {
					answer.push_back(make_pair(row, col));
					return true;
				}
			}
		}
	}
	return false;
}
bool isIn(int i, int j, int time) {
	//cout << i << "/" << j << " __" << time << "/" << time % 4 << "\n";
	if (time % 4 == 0) {
		if (i < num / 2 && j < num / 2) {
			return false;
		}
	}
	if (time % 4 == 1) {
		if (i <num / 2 && j>(num / 2) + 1) {
			return false;
		}
	}
	if (time % 4 == 2) {
		if (i > (num / 2) + 1 && j > (num / 2) + 1) {
			return false;
		}
	}
	if (time % 4 == 3) {
		if (i > (num / 2) + 1 && j < (num / 2)) {
			return false;
		}
	}
	return true;
}
int main()
{
	cin >> num;
	list = vector<vector<int>>(num);
	visit = vector<vector<bool>>(num, vector<bool>(num, false));
	int cnt;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			cin >> cnt;
			list.at(i).push_back(cnt);
		}
	}
	dfs(0, 0);
	int time = -1;
	answer.push_back(make_pair(0, 0));
	//for (auto d : answer) {
	//	cout << d.first << "/" << d.second << "\n";
	//}
	while (!answer.empty()) {
		time++;
		int row = answer.back().first;
		int col = answer.back().second;
		if (!isIn(row, col, time)) {
			continue;
		}
		else {
			answer.pop_back();
		}
	}
	cout << time;
}

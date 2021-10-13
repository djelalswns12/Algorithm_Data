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
bool cmp(const pair<ll,ll> a, const pair<ll,ll> b) {
	if (a.first < b.first) {
		return true;
	}
	else if (a.first > b.first) {
		return false;
	}
	else {
		if (a.second < b.second) {
			return true;
		}
		else {
			return false;
		}
	}
}
int main()
{
	vector<pair<int, int>> v;
	int cnt, start, end;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> start>>end;
			v.push_back(make_pair(start, end));
	}
	int answer=0;
	queue<int> q;
	sort(v.begin(), v.end(),cmp);
	for (auto d : v) {
		if (!q.empty()) {
			if (q.front() <= d.first) {
				answer++;
				q.pop();
				q.push(d.second);
			}
			else {
				if (q.front() > d.second) {
					q.pop();
					q.push(d.second);
				}
			}
		}
		else {
			q.push(d.second);
		}
	}
	if (!q.empty()) {
		answer++;
	}
	cout << answer;
}


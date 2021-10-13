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
int main()
{
	int cnt, num;
	vector<int> money;
	vector<int> per;
	cin >> cnt;
	for (int i = 0; i < cnt - 1; i++) {
		cin >> num;
		per.push_back(num);
	}
	for (int i = 0; i < cnt; i++) {
		cin >> num;
		money.push_back(num);
	}
	ll answer = 0;
	ll dis = 0;
	int min = money.at(0);
	for (int i = 1; i < money.size(); i++) {
		dis += per.at(i - 1);
		if (min > money.at(i)|| i==money.size()-1) {
			answer += min * dis;
			min = money.at(i);
			dis = 0;
		}
	}
	cout << answer;
}
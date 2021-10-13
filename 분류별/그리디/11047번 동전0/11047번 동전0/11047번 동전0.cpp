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

//지문을 잘 파악했어야 했다.
//너무 어렵게 생각했었음
//지문에 보면 첫번째 단위는 1이고 이후 각각의 관계가 배수의 관계를 가지고 있었음
//반례로 생각했던 부분은 나오지 않는 경우였음 이 경우를 해결하려고 시간을 많이 썼음


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
	vector<int> list;
	int num, cnt,n;
	cin >> num >> cnt;
	for (int i = 0; i < num; i++) {
		cin >> n;
		list.push_back(n);
	}
	maxsort(list);
	int answer = 0;
		for (int i = 0; i < list.size(); i++) {
			if (cnt / list.at(i) > 0) {
				answer += (cnt / list.at(i));
				cnt -= (cnt / list.at(i)) * list.at(i);

			}
		}
	cout << answer;
}


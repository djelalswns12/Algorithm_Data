#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

#define maxsort(x) sort(x.begin(),x.end(),greater<int>()); // 내림차순
#define minsort(x) sort(x.begin(),x.end()); // 오름차순

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

int main()
{
	int cnt, k,num;
	vector<int> v;
	cin >> cnt >> k;
	for (int i= 0; i < cnt; i++) {
		cin >> num;
		v.push_back(num);
	}

	minsort(v);
	int index=-1;
	for (int i = 0; i < v.size()-1; i++) {
		index = i;
		int cal = v.at(i + 1) - v.at(i);
		int add = cal * (i + 1);
		if (k >= add) {
			v.at(i) += cal;
			k -= add;
		}
		else {
			v.at(i)+=k / (i + 1);
			break;
		}
	}
	cout << v.at(index);
	/*cout<<"\n"<<index<<"\n";
	for (int a : v) {
		cout << a<<"\t";
	}*/
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴

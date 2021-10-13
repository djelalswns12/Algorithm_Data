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
int main()
{
	
	int num,data;
	cin >> num;
	vector<int> v;
	int index;
	int max;
	int min_max;
	int tmp_max;
	for (int i = 0; i < num; i++) {
		if (i == 0) {
			tmp_max = -1000000001;
			max = -1000000001;
		}
		else {
			max = 1000000001;
		}
		
		for (int j = 0; j < num; j++) {
			cin >> data;
			if (i == 0) {
				if (data > max) {
					max = data;
				}
			}
			else {
				if (data > tmp_max) {
					v.push_back(data);
					if(data<max )
					max = data;
				}
			}
		}
		if (i == 0) {
			//cout << "push" << max << "\n";
			v.push_back(max);
		}
		tmp_max = max;
		
	}
	sort(v.begin(), v.end(),greater<int>());
	//for (auto a : v) {
	//	cout << a << "\t";
	//}
	cout << v.at(num - 1);
}


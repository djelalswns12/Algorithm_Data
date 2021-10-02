#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
using namespace std;
//1477번 휴게소 세우기
#define maxsort(x) sort(x.begin(),x.end(),greater<int>()); // 내림차순
#define minsort(x) sort(x.begin(),x.end()); // 오름차순

using ll = long long;
using pqmax = priority_queue<int, vector<int>, less<int>>;//Top is MAX
using pqmin = priority_queue<int, vector<int>, greater<int>>;//Top is MIN
using mapmax = map<int, int, greater<int>>;//Top is MAX
using mapmin = map<int, int, less<int>>;//Top is MIN
using setmax = set<int,greater<int>>;//Top is MAX
using setmin = set<int>;//Top is MIN

int main()
{
	
	int now_cnt, add_cnt, road;
	int num;
	vector<int> v;
	cin >> now_cnt >> add_cnt >> road;
	v.push_back(0);
	v.push_back(road);
	for (int i = 0; i < now_cnt; i++) {
		cin >> num;
		v.push_back(num);
	}
	minsort(v);
	int left = 0;
	int right = road;
	while (left <= right) {
	
		int mid = (left + right) / 2;
		int cur = 0;
		for (int i = 0; i < v.size()-1; i++) {
			int set = (v.at(i + 1) - v.at(i));
			cur += set / mid;
			if (set % mid == 0) {
				cur--;
			}	
		}
		if (cur <= add_cnt) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << left;
}

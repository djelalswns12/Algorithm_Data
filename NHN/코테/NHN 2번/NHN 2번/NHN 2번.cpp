// NHN 2번.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

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
	
	int N, K, M;//사람 , 최대 층 , 정원
	int ori, des;
	int now=0;
	cin >> N >> K >> M;
	vector<priority_queue<int, vector<int>, less<int>>> q(K+1);
	vector<int> box(K+1,0);
	for (int i = 0; i < N; i++) {
		cin >> ori >> des;
		q.at(ori).push(des);
	}
	for (int i = 1; i < K+1;i++) {
		//빈자리 있으면 가져오기
			while (!q.at(i).empty()) {
				if (now >= M) {
					break;
				}
				box.at(q.at(i).top())++;
				cout << "삽입" << q.at(i).top() << "\n";
				q.at(i).pop();
				now++;
			}
		//있는거 털기
			
			cout << "-------\n";
			for (int d : box) {
				cout << d<<"\n";
			}
			cout << "\n\n-----\n\n";
		now -= box.at(i);
		box.at(i) = 0;
		bool empty1 = true;
		for (int j = 1; j < q.size(); j++) {
			if (!q.at(j).empty()) {
				empty1 = false;
			}
		}
		for (int j = 1; j < q.size(); j++) {
			if (!q.at(j).empty()) {
				empty1 = false;
			}
		}
		if (empty1) {
			cout << "아웃\n";
			break;
		}
	}
}


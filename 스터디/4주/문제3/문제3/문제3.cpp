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
	ll cnt;
	ll need,num;
	ll max=0;
	vector<ll> lines;
	cin >> cnt >> need;
	for (int i = 0; i < cnt; i++) {
		cin >> num;
		lines.push_back(num);
		max += num;
	}
	ll left = 1;
	ll mid;
	ll right = max;
	while (left <= right) {
		//cout << left << "/"<<right<<"\n";
		ll cur=0;
		mid =(left + right) / 2;
		for (ll l : lines) {
			cur += l / mid;
		}
		if (cur < need) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << (left+right)/2<<"\n";

}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

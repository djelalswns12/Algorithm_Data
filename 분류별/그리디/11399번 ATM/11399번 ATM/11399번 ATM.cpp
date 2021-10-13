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
	vector<pair<int, int>> v;
	int cnt, num;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> num;
		v.push_back(make_pair(num,i+1));
	}
	sort(v.begin(), v.end());
	vector<int> answer;
	int n=0;
	answer.push_back(v.begin()->first);
	for (int i = 1; i < v.size(); i++) {
		answer.push_back(answer.at(i - 1) + v.at(i).first);
	}
	for (int d : answer) {
		n += d;
	}
	cout << n;
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

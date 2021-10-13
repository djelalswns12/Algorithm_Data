#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <bitset>
#include <cmath>

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
vector<int> list;
void orders(string order) {
	auto data = split(order, " ");
	if (data.at(0) == "1") {
		//cout << "\n" << "post strin1g:" << bitset<20>(list.at(atoi(data.at(1).c_str()) - 1)).to_string() << "\n";
		if (bitset<20>(list.at(atoi(data.at(1).c_str()) - 1)).to_string().at(20 - (atoi(data.at(2).c_str()))) == '0') {
			list.at(atoi(data.at(1).c_str()) - 1) += pow(2, (atoi(data.at(2).c_str()) - 1));
		}
		//cout << "\n" << "past strin1g:" << bitset<20>(list.at(atoi(data.at(1).c_str()) - 1)).to_string() << "\n";
	}
	if (data.at(0) == "2") {
		//cout << "\n" << "post strin2g:" << bitset<20>(list.at(atoi(data.at(1).c_str()) - 1)).to_string() << "\n";
		if (bitset<20>(list.at(atoi(data.at(1).c_str()) - 1)).to_string().at(20 - (atoi(data.at(2).c_str()))) == '1') {
			//cout << "삭제 됩니다" << pow(2, (atoi(data.at(2).c_str()) - 1)) << "만큼\n";
			list.at(atoi(data.at(1).c_str()) - 1) -= pow(2, (atoi(data.at(2).c_str()) - 1));
		}
		//cout << "\n" << "past strin2g:" << bitset<20>(list.at(atoi(data.at(1).c_str()) - 1)).to_string() << "\n";
	}
	if (data.at(0) == "3") {
		list.at(atoi(data.at(1).c_str()) - 1) <<= 1;
		if (list.at(atoi(data.at(1).c_str()) - 1) >= pow(2, 20)) {
			list.at(atoi(data.at(1).c_str()) - 1) -= pow(2, 20);
		}
		//cout << "\n" << "past strin3g:" << bitset<20>(list.at(atoi(data.at(1).c_str()) - 1)).to_string() << "\n";
	}
	if (data.at(0) == "4") {
		list.at(atoi(data.at(1).c_str()) - 1) >>= 1;
		//cout << "\n" << "past strin4g:" << bitset<20>(list.at(atoi(data.at(1).c_str()) - 1)).to_string() << "\n";
	}
}
int main()
{
	cout << 5<<":"<<bitset<8>((5))<<"\n";
	cout << ~5 << ":"<<bitset<8>((~5));
	setmax s;
	int n, m;
	string order;
	cin >> n >> m;
	list = vector<int>(n, 0);
	cin.ignore();

	for (int i = 0; i < m; i++) {
		getline(cin, order);
		orders(order);
	}
	for (int d : list) {
		s.insert(d);
		//cout << d << "/"<<bitset<20>(d)<<"\n";
	}

	cout << s.size();
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

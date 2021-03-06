// 1202번 보석도둑.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

//가방에는 하나만 넣을 수 있다.
//

#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <set>

using namespace std;

class stone {
public:
	long long weight;
	long long value;
	stone(){}
	stone(long long weight,long long value):weight(weight),value(value){}
};
class up {
public:
	bool operator()(stone p, stone q)
	{
		return p.weight > q.weight;
	}
};
class down {
public:
	bool operator()(stone p, stone q)
	{
		return p.value < q.value;
	}
};
int main()
{
	cin.tie(0);
	priority_queue<stone, vector<stone>, down> q; // 최대힙
	int stone_cnt;
	int bag_cnt;
	long long answer=0;
	long long weight,value;
	long long bag_size;
	cin >>stone_cnt >> bag_cnt;
	for (int i = 0; i < stone_cnt; i++) {
		cin >> weight >> value;
		q.push(stone(weight, value));
	}
	multiset<int> s;
	multiset<int>::iterator iter;
	for (int i = 0; i < bag_cnt; i++) {
		cin >> bag_size;
		s.insert(bag_size);
	}
	for (int i = 0;i< stone_cnt; i++) {
		iter = s.lower_bound(q.top().weight);
		if (iter != s.end()) {
			answer += q.top().value;
			s.erase(iter);
		}
		q.pop();
	}
	cout << answer;

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

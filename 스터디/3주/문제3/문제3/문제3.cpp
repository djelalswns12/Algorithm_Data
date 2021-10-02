
#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

//투포인터로 접근해야함

struct cmp
{
	bool operator()(int n1,int n2) {
		if (abs(n1) > abs(n2)) {
			return true;
		}
		else {
			return false;
		}
	}
};
//14921번 용액합성하기
int main()
{
	multiset<int> s;
	priority_queue<int, vector<int>,cmp> q;
	multiset<int, greater<>> s2;
	int cnt, num;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> num;
		s.insert(num);
		s2.insert(num);
	}
	int less;//내림차순
	int greeter;//오름차순
	for (auto ori = s.begin(); ori != s.end(); ori++) {
		auto iter = s.lower_bound(-(*ori));
		if (iter == s.end()) {
			iter--;
		}
		if (iter != ori) {
			//cout << "insert" << (*iter) << "/" << (*ori) << "\n";
			q.push((*iter) + (*ori));
		}
	}
	for (auto ori = s2.begin(); ori != s2.end(); ori++) {
		auto iter = s2.lower_bound(-(*ori));
		if (iter == s2.end()) {
			iter--;
		}
		if (iter != ori) {
			//cout << "insert" << (*iter) << "/" << (*ori) << "\n";
			q.push( (*iter) + (*ori));
		}
	}
	cout<<q.top();
}

// 11003번 최솟값 찾기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class node {
public:
	int value;
	int index;
	node(int value,int index) :index(index),value(value) {

	}
};
class cmp {
public:
	bool operator()(node n1,node n2) {
		return n1.value > n2.value;
	}
};
int main()
{
	int max_value = 2000000000;
	priority_queue<node, vector<node>,cmp> q;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int cnt;
	int num;
	int L;
	cin >> cnt >> L;
	vector<node> ori;
	vector<int> answer;
	ori.reserve(5000000);
	for (int i = 0; i < cnt; i++) {
		cin >> num;
		ori.push_back(node(num,i));
	}
	for (int i = 0; i < ori.size(); i++) {
		if (q.size() > 0) {
			if (ori.at(i).index - q.top().index >= L) {
				q.pop();
				i--;
				continue;
			}
		}
		q.push(ori.at(i));
		answer.push_back(q.top().value);
	}
	for (int i = 0; i < answer.size(); i++) {
		cout << answer.at(i)<<" ";
	}
}
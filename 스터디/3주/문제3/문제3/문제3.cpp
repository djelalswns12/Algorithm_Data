
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
	int now_cnt, add_cnt, road;
	int num;
	priority_queue<int, vector<int>> q;
	cin >> now_cnt >> add_cnt >> road;
	for (int i = 0; i < now_cnt; i++) {
		cin >> num;
		q.push(num);
	}
	int len=0;
	int max = q.top();
	q.pop();
	while (!q.empty()) {
		if (len <= max - q.top()) {
			len = max - q.top();
		}
		q.pop();
		max = q.top();
	}
}

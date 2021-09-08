

#include <iostream>
#include <vector>
#include <string>
/*
push_front X: 정수 X를 덱의 앞에 넣는다.
push_back X: 정수 X를 덱의 뒤에 넣는다.
pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 덱에 들어있는 정수의 개수를 출력한다.
empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/
using namespace std;

const int MAX_RANAGE = 10004;
int arr[MAX_RANAGE];
int main()
{
	int front = 0;
	int back = MAX_RANAGE - 1;
	int cnt;
	vector<int> answer;
	vector<int> num;
	string order;
	cin >> cnt;
	cin.ignore();
	for (int i = 0; i < cnt; i++) {
		getline(cin, order);
		if (order.find("push_front") != string::npos) {
			int point = stoi(order.substr(11, order.length()));
			num.push_back(point);
			continue;
		}
		if (order.find("push_back") != string::npos) {
			int point = stoi(order.substr(10, order.length()));
			num.insert(num.begin(), point);
			continue;
		}
		if (order.find("pop_front") != string::npos) {
			if (num.size() > 0) {
				answer.push_back(num[num.size() - 1]);
				num.pop_back();
			}
			else {
				answer.push_back(-1);
			}
			continue;
		}
		if (order.find("pop_back") != string::npos) {
			if (num.size() > 0) {
				answer.push_back(num[0]);
				num.erase(num.begin());
			}
			else {
				answer.push_back(-1);
			}
			continue;
		}
		if (order.find("size") != string::npos) {
			answer.push_back(num.size());
			continue;
		}
		if (order.find("empty") != string::npos) {
			if (num.size() > 0) {
				answer.push_back(0);
			}
			else {
				answer.push_back(1);
			}
			continue;
		}
		if (order.find("front") != string::npos) {
			if (num.size() > 0) {
				answer.push_back(num[num.size() - 1]);
			}
			else {
				answer.push_back(-1);
			}
			continue;
		}
		if (order.find("back") != string::npos) {
			if (num.size() > 0) {
				answer.push_back(num[0]);
				continue;
			}
			else {
				answer.push_back(-1);
			}
		}

	}

	for (auto item : answer) {
		cout << item << "\n";
	}
}
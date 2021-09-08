

#include <iostream>
#include <vector>
#include <string>
/*
첫 번째 원소를 뽑아낸다. 이 연산을 수행하면, 원래 큐의 원소가 a1, ..., ak이었던 것이 a2, ..., ak와 같이 된다.
왼쪽으로 한 칸 이동시킨다. 이 연산을 수행하면, a1, ..., ak가 a2, ..., ak, a1이 된다.
오른쪽으로 한 칸 이동시킨다. 이 연산을 수행하면, a1, ..., ak가 ak, a1, ..., ak-1이 된다.
*/
using namespace std;
int answer = 0;
void Left(vector<int>* deque) {
	deque->push_back(deque->front());
	deque->erase(deque->begin());
	answer++;
}
void Right(vector<int>* deque) {
	deque->insert(deque->begin(), deque->back());
	deque->pop_back();
	answer++;
}
void GetOne(vector<int>* deque, vector<int>* list) {
	for (int i = 0; i < list->size(); i++) {
		int front, back;
		for (front = 0; front < deque->size(); front++) {
			if (deque->at(front) == list->at(i)) {
				break;
			}
		}
		for (back=(deque->size())-1; back >=0; back--) {
			if (deque->at(back) == list->at(i)) {
				break;
			}
		}
		//cout << front << ":" << (deque->size()) - back<<"\n";
		if (front <= (deque->size())-back) {
			for (int k = 0; k < front; k++) {
				Left(deque);
			}
		}
		else {
			for (int k = 0; k < (deque->size()) - back; k++) {
				Right(deque);
			}
		}
		deque->erase(deque->begin());
		for (int k = 0; k < deque->size(); k++) {
			//cout<<deque->at(k)<<"\t";
		}
		//cout << "\n";
	}
}

int main()
{
	int cnt;
	int get_num;
	vector<int> deque;
	vector<int> list;
	cin >> cnt>>get_num;
	for (int i = 0; i < cnt; i++) {
		deque.push_back(i+1);
	}
	for (int j = 0; j < get_num; j++) {
		int num;
		cin >> num;
		list.push_back(num);
	}

	GetOne(&deque, &list);
	cout << answer;
}
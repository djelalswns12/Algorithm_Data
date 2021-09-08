// 5430번 c++.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Deques {
public:
	vector<int> deque;
	int range;
	int front;
	int back;
	string order;
	bool flag = true;
	Deques() {
		front = 0;
		back = 0;
		range = 0;
	}
	Deques(int size,string data,string order) {
		this->order = order;
		front = 0;
		back = 0;
		range = size+1;
		deque.resize(range);
		data = data.substr(1, data.length()-2);
		int cur=data.find(",");
		int pre = 0;
		while (cur != string::npos) {
			string num = data.substr(pre, cur-pre);
			push_front(stoi(num));
			pre = cur + 1;
			cur = data.find(",", pre);
		}
		if (data.length() > 0) {
			string num = data.substr(pre, data.length());
			push_front(stoi(num));
		}
	}

	void push_front(int num) {
		front--;
		if (front < 0) {
			front = range - 1;
		}
		deque[front] = num;
	}
	void push_back(int num) {
		deque[back] = num;
		back++;
		if (back > range - 1) {
			back = 0;
		}
	}
	int pop_front() {
		if (back == front) {
			return -1;
		}
		int num = deque[front];
		front++;
		if (front > range - 1) {
			front = 0;
		}
		return num;
	}
	int pop_back() {
		if (back == front) {
			return -1;
		}
		back--;
		if (back < 0) {
			back = range - 1;
		}
		return deque[back];
	}
	void cal() {
		for (int i = 0; i < order.length(); i++) {
			if (order[i]=='R') {
				flag = !flag;
			}
			if (order[i] == 'D') {
				if (flag == true) {
					int num=pop_back();
					if (num == -1) {
						cout << "error";
						return;
					}
				}
				else {
					int num=pop_front();
					if (num == -1) {
						cout << "error";
						return;
					}
				}
			}
		}
		print_deque();
	}
	void print_deque() {
		cout << "[";
		int index = 0;
		int num = 0;
		while (true) {
			if (flag == true) {
				num = pop_back();
			}
			else {
				num = pop_front();
			}
			if (num == -1) {
				break;
			}
			else {
				if(index!=0)
				cout << ",";
			}
			cout << num;


			index++;
		}
		cout << "]";
	}
};


int main()
{
	int cnt;
	int size;
	string order;
	string list;
	
	cin >> cnt;
	vector<Deques> queue;
	for (int i = 0; i < cnt; i++) {
		cin >> order;
		cin >> size;
		cin >> list;
		Deques one = Deques(size, list,order);
		queue.push_back(one);
	}
	for (auto item : queue) {
	item.cal();
	cout << "\n";
	}
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

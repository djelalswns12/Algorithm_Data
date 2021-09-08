// 10845번 큐.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

/*
push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/
#define MAX_SIZE 2000001
int arr[MAX_SIZE] = { 0, };
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> all_answers;
	string new_word;
	int front=0, back=0;
	int my_size,cnt=0,push_num;
	cin >> my_size;
	while (cnt++ < my_size) {
		cin >> new_word;
		if (new_word=="push") {
			//atoi(new_word.substr(5, new_word.length()).c_str());
			cin >> push_num;
			arr[back++] = push_num;
		}
		if (new_word=="pop") {
			if (front<back) {
				all_answers.push_back(arr[front++]);
			}
			else {
				all_answers.push_back(-1);
			}
		}
		if (new_word == "size" ) {
			all_answers.push_back(back-front);
		}
		if (new_word == "empty" ) {
			if (back - front > 0) {
				all_answers.push_back(0);
			}
			else {
				all_answers.push_back(1);
			}
		}
		if (new_word == "front") {
			if (front<back) {
				all_answers.push_back(arr[front]);
			}
			else {
				all_answers.push_back(-1);
			}
		}
		if (new_word == "back" ) {
			if (front < back) {
				all_answers.push_back(arr[back-1]);
			}
			else {
				all_answers.push_back(-1);
			}
		}
	}
	for (int i = 0; i < all_answers.size();i++) {
		cout << all_answers.at(i) << "\n";
	}
}
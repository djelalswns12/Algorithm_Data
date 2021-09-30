// 문제2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
string list;
string ori;
vector<string> orders;
void swap(string* s, int i, int j) {
	char c = s->at(i);
	s->at(i) = s->at(j);
	s->at(j) = c;
}
string cal(string txt, string order) {
	for (int i = 0; i < order.length(); i++) {
		if (order.at(i) == '-') {
			//cout << i <<"/"<<order<< "\n";
			swap(&txt, i, i + 1);
		}
	}
	return txt;
}
int main()
{
	int cnt;
	int line;
	string order;

	cin >> cnt >> line;
	cin.ignore();
	getline(cin, list);
	ori = list;
	sort(ori.begin(), ori.end());
	int find_index = 0;
	for (int i = 0; i < line; i++) {
		getline(cin, order);
		if (order.at(0) == '?') {
			find_index = i;
		}
		orders.push_back(order);
	}
	string up_data;
	string down_data;

	string data = ori;
	for (int i = 0; i < find_index; i++) {
		data = cal(data, orders.at(i));
	}
	up_data = data;
	data = list;
	for (int i = line - 1; i >= find_index+1; i--) {
		data = cal(data, orders.at(i));
	}
	down_data = data;
	//cout << up_data << "\n"<<down_data;

	bool isCheck = true;
	string answers;
	for (int i = 0; i < up_data.length() - 1; i++) {
		if (up_data[i] == down_data[i]) {
			answers += "*";
		}
		else if(up_data[i] == down_data[i + 1]) {
			answers += "-";
			if (i != up_data.length() - 2) {
				answers += "*";
			}
			i++;
		}
		else {

			isCheck = false;
			break;
		}
	}
	if (!isCheck) {
		answers = "";
		for (int i = 0; i < cnt - 1; i++) {
			answers += 'x';
		}
	}
	cout << answers;
}
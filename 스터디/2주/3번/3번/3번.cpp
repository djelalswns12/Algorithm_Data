#include <iostream>
#include <queue>
#include <cmath>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int N, H,obj;

	cin >> N >> H;
	vector<int> down(H+1,0);
	vector<int> up(H+1,0);
	int index = 1;
	for (int i = 0; i < N; i++) {
		cin >> obj;
		if (index == 1) {
			down.at(obj) += 1;
		}
		else {
			up.at(obj) += 1;
		}
		index *= -1;
	}
	for (int i = down.size() - 1; i > 0; i--) {
		if (i + 1 < down.size()) {
			down.at(i) += down.at(i + 1);
	
		}
		//cout << i << "층" << down.at(i) << "\n";
	}
	for (int i = up.size() - 1; i > 0; i--) {
		if (i + 1 < up.size()) {
			up.at(i) += up.at(i + 1);
		}
		//cout << i << "층" << up.at(i) << "\n";
	}
	priority_queue<int, vector<int>, greater<int>> q; 
	for (int i = 1; i <= H; i++) {
		q.push(down.at(i) + up.at(H + 1 - i));
	}
	int cnt = 0;
	int min = q.top();
	while (!q.empty()) {
		if (min != q.top()) {
			break;
		}
		cnt++;
		q.pop();
	}
	cout << min << " " << cnt;
}


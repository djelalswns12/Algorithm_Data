// 모의문제1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> list;
vector<vector<bool>> visit;
int dfs(int i,int j,int cnt) {
	int num = 1;
	if (list.at(i).at(j)==0) {
		return 0;
	}
	if (visit.at(i).at(j) == true) {
		return 0;
	}
	visit.at(i).at(j) = true;
	//상하좌우로 돌리기
	if (i - 1 > 0) {
		if (list.at(i - 1).at(j) == 1) {
			num += dfs(i - 1, j, cnt);
		}
	}

	if (i + 1 < cnt) {
		if (list.at(i + 1).at(j) == 1) {
			num += dfs(i + 1, j, cnt);
		}
	}

	if (j - 1 > 0) {
		if (list.at(i).at(j-1) == 1) {
			num+=dfs(i , j-1, cnt);
		}
	}

	if (j + 1 < cnt) {
		if (list.at(i).at(j+1) == 1) {
			num += dfs(i, j + 1, cnt);
		}
	}
	return num;
}

int main() {
	vector<int> answer;
	int cnt;
	int num;
	cin >> cnt;
	list = vector<vector<int>>(cnt);
	visit = vector<vector<bool>>(cnt,vector<bool>(cnt,false));
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			cin >> num;
			list.at(i).push_back(num);
		}
	}
	int size;
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			size = dfs(i, j, cnt);
			if (size>0) {
				answer.push_back(size);
			}
		}
	}
	sort(answer.begin(), answer.end());
	cout << answer.size() << "\n";
	for (int a : answer) {
		cout << a<<" ";
	}
}
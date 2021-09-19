#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> arr;
int n, m;
int answer;
bool dfs(int i,int j) {
	if (j+1 == m) {
		answer++;
		return true;
	}
	for (int t = -1; t <= 1; t++) {
		if (i + t >= 0 && i + t < arr.size()) {
			if (arr.at(i + t).at(j + 1) == 1) {
				arr.at(i + t).at(j + 1) = 2;
				if (dfs(i + t, j + 1) == true) {
					return true;
				}
			}
		}
	}
	return false;
}
void solution(int n, int m) {
	string s="";
	arr = vector<vector<int>>(n);
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
				if (s.at(j) == '.') {
					arr.at(i).push_back(1);
				}
				else {
					arr.at(i).push_back(2);
				}
		}
	}
	for (int i = 0; i < n; i++) {
		dfs(i, 0);
	}
}
int main()
{
	cin >> n >> m;
		answer = 0;
		solution(n, m);
		cout << answer;
}

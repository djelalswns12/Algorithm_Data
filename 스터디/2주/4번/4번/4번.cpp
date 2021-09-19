#include <iostream>
#include <queue>
#include <cmath>
#include <string>
#include <map>
#include <vector>
using namespace std;
vector<vector<int>> arr;
vector<vector<bool>> visit;
vector<vector<bool>> visit_t;
bool dfs(int pi,int pj,int i,int j) {
	//cout << i << "-" << j << "\n";
	if (visit.at(i).at(j) == true) {
		return false;
	}
	visit.at(i).at(j) = true;

	if (arr.at(i - 1).at(j) <= 0) {
		if (i - 1 != pi || j != pj) {
			if (visit.at(i - 1).at(j) == false) {
				arr.at(i).at(j) -= 1;
				//cout << pi << "/" << pj << "/" << i << "/" << j << " >>> - 1 위 됨\n";
			}
		}
	}
	if (arr.at(i + 1).at(j) <= 0) {
		if (i + 1 != pi || j != pj) {
			if (visit.at(i +1).at(j) == false) {
				arr.at(i).at(j) -= 1;
				//cout << pi << "/" << pj << "/" << i << "/" << j << " >>> - 1 아래 됨\n";
			}
		}
	}

	if (arr.at(i).at(j - 1) <= 0) {
		if (i != pi || j - 1 != pj) {
			if (visit.at(i).at(j-1) == false) {
				arr.at(i).at(j) -= 1;

				//cout << pi << "/" << pj << "/" << i << "/" << j << " >>> - 1 왼 됨\n";
			}

		}
	}

	if (arr.at(i).at(j + 1) <= 0) {
		if (i != pi || j + 1 != pj) {
			if (visit.at(i).at(j+1) == false) {
				arr.at(i).at(j) -= 1;
				//cout << pi << "/" << pj << "/" << i << "/" << j << " >>> - 1 우 됨\n";
			}
		}
	}
	if (arr.at(i).at(j) < 0) {
		arr.at(i).at(j) = 0;
	}
	if(arr.at(i - 1).at(j)<=0){
	}
	else {
		if (visit.at(i - 1).at(j) == false) {
			//visit.at(i - 1).at(j) = true;
			dfs(i,j,i - 1, j);
		}
	}

	if (arr.at(i + 1).at(j) <= 0) {
	}
	else {
		if (visit.at(i + 1).at(j) == false) {
			//visit.at(i + 1).at(j) = true;
			dfs(i,j,i + 1, j);
		}
	}
	if (arr.at(i ).at(j-1) <= 0) {
	}
	else {
		if (visit.at(i).at(j - 1) == false) {
			//visit.at(i).at(j - 1) = true;
			dfs(i,j,i, j - 1);
		}
	}

	if (arr.at(i ).at(j+1) <= 0) {
	}
	else {
		if (visit.at(i).at(j + 1) == false) {
			//visit.at(i).at(j + 1) = true;
			dfs(i,j,i, j + 1);
		}
	}

	//

	return true;
}
int main()
{
	int N, M,num;
	cin >> N >> M;
	arr=vector<vector<int>>(N, vector<int>(M));
	visit=vector<vector<bool>>(N, vector<bool>(M,false));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> num;
			arr.at(i).at(j) = num;
		}
	}
	int isChk = 0;
	int answer = 0;
	bool chk = false;
	while (isChk <= 1) {
		answer++;
		isChk = 0;
		visit = vector<vector<bool>>(N, vector<bool>(M, false));
		chk = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr.at(i).at(j) > 0) {
					chk = true;
					if (dfs(i,j,i, j) == true) {
						isChk++;
						if (isChk > 1) {
							break;
						}
					}
				}
			}
		}
		if (chk == false) {
			answer = 1;
			break;
		}
	}
	cout << answer - 1;
}


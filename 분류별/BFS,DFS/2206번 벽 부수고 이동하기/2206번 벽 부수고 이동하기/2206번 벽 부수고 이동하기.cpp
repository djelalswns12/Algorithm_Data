// 2206번 벽 부수고 이동하기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int N, M, num;
class node {
public:
	int time;
	int r;
	int c;
	int point;
	bool wall;
	node(int time, int r, int c, bool wall,int point) :time(time), r(r), c(c), wall(wall),point(point) {
	}
};

int main()
{
	int dr[] = { 1,0,-1,0 };
	int dc[] = { 0,1,0,-1 };
	queue<node> q;
	string s;
	cin >> N >> M;
	int cnt=0;
	vector<vector<int>> v = vector<vector<int>>(N, vector<int>(M, 0));
	vector<vector<bool>> visit[2];
	visit[0]=vector<vector<bool>>(N, vector<bool>(M, false));
	visit[1]=vector<vector<bool>>(N, vector<bool>(M, false));
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int w = 0; w < s.length(); w++) {
			if (s.at(w) == '1') {
				v[i].at(w) = 1;
				cnt++;
			}
		}
	}
	//vector<vector<bool>>(N, vector<bool>(M, false));
	q.push( node(1, 0, 0, false, 0));
	visit[q.front().point].at(0).at(0) = true;
	bool end = false;
	while (!q.empty()) {
		if (q.front().r == N - 1 && q.front().c == M - 1) {
			end = true;
			cout << q.front().time;
			break;
		}
		//cout << q.front().time<<"초 "<<q.front().r << "," << q.front().c <<" 벽:"<<q.front().wall<<"\n";
		for (int i = 0; i < 4; i++) {
			int row = q.front().r + dr[i];
			int col = q.front().c + dc[i];
			if (row >= 0 && row < N && col >= 0 && col < M) {
				if (v.at(row).at(col) == 0 || q.front().wall == false) {
					if (visit[q.front().point].at(row).at(col) == false) {
						if (row == N - 1 && col == M - 1) {
							end = true;
							cout << q.front().time+1;
							break;
						}
						visit[q.front().point].at(row).at(col) = true;
						if (v.at(row).at(col) == 1) {
							q.push(node(q.front().time + 1, row, col, true, 1));
						}
						else {
							q.push(node(q.front().time + 1, row, col, q.front().wall, q.front().point));
						}
					}
				}
			}
		}
		q.pop();
		if (end)break;
	}
	if (!end)cout << -1;
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

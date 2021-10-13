// NHN 1번 문제.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int> list;
void find(int num) {
	sort(list.begin(), list.end(),greater<int>());
	int left = 1;
	int right = num;
	while (left <= right) {
		int mid = (right + left) / 2;
		int cur = 0;
		for (int i = 0; i < list.size(); i++) {
			cur += list.at(i) / mid;
		}
		if (cur < N) {
			//범위를 늘려 , 칼을 작게 만들기
			right = mid - 1;
		}
		else {
			//범위를 줄여 , 칼을 크게 만들기 , 갯수가 같은 상태에서는 칼을 작게 만들면 무조건 커지기 때문에 칼을 크게 만들어야함
			left = mid + 1;
		}
	}
	cout << left;
}
int main()
{
	int max=0;
	cin >> N>>M;
	int num;
		for (int i = 0; i < M; i++) {
			cin >> num;
				list.push_back(num);
				max += num;
		}
		find(max);
}


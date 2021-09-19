//
//#include <iostream>
//using namespace std;
//int main()
//{
//	unsigned long long answer=0;
//	unsigned long long N;
//	cin >> N;
//	unsigned long long tmp=0, real=0;
//	while (N > 0) {
//		tmp = answer;
//		if (real == 0) {
//			//실버퍼 없다면
//			//예상버퍼로 분기
//			if (tmp >= 3) {
//				if (answer >= 3) {
//					//체력3이상 유무로 분기
//					if (N >= 3) {
//						//모두읽기, 복사 ,붙여 넣기 , 단 
//				
//						real = tmp;
//						answer += real;
//						N -= 3;
//						cout << " TCV1(" << answer << ") ";
//					}
//					else {
//
//						answer++;
//						N--;
//						cout << " A(" << answer << ") ";
//						//그냥 붙이기
//					}
//				}
//			}
//			else {
//				answer++;
//				N--;
//				cout << " A(" << answer << ") ";
//				//그냥 붙이기
//			}
//		}
//		else {
//			//실버퍼 있다면
//			//예상버퍼로 분기
//			if (real * 3 <= tmp && N>=3) {
//				//모두읽기, 복사 ,붙여 넣기
//				
//				real = tmp;
//				answer += real;
//				N -= 3;
//				cout << " TCV2(" << answer << ") ";
//			}
//			else {
//				answer += real;
//				N--;
//				cout << " V(" << answer << ") ";
//			}
//		}
//	}
//	cout << answer;
//}
//
///*
//
//1번을 눌리는 경우는 2개보다 작을때
//
//
//*/
#include <cstdio>
#include <iostream>

using namespace std;

long long d[101];

int Max(int x, int y) {
    if (x < y) return y;
    else return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    d[0] = 0;
    for (int i = 1; i <= n; i++) {
        d[i] = d[i - 1] + 1;
        cout << i<<": ";
        for (int j = 3; j <= i; j++) {
            cout << j;
			if (d[i] < d[i - j] * (j - 1)) {
                cout << "ok";
				d[i] = d[i - j] * (j - 1);
			}
            cout << "\t";
        }
        cout << "\n";
    }
    printf("%lld\n", d[n]);
}
#include <iostream>
#include <vector>
using namespace std;


int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int start=1, end=1;
    for (int i : stations) {
        end = (i - w)-1;
        if (start <= end) {
            //cout << start << "/" << end << "\n";
            answer += ceil((double)(end - start + 1) / (w*2+1));
        }
        start = (i + w)+1;
    }
    if (start <= n) {
        //cout << start << "/" << n << "\n";
        answer += ceil((double)(n - start + 1) / (w*2+1));
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.

    return answer;
}
int main()
{
    vector<int> st;
    st.push_back(9);
    cout<<solution(16,st, 2);
}


/*
N개의 아파트가 일렬로 쭉 늘어서 있습니다. 이 중에서 일부 아파트 옥상에는 4g 기지국이 설치되어 있습니다. 기술이 발전해 5g 수요가 높아져 4g 기지국을 5g 기지국으로 바꾸려 합니다. 그런데 5g 기지국은 4g 기지국보다 전달 범위가 좁아, 4g 기지국을 5g 기지국으로 바꾸면 어떤 아파트에는 전파가 도달하지 않습니다.

예를 들어 11개의 아파트가 쭉 늘어서 있고, [4, 11] 번째 아파트 옥상에는 4g 기지국이 설치되어 있습니다. 만약 이 4g 기지국이 전파 도달 거리가 1인 5g 기지국으로 바뀔 경우 모든 아파트에 전파를 전달할 수 없습니다. (전파의 도달 거리가 W일 땐, 기지국이 설치된 아파트를 기준으로 전파를 양쪽으로 W만큼 전달할 수 있습니다.)

*/

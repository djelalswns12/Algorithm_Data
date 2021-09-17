
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int solution(int n) {
    int answer = 0;
    vector<int> list;
    //3진수로 변환
    while ( n >0) {
        list.push_back(n % 3);
        n /= 3;
    }
    int index = 0;
    for (auto i : list) {

        answer+=i*pow(3, (list.size() - 1)-index);
        index++;
    }

    //뒤집기


    //10진수로 변환
    
    return answer;
}
int main()
{
    
    int n;
    cin >> n;
    cout<<solution(n);
}

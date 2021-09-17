#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> sort;
    for(int item:people){
        sort.push(item);
    }
    vector<int> list;
    while (sort.empty() == false) {
        list.push_back(sort.top());
        sort.pop();
    }
    int index=list.size() - 1;
    for (int i = 0; i < list.size(); i++) {

        for (int j = index; j >= i; j--) {
            answer++;
            index--;
            if (list.at(i) + list.at(j) <= limit) {
                break;
            }
        }
    }

    return answer;
}
int main()
{
    vector<int> list;
    int n,limit;
    cin >> limit;
    while (cin >> n) {
        if (n == EOF)
            break;
         list.push_back(n);
  }
    cout<<solution(list, limit);
}

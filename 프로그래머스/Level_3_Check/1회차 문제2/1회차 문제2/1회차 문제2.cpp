
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct cmp {
    bool operator()(vector<int> &n1, vector<int> &n2) {
        if (n1.at(0) == n2.at(0)) {
            if (n1.at(1) > n2.at(1))
                return true;
            else
                return false;
        }
        else {
            if (n1.at(0) > n2.at(0))
                return true;
            else
                return false;
        }
    }
};
struct cmp2 {
    bool operator()(vector<int>& n1, vector<int>& n2) {
        if (n1.at(1) > n2.at(1))
            return true;
        else
            return false;
    }
};
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0;
    vector<int> an;
    priority_queue<vector<int>, vector<vector<int>>, cmp> q;
    priority_queue<vector<int>, vector<vector<int>>, cmp2> answer_q;
    for (auto i : jobs) {
        q.push(i);
    }
    //첫 태스크를 처리한다.
    answer_q.push(q.top());
    q.pop();
    time = answer_q.top().at(1)+answer_q.top().at(0);
    an.push_back(answer_q.top().at(1));
    answer_q.pop();

    //이후 태스크의 순서로 정렬한다
    while (q.empty() == false) {
        while (q.empty() == false) {
            if (q.top().at(0) <= time) {
                answer_q.push(q.top());
                q.pop();
            }
            else {
                break;
            }
        }
        if (answer_q.empty() == false) {
            an.push_back((answer_q.top().at(1) + time) - answer_q.top().at(0));
            time += answer_q.top().at(1);
            answer_q.pop();
        }
        else {
            time = q.top().at(0);
        }
    }

    //모든 태스크의 처리순서가 정해졌다면 그냥 차례대로 처리한다.
    while (answer_q.empty() == false) {
        an.push_back((answer_q.top().at(1) + time) - answer_q.top().at(0));
        time += answer_q.top().at(1);
        answer_q.pop();
    }
    for (auto i : an) {
        answer += i;
    }
    return answer/jobs.size();
}
int main()
{
    vector<vector<int>> jobs;
    vector<int> n;
    int cnt;
    int start, tasking;
    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        cin >> start >> tasking;
        n.push_back(start);
        n.push_back(tasking);
        jobs.push_back(n);
        n.clear();
    }
    cout<<solution(jobs);
}

/*
하드디스크는 한 번에 하나의 작업만 수행할 수 있습니다. 디스크 컨트롤러를 구현하는 방법은 여러 가지가 있습니다. 가장 일반적인 방법은 요청이 들어온 순서대로 처리하는 것입니다.


*/
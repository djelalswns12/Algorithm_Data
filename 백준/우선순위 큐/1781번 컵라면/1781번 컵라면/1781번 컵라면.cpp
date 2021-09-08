// 1781번 컵라면.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <set>
#include <queue>
#include <map>

using namespace std;
class problem {
public:
    int point;
    int deadline;
    problem() {
        point = 0;
        deadline = 0;
    }
    problem(int point, int deadline) :point(point), deadline(deadline){}
};
class cmp {
public:
    bool operator()(problem n1,problem n2) {
        if (n1.deadline < n2.deadline) {
            return true;
        }
        else {
            if (n1.deadline == n2.deadline) {
                return n1.point < n2.point;
            }
            else {
                return false;
            }
        }
    }
};
class cmp2 {
public:
    bool operator()(problem n1, problem n2) {
        return n1.point < n2.point;
    }
    };
int main()
{
    int cnt;
    int deadline,food_cnt;
    priority_queue<problem,vector<problem>,cmp> m;
    priority_queue<problem,vector<problem>,cmp2> m2;
    //map<int,priority_queue<long long>,greater<long long>> m;

    long long answer=0;

    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        cin >> deadline >> food_cnt;
        m.push(problem(food_cnt, deadline));
    }
    int arr[200001] = { 0 };
    int index =0;
    int max_index =m.top().deadline;
    int sel = max_index;
    while (sel>0) {
        if (!m.empty()) {
            index = m.top().deadline;
            if (index >= sel) {
                while (m.top().deadline == index) {
                    cout << "m2 Push:" << m.top().point << "\n";
                    m2.push(m.top());
                    m.pop();
                    if (m.empty()) {
                        break;
                    }
                }
            }
        }
        if (!m2.empty()) {
            arr[sel] = m2.top().point;
            cout << "배열" << sel << "번에 값:" << m2.top().point << "\n";
            m2.pop();
        }
        sel--;
        if (sel <= 0) break;
        
    }
 
    for (int i = 1; i < max_index + 1; i++) {
        cout << arr[i] << "\t";
        answer += arr[i];
    }
    cout << answer;
    
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

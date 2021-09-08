// 1966번 프린터큐.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int my_num, point;
    Node() {
        my_num = -1;
        point = -1;
    }
    Node(int my_num, int point) {
        this->my_num = my_num;
        this->point = point;

    }
};
void Enqueue(vector<Node>* list, Node item) {
    list->push_back(item);
}
int Dequeue(vector<Node>* list) {
    int select_point = list->at(0).point;
    int select_priority = list->at(0).my_num;
    for (int i = 1; i < list->size(); i++) {
        if (select_point < list->at(i).point) {
            //cout << "나보단 큰놈이 있어서 지웁니다 큰놈:" << list->at(i).point << "선택된:" << list->at(0).my_num << "\n";
            Enqueue(list, list->at(0));
            list->erase(list->begin());
            return -1;
        }
    }
    //올바른 삭제
    //cout << "number :" << list->at(0).my_num << "priority:" << list->at(0).point;
    list->erase(list->begin());
    return select_priority;
}
int FindSelect(vector<Node> list, int num) {
    int answer = 0;
    int priority;
    while (true) {
        priority = Dequeue(&list);
        if (priority != -1) {
            answer++;
            if (priority == num) {
                return answer;
            }
        }
    }
}


int main()
{
    int cnt;
    int max, priority;
    vector<int> answers;
    cin >> cnt;
    vector<Node>* list = new vector<Node>[cnt];
    for (int i = 0; i < cnt; i++) {
        cin >> max >> priority;
        int point;
        for (int j = 0; j < max; j++) {
            cin >> point;
            list[i].push_back(Node(j, point));
        }
        answers.push_back(FindSelect(list[i], priority));
    }
    for (auto item : answers) {
        cout << item << "\n";
    }
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

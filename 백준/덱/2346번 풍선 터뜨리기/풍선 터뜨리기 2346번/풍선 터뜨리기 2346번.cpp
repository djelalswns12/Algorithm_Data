// 풍선 터뜨리기 2346번.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <cmath>

const int range = 1001;
int arr[range];
int front = 0;
int back = 0;

void push_front(int num) {
    front--;
    if (front < 0) {
        front = range - 1;
    }
    arr[front] = num;
}
int pop_front(){
    int num=arr[front];
    arr[front] = 0;
    front++;
    if (front >= range) {
        front = 0;
    }
    return num;
}
void push_back(int num) {
    arr[back] = num;
    back++;
    if (back >= range) {
        back = 0;
    }
}
int pop_back() {
    back--;
    if (back < 0) {
        back = range - 1;
    }
    int num = arr[back];
    arr[back] = 0;
    return num;
}
using namespace std;
int main()
{
    int cnt;
    int num;
    cin >> cnt;
    vector<int> list;
    vector<int> answer;
    for(int i=0;i<cnt;i++){
        cin >> num;
        list.push_back(num);
        push_front(i + 1);
    }
    //int init = list[pop_back() - 1];
    bool flag=true;
    int point = 0;
    for (int i = 0; i < cnt; i++) {
            if (flag) {
                int num = pop_back() - 1;
                answer.push_back(num);
                point = list[num];
            }
            else {
                int num = pop_front() - 1;
                answer.push_back(num);
                point = list[num];
            }
            if (point > 0) {
                flag = true;
                for (int k = 0; k < abs(point) - 1; k++) {
                    push_front(pop_back());
                }
           
            }
            else {
                flag = false;
                for (int k = 0; k < abs(point) - 1; k++) {
                    push_back(pop_front());
                }
        }
    }
    for (auto item : answer) {
        cout << (item+1) << " ";
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

// ConsoleApplication3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int range = 11;
int arr[range];
int front = 0;
int back = 0;
void push_front(int num) {
    front--;
    if (front < 0) {
        front = range-1;
    }
    arr[front] = num;
}
int pop_front() {
    int num = arr[front];
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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, m;
    vector<int> answer;

    cin >> n >> k >> m;
    for (int i = 0; i < n; i++) {
        push_front(i+1);
    }
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (answer.size() % m == 0) {
            flag = !flag;
        }
        for (int w = 0; w < k; w++) {
            if (flag) {
                //정상
                int num = pop_back();
                if (w != k - 1) {
                    push_front(num);
                }
                else {
                    answer.push_back(num);
                }
            }
            else {
                //역순
                int num = pop_front();
                if (w != k - 1) {
                    push_back(num);
                }
                else {
                    answer.push_back(num);
                }
            }

        }
    }
    //for (int i = 0; i < sizeof(arr)/sizeof(arr[0]) ;i++) {
    //    cout << i<<":"<<arr[i]<<"  ";
    //}
    //cout << "\n";
    for (auto item : answer) {
        cout << item<<"\n";
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

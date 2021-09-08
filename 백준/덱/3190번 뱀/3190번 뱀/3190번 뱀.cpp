// 3190번 뱀.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
    //게임오버 기준
    //1.몸과 부딪힌다
//2.벽에 부딪힌다.

//시작 조건
//1,1 에서 시작한다.
//오른쪽을 바라본다.

//참고할점
//지렁이의 최대 길이는 맴사이즈의 제곱 : 10000일듯
const int range = 100001;
int arr[range][2];
int front = 0;
int back = 0;
void push_front(int row, int colume) {
    front--;
    if (front < 0) {
        front = range - 1;
    }
    arr[front][0] = row;
    arr[front][1] = colume;
}
void pop_front() {
    int num[2];
    num[0] = arr[front][0];
    num[1] = arr[front][1];
    arr[front][0] = 0;
    arr[front][1] = 0;
    front++;
    if (front >= range) {
        front = 0;
    }
}
void push_back(int row, int colume) {
    arr[front][0] = row;
    arr[front][1] = colume;
    back++;
    if (back >= range) {
        back = 0;
    }
}
void pop_back() {
    back--;
    if (back < 0) {
        back = range - 1;
    }
    int num[2];
    num[0] = arr[back][0];
    num[1] = arr[back][1];
    arr[back][0] = 0;
    arr[back][1] = 0;
}
int fhead() {
    int num= arr[front][0];
    return num;
}
int bhead() {
    int num = arr[front][1];
    return num;
}
bool find(int row, int colume) {
    int find_num = back;
    while (front != find_num) {
        find_num--;
        if (find_num < 0) {
            find_num = range - 1;
        }
        
        if (front == find_num) {
            break;
        }
        if (arr[find_num][0] == row && arr[find_num][1] == colume) {
            return true;
        }
    }
    return false;
}
string dir_set(string my,string dir) {
    if (my == "right") {
        if (dir == "D") {
            return "down";
        }
        if (dir == "L") {
            return "up";
        }
    }
    if (my == "left") {
        if (dir == "D") {
            return "up";
        }
        if (dir == "L") {
            return "down";
        }
    }
    if (my == "up") {
        if (dir == "D") {
            return "right";
        }
        if (dir == "L") {
            return "left";
        }
    }
    if (my == "down") {
        if (dir == "D") {
            return "left";
        }
        if (dir == "L") {
            return "right";
        }
    }
    return "null";
}

int main()
{
    int size;
    cin >> size;
    vector<vector<int>> map(size + 2, vector<int>(size + 2, 0));

    int apple;
    cin >> apple;
    for (int i = 0; i < apple; i++) {
        int row, colume;
        cin >> row >> colume;
        map[row][colume] = 1;
    }
    int direction;
    vector<string> list;
    cin >> direction;
    cin.ignore();
    for (int i = 0; i < direction; i++) {
        string str;
        getline(cin, str);
        list.push_back(str);
    }
    //맵 보정
    for (int i = 0; i < map.size(); i++) {
        map[0][i] = 2;
        map[size + 1][i] = 2;
        map[i][0] = 2;
        map[i][size + 1] = 2;
    }

    //맵 정보 출력
    for (auto item : map) {
        for (auto i : item) {
            cout << i << " ";
        }
        cout << "\n";
    }

    int timer = 0;
    string dir = "right";
    string order = "D";
    push_front(1, 1);

    while (true) {
        timer++;
        if (dir == "right") {
            push_front(fhead(), bhead()+ 1);
            if (find(fhead(), bhead())) {
                //자기 몸
                cout << "right몸에 부딪힘";
                break;
            }
            if (map[fhead()][bhead()] == 2) {
                //벽
               
                //cout << "right벽에 부딪힘";
                break;
            }
            else if (map[fhead()][bhead()] == 1) {
                //사과
                map[fhead()][bhead()] = 0;
            }
            else if (map[fhead()][bhead()] == 0) {
                //빈땅
                pop_back();
            }
        }
        if (dir == "left"){
            push_front(fhead(), bhead() -1);
            if (find(fhead(),bhead())) {
                //자기 몸
                //cout << "left몸에 부딪힘";
                break;
            }
            if (map[fhead()][bhead()] == 2) {
                //벽
                //cout << "left벽에 부딪힘";
                break;
            }
            else if (map[fhead()][bhead()] == 1) {
                //사과
                map[fhead()][bhead()] = 0;
            }
            else if (map[fhead()][bhead()] == 0) {
                //빈땅
                pop_back();
            }
        }
        if (dir == "up") {
            push_front(fhead()-1, bhead());
            if (find(fhead(), bhead())) {
                //자기 몸
                //cout << "up몸에 부딪힘";
                break;
            }
            if (map[fhead()][bhead()] == 2) {
                //벽
                //cout << "up벽에 부딪힘";
                break;
            }
            else if (map[fhead()][bhead()] == 1) {
                //사과
                map[fhead()][bhead()] = 0;
            }
            else if (map[fhead()][bhead()] == 0) {
                //빈땅
                pop_back();
            }
        }
        if (dir == "down") {
            push_front(fhead()+1, bhead());
            if (find(fhead(), bhead())) {
                //자기 몸
                //cout << "down몸에 부딪힘";
                break;
            }
            if (map[fhead()][bhead()] == 2) {
                //벽
                //cout << "down벽에 부딪힘";
                break;
            }
            else if (map[fhead()][bhead()] == 1) {
                //사과
                map[fhead()][bhead()] = 0;
            }
            else if (map[fhead()][bhead()] == 0) {
                //빈땅
                pop_back();
            }
        }
        //cout <<"time:"<<timer<<"dir:"<<dir<<"pos:"<<head()[0] <<"/"<< head()[1] << "\n";
        for (int i = 0; i < list.size(); i++) {
            if (timer == stoi(list.at(i).substr(0, list.at(i).find(" ")))) {
                dir = dir_set(dir, list.at(i).substr(list.at(i).find(" ") + 1, list.at(i).length()));
            }
        }
    }
    cout <<timer;

    return 0;
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

// 1697번 숨바꼭질.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    int ori, des;
    queue<int> q;
    queue<int> tmp_q;

    cin >> ori >> des;
    vector<bool> visit(100001, false);
    if (ori != des) {
        q.push(ori);
    }
    visit.at(ori) = true;
    int time = 0;
    bool end = false;
    bool find = false;
    while (end == false) {
        while (!q.empty()) {
            int right = q.front() + 1;
            int left = q.front() - 1;
            int up = q.front() * 2;
            if (right < visit.size() && right >= 0) {
                if (visit.at(right) == false) {
                    tmp_q.push(right);
                    visit.at(right) = true;
                }
            }
            if (left < visit.size() && left >= 0) {
                if (visit.at(left) == false) {
                    tmp_q.push(left);
                    visit.at(left) = true;
                }
            }
            if (up < visit.size() && up >= 0) {
                if (visit.at(up) == false) {
                    tmp_q.push(up);
                    visit.at(up) = true;
                }
            }
            if (right == des) {
                find = true;
                break;
            }
            if (left == des) {
                find = true;
                break;
            }
            if (up == des) {
                find = true;
                break;
            }
            q.pop();
        }
        if (find == true) {
            time++;
            break;
        }
            if (!tmp_q.empty()) {
                time++;
                while (!tmp_q.empty()) {
                    if (tmp_q.front() == des) {
                        end = true;
                        break;
                    }
                    q.push(tmp_q.front());
                    tmp_q.pop();
                }
            }
            else {
                break;
            }

    }
    cout << time;
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

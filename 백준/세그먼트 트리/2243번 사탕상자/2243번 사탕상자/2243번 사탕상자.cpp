// 2243번 사탕상자.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main()
{
    vector<int> answer;
    map<int, int> list;
    int n;
    int type, first, second;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> type;
        if (type == 1) {
            //순위 대로 뽑기
            cin >> first;
            for (auto i=list.begin(); i != list.end(); i++) {
                if (i->second <= 0) {
                    continue;
                }
                first = first - i->second;
                if (first > 0) {
                    continue;
                }
                else {
                    answer.push_back(i->first);
                    i->second -= 1;
                    break;
                }
            }
        }
        else {
            //맛 대로 뽑거나 넣기
            cin >> first >> second;
            if (list.find(first) == list.end()) {
                list.insert(make_pair(first, second));
            }
            else {
                list.at(first)+=second;
            }
        }
    }
    for (auto i : answer) {
        cout << i << "\n";
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

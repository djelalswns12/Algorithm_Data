// 1927번 최소힙.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int range = 100000;
vector<int> arr(range);
int head = 1;
int main()
{
    int cnt;
    int num;
    cin >> cnt;
    vector<int> list;
    for (int i = 0; i < cnt; i++) {
        cin >> num;
        list.push_back(num);
    }
    for (auto item : list) {

        if (item == 0) {

            cout << arr[1] <<"\n";
            arr[1] = 0;
            if (head == 1) {
                continue;
            }
            head--;
            arr[1] = arr[head];
            arr[head] = 0;
            
       
            int hear = 1;
            while (true) {
                int tmp = arr[hear];
                int left = hear * 2;
                int right = (hear * 2)+1;
                if (arr[left] > arr[right]) {
                    if (arr[hear] < arr[left]) {
                        arr[hear] = arr[left];
                        arr[left] = tmp;
                        hear = left;
                        continue;
                    }
                }
                else {
                    if (arr[hear] < arr[right]) {
                        arr[hear] = arr[right];
                        arr[right] = tmp;
                        hear = right;
                        continue;
                    }
                }
                break;
            }

        }
        else {
            //값 추가
            int index=floor(head / 2); // 부모 인덱스
            if (head == 1) {
                //루트
                arr[head] = item;
                head++;
            }
            else {
                int hear = head;
                while (true) {
                    if (arr[index] > item) {
                        //부모가 더 크다면
                        arr[hear] = item;
                        head++;
                        break;
                    }
                    else {
                        //부모가 더 작다면
                        int tmp = arr[index];//부모 값
                        arr[hear] = tmp;
                        arr[index] = item;
                        hear = index;
                        if (hear == 1) {
                            head++;
                            break;
                        }
                        index = floor(hear / 2);
                    }
                }
            }
        }
    }
 /*   cout << "*-----------*\n";
    cout << "\n";
    cout << "\n배열상태( head:" << head<<"\n";
    for (int i = 1; i < head;i++) {
       cout<< arr[i]<<"\t";
    }*/
}
// 1       4       3       13      15      3       23      20      24      99      193     19      11      483     213
// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

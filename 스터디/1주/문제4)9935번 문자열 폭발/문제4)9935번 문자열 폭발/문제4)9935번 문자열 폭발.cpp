// 문제4)9935번 문자열 폭발.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;
string split(string str,string p) {
    int previous = 0;
    int current = 0;
    string tmp_str;
    bool isChk = false;
    current = str.find(p);
    //find는 찾을게 없으면 npos를 리턴함
    while (current != string::npos) {
        isChk = true;
        tmp_str += str.substr(previous, current - previous);
        previous = current + p.size();
        current = str.find(p, previous);
    }
    if (isChk == true) {
        tmp_str += str.substr(previous, current - previous);
        str=split(tmp_str, p);
    }
    return str;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;
    string p;
    cin >> p;
    string answer;
    answer=split(str, p);
    if (answer.length() > 0) {
        cout << answer;
    }
    else {
        cout << "FRULA";
    }


}
// 10845번 큐.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

/*
push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/

using namespace std;
void answer(vector<string>);
int main()
{
	vector<string> words;
	string new_word;
	int my_size;
	cin >> my_size;
	while (words.size() <= my_size) {
		getline(cin, new_word);
		words.push_back(new_word);
	}
	answer(words);
}
void answer(vector<string> s) {
	vector<int> answers;
	for (int i = 0; i < s.size(); i++) {
		if (s[i].find("push") != string::npos) {
			int num=atoi(s[i].substr(5, s[i].length()).c_str());
			answers.push_back(num);
		}
		if (s[i].find("pop") != string::npos) {
			if (answers.size()>0) {
				cout << answers.at(0) << endl;
				answers.erase(answers.begin());
			}
			else {
				cout << -1<<endl;
			}
		}
		if (s[i].find("size") != string::npos) {
			cout << answers.size() << endl;
		}
		if (s[i].find("empty") != string::npos) {
			if (answers.size() > 0) {
				cout << 0 << endl;
			}
			else {
				cout << 1 << endl;
			}
		}
		if (s[i].find("front") != string::npos) {
			if (answers.size() > 0) {
				cout << answers.at(0) << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
		if (s[i].find("back") != string::npos) {
			if (answers.size() > 0) {
				cout << answers.at(answers.size()-1) << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
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

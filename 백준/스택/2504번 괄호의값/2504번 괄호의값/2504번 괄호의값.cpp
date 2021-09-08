

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	string line;
	vector<string> stack;
	vector<string> answer;
	cin >> line;
	for (int i = 0; i < line.length(); i++) {
		string data = string(1,line[i]);
		stack.push_back(data);
		if (data == "(") {
			//스택 최상단 하나 밑에서(본인을 제외하기 위해) 부터 내려가면서 (  )  [  ] 찾기
			if (stack.size() > 0) {
				for (int j = stack.size() - 2; j >= 0; j--) {
					if (stack[j] == "(") {
						stack[j] = "a";
						break;
					}
					if (stack[j] == "[") {
						stack[j] = "b";
						break;
					}
				}
			}
		}
		if (data == ")") {

			//스택 최상단 하나 밑에서(본인을 제외하기 위해) 부터 내려가면서 (  )  [  ] 찾기
			if (stack.size() > 0) {
				for (int j = stack.size() - 2; j >= 0; j--) {
					if (stack[j] == "(") {
						stack[j] = "2";
						stack.pop_back();
						break;
					}
					if (stack[j] == "a") {
						bool isOk = true;
						int answer = 0;
						// 스택최상단 한칸 밑부터 j바로 위까지의 숫자들의 합을 구한다. 단 합을 구할때 각 수가 2또는 3이 아닌것들이 있으면 합을 c로 한다.
						for (int t = stack.size() - 2; t > j; t--) {
							if (stack[t] == "a" || stack[t] == "b" || stack[t] == "c" || stack[t] == "[" || stack[t] == "]" || stack[t] == ")" || stack[t] == "(") {
								isOk = false;
								break;
							}
							else {
								
								answer += stoi(stack[t]);
							}
						}
						// 합의 값이 c가 아니면 합에 2를 곱한값을 스택 j에 넣는다
						if (isOk == true) {
							stack[j] = to_string(2*answer);
						}
						else {
							stack[j] = "c";
						}
						// 스택 j 까지 모든 스택을 pop한다.
						for (int w = stack.size() - 1; w > j; w--) {
							stack.pop_back();
						}
						break;
					}
				}
			}
		}
		if (data == "[") {
			//스택 최상단 하나 밑에서(본인을 제외하기 위해) 부터 내려가면서 (  )  [  ] 찾기
			if (stack.size() > 0) {
				for (int j = stack.size() - 2; j >= 0; j--) {
					if (stack[j] == "(") {
						stack[j] = "a";
						break;
					}
					if (stack[j] == "[") {
						stack[j] = "b";
						break;
					}
				}
			}
		}
		if (data == "]") {
			//스택 최상단 하나 밑에서(본인을 제외하기 위해) 부터 내려가면서 (  )  [  ] 찾기
			if (stack.size() > 0) {
				for (int j = stack.size() - 2; j >= 0; j--) {
					if (stack[j] == "[") {
						stack[j] = "3";
						stack.pop_back();
						break;
					}
					if (stack[j] == "b") {
						bool isOk = true;
						int answer = 0;
						// 스택최상단 한칸 밑부터 j바로 위까지의 숫자들의 합을 구한다. 단 합을 구할때 각 수가 2또는 3이 아닌것들이 있으면 합을 c로 한다.
						for (int t = stack.size() - 2; t > j; t--) {
							if (stack[t] == "a" || stack[t] == "b" || stack[t] == "c" || stack[t] == "[" || stack[t] == "]" || stack[t] == ")" || stack[t] == "(") {
								isOk = false;
								break;
							}
							else {

								answer += stoi(stack[t]);
							}
						}
						// 합의 값이 c가 아니면 합에 2를 곱한값을 스택 j에 넣는다
						if (isOk == true) {
							stack[j] = to_string(3 * answer);
						}
						else {
							stack[j] = "c";
						}
						// 스택 j 까지 모든 스택을 pop한다.
						for (int w = stack.size() - 1; w > j; w--) {
							stack.pop_back();
						}
						break;
					}
				}
			}
		}
	}
	bool flag = true;
	for (auto item : stack) {
		if (item == "a" || item == "b" || item == "c" || item == "[" || item == "]" || item == ")" || item == "(") {
			cout << "0";
			flag = false;
			break;
		}
	}
	if (flag) {
		int answer=0;
		for (auto item : stack) {
			answer += stoi(item);
		}
		cout << answer;
	}

}

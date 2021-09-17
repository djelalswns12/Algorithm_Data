#include<string>
#include <iostream>
#include <vector>

using namespace std;
vector<char> stack;
void stackCheck(char c) {
    if(c=='('){
        stack.push_back(c);
    }
    else  if (c == ')') {
        if (stack.size() > 0) {
            if (stack.at(stack.size() - 1) == '(') {
                stack.pop_back();
            }
        }
        else {
            stack.push_back(c);
        }
    }
}

bool solution(string s)
{
    bool answer = true;
    for (int i = 0; i < s.length(); i++) {
        stackCheck(s.at(i));
    }
    if (stack.size() != 0) {
        answer = false;
   }
    return answer;
}
int main()
{
    string s;
    cin >> s;
    solution(s);
}

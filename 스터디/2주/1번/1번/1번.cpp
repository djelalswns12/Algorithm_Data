#include <iostream>
#include <queue>
#include <cmath>
#include <string>
#include <map>
#include <vector>
using namespace std;
string check(string str) {
    vector<char> list;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            list.push_back('(');
        }
        if (str[i] == ')') {
            if (!list.empty()) {
                if (list.at(list.size() - 1) == '(') {
                    list.pop_back();
                }
                else {
                    list.push_back(str[i]);
                }
            }
            else {
                list.push_back(str[i]);
            }
        }
        if (str[i] == '[') {
            list.push_back('[');
        }
        if (str[i] == ']') {
            if (!list.empty()) {
                if (list.at(list.size() - 1) == '[') {
                    list.pop_back();
                }
                else {
                    list.push_back(str[i]);
                }
            }
            else {
                list.push_back(str[i]);
            }
        }
    }
    if (list.empty()) {
        return "yes";
    }
    else {
        return "no";
    }
}
int main()
{
    string s;
    vector<string> str;
    while (getline(cin, s)) {
        if (s[0] == '.') {
            break;
        }
        str.push_back(s);
    }
    for (string c : str) {
        cout << check(c) << "\n";
    }


}


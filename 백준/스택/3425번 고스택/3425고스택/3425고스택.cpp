// 3425고스택.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

//숫자가 부족해서 연산을 수행할 수 없을 때
//0으로 나눴을 때 (DIV, MOD)
//연산 결과의 절댓값이 10억을 넘어갈 때는 모두 프로그램 에러이다.

/*
NUM X: X를 스택의 가장 위에 저장한다. (0 ≤ X ≤ 109)
POP: 스택 가장 위의 숫자를 제거한다.
INV: 첫 번째 수의 부호를 바꾼다. (42 -> -42)
DUP: 첫 번째 숫자를 하나 더 스택의 가장 위에 저장한다.
SWP: 첫 번째 숫자와 두 번째 숫자의 위치를 서로 바꾼다.
ADD: 첫 번째 숫자와 두 번째 숫자를 더한다.
SUB: 첫 번째 숫자와 두 번째 숫자를 뺀다. (두 번째 - 첫 번째)
MUL: 첫 번째 숫자와 두 번째 숫자를 곱한다.
DIV: 첫 번째 숫자로 두 번째 숫자를 나눈 몫을 저장한다. 두 번째 숫자가 피제수, 첫 번째 숫자가 제수이다.
MOD: 첫 번째 숫자로 두 번째 숫자를 나눈 나머지를 저장한다. 두 번째 숫자가 피제수, 첫 번째 숫자가 제수이다.
*/
int PUSH(vector<int>* list,long long num) {
    if (abs(num) <= 1000000000) {
        list->push_back(num);
        return 0;
    }
    else {
        return -1;
    }
}
int NUM(vector<int> *list,int num){
    if (num >= 0 && num <= 1000000000) {
        list->push_back(num);
        return 0;
    }
    else {
        return -1;
    }
}
int POP(vector<int>* list) {
    int answer = -2100000000;
    if (list->size() > 0) {
        answer = list->at(list->size() - 1);
        list->pop_back();
    }
    return answer;
}
int INV(vector<int>* list) {
    if (list->size() > 0) {
        list->at(list->size() - 1) *= -1;
        return 0;
    }
    return -1;
}
int DUP(vector<int>* list) {
    if (list->size() > 0) {
        int num = list->at(list->size() - 1);

        list->push_back(num);

        return 0;
    }
    return -1;
}
int SWP(vector<int>* list) {
    if (list->size() > 0) {
        int f_num= POP (list);
        int s_num = POP(list);
        if (f_num == -2100000000 || s_num == -2100000000) {
            return -1;
        }
        PUSH(list, f_num);
        PUSH(list, s_num);
        return 0;
    }
    return -1;
}
int ADD(vector<int>* list) {
    if (list->size() > 0) {
        long long f_num = POP(list);
        long long s_num = POP(list);
        if (f_num == -2100000000 || s_num == -2100000000) {
            return -1;
        }
        if (PUSH(list, (f_num + s_num)) == -1) {
            return -1;
        }
        return 0;
    }
    return -1;
}
int SUB(vector<int>* list) {
    if (list->size() > 0) {
        long long f_num = POP(list);
        long long s_num = POP(list);
        if (f_num == -2100000000 || s_num == -2100000000) {
            return -1;
        }
        if (PUSH(list, (s_num - f_num)) == -1) {
            return -1;
        }
        return 0;
    }
    return -1;
}
int MUL(vector<int>* list) {
    if (list->size() > 0) {
        long long f_num = POP(list);
        long long s_num = POP(list);
        if (f_num == -2100000000 || s_num == -2100000000) {
            return -1;
        }

        if (PUSH(list, (s_num * f_num)) == -1) {
            return -1;
        }
        return 0;
    }
    return -1;
}
int DIV(vector<int>* list) {
    if (list->size() > 0) {
        long long f_num = POP(list);
        long long s_num = POP(list);
        if (f_num == -2100000000 || s_num == -2100000000 || f_num == 0) {
            return -1;
        }
        if (PUSH(list, (s_num / f_num)) == -1) {
            return -1;
        }
        return 0;
    }
    return -1;
}
int MOD(vector<int>* list) {
    if (list->size() > 0) {
        long long f_num = POP(list);
        long long s_num = POP(list);
        if (f_num == -2100000000 || s_num == -2100000000 || f_num==0) {
            return -1;
        }
        if (PUSH(list, (s_num % f_num)) == -1) {
            return -1;
        }
        return 0;
    }
    return -1;
}
class Node {
public:
    vector<string> orders;
    vector<int> numbers;

    vector<int> stack;
    string message="";
    void GetMsg() {
        if (stack.size() <1 || stack.size() > 1) {
            message = "ERROR";
        }
        else {
            if (message != "ERROR") {
                    message = to_string(stack.at(0));
            }
        }
        cout << message;
        message = "";
    }
    void Cal() {
        for (int i = 0; i < numbers.size(); i++) {
            stack.clear();
            stack.push_back(numbers.at(i));
            for (int j = 0; j < orders.size(); j++) {

                if (orders.at(j).substr(0, 3) == "NUM") {
                    int num = atoi(orders.at(j).substr(4, orders.at(j).length()).c_str());
                    if (NUM(&stack, num) == -1) {
                        message = "ERROR";
                        break;
                    }
                }
                if (orders.at(j).substr(0, 3) == "POP") {
                    if (POP(&stack) == -2100000000) {
                        message = "ERROR";
                        break;
                    }
                }
                if (orders.at(j).substr(0, 3) == "INV") {
                    if (INV(&stack) == -1) {
                        message = "ERROR";
                        break;
                    }
                }
                if (orders.at(j).substr(0, 3) == "DUP") {
                    if (DUP(&stack) == -1) {
                        message = "ERROR";
                        break;
                    }
                }
                if (orders.at(j).substr(0, 3) == "SWP") {
                    if (SWP(&stack) == -1) {
                        message = "ERROR";
                        break;
                    }
                }
                if (orders.at(j).substr(0, 3) == "ADD") {
                    if (ADD(&stack) == -1) {
                        message = "ERROR";
                        break;
                    }
                }
                if (orders.at(j).substr(0, 3) == "SUB") {
                    if (SUB(&stack) == -1) {
                        message = "ERROR";
                        break;
                    }
                }
                if (orders.at(j).substr(0, 3) == "MUL") {
                    if (MUL(&stack) == -1) {
                        message = "ERROR";
                        break;
                    }
                }
                if (orders.at(j).substr(0, 3) == "DIV") {
                    if (DIV(&stack) == -1) {
                        message = "ERROR";
                        break;
                    }
                }
                if (orders.at(j).substr(0, 3) == "MOD") {
                    if (MOD(&stack) == -1) {
                        message = "ERROR";
                        break;
                    }
                }
            }
            GetMsg();
            if (i < numbers.size() - 1) {
                cout << "\n";
            }
        }
       
    }
};
int main()
{

    vector<Node> nodes;
    string order;
    int cnt;
    int number;
    bool isQuit = false;

    while (isQuit==false) {
        Node one;
        order = "";
        while (true) {
            getline(cin, order);
            if (order == "QUIT") {
                isQuit = true;
                break;
            }
            if (order == "END") {
                break;
            }
            one.orders.push_back(order);
        }
        if (isQuit == false) {
            cin >> cnt;
            for (int i = 0; i < cnt; i++) {
                cin >> number;
                one.numbers.push_back(number);
            }
            nodes.push_back(one);
            //cout << "\n";
        }
    }

    //출력문
    for (int i = 0; i < nodes.size(); i++) {
        nodes.at(i).Cal();
        if (i < nodes.size() - 1) {
            cout << "\n";
            cout << "\n";
        }
    }
}
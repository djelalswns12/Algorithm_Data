// 1991번 트리순회.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class node {
public:
    string name;
    node* par;
    node* left;
    node* right;
    node(string name,node *par) {
        this->name = name;
        this->par = par;
        left = nullptr;
        right = nullptr;
    }
    node(string name) {
        this->name = name;
        par = nullptr;
        left = nullptr;
        right = nullptr;
    }
    void SetLeft(node* one) {
        //cout<<"\n" << name << "의 왼쪽 자식" << one->name << "\n";
        left = one;
    }
    void SetRight(node* one) {
        //cout << "\n" << name << "의 오른쪽 자식" << one->name << "\n";
        right = one;
    }
};
class tree {
public:
    node* root;
    tree() {

    }
    tree(node* one) {
        root = one;
    }
    void SetRoot(node* one) {
        root = one;
    }
    node* FindByName(node* one,string name) {
        node* left;
        node* right;
        //cout << one->name;
        if (one->name == name) {
            return one;
        }
        else {
            if (one->left != nullptr) {
               left=FindByName(one->left, name);
               if (left != nullptr) {
                   return left;
               }
            }
            if (one->right != nullptr) {
               right=FindByName(one->right, name);
               if (right!= nullptr) {
                   return right;
               }
            }
            return nullptr;
        }
     
    }
    void InOrder(node* one) {
        //왼쪽 자식 체크
        if (one->left != nullptr) {
            InOrder(one->left);
        }
        //본인 체크
        cout << one->name;
        //오른쪽 자식 체크
        if (one->right != nullptr) {
            InOrder(one->right);
        }
    }
    void PreOrder(node* one) {
        //본인체크
        cout << one->name;
        if (one->left != nullptr) {
            PreOrder(one->left);
        }
        //오른쪽 자식 체크
        if (one->right != nullptr) {
            PreOrder(one->right);
        }
    }
    void PostOrder(node* one) {
        if (one->left != nullptr) {
            PostOrder(one->left);
        }
        //오른쪽 자식 체크
        if (one->right != nullptr) {
            PostOrder(one->right);
        }
        cout << one->name;
    }
};
int main()
{
    int num;
    cin >> num;
    cin.ignore();
    string list;
    tree answer;
    node* setNode;
    node* left;
    node* right;
     
    for (int i = 0; i < num; i++) {
        getline(cin, list);
        if (i == 0) {
            answer.SetRoot(new node(list.substr(0,1)));
        }
        left= new node(list.substr(2, 1));
        right=new node(list.substr(4, 1)); 

        setNode = answer.FindByName(answer.root, list.substr(0, 1));
    
        if (left->name != ".") {
            setNode->SetLeft(left);
        }
        if (right->name != ".") {
            setNode->SetRight(right);
        }
    }
    answer.PreOrder(answer.root);
    cout << "\n";
    answer.InOrder(answer.root);
    cout << "\n";
    answer.PostOrder(answer.root);
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

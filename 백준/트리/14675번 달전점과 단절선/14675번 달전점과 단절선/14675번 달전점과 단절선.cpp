// 14675번 달전점과 단절선.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <map>
#include <vector>
using namespace std;
class tree {
public:
       vector<pair<int, int>> edge;
       vector<pair<int, int>> test;
       map<int,int> nodes;
       void Push(pair<int,int> one){
           if (nodes.find(one.first) == nodes.end()) {
               nodes.insert(make_pair(one.first, 1));
           }
           else {
               nodes.at(one.first) += 1;
           }
           if (nodes.find(one.second) == nodes.end()) {
               nodes.insert(make_pair(one.second, 1));
           }
           else {
               nodes.at(one.second) += 1;
           }
           edge.push_back(one);
       }
       void TestPush(pair<int, int> one) {
           test.push_back(one);
       }
       void Print() {
           for (auto item : nodes) {
               cout << item.first << "/" << item.second << "\n";
           }
       }
       void Answer() {
           for (auto item : test) {
               if (item.first == 1) {
                   //점

                   if (nodes.at(item.second) > 1) {
                       cout << "yes" << "\n";
                   }
                   else {
                       cout << "no" << "\n";
                   }
               }
               else {
                   //선

                   if (edge.size() <= 1) {
                       cout << "yes" << "\n";
                       continue;
                   }
                   if ((nodes.at(edge.at(item.second - 1).first) > 1) || (nodes.at(edge.at(item.second - 1).second) > 1)) {
                       cout << "yes" << "\n";
                   }
                   else {
                       cout << "no" << "\n";
                   }
               }
           }
       }
};
int main()
{
    tree one;
    int cnt;
    int u, v;
    cin >> cnt;
    for (int i = 0; i < cnt-1; i++)
    {
        cin >> u >> v;
        one.Push(make_pair(u, v));
    }
    cin >> cnt;
    int type,num;
    for (int i = 0; i < cnt; i++) {
        cin >> type >> num;
        one.TestPush(make_pair(type, num));
    }

    one.Answer();
    
}


// 이분 그래프.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <map>


using namespace std;
vector<int> nodes;
vector<bool> visit;
class node {
public:
    int par;
    int num;
    int room;
    node(int par,int num,int room) {
        this->num = num;
        this->par = par;
        this->room = room;
        nodes.at(num) = room;
        visit.at(num) = true;
    }
};
int main()
{
    int tc, v, e,ori,des;


    cin >> tc;
    vector<bool> real_ans;

    for (int i = 0; i < tc; i++) {
        vector<string> ans;
        map<int, vector<int>> m;
        cin >> v >> e;
        nodes = vector<int>(v + 1, 0);
        visit = vector<bool>(v + 1, false);
        for (int k = 1; k <= v; k++) {
            m.insert(make_pair(k, vector<int>()));
        }
        for (int j = 0; j < e; j++) {
            cin >> ori >> des;
            m.at(ori).push_back(des);
            m.at(des).push_back(ori);
        }
        //전체 그래프를 연결 그래프 끼리로 구성
        vector<int> linked;
        queue<int> l_q;
        for (int i = 1; i < v; i++) {
            if (visit.at(i) == false) {
                linked.push_back(i);
                l_q.push(i);
                visit.at(i) = true;
            }
            while (!l_q.empty()) {
                for (int t = 0; t < m.at(l_q.front()).size(); t++) {
                    if (visit.at(m.at(l_q.front()).at(t)) == false) {
                        visit.at(m.at(l_q.front()).at(t)) = true;
                        l_q.push(m.at(l_q.front()).at(t));
                    }
                }
                l_q.pop();
            }
        }
        for (int e : linked) {
            visit = vector<bool>(v + 1, false);
            queue<node> q;
            //left = 1 right= 2
            nodes.at(e) = 1;
            q.push(node(0, e, nodes.at(e)));
            visit.at(e) = false;
            bool chk = false;
            while (!q.empty()) {
                int set_room = 0;
                if (q.front().room == 1) {
                    set_room = 2;
                }
                else {
                    set_room = 1;
                }
                for (int t = 0; t < m.at(q.front().num).size(); t++) {
                    if (nodes.at(m.at(q.front().num).at(t)) != 0 && nodes.at(m.at(q.front().num).at(t)) != set_room) {
                        chk = true;
                        ans.push_back("NO");
                        break;
                    }
                    if (visit.at(m.at(q.front().num).at(t)) == false) {
                            node one(q.front().num, m.at(q.front().num).at(t), set_room);
                            q.push(one);
                    }
                }
                q.pop();
                if (chk)break;
            }
            if (!chk)ans.push_back("YES");
        }
        bool answer = true;
        for (string s : ans) {
            if (s == "NO") {
                answer = false;
                break;
            }
        }
        real_ans.push_back(answer);

    }
    for (int i = 0; i < real_ans.size(); i++) {
        if (real_ans.at(i)) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        cout << "\n";
    }
}

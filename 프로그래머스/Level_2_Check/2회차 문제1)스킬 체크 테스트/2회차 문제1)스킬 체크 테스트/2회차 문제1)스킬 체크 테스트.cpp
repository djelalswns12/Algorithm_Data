// 2회차 문제1)스킬 체크 테스트.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;
int levelCheck(string skill,char set) {
    for (int i = 0; i < skill.length(); i++) {
        if (skill.at(i) == set) {
            return i;
        }
    }
    return -1;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    //cout << "스킬트리입니다\n";
    //for (string i : skill_trees) {
    //    cout << ":"<<i << "\n";
    //}

    //BACDE CBD

    for (string item : skill_trees) {
        int skill_level = 0;
        bool isSkill = true;
        for (int i = 0; i < item.length(); i++) {
            int check = levelCheck(skill, item.at(i));
            if (skill_level < check) {
                isSkill = false;
                break;
            } 
            else if (skill_level ==check) {
                skill_level++;
            }
           }
        if (isSkill == true) {
            answer++;
        }
        }
    return answer;
}
int main()
{
    string skill,trees;
    cin >> skill;
    vector<string> skill_trees;
    cin.ignore();
    while (getline(cin,trees)) {
        if (trees[0]==EOF) {
            break;
        }
        skill_trees.push_back(trees);
    }
    cout << solution(skill, skill_trees);
}


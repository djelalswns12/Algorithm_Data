// 좋은친구3078번.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

#define MAX_SIZE 300000;
int MAX_NAME = 21;
using namespace std;
class Student {
public:
	string name;
	int score;
	Student() {
		name = "";
		score = -1;
	}
	Student(string name, int score) {
		this->name = name;
		this->score = score;
	}
};
int main()
{
	int count;
	int compare_score;
	int compare_num = 0;
	int compare_par_num = 0;
	long long answer = 0;
	cin >> count>>compare_score;
	vector<Student>* list = new vector<Student>[MAX_NAME];
	string studentName;
	for (int i = 0; i < count; i++) {
		cin >> studentName;
		list[(studentName.length())].push_back(Student(studentName,i));
	}
	for (int i = 0; i < MAX_NAME; i++) {
		//cout << list[i].size()<<"<<---size------------\n";
		for (int j = 0; j < list[i].size(); j++) {
			//cout << list[i].at(j).score<<"\n";
			if (j == 0) {
				compare_par_num = list[i].at(0).score;;
				compare_num = list[i].at(0).score;
			}
			else {
				if (list[i].at(j).score - compare_num <= compare_score) {
					if (compare_num != compare_par_num) {
						if (list[i].at(j).score - compare_par_num < compare_score) {
							//cout << "상위 부모가 범위에 포함되므로 올라갑니다." << "상위부모:" << compare_par_num << "부모:" << compare_num << "\n";
							answer++;
						}
						else if (list[i].at(j).score - compare_par_num > compare_score) {
							compare_par_num = compare_num;
						}
						else {
							compare_par_num = compare_num;
							//cout << "상위 부모가 범위에 포함되므로 올라갑니다. 또한 상위부모 값이 가능한 최대값이라서 갱신됩니다." << "상위부모:" << compare_par_num << "부모:" << compare_num << "\n";
							answer++;
						}
					}
					//cout << "부모가 범위에 포함되므로 올라갑니다." << "상위부모:" << compare_par_num << "부모:" << compare_num << "\n";
					answer++;
				}
				compare_num = list[i].at(j).score;
			}
		}
	}
	cout << answer;
}
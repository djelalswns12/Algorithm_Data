
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	int cnt;
	int num;
	vector<int> needs;
	vector<int> stack;
	vector<int> origin;
	vector<char> answer;
	bool isOk=true;
	cin >> cnt;

	for (int i = 0; i < cnt; i++) {
		cin >> num;
		needs.push_back(num);
	}
	for (int i = cnt; i > 0; i--) {
		origin.push_back(i);
	}
	//init
	stack.push_back(origin.at(origin.size() - 1));
	origin.pop_back();
	answer.push_back('+');

	for (int i = 0; i < needs.size(); i++) {
		while (true) {
			if (stack.size() > 0) {
				if (stack.back() == needs[i]) {
					stack.pop_back();
					answer.push_back('-');
					//cout << needs[i]<<"-된 값";
					break;
				}
			}
			if (origin.size() > 0) {
				int compare = origin.at(origin.size() - 1);
				origin.pop_back();
				answer.push_back('+');
				stack.push_back(compare);
			}
			else {
				isOk = false;
				break;
			}

		}
	}
	if (isOk) {
		for (auto item : answer) {
			cout << item << "\n";
		}
	}
	else {
		cout << "NO";
	}
}

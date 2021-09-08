
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	int cnt;
	string order;
	vector<string> orders;
	vector<string> stack;
	cin >> cnt;
	cin.ignore();
	for (int i = 0; i < cnt; i++) {
		getline(cin, order);
		orders.push_back(order);

	}

	for (int i = 0; i < orders.size(); i++) {

		if (orders.at(i).substr(0, 3) == "pus") {
			stack.push_back(orders.at(i).substr(5, orders.at(i).length()));
		}

		if (orders.at(i).substr(0, 3) == "pop") {
			if (stack.size() > 0) {
				cout << stack.at(stack.size() - 1) << "\n";
				stack.pop_back();
			}
			else {
				cout << -1<<"\n";
			}
		}

		if (orders.at(i).substr(0, 3) == "siz") {
			cout << stack.size() << "\n";
		}

		if (orders.at(i).substr(0, 3) == "emp") {
			cout << (stack.size() > 0 ? 0 : 1)<<"\n";
		}

		if (orders.at(i).substr(0, 3) == "top") {
			if (stack.size() > 0) {
				cout << stack.at(stack.size() - 1) << "\n";
			}
			else {
				cout << -1 << "\n";
			}
		}
	}

}


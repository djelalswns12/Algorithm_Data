// 7662번 이중 우선순위 큐.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>

using namespace std;
class item {
public:
	long long value;
	long long max_id;
	long long min_id;
	item() {
		value = 0;
		min_id = -1;
		max_id = -1;
	}
	item(int value) {
		this->value = value;
		min_id = -1;
		max_id = -1;
	}
	void min_set(int num) {
		min_id = num;
	}
	void max_set(int num) {
		max_id = num;
	}
	void clear() {
		value = 0;
		min_id = -1;
		max_id = -1;
	}
};

class heap {
public:
	item* new_one;
	item* pop_num;
	item* tmp;
	vector<item*> min;
	int min_head = 1;

	vector<item*> max;
	int max_head = 1;

	void cal(string order) {

		int cur = order.find(" ");
		string menu = order.substr(0, cur);
		long long num = stoll(order.substr(cur, order.length()));
		//삽입
		int hear;
		if (menu == "I") {
			new_one=new item(num);
			//min 삽입
			new_one->min_set(min_head);
			min.at(min_head) = new_one;
			hear = min_head;
			while (min_head != 1) {
				if (hear == 1) {
					break;
				}
				int par_index = floor(hear / 2);
				if (min.at(par_index)->value > min.at(hear)->value) {
					tmp = min.at(hear);

					min.at(hear) = min.at(par_index);
					min.at(hear)->min_set(hear);

					min.at(par_index) = tmp;
					hear = par_index;
					min.at(hear)->min_set(hear);
					new_one->min_set(hear);
				}
				else {
					break;
				}
			}
			min_head++;
			//max 삽입
			new_one->max_set(max_head);
			max.at(max_head) = new_one;
			hear = max_head;
			while (max_head != 1) {
				if (hear == 1) {
					break;
				}
				int par_index = floor(hear / 2);
				if (max.at(par_index)->value < max.at(hear)->value) {
					//cout << "부모가 더 작아요"<< max.at(par_index)->max_id <<"/"<< max.at(hear)->max_id << "\n";
					tmp = max.at(hear);
					max.at(hear) = max.at(par_index);
					max.at(hear)->max_set(hear);

					max.at(par_index) = tmp;
					hear = par_index;
					new_one->max_set(hear);
					max.at(hear)->max_set(hear);
				}
				else {
					break;
				}
			}
			max_head++;
		}
		
		if (menu == "D") {

			if (min_head <= 1 || max_head <= 1)
			{
				return;
			}
			//최솟값 추출
			if (num < 0) {
				pop_num = min_pop();
				
				
				//max에서 min_pop값을 찾아서 최대값으로 설정하여 heap 재구성
				max[pop_num->max_id]->value = (max[1]->value) + 1;

				int hear = pop_num->max_id;

				while (true) {
					if (hear == 1) {
						break;
					}
					int par_index = floor(hear / 2);
					if (max.at(par_index)->value < max.at(hear)->value) {
						tmp = max.at(hear);
						max.at(hear) = max.at(par_index);
						max.at(hear)->max_set(hear);

						max.at(par_index) = tmp;
						hear = par_index;
						max.at(hear)->max_set(hear);

					}
					else {
						break;
					}
				}

				//max_pop수행
				max_pop();
			}
			//최댓값 추출
			else {
	
				pop_num = max_pop();
				//min에서 max_pop값을 찾아서 최솟값으로 설정하여 heap 재구성
				min[pop_num->min_id]->value = (min[1]->value) - 1;
				int hear = pop_num->min_id;
				while (true) {
					if (hear == 1) {
						break;
					}
					int par_index = floor(hear / 2);
					if (min.at(par_index)->value > min.at(hear)->value) {
						tmp = min.at(hear);
						min.at(hear) = min.at(par_index);
						min.at(hear)->min_set(hear);

						min.at(par_index) = tmp;
						hear = par_index;
						min.at(hear)->min_set(hear);
					}
					else {
						break;
					}
				}
				//min_pop수행
				min_pop();
			}
		
		}
	}
	item* min_pop() {
		item *num = min[1];
		if (min_head == 1) {
			return num;
		}

		min_head--;
		min[1] = min[min_head];
		min[1]->min_set(1);
		int hear = 1;
		while (true) {
			int left = hear * 2;
			int right = (hear * 2) + 1;
			item *tmp = min[hear];
			if (right < min_head) {
				if (min[left]->value < min[right]->value) {
					if (min[left]->value < min[hear]->value) {
						min[hear] = min[left];
						min[hear]->min_set(hear);

						min[left] = tmp;
						hear = left;
						min[hear]->min_set(hear);
						continue;
					}
				}
				else {
					if (min[right]->value < min[hear]->value) {
						min[hear] = min[right];
						min[hear]->min_set(hear);

						min[right] = tmp;
						hear = right;
						min[hear]->min_set(hear);
						continue;
					}
				}
			}
			else if (left < min_head) {
				
				if (min[left]->value < min[hear]->value) {
					
					min[hear] = min[left];
					min[hear]->min_set(hear);

					min[left] = tmp;
					hear = left;
					min[hear]->min_set(hear);
					continue;
				}
			}
			break;
		}
		return num;
	}
	item* max_pop() {
		item *num = max[1];
		if (max_head == 1) {
			return num;
		}
		max_head--;
		max[1] = max[max_head];
		max[1]->max_set(1);
		int hear = 1;
		while (true) {
			int left = hear * 2;
			int right = (hear * 2) + 1;
			item *tmp = max[hear];
			if (right < max_head) {
				if (max[left]->value > max[right]->value) {
					if (max[left]->value > max[hear]->value) {
						max[hear] = max[left];
						max[hear]->max_set(hear);

						max[left] = tmp;
						hear = left;
						max[hear]->max_set(hear);
						continue;
					}
				}
				else {
					if (max[right]->value > max[hear]->value) {
						max[hear] = max[right];
						max[hear]->max_set(hear);

						max[right] = tmp;
						hear = right;
						max[hear]->max_set(hear);
						continue;
					}
				}
			}
			else if (left < max_head) {
			
				if (max[left]->value > max[hear]->value) {
					max[hear] = max[left];
					max[hear]->max_set(hear);

					max[left] = tmp;
					hear = left;
					max[hear]->max_set(hear);
					continue;
				}
			}
			break;
		}

		return num;
	}
	void resize_arr(int num) {
		//배열 길이 수정
		min.resize(num);
		max.resize(num);
	}
	void answer() {
		if (min_head == 1) {
			cout << "EMPTY";
		}
		else {
			cout << max_pop()->value << " " << min_pop()->value;
		}
	}
	void print_arr() {
		//최솟값 추출
		
		for (int i = 1; i < min.size(); i++) {
			if(min.at(i)!=nullptr)
			cout <<"(val "<<min.at(i)->value<<"  MIN: " <<min.at(i)->min_id <<"  MAX: " <<min.at(i)->max_id <<")\t";
		}
		cout << "\n---------\n";
		//최댓값 추출
		for (int i = 1; i < max.size(); i++) {
			if (max.at(i) != nullptr)
			cout << "(val " << max.at(i)->value << "  MIN: " << max.at(i)->min_id << "  MAX: " << max.at(i)->max_id << ")\t";
		}
	}
};
int main()
{
	int cnt;
	int order_cnt;
	string order;
	cin >> cnt;
	heap* data = new heap[cnt];
	for (int i = 0; i < cnt; i++) {
		cin >> order_cnt;
		cin.ignore();
		data[i].resize_arr(order_cnt + 1);
		for (int j = 0; j < order_cnt; j++) {
			getline(cin, order);
			data[i].cal(order);
		}
	}
	for (int i = 0; i < cnt; i++) {
		//data[i].print_arr();
		data[i].answer();
		cout << "\n";
	}


}

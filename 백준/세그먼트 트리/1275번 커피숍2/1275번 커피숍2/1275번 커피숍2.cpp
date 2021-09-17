// 2042번 구간 합 구하기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

#include <iostream>
#include <vector>

using namespace std;

vector<long long> list;
class Node {
public:
	Node* left;
	Node* right;
	long long start, end, mid;
	long long num;
	Node(int start, int end) :start(start), end(end) {
		mid = (start + end) / 2;
		//cout << start << "/" << end << "\n";
	}
};

class Tree {
public:
	Node* root;
	Tree(int start, int end) {
		root = new Node(start, end);
	}
	long long init(Node* node) {
		if (node->start == node->end) {
			node->num = list.at(node->start);
			return node->num;
		}
		else {
			node->left = new Node(node->start, node->mid);
			node->right = new Node((node->mid) + 1, node->end);
			node->num = init(node->left) + init(node->right);
			return node->num;
		}
	}
	long long query(Node* node, long long start, long long end) {
		if (node->start == start && node->end == end) {
			return node->num;
		}
		if (node->mid < end) {
			if (node->mid < start) {
				//비교적 큰인덱스, 그냥 보내기
				return query(node->right, start, end);
			}
			else if (node->mid >= start) {
				//쪼개서 보내기
				return query(node->left, start, node->mid) + query(node->right, (node->mid) + 1, end);
			}
		}
		else {
			return query(node->left, start, end);
			//비교적 작은인덱스 , 그냥 보내기
		}
	}
	void update(Node* node, long long point, long long change) {
		node->num += change;
		if (node->start == node->end) {
			list.at(point) += change;
			return;
		}
		if (node->mid < point) {
			if(node->right!=nullptr)
			update(node->right, point, change);
		}
		else {
			if (node->left != nullptr)
			update(node->left, point, change);
		}
	}
	void print(Node* node) {
		cout << node->num << ":" << node->start << "/" << node->end << "\n";
		if (node->left != nullptr) {
			print(node->left);
		}
		if (node->right != nullptr) {
			print(node->right);
		}
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	long long start, end;
	long long point, change;
	long long num;
	Tree* tree;
	vector<long long> answer;
	cin >> N >> M;
	tree = new Tree(0, N - 1);
	for (int i = 0; i < N; i++) {
		cin >> num;
		list.push_back(num);
	}
	tree->init(tree->root);
	for (int j = 0; j < M; j++) {
		cin >> start >> end>> point >> change;
		if (start > end) {
			int tmp = end;
			end = start;
			start =tmp;
		}
		answer.push_back(tree->query(tree->root, start-1, end-1));
		tree->update(tree->root, point - 1, (change - list.at(point - 1)));
	}
	for (auto i : answer) {
		cout << i << "\n";
	}
	//tree->print(tree->root);
}

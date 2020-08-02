#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct Node* treePointer;
typedef struct Node{
	int id;
	int x, y;
	treePointer leftChild;
	treePointer rightChild;
} Node;

bool cmp(Node& a, Node& b) {
	if ( a.y == b.y) return a.x < b.x;
	return a.y > b.y;
}

void insertNode(treePointer parent, treePointer child) {
	if (parent->x > child->x) {
		if (parent->leftChild == NULL) parent->leftChild = child;
		else insertNode(parent->leftChild, child);
	}
	else {
		if (parent->rightChild== NULL) parent->rightChild = child;
		else insertNode(parent->rightChild, child);
	}
}
void preorder(vector<int>& ans, treePointer ptr) {
	if (ptr== NULL) return;
	ans.push_back(ptr->id);
	preorder(ans, ptr->leftChild);
	preorder(ans, ptr->rightChild);
}
void postorder(vector<int>& ans, treePointer ptr) {
	if (ptr == NULL) return;
	postorder(ans, ptr->leftChild);
	postorder(ans, ptr->rightChild);
	ans.push_back(ptr->id);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	int size = nodeinfo.size();
	vector<Node> nodes;

	for (int i = 0; i < nodeinfo.size(); ++i) 
		nodes.push_back({ i + 1, nodeinfo[i][0], nodeinfo[i][1] });
	
	sort(nodes.begin(),nodes.end(), cmp);
	
	treePointer root = &nodes[0]; // 0번째 값 - 루트
	vector<vector<int>> answer{ {},{} };
	for (int i = 1; i < size; i++) {
		insertNode(root, &nodes[i]);
	}
	preorder(answer[0], root);
	postorder(answer[1], root);
	for (int i = 0; i < answer.size(); i++) {
		for (int j = 0; j < answer[i].size(); j++) {
			cout << answer[i][j] << " ";
		}
		cout << "\n";
	}
	return answer;
}

int main() {
	solution({{ 5, 3 }, { 11, 5 }, { 13, 3 }, { 3, 5 }, { 6, 1 }, { 1, 3 }, { 8, 6 }, { 7, 2 }, { 2, 2 }});
	return 0;
}
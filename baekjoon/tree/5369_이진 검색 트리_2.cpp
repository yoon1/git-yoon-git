// 먼저 tree구조를 만들어놓고 시작하는 방법.
#include <iostream>
using namespace std;
struct Node {
	int data;
	Node* left;
	Node* right;
}; 

Node* insert(Node* node, int data) {
	if (node == NULL) {
		node = new Node();
		node->data = data;
		node->left = node->right = NULL;
	}
	else if (data <= node->data)
		node->left = insert(node->left, data);
	else
		node->right = insert(node->right, data);
	return node;
} 

void postorder(Node* node) {
	if (node->left != NULL)
		postorder(node->left);
	if (node->right != NULL)
		postorder(node->right);
	cout << node->data << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Node* root = NULL;
	int x;
	while (cin >> x) {
		root = insert(root, x);
	}
	postorder(root);
	return 0;
}
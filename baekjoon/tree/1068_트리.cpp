#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 52

using namespace std;

typedef struct tree
{
	int val; // ��
	int parent; // �θ� ���
	vector<int> child; // �ڽ� ���(������ ���� �� ����)
}TREE;

queue<int> q;
TREE tree[MAX];


int bfs(int root) {
	int count= 0;
	q.push(root);
	while (!q.empty()) { // visited üũ�� �����൵ �Ǵ� ���� : �θ���� �ϳ�
		int here = q.front();
		q.pop();
		if (tree[here].child.empty()) count++;
		for(int i=0; i < tree[here].child.size(); i++)
			q.push(tree[here].child[i]);
	}
	q.push(root);
	return count;
}
int main()
{
	int n, root;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tree[i].val);
		if (tree[i].val == -1) {
			root = i;
			continue;
		}
		else {
			int p = tree[i].val; // parent
			int c = i; // child
			tree[c].parent = p;
			tree[p].child.push_back(c);
		}
	}

	int remove;
	scanf("%d", &remove);

	if (remove == root) { // root�� �ϳ���� ����
		printf("0");
		return 0;
	}

	tree[remove].child.clear(); // �ڽ� ��� �����
	int parent = tree[remove].parent; // �ڽ��� �ڽĳ��� ������ �ִ� �͵� �����
	for (int i = 0; i < tree[parent].child.size(); i++) {
		if (tree[parent].child[i] == remove)
			tree[parent].child.erase(tree[parent].child.begin() + i);
	}

	printf("%d", bfs(root));

}
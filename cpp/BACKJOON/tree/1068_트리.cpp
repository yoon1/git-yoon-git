#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 52

using namespace std;

typedef struct tree
{
	int val; // 값
	int parent; // 부모 노드
	vector<int> child; // 자식 노드(여러개 있을 수 있음)
}TREE;

queue<int> q;
TREE tree[MAX];


int bfs(int root) {
	int count= 0;
	q.push(root);
	while (!q.empty()) { // visited 체크를 안해줘도 되는 이유 : 부모노드는 하나
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

	if (remove == root) { // root가 하나라는 가정
		printf("0");
		return 0;
	}

	tree[remove].child.clear(); // 자식 노드 지우기
	int parent = tree[remove].parent; // 자신을 자식노드로 가지고 있는 것도 지우기
	for (int i = 0; i < tree[parent].child.size(); i++) {
		if (tree[parent].child[i] == remove)
			tree[parent].child.erase(tree[parent].child.begin() + i);
	}

	printf("%d", bfs(root));

}
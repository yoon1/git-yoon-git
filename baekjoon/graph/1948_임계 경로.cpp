#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001

using namespace std;

class Edge { 
public :
	int node; // ���� ���
	int time; // ���
	Edge(int node, int time) {
		this->node = node;
		this->time = time;
	}
};

int n, start, finish; // ���� ����, ������, ������
int inDegree[MAX], result[MAX], c[MAX]; // ��������, �����, ó������� ����(�Ӱ� ��ο� ��� ��带 �ѹ����� ó���ϱ� ����)
vector<Edge> a[MAX]; 
vector<Edge> b[MAX]; // �������� ����
// a : ������->������
// b : ������->������

void topologySort() {
	queue<int> q;
	// ������ ��带 q�� ����
	q.push(start);
	// ���̻� �湮�� ��尡 ����������
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < a[x].size(); i++) {
			Edge y = Edge(a[x][i].node, a[x][i].time); 
			if (result[y.node] <= y.time + result[x]) {
				result[y.node] = y.time + result[x]; // �Ӱ��δ� �׻� ���� ���� ��� ���� ��.
			}
			// ���Ӱ� ���������� 0�� �� ������ ť�� ����
			if (--inDegree[y.node] == 0) { // ����� ����� ���� ������ 1�� ����� ��.
				q.push(y.node);
			}
		}
	}
	// ����� ������
	int count = 0; // �Ӱ� ��ο� ���� ��� ������ ����
	q.push(finish);
	while (!q.empty()) {
		int y = q.front();
		q.pop();
		for (int i = 0; i < b[y].size(); i++) { // ���������� �ݴ�� ���������� ��.
			Edge x = Edge(b[y][i].node, b[y][i].time); 
			// ���� ��ο� ���Ե� �������� Ȯ���Ѵ�.
			if (result[y] - result[x.node] == x.time) {
				count++;
				// queue���� �� ������ ��� �����Ѵ�.
				if (c[x.node] == 0) {
					q.push(x.node); // q���� ���� 1������ ��� �� �ִ�.
					c[x.node] = 1;
				}
			}

		}
	}
	printf("%d\n%d", result[finish], count);
}
int main() {
	int m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, node, time;
		scanf("%d %d %d", &x, &node, &time);
		a[x].push_back(Edge(node, time));
		b[node].push_back(Edge(x, time));
		inDegree[node]++;
	}
	scanf("%d %d", &start, &finish);
	topologySort();
	return 0;
}

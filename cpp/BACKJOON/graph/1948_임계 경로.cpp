#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001

using namespace std;

class Edge { 
public :
	int node; // 도착 노드
	int time; // 비용
	Edge(int node, int time) {
		this->node = node;
		this->time = time;
	}
};

int n, start, finish; // 정점 개수, 시작점, 도착점
int inDegree[MAX], result[MAX], c[MAX]; // 진입차수, 결과값, 처리됬는지 여부(임계 경로에 담긴 노드를 한번씩만 처리하기 위해)
vector<Edge> a[MAX]; 
vector<Edge> b[MAX]; // 역추적을 위한
// a : 시작점->도착점
// b : 도착점->시작점

void topologySort() {
	queue<int> q;
	// 시작점 노드를 q에 삽입
	q.push(start);
	// 더이상 방문할 노드가 없을때까지
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < a[x].size(); i++) {
			Edge y = Edge(a[x][i].node, a[x][i].time); 
			if (result[y.node] <= y.time + result[x]) {
				result[y.node] = y.time + result[x]; // 임계경로는 항상 많은 값이 드는 것이 들어감.
			}
			// 새롭게 진입차수가 0이 된 정점을 큐에 삽입
			if (--inDegree[y.node] == 0) { // 연결된 노드의 진입 차수는 1을 빼줘야 함.
				q.push(y.node);
			}
		}
	}
	// 결과를 역추적
	int count = 0; // 임계 경로에 속한 모든 정점의 개수
	q.push(finish);
	while (!q.empty()) {
		int y = q.front();
		q.pop();
		for (int i = 0; i < b[y].size(); i++) { // 도착점에서 반대로 시작점으로 감.
			Edge x = Edge(b[y][i].node, b[y][i].time); 
			// 최장 경로에 포함된 간선인지 확인한다.
			if (result[y] - result[x.node] == x.time) {
				count++;
				// queue에는 한 번씩만 담아 추적한다.
				if (c[x.node] == 0) {
					q.push(x.node); // q에는 오직 1번씩만 담길 수 있다.
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

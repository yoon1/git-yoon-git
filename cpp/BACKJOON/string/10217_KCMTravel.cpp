#include <iostream>
#include <queue>
#include <vector>

#define MAX 101
#define MAX2 10001
#define INF 1e8

using namespace std;

struct airport{
	int next;
	int cost;
	int distance;
};

int T;
int N, M, K;
int dist[MAX][MAX2]; // �Ÿ� ��

vector<airport> graph[MAX];

int dijkstra(int start) {
	// dist �迭 �ʱ�ȭ
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX2; j++)
			dist[i][j] = INF;

	dist[start][0] = 0; // start���� start�� ���� ����� 0�̰�, �Ÿ��� 0��

	priority_queue<pair<pair<int, int>, int>> pq; // pq ����
	pq.push({ {0, start}, 0 }); // �ʱⰪ �������! dist�� �� �տ� ���� vertex, ��� ����.

	while (!pq.empty()) {
		int cur_distance = -pq.top().first.first;
		int cur = pq.top().first.second;
		int cur_cost = pq.top().second;

		pq.pop();

		if (dist[cur][cur_cost] < cur_distance) continue;
		
		for (auto i : graph[cur]) {
			int next = i.next;
			int next_cost = i.cost;
			int next_distance = i.distance;

			if (cur_cost + next_cost > M) continue; // ��� �ʰ��ϸ� �ݿ����� ����.
			
			int sum_cost = cur_cost + next_cost; // sum : ��� ��
			
			if (dist[next][sum_cost] > dist[cur][cur_cost] + next_distance) {
				dist[next][sum_cost] = dist[cur][cur_cost] + next_distance;
				pq.push({ {-dist[next][sum_cost], next}, sum_cost });
			}
		}
	}

	int ret = INF;

	for (int i = 0; i <= M; i++) {
		if (dist[N][i] != INF)
			ret = min(ret, dist[N][i]);
	}
	return ret;
}

int main() {
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		scanf("%d %d %d", &N, &M, &K);

		for (int i = 0; i < N; i++) 
			graph[i].clear();

		for (int k = 0; k < K; k++) {
			int u, v, c, d;
			scanf("%d %d %d %d", &u, &v, &c, &d);
			graph[u].push_back({ v,c,d });
		}

		int result = dijkstra(1); // 1�� ���� ����~!

		if (result == INF)
			printf("Poor KCM\n");
		else
			printf("%d\n", result);
	}
	return 0;
}
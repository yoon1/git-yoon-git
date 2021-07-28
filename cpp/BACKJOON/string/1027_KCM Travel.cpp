#include <iostream>
#include <queue>
#include <vector>

#define MAX 101
#define INF 1e9

using namespace std;

struct airport
{
	int next;
	int cost;
	int distance;
};

int N, M, K;
int dist[MAX][10001]; // distance를 저장하는 배열
vector<airport> graph[MAX];

int dijstra(int start) {
	for (int i = 0; i < MAX; i++) {
		fill(dist[i], dist[i] + 10001, INF); // all INF로 초기화~!
	}

	dist[start][0] = 0;

	priority_queue < pair<pair<int, int>, int>> pq;
	pq.push({ {0, start}, 0 }); // ( (cur, distance) , cost ) 
	while (!pq.empty()) {
		int distance = -pq.top().first.first; // 거리 
		int cur = pq.top().first.second;  // 공항
		int cost = pq.top().second; // 비용

		pq.pop();

		if (dist[cur][cost] < distance) continue; // 작으면 continue;

		for (auto i : graph[cur]) {
			int next = i.next;
			int next_cost = i.cost;
			int next_distance = i.distance;

			if (cost + next_cost > M) continue; // 비용보다 작아야 함

			int sum = cost + next_cost;

			if (dist[next][sum] > dist[cur][cost] + next_distance) {
				dist[next][sum] = dist[cur][cost] + next_distance;
				pq.push({ {-dist[next][sum], next}, sum });
			}
		}
	}

	int ret = INF;

	for (int i = 0; i <= M; i++)
		if (dist[N][i] != INF)
			ret = min(ret, dist[N][i]);

	return ret;
}

int main() {
	int T;
	scanf("%d", &T);

	for (int testCase = 0; testCase < T; testCase++) {
		int u, v, c, d;

		for (int i = 0; i < MAX; i++) {
			graph[i].clear();
		}

		scanf("%d %d %d", &N, &M, &K);

		for (int i = 0; i < K; i++) {
			scanf("%d %d %d %d", &u, &v, &c, &d);
			graph[u].push_back({ v,c,d });
		}

		int g = dijstra(1);

		if (g == INF)
			printf("Poor KCM\n");
		else
			printf("%d\n", g);
	}
	return 0;
}
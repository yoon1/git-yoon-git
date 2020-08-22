#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

const int UNCONNECTED = 987654321;
vector<pair<int, int>> graph[20001];
int dist[20001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E; // 정점 갯수 V와 간서느이 개수 E
	int start; // 시작 정점
	
	// 입력
	cin >> V >> E >> start;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v,w }); // 도착점과 가중치
	}

	// disatnce 배열 초기화
	for (int i = 1; i <= V; i++) 
		dist[i] = UNCONNECTED;
	
	// 다익스트라
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start)); 
	// first : 가중치, second : 현재 정점(초기값 : 시작 정점 )
	dist[start] = 0; // 0 -> 0 은 0
	while (pq.empty() == 0) {
		int cost = -pq.top().first; // minus 값을 넣어야 minheap을 구현할 수 있음.
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first; // next정점
			int next_cost = graph[cur][i].second; // next정점의 가중치
			if (dist[next] > cost + next_cost) // 현재 cost와 다음 cost를 합한 값이 더 작으면?
			{
				dist[next] = cost + next_cost; // 갱신
				pq.push(make_pair(-dist[next], next)); // 우선순위 큐에 next값을 넣는다.
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		cout << ((dist[i] != UNCONNECTED) ? to_string(dist[i]) : "INF") << "\n";
	}
	return 0;
}
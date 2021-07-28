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

	int V, E; // ���� ���� V�� �������� ���� E
	int start; // ���� ����
	
	// �Է�
	cin >> V >> E >> start;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v,w }); // �������� ����ġ
	}

	// disatnce �迭 �ʱ�ȭ
	for (int i = 1; i <= V; i++) 
		dist[i] = UNCONNECTED;
	
	// ���ͽ�Ʈ��
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start)); 
	// first : ����ġ, second : ���� ����(�ʱⰪ : ���� ���� )
	dist[start] = 0; // 0 -> 0 �� 0
	while (pq.empty() == 0) {
		int cost = -pq.top().first; // minus ���� �־�� minheap�� ������ �� ����.
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first; // next����
			int next_cost = graph[cur][i].second; // next������ ����ġ
			if (dist[next] > cost + next_cost) // ���� cost�� ���� cost�� ���� ���� �� ������?
			{
				dist[next] = cost + next_cost; // ����
				pq.push(make_pair(-dist[next], next)); // �켱���� ť�� next���� �ִ´�.
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		cout << ((dist[i] != UNCONNECTED) ? to_string(dist[i]) : "INF") << "\n";
	}
	return 0;
}
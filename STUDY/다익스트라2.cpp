#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int number = 6;
int INF = 10000000;

vector<pair<int, int> > a[7]; // 간선 정보(간선 6개)
int d[7]; // 최소 비용

// O(N*logN) 평균적인
// O(N*N
void dijkstra(int start) {
	d[start] = 0; // 자기 자신으로 가는 건 0.
	priority_queue<pair<int, int> > pq; // 힙 구조.
	pq.push(make_pair(start, 0)); // (노드, 값)
	// 가까운 순서대로 처리하므로 큐 사용.
	while (!pq.empty()) { // pq가 비어있지 않다면 계속해서 하나씩 꺼내게 됨.
		int current = pq.top().first; // 가장 적은 비용이 드는 노드 정보가 들어있음.
		// 짧은 것이 먼저 오도록 하기 위해 음수화(-) 합니다. (왜냐면 C++의 pq가최대 힙이라서..)
		int distance = -pq.top().second;
		pq.pop();
		// 최단 거리가 아닌 경우에는 skip
		if (d[current] < distance) continue;
		for (int i = 0; i < a[current].size(); i++) {
			// 선택된 노드의 인접 노드
			int next = a[current][i].first;
			cout << current << "," << next << endl;
			// 선택된 노드를 인접 노드로 거쳐서 가는 비용
			int nextDistance = distance + a[current][i].second;
			// 기존의 최소 비용보다 더 저렴하다면 교체.
			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance)); // 새롭게 갱신된 값.
			}
		}
	}
}

int main() {
	// 안갔던 길은 max
	for (int i = 1; i <= number; i++) {
		d[i] = INF;
	}
	
	// graph
	a[1].push_back(make_pair(2, 2)); 
	a[1].push_back(make_pair(3, 5));
	a[1].push_back(make_pair(4, 1));

	a[2].push_back(make_pair(1, 2));
	a[2].push_back(make_pair(3, 3));
	a[2].push_back(make_pair(4, 2));

	a[3].push_back(make_pair(1, 5));
	a[3].push_back(make_pair(2, 3));
	a[3].push_back(make_pair(4, 3));
	a[3].push_back(make_pair(5, 1));
	a[3].push_back(make_pair(6, 5));

	a[4].push_back(make_pair(1, 1));
	a[4].push_back(make_pair(2, 2));
	a[4].push_back(make_pair(3, 3));
	a[4].push_back(make_pair(5, 1));

	a[5].push_back(make_pair(3, 1));
	a[5].push_back(make_pair(4, 1));
	a[5].push_back(make_pair(6, 2));

	a[6].push_back(make_pair(3, 5));
	a[6].push_back(make_pair(5, 2));
	
	dijkstra(1);
	// 결과 출력

	for (int i = 1; i <= number; i++) {
		cout << d[i] << " ";
	}

	return 0;
}

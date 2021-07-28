#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> graph[32002];
int N, M;

void topologicalSort(vector<int> &cntOfLink) {
	queue<int> q;
	// 초기 : 선행 점점을 갖지 않는 정점을 queue에 삽입
	for (int i = 1; i <= N ; i++) 
		if (cntOfLink[i] == 0) 	// 해당 정점의 간선의 수가 0이면?
			q.push(i);
		
	// 정점의 수 만큼 반복
	for (int i = 0; i < N; i++) {
		// 1. queue에서 정점 추출
		int v = q.front(); 
		q.pop();
		cout << v << " "; // 정점 출력
		
		// 2. 정점과 연결된 모든 정점에 대해서
		for (int nextV : graph[v]) {
			// 2-1 간선의 수 감소
			cntOfLink[nextV]--; 

			// 2-2 선행 정점을 갖지 않는 정점을 queue에 삽입
			if (cntOfLink[nextV] == 0) // 해당 정점의 간선의 수가 0이면
				q.push(nextV);
		}
	}
}

int main() {
	cin >> N >> M;
	// 간선의 수에 대한 배열
	vector<int> cntOfLink(N+1,0);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		cntOfLink[b]++;
	}
	topologicalSort(cntOfLink);
	return 0;

}
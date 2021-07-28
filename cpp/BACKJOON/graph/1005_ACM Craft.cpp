#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#define MAX 1001

using namespace std;

int N, K;
int times[MAX];
int visited[MAX];
bool graph[MAX][MAX];

int solution(int destination) {
	int &result = visited[destination];
	if (result != -1) return result;

	int time = 0;
	for (int i = 1; i <= N; i++)
		if (graph[i][destination])
			time = max(time, solution(i));

	return result = time + times[destination];
}

int main() {
	int T;
	cin >> T;
	for(int testCase= 0; testCase < T; testCase++){
		int dest;
		cin >> N >> K;

		for (int i = 1; i <= N; i++)
			cin >> times[i];

		memset(visited, -1, sizeof(visited));
		memset(graph, 0, sizeof(graph));

		for (int i = 0; i < K; i++) {
			int a, b; cin >> a >> b;
			graph[a][b] = true;
		}

		cin >> dest;

		cout << solution(dest) << endl;
	}
}
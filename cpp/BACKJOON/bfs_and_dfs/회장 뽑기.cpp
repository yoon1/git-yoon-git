#include <iostream>
#include <vector>
#include <queue>
#define MAX 51

using namespace std;

priority_queue<pair<int, int>> pq;
vector<int> friends[MAX];
int N;

int bfs(int start) {
	bool visited[MAX];
	int maxDepth = 0;
	queue<pair<int, int>> q;

	for (int i = 1; i <= N; i++) {
		visited[i] = false;
	}

	q.push({ start,0 });
	visited[start] = true;
	while (!q.empty())
	{
		int cur = q.front().first;
		int cDepth = q.front().second;
		q.pop();
		maxDepth = max(cDepth, maxDepth);

		for (int i=0 ; i < friends[cur].size(); i++) {
			int next = friends[cur][i];
			if (visited[next]) continue;
			visited[next] = true;
			q.push({ next, cDepth + 1 });
		}
	}

	return maxDepth;
}

int main() {
	cin >> N;
	int a, b;
	while(true)
	{
		cin >> a >> b;
		if (a == -1 && b == -1) 
			break;
		friends[a].push_back(b);
		friends[b].push_back(a); // 양방향
	}

	// 순회
	for (int i = 1; i <= N; i++) {
		pq.push({ -bfs(i), i });
	}

	// 점수
	int score = pq.top().first;
	priority_queue<int> candidates;
	while (!pq.empty() && score == pq.top().first)
	{
		candidates.push(-pq.top().second);
		pq.pop();
	}

	// 출력
	cout << -score << " " << candidates.size() << "\n";
	while (!candidates.empty())
	{
		cout << -candidates.top() << " ";
		candidates.pop();
	}
	return 0;
}
#include <iostream>
#include <vector>
#define MAX 1000
using namespace std;

int c[MAX+1]; 
vector<int> graph[MAX+1];

void dfs(int x) {
	if (c[x]) return; 
	c[x] = true; 
	for (int i = 0; i < graph[x].size(); i++) { 
		int y = graph[x][i];
		dfs(y);
	}
}
int main() {
	std::ios_base::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	int count = 0;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v); 
		graph[v].push_back(u); 
	}

	for (int i = 1; i <= N; i++) {
		if (c[i] == false) {
			count++;
			dfs(i); 
		}
	}
	cout << count << endl;
	return 0;
}


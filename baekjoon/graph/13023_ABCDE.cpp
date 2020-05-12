#include <iostream>
#include <vector>
#define MAX 2000

using namespace std;

vector<int> people[MAX];
int N, M;
bool visited[2000];
bool flag = false;

void init() {
	for (int i = 0; i < N; i++) 
		visited[i] = false;
}

void dfs(int x, int cnt) {
	if (visited[x])
		return;
	if (cnt == 5) {
		flag = true;
		return;
	}
	visited[x] = true;
	for (int i = 0; i < people[x].size(); i++) {
		dfs(people[x][i], cnt+1);
	}
	visited[x] = false;
}

int main() {
	
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		people[a].push_back(b);
		people[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		init();
		dfs(i,1);
		if (flag){
			cout << "1" << endl;
			return 0;
		}
	}
	cout << "0" << endl;
	
	return 0;
}
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 100001;
typedef struct line {
	int M2;
	int d;
}Line;

bool visited[MAX];
int maxLength;
int maxNode;
vector<Line> v[MAX]; // 10000?

void dfs(int x, int curLength) {
	if (visited[x]) return;
	visited[x] = true;
	if (maxLength < curLength) {
		maxLength = curLength;
		maxNode = x;
	}
	for (int i = 0; i < v[x].size(); i++) {
		dfs(v[x][i].M2, curLength + v[x][i].d);
	}
}
int main() {
	int N=0, M1=0, M2=0, d=0;
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> M1 >> M2 >> d;
		v[M1].push_back({ M2, d });
		v[M2].push_back({ M1, d });
	}
	memset(visited, false, sizeof(visited));
	dfs(1, 0);
	memset(visited, false, sizeof(visited));
	maxLength = 0;
	dfs(maxNode, 0);

	cout << maxLength;
	return 0;
}
//


#include <iostream>
#include <queue>

using namespace std;

int main() {
	queue<pair<int, int>> que; 
	int N;
	int K;
	bool visited[100001] = {false,};

	ios::sync_with_stdio(false);

	cin >> N >> K;

	que.push({ N, 0 });

	while (!que.empty()) {
		int Np = que.front().first;
		int depth = que.front().second;
		cout << "(NO, DEPTH) : (" << Np << "," << depth << ")" << endl;

		que.pop();

		if (Np == K) {
			cout << depth;
			break;
		};
		if (Np < 0 || Np > 100000 || visited[Np] == true) continue;
		else visited[Np] = true;
		
		que.push({ Np - 1, depth + 1 });
		que.push({ Np + 1, depth + 1 });
		que.push({ Np * 2, depth + 1 });
	}
	return 0;
}

#include <iostream>
#include <queue>

using namespace std;

int main() {
	queue<pair<int, int>> que;
	int N;
	int K;
	bool visited[100001] = { false, };
	int minDepth = 0;
	int count = 0;
	int priorDepth = 0;

	ios::sync_with_stdio(false);

	cin >> N >> K;

	que.push({ N, 0 });

	while (!que.empty()) {
		int Np = que.front().first;
		int depth = que.front().second;

		if (count != 0 && minDepth < depth) break;

		que.pop();

		if (Np == K) {
			if (count == 0) {
				minDepth = depth;
				count++;
			}
			else if (minDepth == depth) {
				count++;
			}
			continue;
		};

		if (visited[Np] == true && depth != priorDepth) { continue; }
		else { visited[Np] = true; }

		if(Np > 0 && visited[Np -1 ] != true)  que.push({ Np - 1, depth + 1 });
		if (Np < 100000  && visited[Np + 1] != true)   que.push({ Np + 1, depth + 1 });
		if (Np * 2 <= 100000 && visited[Np * 2] != true) que.push({ Np * 2, depth + 1 });
		priorDepth = depth;
	}
	
	printf("%d\n", minDepth);
	printf("%d\n", count);
	return 0;
}

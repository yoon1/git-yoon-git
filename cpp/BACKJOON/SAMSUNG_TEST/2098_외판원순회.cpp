#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

const int UNCONNECTED = 987654321;
int n;
int cost[16][16];
int dp[16][1 << 16];
int end_state;

int tsp(int x, int state) {
	if (state == end_state)
		return cost[x][0] ? cost[x][0] : UNCONNECTED; // 처음으로 이어지는 게 있는가?
	int &ref = dp[x][state];
	if (ref != 0) return ref; // 이미 방문한 적 있으면...
	ref = UNCONNECTED;
	for (int i = 0; i < n; i++) {
		if ((state & (1 << i)) == 0 && cost[x][i] != 0) // 방문한 적 없고 cost도 있을 때
			ref = min(ref, tsp(i, state| (1 << i)) + cost[x][i]);
	}
	return ref;
}
int main() {
	scanf("%d", &n); // n을 입력 받는다.
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &cost[i][j]); // graph의 cost값을 받는다.
	end_state = (1 << n) - 1; // end는 모든 상태가 1로 바꼈을 때이다.
	printf("%d", tsp(0, 1)); // 0은 들어간 상태!
	return 0;
}

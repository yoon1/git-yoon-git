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
		return cost[x][0] ? cost[x][0] : UNCONNECTED; // ó������ �̾����� �� �ִ°�?
	int &ref = dp[x][state];
	if (ref != 0) return ref; // �̹� �湮�� �� ������...
	ref = UNCONNECTED;
	for (int i = 0; i < n; i++) {
		if ((state & (1 << i)) == 0 && cost[x][i] != 0) // �湮�� �� ���� cost�� ���� ��
			ref = min(ref, tsp(i, state| (1 << i)) + cost[x][i]);
	}
	return ref;
}
int main() {
	scanf("%d", &n); // n�� �Է� �޴´�.
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &cost[i][j]); // graph�� cost���� �޴´�.
	end_state = (1 << n) - 1; // end�� ��� ���°� 1�� �ٲ��� ���̴�.
	printf("%d", tsp(0, 1)); // 0�� �� ����!
	return 0;
}

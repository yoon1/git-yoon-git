#include <iostream>
#define number 4
#define INF 10000000
using namespace std;

// graph
int a[4][4] = {
	{0, 5, INF, 8},
	{7, 0, 9, INF},
	{2, INF, 0, 4},
	{INF, INF, 3, 0}
};

void floydWarshall() {
	// 결과 그래프를 초기화
	// k = 거쳐가는 노드
	for (int k = 0; k < number; k++) {
		// i = 출발 노드
		for (int i = 0; i < number; i++) {
			// j = 도착 노드
			for (int j = 0; j < number; j++) {
				if (a[i][k] + a[k][j] < a[i][j]) {
					a[i][j] = a[i][k] + a[k][j];
				}
			}
		}
	}

	// 결과를 출력
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			printf("%3d ", a[i][j]);
		}
		printf("\n");
	}
}
int main() {
	floydWarshall(); // 실행
	return 0;
}
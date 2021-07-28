#include <iostream>
#include <algorithm>
#define MAX 401
using namespace std;

bool dist[MAX][MAX];

int N, K, s;

int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < K; i++) {
		int p1, p2;
		scanf("%d %d", &p1, &p2);
		dist[p1][p2] = true;
	}

	for(int k = 1; k <= N; k++)
		for(int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++) 
				if(dist[i][k] && dist[k][j])
					dist[i][j] = true; // 서로 연결된 길임
	
	scanf("%d", &s);
	for (int i = 0; i < s; i++) {
		int c1, c2; 
		scanf("%d %d", &c1, &c2);
		printf("%d\n", (dist[c1][c2] ? -1 : (dist[c2][c1] ? 1 : 0)));
	}

	return 0;
}
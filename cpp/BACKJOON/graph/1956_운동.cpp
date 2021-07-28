#include <iostream>
#include <algorithm>
#define INF 2e8
//#include <vector>

using namespace std;

int V, E;
int map[401][401] = { 0 }; // map

void printf() {
	printf("==========\n");
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			printf("%3d ", map[i][j]);
		}
		printf("\n");
	}
}

void find_min() {
	int result = INF;
	for (int i = 1; i <= V; i++)
		result = min(result, map[i][i]);
	if (result == INF)
		cout << -1;
	else 
		cout << result;
}

void floydWarshal() {
	for (int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				if (map[i][k] + map[k][j] < map[i][j]) {
					map[i][j] = map[i][k] + map[k][j];
				}
			}
		}
	}
	
}

int main() {
	cin >> V >> E; 
	for (int i = 0; i <= V; i++) {
		for (int j = 0; j <= V; j++) {
			map[i][j] = INF;
		}
	}
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a][b] = c; // a -> b : c
	}

	floydWarshal();

	find_min();
	return 0;
}
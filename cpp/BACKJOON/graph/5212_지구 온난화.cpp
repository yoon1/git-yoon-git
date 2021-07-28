#include <iostream>
#include <algorithm>
#define MAX 10

using namespace std;

int R, C;
char map[MAX][MAX];
int water[MAX][MAX] = { 0 };
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,1,-1 };

void solution() {
	// water count 
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			for (int d = 0; d < 4; d++) {
				int sy = y + dy[d];
				int sx = x + dx[d];
				if (!(sy >= 0 && sy < R && sx >= 0 && sx < C) || map[sy][sx] == '.')
					water[y][x]++;
			}
		}
	}

	// fall down
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (water[y][x] >= 3)
				map[y][x] = '.';
		}
	}

	// map
	int maxY = 0, maxX = 0, minY = MAX, minX = MAX;

	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (map[y][x] == 'X') {
				maxY = max(maxY, y);
				minY = min(minY, y);
				maxX = max(maxX, x);
				minX = min(minX, x);
			}
		}
	}

	// print
	for (int y = minY; y <= maxY; y++) {
		for (int x = minX; x <= maxX; x++) {
			printf("%c", map[y][x]);
		}
		printf("\n");
	}
}

int main() {

	// input
	scanf("%d %d\n", &R, &C);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%c", &map[i][j]);
		}
		char space; scanf("%c", &space);
	}

	solution();
	return 0;
}
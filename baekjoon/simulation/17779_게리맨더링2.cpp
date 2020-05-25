#include <iostream>
#include <memory.h>
#include <algorithm>
#define INT_MAX 987654321
using namespace std;

int map[21][21]; // 점수가 있는
int zone[21][21]; // 구역
int zone_point[5];
int N;
int result = 987654321;

void init() {
	for (int i = 0; i < 5; i++)
		zone_point[i] = 0;
}

int setZone(int r, int c, int y, int x, int d1, int d2) {
	if (r < y + d1 && c <= x && !(r >= y && c >= x - r + y))
		return 0;

	else if (r <= y + d2 && c > x && !(r >= y && c <= x + r - y))
		return 1;
	
	else if (r >= y + d1 && c < x - d1 + d2 && !(r <= y + d1 + d2 && c >= (x - d1 + d2 - (y + d1 + d2 - r)))) 
		return 2;

	else if (r > y + d2 && c >= x - d1 + d2 && !(r <= y + d1 + d2 && c <= (x - d1 + d2 + (y + d1 + d2 - r))))
		return 3;

	return 4;
}
int setBoundary(int y, int x, int d1, int d2) {
	init();

	for(int r = 1; r <= N; r++){
		for (int c = 1; c <= N; c++) {
			zone_point[setZone(r, c, y, x, d1, d2)] += map[r][c];
		}
	}

	int maxValue = 0;
	int minValue = INT_MAX;
	for (int i = 0; i < 5; i++) {
		maxValue = max(maxValue, zone_point[i]);
		minValue = min(minValue, zone_point[i]);
	}
	
	return maxValue - minValue;
}

void solution() {
	for (int y = 1; y <= N-2; y++) { // x : row
		for (int x = 2; x <= N-1; x++) {  // y : col
			for (int d1 = 1; d1 <= N - y - 1 && d1 <= x - 1; d1++) {
				for (int d2 = 1; d2 <= N - y - 1 && d2 <= N - x; d2++) {
					result = min(result, setBoundary(y, x, d1, d2));
				}
			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cin >> map[i][j];
	}

	solution();
	
	cout << result << endl;
		
	return 0;
}
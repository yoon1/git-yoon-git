#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 500

using namespace std;

int N, M;

int tetromino[19][4][2] = {
	{{0,0},{0,1},{0,2},{0,3}},
	{{0,0},{1,0},{2,0},{3,0}},
	{{0,0},{0,1},{1,0},{1,1}},
	{{0,0},{1,0},{2,0},{2,1}},
	{{0,0},{0,1},{0,2},{1,0}},
	{{0,0},{0,1},{1,1},{2,1}},
	{{0,2},{1,0},{1,1},{1,2}},
	{{0,1},{1,1},{2,0},{2,1}},
	{{0,0},{0,1},{0,2},{1,2}},
	{{0,0},{0,1},{1,0},{2,0}},
	{{0,0},{1,0},{1,1},{1,2}},
	{{0,0},{1,0},{1,1},{2,1}},
	{{0,1},{0,2},{1,0},{1,1}},
	{{0,1},{1,0},{1,1},{2,0}},
	{{0,0},{0,1},{1,1},{1,2}},
	{{0,0},{0,1},{0,2},{1,1}},
	{{0,1},{1,0},{1,1},{2,1}},
	{{0,1},{1,0},{1,1},{1,2}},
	{{0,0},{1,0},{1,1},{2,0}}
};
int map[MAX][MAX];


int solution(int startY, int startX) {
	int maxValue = 0;
	for (int i = 0; i < 19; i++) {
		int sum = 0;
		for (int j = 0; j < 4; j++) {
			int curY = startY + tetromino[i][j][0]; 
			int curX = startX + tetromino[i][j][1]; 
			if (!(curY >= 0 && curX >= 0 && curY < N && curX < M))
				break;
			sum += map[curY][curX];
		}
		maxValue = max(maxValue, sum);
	}
	return maxValue;
}

int main() {
	cin >> N >> M;
	int rslt = 0;
	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			rslt = max(solution(i, j), rslt);
		}
	}

	cout << rslt;

	return 0;
}

#include<stdio.h>
#define SIZE 16 // 미로 사이즈 정의

int a[SIZE][SIZE]; // 미로판
int index[SIZE][SIZE]; // 갔던 경로
int sx, sy; // 
int dx[] = { 0, 0, -1, 1 }; // 좌표
int dy[] = { -1, 1, 0, 0 }; // 좌표 
int val;
void DFS(int y, int x) {
	if (a[y][x] == 1)
		return;
	if (a[y][x] == 3) {
		val = 1;
		return;
	}
	if (index[y][x] == 1)
		return;

	index[y][x] = 1;


	for (int i = 0; i < 4; i++) {
		DFS(y + dy[i], x + dx[i]);
	}
}

int main() {
	for (int test = 1; test <= 10; test++) {
		int t;
		scanf("%d", &t);

		for (int i = 0; i < SIZE; i++)
		{
			char t1[20];
			scanf("%s ", t1);
			for (int j = 0; j < SIZE; j++)
			{
				a[i][j] = t1[j] - '0';
				if (a[i][j] == 2) {
					sy = i;
					sx = j;
				}
				index[i][j] = 0;
			}
		}

		val = 0;
		DFS(sy, sx);

		if (val)
			printf("#%d 1\n", test);
		else
			printf("#%d 0\n", test);

	}
	return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

char chess[50][50];

char checkSqure(int row, int col, int start) {
	if ((row + col + start) % 2 == 0) return 'B';
	else return 'W';
}

int checkChess(int row, int col, int start) 
{
	int cnt = 0;
	for (int i = row; i < row + 8; i++) {
		for (int j = col; j < col + 8; j++) {
			if (chess[i][j] != checkSqure(i, j, start)) {
				cnt++;
			}
		}
	}
	return cnt;
}
int searchTotalChess(int row, int col) {
	return min(checkChess(row, col, 0), checkChess(row, col, 1));
}

int main() {
	int N, M;
	int min = 64;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> chess[i][j];
		}
	}

	for (int i = 0; i <= N - 8 ; i++) {
		for (int j = 0; j <= M - 8; j++) {
			int result = searchTotalChess(i, j);
			if (min > result) min = result;
		}
	}

	cout << min << endl;
	return 0;
}


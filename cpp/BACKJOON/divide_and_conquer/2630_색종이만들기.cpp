#include <iostream>

using namespace std;

int N;
int map[128][128];

int blue;
int white;

void search(int x1, int y1, int x2, int y2) {
	int count_blue = 0;
	int count_white = 0;
	for (int i = y1; i <= y2; i++) {
		for (int j = x1; j <= x2; j++) {
			map[i][j] == 1 ? count_blue++ : count_white++;
		}
	}
	if (count_blue == 0)
		white++;
	else if (count_white == 0)
		blue++;
	else {
		search(x1, y1, (x1 + x2) / 2, (y1 + y2) / 2); // 1
		search(((x1 + x2) / 2) + 1, y1, x2, (y1 + y2) / 2); // 2
		search(x1, ((y1 + y2) / 2 + 1), (x1 + x2) / 2, y2); // 3
		search(((x1 + x2) / 2) + 1, ((y1 + y2) / 2) + 1, x2, y2); // 4
	}
	return;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	search(0, 0, N-1,N-1);
	cout << white << "\n" << blue << "\n";
	return 0;
}
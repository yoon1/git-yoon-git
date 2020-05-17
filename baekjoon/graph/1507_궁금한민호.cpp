#include <iostream>
#include <vector>

using namespace std;

int map[20][20];
int visited[20][20];
int N;
bool flag = true;

void move() {
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j || j == k || i == k)
					continue;
				else if (map[i][j] > map[i][k] + map[k][j]) // i => j ,  i => n => j 둘중 작은것
				{
					flag = false;
					return;
				}
				else if (map[i][j] == map[i][k] + map[k][j]) {
					visited[i][j] = false;
				}
			}
		}
	}

}
int main() {
	cin >> N;
	int total = 0;
	// map input
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			visited[i][j] = true;
		}
	}

	// 이동
	move();

	if (flag) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j])
					total += map[i][j];
			}
		}
		total /= 2;
	}

	else
		total = -1;

	cout << total << "\n";
	return 0;
}
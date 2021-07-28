#include <iostream>
#include <string>
#include <vector>

using namespace std;
int n, m;

void rotate90(vector<vector<int>> &arr) {
	int ret[21][21] = {};
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			ret[j][m - i - 1] = arr[i][j];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = ret[i][j];
}

bool solution(vector<vector<int>> k, vector<vector<int>> l) {
	m = k.size(), n = l.size();
	bool result = true;
	for (int dir = 0; dir < 4; dir++) {
		for (int off_y = n - 1; off_y >= -n + 1; off_y--) {
			for (int off_x = n - 1; off_x >= -n + 1; off_x--) {
				result = true;
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						int ny = i + off_y, nx = j + off_x;
						if (ny < 0 || ny >= m || nx < 0 || nx >= m) {
							if ( l[i][j] == 0) result = false;
						}
						else {
							if ((l[i][j] == 0 & k[ny][nx] == 0) || (l[i][j] == 1 && k[ny][nx] == 1) )
								result = false;
						}
					}
				}
				if (result) return true;
			}
		}
		rotate90(k);
	}
	return false;
}

int main() {
	cout << solution({ {0, 0, 0}, { 1, 0, 0 }, { 0, 1, 1 } }, { {1, 1, 1}, {1, 1, 0}, {1, 0, 1} }) << endl;
	return 0;
}
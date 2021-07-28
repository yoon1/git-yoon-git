#include <stdio.h>
#include <vector>

using namespace std;


int N, score, cnt;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
vector<vector<int>> green(9, vector<int>(9)), blue(9, vector<int>(9));

int go(int y, int x, vector<vector<int>> &a) {
	if (!a[y][x]) return 0;

	int T = a[y][x];
	vector<pair<int, int>> v;
	v.push_back({ y,x });
	for (int d = 0; d < 4; d++) {
		if (a[y + dy[d]][x + dx[d]] == a[y][x]) 
			v.push_back({ y + dy[d], x + dx[d] });
		for (auto [x, y] : v) 
			a[x][y] = 0;
		if ( )
		
	}
}

int main() {
	scanf("%d", &N);
	for (int n = 1; n <= N; n++) {
		int t, x, y;
		scanf("%d %d %d", &t, &x, &y); 
		x++, y++;

		if ( t == 1 ) green[1][y] = blue[1][x] = n;
		if ( t == 2 ) green[1][y] = green[1][y + 1] = blue[1][x] = blue[2][x] = n;
		if ( t == 3 ) green[1][y] = green[2][y] = blue[1][x] = blue[1][x+1] = n;

		int flag = 1;
		while (flag--) {
			for (int y = 1; y <= 6; y++) {
				for (int x = 1; x <= 4; x++) 
					flag |= go(y, x, green) | go(y, x, blue);
				
			}
		}
	}
		
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			cnt += !!blue[y][x] + !!green[y][x];
		}
	}

	printf("%d\n%d", score, cnt);
	return 0;
}
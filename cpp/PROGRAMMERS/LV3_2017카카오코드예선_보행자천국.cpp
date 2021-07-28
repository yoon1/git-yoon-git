#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int MOD = 20170805;

struct pos{
	int y;
	int x;
	int d;
};
pos dir[2] = { { 0,1 },{1,0} }; // 오른쪽, 아래쪽
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
	int answer = 0;
	queue<pos> q;
//	bool visited[500][500];
	q.push({ 0, 0 });
	while (!q.empty()) {
		pos cur = q.front();
		q.pop();
		if (cur.y == m - 1 && cur.x == n - 1) {
			answer++;
		}
		int val = city_map[cur.y][cur.x]; 
		if (val == 0) {
			for (int i = 0; i < 2; i++) {
				pos next = { cur.y + dir[i].y, cur.x + dir[i].x };
				if (next.y < 0 || next.y >= m || next.x < 0 || next.x >= n) continue;
				if (city_map[next.y][next.x] == 1) continue;
				q.push({ next.y, next.x, i });
			}
		}
		else if (val == 2) {
			pos next = { cur.y + dir[cur.d].y, cur.x + dir[cur.d].x };
			if (next.y < 0 || next.y >= m || next.x < 0 || next.x >= n) continue;
			if (city_map[next.y][next.x] == 1) continue;
			q.push({ next.y, next.x, cur.d });
		}
	}
	return answer / 20170805;
}

int main() {
	cout << solution(3, 3, { {0, 0, 0}, { 0, 0, 0 }, { 0, 0, 0 }});
	//cout << solution(3, 6, { {0, 2, 0, 0, 0, 2}, {0, 0, 2, 0, 1, 0}, {1, 0, 0, 2, 2, 0}}) << endl;
	return 0;
}
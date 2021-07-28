#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct pos {
	int y1, x1;
	int y2, x2;
	int d1, d2;
};

int n;
int dy[4] = {0,1,0,-1}; // 오, 밑, 왼, 위
int dx[4] = {1,0,-1,0};

bool visited[101][101][4];

int solution(vector<vector<int>> map) {
	int answer = 0;
	n = map.size();
	queue<pos> q;
	visited[0][0][0] = visited[0][1][2] = true; // 0,0이랑 0,1은 현재 true. 각각 오/왼 을 가리키고 있음.
	q.push({ 0,0,0,1,0,2 }); 
	while (!q.empty()) {
		pos cur = q.front(); q.pop();
		if ((cur.y1 == n - 1 && cur.x1 == n - 1) || (cur.y2 == n - 1 && cur.x2 == -n - 1)) 
			return answer; // (n-1, n-1)에 도달
		// 방향 이동(오, 밑, 왼, 위)
		for (int i = 0; i < 4; i++) {
			pos next = { cur.y1 + dy[i], cur.x1 + dx[i], cur.y2 + dy[i], cur.x2 + dy[i], cur.d1, cur.d2 };
			if (!(next.y1 >= 0 && next.y2 >= 0 && next.x1 >= 0 && next.x2 >= 0
				&& next.y1 < n && next.y2 < n && next.x1 < n && next.x2 < n))
				continue;
			if (visited[next.y1][next.x1][next.d1] || visited[next.y2][next.x2][next.d2])
				continue;
			visited[next.y1][next.x1][next.d1] = visited[next.y2][next.x2][next.d2] = true;
			q.push({ next.y1, next.x1, next.y2, next.x2, next.d1, next.d2 });
		}
		
		for (int i = -1; i <= 1; i++) {
			if (i == 0) continue;
			for (int j = 0; j < 2; j++) { // ?  
				int y = next.


			}
		}
	}
	
	

	return answer;
}
int main() {
	solution({{0, 0, 0, 1, 1}, {0, 0, 0, 1, 0}, {0, 1, 0, 1, 1}, {1, 1, 0, 0, 1}, {0, 0, 0, 0, 0}}, 7);
	return 0;
}
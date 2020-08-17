#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
struct pos{
	int y;
	int x;
};
bool visited[100][100];
queue<pos> q;
int bfs(int m, int n, vector<vector<int>> &picture, int color) {
	pos dir[4] = { {0,1},{0,-1},{1,0},{-1,0} };
	int cnt = 0;
	while (!q.empty()) {
		pos cur = q.front();
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++) {
			pos next = { cur.y + dir[i].y , cur.x + dir[i].x };
			if (next.y < 0 || next.y >= m || next.x < 0 || next.x >= n) continue;
			if (visited[next.y][next.x]) continue;
			if (picture[next.y][next.x] != color) continue;
			visited[next.y][next.x] = true;
			q.push({ next.y, next.x });
		}
	}
	return cnt;
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	vector<int> answer(2);
	for (int i = 0; i < m; i++) 
		for(int j = 0; j < n; j++)
			visited[i][j] = false;
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (picture[i][j] > 0 && !visited[i][j] ) {
				number_of_area++;
				q.push({ i,j });
				visited[i][j] = true;
				max_size_of_one_area = max(bfs(m, n, picture, picture[i][j]), max_size_of_one_area);
			}
		}
	}
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}

int main() {
	vector<int> v = solution(6, 4, { {1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3} });
	cout << v[0] << "," << v[1];
	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 21
#define INF 987654321

using namespace std;


struct pos {
	int y;
	int x;
	int d;
};
int N, M;
pos dir[4] = { {0,1},{0,-1},{1,0},{-1,0} };

int bfs(pos start, int map[MAX][MAX], vector<pair<int, int>>& dust) {

	bool visited[MAX][MAX];
	int total_distance= 0;
	int idx = 0;
	pos _start= start;
	pair<int, int> dust_pos = dust[idx++];
	while (idx <= dust.size()) {
		// 초기화
		queue<pos> q;
//		cout << " dust_pos : " << dust_pos.first << "," << dust_pos.second << "\n";
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				visited[i][j] = false;
		q.push(_start);
		visited[_start.y][_start.x] = true;
		int depth = 0;
		bool flag = false;
		while (!q.empty()) {
			pos cur = q.front();
			q.pop();
			depth = max(cur.d, depth);
			if (cur.y == dust_pos.first && cur.x == dust_pos.second) {
//				cout << "먼지다!! : " << cur.y << "," << cur.x << endl;
				total_distance += depth;
//				cout << "현재 까지 total_distance : " << total_distance << endl;
				_start = { cur.y, cur.x };
				map[cur.y][cur.x] = 0;

				if (dust.size() > idx)
					dust_pos = dust[idx++];
				else
					return total_distance;
				flag = true;
				break;
			}
			for (int i = 0; i < 4; i++) {
				pos next = { cur.y + dir[i].y , cur.x + dir[i].x };
				if (!(next.y >= 0 && next.y < N && next.x >= 0 && next.x < M)) continue;
				if (!visited[next.y][next.x] && map[next.y][next.x] != -1) {
					visited[next.y][next.x] = true;
					q.push({ next.y, next.x, cur.d + 1 });
				}
			}
		}

		if (!flag)
			return -1;
	}
	return total_distance;
}

int main() {
	while (1) {
		scanf("%d %d", &M, &N);
		if (M == 0 && N == 0) break;
		int map[MAX][MAX];
		pos start;
		vector<pair<int, int>> dust;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				char c;
				scanf(" %1c", &c);
				map[i][j] = ((c == '.') ? 1 : ((c == '*') ? 0 : ((c == 'x') ? -1 : 0)));
				if (c == 'o') start = { i,j };
				if (c == '*') dust.push_back(make_pair(i,j));
			}
		}
		/* 
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}
		*/
		int min_distance = INF;
		do {
//			for (int i = 0; i < dust.size(); i++) {
//				cout << dust[i].first << "," << dust[i].second << " "  << endl;
			//}
			//cout << "\n";
			min_distance = min(bfs(start, map, dust), min_distance);
		} while (next_permutation(dust.begin(), dust.end()));
		if (min_distance == INF) cout << "-1" << "\n";
		else cout << min_distance << "\n";
	}
	return 0;
}
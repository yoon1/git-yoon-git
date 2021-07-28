#include <iostream>
#include<vector>
#include<queue>
using namespace std;

typedef struct pos{
	int y;
	int x;
	int d;
}Pos;
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
int solution(vector<vector<int> > maps)
{
	int answer = 0;
	int n = maps.size()-1; 
	int m = maps[0].size()-1;
	queue<Pos> q; 
	bool visited[100][100] = { false };
	q.push({ 0,0,1 });
	visited[0][0] = true;
	while (!q.empty()) {
		Pos cur = q.front();
		q.pop();
		//cout << cur.y << "," << cur.x << "," << cur.d << endl;
		if (cur.y == n && cur.x == m)
			return cur.d;
		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			if (ny >= 0 && nx >= 0 && ny <= n && nx <= m &&
				maps[ny][nx] && !visited[ny][nx]) {
				q.push({ ny, nx,cur.d + 1 });
				visited[ny][nx] = true;
			}
		}
	}
	return -1;
}
#include <iostream>
#include <queue>
#include <vector>
#define MAX 50

using namespace std;

typedef struct pos {
	int y;
	int x;
}Pos;
Pos dir[4] = { {0,-1},{-1,0}, {0,1},{1,0} };
int N, M;
int map[MAX][MAX] = { 0 };
int goal = 0;
int minSec = 987654321;
vector<Pos> virus;

int spreadVirus(vector<Pos> tVirus) {
	// virus 활성화
	queue<pair<Pos, int>> q;
	int tMap[MAX][MAX] = { 0 };
	for (int i = 0; i < N; i++) { // copy;
		for (int j = 0; j < N; j++) {
			tMap[i][j] = map[i][j];
		}
	}
	for (int i = 0; i < tVirus.size(); i++) {
		tMap[tVirus[i].y][tVirus[i].x] = 2;
		q.push({ {tVirus[i].y, tVirus[i].x}, 0 });
	}
	bool visited[MAX][MAX] = { false };
	int maxDepth = -1;
	int goalCnt = 0;
	while (!q.empty()) { // q가 비어있지 않으면?
		Pos cur = q.front().first;
		int depth = q.front().second;
		maxDepth = depth;
		q.pop();
		for (int i = 0; i < 4; i++) {
			Pos next = { cur.y + dir[i].y, cur.x + dir[i].x };
			if (!(next.y >= 0 && next.y < N && next.x >= 0 && next.x < N)) continue;
			if ((tMap[next.y][next.x] == 0 || tMap[next.y][next.x] == -1)&& !visited[next.y][next.x]) {
				if (tMap[next.y][next.x] == 0) {
					goalCnt++;
				}
				tMap[next.y][next.x] = 2;
				visited[next.y][next.x] = true;
				q.push({ { next.y, next.x }, depth + 1 });
				if (goal == goalCnt) {
					return depth + 1;
				}
			}
		}
	}
	if (goal == goalCnt)
		return maxDepth;
	else
		return -1;
}

void setVirus(int start, vector<Pos> tVirus) { // 
	if (tVirus.size() == M) {
		int rslt = spreadVirus(tVirus);
		if ( rslt != -1) 
			minSec = min(minSec, rslt);
	}
	for (int i = start; i < virus.size(); i++) {
		tVirus.push_back(virus[i]);
		setVirus(i+1, tVirus);
		tVirus.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	vector<Pos> tVirus;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				virus.push_back({ i,j });
				map[i][j] = -1; // 비활성
			}
			if (map[i][j] == 0) {
				goal++;
			}
		}
	}
	if (goal == 0) {
		cout << 0;
		return 0;
	}
	setVirus(0, tVirus);
	if (minSec == 987654321)
		cout << -1;
	else
		cout << minSec;
	return 0;
}